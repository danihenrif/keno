#ifndef DADOSAPOSTA_HPP
#define DADOSAPOSTA_HPP
#include <iostream>
using std::endl;
using std::cout;

#include <vector>
using std::vector;

#include "payoffTable.hpp"

class dadosAposta{
    private:
    float valorInicial;
    float valorAtual;
    float valorFinal;
    int qtdApostas;
    float valorAposta;
    vector<int> numerosUsuario;
    vector<int> numerosSorteados;
    payoffTable *tabelaDePagamento;

    public:
    //construtor e destrutor
    dadosAposta( float dinheiroInicial, int rodadas, float valorApostado, vector<int> numerosApostados, payoffTable *tabela );
    ~dadosAposta();

    void mensagemSorteio(int numRodada);
    void mensagemNumerosSorteados();
    void mensagemResultado(int qtd, float valor);
    void mensagemFinal();
    void realizaRodadas();
    void sorteiaNumeros();
    int checaQtdAcertos();

};
#endif

