#include "../include/dadosAposta.hpp"

//Construtor padrão
dadosAposta::dadosAposta(){

}
//Construtor
dadosAposta::dadosAposta( float dinheiroInicial, int rodadas, vector<int> numerosApostados, payoffTable *tabela){
    this->valorInicial = dinheiroInicial;
    this->valorAtual = 0;
    this->valorFinal = valorInicial;
    this->qtdApostas = rodadas;
    this->numerosUsuario = numerosApostados;
    this->tabelaDePagamento = tabela;
}
//Destrutor
dadosAposta::~dadosAposta(){

}

void dadosAposta::mensagemSorteio(int numRodada){
    cout << "     -------------------------------------------------------------------------------------------------" << endl;
    cout << "     " << "Essa é a rodada #" << numRodada + 1 << " de " << this->qtdApostas;
    sleep(1);
    cout << ", sua aposta é de R$" << this->valorInicial/this->qtdApostas << "." << " Boa sorte :)" << endl;
    sleep(2);


}

void dadosAposta::apostaLida( int qtdNumerosApostados){
    int i = 0;
    cout << "     <<< Lendo o arquivo [bet.dat]..." << endl; 
    sleep(2);
    cout << "     >>> " << "Arquivo lido com sucesso!" << endl ;
    sleep(2);
    cout << "     " << "Você apostará um total de" << " R$" << this->valorInicial << endl;
    cout << "     " << "Jogará um total de " << this->qtdApostas << " rodadas" << endl << endl << endl;
    cout << "     " << "Sua aposta tem " << qtdNumerosApostados << " números," << "são eles: ";
    sleep(2);
    cout << "[";
    while( i < qtdNumerosApostados){
        if( i == qtdNumerosApostados-1 ){
            cout << this->numerosUsuario[i];
        }
        else{
            cout << this->numerosUsuario[i] << ",";
        }
        i++;
    }
    cout << "]" << endl;
    cout << "     " << "Você pode checar os seus possíveis retornos na tabela :" << endl << endl;
    sleep(2);
 }

void dadosAposta::mensagemNumerosSorteados(){
    int qtd = this->numerosSorteados.size(), i = 0;
    cout << "     " << "Os números sorteados são: ";
    cout << "[";
    sleep(2);
    while( i < qtd){
        if( i == qtd-1 ){
            cout << this->numerosSorteados[i];
        }
        else{
            cout << this->numerosSorteados[i] << ",";
        }
        i++;
    }
    cout << "]" << endl << endl;
    sleep(2);
}

void dadosAposta::mensagemResultado(int qtd, float valor){
    if(qtd==0){
        cout << "     " << "Você obteve " << qtd << " hits de " << this->numerosUsuario.size() << ".";
        cout << " Sua taxa de retorno é " << valor << endl << endl ;
        this->valorAtual = 0;
        cout << "     " << "Assim, você sai com R$ " << this->valorAtual << endl;
        this->valorFinal = this->valorFinal - this->valorInicial/this->qtdApostas + valorAtual;
        cout << "     " << "Você possui : R$" << valorFinal << endl << endl;
    cout << "     -------------------------------------------------------------------------------------------------" << endl;
    }
    else{
        cout << "     " << "Você obteve " << qtd << " hits de " << this->numerosUsuario.size() << ".";
        cout << " Sua taxa de retorno é " << valor << endl << endl ;
        this->valorAtual += this->valorInicial/this->qtdApostas * valor;
        cout << "     " << "Assim, você sai com R$ " <<  valorAtual << endl;
        this->valorFinal = this->valorFinal - this->valorInicial/this->qtdApostas + valorAtual;
        cout << "     " << "Você possui : R$" << valorFinal<< endl << endl;
        this->valorAtual = 0;
        cout << "     -------------------------------------------------------------------------------------------------" << endl;
    }

}


void dadosAposta::mensagemFinal(){
    float winOrLose = this->valorInicial - this->valorFinal;
    
    cout << "     " << " >>> " << "Fim das rodadas" << endl << endl ;

    cout << "     " << "============= SUMÁRIO =============" << endl;
    cout << "     " << " >>> " << "Você apostou um total de R$ " << this->valorInicial << endl;
    
    if(winOrLose < this->valorInicial){
        cout << "     " << " >>> " << "Você perdeu um total de R$ " << winOrLose << ":(" << endl;
    }
    else if(winOrLose == this->valorInicial){
        cout << "     " << "Você não perdeu e não ganhou dinheiro :D" << endl;
    }
    else{
        cout << "     " << " >>> " << "Você ganhou um total de R$ " << winOrLose << ":)" << endl;
    }

    cout << "     " << " >>> " << "Você terminou o jogo com R$ " << this->valorFinal << " !" << endl << endl;



}

/*! 
 * Métodos para sortear os números
 */

void dadosAposta::sorteiaNumeros(){
    
    int numeroRandomico;
    int qtdNumerosSorteados = 0;
    bool repete;
    int p;
    this->numerosSorteados.clear();
    
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

/*! 
 * Método para checar a quantidade de acertos na aposta
 */

int dadosAposta::checaQtdAcertos(){
    vector<int>::iterator inicio = this->numerosUsuario.begin();
    vector<int>::iterator fim = this->numerosUsuario.end();
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

/*! 
 * Aqui é realizado as rodadas do jogo, esse método chamas as funções
 * que foram modularizadas internamente
 */
void dadosAposta::realizaRodadas(){
    
    float valorRetorno;
    int qtdAcertos;

    for(int i = 0 ; i < this->qtdApostas ; i++){    
        sleep(2);
        mensagemSorteio(i);
        sorteiaNumeros();
        mensagemNumerosSorteados();
        qtdAcertos = checaQtdAcertos();       

        //Pega o retorno na tabela
        valorRetorno = this->tabelaDePagamento->getRetorno( this->numerosUsuario.size(), qtdAcertos);     

        mensagemResultado(qtdAcertos, valorRetorno);
    }
    sleep(2);
    cout << "     Processando resultado....." << endl;
    sleep(2);
    mensagemFinal();

}
