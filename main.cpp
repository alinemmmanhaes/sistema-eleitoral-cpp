#include <iostream>
#include <string>

#include "Partido.hpp"
#include "Candidato.hpp"
#include "Leitor.hpp"
#include "Eleicao.hpp"

using namespace std;

int main(int argc, char const *argv[]){
    if(argc <= 4){
        cout << "ERRO! Faltam argumentos\n";
        return 1;
    }

    int diaEleicao, mesEleicao, anoEleicao;
    sscanf(argv[4], "%d/%d/%d", &diaEleicao, &mesEleicao, &anoEleicao);
    int cidade = atoi(argv[1]), vereador = 13;
    string arquivoCandidatos = argv[2];
    string arquivoVotacao = argv[3];

    Leitor leitor(diaEleicao, mesEleicao, anoEleicao, cidade, vereador);
    leitor.leCandidatos(arquivoCandidatos);
    leitor.leVotacao(arquivoVotacao);

    Eleicao* eleicao = leitor.getEleicao();

    return 0;
}