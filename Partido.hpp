#if !defined(PARTIDO_HPP)
#define PARTIDO_HPP

#include <iostream>
#include <string>

using namespace std;

class Partido{
    int numero;
    string sigla;
    bool federacao;
    int qtdVotosNominais;
    int qtdVotosLegenda;
    int candidatosEleitos;
    //candidatos hash e list

    public:
    Partido(const int& numero, const string& sigla, const bool& federacao) : 
    numero(numero), sigla(sigla), federacao(federacao){
        this->qtdVotosNominais = 0;
        this->qtdVotosLegenda = 0;
        this->candidatosEleitos = 0;
    }

    const int &getNumero() const;
    const string &getSigla() const;
    const bool &getFederacao() const;
    const int &getQtdVotos() const;
    const int &getQtdVotosNominais() const;
    const int &getQtdVotosLegenda() const;
    const int &getQtdCandidatosEleitos() const;
    //candidato

    //add candidato
    //calcula qtd candidatos eleitos
    //ordena candidatos

    void aumentaVotosLegenda(const int& qtdVotos);
    void aumentaVotosNominais(const int& qtdVotos);

    const string &toString() const;
};

#endif
