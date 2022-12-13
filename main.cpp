#include <iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include "Espada.h"
#include "Controlador.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

//void reinicializarObjetos(Jogador jogador, Inimigo *inimigos);

// VARIÁVEIS GLOBAIS
const int LARGURA_TELA = 500;
const int ALTURA_TELA = 500;
const int FPS = 40;

enum TECLAS {CIMA, BAIXO, ESQUERDA, DIREITA, C};

int contador = 1;

int main(){

    // VARIÁVEIS
    ALLEGRO_EVENT_QUEUE *fila_eventos = nullptr;
    ALLEGRO_TIMER *timer = nullptr;
    //ALLEGRO_FONT *font14 = nullptr;

    bool teclas[] = {false, false, false, false, false};
    int ultima_posicao;
    bool fim = false;
    //bool game_over = false;
    bool desenha = true;
    
    Controlador controlador;
    Jogador jogador(100, 2, 2, 100, 100, 10);
    Espada espada(3, 30);
    Inimigo *inimigos;

    Inimigo inimigo1(100, 1, 1, LARGURA_TELA - 25, ALTURA_TELA/2, 25);
    //Inimigo inimigo2(200, 2, 2, LARGURA_TELA/2 - 50, ALTURA_TELA/2, 50);
    //Inimigo inimigo3(300, 3, 3, LARGURA_TELA/2 - 75, ALTURA_TELA/2, 75);

    inimigos[1] = inimigo1;
    //inimigos[2] = inimigo2;
    //inimigos[3] = inimigo3;

    // INICIALIZAÇÃO ALLEGRO E DISPLAY
    ALLEGRO_DISPLAY *display = nullptr;

    if(!al_init()){
        //al_show_native_message_box(nullptr, nullptr, nullptr, "Erro ao iniciar o allegro.", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        std::cout << "erro1" << std::endl;
        return -1;
    }

    display = al_create_display(LARGURA_TELA, ALTURA_TELA);

    if(!display){
        //al_show_native_message_box(display, "Título Padrão", nullptr, "Erro ao criar o display.", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        std::cout << "erro2" << std::endl;
        return -1;
    }

    // INICIALIZAÇÃO DE ADDONS E INSTALAÇÕES
    al_install_keyboard();
    al_init_primitives_addon();
    //al_init_font_addon();
    //al_init_ttf_addon();

    // CRIAÇÃO DA FILA E OUTROS DISPOSITIVOS
    fila_eventos = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);
    //font14 = al_load_font("arial.ttf", 14, 0);

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
                ultima_posicao = CIMA;
                break;
            case ALLEGRO_KEY_DOWN:
                teclas[BAIXO] = true;
                ultima_posicao = BAIXO;
                break;
            case ALLEGRO_KEY_LEFT:
                teclas[ESQUERDA] = true;
                ultima_posicao = ESQUERDA;
                break;
            case ALLEGRO_KEY_RIGHT:
                teclas[DIREITA] = true;
                ultima_posicao = DIREITA;
                break;
            case ALLEGRO_KEY_C:
                teclas[C] = true;
                espada.setAtivo(true);
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
            case ALLEGRO_KEY_C:
                teclas[C] = false;
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
                if(jogador.getPosY() < jogador.getBordaY()){
                    jogador.setPosY(jogador.getBordaY());
                }
                espada.setPosX(jogador.getPosX());
                espada.setPosY(jogador.getPosY() - jogador.getBordaY());
            }
            if(teclas[BAIXO]){
                jogador.movimentaBaixo();
                if(jogador.getPosY() > ALTURA_TELA - jogador.getBordaY()){
                    jogador.setPosY(ALTURA_TELA - jogador.getBordaY());
                }
                espada.setPosX(jogador.getPosX());
                espada.setPosY(jogador.getPosY() + jogador.getBordaY());
            }
            if(teclas[ESQUERDA]){
                jogador.movimentaEsquerda();
                if(jogador.getPosX() < jogador.getBordaX()){
                    jogador.setPosX(jogador.getBordaX());
                }
                espada.setPosY(jogador.getPosY());
                espada.setPosX(jogador.getPosX() - jogador.getBordaX());
            }
            if(teclas[DIREITA]){
                jogador.movimentaDireita();
                if(jogador.getPosX() > LARGURA_TELA - jogador.getBordaX()){
                    jogador.setPosX(LARGURA_TELA - jogador.getBordaX());
                }
                espada.setPosY(jogador.getPosY());
                espada.setPosX(jogador.getPosX() + jogador.getBordaX());
            }

            if(espada.getAtivo()){
                controlador.colisaoDarDano(espada, inimigos[1], jogador, ultima_posicao);
            }

            if(al_get_timer_count(timer) / contador == 150){
            inimigos[1].setAtacar(true);
            }

            if(jogador.getVida() <= 0){
                break;
                //game_over = true;
            }
        }

        //if(!game_over){

        // DESENHO
        if(desenha && al_is_event_queue_empty(fila_eventos)){
            desenha = false;

            if(inimigos[1].getAtacar()){
                int temp = rand() % 2;
                
                inimigos[1].ataque(espada, 0);
                jogador.colisaoReceberDano(inimigos[1], temp);
                
                inimigos[1].setAtacar(false);
                contador++;
            }            

            al_draw_filled_rectangle(jogador.getPosX()-jogador.getBordaX(), jogador.getPosY()-jogador.getBordaY(), jogador.getPosX()+jogador.getBordaX(), jogador.getPosY()+jogador.getBordaY(), al_map_rgb(0, 128, 0));

            al_draw_filled_rectangle(inimigo1.getPosX()-inimigo1.getBordaX(), inimigo1.getPosY()-inimigo1.getBordaY(), inimigo1.getPosX()+inimigo1.getBordaX(), inimigo1.getPosY()+inimigo1.getBordaY(), al_map_rgb(0, 0, 128));

            // DESENHANDO ESPADA
            if(espada.getAtivo()){
                jogador.ataque(espada, ultima_posicao);
                espada.setAtivo(false);
            }

            // VIDAS E INFORMAÇÕES
            //al_draw_text(font14, al_map_rgb(255, 255, 255), 0, 0, 0, "VIDA: %d ");

            //if(!game_over){}
            /*else{
                al_draw_text(font14, al_map_rgb(255, 255, 255), ALTURA_TELA / 2, LARGURA_TELA / 2, ALLEGRO_ALIGN_CENTER, "VOCÊ MORREU. PRECIONE ESC PARA SAIR.");

                if(teclas[ENTER]){
                    reinicializarObjetos(jogador, inimigos);
                    game_over = false;
                }
            }*/

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

/*void reinicializarObjetos(Jogador jogador, Inimigo *inimigos){
    jogador.setVida(100);
    jogador.setPosX(100);
    jogador.setPosY(100);

    inimigos[1].setVida(100);
    //inimigos[2].setVida(200);
    //inimigos[3].setVida(300);
}*/