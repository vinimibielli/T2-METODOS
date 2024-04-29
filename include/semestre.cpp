#include <iostream>
#include "semestre.h"

Semestre::Semestre(){
    nome = "";
    passar = 0;
    reprovar = 0;
    trancar = 0;
    alunos = 0;
    alunosMais = 0;
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

float Semestre::getTrancar(){
    return trancar;
}

float Semestre::getAlunos(){
    return alunos;
}

float Semestre::getAlunosMais(){
    return alunosMais;
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

void Semestre::setTrancar(){
    float soma = passar + reprovar;
    this->trancar = 1 - soma;
}

void Semestre::setAlunos(float alunos){
    this->alunos = alunos;
}

void Semestre::somaAlunos(float alunos){
    this->alunos = this->alunos + alunos;
}

void Semestre::setAlunosMais(float alunosMais){
    this->alunosMais = alunosMais;
}


