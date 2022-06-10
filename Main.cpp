/*
* Um projeto feito com o objetivo de aprender! Não somente
* Opengl e C++, e sim aprender programação, matemática, fisica,
* geometria, e mais matemática!
* 
* A project made with the objective of learn! Not only Opengl
* and C++, but learn programming, math, fisics, geometry and
* more math!
* 
* author Eduardo Oliveira
* email: Eduardo.Oliveira100@fatec.sp.gov.br
* date: 19 july 2021
* 
*/


#include <iostream>
#include <GLFW/glfw3.h>
#include "Shader2D.cpp"
//#include <GL/glut.h>
#include <math.h>
#include <random>
#include "Estruturas.h"
#include "DetectarColisao.cpp"
#include "Mouse.cpp"
#include "Configuracao.h"

GLFWwindow* window;

int w = 1280;
int h = 720;

Shader shader;
DetectarColisao dCol; //Em construção
Mouse Mo(w, h);

double G = 6.67*(pow(10,-11)); //Constante gravitacional universal

CorpoCeleste mercurio; //Mercury
CorpoCeleste venus;
CorpoCeleste terra; //Earth
CorpoCeleste marte; //Mars
CorpoCeleste jupiter;
CorpoCeleste saturno; //Saturn
CorpoCeleste urano; //Uranus
CorpoCeleste netuno; //Neptune
CorpoCeleste plutao; //Pluto
const int numeroPlanetas = 9;

long double Escala = 1.0 / 99999999999 / 99999999; //1.0 / 99999999999 / 99999999999 / 999 Terra ~= tamanho da tela


float SolMassa = 1.98 * (pow(10, 30)); //1988999999999999999999999999987
float MerMassa = 3.28 * (pow(10, 23));
float VenMassa = 4.86 * (pow(10, 24));
float TerMassa = 5.97 * (pow(10, 24));
float MarMassa = 6.39 * (pow(10, 23));
float JupMassa = 1.89 * (pow(10, 27));
float SatMassa = 5.68 * (pow(10, 26));
float UraMassa = 8.68 * (pow(10, 25));
float NetMassa = 1.02 * (pow(10, 26));
float PluMassa = 1.30 * (pow(10, 22));

/*
SOL 1989 * 10^30 kg

Distancia do sol (km) | massa (kg) | Velocidade orbital |

mercúrio - 57910000 - 3.285 * 10^23 - 47.362 km/s
Vênus - 108208930 - 4.867 * 10^24 - 35.02 km/s
Terra - 149597870 - 5.972 * 10^24 -  30 km/s
Marte - 227936640 - 6.39 * 10^23 - 24.077 km/s
Júpiter - 778412010 - 1.898 * 10^27 - 13.07 km/s
Saturno - 1426725400 - 5.683 * 10^26 - 9.69 km/s
Urano - 2870972200 - 8.681 * 10^25 - 6.83 km/s
Netuno - 4498252900 - 1.024 * 10^26 - 5.5 km/s
Plutão - 5922000000 - 1.3 * 10^22 - 4.66 km/s

referência:
força da gravidade entre a Terra e o Sol:
3.52 * 10^22 newtons
*/

const long double terraSolN = 3.52 * pow(10, 22);




//Vertices do circulo
float verCirX[360];
float verCirY[360];

//Definitivamente não precisamos de 300 vertices kkkkkk 36 é o suficiente
float verCirX2[36];
float verCirY2[36];

//Aumento ou Diminuição do tempo
float timeWarp = Time_Warp_Inicial;

//Usado para aumentar ou diminuir somente uma vez ao apertar a tecla
bool warp = true; //Tempo
bool reiniciar = true;

bool pausarSwitch = false;
bool pausar = false;

//Parada de emergêmcia (que não funciona muito bem)
bool stop = false;

//Variável para zoom da camera que não funciona
float zoom = 0;

//Numero de corpos no cenário
const int numBody = Numero_De_Corpos;
const int numParede = 5;

Body body[numBody];
Parede parede[numParede];

