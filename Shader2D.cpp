#include <iostream>
#include <GLFW/glfw3.h>
#include "Estruturas.h"



class Shader {
public:
    //Dados d;
    /*
    struct FormaGeo {
        float* verticesX;
        float* verticesY;
    };
    */
    struct vetores {
        double vetor1;
        double vetor2;
    };

    direcaoXY dirXY;
    direcaoXY aDirXY;
    vetores vet;

    //Vertices do circulo
    float verCirX[360];
    float verCirY[360];

    float vCirX1080[1080];
    float vCirY1080[1080];

    void iniciar() {
        for (int v = 0; v < 360; v++) {
            verCirX[v] = (cos(v * PI / 180));
            verCirY[v] = (sin(v * PI / 180));
        }

        for (double v = 0; v < 1080; v++) {
            vCirX1080[(int)v] = (cos((v / 3) * PI / 180));
            vCirY1080[(int)v] = (sin((v / 3) * PI / 180));
        }
    }
    Shader() {
        //iniciar();
        for (int v = 0; v < 360; v++) {
            verCirX[v] = (cos(v * PI / 180));
            verCirY[v] = (sin(v * PI / 180));
        }

        for (double v = 0; v < 1080; v++) {
            vCirX1080[(int)v] = (cos((v / 3) * PI / 180));
            vCirY1080[(int)v] = (sin((v / 3) * PI / 180));
        }
    }

    //FUNCIONA!
    //Agora precisamos selecionar os vetores corretos!
    auto Direcao(double x1, double y1, double x2, double y2) {
        //Teorema de Pitagoras para calcular a distância
        float diferencaX = x1 - x2;
        float diferencaY = y1 - y2;

        float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
        distancia = sqrt(distancia);

        //PERFEITO!
        float anguloRadians = atan2(diferencaY, diferencaX);
        float anguloDegrees = (180 / PI) * anguloRadians;

        float compassRadians = PI * 2 + anguloRadians;
        float compassDegrees = (180 / PI) * compassRadians;

        //float angulo = (((int)compassDegrees % 360) + 360) % 360;
        //

        //Essa força dividida é a direção distribuita entre o x e o y (Do x1 e y1 para o x2 e y2)
        float divForX = cos(compassDegrees * PI / 180); //Força dividida de acordo com o coseno
        float divForY = sin(compassDegrees * PI / 180); //Força dividida de acordo com o seno


        dirXY.dX = ((divForX * -1) * 2);
        dirXY.dY = ((divForY * -1) * 2);

        //vão pegar uma aceleração gigante
        if (distancia > 0.02) {
        }
        return dirXY;

        /*
        2
        //Teorema de Pitagoras para calcular a distância
        float diferencaX = x1 - x2;
        float diferencaY = y1 - y2;

        float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
        distancia = sqrt(distancia);
        if (distancia < 0.5) {
        //PERFEITO!
        float anguloRadians = atan2(diferencaY, diferencaX);
        float anguloDegrees = (180 / PI) * anguloRadians;

        float compassRadians = PI * 2 + anguloRadians;
        float compassDegrees = (180 / PI) * compassRadians;

        //float angulo = (((int)compassDegrees % 360) + 360) % 360;
        //

        //Essa força dividida é a direção distribuita entre o x e o y (Do x1 e y1 para o x2 e y2)
        float divForX = cos(anguloRadians); //Força dividida de acordo com o coseno
        float divForY = sin(anguloRadians); //Força dividida de acordo com o seno


        dirXY.dX = ((divForX * 1) * 2);
        dirXY.dY = ((divForY * 1) * 2);

        dirXY.dX = 0;
        //vão pegar uma aceleração gigante

            return dirXY;
        }
        else {
            return dirXY;
        }
        */
    }
    //Teorema de Pitagoras para calcular a distância //Não usadas
    /*
    float teoremaPitagoras(double x1, double y1, double x2, double y2) {
        float diferencaX = x2 - x1;
        float diferencaY = y2 - y1;

        float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
        distancia = sqrt(distancia);
    }
    */

