#pragma once
#include "../../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../../motor/KeyOyente.hpp"
#include "../../motor/MouseOyente.hpp"
#include<string>
class Enemy; //forward declaration
class FSMEnemy
{
    protected:
        std::string strnombre;
    
    public:
        virtual ~FSMEnemy(){};
        virtual FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse)=0;
        virtual void entrar(Enemy& slime)=0;
        virtual void salir(Enemy& slime)=0;
        virtual void update(Enemy& slime,double dt)=0;
        std::string get_namestate()const{return strnombre;};
};

class EstadoEnemyMOVERDerecha : public FSMEnemy
{
    public:
        EstadoEnemyMOVERDerecha();
        virtual ~EstadoEnemyMOVERDerecha(){};
        FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Enemy& enemy);
        void salir(Enemy& enemy);
        void update(Enemy& enemy,double dt);
    private:
        int velocidad;
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
        Coordenadas pos_inicial;
        Coordenadas pos_final;
        int distancia;
        
    
};

class EstadoEnemyMOVERIzquierda : public FSMEnemy
{
    public:
        EstadoEnemyMOVERIzquierda();
        virtual ~EstadoEnemyMOVERIzquierda(){};
        FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Enemy& enemy);
        void salir(Enemy& enemy);
        void update(Enemy& enemy,double dt);
    private:
        int velocidad;
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
        Coordenadas pos_inicial;
        Coordenadas pos_final;
        int distancia;
    
};

class EstadoEnemyMOVERArriba : public FSMEnemy
{
    public:
        EstadoEnemyMOVERArriba();
        virtual ~EstadoEnemyMOVERArriba(){};
        FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Enemy& enemy);
        void salir(Enemy& enemy);
        void update(Enemy& enemy,double dt);
    private:
        int velocidad;
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
        Coordenadas pos_inicial;
        Coordenadas pos_final;
        int distancia;
    
};

class EstadoEnemyMOVERAbajo : public FSMEnemy
{
    public:
        EstadoEnemyMOVERAbajo();
        virtual ~EstadoEnemyMOVERAbajo(){};
        FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Enemy& enemy);
        void salir(Enemy& enemy);
        void update(Enemy& enemy,double dt);
    private:
        int velocidad;
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
        Coordenadas pos_inicial;
        Coordenadas pos_final;
        int distancia;
    
};

class EstadoEnemyIDLE_D : public FSMEnemy
{
    public:
        EstadoEnemyIDLE_D();
        virtual ~EstadoEnemyIDLE_D(){};
        FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Enemy& enemy);
        void salir(Enemy& enemy);
        void update(Enemy& enemy, double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};

class EstadoEnemyIDLE_I : public FSMEnemy
{
    public:
        EstadoEnemyIDLE_I();
        virtual ~EstadoEnemyIDLE_I(){};
        FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Enemy& enemy);
        void salir(Enemy& enemy);
        void update(Enemy& enemy,double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};

class EstadoEnemyIDLE_A : public FSMEnemy
{
    public:
        EstadoEnemyIDLE_A();
        virtual ~EstadoEnemyIDLE_A(){};
        FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Enemy& enemy);
        void salir(Enemy& enemy);
        void update(Enemy& enemy,double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};


class EstadoEnemyIDLE_B : public FSMEnemy
{
    public:
        EstadoEnemyIDLE_B();
        virtual ~EstadoEnemyIDLE_B(){};
        FSMEnemy* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Enemy& enemy);
        void salir(Enemy& enemy);
        void update(Enemy& enemy,double dt);

    private:
        int frames_actual_ani;
        int frames_maxim_ani;
        int frames_dt{0};
};