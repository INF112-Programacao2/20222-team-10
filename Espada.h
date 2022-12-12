#ifndef ESPADA_H
#define ESPADA_H

class Espada{
private:
    int _pos_x;
    int _pos_y;
    bool _ativo = true;

public:
    // CRIADOR E DESTRUTOR
    Espada(int pos_X, int pos_y);
    ~Espada();

    // GETTERS E SETTERS
    int getPosX();
    int getPosY();
    void setPosX(int new_x);
    void setPosY(int new_y);

    // MÉTODOS
};

#endif