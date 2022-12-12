#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Controlador{
public:
   // char Mapa1[26][26];

    
    
    int _cont=1;
    Controlador();
    ~Controlador();

    char escolherMapa();
};

#endif