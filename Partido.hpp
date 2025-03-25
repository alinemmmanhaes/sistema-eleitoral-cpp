#if !defined(PARTIDO_HPP)
#define PARTIDO_HPP

#include <iostream>
#include <string>

#include <map>
#include <list>

class Candidato;
#include "Candidato.hpp"

using namespace std;

class Partido{
    int numero;
    string sigla;
    bool federacao;
    int qtdVotosNominais;
    int qtdVotosLegenda;
    int candidatosEleitos;
    map<int, Candidato*> mapCandidatos;
    list<Candidato*> listCandidatos;

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
    int getQtdVotos() const;
    const int &getQtdVotosNominais() const;
    const int &getQtdVotosLegenda() const;
    const int &getQtdCandidatosEleitos() const;
    map<int, Candidato*> getCandidatos() const;
    Candidato* getCandidatoPos(const int& i) const;

    void insereCandidato(Candidato* c);
    void calculaQtdCandidatosEleitos();
    void ordenaCandidatos();

    void aumentaVotosLegenda(const int& qtdVotos);
    void aumentaVotosNominais(const int& qtdVotos, Candidato* c);

    void printPartido() const;
};

bool comparaPartidos(Partido* p1, Partido* p2);
bool comparaPartCand(Partido* p1, Partido* p2);

#endif
