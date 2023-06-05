#include "FSMEnemy.hpp"
#include "../Func_aux.hpp"
#include "../../motor/imagen/Atlas.hpp"
#include "../../motor/camaras/ManejadorCamaras.hpp"
#include "../InteraccionEntidades.hpp"
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
    frames_maxim_ani = 3;
    
};

FSMEnemy* EstadoEnemyIDLE_D::input_handle(KeyOyente& input)
{
        int px, py, ex, ey;
    px = InteraccionEntidades::get_entidad()->get_posicion_mundo().x;
    py = InteraccionEntidades::get_entidad()->get_posicion_mundo().y;
    ex = InteraccionEntidades::get_enemigo()->get_posicion_mundo().x;
    ey = InteraccionEntidades::get_enemigo()->get_posicion_mundo().y;


    if(ex < px)
    {
        if(ey < py)
        {
            return new EstadoEnemyMOVERAbajo();
        }
        if(ey > py) 
        {
            return new EstadoEnemyMOVERArriba();
        }
        return new EstadoEnemyMOVERDerecha();
    }
    if(ex > px) 
    {
        if(ey < py)
        {
            return new EstadoEnemyMOVERAbajo();
        }
        if(ey > py) 
        {
            return new EstadoEnemyMOVERArriba();
        }
        return new EstadoEnemyMOVERIzquierda();
    }
    if(ey < py)
    {
        if(ex < px)
        {
            return new EstadoEnemyMOVERDerecha();
        }
        if(ex > px) 
        {
            return new EstadoEnemyMOVERIzquierda();
        }
        return new EstadoEnemyMOVERAbajo();
    }
    if(ey > py)
    {
        if(ex < px)
        {
            return new EstadoEnemyMOVERDerecha();
        }
        if(ex > px) 
        {
            return new EstadoEnemyMOVERIzquierda();
        }
        return new EstadoEnemyMOVERArriba();
    }
    
    return NULL;
};
void EstadoEnemyIDLE_D::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 3;
};
void EstadoEnemyIDLE_D::salir(Enemy& enemy)
{
    
};
void EstadoEnemyIDLE_D::update(Enemy& enemy,double dt)
{
    enemy.get_sprite()->play_frame(2,frames_actual_ani%frames_maxim_ani);
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
    frames_maxim_ani = 3;
    
};

FSMEnemy* EstadoEnemyIDLE_I::input_handle(KeyOyente& input)
{
        int px, py, ex, ey;
    px = InteraccionEntidades::get_entidad()->get_posicion_mundo().x;
    py = InteraccionEntidades::get_entidad()->get_posicion_mundo().y;
    ex = InteraccionEntidades::get_enemigo()->get_posicion_mundo().x;
    ey = InteraccionEntidades::get_enemigo()->get_posicion_mundo().y;


    if(ex < px)
    {
        if(ey < py)
        {
            return new EstadoEnemyMOVERAbajo();
        }
        if(ey > py) 
        {
            return new EstadoEnemyMOVERArriba();
        }
        return new EstadoEnemyMOVERDerecha();
    }
    if(ex > px) 
    {
        if(ey < py)
        {
            return new EstadoEnemyMOVERAbajo();
        }
        if(ey > py) 
        {
            return new EstadoEnemyMOVERArriba();
        }
        return new EstadoEnemyMOVERIzquierda();
    }
    if(ey < py)
    {
        if(ex < px)
        {
            return new EstadoEnemyMOVERDerecha();
        }
        if(ex > px) 
        {
            return new EstadoEnemyMOVERIzquierda();
        }
        return new EstadoEnemyMOVERAbajo();
    }
    if(ey > py)
    {
        if(ex < px)
        {
            return new EstadoEnemyMOVERDerecha();
        }
        if(ex > px) 
        {
            return new EstadoEnemyMOVERIzquierda();
        }
        return new EstadoEnemyMOVERArriba();
    }
    
    return NULL;
};
void EstadoEnemyIDLE_I::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 3;
};
void EstadoEnemyIDLE_I::salir(Enemy& enemy)
{
    
};
void EstadoEnemyIDLE_I::update(Enemy& enemy,double dt)
{
    ////("IDLE Izquierda de enemy\n");
    enemy.get_sprite()->play_frame(1, frames_actual_ani % frames_maxim_ani);
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
    frames_maxim_ani = 3;
    
};

