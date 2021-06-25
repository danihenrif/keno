#include "../include/dadosAposta.hpp">


dadosAposta::dadosAposta( float dinheiroInicial, int rodadas, vector<float> numerosApostados, payoffTable *tabela){
    this->valorInicial = dinheiroInicial;
    this->qtdApostas = rodadas;
    this->numerosUsuario = numerosApostados;
    this->tabelaDePagamento = tabela;
}

dadosAposta::~dadosAposta(){

}

void dadosAposta::realizaRodadas(){
    
    float valorRetorno;

    for(int i = 0 ; i < this->qtdApostas ; i++){
        this->qtdAcertos = 0;

        //Sorteia os números
        for(int j = 0 ; j < 20 ; j++){
            this->numerosSorteados.push_back( 1+rand()%80);
        }

        //Checa a quantidade de acertos
        for( int i = 0 ; i < this->numerosUsuario.size() ; i++ ){
            for(int j = 0 ; j < 20 ; j++){
                if( this->numerosUsuario[i] == this->numerosSorteados[j]){
                    qtdAcertos++;
                }
            }
        }

        //Direciona os valores ganhados ou perdidos
        if( this->qtdAcertos == 0){
            cout << "     Você não acertou nenhum número e com isso perdeu todo o seu valor apostado :C" << "Tente novamente" << endl;
        }
        else{
            valorRetorno = this->tabelaDePagamento->getRetorno( this->numerosUsuario.size(), qtdAcertos);
            cout << "Valor de retorno : " << valorRetorno << endl;         
        }
    }

}
