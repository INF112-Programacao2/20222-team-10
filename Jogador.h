#include "Personagem.h"

#ifndef JOGADOR_H
#define JOGADOR_H


class Jogador: public Personagem{
private:
    int itens[5];
    int const _velocidade = 5;

public:
    // CRIADOR E DESTRUTOR
    Jogador(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda);
    ~Jogador();

    int getVelocidade();

    void ataqueNormal() override;
    void ataqueForte() override;
    void defender() override;

    void movimentaCima();
    void movimentaBaixo();
    void movimentaEsquerda();
    void movimentaDireita();
};

#endif