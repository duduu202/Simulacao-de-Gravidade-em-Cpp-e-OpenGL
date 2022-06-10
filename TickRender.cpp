#include <WinUser.h>
#include <iostream>
#include <gl/GL.h>

float teste = 0.2;
float x = 0.5;
float y = 0.5;
void move() {

    /*
    * O "conio.h" usando o "_getch()" é péssimo para jogos,
    * pois ele para o looping inteiro esperando um input.
    *
    * Como solução usamos o GetAsyncKeyState(), da biblioteca "Windows.h",
    * esse metodo não precisa parar o looping para pegar um input
    */


    if (GetAsyncKeyState((unsigned short)'W')) {
        y += 0.01;
        //teste = teste + 0.1;
        //std::cout << "W\n";
    }

    if (GetAsyncKeyState((unsigned short)'A')) {
        x -= 0.01;
        //teste = teste + 0.1;
        //std::cout << "A\n";
    }
    if (GetAsyncKeyState((unsigned short)'S')) {
        y -= 0.01;
        //teste = teste - 0.1;
        //std::cout << "S\n";
    }
    if (GetAsyncKeyState((unsigned short)'D')) {
        x += 0.01;
        //teste = teste - 0.1;
        //std::cout << "D\n";
    }

}

void dQuadrado(float quadrTam) {
    glColor3f(1.0f, 0.0f, 0.0f);
    //std::cout << x << " " << y << "x e y\n";


    //glTranslatef(x, y, 0.0f);


    glBegin(GL_POLYGON);

    glVertex2d(-quadrTam + x, -quadrTam + y);
    glVertex2d(quadrTam + x, -quadrTam + y);
    glVertex2d(quadrTam + x, quadrTam + y);
    glVertex2d(-quadrTam + x, quadrTam + y);

    glEnd();

}

void renderObjs() {


    dQuadrado(teste);


}
void camera() {


}
void bGroud() {
    glColor3f(1.0f, 1.0f, 1.0f);



    //glTranslatef(x, y, 0.0f);


    glBegin(GL_QUADS);

    glVertex2d(-1, -1);
    glVertex2d(1, -1);
    glVertex2d(1, 1);
    glVertex2d(-1, 1);
    glRotated(20, 1, 1, 1);

}
double t1, t2;
void text() {
    if (t1 >= 60) {
        t1 = 0;
        t2 += 1;
    }
    t1 += 1;

    std::cout << t2 << " * 60 = ticks \n";
}

void tick() {

    text();
    move();
}