#if !defined(ELEICAO_HPP)
#define ELEICAO_HPP

#include <iostream>
#include <string>
#include <map>

#include "Partido.hpp"
#include "Candidato.hpp"

using namespace std;

class Eleicao{
    int dia, mes, ano;
    map<int, Candidato*> candidatos;
    map<int, Partido*> partidos;

    public:
    Eleicao(const int& dia, const int& mes, const int& ano) : dia(dia), mes(mes), ano(ano){}

    void partidoInsereVotos(const int& numeroPartido, const int& qtdVotos);
    void candidatoInsereVotos(const int& numeroCandidato, const int& qtdVotos);

    void adicionaCandidato(Candidato* c);
    void adicionaPartido(Partido* p);

    bool partidoExiste(const int& num);

    map<int, Candidato*> getCandidatos();
    Candidato* getCandidato(const int& num);
    map<int, Partido*> getPartidos();
    Partido* getPartido(const int& num);
    const int getDia();
    const int getMes();
    const int getAno();

    void deleteEleicao();
};

#endif // ELEICAO_HPP
