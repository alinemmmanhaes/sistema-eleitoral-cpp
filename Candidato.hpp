#if !defined(CANDIDATO_HPP)
#define CANDIDATO_HPP

#include <iostream>
#include <string>

class Partido;

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
        this->partido->insereCandidato(&this);
        this->idade = 0;
    }

    const int &getNumero() const;
    const string &getNome() const;
    Partido* &getPartido() const;
    //nascimento
    const int &getIdade() const;
    const bool &getEleito() const;
    const bool &getGenero() const;
    const int &getQtdVotos() const;

    void aumentaQtdVotos(const int &votos);
    void calculaIdade(const int& dia, const int& mes, const int& ano);

    const string &toString() const;
};

#endif
