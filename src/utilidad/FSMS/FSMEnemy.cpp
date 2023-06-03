#include "FSMEnemy.hpp"
#include "../Func_aux.hpp"
#include "../../motor/imagen/Atlas.hpp"
#include "../../motor/camaras/ManejadorCamaras.hpp"
#include "../Tiempo.hpp"
#include<SDL.h>
#include<iostream>
#include <sstream>
#include<cmath>


//IDLES Y MOVERS

EstadoEnemyIDLE_D::EstadoEnemyIDLE_D()
{
    strnombre = "IDLE_Derecha";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMEnemy* EstadoEnemyIDLE_D::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    srand(time(NULL));
    int random = rand() % 5;
    printf("Random: %d\n",random);
    if(random == 0)
    {
        return NULL;
    }
    if(random == 1)
    {
        return new EstadoEnemyMOVERDerecha();
    }
    if(random == 2)
    {
        return new EstadoEnemyMOVERIzquierda();
    }
    if(random == 3)
    {
        return new EstadoEnemyMOVERArriba();
    }
    if(random == 4) 
    {
        return new EstadoEnemyMOVERAbajo();
    }
    return NULL;
};
void EstadoEnemyIDLE_D::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
};
void EstadoEnemyIDLE_D::salir(Enemy& enemy)
{

};
void EstadoEnemyIDLE_D::update(Enemy& enemy,double dt)
{
    //printf("IDLE Derecha de enemy\n");
    enemy.get_sprite()->play_frame(1,frames_actual_ani%frames_maxim_ani);
    if(frames_dt >= 5)
    {
        frames_dt = 0;
        frames_actual_ani++;
        
    }
    frames_dt++;

};


// IDLE IZQUIERDA

EstadoEnemyIDLE_I::EstadoEnemyIDLE_I()
{
    strnombre = "IDLE_Izquierda";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMEnemy* EstadoEnemyIDLE_I::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    srand(time(NULL));
    int random = rand() % 5;
    printf("Random: %d\n",random);
    if(random == 0)
    {
        return NULL;
    }
    if(random == 1)
    {
        return new EstadoEnemyMOVERDerecha();
    }
    if(random == 2)
    {
        return new EstadoEnemyMOVERIzquierda();
    }
    if(random == 3)
    {
        return new EstadoEnemyMOVERArriba();
    }
    if(random == 4) 
    {
        return new EstadoEnemyMOVERAbajo();
    }
    return NULL;
};
void EstadoEnemyIDLE_I::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
};
void EstadoEnemyIDLE_I::salir(Enemy& enemy)
{
};
void EstadoEnemyIDLE_I::update(Enemy& enemy,double dt)
{
    //printf("IDLE Izquierda de enemy\n");
    enemy.get_sprite()->play_frame(11, frames_actual_ani % frames_maxim_ani);
    if(frames_dt >= 5)
    {
        frames_dt = 0;
        frames_actual_ani++;
        
    }
    frames_dt++;

};



//IDLE ARRIBA

EstadoEnemyIDLE_A::EstadoEnemyIDLE_A()
{
    strnombre = "IDLE_Arriba";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMEnemy* EstadoEnemyIDLE_A::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    srand(time(NULL));
    int random = rand() % 5;
    printf("Random: %d\n",random);
    if(random == 0)
    {
        return NULL;
    }
    if(random == 1)
    {
        return new EstadoEnemyMOVERDerecha();
    }
    if(random == 2)
    {
        return new EstadoEnemyMOVERIzquierda();
    }
    if(random == 3)
    {
        return new EstadoEnemyMOVERArriba();
    }
    if(random == 4) 
    {
        return new EstadoEnemyMOVERAbajo();
    }
    return NULL;
};
void EstadoEnemyIDLE_A::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
};
void EstadoEnemyIDLE_A::salir(Enemy& enemy)
{

};
void EstadoEnemyIDLE_A::update(Enemy& enemy,double dt)
{
    //printf("IDLE Arriba de enemy\n");
    enemy.get_sprite()->play_frame(2,frames_actual_ani%frames_maxim_ani);
    if(frames_dt >= 5)
    {
        frames_dt = 0;
        frames_actual_ani++;
        
    }
    frames_dt++;

};




//IDLE ABAJO

EstadoEnemyIDLE_B::EstadoEnemyIDLE_B()
{
    strnombre = "IDLE_Abajo";
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
    
};

FSMEnemy* EstadoEnemyIDLE_B::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    srand(time(NULL));
    int random = rand() % 5;
    printf("Random: %d\n",random);
    if(random == 0)
    {
        return NULL;
    }
    if(random == 1)
    {
        return new EstadoEnemyMOVERDerecha();
    }
    if(random == 2)
    {
        return new EstadoEnemyMOVERIzquierda();
    }
    if(random == 3)
    {
        return new EstadoEnemyMOVERArriba();
    }
    if(random == 4) 
    {
        return new EstadoEnemyMOVERAbajo();
    }
    return NULL;
};
void EstadoEnemyIDLE_B::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 5;
};
void EstadoEnemyIDLE_B::salir(Enemy& enemy)
{

};
void EstadoEnemyIDLE_B::update(Enemy& enemy,double dt)
{
    //printf("IDLE Abajo de enemy\n");
    enemy.get_sprite()->play_frame(0,frames_actual_ani%frames_maxim_ani);
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
EstadoEnemyMOVERDerecha::EstadoEnemyMOVERDerecha()
{
    strnombre = "MOVER_Derecha";
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 9;
    
};

FSMEnemy* EstadoEnemyMOVERDerecha::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(frames_actual_ani > frames_maxim_ani)
    {
        return new EstadoEnemyIDLE_D();
    }

    return NULL;
};
void EstadoEnemyMOVERDerecha::entrar(Enemy& enemy)
{
    frames_actual_ani = 0; 
    enemy.cambio = true;
    pos_inicial = enemy.get_posicion_mundo();
    pos_final = {pos_inicial.x + 72, pos_inicial.y};

    //DEBUGCOOR(enemy.get_posicion_mundo())
    distancia = (pos_final.x-pos_inicial.x)/frames_maxim_ani;

};