//Luzes '-'
Luz luz[numBody];

//RETANGULO!
float retanguloTamanhoTeste = 0.1;
float retanguloPosiX = 1;
float retanguloPosiY = 0;

//Um multiplicador para que a velocidade da câmera aumente ou diminui com o zoom
float mult = Velocidade_Da_Camera;

float multWarp = 1;

void correcaoNewtons(long double n1, long double ref) {
    
    std::cout << "\n\nForça gravidade calculado T.S: " << n1 <<"\n";
    std::cout << "Força gravidade T.S REAL: " << ref <<"\n";
    n1 = n1 - ref;
    std::cout << "Diferenca: " << n1 <<"\n\n";

}

void iniciarPlanetas() {
    std::cout << Escala << " escala\n";
    //for (int i = 0; i <= numBody; i++) {}
    /*
float SolMassa = 1.98 * (pow(10, 30)); //1988999999999999999999999999987
float MerMassa = 3.28 * (pow(10, 23));
float VenMassa = 4.86 * (pow(10, 24));
float TerMassa = 5.97 * (pow(10, 24));
float MarMassa = 6.39 * (pow(10, 23));
float JupMassa = 1.89 * (pow(10, 27));
float SatMassa = 5.68 * (pow(10, 26));
float UraMassa = 8.68 * (pow(10, 25));
float NetMassa = 1.02 * (pow(10, 26));
float PluMassa = 1.30 * (pow(10, 22));
*/

/*
SOL 1989 * 10^30 kg

Distancia do sol (km) | massa (kg) | Velocidade orbital |

mercúrio - 57910000 - 3.285 * 10^23 - 47.362 km/s
Vênus - 108208930 - 4.867 * 10^24 - 35.02 km/s
Terra - 149597870 - 5.972 * 10^24 -  30 km/s
149 597 870,691
Marte - 227936640 - 6.39 * 10^23 - 24.077 km/s
Júpiter - 778412010 - 1.898 * 10^27 - 13.07 km/s
Saturno - 1426725400 - 5.683 * 10^26 - 9.69 km/s
Urano - 2870972200 - 8.681 * 10^25 - 6.83 km/s
Netuno - 4498252900 - 1.024 * 10^26 - 5.5 km/s
Plutão - 5922000000 - 1.3 * 10^22 - 4.66 km/s

https://nssdc.gsfc.nasa.gov/planetary/factsheet/planet_table_ratio.html

referência:
força da gravidade entre a Terra e o Sol:
3.52 * 10^22 newtons

*/

    mercurio.massa = 3.28 * (pow(10, 23)) * Escala;
    mercurio.distSol = 57910000 * Escala;
    mercurio.velRot = 47.36 * Escala / 1000;

    venus.massa = 4.86 * (pow(10, 24)) * Escala;
    venus.distSol = 108208930 * Escala;
    venus.velRot = 35.02 * Escala / 1000;

    terra.massa = 5.97 * (pow(10, 24)) * Escala;
    terra.distSol = 149597870 * Escala;
    terra.velRot = 30.00 * Escala / 1000;

    marte.massa = 6.39 * (pow(10, 23)) * Escala;
    marte.distSol = 227936640 * Escala;
    marte.velRot = 24.07 * Escala / 1000;

    jupiter.massa = 1.89 * (pow(10, 27)) * Escala;
    jupiter.distSol = 778412010 * Escala;
    jupiter.velRot = 13.07 * Escala / 1000;

    saturno.massa = 5.68 * (pow(10, 26)) * Escala;
    saturno.distSol = 1426725400 * Escala;
    saturno.velRot = 9.69 * Escala / 1000;

    urano.massa = 8.68 * (pow(10, 25)) * Escala;
    urano.distSol = 2870972200 * Escala;
    urano.velRot = 6.83 * Escala / 1000;

    netuno.massa = 1.02 * (pow(10, 26)) * Escala;
    netuno.distSol = 4498252900 * Escala;
    netuno.velRot = 5.50 * Escala / 1000;

    plutao.massa = 1.30 * (pow(10, 22)) * Escala;
    plutao.distSol = 5922000000 * Escala;
    plutao.velRot = 4.66 * Escala / 1000;

}
void atribuirPlanetas() {
    //Sol
    body[9].massa = SolMassa * Escala;// terra.massa * 333000 * Escala;
    body[9].posiY = 0;
    body[9].posiX = 0;
    body[9].corR = 1;
    body[9].corG = 1;
    body[9].corB = 1;
    body[9].tamanho = 10;
    body[9].velocidadeX = 0;
    body[9].velocidadeY = 0;
    luz[9].tamanho = 6;
    luz[9].corR = body[9].corR;
    luz[9].corG = body[9].corG;
    luz[9].corB = body[9].corB;

    body[0].massa = mercurio.massa;
    body[0].posiY = mercurio.distSol;
    body[0].velocidadeX = mercurio.velRot;

    body[1].massa = venus.massa;
    body[1].posiY = venus.distSol;
    body[1].velocidadeX = venus.velRot;

    body[2].massa = terra.massa;
    body[2].posiY = terra.distSol;
    body[2].velocidadeX = terra.velRot;
    luz[2].tamanho = 5;

    body[3].massa = marte.massa;
    body[3].posiY = marte.distSol;
    body[3].velocidadeX = marte.velRot;

    body[4].massa = jupiter.massa;
    body[4].posiY = jupiter.distSol;
    body[4].velocidadeX = jupiter.velRot;

    body[5].massa = saturno.massa;
    body[5].posiY = saturno.distSol;
    body[5].velocidadeX = saturno.velRot;

    body[6].massa = urano.massa;
    body[6].posiY = urano.distSol;
    body[6].velocidadeX = urano.velRot;

    body[7].massa = netuno.massa;
    body[7].posiY = netuno.distSol;
    body[7].velocidadeX = netuno.velRot;

    body[8].massa = plutao.massa;
    body[8].posiY = plutao.distSol;
    body[8].velocidadeX = plutao.velRot;

    std::cout << body[4].posiY << "\n";

    //glScaled(0.0000000001, 0.0000000001, 0);
    //Mo.setCameraZoom(19999999); //1.01
    //mult *= 19999999;
}

