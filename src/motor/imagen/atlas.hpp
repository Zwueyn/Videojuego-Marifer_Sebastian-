#pragma once
#include "../../utilidad/Estructuras.hpp"
#include "../../objetos_estaticos/ObjetoEstatico.hpp"
#include<string>
#include<SDL.h>

class Atlas
{
    public:
        //Atlas(std::string atlas);
        //~Atlas();
        static Atlas& get();
        static bool cargar_textura(SDL_Renderer *r);
        static void generar_mapa(SDL_Renderer *r,int idflip,int notidobjfisicos);
        static std::vector<ObjetoEstatico*> get_objetos_fisicos();
        static int indiceCuadro(int fila, int columna);

    private:
        Atlas();
        static Atlas* instancia;
        AtlasInfo info;
        std::vector<ObjetoEstatico*> objetos_fisicos;
        SDL_Texture *atlas_sheet;
        
};