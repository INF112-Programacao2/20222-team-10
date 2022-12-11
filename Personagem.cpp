#include "Personagem.h"

Personagem::Personagem(int vida, int ataque, int defesa, int pos_x, int pos_y){
    _vida = vida;
    _ataque = ataque;
    _defesa = defesa;
    _pos_x = pos_x;
    _pos_y = pos_y;
}

Personagem::~Personagem(){}

void Personagem::movimentaCima(){
    this->setPosY(this->getPosY() - getVelocidade());
}

void Personagem::movimentaBaixo(){
    this->setPosY(this->getPosY() + getVelocidade());
}

void Personagem::movimentaEsquerda(){
    this->setPosX(this->getPosX() - getVelocidade());
}

void Personagem::movimentaDireita(){
    this->setPosX(this->getPosX() + getVelocidade());
}

int Personagem::getAtaque(){
    return _ataque;
}

int Personagem::getDefesa(){
    return _defesa;
}

int Personagem::getVida(){
    return _vida;
}

int Personagem::getPosX(){
    return _pos_x;
}

int Personagem::getPosY(){
    return _pos_y;
}

int Personagem::getVelocidade(){
    return _velocidade;
}

void Personagem::setPosX(int newX){
    _pos_x = newX;
}

void Personagem::setPosY(int newY){
    _pos_y = newY;
}