//A função iniciar só será chamada uma vez, ao menos que o comando de reiniciar seja acionado
void iniciar() {
    Escala = 1;



    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    

    //glScaled(0.0000000001, 0.0000000001, 0);
    //Mo.setCameraZoom(19999999); //1.01
    //mult *= 19999999;
    Mo.iniciar(w, h);
    //Coletando vertices de um circulo, usando o coseno como ponto X
    //E o seno como ponto Y
    for (int v = 0; v < 360; v++) {
        verCirX[v] = (cos(v * PI / 180));
        verCirY[v] = (sin(v * PI / 180));
    }

    for (int v = 0; v < 36; v++) {
        verCirX2[v] = (cos(v*10 * PI / 180));
        verCirY2[v] = (sin(v*10 * PI / 180));
    }
    

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-100, 100); // define the range

    for (int i = 0; i + 1 <= numBody; i++) {
        //min + ( std::rand() % ( max - min + 1 ) )

        //Gera os corpos de maneira aleatoria
        //double m = distr(gen) + 125; //massa - Antigo
        double m = Massa_Minima_Dos_Corpos + (((Massa_Maxima_Dos_Corpos * (distr(gen)+100))/200) % (Massa_Maxima_Dos_Corpos+1 - Massa_Minima_Dos_Corpos)); //massa
        //m = m / 7;
        double px = distr(gen); //Posição xDistribuicao_Dos_Corpos
        px = px * (Distribuicao_Dos_Corpos / 100); //px / 100 /1.5;
        double py = distr(gen); //Posição y
        py = py * (Distribuicao_Dos_Corpos / 100);

        //Gerando as cores aleatóriamente para cada corpo
        double r = distr(gen);
        double g = distr(gen);
        double b = distr(gen);
        r = (r + 100) / 200;
        g = (g + 100) / 200;
        b = (b + 100) / 200;

        //Velocidade
        double vx = distr(gen);
        double vy = distr(gen);
        vx /= 10000000*4;
        vy /= 10000000*4;

        body[i].massa = m; //m*(pow(10,10)); valores altos, movimentos lentos
        body[i].posiX = px;
        body[i].posiY = py;
        body[i].tamanho = body[i].massa/500; //body[i].massa/5000000000000; valores altos, movimentos lentos
        body[i].velocidadeX = vx;
        body[i].velocidadeY = vy;

        body[i].corR = r;
        body[i].corG = g;
        body[i].corB = b;

        luz[i].corR = r + 0.15;
        luz[i].corG = g + 0.15;
        luz[i].corB = b + 0.15;

        luz[i].tamanho = m / 3;
    }

    /////// PAREDE ////////
    for (int i = 0; i + 1 <= numParede; i++) {
        double px = distr(gen); //Posição x
        px = px * (0.9 / 100);
        double py = distr(gen); //Posição y
        py = py * (0.9 / 100);

        parede[i].x3 = px;
        parede[i].y3 = py;

        px = distr(gen); //Posição x
        px = px * (0.9 / 100);
        py = distr(gen); //Posição y
        py = py * (0.9 / 100);

        parede[i].x4 = px;
        parede[i].y4 = py;
    }

    //player
    //luz[0].tamanho = 1;
    luz[0].corR = 1;
    luz[0].corG = 0;
    luz[0].corB = 0;

    /*
    body[0].massa = 25; //10000
    body[0].posiX = 0;
    body[0].posiY = 0;
    body[0].tamanho = body[0].massa/500; // / 500000;
    body[0].velocidadeX = 0;
    body[0].velocidadeY = 0;
    */
    //SetCursorPos(mid_x, mid_y); // :O

    


    
    timeWarp = Time_Warp_Inicial;//Reiniciando timeWarp
    mult = Velocidade_Da_Camera; //Reiniciando velocidade da camera


    //iniciarPlanetas();
    //atribuirPlanetas();
    /*
    body[2].massa = terra.massa;
    body[2].posiY = 0;
    body[2].velocidadeX = terra.velRot;
    body[2].tamanho = terra.massa/99999999999/99999999999/999;
    */
    //Reiniciando camera
    glPopMatrix();
    glPushMatrix();


    ////
    //glScaled(0.0190, 0.0190, 0);


    

    std::cout << "INICIADO :)\n";
}

