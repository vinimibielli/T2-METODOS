#ifndef SEMESTRE_H
#define SEMESTRE_H
#include <string>

class Semestre {

private:

    std::string nome;
    float passar;
    float reprovar;
    int semestre;

public:
    Semestre();
    ~Semestre();
    std::string getNome();
    float getPassar();
    float getReprovar();
    int getSemestre();
    void setNome(std::string nome);
    void setPassar(float passar);
    void setReprovar(float reprovar);
    void setSemestre(int semestre);

};
#endif