void EstadoEnemyMOVERDerecha::salir(Enemy& enemy){};

void EstadoEnemyMOVERDerecha::update(Enemy& enemy,double dt)
{
    frames_actual_ani++;
    if(Atlas::get().indiceCuadro(enemy.get_columna() + 1, enemy.get_fila()) != 18) return;

    enemy.get_sprite()->play_frame(4,frames_actual_ani%5);
    
    if(frames_dt< frames_maxim_ani)
    {
        //DEBUGPRINT(distancia)
        enemy.MoverDer(distancia);
        //DEBUGCOOR(enemy.get_posicion_camara())
        frames_dt++;
    }
    if(frames_actual_ani > frames_maxim_ani)
    {
        enemy.set_columna(enemy.get_columna() + 1);
    }
    if(!enemy.cambio)
        enemy.set_estado(new EstadoEnemyIDLE_D());

    
};

/*
MOVER IZQUIERDA
*/
EstadoEnemyMOVERIzquierda::EstadoEnemyMOVERIzquierda()
{
    strnombre = "MOVER_Izquierda";
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 9;
    
};

FSMEnemy* EstadoEnemyMOVERIzquierda::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(frames_actual_ani > frames_maxim_ani)
    {
        return new EstadoEnemyIDLE_I();
    }

    return NULL;
};
void EstadoEnemyMOVERIzquierda::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    enemy.cambio = true;
    
    pos_inicial = enemy.get_posicion_mundo();
    pos_final = {pos_inicial.x - 72, pos_inicial.y};

    distancia = (pos_final.x-pos_inicial.x)/frames_maxim_ani;

};
void EstadoEnemyMOVERIzquierda::salir(Enemy& enemy){};
void EstadoEnemyMOVERIzquierda::update(Enemy& enemy,double dt)
{
    //printf("Movimiento Izquierda de enemy\n");
    frames_actual_ani++;
    if(Atlas::get().indiceCuadro(enemy.get_columna() -1, enemy.get_fila()) != 18) return;

    enemy.get_sprite()->play_frame(10,frames_actual_ani%5);
    if(frames_dt < frames_maxim_ani)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x + distancia ,enemy.get_posicion_mundo().y});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        enemy.set_columna(enemy.get_columna() - 1);
    }
    if(!enemy.cambio)
        enemy.set_estado(new EstadoEnemyIDLE_I());
};


/*
MOVER ARRIBA
*/
EstadoEnemyMOVERArriba::EstadoEnemyMOVERArriba()
{
    strnombre = "MOVER_Arriba";
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 9;
    
};

FSMEnemy* EstadoEnemyMOVERArriba::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(frames_actual_ani > frames_maxim_ani)
    {
        return new EstadoEnemyIDLE_A();
    }

    return NULL;
};
void EstadoEnemyMOVERArriba::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    enemy.cambio = true;
    pos_inicial = enemy.get_posicion_mundo();
    pos_final = {pos_inicial.x, pos_inicial.y-72};

    distancia = (pos_final.y-pos_inicial.y)/frames_maxim_ani;
};
void EstadoEnemyMOVERArriba::salir(Enemy& enemy){};
void EstadoEnemyMOVERArriba::update(Enemy& enemy,double dt)
{
    //printf("Movimiento Arriba de enemy\n");
    frames_actual_ani++;

    if(Atlas::get().indiceCuadro(enemy.get_columna(), enemy.get_fila() -1) != 18) return;

    enemy.get_sprite()->play_frame(5,frames_actual_ani%5);
    if(frames_dt < frames_maxim_ani)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x,enemy.get_posicion_mundo().y + distancia});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        enemy.set_fila(enemy.get_fila() - 1);
    }

    if(!enemy.cambio)
        enemy.set_estado(new EstadoEnemyIDLE_A());
    
};



/*
MOVER ABAJO
*/
EstadoEnemyMOVERAbajo::EstadoEnemyMOVERAbajo()
{
    strnombre = "MOVER_Abajo";
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 9;
    
};

FSMEnemy* EstadoEnemyMOVERAbajo::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(frames_actual_ani > frames_maxim_ani)
    {
        return new EstadoEnemyIDLE_B();
    }

    return NULL;
};
void EstadoEnemyMOVERAbajo::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    enemy.cambio = true;
    pos_inicial = enemy.get_posicion_mundo();
    pos_final = {pos_inicial.x, pos_inicial.y + 72};

    distancia = (pos_final.y-pos_inicial.y)/frames_maxim_ani; 
};
void EstadoEnemyMOVERAbajo::salir(Enemy& enemy){};
void EstadoEnemyMOVERAbajo::update(Enemy& enemy,double dt)
{
    //printf("Movimiento Abajo de enemy\n");
    frames_actual_ani++;
    

    if(Atlas::get().indiceCuadro(enemy.get_columna(), enemy.get_fila() +1) != 18) return;
    
    enemy.get_sprite()->play_frame(3,frames_actual_ani%5);
    if(frames_dt < frames_maxim_ani)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x,enemy.get_posicion_mundo().y + distancia});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        enemy.set_fila(enemy.get_fila() + 1);
    }

    if(!enemy.cambio)
        enemy.set_estado(new EstadoEnemyIDLE_B());

};