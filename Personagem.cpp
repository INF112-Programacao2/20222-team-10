#include "Personagem.h"

Personagem::Personagem(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda){
    _vida = vida;
    _ataque = ataque;
    _defesa = defesa;
    _pos_x = pos_x;
    _pos_y = pos_y;
    _borda_x = borda;
    _borda_y = borda;
}

Personagem::~Personagem(){}

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

int Personagem::getBordaX(){
    return _borda_x;
}

int Personagem::getBordaY(){
    return _borda_y;
}

void Personagem::setVida(int newVida){
    _vida = newVida;
}

void Personagem::setAtaque(int newAtaque){
    _ataque = newAtaque;
}

void Personagem::setDefesa(int newDefesa){
    _defesa = newDefesa;
}

void Personagem::setPosX(int newX){
    _pos_x = newX;
}

void Personagem::setPosY(int newY){
    _pos_y = newY;
}