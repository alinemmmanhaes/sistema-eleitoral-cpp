#include "Relatorio.hpp"
#include <algorithm>

void Relatorio::geraRelatorios(){
    relatorio1();
    relatorio2();
    relatorio3();
    relatorio4();
    relatorio5();
    relatorio6();
    relatorio7();
    relatorio8();
    relatorio9();
    relatorio10();
}

void Relatorio::relatorio1(){
    for (auto c : candidatos) {
        c->calculaIdade(dia, mes, ano);
        if(c->getEleito()){
            eleitosCandidatos.push_back(c);
            this->vagas++;
        }
    }

    cout << "Número de vagas: " << this->vagas << "\n";
}

void Relatorio::relatorio2(){
    eleitosCandidatos.sort(comparaCandidatos);
    int i = 1;
    cout << "Vereadores eleitos:\n";
    for (auto c : eleitosCandidatos) {
        cout << i << " - ";
        if(c->getPartido()->getFederacao()) cout << "*";
        c->printCandidato();
        cout << "\n";
        i++;
    }
    cout << "\n";
}

void Relatorio::relatorio3(){
    candidatos.sort(comparaCandidatos);
    int i = 0;
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):\n";
    for (auto c : candidatos) {
        cout << i+1 << " - ";
        if(c->getPartido()->getFederacao()) cout << "*";
        c->printCandidato();
        cout << "\n";
        if(i == this->vagas-1) break;
        i++;
    }
    cout << "\n";
}

void Relatorio::relatorio4(){
    int i = 1;
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n";
    cout << "(com sua posição no ranking de mais votados)\n";
    for (auto c : candidatos) {
        list<Candidato*>::iterator it = find(eleitosCandidatos.begin(), eleitosCandidatos.end(), c);
        if(it == eleitosCandidatos.end()){
            cout << i << " - ";
            if(c->getPartido()->getFederacao()) cout << "*";
            c->printCandidato();
            cout << "\n";
        }
        if(i == this->vagas) break;
        i++;
    }
    cout << "\n";
}

void Relatorio::relatorio5(){
    int i = 0;
    cout << "Eleitos, que se beneficiaram do sistema proporcional:\n";
    cout << "(com sua posição no ranking de mais votados)\n";
    for (auto c : candidatos) {
        i++;
        if(i <= vagas) continue;
        if(c->getEleito()){
            cout << i << " - ";
            if(c->getPartido()->getFederacao()) cout << "*";
            c->printCandidato();
            cout << "\n";
        }
    }
    cout << "\n";
}

void Relatorio::relatorio6(){
    partidos.sort(comparaPartidos);
    cout << "Votação dos partidos e número de candidatos eleitos:\n";
    int i=1;
    for (auto p : partidos) {
        p->calculaQtdCandidatosEleitos();
        cout << i << " - ";
        p->printPartido();
        cout << "\n";
        i++;
    }
    cout << "\n";
}

void Relatorio::relatorio7(){
    list<Partido*> listPartidos;
    list<Partido*> partidosRemove;

    for(auto p: partidos){ //insere todos os elementos que estão na list "partidos"
        listPartidos.push_back(p);
    }

    for (auto p : listPartidos) {
        if(p->getCandidatos().size() == 0){
            partidosRemove.push_back(p);
        }
        else p->ordenaCandidatos();
    }

    for(auto p: partidosRemove){ //remove de "listPartidos" todos os elementos de "partidosRemove"
        listPartidos.remove(p);
    }

    listPartidos.sort(comparaPartCand);
    int i = 1;
    cout << "Primeiro e último colocados de cada partido:\n";
    for (auto p : listPartidos) {
        if(p->getQtdVotosNominais() == 0) continue;

        Candidato* c1 = p->getCandidatoPos(0);
        int size = p->getCandidatos().size();
        Candidato* c2 = p->getCandidatoPos(size-1);

        cout << i << " - " << p->getSigla() << " - " << p->getNumero() << ", ";

        string saidaVoto = " voto";
        if(c1->getQtdVotos() > 1) saidaVoto += "s";
        cout << c1->getNome() << " (" << c1->getNumero() << ", " << c1->getQtdVotos() << saidaVoto << ") / ";

        if(c2->getQtdVotos() > 1) saidaVoto = " votos";
        else saidaVoto = " voto";
        cout << c2->getNome() << " (" << c2->getNumero() << ", " << c2->getQtdVotos() << saidaVoto << ")\n";

        i++;
    }
    cout << "\n";
}

void Relatorio::relatorio8(){
    int menorque30 = 0, entre30e40 = 0, entre40e50 = 0, entre50e60 = 0, maiorque60 = 0;

    cout << "Eleitos, por faixa etária (na data da eleição):\n";
    for (auto c : eleitosCandidatos) {
        int idade = c->getIdade();
        if(idade < 30) menorque30++;
        else if(idade >= 30 && idade < 40) entre30e40++;
        else if(idade >= 40 && idade < 50) entre40e50++;
        else if(idade >= 50 && idade < 60) entre50e60++;
        else maiorque60++;
    }
    int total = eleitosCandidatos.size();
    cout << "      Idade < 30: " << menorque30 << " (" << 100.0*((double)menorque30)/total << "%)\n"; //%.2f
    cout << "30 <= Idade < 40: " << entre30e40 << " (" << 100.0*((double)entre30e40)/total << "%)\n";
    cout << "40 <= Idade < 50: " << entre40e50 << " (" << 100.0*((double)entre40e50)/total << "%)\n";
    cout << "50 <= Idade < 60: " << entre50e60 << " (" << 100.0*((double)entre50e60)/total << "%)\n";
    cout << "60 <= Idade     : " << maiorque60 << " (" << 100.0*((double)maiorque60)/total << "%)\n";
    cout << "\n";
}

void Relatorio::relatorio9(){
    int homem = 0, mulher = 0;

    for (auto c : eleitosCandidatos) {
        bool genero = c->getGenero();
        if(genero == HOMEM) homem++;
        else if(genero == MULHER) mulher++;
    }
    int total = eleitosCandidatos.size();
    cout << "Eleitos, por gênero:\n";
    cout << "Feminino:  " << mulher << " (" << 100*((double)mulher)/total << "%)\n"; //%.2f
    cout << "Masculino: " << homem << " (" << 100*((double)homem)/total << "%)\n";
    cout << "\n";
}

void Relatorio::relatorio10(){
    int total = 0, legenda = 0, nominal = 0;
    for (auto p : partidos) {
        total += p->getQtdVotos();
        nominal += p->getQtdVotosNominais();
        legenda += p->getQtdVotosLegenda();
    }
    cout << "Total de votos válidos:    " << total << "\n";
    cout << "Total de votos nominais:   " << nominal << " (" << (100*((double)nominal)/total) << "%)\n";
    cout << "Total de votos de legenda: " << legenda << " (" << (100*((double)legenda)/total) << "%)\n";
    cout << "\n";
}