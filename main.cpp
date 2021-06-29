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

/*
* A função checa se há números repetidos dentro de um determinado vector a
* 
* @param a determinado vetor
*
* @return true se pelomenos um valor se repete
* @return false se nenhum valor do vetor se repete
*/
bool checaNumerosRepetidos(vector<int> a){
    int aux = 0;
    for(int i = 0; i < a.size() ; i++){
        aux = a[i];
        for(int j = i + 1 ; j < a.size() ; j++){
            if(aux == a[j]){
                return true;
            }
        }
    }
    return false;
}

int main( int argc, char *argv[]){
    //Abre o arquivo
    ifstream arquivo("bet.dat");
    //Vetor para guardade a entrada do arquivo
    vector<float> entrada;
    //Auxiliar para ler o arquivo
    float num;
    //Guarda a quantidade de números que serão apostados
    int qtdNumerosApostados;
    //Instancia a tabela
    payoffTable *tabela = new payoffTable();
    //Guarda o saldo inicial do usuário
    float saldoInicial;
    //Guarda a quantidade de apostas 
    int rodadas;
    //Guarda os números apostados    
    vector <int> numerosApostados;

    //Checa se o arquivo foi aberto
    if(arquivo.bad()){
        std::cerr << "Problema ao abrir o arquivo !!!" << endl;
        exit(1);
    }

    //Lê o arquivo
    while(arquivo >> num){
        entrada.push_back(num);
    }
    
    saldoInicial = entrada[0];
    rodadas = entrada[1];

    //Carregar o vetor com os valores de aposta
    for ( int i = 2; i < entrada.size() ; i++ ){
        numerosApostados.push_back( entrada[i] );
        
        //Checa se há muitos argumentos
        if(i == 17){
            cout << "Há muitos numeros apostados, edite o arquivo bet.dat para continuar jogando!" << endl;
            return 0;
        }
    }

    if(checaNumerosRepetidos(numerosApostados)){
        cout << "Há números repetidos na sequência, edite o arquivo bet.dat para continuar jogando!" << endl;
        return 0;
    }

    qtdNumerosApostados = numerosApostados.size();

    //Instancia os dados
    dadosAposta *dados = new dadosAposta( saldoInicial, rodadas, numerosApostados, tabela);

    dados->apostaLida( qtdNumerosApostados );
    tabela->printaRetorno( qtdNumerosApostados ); 

    //Realiza as rodadas de aposta
    dados->realizaRodadas();

    return 0;
}
