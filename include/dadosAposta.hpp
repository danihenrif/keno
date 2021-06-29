#ifndef DADOSAPOSTA_HPP
#define DADOSAPOSTA_HPP
#include <iostream>
using std::endl;
using std::cout;

#include <unistd.h>

#include <vector>
using std::vector;

#include "payoffTable.hpp"

class dadosAposta{
    private:
    float valorInicial;
    float valorAtual;
    float valorFinal;
    int qtdApostas;
    vector<int> numerosUsuario;
    vector<int> numerosSorteados;
    payoffTable *tabelaDePagamento;

    public:
    //construtor e destrutor
    dadosAposta();
    dadosAposta( float dinheiroInicial, int rodadas, vector<int> numerosApostados, payoffTable *tabelaDePagamento );
    ~dadosAposta();

    void apostaLida( int qtdNumerosApostados );
    void mensagemSorteio(int numRodada);
    void mensagemNumerosSorteados();
    void mensagemResultado(int qtd, float valor);
    void mensagemFinal();
    void realizaRodadas();
    void sorteiaNumeros();
    int checaQtdAcertos();

};
#endif

