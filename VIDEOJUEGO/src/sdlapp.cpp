#include "sdlapp.hpp"
#include "utilidad/Tiempo.hpp"
#include "motor/KeyOyente.hpp"
#include "motor/MouseOyente.hpp"
#include <SDL_ttf.h>
#include "utilidad/RenderTexto.hpp"
#include "motor/fisica/MotorFisico.hpp"
#include "utilidad/Func_aux.hpp"
#include <iostream>
#include <cmath>

//#define RECTANGULOS
//#define TRIANGULOS
//#define CIRCULOS

SDLApp* SDLApp::instancia = 0;

SDLApp::SDLApp()
{
    vnt = nullptr;
    vntsurf = nullptr;
    render = nullptr;
    ensamble= nullptr;
    bg_color.r = 255; //rojo
    bg_color.g = 255; //verde
    bg_color.b = 255; //azul
    bg_color.a = 255; //alpha

    esta_corriendo = true;
    WIDTH=1008;
    HEIGHT=864;
    maxFPS=60;
    fps=0;

    
};

//Como solo queremos una instancia del esta clase, entonces se hace una clase singleton
SDLApp& SDLApp::get()
{
    if(!instancia)
        instancia = new SDLApp();
    return *instancia;
};

bool SDLApp::on_init()
{
    //revisar que SDL inicio bien
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){return false;};
    //crear la ventana
    get().vnt = SDL_CreateWindow(
        "Juego",                // Titulo de la ventana
        SDL_WINDOWPOS_UNDEFINED,// posicion X de la pantalla
        SDL_WINDOWPOS_UNDEFINED,// posicion Y de la pantalla
        get().WIDTH,            // ancho de la ventana
        get().HEIGHT,           // alto de la ventana
        SDL_WINDOW_OPENGL);     // que use OPENGL
    
    TTF_Init();
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    //revisar que se creo bien la ventana
    if(get().vnt == NULL)
    {
        printf("No se creo la ventana por: %s",SDL_GetError());
        return false;
    }
    //la forma de procesar en GPU
    SDL_SetHint(SDL_HINT_RENDER_BATCHING,"opengl");
    //creamos el 'canvas'
    get().render = SDL_CreateRenderer(
        get().vnt,                  // la ventana
        -1,                         // driver
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);  // flags driver
    //revisamos si se creo correctamente
    if(get().render == NULL)
    {
        printf("No se creo el renderer por: %s",SDL_GetError());
        return false; 
    }
    // si se creo correcto lo agregamos al Pipeline
    get().ensamble = new Pipeline(*get().render);

    //08 tiles
    Atlas::get().generar_mapa(get().render,2,0);
    //05

    

    player = new Jugador("assets/sprites/heroe/player2.png",
                //      hp , x , y, sW,sH , vW,vH ,color
                        100,144,144,48,48,100,100,{255,0,255,255});
    get().ensamble->cargar_texturas(player->get_sprite());
    printf("Se creo el player\n");
    plataformas = Atlas::get().get_objetos_fisicos();

    
    spawnEnemigos = new Spawner("assets/sprites/enemigos/player2.png"
    ,100,0,0,48,48,100,100,{255,0,255,255},*get().ensamble);
    spawnEnemigos->set_velocidad(6);

    get().camara_principal = new Camara(0,0,get().WIDTH,get().HEIGHT,*get().render);
    ManejadorCamaras::get().set_camara(*get().camara_principal);

    for(int i=0;i<plataformas.size();i++)
    {
        objetos.push_back(plataformas[i]);
    }

    objetos.push_back(player);

    
    Enemy * m = new Enemy("assets/sprites/enemigos/player2.png",
                //      hp , x , y, sW,sH , vW,vH ,color
                        100,720,720,48,48,100,100,{255,0,255,255});
    get().ensamble->cargar_texturas(m->get_sprite());
    enemigos.push_back(m);
    
    
    
    printf("\nSe crearon los objetos exitosamente\n");

    //agregamos el color del background del frame
    SDL_SetRenderDrawColor(
        get().render,       // canvas
        get().bg_color.r,   // rojo
        get().bg_color.g,   // verde
        get().bg_color.b,   // azul
        SDL_ALPHA_TRANSPARENT);// como usar el alpha

    ManejadorCamaras::get().lock_objeto(*player);
    ManejadorCamaras::get().set_estado(new EstadoCamaraTransicion());
    return true;
};

void SDLApp::on_evento(SDL_Event* evento)
{
    if(evento->type==SDL_QUIT)
    {
        get().esta_corriendo = false;
    }
    //eventos del mouse
    MouseOyente::get().evento_movimiento(evento);
    MouseOyente::get().evento_presionado(evento);
    MouseOyente::get().evento_scroll(evento);
    // que esta presionado
    KeyOyente::get().keyPresionado(evento);
    
};

