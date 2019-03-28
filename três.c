#include "xpaint.h"

void brotinho(int x, int y, float ang, int size){
   
    if(size < 10){
        return;
    }
   
    int xf = x + size * xm_cos(ang);
    int yf = y - size * xm_sin(ang);
    xs_color((XColor){xm_rand(0,255),xm_rand(0,255), xm_rand(0,255)});
    xd_thick_line(x, y, xf, yf, 3);
    x_step("brotinho");
    brotinho(xf, yf, ang - 22, size - xm_rand(15, 20));
    brotinho(xf, yf, ang + 22, size - xm_rand(15, 20));

}

int main(){
    
	int width = 800, height = 800;
    x_open(width, height);
    x_clear(BLACK);
    float ang = 90;
    int x = width/2;
    int y = height - 5;
    float size = 145;
    brotinho(x, y, ang, size);
    x_save("brotinho");
    x_close();
   
    return 0;
    
}
