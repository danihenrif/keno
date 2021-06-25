#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;


#include "../include/payoffTable.hpp"
#include "../include/dadosAposta.hpp"



int main( int argc, char *argv[]){
    //Instancia a tabela
    payoffTable *tabela = new payoffTable();
    
    float saldoInicial = atof(argv[1]), rodadas = atof(argv[2]);
    
    vector <float> numerosApostados;

    //Carregar o vetor com os valores de aposta
    for ( int i = 3; i < argc ; i++ ){
        numerosApostados.push_back( atof(argv[i]));
    }

    //Instancia os dados
    dadosAposta *dados = new dadosAposta( saldoInicial, rodadas, numerosApostados, tabela);

    //Realiza as rodadas de aposta
    dados->realizaRodadas();

    return 0;

}