void SDLApp::on_fisicaupdate(double dt)
{
    //double tiempo_inicial = 0;
    if(!ManejadorCamaras::get_camara().en_transicion)
    {
        if(player->get_posicion_mundo().x < ManejadorCamaras::get().get_camara().get_posicion_relativa().x - 216 ||
        player->get_posicion_mundo().x > ManejadorCamaras::get().get_camara().get_posicion_relativa().x + 216 ||
        player->get_posicion_mundo().y > ManejadorCamaras::get().get_camara().get_posicion_relativa().y + 216 ||
        player->get_posicion_mundo().y < ManejadorCamaras::get().get_camara().get_posicion_relativa().y - 216) 
        {
            ManejadorCamaras::get().set_estado(new EstadoCamaraTransicion());
        }
    }
    if(!ManejadorCamaras::get_camara().en_transicion)
    {
        if(!spawnEnemigos->actualizar_posicion(*player))
        {  
            exit(EXIT_FAILURE);
        }
        //printf("\nPosicion mundo: ");
        //DEBUGCOOR(player->get_posicion_mundo())
        //printf("\nPosicion camara: ");
        //DEBUGCOOR(player->get_posicion_camara())
        spawnEnemigos->update(&enemigos);
    }
    
    for(auto &p:objetos)
    {  
        p->update(dt);
        
    }
    
    if(KeyOyente::get().estaPresionado(SDL_SCANCODE_A) || KeyOyente::get().estaPresionado(SDL_SCANCODE_D) ||
     KeyOyente::get().estaPresionado(SDL_SCANCODE_W) || KeyOyente::get().estaPresionado(SDL_SCANCODE_S))
    {
       int i=0;
        for(auto &p:enemigos)
        {
            i++;
            p->input_handle(KeyOyente::get(),MouseOyente::get());
            p->update(dt);
            
            printf("Enemigo [%d]",i);
            printf("\nPosicion Enemigo: ");
            DEBUGCOOR(p->get_posicion_mundo())
            printf("Posicion Camara: ");
            DEBUGCOOR(p->get_posicion_camara())
            printf("\n");
        }
    }

    for(auto &p:enemigos)
    {
        p->update(dt);
        p->cambio = false;
    }

    
    
    
    player->input_handle(KeyOyente::get(),MouseOyente::get());

    //player->update(dt);

    
    /*CAMARA al final para actualizar la proyeción de los objetos*/
    ManejadorCamaras::get().input_handle(KeyOyente::get(),MouseOyente::get());
    ManejadorCamaras::get().update(objetos);
    ManejadorCamaras::get().update(enemigos);
    //printf("Update Fisica\n");

    
    
};

void SDLApp::on_frameupdate(double dt)
{
    // limpiar frame
    SDL_RenderClear(get().render);

    //Renderizar todo a través de la camara
    
    ManejadorCamaras::get().renderizar(objetos);
    ManejadorCamaras::get().renderizar(enemigos);


    


    //posicion del mouse
    /*
    int mx = MouseOyente::get().getX();
    int my = MouseOyente::get().getY();
    std::string pm = "mouse("+std::to_string(mx)+","+std::to_string(my)+")";
    Coordenadas cp = ManejadorCamaras::get().get_camara().get_posicion_centro();
    Coordenadas mcp = ManejadorCamaras::get().get_camara().get_posicion_mundo();
    std::string cm = "camara("+std::to_string(cp.x)+","+std::to_string(cp.y)+")";
    std::string cmm = "camara("+std::to_string(mcp.x)+","+std::to_string(mcp.y)+")";
    */
    //RenderTexto::get().render_texto(get().render,815,630,pm,100,30,SDL_Color{0,0,0,255});
    //RenderTexto::get().render_texto(get().render,815,580,cmm,100,30,SDL_Color{0,0,0,255});
    //RenderTexto::get().render_texto(get().render,815,530,cm,100,30,SDL_Color{0,0,0,255});
    //fps

    RenderTexto::get().render_texto(get().render,get().WIDTH-200,30,
        "Turno: "+std::to_string(turn),
        100,30,SDL_Color{0,135,62});
    //RenderTexto::get().render_texto(get().render,get().WIDTH-200,30,
     //   std::to_string((int)(dt/get().msfrecuencia))+" fps",
      //  100,30,SDL_Color{0,135,62});
    
    //RenderTexto::get().render_texto(get().render,50,630,player->get_strEstado(),120,30,SDL_Color{0,0,0,255});

    //Actualizar
    SDL_RenderPresent(get().render);

    //resetear color del frame
    SDL_SetRenderDrawColor(
        get().render,
        get().bg_color.r,
        get().bg_color.g,
        get().bg_color.b,
        SDL_ALPHA_TRANSPARENT);
};

void SDLApp::on_limpiar()
{
    SDL_DestroyRenderer(get().render);
    SDL_FreeSurface(get().vntsurf);
    SDL_DestroyWindow(get().vnt);

    for(auto &p:plataformas)
    {
        delete p;
    }
    plataformas.clear();
    delete spawnEnemigos;
    delete ensamble;
    delete player;
    SDL_Quit();
};

int SDLApp::on_correr()
{
    //revisar que todo se inicializo bien
    if(get().on_init()==false){return -1;}

    SDL_Event eventos;
    double dt=0;
    double frecuencia = 1/get().maxFPS; // 1 frame a 60fps
    get().msfrecuencia = frecuencia*1000;

    while(get().estaCorriendo())
    {
        //double start = SDL_GetTicks();
        double inicio = Tiempo::get_tiempo();

        //captura eventos
        while(SDL_PollEvent(&eventos))
        {
            get().on_evento(&eventos);
        }

        //actualizamos si inicia o hay una diferencia de tiempo
        
        get().on_fisicaupdate(dt);
        get().on_frameupdate(dt);

        //calculamos el tiempo del frame
        dt = (Tiempo::get_tiempo() - inicio)/frecuencia*1000;
        
        inicio=dt; //el nuevo frame inicia en este tiempo
        if(dt<get().msfrecuencia)
        {
            SDL_Delay(floor(get().msfrecuencia-dt));
        }
    }
    //liberamos memoria
    get().on_limpiar();
    return 0;
};


