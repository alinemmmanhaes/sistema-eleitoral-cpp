#include "Partido.hpp"

const int &Partido::getNumero() const{
    return this->numero;
}
const string &Partido::getSigla() const{
    return this->sigla;
}
const bool &Partido::getFederacao() const{
    return this->federacao;
}
const int &Partido::getQtdVotos() const{
    return this->qtdVotosLegenda + this->qtdVotosNominais;
}
const int &Partido::getQtdVotosNominais() const{
    return this->qtdVotosNominais;
}
const int &Partido::getQtdVotosLegenda() const{
    return this->qtdVotosLegenda;
}
const int &Partido::getQtdCandidatosEleitos() const{
    return this->candidatosEleitos;
}
map<int, Candidato*> Partido::getCandidatos() const{
    return mapCandidatos;
}
Candidato* Partido::getCandidatoPos(const int& i) const{
    list<Candidato*>:: iterator it = listCandidatos.begin();
    advance(it, i);
    return *it;
}

void Partido::insereCandidato(const Candidato* c){
    int numero = c->getNumero();
    mapCandidatos.insert(pair<int, Candidato*> (numero, c));
}
void Partido::calculaQtdCandidatosEleitos(){
    for(map<int, Candidato*>::iterator it = mapCandidatos.begin(); it != mapCandidatos.end(); ++it){
        if((it->second)->getEleito) candidatosEleitos++;
    }
}

bool comparaCandidatos(Candidato* c1, Candidato* c2){
    if(c1->getQtdVotos() != c2->getQtdVotos()){
        return c1->getQtdVotos() > c2->getQtdVotos();
    }
    return c1->getIdade() > c2->getIdade();
}

void Partido::ordenaCandidatos(){
    for(map<int, Candidato*>::iterator it = mapCandidatos.begin(); it != mapCandidatos.end(); ++it){
        listCandidatos.insert(it->second);
    }
    listCandidatos.sort(comparaCandidatos);
}

void Partido::aumentaVotosLegenda(const int& qtdVotos){
    this->qtdVotosLegenda += qtdVotos;
}
void Partido::aumentaVotosNominais(const int& qtdVotos, Candidato* c){
    int numero = c->getNumero();
    if(mapCandidatos.find(numero) != mapCandidatos.end()){
        c->aumentaQtdVotos(qtdVotos);
        this->qtdVotosNominais += qtdVotos;
    }
}

const string &Partido::toString() const{
        int qtdVotos = (qtdVotosNominais+qtdVotosLegenda);

        string saida = sigla + " - " + numero + ", " + qtdVotos;

        if(qtdVotos <2){
            saida += " voto (";
        }
        else saida += " votos (";
        saida += qtdVotos-qtdVotosLegenda;

        if((qtdVotosNominais) <2){
            saida += " nominal e ";
        }
        else saida += " nominais e ";

        saida += qtdVotosLegenda + " de legenda), " + candidatosEleitos;

        if(candidatosEleitos <2){
            saida += " candidato eleito";
        }
        else saida += " candidatos eleitos";

        return saida ;
}