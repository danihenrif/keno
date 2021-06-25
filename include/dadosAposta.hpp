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
    int qtdApostas;
    int qtdAcertos;
    vector<float> numerosUsuario;
    vector<float> numerosSorteados;
    payoffTable *tabelaDePagamento;

    public:
    //construtor e destrutor
    dadosAposta( float dinheiroInicial, int rodadas, vector<float> numerosApostados, payoffTable *tabela );
    ~dadosAposta();

    void realizaRodadas();

};
#endif

