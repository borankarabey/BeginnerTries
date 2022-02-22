#include <stdio.h>
#include <stdlib.h>


struct Tarih
{
    int gun;
    int ay;
    int yil;
};

void fonksiyon(struct Tarih d1, struct Tarih d2);

int main(){
    
    struct Tarih d1;
    struct Tarih d2;
    
    d1.gun = 12;
    d1.ay = 02;
    d1.yil = 2019;
    
    d2.gun = 13;
    d2.ay = 02;
    d2.yil = 2019;
    
    fonksiyon(d1, d2);
    
    return 0;
}
