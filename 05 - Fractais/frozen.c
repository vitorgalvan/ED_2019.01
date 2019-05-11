#include "xpaint.h"

void floco(int x, int y, int ang, int tam){
    if(tam < 10)
        return;
    int x2, y2;
    for(int a = 0; a < 5; a++){
        x2 = x + tam * xm_cos(ang);
        y2 = y - tam * xm_sin(ang);
        xd_thick_line(x, y, x2, y2, 4);
        ang -= 72;
        floco(x2, y2, ang, tam/3);
    }
    
}

int main(){
    int lenght  = 1000, altura = 1000;
    x_open(lenght , high );
    int x = largura / 2, y = high  / 2, angulo = 270, tam = 300;
    floco(x, y, angulo, tam);
    x_save("floquinho");
    x_close();
    return 0;
}