    //Ideia antiga e ruim de calcular o shader geometrico, calculando o angulos da sombra. Uma gambiarra :)
    void shaderGeometrico(float verticesX[], float verticesY[], Luz* luz) {
        //void shaderGeometrico(float verticesX[], float verticesY[], float luzX[], float luzY[]) {

            //float* luzesX, float* luzesY
            //PONTOS MAIS DISTANTES QUE A LUZ TEM CONTATO?

            //GAMBIARRA?!?!?!?!?!?!?!?
            //Talvez usando gambiarras, não precisaremos de muita matematica, otimizando o codigo!

            //glColor3f(0.2, 0.2, 0.2);
            //double x1 = luz.posiX[0];
            //Direcao(, y1, x2, y2);



            //std::cout << "\n\n\n";


            ///1
        glBegin(GL_POLYGON);
        glColor3f(0.2, 0.2, 0.2);
        aDirXY = Direcao(luz[0].posiX, luz[0].posiY, verticesX[0], verticesY[0]);
        glVertex2d(aDirXY.dX, aDirXY.dY);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2d(verticesX[0], verticesY[0]); //Canto inferior esquerdo
        //glColor3f(0.0f, 1.0f, 0.0f);
        //glVertex2d(verticesX[1], verticesY[1]); //Canto inferior direito

        //glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2d(verticesX[2], verticesY[2]); //Canto superior direito
        //glColor3f(1.0f, 1.0f, 1.0f);
        //glVertex2d(verticesX[3], verticesY[3]); //Canto superior esquerdo
        aDirXY = Direcao(luz[0].posiX, luz[0].posiY, verticesX[2], verticesY[2]);
        glVertex2d(aDirXY.dX, aDirXY.dY);
        glEnd();



        ///2
        glBegin(GL_POLYGON);
        glColor3f(0.2, 0.2, 0.2);
        aDirXY = Direcao(luz[0].posiX, luz[0].posiY, verticesX[1], verticesY[1]);
        glVertex2d(aDirXY.dX, aDirXY.dY);

        glColor3f(0.0f, 0.0f, 0.0f);
        //glVertex2d(verticesX[0], verticesY[0]); //Canto inferior esquerdo
        //glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2d(verticesX[1], verticesY[1]); //Canto inferior direito

        //glColor3f(0.0f, 0.0f, 1.0f);
        //glVertex2d(verticesX[2], verticesY[2]); //Canto superior direito
        //glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(verticesX[3], verticesY[3]); //Canto superior esquerdo
        aDirXY = Direcao(luz[0].posiX, luz[0].posiY, verticesX[3], verticesY[3]);
        glVertex2d(aDirXY.dX, aDirXY.dY);
        glEnd();
        /// 


        glBegin(GL_POLYGON);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2d(verticesX[0], verticesY[0]); //Canto inferior esquerdo
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2d(verticesX[1], verticesY[1]); //Canto inferior direito
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2d(verticesX[2], verticesY[2]); //Canto superior direito
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(verticesX[3], verticesY[3]); //Canto superior esquerdo

        glEnd();

        /*
        float auxVertX[1];
        for (float vertX : auxVertX) {

            //std::cout << "a";
        }
        */


        //std::cout << d.getNum() <<"\n";
    }



    double verticesTrngX[360];
    double verticesTrngY[360];

    double VTX1080[1080];
    double VTY1080[1080];

    //Faz um efeito de sombra usando a tecnica dos triangulos, a partir de um centro e o tamanho da luz.
    //Fazendo um circulo completo a partir de 360 raios de luz armazenados na variavel global
    //verticesTrngX[] e verticesTrngY[] (360 valores)
    void desenharTriangulos(double cx, double cy, double tam, double r, double g, double b) {
        float te = 1;
        float forca = tam / 8;
        if (forca > 1) {
            forca = 1;
        }
        glBegin(GL_TRIANGLE_FAN);
        glColor4f(r * te, g * te, b * te, 1 * forca);
        glVertex2d(cx, cy); //Desenhando o começo do raio de luz
        //glColor3f(0.2, 0.2, 0.2);
        for (int i = 0; i < 360; i++) {
            float diferencaX = cx - verticesTrngX[i];
            float diferencaY = cy - verticesTrngY[i];
            float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
            distancia = sqrt(distancia);

            //A intensidade ira calcular a intensidade do final da luz. Se ela não bater em uma parede, ela vai ser 0
            //Mas se bem no meio do raio de luz tiver uma parede, ela vai ser 0.5
            //Se ela estiver muito perto da origem da luz, vai ser muito proxima de 1
            //Essa formula calcula de a cordo com o tamanho da luz e distancia em que entra em colisão
            //Dando um efeito bonito de degradê C:
            float intensidade = ((tam)-(distancia)) / tam; // Era só dividir tudo pelo tamanho ;-;

            //te = intensidade/(tam/2);
            //te = intensidade;
            glColor4f(r * te, g * te, b * te, intensidade * forca); //AlPhA :OOO efeito lindo ;u;
            glVertex2d(verticesTrngX[i], verticesTrngY[i]); //Desenhando o final do raio de luz
        }
        glVertex2d(verticesTrngX[0], verticesTrngY[0]); //Fim

        glEnd();
    }

