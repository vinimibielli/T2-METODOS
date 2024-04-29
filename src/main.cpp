#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "semestre.cpp"
#include <vector>
#include <windows.h>

#define caso "data\\caso1.txt"

int main()
{
    std::ifstream casos;
    std::string linha, palavra;
    std::stringstream inicio;
    float valor;
    int alunos;
    std::vector<Semestre> semestres;
    std::vector<std::string> nomes;
    float formados = 0;

    casos.open(caso);

    if (!casos.is_open())
    {
        std::cout << "Não foi possível abrir o caso teste" << std::endl;
        return 1;
    }

    getline(casos, linha);
    inicio << linha;
    while (!inicio.eof())
    {
        inicio >> palavra;
    }
    alunos = std::stoi(palavra);

    while (!casos.eof())
    {
        getline(casos, linha);
        std::stringstream s(linha);
        Semestre semestre;
        int i = 0;
        bool existe = false;

        while (!s.eof())
        {
            // std::cout << "entrou2" << std::endl;
            getline(s, palavra, ' ');
            // std::cout << palavra << std::endl;

            if (palavra == "->")
            {
                i++;
                continue;
            }

            if (i == 0)
            {
                if (semestres.size() == 0)
                {
                    semestre.setNome(palavra);
                }
                else
                {
                    for (auto &sem : semestres)
                    {
                        if (sem.getNome() == palavra)
                        {
                            semestre = sem;
                            existe = true;
                        }
                    }
                    if (!existe)
                    {
                        semestre.setNome(palavra);
                    }
                }
            }

            if (i == 2)
            {
                valor = std::stof(palavra);
            }

            if (i == 4)
            {
                if (palavra == semestre.getNome())
                {
                    semestre.setReprovar(valor);
                }
                else
                {
                    semestre.setPassar(valor);
                }
            }
            i++;
        }
        if (!existe)
        {
            if (semestre.getNome() == "")
            {
                continue;
            }
            semestres.push_back(semestre);
        }
        else
        {
            for (auto &sem : semestres)
            {
                if (sem.getNome() == semestre.getNome())
                {
                    sem.setPassar(semestre.getPassar());
                    sem.setReprovar(semestre.getReprovar());
                }
            }
        }
    }

    casos.close();

    for (auto &sem : semestres)
    {
        sem.setTrancar();
    }

    std::vector<Semestre> semestresaux = semestres;
    for (auto &sem : semestres)
    {
        // std::vector<Semestre> semestres2 = semestres;
        int i = sem.getNome().back() - '0';
        semestresaux[i - 1] = sem;
    }
    semestres = semestresaux;
    delete &semestresaux;

    for (auto &sem : semestres)
    {
        std::cout << sem.getNome() << " Passar: " << sem.getPassar() << " Reprovar: " << sem.getReprovar() << " Trancar: " << sem.getTrancar() << std::endl;
    }

int j = 0;
    while(j < 8){
        
        float passaram, reprovaram, trancaram;
        for (auto &sem : semestres){
            if((sem.getNome().back() - '0') == 1){
                sem.somaAlunos(alunos);
                //std::cout << sem.getNome() << " Alunos: " << sem.getAlunos();
            }else{
                if(sem.getAlunos() == 0 && sem.getAlunosMais() == 0){
                    sem.setAlunosMais(passaram);
                    //continue;
                } else{
                    sem.somaAlunos(sem.getAlunosMais());
                    sem.setAlunosMais(passaram);
                }
                //std::cout << sem.getNome() << " Alunos: " << sem.getAlunos();
            }
        passaram = sem.getPassar() * sem.getAlunos();
        reprovaram = sem.getReprovar() * sem.getAlunos();
        trancaram = sem.getTrancar() * sem.getAlunos();
        sem.setAlunos(reprovaram);
       // std::cout << " Aprovados: " << passaram << " Reprovados: " << reprovaram << " Trancaram: " << trancaram << " Alunos restantes: " << sem.getAlunos() << " AlunosMais: " << sem.getAlunosMais() << std::endl;
        }
        formados = formados + passaram;

        //std::cout << "Formados: " << formados << std::endl;
        j++;
    }
    return 0;
}