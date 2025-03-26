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

    //funções get, para retorno de informações armazenadas dentro de um candidato
    const int &getNumero() const;
    const string &getSigla() const;
    const bool &getFederacao() const;
    int getQtdVotos() const;
    const int &getQtdVotosNominais() const;
    const int &getQtdVotosLegenda() const;
    const int &getQtdCandidatosEleitos() const;
    map<int, Candidato*> getCandidatos() const;
    Candidato* getCandidatoPos(const int& i) const;

    //adiciona candidato ao seu partido, assim um terá acesso ao outro
    void insereCandidato(Candidato* c);
    //calcula quantos candidatos foram eleitos em um partido com base em suas variaveis bool eleito (dos candidatos)
    void calculaQtdCandidatosEleitos();
    //ordena todos os candidatos de um partido usando o comparador
    void ordenaCandidatos();

    //aumenta o numero de votos de legenda dados ao partido
    void aumentaVotosLegenda(const int& qtdVotos);
    //aumenta o numero de votos nominais dados ao partido e ao candidato c
    void aumentaVotosNominais(const int& qtdVotos, Candidato* c);

    //printa informações básicas de um partido
    void printPartido() const;
};

//compara dois partidos a partir de seus votos, e em ultimo caso, por seus numeros
bool comparaPartidos(Partido* p1, Partido* p2);

/*compara dois partidos a partir de seus candidatos mais votados, 
utilizando o comparador de candidatos*/
bool comparaPartCand(Partido* p1, Partido* p2);

#endif
