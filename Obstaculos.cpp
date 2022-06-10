#include <iostream>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
//#include "Mechanics.cpp"


class Obstaculos {
public:
    double pipeSizeX = 0.1;
    double pipeSizeY = 0.8;

	double xPipe1 = 0.0;
    double yPipe1 = -1.0;

    int contar = 0;
    double pipeId[5];

	void pipes(double x) {
        //Pipes sera atualizado de acordo com os ticks
        //pipesLogic();
        

	}
    void dPipesUp() {
        //Desenhar Pipes Update é uma função que será atualizada de acordo com os frames (para desenhar)
        dPipes(0.1, 0.8, 0, -1);
    }
    void ids() {
        //Atualizado a cada segundo
        /*
        if (contar >= 5) {
            for (int i = 0; i <= 5; i++) {
                pipeId[i] = ((double)rand() / (double)RAND_MAX / (1 - 0));
                
            }
            contar = 0;
        }
        contar++;
        std::cout << contar << "\n";
        */
    }

	void dPipes(double pipeSizeX, double pipeSizeY, double xPipe1,  double yPipe1) {
        

        //glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 0.3f);
        glVertex2d(-pipeSizeX + xPipe1, -pipeSizeY + yPipe1);
        glVertex2d(pipeSizeX + xPipe1, -pipeSizeY + yPipe1);
        glVertex2d(pipeSizeX + xPipe1, pipeSizeY + yPipe1);
        glVertex2d(-pipeSizeX + xPipe1, pipeSizeY + yPipe1);
        //glRotatef(-180.0f, 0.0f, 0.0f, 1.0f);
        


        glEnd();
        glFlush();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 0.3f);
        glVertex2d(-pipeSizeX + xPipe1, -pipeSizeY + yPipe1 + 2.0);
        glVertex2d(pipeSizeX + xPipe1, -pipeSizeY + yPipe1 + 2.0);
        glVertex2d(pipeSizeX + xPipe1, pipeSizeY + yPipe1 + 2.0);
        glVertex2d(-pipeSizeX + xPipe1, pipeSizeY + yPipe1 + 2.0);

        glEnd();
        glFlush();

        
	}

    void pipesLogic() {
        /*
        contar += 1;
        if (contar >= 360) {
            //dPipes();
        }
        */
        //std::cout << (double)rand() / (double) RAND_MAX / (1 - 0) << "\n"; // Numero aleatorio entre 0 e 1
        
        for (int i = 1; i <= 20; i++) {
            //dPipes(0.1, 0.8, (i/10)* ((i / 10)+5),- 1);
            //std::cout << (i / 10) * ((i / 10)+5) << "\n";

            dPipes(0.1, 0.8, (i / 10) * ((i / 10) + 5), -1);
            //std::cout << (i / 10) * ((i / 10) + 5) << "\n";
            
        }
        //std::cout << "teste 2";
        
    }


};