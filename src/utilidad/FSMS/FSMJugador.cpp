#include "FSMJugador.hpp"
#include "../Func_aux.hpp"
#include "../../motor/imagen/Atlas.hpp"
#include "../../motor/camaras/ManejadorCamaras.hpp"
#include<SDL.h>
#include<iostream>
#include <sstream>
#include<cmath>



/*
IDLE
*/
EstadoJugadorIDLE_D::EstadoJugadorIDLE_D()
{
    strnombre = "IDLE_Derecha";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMJugador* EstadoJugadorIDLE_D::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(ManejadorCamaras::get_camara().en_transicion)
        return NULL;
    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorMOVERDerecha({1,0});
    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorMOVERIzquierda({-1,0});
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorMOVERArriba({0,-1});
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorMOVERAbajo({0,1});
    if(input.estaPresionado(SDL_SCANCODE_SPACE))
        return new EstadoJugadorDead;
    return NULL;
};
void EstadoJugadorIDLE_D::entrar(Jugador& player)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
};
void EstadoJugadorIDLE_D::salir(Jugador& player)
{

};
void EstadoJugadorIDLE_D::update(Jugador& player,double dt)
{
    player.get_sprite()->play_frame(1,frames_actual_ani%frames_maxim_ani);
    if(frames_dt >= 5)
    {
        frames_dt = 0;
        frames_actual_ani++;
        
    }
    frames_dt++;

};


// IDLE IZQUIERDA

EstadoJugadorIDLE_I::EstadoJugadorIDLE_I()
{
    strnombre = "IDLE_Izquierda";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMJugador* EstadoJugadorIDLE_I::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(ManejadorCamaras::get_camara().en_transicion)
        return NULL;
    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorMOVERDerecha({1,0});
    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorMOVERIzquierda({-1,0});
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorMOVERArriba({0,-1});
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorMOVERAbajo({0,1});

    return NULL;
};
void EstadoJugadorIDLE_I::entrar(Jugador& player)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
};
void EstadoJugadorIDLE_I::salir(Jugador& player)
{
};
void EstadoJugadorIDLE_I::update(Jugador& player,double dt)
{
    player.get_sprite()->play_frame(11,frames_actual_ani%frames_maxim_ani);
    if(frames_dt >= 5)
    {
        frames_dt = 0;
        frames_actual_ani++;
        
    }
    frames_dt++;

};



//IDLE ARRIBA

EstadoJugadorIDLE_A::EstadoJugadorIDLE_A()
{
    strnombre = "IDLE_Arriba";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMJugador* EstadoJugadorIDLE_A::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(ManejadorCamaras::get_camara().en_transicion)
        return NULL;
    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorMOVERDerecha({1,0});
    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorMOVERIzquierda({-1,0});
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorMOVERArriba({0,-1});
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorMOVERAbajo({0,1});

    return NULL;
};
void EstadoJugadorIDLE_A::entrar(Jugador& player)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
};
void EstadoJugadorIDLE_A::salir(Jugador& player)
{

};
void EstadoJugadorIDLE_A::update(Jugador& player,double dt)
{
    player.get_sprite()->play_frame(2,frames_actual_ani%frames_maxim_ani);
    if(frames_dt >= 5)
    {
        frames_dt = 0;
        frames_actual_ani++;
        
    }
    frames_dt++;

};




//IDLE ABAJO

EstadoJugadorIDLE_B::EstadoJugadorIDLE_B()
{
    strnombre = "IDLE_Abajo";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMJugador* EstadoJugadorIDLE_B::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(ManejadorCamaras::get_camara().en_transicion)
        return NULL;
    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorMOVERDerecha({1,0});
    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorMOVERIzquierda({-1,0});
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorMOVERArriba({0,-1});
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorMOVERAbajo({0,1});

    return NULL;
};
void EstadoJugadorIDLE_B::entrar(Jugador& player)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
};
void EstadoJugadorIDLE_B::salir(Jugador& player)
{

};
void EstadoJugadorIDLE_B::update(Jugador& player,double dt)
{
    
    player.get_sprite()->play_frame(0,frames_actual_ani%frames_maxim_ani);
    if(frames_dt >= 5)
    {
        frames_dt = 0;
        frames_actual_ani++;
        
    }
    frames_dt++;

};

/*
MOVER
*/
EstadoJugadorMOVERDerecha::EstadoJugadorMOVERDerecha(Coordenadas dir)
{
    strnombre = "MOVER_Derecha";
    direccion = dir;
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 9;
    
};

FSMJugador* EstadoJugadorMOVERDerecha::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(frames_actual_ani > frames_maxim_ani)
    {
        return new EstadoJugadorIDLE_D();
    }

    return NULL;
};
void EstadoJugadorMOVERDerecha::entrar(Jugador& player)
{
    frames_actual_ani = 0; 

    pos_inicial = player.get_posicion_mundo();
    pos_final = {pos_inicial.x + 72, pos_inicial.y};


    distancia = (pos_final.x-pos_inicial.x)/frames_maxim_ani;

};

void EstadoJugadorMOVERDerecha::salir(Jugador& player){};

