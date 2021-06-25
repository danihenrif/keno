#include <iostream>
using std::cout;
using std::endl;

#include "../include/payoffTable.hpp"

payoffTable::payoffTable(){
    
    //Zera toda a table
    for( int i = 0 ; i < 16 ; i++){
        for (int j = 0 ; j < 16 ; j++){
            this->payTable[i][j] = 0;
        }
    }

    //preenche linha 1
    this->payTable[1][1] = 3;

    //preenche linha 2
    this->payTable[2][1] = 1;
    this->payTable[2][2] = 9;

    //preenche linha 3
    this->payTable[3][1] = 1;
    this->payTable[3][2] = 2;
    this->payTable[3][3] = 16;

    //preenche linha 4
    this->payTable[4][1] = 0.5;
    this->payTable[4][2] = 2;
    this->payTable[4][3] = 6;
    this->payTable[4][4] = 12;

    //preenche linha 5
    this->payTable[5][1] = 0.5;
    this->payTable[5][2] = 1;
    this->payTable[5][3] = 3;
    this->payTable[5][4] = 15;
    this->payTable[5][5] = 50;

    //preenche linha 6
    this->payTable[6][1] = 0.5;
    this->payTable[6][2] = 1;
    this->payTable[6][3] = 2;
    this->payTable[6][4] = 3;
    this->payTable[6][5] = 30;
    this->payTable[6][6] = 75;

    //preenche linha 7
    this->payTable[7][1] = 0.5;
    this->payTable[7][2] = 0.5;
    this->payTable[7][3] = 1;
    this->payTable[7][4] = 6;
    this->payTable[7][5] = 12;
    this->payTable[7][6] = 36;
    this->payTable[7][7] = 100;

    //preenche linha 8
    this->payTable[8][1] = 0.5;
    this->payTable[8][2] = 0.5;
    this->payTable[8][3] = 1;
    this->payTable[8][4] = 3;
    this->payTable[8][5] = 6;
    this->payTable[8][6] = 19;
    this->payTable[8][7] = 90;
    this->payTable[8][8] = 720;
    
    //preenche linha 9
    this->payTable[9][1] = 0.5;
    this->payTable[9][2] = 0.5;
    this->payTable[9][3] = 1;
    this->payTable[9][4] = 2;
    this->payTable[9][5] = 4;
    this->payTable[9][6] = 8;
    this->payTable[9][7] = 20;
    this->payTable[9][8] = 80;
    this->payTable[9][9] = 1200;

    //preenche linha 10
    this->payTable[10][1] = 0;
    this->payTable[10][2] = 0.5;
    this->payTable[10][3] = 1;
    this->payTable[10][4] = 2;
    this->payTable[10][5] = 3;
    this->payTable[10][6] = 5;
    this->payTable[10][7] = 10;
    this->payTable[10][8] = 30;
    this->payTable[10][9] = 600;
    this->payTable[10][10] = 1800;

    //preenche linha 11
    this->payTable[11][1] = 0;
    this->payTable[11][2] = 0.5;
    this->payTable[11][3] = 1;
    this->payTable[11][4] = 1;
    this->payTable[11][5] = 2;
    this->payTable[11][6] = 6;
    this->payTable[11][7] = 15;
    this->payTable[11][8] = 25;
    this->payTable[11][9] = 180;
    this->payTable[11][10] = 1000;
    this->payTable[11][11] = 3000;

    //preenche linha 12
    this->payTable[12][1] = 0;
    this->payTable[12][2] = 0;
    this->payTable[12][3] = 0.5;
    this->payTable[12][4] = 1;
    this->payTable[12][5] = 2;
    this->payTable[12][6] = 4;
    this->payTable[12][7] = 24;
    this->payTable[12][8] = 72;
    this->payTable[12][9] = 250;
    this->payTable[12][10] = 500;
    this->payTable[12][11] = 2000;
    this->payTable[12][12] = 4000;

    //preenche linha 13
    this->payTable[13][1] = 0;
    this->payTable[13][2] = 0;
    this->payTable[13][3] = 0.5;
    this->payTable[13][4] = 0.5;
    this->payTable[13][5] = 3;
    this->payTable[13][6] = 4;
    this->payTable[13][7] = 5;
    this->payTable[13][8] = 20;
    this->payTable[13][9] = 80;
    this->payTable[13][10] = 240;
    this->payTable[13][11] = 500;
    this->payTable[13][12] = 3000;
    this->payTable[13][13] = 6000;

    //preenche linha 14
    this->payTable[14][1] = 0;
    this->payTable[14][2] = 0;
    this->payTable[14][3] = 0.5;
    this->payTable[14][4] = 0.5;
    this->payTable[14][5] = 2;
    this->payTable[14][6] = 3;
    this->payTable[14][7] = 5;
    this->payTable[14][8] = 12;
    this->payTable[14][9] = 50;
    this->payTable[14][10] = 150;
    this->payTable[14][11] = 500;
    this->payTable[14][12] = 1000;
    this->payTable[14][13] = 2000;
    this->payTable[14][14] = 7500;

    //preenche linha 14
    this->payTable[15][1] = 0;
    this->payTable[15][2] = 0;
    this->payTable[15][3] = 0.5;
    this->payTable[15][4] = 0.5;
    this->payTable[15][5] = 1;
    this->payTable[15][6] = 2;
    this->payTable[15][7] = 5;
    this->payTable[15][8] = 15;
    this->payTable[15][9] = 50;
    this->payTable[15][10] = 150;
    this->payTable[15][11] = 300;
    this->payTable[15][12] = 600;
    this->payTable[15][13] = 1200;
    this->payTable[15][14] = 2500; 
    this->payTable[15][15] = 10000;     
}

void payoffTable::printaTabela(){
    for(int i = 0 ; i < 16 ; i++){
        for(int j = 0 ; j < 16 ; j++){
            cout << this->payTable[i][j] << "     ";
        }
        cout << endl;
    }
}

float payoffTable::getRetorno(int linha, int coluna){
    return this->payTable[linha][coluna];
}
