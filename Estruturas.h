#include <random>
#pragma once
#ifndef STRUCT_HEADER  //begin header guard
#define STRUCT_HEADER
const float PI = 3.14159265358979323846;

const int numPaderes = 5;

static int bodies;

struct CorpoCeleste {
    long double distSol;
    long double massa;
    long double velRot;
};

//Usado na função shader2D para retornar 2 valores
struct direcaoXY {
    double dX;
    double dY;
};

//Fonte de luz
struct Luz {
    double posiX = 0;
    double posiY = 0;

    double tamanho = 1.5;
    double intensidade = 1;

    double corR = 1;
    double corG = 1;
    double corB = 1;
};

//Corpos com informações necessárias para a criação de gravidade
struct Body {
    long double massa;
    long double tamanho;
    long double velocidadeX;
    long double velocidadeY;
    double posiX;
    double posiY;
    double corR;
    double corG;
    double corB;
};

//Coordenadas das paredes
struct Parede {
    double x3, y3; //Começo da parede
    double x4, y4; //Fim da parede
};

struct circulo360Vert {
    double cvX[360];
    double cvY[360];
};


#endif //STRUCT_HEADER //end header guard

/*
#include <random>
#pragma once
#ifndef STRUCT_HEADER  //begin header guard
#define STRUCT_HEADER
const float PI = 3.14159265358979323846;

const int numPaderes = 5;

static int bodies;

struct CorpoCeleste {
    long double distSol;
    long double massa;
    long double velRot;
};

//Usado na função shader2D para retornar 2 valores
struct direcaoXY {
    double dX;
    double dY;
};

//Fonte de luz
struct Luz {
    double posiX = 0;
    double posiY = 0;

    double tamanho = 1.5;
    double intensidade = 1;

    double corR = 1;
    double corG = 1;
    double corB = 1;
};

//Corpos com informações necessárias para a criação de gravidade
struct Body {
    long double massa;
    long double tamanho;
    long double velocidadeX;
    long double velocidadeY;
    double posiX;
    double posiY;

    double corR;
    double corG;
    double corB;
};

//Coordenadas das paredes
struct Parede {
    double x3, y3; //Começo da parede
    double x4, y4; //Fim da parede
};

struct circulo360Vert {
    double cvX[360];
    double cvY[360];
};


#endif //STRUCT_HEADER //end header guard

*/