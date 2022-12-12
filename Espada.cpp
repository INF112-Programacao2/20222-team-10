#include "Espada.h"

Espada::Espada(int pos_x, int pos_y){
    _pos_x = pos_x;
    _pos_y = pos_y;
}

Espada::~Espada(){}

int Espada::getPosX(){
    return _pos_x;
}

int Espada::getPosY(){
    return _pos_y;
}

void Espada::setPosX(int new_x){
    _pos_x = new_x;
}

void Espada::setPosY(int new_y){
    _pos_y = new_y;
}