FSMEnemy* EstadoEnemyIDLE_A::input_handle(KeyOyente& input)
{
    int px, py, ex, ey;
    px = InteraccionEntidades::get_entidad()->get_posicion_mundo().x;
    py = InteraccionEntidades::get_entidad()->get_posicion_mundo().y;
    ex = InteraccionEntidades::get_enemigo()->get_posicion_mundo().x;
    ey = InteraccionEntidades::get_enemigo()->get_posicion_mundo().y;


    if(ex < px)
    {
        if(ey < py)
        {
            return new EstadoEnemyMOVERAbajo();
        }
        if(ey > py) 
        {
            return new EstadoEnemyMOVERArriba();
        }
        return new EstadoEnemyMOVERDerecha();
    }
    if(ex > px) 
    {
        if(ey < py)
        {
            return new EstadoEnemyMOVERAbajo();
        }
        if(ey > py) 
        {
            return new EstadoEnemyMOVERArriba();
        }
        return new EstadoEnemyMOVERIzquierda();
    }
    if(ey < py)
    {
        if(ex < px)
        {
            return new EstadoEnemyMOVERDerecha();
        }
        if(ex > px) 
        {
            return new EstadoEnemyMOVERIzquierda();
        }
        return new EstadoEnemyMOVERAbajo();
    }
    if(ey > py)
    {
        if(ex < px)
        {
            return new EstadoEnemyMOVERDerecha();
        }
        if(ex > px) 
        {
            return new EstadoEnemyMOVERIzquierda();
        }
        return new EstadoEnemyMOVERArriba();
    }
    
    return NULL;
};
void EstadoEnemyIDLE_A::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 3;
};
void EstadoEnemyIDLE_A::salir(Enemy& enemy)
{
    
};
void EstadoEnemyIDLE_A::update(Enemy& enemy,double dt)
{
    ////("IDLE Arriba de enemy\n");
    enemy.get_sprite()->play_frame(3,frames_actual_ani%frames_maxim_ani);
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
    frames_maxim_ani = 3;
    
};

FSMEnemy* EstadoEnemyIDLE_B::input_handle(KeyOyente& input)
{
        int px, py, ex, ey;
    px = InteraccionEntidades::get_entidad()->get_posicion_mundo().x;
    py = InteraccionEntidades::get_entidad()->get_posicion_mundo().y;
    ex = InteraccionEntidades::get_enemigo()->get_posicion_mundo().x;
    ey = InteraccionEntidades::get_enemigo()->get_posicion_mundo().y;


    if(ex < px)
    {
        if(ey < py)
        {
            return new EstadoEnemyMOVERAbajo();
        }
        if(ey > py) 
        {
            return new EstadoEnemyMOVERArriba();
        }
        return new EstadoEnemyMOVERDerecha();
    }
    if(ex > px) 
    {
        if(ey < py)
        {
            return new EstadoEnemyMOVERAbajo();
        }
        if(ey > py) 
        {
            return new EstadoEnemyMOVERArriba();
        }
        return new EstadoEnemyMOVERIzquierda();
    }
    if(ey < py)
    {
        if(ex < px)
        {
            return new EstadoEnemyMOVERDerecha();
        }
        if(ex > px) 
        {
            return new EstadoEnemyMOVERIzquierda();
        }
        return new EstadoEnemyMOVERAbajo();
    }
    if(ey > py)
    {
        if(ex < px)
        {
            return new EstadoEnemyMOVERDerecha();
        }
        if(ex > px) 
        {
            return new EstadoEnemyMOVERIzquierda();
        }
        return new EstadoEnemyMOVERArriba();
    }
    
    return NULL;

};
void EstadoEnemyIDLE_B::entrar(Enemy& enemy)
{
    frames_actual_ani = 0;
    frames_maxim_ani = 3;
};
void EstadoEnemyIDLE_B::salir(Enemy& enemy)
{
    
};
void EstadoEnemyIDLE_B::update(Enemy& enemy,double dt)
{
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
    frames_maxim_ani = 3;
    
};

