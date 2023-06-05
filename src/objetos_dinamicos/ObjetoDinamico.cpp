#include "ObjetoDinamico.hpp"
#include "../objetos/Figuras.hpp"
#include "../utilidad/Func_aux.hpp"
#include <iostream>

Jugador::Jugador(float vida, int x, int y , SDL_Color c)
:ObjetoDinamico{}
{
    hp = vida;
    posicion_mundo.x=x;
    posicion_mundo.y=y;
    posicion_camara.x = posicion_mundo.x;
    posicion_camara.y = posicion_mundo.y;
    avatar = new Rectangulo(x,y,75,75,c);
    c.a=150;
    color = c;
    avatar->set_rellenocolor(c);
    avatar->set_serellena(true);
    col_box = new Rectangulo(x,y,75+10,75+10,c);
    col_box->set_serellena(false);
    tiene_fisica = true;
    en_colision = false;
    estado_actual = new EstadoJugadorIDLE_B();
};

Jugador::Jugador(std::string path_sprite,float vida, int x, int y, int w, int h, int sw, int sh, SDL_Color c)
:ObjetoDinamico{}
{
    hp = vida;
    posicion_mundo.x=x;
    posicion_mundo.y=y;
    posicion_camara.x = posicion_mundo.x;
    posicion_camara.y = posicion_mundo.y;
    avatar = new Rectangulo(x,y,75,75,c);
    c.a=150;
    color = c;
    avatar->set_rellenocolor(c);
    avatar->set_serellena(true);
    col_box = new Rectangulo(x,y,48,48,c);
    col_box->set_serellena(false);
    tiene_fisica = true;
    en_colision = false;
    estado_actual = new EstadoJugadorIDLE_B();
    dmg = 15;

    sprite = new Sprite(path_sprite,posicion_mundo,w,h,sw,sh);
    tile = nullptr;
};

std::string Jugador::get_strEstado()
{
    return estado_actual->get_namestate();
};

void* Jugador::get_estado()
{
    return estado_actual;
};

void Jugador::set_estado(void* estado)
{
    estado_actual->salir(*this);
    delete estado_actual;
    estado_actual = (FSMJugador*)estado;
    estado_actual->entrar(*this);
};

void Jugador::update(double dt)
{
    
    //avatar->set_position((avatar->get_posicion().x)-2,(avatar->get_posicion().y-22));
    if(!estado_actual) //nulo
        return;
    estado_actual->update(*this,dt);

};

void Jugador::input_handle(KeyOyente& input,MouseOyente& mouse)
{
    if(!estado_actual) //nulo
        return;
    FSMJugador* estado = estado_actual->input_handle(input,mouse);
    if(estado)
    {
        set_estado(estado);
    }
};






//ENEMIGOS
Enemy::Enemy(std::string path_sprite,float vida, int x, int y, int w, int h, int sw, int sh, int atak, SDL_Color c)
:ObjetoDinamico{}
{
    hp = vida;
    posicion_mundo.x=x;
    posicion_mundo.y=y;
    posicion_camara.x =x;
    posicion_camara.y =y;
    avatar = new Rectangulo(x,y,75,75,c);
    c.a=150;
    color = c;
    avatar->set_rellenocolor(c);
    avatar->set_serellena(true);
    col_box = new Rectangulo(x,y,48,48,c);
    col_box->set_serellena(false);
    tiene_fisica = true;
    en_colision = false;
    estado_actual = new EstadoEnemyIDLE_B();
    dmg = atak;

    sprite = new Sprite(path_sprite,posicion_mundo,w,h,sw,sh);
    tile = nullptr;
};

std::string Enemy::get_strEstado()
{
    return estado_actual->get_namestate();
};

void* Enemy::get_estado()
{
    return estado_actual;
};

void Enemy::set_estado(void* estado)
{
    estado_actual->salir(*this);
    delete estado_actual;
    estado_actual = (FSMEnemy*)estado;
    estado_actual->entrar(*this);
};

void Enemy::update(double dt)
{

    if(!estado_actual) //nulo
        return;

    estado_actual->update(*this,dt);


};

void Enemy::input_handle(KeyOyente& input)
{
    if(!estado_actual) //nulo
        return;
    FSMEnemy* estado = estado_actual->input_handle(input);
    if(estado)
    {
        set_estado(estado);
    }
};

