#ifndef PERSONAGEM_H
#define PERSONAGEM_H

class Personagem{
protected:
    // 
    int _vida;
    int _ataque;
    int _defesa;

public:
    // CRIADOR E DESTRUIDOR
    Personagem(int vida, int ataque, int defesa);
    ~Personagem();

    // GETTERS E SETTERS
    int getVida();
    int getAtaque();
    int getDefesa();

    // MÉTODOS
    void virtual ataqueNormal() = 0;
    void virtual ataqueForte() = 0;
    void virtual defender() = 0;
};

#endif