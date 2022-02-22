#include <stdio.h>
#include "CL.h"


struct Tarih {
    int gun;
    int ay;
    int yil;
};

struct Tarih d1;
struct Tarih d2;

void fonksiyon( struct Tarih d1, struct Tarih d2)
{
    int x=0, m=0, n=0;
    int secme, degisken;
    int secilenler[20] = {33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33};
    char Array[16][20] = {"Borussia Dortmund", "FC Barcelona", "Paris Saint-Germain", "Porto FC", "Bayern Munich", "Manchester City", "Real Madrid", "Juventus FC", "Atletico Madrid", "Tottenham Hotspur", "Liverpool FC", "Schalke O4", "AFC Ajax", "Olympique Lyon", "AS Roma", "Manchester United"};
    
    int dizi[16] = {1,2,3,4,1,5,2,6,2,5,5,1,7,3,6,5};
    

    while (x<16){
        
        if (x%2 == 0){
            
        birinciler:
            
            printf("1'den 8'e kadar bir sayi seciniz:");
            scanf("%d", &secme);
            
            if (secme<1 || secme>8){
                
                printf("Lutfen gecerli deger araliginda bir sayi giriniz:\n");
                goto birinciler;
            }
            
            else if (secme-1 == secilenler[0] || secme-1 == secilenler[1] || secme-1 == secilenler[2] || secme -1 == secilenler[3] || secme-1 == secilenler[4] || secme-1 == secilenler[5] || secme-1 == secilenler[6] || secme-1 == secilenler[7] || secme-1 == secilenler[8] || secme-1 == secilenler[9] || secme-1 == secilenler[10] || secme-1 == secilenler[11] || secme-1 == secilenler[12] || secme-1 == secilenler[13]){
                
                printf("Sectiginiz takim daha once secildi.\n");
                goto birinciler;
            }
            
            else {
                printf("Secilen takim: %s\n \n", Array[secme-1]);
                
                secilenler[m]=secme-1;
                degisken=secme-1;
                m++;
                x++;
            }
        }
        
        if (x%2 != 0){
            
        ikinciler:
            
            printf("9'den 16'ya kadar bir sayi seciniz: ");
            scanf("%d", &secme);
            
            if (secme<9 || secme>16){
                
                printf("Lutfen gecerli deger araliginda bir sayi giriniz:\n");
                
                goto ikinciler;
            }
            
            else if (secme-1 == secilenler[0] || secme-1 == secilenler[1] || secme-1 == secilenler[2] || secme-1 == secilenler[3] || secme-1 == secilenler[4] || secme-1 == secilenler[5] || secme-1 == secilenler[6] || secme-1 == secilenler[7] || secme-1==secilenler[8] || secme-1 == secilenler[9] || secme-1 == secilenler[10] || secme-1 == secilenler[11] || secme-1 == secilenler[12] || secme-1 == secilenler[13] || secme-1 == secilenler[14] || secme-1 == secilenler[15]){
                
                printf("Sectiginiz takim daha once secildi\n");
                goto ikinciler;
            }
            
            else if (dizi[degisken] == dizi[secme-1]){
                
                printf("Ayni ulkenin takimlari eslesemez.\n");
                goto ikinciler;
            }
            
            else {
                
                printf("Secilen takim: %s \n\n", Array[secme-1]);
                secilenler[m] = secme-1;
                
                printf("* Eslesen takimlar: %s - %s *\n", Array[degisken], Array[secme-1]);
                
                if (n%2 == 0){
                    
                    printf("Macin oynanacagi tarih : %d.%d.%d \n \n", d1.gun, d1.ay, d1.yil);
                }
                else {
                    printf("Macin oynanacagi tarih : %d.%d.%d \n \n", d2.gun, d2.ay, d2.yil);
                }
            }
            n++;
            m++;
            x++;
        }
    }
}