    void desenharTriangulos1080(double cx, double cy, double tam, double r, double g, double b) {
        float te = 1;
        float forca = tam / 8;
        if (forca > 1) {
            forca = 1;
        }
        glBegin(GL_TRIANGLE_FAN);
        glColor4f(r * te, g * te, b * te, 1 * forca);
        glVertex2d(cx, cy); //Desenhando o começo do raio de luz
        //glColor3f(0.2, 0.2, 0.2);
        for (int i = 0; i < 1080; i++) {
            float diferencaX = cx - VTX1080[i];
            float diferencaY = cy - VTY1080[i];
            float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
            distancia = sqrt(distancia);

            //A intensidade ira calcular a intensidade do final da luz. Se ela não bater em uma parede, ela vai ser 0
            //Mas se bem no meio do raio de luz tiver uma parede, ela vai ser 0.5
            //Se ela estiver muito perto da origem da luz, vai ser muito proxima de 1
            //Essa formula calcula de a cordo com o tamanho da luz e distancia em que entra em colisão
            //Dando um efeito bonito de degradê C:
            float intensidade = ((tam)-(distancia)) / tam; // Era só dividir tudo pelo tamanho ;-;

            //te = intensidade/(tam/2);
            //te = intensidade;
            glColor4f(r * te, g * te, b * te, intensidade * forca); //AlPhA :OOO efeito lindo ;u;
            glVertex2d(VTX1080[i], VTY1080[i]); //Desenhando o final do raio de luz
        }
        glVertex2d(VTX1080[0], VTY1080[0]); //Fim

        glEnd();
    }


    //Dado a estrutura Luz e Parede, cria sombras usando formas geométricas.
    //A função usa formulas para calcular a intersecao das linhas da parede com as linhas do raio de luz.
    template <size_t P, size_t L>
    void shaderGeometrico2(Luz(&luz)[L], Parede(&parede)[P]) {
        // shader.intersecaoLinhas(luz[0].posiX, luz[0].posiY, //x1, y1
        // (verCirX[i] * 1.0) + luz[0].posiX, (verCirY[i] * 1.0) + luz[0].posiY, //x2, y2
        // parede[0].x3, parede[0].y3, //x3, y3
        // parede[0].x4, parede[0].y4, parede); //x4, y4
        float dx2;
        float dy2;
        for (int l = 0; l < L; l++) {
            glBegin(GL_LINES);
            for (int i = 0; i < 360; i++) {

                glColor4f(1, 1, 1, 1);
                float record = 3402823E+38;
                //Luz
                float x1 = luz[l].posiX; //Começo
                float y1 = luz[l].posiY; //Começo
                float x2 = (verCirX[i] * luz[l].tamanho) + luz[l].posiX; //Fim
                float y2 = (verCirY[i] * luz[l].tamanho) + luz[l].posiY; //Fim


                glVertex2d(x1, y1); //Desenhando o começo do raio de luz
                for (int j = 0; j < P; j++) {
                    float x3 = parede[j].x3;
                    float y3 = parede[j].y3;
                    float x4 = parede[j].x4;
                    float y4 = parede[j].y4;




                    float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

                    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
                    float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

                    if (t > 0 && t < 1 && u > 0 && u < 1) {
                        //Distancia até a intersecao
                        dx2 = x1 + t * (x2 - x1);
                        dy2 = y1 + t * (y2 - y1);

                        //Agora achar a parede mais proxima em que esse raio de luz entra em contato
                        //Teorema de Pitagoras para calcular a distância
                        //EDIT: Por algum motivo, eu não preciso calcular a parede mais proxima,
                        //o raio de luz ja para na primeira parede :/
                        // 
                        //float diferencaX = dx2 - x1;
                        //float diferencaY = dy2 - y1;
                        //float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
                        //distancia = sqrt(distancia);

                        //if (distancia < record) {
                        //    record = distancia;

                            //Se for o mais proximo até agora, aplicar novos valores
                        x2 = dx2;
                        y2 = dy2;
                        //}

                    }

                    //Desenhar linhas das paredes
                    glBegin(GL_LINES);

                    glColor3f(1.0f, 0.0f, 0.0f);
                    glVertex2d(x3, y3);
                    glColor3f(1.0f, 0.0f, 0.0f);
                    glVertex2d(x4, y4);

                    glEnd();
                }

                /*
                glBegin(GL_LINES);

                glColor3f(1.0f, 1.0f, 1.0f);
                glVertex2d(x1, y1);
                glVertex2d(x2, y2);

                glEnd();
                */

                //Aplicar novas coordenadas dos raios de luz que colidiram com a parede
                verticesTrngX[i] = x2;
                verticesTrngY[i] = y2;
            }

            desenharTriangulos(luz[l].posiX, luz[l].posiY, luz[l].tamanho, luz[l].corR, luz[l].corG, luz[l].corB);
        }


    }

