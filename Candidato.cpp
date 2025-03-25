#include "Candidato.hpp"

int Candidato::getNumero() const{
    return numero;
}
const string &Candidato::getNome() const{
    return nome;
}
Partido* Candidato::getPartido() const{
    return partido;
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
int Candidato::getQtdVotos() const{
    return qtdVotos;
}

void Candidato::aumentaQtdVotos(const int &votos){
    this->qtdVotos += votos;
}
void Candidato::calculaIdade(const int& dia, const int& mes, const int& ano){
    if(this->mes < mes) this->idade = ano - this->ano;
    else if(this->mes > mes) this->idade = ano - this->ano -1;
    else{
        if(this->dia <= dia) this->idade = ano - this->ano;
        else this->idade = ano - this->ano - 1;
    }
}

void Candidato::printCandidato() const{
    cout << nome << " (" << partido->getSigla() << ", " << getQtdVotos();
    
    if(qtdVotos < 2) cout << " voto)";
    else cout << " votos)";
}

bool comparaCandidatos(Candidato* c1, Candidato* c2){
    if(c1->getQtdVotos() != c2->getQtdVotos()){
        return c1->getQtdVotos() > c2->getQtdVotos();
    }
    return c1->getIdade() > c2->getIdade();
}