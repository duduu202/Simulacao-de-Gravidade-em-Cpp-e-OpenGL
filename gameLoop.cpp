#include <time.h>





//Gamming loop!
double begin = clock();
double lag = 0.0;
void gameLoop() {


    double MS_PER_UPDATE = 16.67;
    double now = clock();
    double elapsed = now - begin;
    begin = now;
    lag += elapsed;

    while (lag >= MS_PER_UPDATE) {
        //tick();
        lag -= MS_PER_UPDATE;
    }
    //render();
}