    template <size_t P, size_t L>
    void SG1080(Luz(&luz)[L], Parede(&parede)[P]) {
        // shader.intersecaoLinhas(luz[0].posiX, luz[0].posiY, //x1, y1
        // (verCirX[i] * 1.0) + luz[0].posiX, (verCirY[i] * 1.0) + luz[0].posiY, //x2, y2
        // parede[0].x3, parede[0].y3, //x3, y3
        // parede[0].x4, parede[0].y4, parede); //x4, y4
        float dx2;
        float dy2;
        for (int l = 0; l < L; l++) {
            for (int i = 0; i < 1080; i++) {
                float record = 3402823E+38;
                //Luz
                float x1 = luz[l].posiX; //Começo
                float y1 = luz[l].posiY; //Começo
                float x2 = (vCirX1080[i] * luz[l].tamanho) + luz[l].posiX; //Fim
                float y2 = (vCirY1080[i] * luz[l].tamanho) + luz[l].posiY; //Fim
                //glBegin(GL_LINES);
                //glColor4f(1, 1, 1, 1);
                //glVertex2d(x1, y1); //Desenhando o começo do raio de luz

                for (int j = 0; j < P; j++) {
                    float x3 = parede[j].x3;
                    float y3 = parede[j].y3;
                    float x4 = parede[j].x4;
                    float y4 = parede[j].y4;


                    float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

                    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
                    float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

                    if (t > 0 && t < 1 && u > 0 && u < 1) {
                        //Distancia até a intersecao
                        dx2 = x1 + t * (x2 - x1);
                        dy2 = y1 + t * (y2 - y1);

                        //Agora achar a parede mais proxima em que esse raio de luz entra em contato
                        //Teorema de Pitagoras para calcular a distância
                        //EDIT: Por algum motivo, eu não preciso calcular a parede mais proxima,
                        //o raio de luz ja para na primeira parede :/
                        // 
                        //float diferencaX = dx2 - x1;
                        //float diferencaY = dy2 - y1;
                        //float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
                        //distancia = sqrt(distancia);

                        //if (distancia < record) {
                        //    record = distancia;

                            //Se for o mais proximo até agora, aplicar novos valores
                        x2 = dx2;
                        y2 = dy2;
                        //}

                    }


                    //Desenhar linhas das paredes
                    glBegin(GL_LINES);

                    glColor3f(1.0f, 0.0f, 0.0f);
                    glVertex2d(x3, y3);
                    glColor3f(1.0f, 0.0f, 0.0f);
                    glVertex2d(x4, y4);

                    glEnd();

                }

                //Aplicar novas coordenadas dos raios de luz que colidiram com a parede
                VTX1080[i] = x2;
                VTY1080[i] = y2;
                //glVertex2d(x2, y2); //Desenhando o começo do raio de luz
                //glEnd();
            }

            desenharTriangulos1080(luz[l].posiX, luz[l].posiY, luz[l].tamanho, luz[l].corR, luz[l].corG, luz[l].corB);
        }


    }

    //Desenha luzes sem as sombras, economizando performace
    template <size_t L>
    void LuzSomente360(Luz(&luz)[L]) {
        for (int l = 0; l < L; l++) {
            float r = luz[l].corR;
            float g = luz[l].corG;
            float b = luz[l].corB;
            float tam = luz[l].tamanho * 40000000; //40000000


            glBegin(GL_TRIANGLE_FAN);
            glColor4f(r, g, b, 1);
            glVertex2d(luz[l].posiX, luz[l].posiY); //Desenhando o começo do raio de luz
            //glColor3f(0.2, 0.2, 0.2);
            for (int i = 0; i < 360; i++) {

                glColor4f(r, g, b, 0);
                glVertex2d((verCirX[i] * tam) + luz[l].posiX, (verCirY[i] * tam) + luz[l].posiY); //Desenhando o final do raio de luz

            }
            glVertex2d((verCirX[0] * tam) + luz[l].posiX, (verCirY[0] * tam) + luz[l].posiY); //Fim

            glEnd();
        }
    }



    //UAHSUAHSUAHUSAHAS :D É TÃO LINDO QUANDO FUNCIONA EXATAMENTE COMO VOCÊ ESPERAVA
    template <size_t N, size_t L>
    void teste(Luz(&luz)[L], Parede(&parede)[N]) {
        size_t numLUZES = L;
        //std::cout << numLUZES << " luzes\n\n";
        //std::cout << parede[0].x3 << " paredes\n\n"; // :o
    }





};