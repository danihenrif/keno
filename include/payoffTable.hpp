#include <iostream>

class payoffTable {
    private:
    float payTable[16][16];
    
    public:
    payoffTable();
    ~payoffTable();
    
    void printaTabela();
};
