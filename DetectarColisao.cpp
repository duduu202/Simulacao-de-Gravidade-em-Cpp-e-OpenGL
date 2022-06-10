#include <iostream>
#include "Estruturas.h"



class DetectarColisao {
public:
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


    auto corrigirColisao(Body* body, int i, int j) {
        body[j].posiX = 0;
        body[i].posiX = 0;
    }

    template <size_t B>
    auto Colisao(Body(&body)[B]) {
        //std::cout << numBody;

        double px = 0, py = 0, objx = 0, objy = 0, m1 = 0, m2 = 0;
        double tamanho1, tamanho2;

        for (int i = 0; i < B; i++) {
            px = body[i].posiX;
            py = body[i].posiY;
            m1 = body[i].massa;
            tamanho1 = body[i].tamanho;
            for (int j = 1 + i; j < B; j++) {
                //double objx = 0, objy = 0, m2 = 0;

                objx = body[j].posiX;
                objy = body[j].posiY;
                m2 = body[j].massa;
                tamanho2 = body[j].tamanho;

                float diferencaX = objx - px;
                float diferencaY = objy - py;
                float distancia = (diferencaX * diferencaX) + (diferencaY * diferencaY);
                distancia = sqrt(distancia);

                //std::cout << distancia << "\n";

                if (distancia <= tamanho1 + tamanho2) {
                    /*
                    std::cout << distancia << "BATEU \n";
                    corrigirColisao(body, i, j);

                    float anguloRadians = atan2(diferencaY, diferencaX);

                    float divForX = cos(anguloRadians)-1;
                    float divFory = sin(anguloRadians)-1;

                    float Forca = body[i].velocidadeX + body[i].velocidadeY;

                    body[i].velocidadeX += ((divForX * Forca) / expt(m1, 2) * 2); //Força dividida de acordo com o coseno
                    body[i].velocidadeY += ((divFory * Forca) / expt(m1, 2) * 2); //Força dividida de acordo com o seno

                    //Mesma força para ambos dos corpos :)
                    body[j].velocidadeX += ((divForX * Forca) / expt(m2, 2) * 2) * -1; //Força dividida de acordo com o coseno
                    body[j].velocidadeY += ((divFory * Forca) / expt(m2, 2) * 2) * -1; //Força dividida de acordo com o seno
                    */
                    std::cout << "Bateu!\n";

                }
                else {
                    //std::cout << "Diboa ";
                }
                //?? Isso funciona!
                //body[j].posiX = 0;
                //body[i].posiX = 0;
            }
        }

        //return body;
    }
};