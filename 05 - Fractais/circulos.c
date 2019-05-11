#include "xpaint.h"

void espiral(int x, int y, int tam, int angulo){
    if(tam < 5)
        return;
    int x2 = x + tam * xm_cos(angulo);
    int y2 = y - tam * xm_sin(angulo);
    xd_thick_line(x, y, x2, y2, 3);
    espiral(x2, y2, tam - 10, angulo - 90);
}

int main(){
    int lenght = 600, high = 600;
    x_open(lenght, high);
    int tam = 500, angulo = 0, x = 50, y = 50;
    espiral(x, y, tam, angulo);
    x_save("figura_base");
    x_close();
    return 0;
}