//Comandos do teclado
void move() {
    //Aumentar a velocidade do tempo
    if (GetAsyncKeyState((unsigned short)'O')) {
        if (warp) {
            timeWarp *= 2.0;
            warp = false;

            std::cout << "Time warp: " << timeWarp << "\n";
            mult = mult / 2;
        }

    }
    else if (GetAsyncKeyState((unsigned short)'I')) {
        if (warp && timeWarp > 0.05) {
            timeWarp *= 0.5;
            warp = false;

            std::cout << "Time warp: " << timeWarp << "\n";
            mult = mult * 2;
        }

    }
    //Esse multiplicador de time warp multiplica a força da gravidade e a velocidade, dando a ilusão de time warp
    //Em 60 ticks por segundo, ou seja, no Time warp 1, o maximo do multiplicador é 1024(O que é ótimo :D) e mantendo
    //a física estável!
    else if (GetAsyncKeyState((unsigned short)'U')) {
        if (warp) {
            multWarp *= 2.0;
            warp = false;

            std::cout << "MultWarp: " << multWarp << "\n";
            if (multWarp >= 512) {
                std::cout << "-Atencao! o multWarp somente multiplica a velocidade!\n Valores muito altos podem interferir na fisica!-\n";
            }
            //mult = mult / 2;
        }

    }
    else if (GetAsyncKeyState((unsigned short)'Y')) {
        if (warp) {
            multWarp *= 0.5;
            warp = false;

            std::cout << "MultWarp: " << multWarp << "\n";

            //mult = mult * 2;
        }

    }
    else {
        warp = true;
    }

    //Pausar!
    if (GetAsyncKeyState((unsigned short)'P')) {
        if (!pausarSwitch) {

            pausarSwitch = true;

            if (pausar) {
                pausar = false;
                std::cout << "-CONTINUAR- " << "\n";
            }
            else {
                pausar = true;
                std::cout << "-PAUSADO- " << "\n";
            }
            

        }

    }
    else {
        pausarSwitch = false;
    }
    
    if (GetAsyncKeyState((unsigned short)'R')) {
        
        if (reiniciar) {
            iniciar();
            reiniciar = false;
        }
        //std::cout << "Reiniciado\n";
    }
    else {
        reiniciar = true;
    }
    //Todos os corpos, velocidade = 0
    if (GetAsyncKeyState((unsigned short)'T')) {
        for (int i = 0; i + 1 <= numBody; i++) {

            body[i].velocidadeX = 0.0;
            body[i].velocidadeY = 0.0;

            //std::cout << "Velocidade resetada\n";
        }
    }

}
float camX = 1;
float camY = 1;
void independentMove() {

    if (GetAsyncKeyState((unsigned short)'W')) {
        glTranslatef(0, -0.003 * mult, 0);
        Mo.setCameraY(0.003);
        camY *= -0.003;
    }
    //std::cout << mult << "\n";

    if (GetAsyncKeyState((unsigned short)'A')) {
        glTranslatef(0.003 * mult, 0, 0);
        Mo.setCameraX(-0.003);
        camX *= 0.003;
    }

    if (GetAsyncKeyState((unsigned short)'S')) {
        glTranslatef(0, 0.003 * mult, 0);
        Mo.setCameraY(-0.003);
        camY *= 0.003;
    }

    if (GetAsyncKeyState((unsigned short)'D')) {
        glTranslatef(-0.003 * mult, 0, 0);
        Mo.setCameraX(0.003);
        camX *= 0.003;
    }

    //Zoom
    //O zoom não funciona muito bem, as coordenadas da tela ficam descronizados com a do mouse
    if (GetAsyncKeyState((unsigned short)'Z')) {
        //glPushMatrix();
        //glTranslatef(-0.003, -0.003, 0);
        glScaled(1.01, 1.01, 0);
        Mo.setCameraZoom(0.99); //0.99
        mult *= 0.99;
        //glPopMatrix();
    }
    if (GetAsyncKeyState((unsigned short)'X')) {
        //glPushMatrix();
        //glTranslatef(0.003, 0.003, 0);
        glScaled(0.990, 0.990, 0);
        Mo.setCameraZoom(1.01); //1.01
        mult *= 1.01;
        //glPopMatrix();
    }

    //Mo.setMult(mult / 10);
}

