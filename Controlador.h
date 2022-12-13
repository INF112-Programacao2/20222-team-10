#include "Jogador.h"
#include "Inimigo.h"
#include "Espada.h"

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

class Controlador{
private:
    int mapa1[20][20];
    int mapa2[20][20];
    int mapa3[20][20];
    
public:
    Controlador();
    ~Controlador();

    void escolherMapa();
    void colisaoDarDano(Espada espada, Inimigo &inimigo, Jogador jogador, int ultima_posicao);
};

#endif