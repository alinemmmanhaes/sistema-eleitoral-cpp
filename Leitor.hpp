#if !defined(LEITOR_HPP)
#define LEITOR_HPP

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>

#include "Eleicao.hpp"

using namespace std;

class Leitor{
    Eleicao* eleicao;
    int cidade;
    int cargo;

    public:
    Leitor(const int& dia, const int& mes, const int& ano, const int& cidade, const int& cargo) : 
    cidade(cidade), cargo(cargo){
        eleicao = new Eleicao(dia, mes, ano);
    }

    void leCandidatos(const string& arquivoCandidatos);
    void leVotacao(const string& arquivoVotacao);

    Eleicao* getEleicao() const;
};


#endif // LEITOR_HPP