bool LMB; // = Left Mouse Button = Botão Esquerdo do Mouse
void mouse() {
    //Se clicar com o botão esquerdo do mouse
    if (GetAsyncKeyState(VK_LBUTTON)) {
        LMB = true;
    }
    else {
        LMB = false;
    }
}
//Calculo exponencial mais otimizado?
template <typename T>
T expt(T p, unsigned q) {
    T r = 1;
    while (q != 0) {
        if (q % 2 == 1) {    // if q is odd
            r *= p;
            q--;
        }
        p *= p;
        q /= 2;
    }
    return r;
}

int contTemporario = 0;
//Atualiza a gravidade de todos os corpos usando newtons v1.5(melhor otimizado)
void cadaGravidade(Body *body) {
    double px=0, py=0, objx=0, objy=0, m1=0, m2=0;
    //double objx = 0, objy = 0, m2 = 0;
    //Seleção dos corpos

    for (int i = 0; i < numBody; i++) {
        px = body[i].posiX;
        py = body[i].posiY;
        m1 = body[i].massa;

        //Não podemos calcular a gravidade do mesmo corpo, logo: i+1
        for (int j = 1 + i; j < numBody; j++) {
                objx = body[j].posiX;
                objy = body[j].posiY;
                m2 = body[j].massa;

                //Teorema de Pitagoras para calcular a distância
                float diferencaX = objx - px;
                float diferencaY = objy - py;
                float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
                distancia = sqrt(distancia);
                //distancia /= 1000;
                //m1 = TerMassa;// 5.97 * pow(10, 22);
                //m2 = 75;
                //distancia = (1.737 + 559) * pow(10, 6);
                //pow(10, 6)

                //std::cout << distancia <<" " << i << j << "\n";

                //OTIMIZAÇÃO temporaria e errada, pois corpos gigantes tem alcance maior de gravidade
                //if (distancia < 3.0 && distancia > 0.01) { //0.02
                       
                    //Newton's Law of Universal Gravitation (detalhe: multiplicar distancia por pow(10, 6) pra converter km para milimetros, n sei pq :/ mas tem que fazer)
                    long double F = ((G * m1 * m2) / expt((distancia), 2)) * multWarp;

                    //std::cout << F << "\n";
                    
                    if (i == 0 && j == 9) {
                        //std::cout << terraSolN << "\n";
                        //correcaoNewtons(F, terraSolN);



                        F = terraSolN;// *100000 * 100000 * 100000 * 100000 * 100000;
                        contTemporario++;
                        F *= expt(10, 12);
                        if (contTemporario == 1000) {

                            std::cout << F << "\n";
                            contTemporario = 0;
                        }

                    }
                    

                    //Direção
                    float anguloRadians = atan2(diferencaY, diferencaX); //Algulo em radianos
                    float divForX = cos(anguloRadians); //Força dividida de acordo com o coseno
                    float divForY = sin(anguloRadians); //Força dividida de acordo com o seno


                    //std::cout << divForX << " X \n";
                    //std::cout << divForY << " Y \n\n";
                    
                        //Aplicando velocidade de acordo com a força em newtons, a massa do objeto
                        //E Dividindo essa força entre o X e o Y de acordo com a direção :D
                        body[i].velocidadeX += (((divForX * F) / expt(m1, 2) * 2)); 
                        body[i].velocidadeY += (((divForY * F) / expt(m1, 2) * 2));

                        //Mesma força para ambos dos corpos :)
                        body[j].velocidadeX += (((divForX * F) / expt(m2, 2) * 2)*-1);
                        body[j].velocidadeY += (((divForY * F) / expt(m2, 2) * 2)*-1);
                        
                        //body[i].velocidadeX += (((divForX * F) / expt(m1, 2) * 2)); //12/08/21 - Provavelmente errada
                        //body[i].velocidadeY += (((divForY * F) / expt(m1, 2) * 2));

                        //Mesma força para ambos dos corpos :)
                        //body[j].velocidadeX += (((divForX * F) / expt(m2, 2) * 2) * -1);
                        //body[j].velocidadeY += (((divForY * F) / expt(m2, 2) * 2) * -1);
                //}
            
        }

        //CORES (de acordo com a sua velocidade)
        double vxc = body[i].velocidadeX;
        double vyc = body[i].velocidadeY;

        if (vxc < 0)
            vxc = vxc * -1;
        if (vyc < 0)
            vyc = vyc * -1;

        double media = (vxc + vyc) / 2;

        body[i].corR = media * 30000;
        body[i].corG = (media * 30000) - 0.4;//media*1;
        body[i].corB = (media * 15000) - 0.6;//media*1;

        //O que esta em movimento permanece em movimento :D
        body[i].posiX += body[i].velocidadeX * multWarp;
        body[i].posiY += body[i].velocidadeY * multWarp;

        //Cada corpo com sua luz :)
        luz[i].posiX = body[i].posiX;
        luz[i].posiY = body[i].posiY;
    }
}

