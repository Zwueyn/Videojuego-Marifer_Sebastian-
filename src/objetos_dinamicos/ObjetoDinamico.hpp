#pragma once
#include "../objetos/Objeto.hpp"
#include "../motor/KeyOyente.hpp"
#include "../motor/MouseOyente.hpp"
#include "../utilidad/FSMS/FSMEnemy.hpp"
#include "../utilidad/FSMS/FSMJugador.hpp"
#include<SDL.h>
#include<string>
class FSMJugador;//forward declaration
class FSMEnemy;//forward declaration

class ObjetoDinamico : public Objeto
{
    public:
        virtual ~ObjetoDinamico(){};
        virtual void update(double dt)=0;
        float get_dtgf()const{return dtgravedad;};
        void set_dtgf(float v){dtgravedad=v;};

        //forma general de convertir cualquier puntero si se conoce la clase
        virtual void set_estado(void* estado)=0;
        virtual void* get_estado()=0;

        Coordenadas offsetoverlap;
    protected:
        float dtgravedad{0};
        
};


class Jugador : public ObjetoDinamico
{
    public:
        virtual ~Jugador(){};
        Jugador(float vida, int x, int y,SDL_Color c );
        Jugador(std::string path_sprite,float vida, int x, int y, int w, int h,int sw,int sh, SDL_Color c );
        void update(double dt);
        void input_handle(KeyOyente& input,MouseOyente& mouse);
        std::string get_strEstado();
        Coordenadas get_piso()const{return piso;};
        void set_piso(Coordenadas p){piso = p;};

        void set_estado(void* estado);
        void* get_estado();

        void set_columna(int c){columna=c;};
        void set_fila(int f){fila=f;};
        int get_columna()const{return columna;};
        int get_fila()const{return fila;};
    private:
        FSMJugador* estado_actual;
        //typedef Objeto super;
        Coordenadas piso;
        int columna;
        int fila;
        
};

class Enemy : public ObjetoDinamico
{
    public:
        virtual ~Enemy(){};
        Enemy(float vida, int x, int y,SDL_Color c );
        Enemy(std::string path_sprite,float vida, int x, int y, int w, int h,int sw,int sh, SDL_Color c );
        void update(double dt);
        void input_handle(KeyOyente& input,MouseOyente& mouse);
        std::string get_strEstado();
        Coordenadas get_piso()const{return piso;};
        void set_piso(Coordenadas p){piso = p;};

        void set_estado(void* estado);
        void* get_estado();

        void set_columna(int c){columna=c;};
        void set_fila(int f){fila=f;};
        int get_columna()const{return columna;};
        int get_fila()const{return fila;};
        void MoverDer(int distancia);

        bool cambio{false};
    private:
        FSMEnemy* estado_actual;
        double delay;
        double init_tiempo;
        Coordenadas piso;
        int columna;
        int fila;
        
};