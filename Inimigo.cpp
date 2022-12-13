#include "Inimigo.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

Inimigo::Inimigo(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda): Personagem(vida, ataque, defesa, pos_x, pos_y, borda){}

Inimigo::~Inimigo(){}

bool Inimigo::getAtacar(){
    return _atacar;
}

void Inimigo::setAtacar(bool newAtacar){
    _atacar = newAtacar;
}

void Inimigo::IA(){}

void Inimigo::desenhaAtaque(){
    al_draw_filled_rectangle(this->getPosX()-(2*this->getBordaX()), this->getPosY()-(2*this->getBordaY()), this->getPosX()+(2*this->getBordaX()), this->getPosY()+(2*this->getBordaY()), al_map_rgb(128, 64, 64));
}