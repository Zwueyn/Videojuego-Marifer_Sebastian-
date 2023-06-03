#include "atlas.hpp"
#include <iostream>
#include <fstream>


Atlas* Atlas::instancia = 0;

Atlas::Atlas()
{
    info.archivo_ids = "assets/sprites/mundo/ids/mundo_ids.txt";
    
};

Atlas& Atlas::get()
{
    if(!instancia)
        instancia = new Atlas();
    return *instancia;
};

bool Atlas::cargar_textura(SDL_Renderer *r)
{
    get().atlas_sheet = IMG_LoadTexture(r,get().info.archivo_atlas.c_str());
    if(!get().atlas_sheet)
    {
        std::cout<<SDL_GetError()<<"\n";
        return false;
    }
    return true;
};
void Atlas::generar_mapa(SDL_Renderer *r,int idflip,int notidobjfisicos)
{
    std::ifstream archivo;
    archivo.open(get().info.archivo_ids.c_str());
    if(!archivo.is_open())
    {
        std::cout<<"El archivo "<<get().info.archivo_ids<<" no se pudo abrir por:\n"<<SDL_GetError();
        exit(EXIT_FAILURE);
    }


    //cargar la cantidad de tiles y su tamaño
    int renglon,columna;
    archivo >> get().info.archivo_atlas;
    printf("Archivo del atlas: %s\n",get().info.archivo_atlas.c_str());
    if(!cargar_textura(r))
    {
        exit(EXIT_FAILURE);
    }
    archivo >> renglon >> columna;
    get().info.renglones = renglon;
    get().info.columnas = columna;
    printf("Mundo tiene %d ancho y %d alto\n",renglon, columna);
    
    archivo >> get().info.tile_width >> get().info.tile_height;
    printf("Tamaño de los tiles (%dx%d)\n",get().info.tile_width,get().info.tile_height);

    archivo >> get().info.num_tiles_ancho >> get().info.num_tiles_alto;
    printf("Atlas tiles ancho=%d\nAtlas tiles alto=%d\n",get().info.num_tiles_ancho,get().info.num_tiles_alto);

    archivo >>get().info.atlas_width >> get().info.atlas_height;
    printf("Atlas width=%d\nAtlas height=%d\n",get().info.atlas_width,get().info.atlas_height);
    // inicializar la matriz
    //inicializar la matriz de ids en 0;
    for(int i=0;i<columna;++i)
    {
        std::vector<int> temp;
        for(int j=0;j<renglon;++j)
        {
            temp.push_back(0);
        }
        get().info.mapa_ids.push_back(temp);
    }
    //llenar matriz_ids
    for(int i=0;i<columna;++i)
    {
        printf("[ ");
        for(int j=0;j<renglon;++j)
        {
            archivo>>get().info.mapa_ids[i][j];
            printf("%d,",get().info.mapa_ids[i][j]);
            
            TileInfo tile
            {
                SDL_RendererFlip::SDL_FLIP_NONE,                            //flip
                0.0,                                                        //angulo
                {(get().info.mapa_ids[i][j]%get().info.num_tiles_ancho)*get().info.tile_width,
                (get().info.mapa_ids[i][j]/get().info.num_tiles_ancho)*get().info.tile_height,get().info.tile_width,get().info.tile_height},//srcRect
                {j*72,i*72,72,72},//dstRect
                get().atlas_sheet,//source
                {j*72,i*72},//pos
                72,//width
                72//height
            };
            //objetos_fisicos.push_back(new Plataformas(j*t_width,i*t_height,t_width,t_height,{0,0,0,255}));
            bool tiene_colision = false;//(info.mapa_ids[i][j]==notidobjfisicos) ? false : true;
            get().objetos_fisicos.push_back(new Plataformas(tile,tiene_colision));
        }
        printf("]\n");
    }


    printf("Objetos -> %d\n",(int)get().objetos_fisicos.size());
    //cerrar archivo
    archivo.close();
};

std::vector<ObjetoEstatico*> Atlas::get_objetos_fisicos() 
{
    return get().objetos_fisicos;
};

int Atlas::indiceCuadro(int fila, int columna)
{
    return get().info.mapa_ids[columna][fila];
};