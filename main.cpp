#include <iostream>
using std::cout;
using std::cin;
using std::endl;


#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;

#include "include/payoffTable.hpp"
#include "include/dadosAposta.hpp"

void apostaLida( float a, int b, int c, vector<int> vetor, int qtd ){
    int i = 0;
    cout << "     <<< Lendo o arquivo [bet.dat]..." << endl; 
    cout << "     >>> " << "Arquivo lida com sucesso!" << endl ;
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
   
    ifstream arquivo("bet.dat");
    vector<float> entrada;
    float num;

    while(arquivo >> num){
        entrada.push_back(num);
    }

    //Instancia a tabela
    payoffTable *tabela = new payoffTable();
    
    //Guarda a quantidade de números que serão apostados
    int qtdNumerosApostados;
    
    
    float saldoInicial = entrada[0];
    int rodadas = entrada[1];

    vector <int> numerosApostados;
    
    //Carregar o vetor com os valores de aposta
    for ( int i = 2; i < entrada.size() ; i++ ){
        numerosApostados.push_back( entrada[i] );
        //Ja há 18 argumentos
        if(i == 17){
            cout << "Há muitos numeros apostados, edite o arquivo bet.dat para continuar jogando!" << endl;
        }
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
