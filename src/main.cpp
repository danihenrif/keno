#include <iostream>
using std::cout;
using std::cin;
using std::endl;


#include "../include/payoffTable.hpp"


int main( int argc, char *argv[]){
    payoffTable *tabela = new payoffTable();

    tabela->printaTabela();

}
