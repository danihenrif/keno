#ifndef PAYOFFTABLE_HPP
#define PAYOFFTABLE_HPP
#include <iostream>

class payoffTable {
    private:
    float payTable[16][16];
    
    public:
    payoffTable();
    ~payoffTable();
    
    void printaTabela();
    float getRetorno( int linha , int coluna);
};
#endif
