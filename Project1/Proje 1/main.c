#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct dugum{
    int sayi;
    char *ad;
    struct dugum *sonraki;
};

struct dugum *start = NULL;
struct dugum *q = NULL;
struct dugum *son = NULL;

int sayac = 0;


void listele() {
    struct dugum *t;
    
    t = start;
    
    if (t == NULL) {
        printf("Liste su anda bos.\n");
        return;
    }
    
    printf("Magazada %d adet araba bulundu.\n", sayac);
    
    while (t -> sonraki != NULL) {
        printf("Aracin ismi: %s , Fiyat: ", t -> ad);
        printf("%d\n", t -> sayi);
        t = t -> sonraki;
    }
    printf("Aracin ismi: %s , Fiyat: ", t -> ad);
    printf("%d\n", t -> sayi);
}

void ekle(int x, char a[]) {
    struct dugum *t, *temp;
    
    t = (struct dugum*)malloc(sizeof(struct dugum));
    sayac ++;
    
    if (start == NULL) {
        start = t;
        start -> ad = malloc(strlen(a)+1);
        start -> sayi = x;
        strcpy(start -> ad, a);
        start -> sonraki = NULL;
        return;
    }
    
    temp = start;
    
    while (temp -> sonraki != NULL)
        temp = temp -> sonraki;
    
    temp-> sonraki = t;
    t -> ad = malloc(strlen(a)+1);
    t -> sayi = x;
    strcpy(t -> ad, a);
    t -> sonraki = NULL;
}

void sondansil(){
    sayac --;
    q = start;
    while(q -> sonraki -> sonraki != NULL){
        q = q -> sonraki;
    }
    free(q -> sonraki);
    q -> sonraki = NULL;
}

void bastansil(){
    struct dugum *ikinci = NULL;
    ikinci = start -> sonraki;
    start = ikinci;
    sayac --;
    free(start);
    
    
}
void aradansil(char x[]){
    
    son=start;
    q=start;
    
    int m = strcmp(start -> ad, x);
    if(m == 0){
        bastansil();
        return ;
    }
    while(q -> sonraki -> sonraki != NULL){
        q = q -> sonraki;
    }
    son = q -> sonraki;
    int n = strcmp(son->ad, x);
    if(n == 0){
        sondansil();
    }
    else{
        sayac--;
        q = start;
        struct dugum *onceki = NULL;
        struct dugum *sonraki = NULL;
        
        while(strcmp(q -> sonraki -> ad,x)!= 0)
            q = q -> sonraki;
        
        if(q -> sonraki == NULL)
            sondansil();
        
        onceki = q;
        sonraki = q -> sonraki -> sonraki;
        free(q -> sonraki);
        onceki -> sonraki = sonraki;
    }
}



int main() {
    char tutma[10];
    int islem;
    int secim;
    int fiyat;
    
    while(1){
        printf("Araba eklemek icin 1,\n");
        printf("Araba almak icin 2,\n");
        printf("Arabalari görmek icin 3 e basiniz: ");
        scanf("%d", &secim);
        
        if(secim == 1){
            printf("Arabanizin fiyatini giriniz: ");
            scanf("%d", &fiyat);
            printf("Arabanizin adini giriniz: ");
            scanf(" %s", &tutma);
            ekle(fiyat,tutma);
            printf("Baska islem yapilsin mi? (Evet:1, Hayir:0) ");
            scanf("%d", &islem);
            if(islem == 0)
                break;
            else if(islem == 1)
                continue;
            
            
        }
        
        if(secim == 2){
            if(sayac == 0){
                printf("Su anda araba bulunmamaktadir.");
                break;
            }
            printf("Almak istediginiz arabanin ismini giriniz: ");
            scanf(" %s", &tutma);
            printf("%s arabasini satin aldiniz.\n", tutma);
            aradansil(tutma);
            
            printf("Baska islem yapilsin mi? (Evet:1, Hayir:0) ");
            scanf("%d", &islem);
            if(islem == 0)
                break;
            else if(islem == 1)
                continue;
            
            
        }
        
        if(secim == 3){
            
            listele();
            
            printf("Baska islem yapilsin mi? (Evet:1, Hayir:0) ");
            scanf("%d", &islem);
            if(islem == 0)
                break;
            else if(islem == 1)
                continue;
            
        }
        
        if(secim == 4){
            break;
        }
        
    }
    
    
    
    return 0;
}
