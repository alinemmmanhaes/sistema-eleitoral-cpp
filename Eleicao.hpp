#if !defined(ELEICAO_HPP)
#define ELEICAO_HPP

#include <iostream>
#include <string>
#include <map>

#include "Partido.hpp"
#include "Candidato.hpp"

using namespace std;

class Eleicao{
    int dia, mes, ano; //data da eleição
    map<int, Candidato*> candidatos;
    map<int, Partido*> partidos;

    public:
    Eleicao(const int& dia, const int& mes, const int& ano) : dia(dia), mes(mes), ano(ano){}

    //para um partido de numero do parametro, aumenta seus votos de legenda
    void partidoInsereVotos(const int& numeroPartido, const int& qtdVotos);
    //para um candidato de numero do parametro, aumenta os votos nominais do seu partido e do candidato
    void candidatoInsereVotos(const int& numeroCandidato, const int& qtdVotos);

    //insere candidato no map de candidatos
    void adicionaCandidato(Candidato* c);
    //insere partido no map de partidos
    void adicionaPartido(Partido* p);

    //verifica se um partido existe
    bool partidoExiste(const int& num);

    //funções get, para retorno de informações armazenadas dentro de uma eleicao
    map<int, Candidato*> getCandidatos();
    Candidato* getCandidato(const int& num);
    map<int, Partido*> getPartidos();
    Partido* getPartido(const int& num);
    const int getDia();
    const int getMes();
    const int getAno();

    //deleta memória alocada pela eleição
    void deleteEleicao();
};

#endif // ELEICAO_HPP
