#include "Controlador.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Espada.h"
#include <iostream>

Controlador::Controlador(){}

Controlador::~Controlador(){}

void Controlador::colisaoDarDano(Espada espada, Inimigo &inimigo, Jogador jogador, int ultima_posicao){
    switch(ultima_posicao){
    case 0:     // CIMA
        if((espada.getPosY() - espada.getBordaTamanho()) < (inimigo.getPosY() + inimigo.getBordaY()) && 
        (espada.getPosY() + espada.getBordaTamanho()) > (inimigo.getPosY() - inimigo.getBordaY()) &&
        (espada.getPosX() - espada.getBordaBase()) < (inimigo.getPosX() + inimigo.getBordaX()) &&
        (espada.getPosX() + espada.getBordaBase()) > (inimigo.getPosX() - inimigo.getBordaX())){
            inimigo.setVida(inimigo.getVida() - ((jogador.getAtaque() * 5) - inimigo.getDefesa()));
            std::cout << inimigo.getVida() << std::endl;
        }
        break;
    case 1:     // BAIXO
        if((espada.getPosY() + espada.getBordaTamanho()) > (inimigo.getPosY() - inimigo.getBordaY()) && 
        (espada.getPosY() - espada.getBordaTamanho()) < (inimigo.getPosY() + inimigo.getBordaY()) &&
        (espada.getPosX() + espada.getBordaBase()) > (inimigo.getPosX() - inimigo.getBordaX()) &&
        (espada.getPosX() - espada.getBordaBase()) < (inimigo.getPosX() + inimigo.getBordaX())){
            inimigo.setVida(inimigo.getVida() - ((jogador.getAtaque() * 5) - inimigo.getDefesa()));
            std::cout << inimigo.getVida() << std::endl;
        }
        break;
    case 2:     // ESQUERDA
        if((espada.getPosX() - espada.getBordaTamanho()) < (inimigo.getPosX() + inimigo.getBordaX()) && 
        (espada.getPosX() + espada.getBordaTamanho()) > (inimigo.getPosX() - inimigo.getBordaX()) &&
        (espada.getPosY() - espada.getBordaBase()) < (inimigo.getPosY() + inimigo.getBordaY()) &&
        (espada.getPosY() + espada.getBordaBase()) > (inimigo.getPosY() - inimigo.getBordaY())){
            inimigo.setVida(inimigo.getVida() - ((jogador.getAtaque() * 5) - inimigo.getDefesa()));
            std::cout << inimigo.getVida() << std::endl;
        }
        break;
    case 3:     // DIREITA
        if((espada.getPosX() + espada.getBordaTamanho()) > (inimigo.getPosX() - inimigo.getBordaX()) && 
        (espada.getPosX() - espada.getBordaTamanho()) < (inimigo.getPosX() + inimigo.getBordaX()) &&
        (espada.getPosY() + espada.getBordaBase()) > (inimigo.getPosY() - inimigo.getBordaY()) &&
        (espada.getPosY() - espada.getBordaBase()) < (inimigo.getPosY() + inimigo.getBordaY())){
            inimigo.setVida(inimigo.getVida() - ((jogador.getAtaque() * 5) - inimigo.getDefesa()));
            std::cout << inimigo.getVida() << std::endl;
        }
        break;
    }
}