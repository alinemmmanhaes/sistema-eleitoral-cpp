#include "Candidato.hpp"

const int &Candidato::getNumero() const{
    return numero;
}
const string &Candidato::getNome() const{
    return nome;
}
Partido &Candidato::getPartido() const{
    return *partido;
}
//nascimento
const int &Candidato::getIdade() const{
    return idade;
}
const bool &Candidato::getEleito() const{
    return eleito;
}
const bool &Candidato::getGenero() const{
    return genero;
}
const int &Candidato::getQtdVotos() const{
    return qtdVotos;
}

void Candidato::aumentaQtdVotos(const int &votos){
    this->qtdVotos += votos;
}
//void calculaIdade()

const string &Candidato::toString() const{
    string s = nome + " (" + partido.getSigla() + ", " + qtdVotos;
    if(qtdVotos < 2) s += " voto)";
    else s += " votos)";
    return s;
}