#include "Spawner.hpp"
#include "Tiempo.hpp"
#include "Func_aux.hpp"
#include "../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../motor/imagen/Atlas.hpp"

#include <iostream>
#include <cstdlib>

Spawner::Spawner(std::string sprite_path, float v, int x, int y, int w, int h, int sw, int sh, SDL_Color c, Pipeline &p)
{
    this->sprite_path = sprite_path;
    colordebug=c;
    this->v=v;
    this->x=x; //pos x
    this->y=y; //pos y
    this->w=w; //ancho del sprite
    this->h=h; //alto del sprite
    this->sw=sw; //ancho mostrar sprite
    this->sh=sh; //alto mostrar sprite
    objetos_activos=0;
    jugador=nullptr;
    delay=3;
    init_tiempo = Tiempo::get_tiempo();
    check=false;
    pipeline = &p;
    velocidad=0;
};

void Spawner::spawn(std::vector<Enemy*> *lista)
{
    
    //random
    srand((unsigned) time(NULL));
    int sx, sy;
    
    do
    {
        int posX = rand()%50;
        int posY = rand()%50;
        sx = x + (posX*72);
        sy = y + (posY*72);
    } while (Atlas::get().indiceCuadro(sx/72 , sy/72) != 18);
    
    printf("\nPosicion matris X: [%d]", sx/72);
    printf("\nPosicion matris Y: [%d]\n", sy/72);

    Enemy * nuevo = new Enemy(
    sprite_path,v,sx,sy,w,h,sw,sh,colordebug);
    pipeline->cargar_texturas(nuevo->get_sprite());
    lista->push_back(nuevo);
    objetos_activos++;

};

void Spawner::set_velocidad(int v)
{
    velocidad=v;
};

void Spawner::despawn(std::vector<Enemy*> *lista)
{
    int id = lista->size()-objetos_activos;
    delete lista->at(id);
    objetos_activos--;
    lista->erase(std::next(lista->begin()+id));
};

void Spawner::update(std::vector<Enemy*> *lista)
{
    double dt =  Tiempo::get_tiempo() - init_tiempo;

    /*
    for(auto &p: *lista)
    {
        p->get_sprite()
    }
    */
    
    if((int)dt!=0 && ((int)dt)%delay == 0 && check==false && objetos_activos<5)
    {
        
        spawn(lista);
        past_tiempo=dt;
        check=true;
        DEBUGPRINT(std::to_string(dt)+" SPAWN "+std::to_string(objetos_activos))
        DEBUGCOOR(lista->at(lista->size()-1)->get_posicion_mundo());
    }

    if((int)dt!=0 && (int)dt%(delay*2) == 0 && !check)
    {
        //DEBUGPRINT("DESPAWN")
        //despawn(lista);
        //check=true;
    }

    if((int)dt>past_tiempo)
    {    
        check=false;
    }
};

bool Spawner::actualizar_posicion(Jugador &j)
{
    if(jugador==nullptr || jugador!=&j)
    {
        jugador=&j;
    }
    if(!jugador)
    {
        return false;
    }
    //x = j.get_posicion_mundo().x;
    //y = j.get_posicion_mundo().y;
    return true;
};