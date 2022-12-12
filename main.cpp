#include <iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include "Controlador.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

/*const float FPS = 8;
const int SCREEN_W = 500;
const int SCREEN_H = 500;
const int QUAD_SIZE = 20;

enum MYKEYS{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_TIMER *timer = nullptr;
ALLEGRO_BITMAP *mapa   = nullptr;

bool key[4] = {false, false, false, false};
bool redraw = true;
bool sair = false;
bool cima, baixo, esq, dir;*/

enum TECLAS {CIMA, BAIXO, ESQUERDA, DIREITA};

int main() {

    ALLEGRO_BITMAP *mapa = NULL;
    ALLEGRO_BITMAP *personagem = NULL;

    // VARIÁVEIS
    char Mapa1[26][26] =
    {
        "111111111111111111111111",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "111111111111111111111111",
    };

    char Mapa2[26][26] =
    {
        "111111111111111111111111",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000222222200000001",
        "100000000222222200000001",
        "100000000222222200000001",
        "100000000222222200000001",
        "100000000222222200000001",
        "100000000222222200000001",
        "100000000222222200000001",
        "100000000222222200000001",
        "100000000222222200000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "100000000000000000000001",
        "111111111111111111111111",
    };

    char Mapa3[26][26] =
    {
        "111111111111111111111111",
        "133300000000000000333331",
        "133300000000000000333331",
        "133300000000000000333331",
        "100000000000000000000331",
        "100000000000000000000331",
        "100000333330000000000001",
        "100000333330000000000001",
        "100000333330000000000001",
        "100000000000000000000001",
        "100000000000000333000001",
        "100000000000000333000001",
        "100000000000000333000001",
        "100000000000000333000001",
        "100000000000000333000001",
        "100000000000000000000001",
        "100000333330000000000001",
        "100000333330000000000001",
        "100000333330000000000001",
        "100000000000000000000331",
        "100000000000000000000331",
        "133300000000000000333331",
        "133300000000000000333331",
        "133300000000000000333331",
        "111111111111111111111111",
    };
    //Controlador overlord;
    //overlord.Controlador();
    // Jogador player;
    
    const int largura_tela = 500;
    const int altura_tela = 500;

    int pos_x = 20;
    int pos_y = 20;
    bool teclas[] = {false, false, false, false};

    bool fim = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

    // INICIALIZAÇÃO ALLEGRO E DISPLAY
    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init_image_addon())
    {
        std::cout <<"Falha ao iniciar al_init_image_addon!" << std::endl;
        return 0;
    }

    if(!al_init()){
        std::cout << "Erro ao inicializar o allegro." << std::endl;
        return -1;
    }

    display = al_create_display(largura_tela, altura_tela);

    if(!display){
        std::cout << "Erro ao criar display." << std::endl;
        return -1;
    }

    mapa = al_load_bitmap("map1.bmp");
    if(!mapa)
    {
        std::cout << "Falha ao carregar o mapa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    personagem = al_load_bitmap("personagem.bmp");
    if(!personagem)
    {
        std::cout << "Falha ao carregar o personagem!" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    al_draw_bitmap(mapa,0,0,0);
    al_draw_bitmap(personagem,0,0,0);
    al_flip_display();

    // INICIALIZAÇÃO DE ADDONS E INSTALAÇÕES
    al_install_keyboard();

    // CRIAÇÃO DA FILA E OUTROS DISPOSITIVOS
    fila_eventos = al_create_event_queue();
    al_init_primitives_addon();

    // REGISTRO DE SOURCES
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(display));

    // LOOP PRINCIPAL
    while(!fim){
        ALLEGRO_EVENT ev;

        al_wait_for_event(fila_eventos, &ev);

        // EVENTOS E LÓGICA DO JOGO
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                fim = true;
            }
            switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                teclas[CIMA] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                teclas[BAIXO] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                teclas[ESQUERDA] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                teclas[DIREITA] = true;
                break;
            }
        }

        if(ev.type == ALLEGRO_EVENT_KEY_UP){
            switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                teclas[CIMA] = false;
                break;
            case ALLEGRO_KEY_DOWN:
                teclas[BAIXO] = false;
                break;
            case ALLEGRO_KEY_LEFT:
                teclas[ESQUERDA] = false;
                break;
            case ALLEGRO_KEY_RIGHT:
                teclas[DIREITA] = false;
                break;
            }
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            fim = true;
        }

        if(Mapa1[pos_x/20][(pos_y/20)-1]!='1') 
            pos_y -= teclas[CIMA] * 20;

        if(Mapa1[pos_x/20][(pos_y/20)]!='1')
            pos_y += teclas[BAIXO] * 20;

        if(pos_x>20) 
            pos_x -= teclas[ESQUERDA] * 20;

        if(pos_x<460)
            pos_x += teclas[DIREITA] * 20;

        

       // if(overlord._cont=='3') {
        //    if(overlord.mapa1[pos_x/20][pos_y/20]==2)
         //       player.setVida(getVida()-1);
       // }
            

        // DESENHO
       // if(overlord.escolherMapa(int vidaInimigo)=='1')
            mapa = al_load_bitmap("map1.bmp");
        //if(overlord.escolherMapa(int vidaInimigo)=='2')
         //   mapa = al_load_bitmap("map2.bmp");
       // if(overlord.escolherMapa(int vidaInimigo)=='3')
          //  mapa = al_load_bitmap("map3.bmp");
        al_draw_bitmap(mapa,0,0,0);
        al_draw_bitmap(personagem,pos_x,pos_y,0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
    }


    // FINALIZAÇÃO DO PROGRAMA
    al_destroy_display(display);
    al_destroy_event_queue(fila_eventos);

    return 0;
}