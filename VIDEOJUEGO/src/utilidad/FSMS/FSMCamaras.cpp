#include "FSMCamaras.hpp"
#include "../Func_aux.hpp"
#include <iostream>
#include <cmath>

EstadoCamaraMover::EstadoCamaraMover()
{
    strestado = "mover";
};

FSMCamara* EstadoCamaraMover::input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse)
{
    return new EstadoCamaraMover();
};

void EstadoCamaraMover::on_entrar(Camara &cam)
{

};
void EstadoCamaraMover::on_salir(Camara &cam)
{

};
void EstadoCamaraMover::on_update(Camara &cam)
{    

};

/*
TRANSICIÓN
*/
EstadoCamaraTransicion::EstadoCamaraTransicion()
{
    frames_actual =0;
    frames_maximo = 30;
    strestado = "transicion";
};

FSMCamara* EstadoCamaraTransicion::input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse)
{
    if(frames_actual>frames_maximo)
    {
        if(distancia<10)
        {
            return new EstadoCamaraLock(*cam.get_obj_lock());
        }
        return new EstadoCamaraTransicion();
    }

    return NULL;
};

void EstadoCamaraTransicion::on_entrar(Camara &cam)
{
    //Alumnos implementa
    cam.en_transicion = 1;

    vel = cam.velocidad;
    pos_inicial = cam.get_posicion_mundo();//(0,0) 

    //seguro decir que este estado siempre entra en lock object
    // no es necesario comprobar que lock object no es nulo
    pos_final = cam.get_obj_lock()->get_posicion_mundo(); //o.x,o.y
    
    //convertir en posicion relativo a las coordenads camara
    centro = cam.get_posicion_centro();
    pos_final.x -= centro.x;
    pos_final.y -= centro.y;

    //la diferencia es la cantidad de pixeles que se mueve
    ant_check={0,0};
    //distancia=0.f;

    //checkar la distancia es pequeña para ajustar los frames
    distancia = std::sqrt(std::pow(centro.x-(pos_final.x+centro.x),2)+std::pow(centro.y-(pos_final.y+centro.y),2));
    //std::cout<<"Distancia > "<<distancia<<"\n";
    float lim = cam.get_obj_lock()->get_avatar()->get_vertices()[3].x - cam.get_obj_lock()->get_avatar()->get_vertices()[0].x;
    if(distancia<lim)
    {
        //std::cout<<"LIM "<<lim<<"\n";
        frames_maximo = 10;
    }

};
void EstadoCamaraTransicion::on_salir(Camara &cam)
{
    //Alumnos implementa
    cam.en_transicion=0;
};
void EstadoCamaraTransicion::on_update(Camara &cam)
{

    //Alumnos implementa
    if(frames_actual>frames_maximo)
        return;

    float t = frames_actual/(float)frames_maximo;
    check= LERP(pos_inicial,pos_final,t);
    //la diferencia es cuantos pixeles avanza por frame
    ant_check.x = check.x-ant_check.x;
    ant_check.y = check.y-ant_check.y;

    Coordenadas objpos = cam.get_obj_lock()->get_posicion_camara();

    distancia = std::sqrt(std::pow(centro.x-objpos.x,2)+std::pow(centro.y-objpos.y,2));
    //std::cout<<"Distancia > "<<distancia<<"\n";

    cam.set_posicion_mundo(check);
    frames_actual++;


    //guardamos la posición anterior
    ant_check = check;

};
/*
LOCK
*/
EstadoCamaraLock::EstadoCamaraLock(Objeto &objlock)
{
    strestado = "lock";
    obj = &objlock;

};

FSMCamara* EstadoCamaraLock::input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse)
{   
    return new EstadoCamaraMover;
};

void EstadoCamaraLock::on_entrar(Camara &cam)
{
    //Alumnos implementa
    centro = cam.get_posicion_centro();
    
};
void EstadoCamaraLock::on_salir(Camara &cam)
{
    //Alumnos implementa
};
void EstadoCamaraLock::on_update(Camara &cam)
{
    //Alumnos implementa

    // simplemente la camara obtiene la posición del obj

    Coordenadas pos_mundo = obj->get_posicion_mundo();
    pos_mundo.x -= centro.x;
    pos_mundo.y -= centro.y;
    cam.set_posicion_mundo(pos_mundo);
    cam.set_posicion_relativa(cam.get_obj_lock()->get_posicion_mundo());
    

};