#include "Personagem.h"

Personagem::Personagem(int vida, int ataque, int defesa){
    _vida = vida;
    _ataque = ataque;
    _defesa = defesa;
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

int Personagem::setVida(int vida){
    _vida=vida;
}