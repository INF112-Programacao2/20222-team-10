#include "Inimigo.h"
#include "Espada.h"
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

/*void Inimigo::desenhaAtaque1(){
    al_draw_filled_rectangle(this->getPosX()-(3*this->getBordaX()), this->getPosY()-(3*this->getBordaY()), this->getPosX()+(2*this->getBordaX()), this->getPosY()+(3*this->getBordaY()), al_map_rgb(128, 64, 64));
}

void Inimigo::desenhaAtaque2(){
    al_draw_filled_rectangle(this->getPosX() - this->getBordaX(), this->getPosY() - this->getBordaY(), getBordaX(), this->getPosY() + this->getBordaY(), al_map_rgb(128, 64, 64));
}*/

void Inimigo::ataque(Espada espada, int ultima_posicao){
    //if(qualAtaque == 0){
        al_draw_filled_rectangle(this->getPosX()-(3*this->getBordaX()), this->getPosY()-(3*this->getBordaY()), this->getPosX()+(2*this->getBordaX()), this->getPosY()+(3*this->getBordaY()), al_map_rgb(128, 64, 64));
    //}
    //else if(qualAtaque == 1){
    //    al_draw_filled_rectangle(this->getPosX() - this->getBordaX(), this->getPosY() - this->getBordaY(), getBordaX(), this->getPosY() + this->getBordaY(), al_map_rgb(128, 64, 64));
    //}
}