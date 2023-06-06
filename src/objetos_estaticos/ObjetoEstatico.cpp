#include "ObjetoEstatico.hpp"

Plataformas::Plataformas(int x, int y, int w, int h, SDL_Color color)
:ObjetoEstatico{} //llamar constructor padre
{
    posicion_mundo.x=x;
    posicion_mundo.y=y;
    posicion_camara.x = posicion_mundo.x;
    posicion_camara.y = posicion_mundo.y;
    avatar = new Rectangulo(x,y,w,h,color);
    avatar->set_rellenocolor(color);
    avatar->set_serellena(false);
    col_box = new Rectangulo(x,y,w+5,h+5,{0,255,0,255});
    tiene_fisica=false;
    en_colision=false;
    sprite = nullptr;
};

Plataformas::Plataformas(TileInfo tiles, bool colision)
{
    avatar=nullptr;
    sprite = nullptr;
    posicion_mundo = tiles.pos;
    posicion_camara = posicion_mundo;
    col_box = new Rectangulo(posicion_camara.x-(tiles.width/2),posicion_camara.y-(tiles.height/2),tiles.width,tiles.height,{0,255,0,255});
    tiene_fisica=colision;
    en_colision=false;
    tile = new Tile(tiles);
    
};

void Plataformas::update(double dt)
{

};

Background::Background(std::string path_sprite, int x, int y, int w, int h): ObjetoEstatico{} {
    posicion_mundo.x=x;
    posicion_mundo.y=y;
    avatar = new Rectangulo(x,y,w,h,color);
    avatar->set_rellenocolor(color);
    avatar->set_serellena(true);
    col_box = new Rectangulo(x,y,w+5,h+5,{0,255,0,255});
    tiene_fisica=false;
    en_colision=false;
    tile=nullptr;
    sprite = new Sprite(path_sprite,{x,y},w,h,w,h);
}

void Background::update(double dt)
{

};
