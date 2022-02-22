#include "Tickets.hpp"
#include <iostream>


Tickets :: Tickets(){
    
    city = "no name";
    price = 0.0;
    vehicle = "unknown";
}

Tickets :: Tickets(char *C, double P, char *V){
    
    city = C;
    price = P;
    vehicle = V;
}

Tickets :: Tickets(const Tickets &other){
    
    city = other.city;
    price = other.price;
    vehicle = other.vehicle;
}

Tickets& Tickets :: operator = (const Tickets &other){

    city = other.city;
    price = other.price;
    vehicle = other.vehicle;

    return *this;
}

Tickets :: ~Tickets(void){
    
    std::cout << "Freeing memory!" << std::endl;
}

void Tickets :: setPrice(double P){
    
    price = P;
}

char Tickets :: getCity(void){
    return *city;
}

double Tickets :: getPrice(void){
    return price;
}

char Tickets :: getVehicle(void){
    return *vehicle;
}

double Tickets :: operator + (const Tickets &T1){
    
    return (price + T1.price);
}

double Tickets :: operator * (int sayi){
    
    return price * sayi;
}


void Tickets :: fonksiyon(){
    
    try {
    
int secme, biletsayisi;
int secim_arr[2];
int sayi_arr[2];
    
    Tickets *ptr;
    ptr = new Tickets[4];
    ptr[0].setPrice(300);
    ptr[1].setPrice(5000);
    ptr[2].setPrice(30);
    ptr[3].setPrice(4000);
    

for (int i=0; i<2; i++) {
    
    
    std::cout << "1 ile 4 arasinda bir deger giriniz ";
    std::cin >> secme;
    
    if (secme > 4 || secme < 1 || secme == NULL){
        
        throw "ERROR! Try Again. ";
    }
    
    secim_arr[i] = secme - 1;
    
    if (secme == 1) {
        
        std::cout << "Sectiginiz sehir Berlin. Berlin'e sadece tren ile gidilebilmektedir. ";
        
        std::cout << "Almak istediginiz bilet sayisini giriniz. ";
        std::cin >> biletsayisi;
        sayi_arr[i] = biletsayisi;
        
        std::cout << "Biletlerinizin toplam fiyati: " << (biletsayisi)*(ptr[0].getPrice()) << "₺. ";
        }
        
        else if (secme == 2) {
            
            std::cout << "Sectiginiz sehir Sydney. Sydney'e sadece ucak ile gidilebilmektedir. ";
            
            std::cout << "Almak istediginiz bilet sayisini giriniz. ";
            std::cin >> biletsayisi;
            sayi_arr[i] = biletsayisi;
            
            std::cout << "Biletlerinizin toplam fiyati: " << (biletsayisi)*(ptr[1].getPrice()) << "₺. ";
        }
        
        else if (secme == 3) {
            
            std::cout << "Sectiginiz sehir Gebze. Gebze'ye sadece otobus ile gidilebilmektedir. ";
            
            std::cout << "Almak istediginiz bilet sayisini giriniz. ";
            std::cin >> biletsayisi;
            sayi_arr[i] = biletsayisi;
            
            std::cout << "Biletlerinizin toplam fiyati: " << (biletsayisi)*(ptr[2].getPrice()) << "₺. ";
        }
        
        else {
            
            std::cout << "Sectiginiz sehir Rio. Rio'ya sadece gemi ile gidilebilmektedir. ";
            
            std::cout << "Almak istediginiz bilet sayisini giriniz. ";
            std::cin >> biletsayisi;
            sayi_arr[i] = biletsayisi;
            
            std::cout << "Biletlerinizin toplam fiyati: " << (biletsayisi)*(ptr[3].getPrice()) << "₺. ";
        }
        
        }
    
     std::cout << "Toplam bilet fiyatiniz: " << (ptr[secim_arr[0]] * sayi_arr[0]) + (ptr[secim_arr[1]] * sayi_arr[1]) << std::endl;
}

      catch(const char *ptr) {std::cout << ptr << std::endl;}
}
