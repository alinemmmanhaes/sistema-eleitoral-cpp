#include "Leitor.hpp"

#include "Partido.hpp"
#include "Candidato.hpp"

string removeAspas(string input){
    input.replace(0, 1, "");
    input.replace(input.size()-1, 1, "");
    return input;
}

string iso_8859_1_to_utf8(string &str)
{
  // adaptado de: https://stackoverflow.com/a/39884120 :-)
  string strOut;
  for (string::iterator it = str.begin(); it != str.end(); ++it)
  {
    uint8_t ch = *it;
    if (ch < 0x80)
    {
      // já está na faixa ASCII (bit mais significativo 0), só copiar para a saída
      strOut.push_back(ch);
    }
    else
    {
      // está na faixa ASCII-estendido, escrever 2 bytes de acordo com UTF-8
      // o primeiro byte codifica os 2 bits mais significativos do byte original (ISO-8859-1)
      strOut.push_back(0b11000000 | (ch >> 6));
      // o segundo byte codifica os 6 bits menos significativos do byte original (ISO-8859-1)
      strOut.push_back(0b10000000 | (ch & 0b00111111));
    }
  }
  return strOut;
}

void Leitor::leCandidatos(const string& arquivoCandidatos){
    ifstream in(arquivoCandidatos);
    string linha, input;
    getline(in, linha);
    while(getline(in, linha)){
        istringstream lineStream(linha);

        int i = 0, diaNasc = 0, mesNasc = 0, anoNasc = 0;
        int codCidade = 0, cargo = 0, numeroCandidato = 0, numeroPartido = 0, numeroFederacao = 0, codEleito = 0, codGenero = 0;
        string nomeCandidato = "", siglaPartido = "";

        for(i=0; i<50; i++){
            getline(lineStream, input, ';');
            input = iso_8859_1_to_utf8(input);

            if(i==11) codCidade = stoi(removeAspas(input));
            else if(i == 13) cargo = stoi(input);
            else if(i == 16) numeroCandidato = stoi(input);
            else if(i == 18) nomeCandidato = removeAspas(input);
            else if(i == 25) numeroPartido = stoi(input);
            else if(i == 26) siglaPartido = removeAspas(input);
            else if(i == 28) numeroFederacao = stoi(input);
            else if(i == 36) sscanf(removeAspas(input).c_str(), "%d/%d/%d", &diaNasc, &mesNasc, &anoNasc);
            else if(i == 38) codGenero = stoi(input);
            else if(i == 48) codEleito = stoi(input);
        }

        if(eleicao->partidoExiste(numeroPartido) == false){
            Partido* p = new Partido(numeroPartido, siglaPartido, (numeroFederacao != -1));
            eleicao->adicionaPartido(p);
        }

        /*verifica se a cidade do candidato é a mesma a ser analisada
        se o cargo é o de vereador
        se a situação eleitoral do candidato não é invalida
        */
        if(codCidade == this->cidade && cargo == this->cargo && codEleito != -1){
            Partido* partido = eleicao->getPartido(numeroPartido);
            bool genero = MULHER; //true
            if(codGenero == 2) genero = HOMEM; //false
            Candidato* c = new Candidato(numeroCandidato, nomeCandidato, partido, diaNasc, mesNasc, anoNasc, (codEleito == 2 || codEleito == 3), genero);
            eleicao->adicionaCandidato(c);
            partido->insereCandidato(c);
        }
    }
}
void Leitor::leVotacao(const string& arquivoVotacao){
    ifstream in(arquivoVotacao);
    string linha, input;
    getline(in, linha);
    while(getline(in, linha)){
        istringstream lineStream(linha);

        int i = 0;
        int codCidade = 0, cargo = 0, qtdVotos = 0, numeroCandidato = 0;

        for(i=0; i<26; i++){
            getline(lineStream, input, ';');
            input = iso_8859_1_to_utf8(input);

            if(i==13) codCidade = stoi(input);
            else if(i == 17) cargo = stoi(input);
            else if(i == 19) numeroCandidato = stoi(input);
            else if(i == 21) qtdVotos = stoi(input);
        }
        
        if(codCidade == this->cidade && cargo == this->cargo && (numeroCandidato<95 || numeroCandidato>98)){
            if(numeroCandidato < 100){
                eleicao->partidoInsereVotos(numeroCandidato, qtdVotos);
            }
            else{
                eleicao->candidatoInsereVotos(numeroCandidato, qtdVotos);
            }
        }
    }
}

Eleicao* Leitor::getEleicao() const{
    return this->eleicao;
}