void EstadoJugadorMOVERDerecha::update(Jugador& player,double dt)
{
    frames_actual_ani++;
    if(Atlas::get().indiceCuadro(player.get_columna() + 1, player.get_fila()) != 18) return;

    player.get_sprite()->play_frame(4,frames_actual_ani%5);
    if(frames_dt< frames_maxim_ani)
    {
        player.set_posicion_mundo({player.get_posicion_mundo().x + distancia ,player.get_posicion_mundo().y});
        frames_dt++;
    }
    if(frames_actual_ani > frames_maxim_ani)
    {
        player.set_columna(player.get_columna() + 1);
    }

    
};

/*
MOVER IZQUIERDA
*/
EstadoJugadorMOVERIzquierda::EstadoJugadorMOVERIzquierda(Coordenadas dir)
{
    strnombre = "MOVER_Izquierda";
    direccion = dir;
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 9;
    
};

FSMJugador* EstadoJugadorMOVERIzquierda::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(frames_actual_ani > frames_maxim_ani)
    {
        return new EstadoJugadorIDLE_I();
    }

    return NULL;
};
void EstadoJugadorMOVERIzquierda::entrar(Jugador& player)
{
    frames_actual_ani = 0;
    pos_inicial = player.get_posicion_mundo();
    pos_final = {pos_inicial.x - 72, pos_inicial.y};

    distancia = (pos_final.x-pos_inicial.x)/frames_maxim_ani;

};
void EstadoJugadorMOVERIzquierda::salir(Jugador& player){};
void EstadoJugadorMOVERIzquierda::update(Jugador& player,double dt)
{
    frames_actual_ani++;
    if(Atlas::get().indiceCuadro(player.get_columna() -1, player.get_fila()) != 18) return;

    player.get_sprite()->play_frame(10,frames_actual_ani%5);
    if(frames_dt < frames_maxim_ani)
    {
        player.set_posicion_mundo({player.get_posicion_mundo().x + distancia ,player.get_posicion_mundo().y});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        player.set_columna(player.get_columna() - 1);
    }
    
};


/*
MOVER ARRIBA
*/
EstadoJugadorMOVERArriba::EstadoJugadorMOVERArriba(Coordenadas dir)
{
    strnombre = "MOVER_Arriba";
    direccion = dir;
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 9;
    
};

FSMJugador* EstadoJugadorMOVERArriba::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(frames_actual_ani > frames_maxim_ani)
    {
        return new EstadoJugadorIDLE_A();
    }

    return NULL;
};
void EstadoJugadorMOVERArriba::entrar(Jugador& player)
{
    frames_actual_ani = 0;
    pos_inicial = player.get_posicion_mundo();
    pos_final = {pos_inicial.x, pos_inicial.y-72};

    distancia = (pos_final.y-pos_inicial.y)/frames_maxim_ani;
};
void EstadoJugadorMOVERArriba::salir(Jugador& player){};
void EstadoJugadorMOVERArriba::update(Jugador& player,double dt)
{
    frames_actual_ani++;

    if(Atlas::get().indiceCuadro(player.get_columna(), player.get_fila() -1) != 18) return;

    player.get_sprite()->play_frame(5,frames_actual_ani%5);
    if(frames_dt < frames_maxim_ani)
    {
        player.set_posicion_mundo({player.get_posicion_mundo().x,player.get_posicion_mundo().y + distancia});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        player.set_fila(player.get_fila() - 1);
    }
    
};



/*
MOVER ABAJO
*/
EstadoJugadorMOVERAbajo::EstadoJugadorMOVERAbajo(Coordenadas dir)
{
    strnombre = "MOVER_Abajo";
    direccion = dir;
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 9;
    
};

FSMJugador* EstadoJugadorMOVERAbajo::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(frames_actual_ani > frames_maxim_ani)
    {
        return new EstadoJugadorIDLE_B();
    }

    return NULL;
};
void EstadoJugadorMOVERAbajo::entrar(Jugador& player)
{
    frames_actual_ani = 0;
    pos_inicial = player.get_posicion_mundo();
    pos_final = {pos_inicial.x, pos_inicial.y + 72};

    distancia = (pos_final.y-pos_inicial.y)/frames_maxim_ani; 
};
void EstadoJugadorMOVERAbajo::salir(Jugador& player){};
void EstadoJugadorMOVERAbajo::update(Jugador& player,double dt)
{

    frames_actual_ani++;

    if(Atlas::get().indiceCuadro(player.get_columna(), player.get_fila() +1) != 18) return;

    player.get_sprite()->play_frame(3,frames_actual_ani%5);
    if(frames_dt < frames_maxim_ani)
    {
        player.set_posicion_mundo({player.get_posicion_mundo().x,player.get_posicion_mundo().y + distancia});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        player.set_fila(player.get_fila() + 1);
    }

};



//DEAD

EstadoJugadorDead::EstadoJugadorDead()
{
    strnombre = "DEAD";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMJugador* EstadoJugadorDead::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorMOVERDerecha({1,0});
    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorMOVERIzquierda({-1,0});
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorMOVERArriba({0,-1});
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorMOVERAbajo({0,1});

    return NULL;
};
void EstadoJugadorDead::entrar(Jugador& player)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 2;
};
void EstadoJugadorDead::salir(Jugador& player)
{

};
void EstadoJugadorDead::update(Jugador& player,double dt)
{
    player.get_sprite()->play_frame(9,frames_actual_ani%frames_maxim_ani);
    
    if(frames_dt >= 10)
    {
        frames_dt = 0;
        if(frames_actual_ani<1)
        {
            frames_actual_ani++;
        }
        
    }
    frames_dt++;

};

