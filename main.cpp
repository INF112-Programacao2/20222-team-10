#include <iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include "Controlador.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

// VARIÁVEIS GLOBAIS
const int largura_tela = 640;
const int altura_tela = 480;
const int FPS = 60;

enum TECLAS {CIMA, BAIXO, ESQUERDA, DIREITA, A, S, D};

int main(){

    // VARIÁVEIS
    ALLEGRO_EVENT_QUEUE *fila_eventos = nullptr;
    ALLEGRO_TIMER *timer = nullptr;

    bool teclas[] = {false, false, false, false, false, false, false};
    bool fim = false;
    bool desenha = true;

    Jogador jogador(100, 2, 2, 100, 100);

    // INICIALIZAÇÃO ALLEGRO E DISPLAY
    ALLEGRO_DISPLAY *display = nullptr;

    if(!al_init()){
        std::cout << "Erro ao inicializar o allegro." << std::endl;
        return -1;
    }

    display = al_create_display(largura_tela, altura_tela);

    if(!display){
        std::cout << "Erro ao criar display." << std::endl;
        return -1;
    }

    // INICIALIZAÇÃO DE ADDONS E INSTALAÇÕES
    al_install_keyboard();
    al_init_primitives_addon();

    // CRIAÇÃO DA FILA E OUTROS DISPOSITIVOS
    fila_eventos = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

    // REGISTRO DE SOURCES
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(display));
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    // LOOP PRINCIPAL
    al_start_timer(timer);

    while(!fim){
        ALLEGRO_EVENT ev;

        al_wait_for_event(fila_eventos, &ev);

        // EVENTOS E LÓGICA DO JOGO
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_ESCAPE:
                fim = true;
                break;
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
            case ALLEGRO_KEY_A:
                teclas[A] = true;
                break;
            case ALLEGRO_KEY_S:
                teclas[S] = true;
                break;
            case ALLEGRO_KEY_D:
                teclas[D] = true;
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
            case ALLEGRO_KEY_A:
                teclas[A] = false;
                break;
            case ALLEGRO_KEY_S:
                teclas[S] = false;
                break;
            case ALLEGRO_KEY_D:
                teclas[D] = false;
                break;
            }
        }

        // FECHA O JOGO COM O 'X'
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            fim = true;
        }

        else if(ev.type == ALLEGRO_EVENT_TIMER){
            desenha = true;

            if(teclas[CIMA]){
                jogador.movimentaCima();
            }
            if(teclas[BAIXO]){
                jogador.movimentaBaixo();
            }
            if(teclas[ESQUERDA]){
                jogador.movimentaEsquerda();
            }
            if(teclas[DIREITA]){
                jogador.movimentaDireita();
            }
        }

        // DESENHO
        if(desenha && al_is_event_queue_empty(fila_eventos)){
            al_draw_filled_rectangle(jogador.getPosX()-15, jogador.getPosY()-15, jogador.getPosX()+15, jogador.getPosY()+15, al_map_rgb(0, 128, 0));

            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
    }


    // FINALIZAÇÃO DO PROGRAMA
    al_destroy_display(display);
    al_destroy_event_queue(fila_eventos);
    al_destroy_timer(timer);

    return 0;
}