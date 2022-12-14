#include "Jogador.h"
#include "Inimigo.h"
#include <iostream>

Jogador::Jogador(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda): Personagem(vida, ataque, defesa, pos_x, pos_y, borda){}

Jogador::~Jogador(){}

int Jogador::getVelocidade(){
    return _velocidade;
}

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

void Jogador::colisaoAtaque1(Inimigo inimigo){
    if(this->getPosX() + this->getBordaX() > inimigo.getPosX()-(3*inimigo.getBordaX()) &&
    this->getPosX() - this->getBordaX() < inimigo.getPosX()+(3*inimigo.getBordaX()) &&
    this->getPosY() + this->getBordaY() > inimigo.getPosY()-(3*inimigo.getBordaY()) &&
    this->getPosY() - this->getBordaY() < inimigo.getPosY()+(3*inimigo.getBordaY())){
        this->setVida(this->getVida() - (inimigo.getAtaque() * 3) - this->getDefesa());
        std::cout << this->getVida() << std::endl;
    }
}

void Jogador::colisaoAtaque2(Inimigo inimigo){
    if(this->getPosY() - this->getBordaY() < inimigo.getPosY() + inimigo.getBordaY() &&
    this->getPosY() + this->getBordaY() > inimigo.getPosY() - inimigo.getBordaY()){
        this->setVida(this->getVida() - (inimigo.getAtaque() * 3) - this->getDefesa());
        std::cout << this->getVida() << std::endl;
    }
}