FSMEnemy* EstadoEnemyMOVERDerecha::input_handle(KeyOyente& input)
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
    pos_inicial = enemy.get_posicion_mundo();
    pos_final = {pos_inicial.x + 72, pos_inicial.y};

    distancia = (pos_final.x-pos_inicial.x)/frames_maxim_ani;

};

void EstadoEnemyMOVERDerecha::salir(Enemy& enemy)
{
    if(enemy.get_posicion_mundo().x % 72 != 0)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x + ((enemy.get_posicion_mundo().x % 72)), enemy.get_posicion_mundo().y});
    }
};

void EstadoEnemyMOVERDerecha::update(Enemy& enemy,double dt)
{
    frames_actual_ani++;
    

    if(Atlas::get().indiceCuadro(enemy.get_pos_matriz(pos_inicial.x) +1, enemy.get_pos_matriz(pos_inicial.y)) != 18)
    {
        enemy.set_estado(new EstadoEnemyIDLE_D());
        return;
    }


    if(enemy.get_columna() == (InteraccionEntidades::get_entidad()->get_posicion_mundo().x/72))
    {
        enemy.set_estado(new EstadoEnemyIDLE_D());
        return;
    }
    

    enemy.get_sprite()->play_frame(1,frames_actual_ani%frames_maxim_ani);
    enemy.get_sprite()->play_frame(4,frames_actual_ani%5);
    if(frames_dt< frames_maxim_ani)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x + distancia ,enemy.get_posicion_mundo().y});
        frames_dt++;
    }
    if(frames_actual_ani > frames_maxim_ani)
    {
        enemy.set_estado(new EstadoEnemyIDLE_D());

    }

    
};

/*
MOVER IZQUIERDA
*/
EstadoEnemyMOVERIzquierda::EstadoEnemyMOVERIzquierda()
{
    strnombre = "MOVER_Izquierda";
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 3;
    
};

FSMEnemy* EstadoEnemyMOVERIzquierda::input_handle(KeyOyente& input)
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
    pos_inicial = enemy.get_posicion_mundo();
    pos_final = {pos_inicial.x - 72, pos_inicial.y};
    distancia = (pos_inicial.x-pos_final.x)/frames_maxim_ani;


};
void EstadoEnemyMOVERIzquierda::salir(Enemy& enemy)
{
    
    if(enemy.get_posicion_mundo().x % 72 != 0)
    {
        int aux = enemy.get_posicion_mundo().x / 72;
        enemy.set_posicion_mundo({72*aux, enemy.get_posicion_mundo().y});
    }
    

};
void EstadoEnemyMOVERIzquierda::update(Enemy& enemy,double dt)
{
    frames_actual_ani++;
    
    if(Atlas::get().indiceCuadro(enemy.get_pos_matriz(pos_inicial.x) -1, enemy.get_pos_matriz(pos_inicial.y)) != 18)
    {
        enemy.set_estado(new EstadoEnemyIDLE_I());
        return;
    }
    
    if(enemy.get_columna() == (InteraccionEntidades::get_entidad()->get_posicion_mundo().x/72))
    {
        enemy.set_estado(new EstadoEnemyIDLE_I());
        return;
    } 

    enemy.get_sprite()->play_frame(0,frames_actual_ani%frames_maxim_ani);
    if(frames_dt < frames_maxim_ani)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x - distancia ,enemy.get_posicion_mundo().y});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        enemy.set_estado(new EstadoEnemyIDLE_I());
        
    }

};


