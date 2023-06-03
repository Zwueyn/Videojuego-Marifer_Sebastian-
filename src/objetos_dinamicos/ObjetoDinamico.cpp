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
    piso = {500,500}; // definir el piso en general
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
    //piso = {500,500}; // definir el piso en general
    columna = 2;
    fila = 2;

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
Enemy::Enemy(std::string path_sprite,float vida, int x, int y, int w, int h, int sw, int sh, SDL_Color c)
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
    columna = x / 72;
    fila = y / 72;

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

    //posicion_camara.x+=1;
    //posicion_mundo.x+=1;
    //printf("camra : %d %d\n",posicion_camara.x,posicion_camara.y);
    //printf("mundo : %d %d\n",posicion_mundo.x,posicion_mundo.y);
    estado_actual->update(*this,dt);


};

void Enemy::input_handle(KeyOyente& input,MouseOyente& mouse)
{
    if(!estado_actual) //nulo
        return;
    FSMEnemy* estado = estado_actual->input_handle(input,mouse);
    if(estado)
    {
        set_estado(estado);
    }
};

void Enemy::MoverDer(int distancia)
{
    posicion_mundo.x+=(distancia);
    //posicion_camara.x+=(72*distancia);
};