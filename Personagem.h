#ifndef PERSONAGEM_H
#define PERSONAGEM_H

class Personagem{
protected:
    // ARGUMENTOS DA CLASSE
    int _vida;
    int _ataque;
    int _defesa;

    //
    int _pos_x;
    int _pos_y;
    int _borda_x;
    int _borda_y;

public:
    // CRIADOR E DESTRUTOR
    Personagem(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda);
    ~Personagem();

    // GETTERS E SETTERS
    int getVida();
    int getAtaque();
    int getDefesa();

    int getPosX();
    int getPosY();
    int getBordaX();
    int getBordaY();

    void setVida(int newVida);
    void setAtaque(int newAtaque);
    void setDefesa(int newDefesa);

    void setPosX(int newX);
    void setPosY(int newY);

    // MÉTODOS
    void virtual ataqueNormal() = 0;
    void virtual ataqueForte() = 0;
    void virtual defender() = 0;
};

#endif