#include "Eleicao.hpp"

void Eleicao::partidoInsereVotos(const int& numeroPartido, const int& qtdVotos){
    Partido* p = this->getPartido(numeroPartido);
    if(p != NULL) p->aumentaVotosLegenda(qtdVotos);
}
void Eleicao::candidatoInsereVotos(const int& numeroCandidato, const int& qtdVotos){
    Candidato* c = this->getCandidato(numeroCandidato);
    if(c != NULL){
        Partido* p = c->getPartido();
        p->aumentaVotosNominais(qtdVotos, c);
    }
}

void Eleicao::adicionaCandidato(Candidato* c){
    candidatos.insert(pair<int, Candidato*>(c->getNumero(), c));
}
void Eleicao::adicionaPartido(Partido* p){
    partidos.insert(pair<int, Partido*>(p->getNumero(), p));
}

bool Eleicao::partidoExiste(const int& num){
    return (partidos.find(num)) != partidos.end();
}

map<int, Candidato*> Eleicao::getCandidatos(){
    return candidatos;
}
Candidato* Eleicao::getCandidato(const int& num){
    return candidatos.at(num);
}
map<int, Partido*> Eleicao::getPartidos(){
    return partidos;
}
Partido* Eleicao::getPartido(const int& num){
    return partidos.at(num);
}
const int Eleicao::getDia(){
    return this->dia;
}
const int Eleicao::getMes(){
    return this->mes;
}
const int Eleicao::getAno(){
    return this->ano;
}

void Eleicao::deleteEleicao(){
    for(auto it = candidatos.begin(); it != candidatos.end(); it++){
        delete it->second;
    }

    for(auto it = partidos.begin(); it != partidos.end(); it++){
        delete it->second;
    }
}