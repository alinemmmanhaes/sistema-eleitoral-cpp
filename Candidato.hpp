#if !defined(CANDIDATO_HPP)
#define CANDIDATO_HPP

#include <iostream>
#include <string>

#define MULHER true
#define HOMEM false

class Partido;
#include "Partido.hpp"

using namespace std;

class Candidato{
    int numero;
    string nome;
    Partido* partido;
    int dia, mes, ano; //nascimento
    int idade;
    bool eleito;
    bool genero; //homem = false / mulher = true
    int qtdVotos;

    public:
    Candidato(const int& numero, const string& nome, Partido* partido, const int& dia, const int& mes, const int& ano, const bool& eleito, const bool& genero) : 
    numero(numero), nome(nome), partido(partido), dia(dia), mes(mes), ano(ano), eleito(eleito), genero(genero){
        this->qtdVotos = 0;
        this->idade = 0;
    }

    //funções get, para retorno de informações armazenadas dentro de um candidato
    int getNumero() const;
    const string &getNome() const;
    Partido* getPartido() const;
    const int &getIdade() const;
    const bool &getEleito() const;
    const bool &getGenero() const;
    int getQtdVotos() const;

    //aumenta a quantidade de votos armazenada no candidato
    void aumentaQtdVotos(const int &votos);
    //calcula a idade do candidato, comparando a sua data de nascimento com a data da eleição passada por parâmetro
    void calculaIdade(const int& dia, const int& mes, const int& ano);

    //printa informações básicas de um candidato
    void printCandidato() const;
};

//compara dois candidados, avaliando suas quantidades de votos, e em ultimo caso, as suas idades
bool comparaCandidatos(Candidato* c1, Candidato* c2);

#endif
