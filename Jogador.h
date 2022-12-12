#include "Personagem.h"

#ifndef JOGADOR_H
#define JOGADOR_H

class Jogador: public Personagem{
private:
    int itens[5];

public:
    Jogador(int vida, int ataque, int defesa);
    ~Jogador();

    void ataqueNormal() override;
    void ataqueForte() override;
    void defender() override;
};

#endif