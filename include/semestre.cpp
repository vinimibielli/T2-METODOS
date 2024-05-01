#include <iostream>
#include "semestre.h"

Semestre::Semestre(){
    nome = "";
    passar = 0;
    reprovar = 0;
}

Semestre::~Semestre(){
}

std::string Semestre::getNome(){
    return nome;
}

float Semestre::getPassar(){
    return passar;
}

float Semestre::getReprovar(){
    return reprovar;
}

int Semestre::getSemestre(){
    return semestre;
}

void Semestre::setNome(std::string nome){
    this->nome = nome;
}

void Semestre::setPassar(float passar){
    this->passar = passar;
}

void Semestre::setReprovar(float reprovar){
    this->reprovar = reprovar;
}

void Semestre::setSemestre(int semestre){
    this->semestre = semestre;
}