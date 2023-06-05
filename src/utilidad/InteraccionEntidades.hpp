#pragma once
#include "Estructuras.hpp"
#include "../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../objetos/Objeto.hpp"
#include <string>
#include <SDL.h>
#include <vector>

class InteraccionEntidades
{
    public: 
        static InteraccionEntidades& get();
        static bool adyacentes(ObjetoDinamico *a, Enemy *b);
        static int posicionFila(ObjetoDinamico *a);
        static int posicionColumna(ObjetoDinamico *a);
        static void set_entidad(ObjetoDinamico *e);
        static ObjetoDinamico* get_entidad();
        static ObjetoDinamico* get_enemigo();
        static void set_target(ObjetoDinamico *e);
        static void set_enemigo(ObjetoDinamico *e);
        static void set_enemigo();
        static void combate();

    private:
        InteraccionEntidades();
        static InteraccionEntidades* instancia;
        int columnaUno;
        int columnaDos;
        int filaUno;
        int filaDos;

        //std::vector<ObjetoDinamico*> objetos;
        ObjetoDinamico *entidad;
        ObjetoDinamico *enemigo;
        ObjetoDinamico *target;

};