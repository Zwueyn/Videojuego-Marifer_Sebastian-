#pragma once
#include "../../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../../motor/KeyOyente.hpp"
#include "../../motor/MouseOyente.hpp"
#include<string>
class Jugador; //forward declaration
class FSMJugador
{
    protected:
        std::string strnombre;
    
    public:
        virtual ~FSMJugador(){};
        virtual FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse)=0;
        virtual void entrar(Jugador& player)=0;
        virtual void salir(Jugador& player)=0;
        virtual void update(Jugador& player,double dt)=0;
        std::string get_namestate()const{return strnombre;};
};


class EstadoJugadorMOVERDerecha : public FSMJugador
{
    public:
        EstadoJugadorMOVERDerecha(Coordenadas dir);
        virtual ~EstadoJugadorMOVERDerecha(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
    private:
        Coordenadas direccion;
        int velocidad;
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
        Coordenadas pos_inicial;
        Coordenadas pos_final;
        int distancia;
        
    
};

class EstadoJugadorMOVERIzquierda : public FSMJugador
{
    public:
        EstadoJugadorMOVERIzquierda(Coordenadas dir);
        virtual ~EstadoJugadorMOVERIzquierda(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
    private:
        Coordenadas direccion;
        int velocidad;
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
        Coordenadas pos_inicial;
        Coordenadas pos_final;
        int distancia;
    
};

class EstadoJugadorMOVERArriba : public FSMJugador
{
    public:
        EstadoJugadorMOVERArriba(Coordenadas dir);
        virtual ~EstadoJugadorMOVERArriba(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
    private:
        Coordenadas direccion;
        int velocidad;
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
        Coordenadas pos_inicial;
        Coordenadas pos_final;
        int distancia;
    
};

class EstadoJugadorMOVERAbajo : public FSMJugador
{
    public:
        EstadoJugadorMOVERAbajo(Coordenadas dir);
        virtual ~EstadoJugadorMOVERAbajo(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
    private:
        Coordenadas direccion;
        int velocidad;
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
        Coordenadas pos_inicial;
        Coordenadas pos_final;
        int distancia;
    
};

class EstadoJugadorIDLE_D : public FSMJugador
{
    public:
        EstadoJugadorIDLE_D();
        virtual ~EstadoJugadorIDLE_D(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};

class EstadoJugadorIDLE_I : public FSMJugador
{
    public:
        EstadoJugadorIDLE_I();
        virtual ~EstadoJugadorIDLE_I(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};

class EstadoJugadorIDLE_A : public FSMJugador
{
    public:
        EstadoJugadorIDLE_A();
        virtual ~EstadoJugadorIDLE_A(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};


class EstadoJugadorIDLE_B : public FSMJugador
{
    public:
        EstadoJugadorIDLE_B();
        virtual ~EstadoJugadorIDLE_B(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};

class EstadoJugadorDead : public FSMJugador
{
    public:
        EstadoJugadorDead();
        virtual ~EstadoJugadorDead(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};