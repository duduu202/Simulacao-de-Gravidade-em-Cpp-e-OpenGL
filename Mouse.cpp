#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include "Estruturas.h"

static double mvx, mvy;
static double cameraX, cameraY;

//SetCursorPos(mid_x, mid_y); // :O

class Mouse {
public:

    POINT mousePos;
    double mx, my;

    //Variáveis para corrigir distorções
    double corr;
    double corr2;
    double zMult = 1;

    int w2, h2;



    //Coletando valores necessários para essa classe funcionar,
    //incluindo valores para corrigir distorções
    //FIZ ISSO QUANDO EU NÃO SABIA FAZER CONSTRUTORES
    void iniciar(double w, double h) {
        mx = 0;
        my = 0;
        cameraX = 0;
        cameraY = 0;
        zMult = 1;


        w2 = w / 2;
        h2 = h / 2;
        corr = w / h; //Correção da distorção ja janela com as coordenadas do mouse
        corr2 = h / w; //Correção das coordenadas da camera com a janela
    }

    Mouse(double w, double h) {
        this->mx = 0;
        this->my = 0;
        cameraX = 0;
        cameraY = 0;
        this->zMult = 1;


        this->w2 = w / 2;
        this->h2 = h / 2;
        this->corr = w / h; //Correção da distorção ja janela com as coordenadas do mouse
        this->corr2 = h / w; //Correção das coordenadas da camera com a janela
    }

    //Gambiarra?:
    //cameraX e cameraY feito para corrigir a posição para selecionar os objetos
    //mesmo com a camera em movimento ou em outra posição
    void setCameraX(double cx) {
        cameraX += cx * 5.622; //0.568371
    }
    void setCameraY(double cy) {
        cameraY += cy * 5.622 * corr;
    }
    void setCameraZoom(double z) {
        zMult *= (z* 1.0001); 
    }

    double getMouseX() {
        return mx;
    }
    double getMouseY() {
        return my;
    }

    bool segurando;
    int segurarID;
    //FUNCIONA! - Pega, segura e ainda atribui velocidade de acordo velocidade com do mouse! ;u; Mas é mal otimizado :(
    template <size_t B>
    void mousePegar(Body(&body)[B], GLFWwindow* window, bool LMB) {
        //std::cout << "mult:" << zMult << "\n";
        if (segurando) {
            glfwGetCursorPos(window, &mx, &my); //É SÓ ISSO '----'
            //Converter para coordenadas
            mx = (((mx / w2 - 1.0)) + cameraX) * corr * zMult;
            my = ((-(my / h2 - 1.0)) + cameraY) * zMult;
            //Calculando a velocidade a partir da diferença da antiga posição
            mvx -= mx;
            mvy -= my;
            if (!LMB) {
                //Se soltar o botão esquerdo do mouse, solte :)
                segurando = false;
            }
            body[segurarID].posiX = mx;
            body[segurarID].posiY = my;
            body[segurarID].velocidadeX = -mvx * 0.0005; //0.005
            body[segurarID].velocidadeY = -mvy * 0.0005;

            //Atribuindo nova posição
            mvy = my;
            mvx = mx;
        }
        else if (LMB) {
            glfwGetCursorPos(window, &mx, &my); //É SÓ ISSO '----'
            //Converter para coordenadas
            mx = (((mx / w2 - 1.0)) + cameraX) * corr * zMult;
            my = ((-(my / h2 - 1.0)) + cameraY) * zMult;
            //Calculando a velocidade a partir da diferença da antiga posição
            mvx -= mx;
            mvy -= my;
            double objx, objy, tamanho;


            for (int i = 0; i < B; i++) {

                objx = body[i].posiX;
                objy = body[i].posiY;
                tamanho = body[i].tamanho;

                float diferencaX = objx - mx;
                float diferencaY = objy - my;
                float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
                distancia = sqrt(distancia);


                if (distancia < tamanho) {


                    //std::cout << distancia <<"UEPAAA\n";
                    body[i].posiX = mx;
                    body[i].posiY = my;
                    body[i].velocidadeX = -mvx * 0.005;
                    body[i].velocidadeY = -mvy * 0.005;

                    segurando = true;
                    segurarID = i;
                }

            }


        }

        //std::cout << mvy <<"UEPAAA\n";
        //Atribuindo nova posição
        mvy = my;
        mvx = mx;
    }

    void mouse(int btn, int state, int x, int y) {
        float mx = x;
        float my = y;
        double ox = (mx / 500 - 1.0);
        double oy = -(my / 500 - 1.0);
        switch (btn) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                printf("%f\n", mx);
                printf("%f\n", my);
            }
            break;
        }

    };
};