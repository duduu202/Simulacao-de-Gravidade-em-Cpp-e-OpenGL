#include <iostream>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

class formas {
public:
    void Quadrado(double dQx, double dQy, double quadrTam) {
        glColor3f(1.0f, 0.5f, 0.0f);
        //std::cout << x << " " << y << "x e y\n";


        //glTranslatef(x, y, 0.0f);


        glBegin(GL_POLYGON);
        /*
        glVertex2d(-quadrTam + (posi), -quadrTam + (posi));
        glVertex2d(quadrTam + (posi), -quadrTam + (posi));
        glVertex2d(quadrTam + (posi), quadrTam + (posi));
        glVertex2d(-quadrTam + (posi), quadrTam + (posi));
        */


        //dQy = seg.seguirPY(dQy, y);
        //dQx = seg.seguirPX(dQx, x);




        glVertex2d(-quadrTam + dQx, -quadrTam + dQy);
        glVertex2d(quadrTam + dQx, -quadrTam + dQy);
        glVertex2d(quadrTam + dQx, quadrTam + dQy);
        glVertex2d(-quadrTam + dQx, quadrTam + dQy);
        glEnd();


        //testeD = seg.distancia(x, y, dQx, dQy);

        //std:: cout << "Distância: " << testeD << "\n";
    }

};