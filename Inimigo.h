#include "Personagem.h"
#include "Espada.h"

#ifndef INIMIGO_H
#define INIMIGO_H

class Inimigo: public Personagem{
private:
    bool _atacar = false;
public:
    // CRIADOR E DESTRUTOR
    Inimigo(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda);
    ~Inimigo();

    bool getAtacar();

    void setAtacar(bool newAtacar);

    //void desenhaAtaque1();
    //void desenhaAtaque2();
    void ataque(Espada espada, int ultima_posicao) override;
};

#endif