/*
MOVER ARRIBA
*/
EstadoEnemyMOVERArriba::EstadoEnemyMOVERArriba()
{
    strnombre = "MOVER_Arriba";
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 3;
    
};

FSMEnemy* EstadoEnemyMOVERArriba::input_handle(KeyOyente& input)
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
    pos_inicial = enemy.get_posicion_mundo();
    pos_final = {pos_inicial.x, pos_inicial.y-72};

    distancia = (pos_final.y-pos_inicial.y)/frames_maxim_ani;

};
void EstadoEnemyMOVERArriba::salir(Enemy& enemy)
{
    if(enemy.get_posicion_mundo().y % 72 != 0)
    {
        int aux = enemy.get_posicion_mundo().y / 72;
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x, aux*72});
    }

};
void EstadoEnemyMOVERArriba::update(Enemy& enemy,double dt)
{
    frames_actual_ani++;

    if(Atlas::get().indiceCuadro(enemy.get_pos_matriz(pos_inicial.x), enemy.get_pos_matriz(pos_inicial.y)-1) != 18)
    {
        enemy.set_estado(new EstadoEnemyIDLE_A());
        return;
    }
    
    if(enemy.get_fila() == (InteraccionEntidades::get_entidad()->get_posicion_mundo().y/72))
    {
        enemy.set_estado(new EstadoEnemyIDLE_A());
        return;
    }
    

    enemy.get_sprite()->play_frame(3,frames_actual_ani%frames_maxim_ani);
    if(frames_dt < frames_maxim_ani)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x,enemy.get_posicion_mundo().y + distancia});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        enemy.set_estado(new EstadoEnemyIDLE_A());

    }
    
};



/*
MOVER ABAJO
*/
EstadoEnemyMOVERAbajo::EstadoEnemyMOVERAbajo()
{
    strnombre = "MOVER_Abajo";
    velocidad = 5;
    frames_actual_ani = 0;
    frames_maxim_ani = 3;
    
};

FSMEnemy* EstadoEnemyMOVERAbajo::input_handle(KeyOyente& input)
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
    pos_inicial = enemy.get_posicion_mundo();
    pos_final = {pos_inicial.x, pos_inicial.y + 72};
    distancia = (pos_final.y-pos_inicial.y)/frames_maxim_ani; 

};
void EstadoEnemyMOVERAbajo::salir(Enemy& enemy)
{
    if(enemy.get_posicion_mundo().y % 72 != 0)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x , (enemy.get_posicion_mundo().y + (enemy.get_posicion_mundo().y % 72))});
    }
};
void EstadoEnemyMOVERAbajo::update(Enemy& enemy,double dt)
{

    frames_actual_ani++;
    
    if(Atlas::get().indiceCuadro(enemy.get_pos_matriz(pos_inicial.x), enemy.get_pos_matriz(pos_inicial.y)+1) != 18)
    {
        enemy.set_estado(new EstadoEnemyIDLE_B());
        return;
    }

    if(enemy.get_fila() == (InteraccionEntidades::get_entidad()->get_posicion_mundo().y/72))
    {
        enemy.set_estado(new EstadoEnemyIDLE_B());
        return;
    }
    
    enemy.get_sprite()->play_frame(0,frames_actual_ani%frames_maxim_ani);
    if(frames_dt < frames_maxim_ani)
    {
        enemy.set_posicion_mundo({enemy.get_posicion_mundo().x,enemy.get_posicion_mundo().y + distancia});
        frames_dt++;
    }

    if(frames_actual_ani > frames_maxim_ani)
    {
        enemy.set_estado(new EstadoEnemyIDLE_B());

    }
};