void antigoCadaGravidade(Body* body) {
    double px = 0, py = 0, objx = 0, objy = 0, m1 = 0, m2 = 0;
    //Seleção dos corpos
    for (int i = 0; i <= numBody - 1; i++) {
        px = body[i].posiX;
        py = body[i].posiY;
        m1 = body[i].massa;
        for (int j = 0; j <= numBody - 1; j++) {
            //Não podemos calcular a gravidade do mesmo corpo
            if (i != j) {
                objx = body[j].posiX;
                objy = body[j].posiY;
                m2 = body[j].massa;


                //Teorema de Pitagoras para calcular a distância
                float diferencaX = objx - px;
                float diferencaY = objy - py;

                float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
                distancia = sqrt(distancia);

                //OTIMIZAÇÃO temporaria e errada, pois corpos gigantes tem alcance maior de gravidade
                if (distancia < 1.5) {

                    //Newton's Law of Universal Gravitation
                    float F = (G * m1 * m2) / pow(distancia, 2);


                    //PERFEITO!
                    float anguloRadians = atan2(diferencaY, diferencaX);
                    float anguloDegrees = (180 / PI) * anguloRadians;

                    float compassRadians = PI * 2 + anguloRadians;
                    float compassDegrees = (180 / PI) * compassRadians;

                    //float angulo = (((int)compassDegrees % 360) + 360) % 360;
                    //

                    float divForX = cos(compassDegrees * PI / 180);
                    float divFory = sin(compassDegrees * PI / 180);

                    //Se não colocarmos essa verificação, ocorrera um pequeno bug e os circulos
                    //vão pegar uma aceleração gigante
                    if (distancia > 0.02) {
                        body[i].velocidadeX += ((divForX * (F)) / pow(m1, 2) * 2); //Força dividida de acordo com o coseno
                        body[i].velocidadeY += ((divFory * (F)) / pow(m1, 2) * 2); //Força dividida de acordo com o seno
                    }



                    //CORES (de acordo com a sua velocidade)
                    double vxc = body[i].velocidadeX;
                    double vyc = body[i].velocidadeY;

                    if (vxc < 0)
                        vxc = vxc * -1;
                    if (vyc < 0)
                        vyc = vyc * -1;

                    double media = (vxc + vyc) / 2;

                    body[i].corR = media * 10000;
                    body[i].corG = (media * 10000) - 0.4;//media*1;
                    body[i].corB = media * 1;
                    //std::cout << body[0].velocidadeX << " x\n";
                    //std::cout << vyc << " Fs\n";

                }
                //O que esta em movimento permanece em movimento :D
                body[i].posiX += body[i].velocidadeX;
                body[i].posiY += body[i].velocidadeY;
            }
        }
    }
}

