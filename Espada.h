#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#ifndef ESPADA_H
#define ESPADA_H

class Espada{
private:
    int _pos_x;
    int _pos_y;
    int _borda_base;
    int _borda_tamanho;
    bool _ativo = false;

public:
    // CRIADOR E DESTRUTOR
    Espada(int borda_base, int borda_tamanho);
    ~Espada();

    // GETTERS E SETTERS
    int getPosX();
    int getPosY();
    int getBordaBase();
    int getBordaTamanho();
    bool getAtivo();

    void setPosX(int newX);
    void setPosY(int newY);
    void setAtivo(bool newBool);

    // MÉTODOS
    //void desenhaEspada(int ultima_posicao);
    //void colisao(Inimigo &inimigo, Jogador jogador, int ultima_posicao);
};

#endif