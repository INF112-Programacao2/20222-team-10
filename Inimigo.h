#include "Personagem.h"

#ifndef INIMIGO_H
#define INIMIGO_H

class Inimigo: public Personagem{
private:
public:
    Inimigo(int vida, int ataque, int defesa, int pos_x, int pos_y);
    ~Inimigo();

    void virtual IA();
    void ataqueNormal() override;
    void ataqueForte() override;
    void defender() override;
};

#endif