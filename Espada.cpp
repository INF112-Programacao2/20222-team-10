#include "Espada.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

Espada::Espada(int borda_base, int borda_tamanho){
    _borda_base = borda_base;
    _borda_tamanho = borda_tamanho;
}

Espada::~Espada(){}

int Espada::getPosX(){
    return _pos_x;
}

int Espada::getPosY(){
    return _pos_y;
}

int Espada::getBordaBase(){
    return _borda_base;
}

int Espada::getBordaTamanho(){
    return _borda_tamanho;
}

bool Espada::getAtivo(){
    return _ativo;
}

void Espada::setPosX(int newX){
    _pos_x = newX;
}

void Espada::setPosY(int newY){
    _pos_y = newY;
}

void Espada::setAtivo(bool newBool){
    _ativo = newBool;
}

/*void Espada::desenhaEspada(int ultima_posicao){
    switch(ultima_posicao){
    case 0:
        al_draw_filled_rectangle(this->getPosX()-this->getBordaBase(), this->getPosY(), this->getPosX()+this->getBordaBase(), this->getPosY()-this->getBordaTamanho(), al_map_rgb(128, 0, 0));
        break;
    case 1:
        al_draw_filled_rectangle(this->getPosX()-this->getBordaBase(), this->getPosY(), this->getPosX()+this->getBordaBase(), this->getPosY()+this->getBordaTamanho(), al_map_rgb(128, 0, 0));
        break;
    case 2:
        al_draw_filled_rectangle(this->getPosX(), this->getPosY()+this->getBordaBase(), this->getPosX()-this->getBordaTamanho(), this->getPosY()-this->getBordaBase(), al_map_rgb(128, 0, 0));
        break;
    case 3:
        al_draw_filled_rectangle(this->getPosX(), this->getPosY()+this->getBordaBase(), this->getPosX()+this->getBordaTamanho(), this->getPosY()-this->getBordaBase(), al_map_rgb(128, 0, 0));
        break;
    }
}*/

/*void Espada::colisao(Inimigo &inimigo, Jogador jogador, int ultima_posicao){
    switch(ultima_posicao){
    case 0:     // CIMA
        if((this->getPosY() - this->getBordaTamanho()) < (inimigo.getPosY() + inimigo.getBordaY()) && 
        (this->getPosY() + this->getBordaTamanho()) > (inimigo.getPosY() - inimigo.getBordaY()) &&
        (this->getPosX() - this->getBordaBase()) < (inimigo.getPosX() + inimigo.getBordaX()) &&
        (this->getPosX() + this->getBordaBase()) > (inimigo.getPosX() - inimigo.getBordaX())){
            inimigo.setVida(inimigo.getVida() - ((jogador.getAtaque() * 5) - inimigo.getDefesa()));
            std::cout << inimigo.getVida() << std::endl;
        }
        break;
    case 1:     // BAIXO
        if((this->getPosY() + this->getBordaTamanho()) > (inimigo.getPosY() - inimigo.getBordaY()) && 
        (this->getPosY() - this->getBordaTamanho()) < (inimigo.getPosY() + inimigo.getBordaY()) &&
        (this->getPosX() + this->getBordaBase()) > (inimigo.getPosX() - inimigo.getBordaX()) &&
        (this->getPosX() - this->getBordaBase()) < (inimigo.getPosX() + inimigo.getBordaX())){
            inimigo.setVida(inimigo.getVida() - ((jogador.getAtaque() * 5) - inimigo.getDefesa()));
            std::cout << inimigo.getVida() << std::endl;
        }
        break;
    case 2:     // ESQUERDA
        if((this->getPosX() - this->getBordaTamanho()) < (inimigo.getPosX() + inimigo.getBordaX()) && 
        (this->getPosX() + this->getBordaTamanho()) > (inimigo.getPosX() - inimigo.getBordaX()) &&
        (this->getPosY() - this->getBordaBase()) < (inimigo.getPosY() + inimigo.getBordaY()) &&
        (this->getPosY() + this->getBordaBase()) > (inimigo.getPosY() - inimigo.getBordaY())){
            inimigo.setVida(inimigo.getVida() - ((jogador.getAtaque() * 5) - inimigo.getDefesa()));
            std::cout << inimigo.getVida() << std::endl;
        }
        break;
    case 3:     // DIREITA
        if((this->getPosX() + this->getBordaTamanho()) > (inimigo.getPosX() - inimigo.getBordaX()) && 
        (this->getPosX() - this->getBordaTamanho()) < (inimigo.getPosX() + inimigo.getBordaX()) &&
        (this->getPosY() + this->getBordaBase()) > (inimigo.getPosY() - inimigo.getBordaY()) &&
        (this->getPosY() - this->getBordaBase()) < (inimigo.getPosY() + inimigo.getBordaY())){
            inimigo.setVida(inimigo.getVida() - ((jogador.getAtaque() * 5) - inimigo.getDefesa()));
            std::cout << inimigo.getVida() << std::endl;
        }
        break;
    }
}*/