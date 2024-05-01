#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "semestre.cpp"

#define caso "data\\caso9.txt"

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
    float restantes = 0;
    std::string casoteste;

    std::cout << "Digite o nome do caso teste: ";
    std::cin >> casoteste;

    casos.open("data\\" + casoteste + ".txt");
    // casos.open(caso);

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

            if (palavra == "->" || palavra == "")
            {
                i++;
                continue;
            }

            if (i == 0)
            {
                std::string num;
                for (char c : palavra)
                {
                    if (isdigit(c))
                    {
                        num += c;
                    }
                }
                int sem = std::stoi(num);

                if (semestres.size() == 0)
                {
                    semestre.setNome(palavra);
                    semestre.setSemestre(sem);
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
                        semestre.setSemestre(sem);
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

    std::vector<Semestre> semestresaux = semestres;
    for (auto &sem : semestres)
    {
        // std::vector<Semestre> semestres2 = semestres;

        int i = sem.getSemestre();
        semestresaux[i - 1] = sem;
    }
    Semestre *aux = new Semestre();
    aux->setNome("Gradu");
    semestres = semestresaux;
    semestres.push_back(*aux);
    delete &semestresaux, aux;

    float matriz[semestres.size()][(semestres.size() + 1)];
    float resultalunos[semestres.size()];

    for (int i = 0; i < semestres.size(); i++)
    {
        resultalunos[i] = 0;
        for (int j = 0; j < semestres.size() + 1; j++)
        {
            matriz[i][j] = 0;
        }
        matriz[i][semestres.size()] = 0;
    }

    for (int i = 0; i < semestres.size(); i++)
    {
        for (int j = 0; j < semestres.size() + 1; j++)
        {
            if (i == j)
            {
                matriz[i][j] = semestres[i].getReprovar() - 1;
            }
            else if (i - 1 == j)
            {
                matriz[i][j] = semestres[i - 1].getPassar();
            }
        }
    }

    matriz[0][semestres.size()] = alunos * -1;

    /*for(int i = 0; i < semestres.size(); i++){
        std::cout << semestres[i].getNome() << ": ";
        for(int j = 0; j < semestres.size() + 1; j++){
            if(i != j){
                std::cout << " ";
            }
            std::cout << std::fixed << std::setprecision(4) << matriz[i][j] << "     ";
        }
        std::cout << std::endl;
    }*/

    for (int i = 0; i < semestres.size() - 1; i++)
    {
        for (int j = i + 1; j < semestres.size(); j++)
        {
            float f = matriz[j][i] / matriz[i][i];
            for (int k = 0; k < semestres.size() + 1; k++)
            {
                matriz[j][k] = matriz[j][k] - f * matriz[i][k];
            }
        }
    }

    for (int i = semestres.size() - 1; i >= 0; i--)
    {
        resultalunos[i] = matriz[i][semestres.size()];

        for (int j = i + 1; j < semestres.size(); j++)
        {
            if (i != j)
            {
                resultalunos[i] = resultalunos[i] - matriz[i][j] * resultalunos[j];
            }
        }
        resultalunos[i] = resultalunos[i] / matriz[i][i];
    }

    for (int i = 0; i < semestres.size(); i++)
    {
        if (i == semestres.size() - 1)
        {
            formados = resultalunos[i];
        }
        else
        {
            restantes += resultalunos[i];
        }
    }

    std::cout << "Alunos formados: " << std::fixed << std::setprecision(0) << formados << std::endl;
    std::cout << "Alunos restantes: " << std::fixed << std::setprecision(0) << restantes << std::endl;
    std::cout << "Total de alunos: " << std::fixed << std::setprecision(0) << formados + restantes << std::endl;

    return 0;
}
