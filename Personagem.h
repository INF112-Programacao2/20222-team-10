#ifndef PERSONAGEM_H
#define PERSONAGEM_H

class Personagem{
protected:
    // ARGUMENTOS DA CLASSE
    int _vida;
    int _ataque;
    int _defesa;

    int const _velocidade = 7;
    int _pos_x;
    int _pos_y;
    int _borda_x;
    int _borda_y;

public:
    // CRIADOR E DESTRUTOR
    Personagem(int vida, int ataque, int defesa, int pos_x, int pos_y);
    ~Personagem();

    // GETTERS E SETTERS
    int getVida();
    int getAtaque();
    int getDefesa();

    int getVelocidade();
    int getPosX();
    int getPosY();

    void setPosX(int newX);
    void setPosY(int newY);

    // MÉTODOS
    void virtual ataqueNormal() = 0;
    void virtual ataqueForte() = 0;
    void virtual defender() = 0;

    void movimentaCima();
    void movimentaBaixo();
    void movimentaEsquerda();
    void movimentaDireita();
};

#endif