#ifndef SEMESTRE_H
#define SEMESTRE_H
#include <string>

class Semestre {

private:

    std::string nome;
    float passar;
    float reprovar;
    float trancar;
    float alunos;
    float alunosMais;

public:
    Semestre();
    ~Semestre();
    std::string getNome();
    float getPassar();
    float getReprovar();
    float getTrancar();
    float getAlunos();
    float getAlunosMais();
    void setAlunos(float alunos);
    void setNome(std::string nome);
    void setPassar(float passar);
    void setReprovar(float reprovar);
    void setTrancar();
    void somaAlunos(float alunos);
    void setAlunosMais(float alunosMais);
};
#endif