void circulo2(float cPosiX, float cPosiY, float cTamanho, double r, double g, double b) {

    //Circulo de 36 vertices!
    //glColor3f(0, 0, 0.5);
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 36; i++) {
        glVertex2d(cPosiX + verCirX2[i]*cTamanho, cPosiY + verCirY2[i]*cTamanho);
    }
    glEnd();
}

void circulo(float cPosiX, float cPosiY, float cTamanho, double r, double g, double b) {

    //Circulo! 360 vertices kkkkkkkkkkkk E BUGADO!! KKKKKKKKKKK
    //glColor3f(0, 0, 0.5);
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        glVertex2d(cPosiX + verCirX[i] * cTamanho, cPosiY + verCirY[i] * cTamanho);
    }
    glEnd();
}



//Os ticks atualizam 60 vezes por segundo em sincronia com o tempo real, separado do render
void tick() {

    
    //Controles do teclado
    move();
    independentMove(); //É ativado, Independente de quanto lag tem <- Não exatamente, agora que ele esta no tick
    if (!pausar) {
        cadaGravidade(body);
        //antigoCadaGravidade(body);
    }
    //dCol.Colisao(body);

    //Pegar circulos com o mouse
    if (Controles_Do_Mouse) {
        mouse();
        Mo.mousePegar(body, window, LMB);
    }
}

