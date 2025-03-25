#if !defined(RELATORIO_HPP)
#define RELATORIO_HPP

#include <iostream>
#include <string>
#include <list>
#include <map>

#include "Partido.hpp"
#include "Candidato.hpp"
#include "Eleicao.hpp"

class Relatorio{
    int dia, mes, ano;
    int vagas;
    list<Candidato*> candidatos;
    list<Candidato*> eleitosCandidatos;
    list<Partido*> partidos;

    public:
    Relatorio(Eleicao* eleicao){
        dia = eleicao->getDia();
        mes = eleicao->getMes();
        ano = eleicao->getAno();
        vagas = 0;

        map<int, Candidato*> mapCandidatos = eleicao->getCandidatos();
        for(map<int, Candidato*>::iterator it = mapCandidatos.begin(); it != mapCandidatos.end(); ++it){
            candidatos.insert(it->second);
        }

        map<int, Partido*> mapPartidos = eleicao->getPartidos();
        for(map<int, Partido*>::iterator it = mapPartidos.begin(); it != mapPartidos.end(); ++it){
            partidos.insert(it->second);
        }
    }

    void geraRelatorios();

    void relatorio1();
    void relatorio2();
    void relatorio3();
    void relatorio4();
    void relatorio5();
    void relatorio6();
    void relatorio7();
    void relatorio8();
    void relatorio9();
    void relatorio10();
}


#endif // RELATORIO_HPP
