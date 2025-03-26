#if !defined(LEITOR_HPP)
#define LEITOR_HPP

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>

#include "Eleicao.hpp"

using namespace std;

class Leitor{
    Eleicao* eleicao;
    int cidade;
    int cargo;

    public:
    Leitor(const int& dia, const int& mes, const int& ano, const int& cidade, const int& cargo) : 
    cidade(cidade), cargo(cargo){
        eleicao = new Eleicao(dia, mes, ano);
    }

    /*le as informações do arquivo de candidatos:
    -criando todos os partidos existentes no estado (que foram lidos do arquivo)
    -criando todos os candidatos do cargo especificado da cidade com o codigo armazenado
    -guardando tudo no objeto eleicao
    */
    void leCandidatos(const string& arquivoCandidatos);

    /*le as informações do arquivo de votacao:
    -aumentando todos os votos em partidos existentes no estado (que foram lidos do arquivo)
    -aumentando todos os votos em candidatos do cargo especificado da cidade com o codigo armazenado
    -guardando tudo no objeto eleicao
    */
    void leVotacao(const string& arquivoVotacao);

    //retorna um ponteiro para a eleicao armazenada com os dados de leitura
    Eleicao* getEleicao() const;
};


#endif // LEITOR_HPP
