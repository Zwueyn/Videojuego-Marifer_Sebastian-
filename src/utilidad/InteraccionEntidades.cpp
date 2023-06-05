#include "InteraccionEntidades.hpp"
#include "time.h"
#include <iostream>
#include <fstream>

InteraccionEntidades* InteraccionEntidades::instancia = 0;

InteraccionEntidades::InteraccionEntidades()
{

};

InteraccionEntidades& InteraccionEntidades::get()
{
    if(!instancia)
        instancia = new InteraccionEntidades();
    return *instancia;
};

bool InteraccionEntidades::adyacentes(ObjetoDinamico *a, Enemy *b)
{
    get().columnaUno = a->get_posicion_mundo().x/72;
    get().columnaDos = b->get_posicion_mundo().x/72;
    get().filaUno = a->get_posicion_mundo().y/72;
    get().filaDos = b->get_posicion_mundo().y/72;
    bool adyacentes = false;
    if((get().columnaUno == get().columnaDos) && (get().filaUno == get().filaDos))
    {
        adyacentes = true;
    } else
    {
        if((get().columnaUno - get().columnaDos == 1 || (get().columnaUno - get().columnaDos) == -1) && get().filaUno == get().filaDos)
        {
            adyacentes = true;
        }
        if((get().filaUno - get().filaDos == 1 || get().filaUno - get().filaDos == -1) && get().columnaUno == get().columnaDos)
        {
            adyacentes = true;
        }
    }
    
    return adyacentes;

};

int InteraccionEntidades::posicionFila(ObjetoDinamico *a)
{
    return a->get_posicion_mundo().y/72;
};

int InteraccionEntidades::posicionColumna(ObjetoDinamico *a)
{
    return a->get_posicion_mundo().x/72;
};

void InteraccionEntidades::set_entidad(ObjetoDinamico *e)
{
    get().entidad = e;
};

ObjetoDinamico* InteraccionEntidades::get_entidad()
{
    return get().entidad;
};

ObjetoDinamico* InteraccionEntidades::get_enemigo()
{
    return get().enemigo;
};

void InteraccionEntidades::set_enemigo(ObjetoDinamico *e)
{
    get().enemigo = e;
};

void InteraccionEntidades::set_enemigo()
{
    get().enemigo = NULL;
};

void InteraccionEntidades::set_target(ObjetoDinamico *e)
{
    get().target = e;
};


void InteraccionEntidades::combate()
{
    srand(time(NULL));
    int critico = rand() % 10;
    int esquive = rand() % 30;
    int multiplicadorEnemigo = 1;
    int multiplicadorPlayer = 1;
    if(critico == 3)
    {
        multiplicadorPlayer = 2;
        if(esquive == 29)
        {
            multiplicadorPlayer = 0;
        }
        
    }
    if(critico == 7)
    {
        multiplicadorEnemigo = 2;
        if(esquive == 0)
        {
            multiplicadorEnemigo = 0;
        }
    }
    get().target->set_hp(get().target->get_hp() - (get().entidad->get_dmg() * multiplicadorEnemigo));
    get().entidad->set_hp(get().entidad->get_hp() - (get().target->get_dmg() * multiplicadorPlayer));

};