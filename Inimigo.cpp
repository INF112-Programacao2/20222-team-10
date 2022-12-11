#include "Inimigo.h"

Inimigo::Inimigo(int vida, int ataque, int defesa, int pos_x, int pos_y): Personagem(vida, ataque, defesa, pos_x, pos_y){}

Inimigo::~Inimigo(){}

void Inimigo::IA(){}

void Inimigo::ataqueNormal(){}

void Inimigo::ataqueForte(){}

void Inimigo::defender(){}