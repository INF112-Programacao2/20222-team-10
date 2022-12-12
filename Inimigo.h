#include "Personagem.h"

#ifndef INIMIGO_H
#define INIMIGO_H

class Inimigo: public Personagem{
private:
public:
    // CRIADOR E DESTRUTOR
    Inimigo(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda);
    ~Inimigo();

    void virtual IA();
    void ataqueNormal() override;
    void ataqueForte() override;
    void defender() override;
};

#endif