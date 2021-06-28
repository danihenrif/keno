#include <iostream>
using std::cout;
using std::cin;
using std::endl;


#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;

#include "../include/payoffTable.hpp"
#include "../include/dadosAposta.hpp"

void apostaLida( int a, int b, int c, vector<int> vetor, int qtd ){
    int i = 0;
    cout << "     >>> " << "Aposta lida com sucesso!" << endl ;
    cout << "     " << "Você apostará um total de" << " R$" << a << endl;
    cout << "     " << "Jogará um total de " << b << " rodadas" << endl << endl << endl;
    cout << "     " << "Sua aposta tem " << c << " números," << "são eles: ";
    cout << "[";
    while( i < qtd){
        if( i == qtd-1 ){
            cout << vetor[i];
        }
        else{
            cout << vetor[i] << ",";
        }
        i++;
    }
    cout << "]" << endl;
    cout << "     " << "Você pode checar os seus possíveis retornos na tabela :" << endl << endl;
 }

int main( int argc, char *argv[]){
    //Instancia a tabela
    payoffTable *tabela = new payoffTable();
    
    //Guarda a quantidade de números que serão apostados
    int qtdNumerosApostados;
    
    
    float saldoInicial = atof(argv[1]);
    int rodadas = atoi(argv[2]);

    vector <int> numerosApostados;
    
    //Carregar o vetor com os valores de aposta
    for ( int i = 4; i < argc ; i++ ){
        numerosApostados.push_back( atof(argv[i]));
    }

    qtdNumerosApostados = numerosApostados.size();

    apostaLida( saldoInicial ,rodadas, qtdNumerosApostados, numerosApostados,qtdNumerosApostados );
    tabela->printaRetorno(qtdNumerosApostados); 

    //Instancia os dados
    dadosAposta *dados = new dadosAposta( saldoInicial, rodadas, numerosApostados, tabela);

    //Realiza as rodadas de aposta
    dados->realizaRodadas();

    return 0;
}
