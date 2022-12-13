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

void Jogador::colisaoReceberDano(Inimigo inimigo, int qualAtaque){
    //if(qualAtaque == 0){
        if(this->getPosX() + this->getBordaX() > inimigo.getPosX()-(3*inimigo.getBordaX()) &&
        this->getPosX() - this->getBordaX() < inimigo.getPosX()+(3*inimigo.getBordaX()) &&
        this->getPosY() + this->getBordaY() > inimigo.getPosY()-(3*inimigo.getBordaY()) &&
        this->getPosY() - this->getBordaY() < inimigo.getPosY()+(3*inimigo.getBordaY())){
            this->setVida(this->getVida() - (inimigo.getAtaque() * 3) - this->getDefesa());
            std::cout << this->getVida() << std::endl;
        }
    /*}
    else if(qualAtaque == 1){
        if(this->getPosY() - this->getBordaY() < inimigo.getPosY() + inimigo.getBordaY() &&
        this->getPosY() + this->getBordaY() > inimigo.getPosY() - inimigo.getBordaY()){
            this->setVida(this->getVida() - (inimigo.getAtaque() * 3) - this->getDefesa());
            std::cout << this->getVida() << std::endl;
        }
    }*/
    
}

void Jogador::ataque(Espada espada, int ultima_posicao){
    switch(ultima_posicao){
    case 0:
        al_draw_filled_rectangle(espada.getPosX()-espada.getBordaBase(), espada.getPosY(), espada.getPosX()+espada.getBordaBase(), espada.getPosY()-espada.getBordaTamanho(), al_map_rgb(128, 0, 0));
        break;
    case 1:
        al_draw_filled_rectangle(espada.getPosX()-espada.getBordaBase(), espada.getPosY(), espada.getPosX()+espada.getBordaBase(), espada.getPosY()+espada.getBordaTamanho(), al_map_rgb(128, 0, 0));
        break;
    case 2:
        al_draw_filled_rectangle(espada.getPosX(), espada.getPosY()+espada.getBordaBase(), espada.getPosX()-espada.getBordaTamanho(), espada.getPosY()-espada.getBordaBase(), al_map_rgb(128, 0, 0));
        break;
    case 3:
        al_draw_filled_rectangle(espada.getPosX(), espada.getPosY()+espada.getBordaBase(), espada.getPosX()+espada.getBordaTamanho(), espada.getPosY()-espada.getBordaBase(), al_map_rgb(128, 0, 0));
        break;
    }
}