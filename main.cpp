#include <iostream>
#include <string>

#include "Partido.hpp"
#include "Candidato.hpp"
#include "Leitor.hpp"
#include "Eleicao.hpp"
#include "Relatorio.hpp"

using namespace std;

/*
Pré-condição de leitura: entradas nos args e nos arquivos de candidato e votação conforme especificado nao enunciado do Trabalho
Por exemplo, a cidade deve ter um código que a representa e este deve ser do tipo "int"
O mesmo vale para outras leituras, como o número de um candidato

Para as funções com parâmetro de candidato ou partido, é pré-condição que esse parâmetro exista
*/
int main(int argc, char const *argv[]){
    if(argc <= 4){
        cout << "ERRO! Faltam argumentos\n";
        return 1;
    }

    //conforme a especificação, guarda em sua respectiva variavel todos os parametros passados por args
    int diaEleicao, mesEleicao, anoEleicao;
    sscanf(argv[4], "%d/%d/%d", &diaEleicao, &mesEleicao, &anoEleicao);
    int cidade = atoi(argv[1]), vereador = 13;
    string arquivoCandidatos = argv[2];
    string arquivoVotacao = argv[3];

    //cria um leitor, para ler os arquivos cujos nomes foram passados por args
    Leitor leitor(diaEleicao, mesEleicao, anoEleicao, cidade, vereador);
    leitor.leCandidatos(arquivoCandidatos); //le o arquivo de candidatos
    leitor.leVotacao(arquivoVotacao); //le o arquivo de votação

    //eleicao criada e calculada pelo leitor, com base nos dados presentes nos arquivos
    Eleicao* eleicao = leitor.getEleicao();

    //cria um objeto da classe Relatorio, que fará todas as análises solicitadas
    Relatorio* relatorio = new Relatorio(eleicao);
    relatorio->geraRelatorios();

    //desaloca a memória alocada ao longo do programa
    eleicao->deleteEleicao(); //eleicao contém todos os candidatos e partidos alocados
    delete eleicao; //Eleicao*
    delete relatorio; //Relatorio*

    return 0;
}