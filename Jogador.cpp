#include "Jogador.h"

Jogador::Jogador(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda): Personagem(vida, ataque, defesa, pos_x, pos_y, borda){}

Jogador::~Jogador(){}

int Jogador::getVelocidade(){
    return _velocidade;
}

void Jogador::ataqueNormal(){}

void Jogador::ataqueForte(){}

void Jogador::defender(){}

void Jogador::movimentaCima(){
    this->setPosY(this->getPosY() - getVelocidade());
}

void Jogador::movimentaBaixo(){
    this->setPosY(this->getPosY() + getVelocidade());
}

void Jogador::movimentaEsquerda(){
    this->setPosX(this->getPosX() - getVelocidade());
}

void Jogador::movimentaDireita(){
    this->setPosX(this->getPosX() + getVelocidade());
}