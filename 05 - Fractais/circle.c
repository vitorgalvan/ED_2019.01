#include "xpaint.h"

void bolinhas(int x, int y, int raio){
    int ang = 0;
	if(raio < 1){
        return;
    }
   	int i;
    for(i = 0; i < 6; i++){
        xd_circle(x, y, raio);
        int xf = x + raio * xm_cos(ang);
        int yf = y - raio * xm_sin(ang);
        xd_circle(xf, yf, raio/3);
        bolinhas(xf, yf, raio/3);
        ang += 60;
        x_step("bolinhas");
    }
}

int main(){
   
    int width = 800, height = 800;
    x_open(width, height);
    x_clear(BLACK);
    
    int x = width/2;
    int y = height/2;
    int size = 260;
    bolinhas(x, y, size);
    x_save("bolinhas");
    x_close();
    
	return 0;
}
