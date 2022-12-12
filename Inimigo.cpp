#include "Inimigo.h"

Inimigo::Inimigo(int vida, int ataque, int defesa, int pos_x, int pos_y, int borda): Personagem(vida, ataque, defesa, pos_x, pos_y, borda){}

Inimigo::~Inimigo(){}

void Inimigo::IA(){}

void Inimigo::ataqueNormal(){}

void Inimigo::ataqueForte(){}

void Inimigo::defender(){}