//O render renderiza (desenha) tudo o maximo de vezes possível
void render() {
    luz[9].corR = 1;
    luz[9].corG = 1;
    luz[9].corB = 1;


    if (Luzes_E_Sombras) {
        shader.SG1080(luz, parede); //A função que faz a magica :)
    }
    else if (Luzes) {
        shader.LuzSomente360(luz);
    }
    

    //Renderizar circulos
    for (int i = 0; i + 1 <= numBody; i++) {
        circulo2(body[i].posiX, body[i].posiY, body[i].tamanho, body[i].corR, body[i].corG, body[i].corB);
    }


    
}



//Gamming loop! - O coração do codigo
double begin = clock();
double lag = -1000; //-1000 para dar um tempo para o programa realmente iniciar
//O gameLoop corrige a atualização da fisica com a atualização de renderização (fps)
//assim a taxa de atualização da fisica (tick) será sempre constante,
//enquanto o fps vai ser chamado o máximo de vezes possível
void gameLoop() {

    double MS_PER_UPDATE = 16.67/timeWarp;
    double now = clock();
    double elapsed = now - begin;
    begin = now;
    lag += elapsed;

    
    //Isso evita que o codigo fica em um looping infinito de lag
    if (lag > 1500) {
        //stop = true;
        std::cout << "Alerta de lag muito alto: ";
        std::cout << lag << "\n";
        std::cout << "ZERANDO LAG - Pulando esse tick\n";
        lag = 32;
    }

    while (lag >= MS_PER_UPDATE) {
        tick();
        lag -= MS_PER_UPDATE;
    }
    render();
}
//

bool alerta = true;
int main(int argc, char* argv[])
{
    //O primeiro e o segundo valor muda a posição de RENDERIZAÇÃO.... Acho
    //glViewport(0, 0, 1280, 720); //Distância da camera? //E atrabalha o GLUT que escreve na tela //E a renderização não alcança toda a tela se aumentar // PODE MUDAR A PERSPECTIVA

    //glutInit(&argc, argv);
    //GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;



    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(w, h, "Gravidade! :D", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //Corrige a distorção da tela em relação ao que esta na tela
    //Assim um quadrado permanece quadrado, e não fica retangulo
    //por causa que a camera é retangulo :)
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0 * w / h, 1.0 * w / h, -1.0, 1.0); //Mais especificamente isso que corrige a distorção
    //

    glPushMatrix(); //"Pega" matriz atual da tela, usado para reiniciar caso necessário

    /* Loop until the user closes the window */
    //std::cout << "-- Simulador de Gravidade --\n COMANDOS:\n P = Aumenta a velocidade de atualizacao da fisica\n O = Diminui a velocidade de atualizacao da fisica\n WASD = Movimento da camera\n Y = Zera a velocidade de todos os corpos\n R = Reiniciar\n ESC = Parar\n----------\nAbra o arquivo Configuracao.h para modificar configuracoes interessantes\n\n";
    std::cout << "-- Simulador de Gravidade --\n COMANDOS:\n P = Pausar e continuar \n O = Aumenta a velocidade de atualizacao da fisica\n I = Diminui a velocidade de atualizacao da fisica\n U = Parecido com o comando O, mas instavel em altos valores\n Y = Parecido com o comando I\n WASD = Movimento da camera\n T = Zera a velocidade de todos os corpos\n R = Reiniciar\n Z e X = Zoom (Em desenvolvimendo)\n ESC = Parar\n----------\nAbra o arquivo Configuracao.h para modificar configuracoes interessantes\n\n";

    iniciar();
    while (!glfwWindowShouldClose(window))
    {
        //independentMove(); //É ativado, Independente de quanto lag tem
        //Emergencia
        if (GetAsyncKeyState(VK_ESCAPE)) {
            stop = true;
        }

        
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        

        //ANTIGO FUNDO:
        glClearColor(0.2, 0.2, 0.2, 1.0);

        //glClearColor(0.01, 0.01, 0.01, 1.0);
        
        if (!stop)
            gameLoop();
        else if (alerta) {
            std::cout << "\n-Pausa de emergencia-\n";
            alerta = false;
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        

        /* Poll for and process events */
        glfwPollEvents();

    }

    
    glfwTerminate();

    
    return 0;
}
