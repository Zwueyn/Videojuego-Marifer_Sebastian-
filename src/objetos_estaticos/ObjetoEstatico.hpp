#pragma once
#include "../objetos/Objeto.hpp"
#include "../utilidad/Estructuras.hpp"
#include "../motor/imagen/tiles.hpp"
#include <SDL.h>

class ObjetoEstatico : public Objeto
{
    public:
        virtual ~ObjetoEstatico(){};
        virtual void update(double dt) = 0;

};

class Plataformas : public ObjetoEstatico
{
    public:
        virtual ~Plataformas(){};
        Plataformas(int x, int y, int w, int h, SDL_Color color);
        Plataformas(TileInfo tiles,bool colision);
        void update(double dt);
    
};

class Background : public ObjetoEstatico{
    public:
        virtual ~Background(){};
        Background(std::string path_sprite,int x, int y, int w, int h);
        void update(double dt);
};
