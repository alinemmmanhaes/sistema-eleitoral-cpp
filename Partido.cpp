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
int Partido::getQtdVotos() const{
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
    list<Candidato*>::const_iterator it = listCandidatos.begin();
    advance(it, i);
    return *it;
}

void Partido::insereCandidato(Candidato* c){
    int numero = c->getNumero();
    mapCandidatos.insert(pair<int, Candidato*> (numero, c));
}
void Partido::calculaQtdCandidatosEleitos(){
    for(map<int, Candidato*>::iterator it = mapCandidatos.begin(); it != mapCandidatos.end(); ++it){
        if((it->second)->getEleito()) candidatosEleitos++;
    }
}

void Partido::ordenaCandidatos(){
    for(map<int, Candidato*>::iterator it = mapCandidatos.begin(); it != mapCandidatos.end(); ++it){
        listCandidatos.push_back(it->second);
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

void Partido::printPartido() const{
        int qtdVotos = (qtdVotosNominais+qtdVotosLegenda);

        cout << sigla << " - " << numero << ", " << qtdVotos;

        if(qtdVotos <2){
            cout << " voto (";
        }
        else cout << " votos (";
        cout << qtdVotosNominais;

        if((qtdVotosNominais) <2){
            cout << " nominal e ";
        }
        else cout << " nominais e ";

        cout << qtdVotosLegenda << " de legenda), " << candidatosEleitos;

        if(candidatosEleitos <2){
            cout << " candidato eleito";
        }
        else cout << " candidatos eleitos";    
}

bool comparaPartidos(Partido* p1, Partido* p2){
    int diffVotos = p1->getQtdVotos() - p2->getQtdVotos();
    if(p1->getQtdVotos() != p2->getQtdVotos()){
        return p1->getQtdVotos() > p2->getQtdVotos();
    }
    return (p1->getNumero() > p2->getNumero());
}

bool comparaPartCand(Partido* p1, Partido* p2){
    return comparaCandidatos(p1->getCandidatoPos(0), p2->getCandidatoPos(0));
}