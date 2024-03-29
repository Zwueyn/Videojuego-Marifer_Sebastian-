#pragma once
#include "Camaras.hpp"
#include "../../objetos/Objeto.hpp"
#include "../../objetos_dinamicos/ObjetoDinamico.hpp"

class ManejadorCamaras
{
    public:
        static ManejadorCamaras& get();
        static void set_camara(Camara &cam);
        static Camara& get_camara();
        static void lock_objeto(Objeto& obj);
        static void unlock_objeto();

        static void input_handle(KeyOyente &input, MouseOyente &mouse);
        static void update(std::vector<Objeto*> objetos);
        static void update(std::vector<Enemy*> objetos);
        static void set_estado(void *nuevo);
        static void* get_estado();
        static void renderizar(std::vector<Objeto*> objetos);
        static void renderizar(std::vector<Enemy*> objetos);

    private:
        ManejadorCamaras();
        static ManejadorCamaras* instancia;
        Camara *camara_actual;
};