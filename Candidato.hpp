#if !defined(CANDIDATO_HPP)
#define CANDIDATO_HPP

#include <iostream>
#include <string>

#include "Partido.hpp"

using namespace std;

class Candidato{
    int numero;
    string nome;
    Partido* partido;
    //Data nascimento
    int idade;
    bool eleito;
    int genero;
    int qtdVotos;

    public:
    Candidato(const int& numero, const string& nome, Partido* partido, /*nascimento,*/ const bool& eleito, const int& genero) : 
    numero(numero), nome(nome), partido(partido), eleito(eleito), genero(genero){
        this->qtdVotos = 0;
        //nascimento e idade
    }

    const int &getNumero() const;
    const string &getNome() const;
    Partido &getPartido() const;
    //nascimento
    const int &getIdade() const;
    const bool &getEleito() const;
    const int &getGenero() const;
    const int &getQtdVotos() const;

    void aumentaQtdVotos(const int &votos);
    //void calculaIdade()

    const string &toString() const;
};

#endif
