#pragma once
#include "../objetos/Objeto.hpp"
#include "../motor/Pipeline.hpp"
#include "../objetos_dinamicos/ObjetoDinamico.hpp"
#include <SDL.h>

class Spawner
{
    public:
        Spawner(int x, int y, int sw, int sh, SDL_Color c, Pipeline &p); //Constructor igual que enemy

        void spawn(std::vector<Enemy*> *lista);
        void despawn(std::vector<Enemy*> *lista);
        void update(std::vector<Enemy*> *lista);
        void set_velocidad(int v);

    private:
        std::vector<Enemy*> objetos;
        Jugador *jugador;
        std::string sprite_path;
        SDL_Color colordebug;
        int x; //posicion x
        int y; //posicion y
        int w; //ancho del sprite
        int h; //alto del sprite
        int sw; //ancho mostrar sprite
        int sh; //alto mostrar sprite
        int v; //vida del sprite
        int objetos_activos;
        int delay;
        double init_tiempo;
        int past_tiempo;
        bool check;
        Pipeline *pipeline;
        int velocidad;

};