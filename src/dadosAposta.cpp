#include "../include/dadosAposta.hpp"

dadosAposta::dadosAposta( float dinheiroInicial, int rodadas, vector<float> numerosApostados, payoffTable *tabela){
    this->valorInicial = dinheiroInicial;
    this->qtdApostas = rodadas;
    this->numerosUsuario = numerosApostados;
    this->tabelaDePagamento = tabela;
}

dadosAposta::~dadosAposta(){

}

void dadosAposta::sorteiaNumeros(){
    
    int numeroRandomico;
    int qtdNumerosSorteados = 0;
    bool repete;
    int p;
    
    while( qtdNumerosSorteados != 20 ){
        p=0;
        repete = 0;
        numeroRandomico = 1+rand()%80;
            
        //Checa se o número já se repetiu
        while( p != this->numerosSorteados.size() ){
            if( this->numerosSorteados[p] == numeroRandomico ){
                p = this->numerosSorteados.size();
                repete = 1;
            }
            else{
                p++;
            }
        }
            
        //Se não se repetiu entra como valor sorteado
        if(!repete){
            this->numerosSorteados.push_back( numeroRandomico );
            qtdNumerosSorteados++;
        }
    }   
}

int dadosAposta::checaQtdAcertos(){
    vector<float>::iterator inicio = this->numerosUsuario.begin();
    vector<float>::iterator fim = this->numerosUsuario.end();
    int qtdAcertos = 0;
    
    while( inicio != fim ){
        for( int j = 0 ; j < 20 ; j++ ){
            if( *inicio == this->numerosSorteados[j] ){
                qtdAcertos++;
            }
        }
        inicio++;
    }
    return qtdAcertos;
}

void dadosAposta::realizaRodadas(){
    
    float valorRetorno;
    int qtdAcertos;

    for(int i = 0 ; i < this->qtdApostas ; i++){    

        sorteiaNumeros();
        qtdAcertos = checaQtdAcertos();

        //Direciona os valores ganhados ou perdidos
        if( qtdAcertos == 0){
            cout << "     Você não acertou nenhum número e com isso perdeu todo o seu valor apostado :C" << "Tente novamente" << endl;
        }
        else{
            valorRetorno = this->tabelaDePagamento->getRetorno( this->numerosUsuario.size(), qtdAcertos);      
        }
    }

}
