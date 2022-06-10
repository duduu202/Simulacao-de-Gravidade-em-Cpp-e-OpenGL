#include <iostream>
#include <cstdlib>


class seguir {
public:
    double bvx;
    double bvy;
    double teste;

    double seguirPX(double px, double x) {
        if (px < x) {
            px += 0.0001;
        }
        if (px > x) {
            px -= 0.0001;
        }
        return px;

    }
    double seguirPY(double py, double y) {
        if (py < y) {
            py += 0.0001;
        }
        if (py > y) {
            py -= 0.0001;
        }
        return py;
    }

    /// //////////////////////
    double gravPX(double px, double pvx, double x) {
        if (px < x) {
            //px += 0.0001;
            pvx = pvx + 0.002;
        }
        if (px > x) {
            //px -= 0.0001;
            pvx = pvx - 0.002;
        }
        if (px == x) {
            pvx = -pvx;
        }
        bvx = pvx;
        /*
        if (std::abs(px - x) <= 1) {
            std::cout << std::abs(px - x) << "OPAAAAAAAAAAAAAAAAAAAAAAAAAAAA NO PVX\n";
            return -pvx * 0.4;
        }
        */

        //std::cout << pvx;
        return pvx;
        //std::cout << "AAAAAAAAAAAAAA";
        
    }

    /// //////////////////////////
    double gravPY(double py, double pvy, double y) {
        if (py < y) {
            //px += 0.0001;
            pvy = pvy + 0.002;
        }
        if (py > y) {
            //px -= 0.0001;
            pvy = pvy - 0.002;
        }
        bvy = pvy;
        /*
        if (std::abs(py - y) <= 1) {
            std::cout << std::abs(py - y) <<"OPAAAAAAAAAAAAAAAAAAAAAAAAAAAA NO PVY\n";
            return -pvy * 0.4;
        }
        */
        teste = bvx / pvy;
        return pvy;
        //std::cout << pvy;

        //std::cout << "AAAAAAAAAAAAAA";
        
    }
    double distancia(double x1, double y1, double x2, double y2){
        double diferencaX = x2 - x1;
        double diferencaY = y2 - y1;
        double resultado = (diferencaX * diferencaX) + (diferencaY * diferencaY);

 
        return sqrt(resultado);
    }

};

/*
double seguirPX(double px) {
    if (px < x) {
        px += 0.0001;
    }
    if (px > x) {
        px -= 0.0001;
    }
    return px;

}
double seguirPY(double py) {
    if (py < y) {
        py += 0.0001;
    }
    if (py > y) {
        py -= 0.0001;
    }
    return py;
}

*/