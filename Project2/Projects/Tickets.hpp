#ifndef Tickets_hpp
#define Tickets_hpp


class Tickets {

public:
    
    Tickets();
    Tickets(char *C, double P, char *V);
    Tickets(const Tickets &other);
    Tickets& operator = (const Tickets &other);
    ~Tickets(void);
    
    void Print();
    char getCity(void);
    double getPrice(void);
    char getVehicle(void);
    void setPrice(double);
    
    double operator * (int sayi);
    double operator + (const Tickets &T1);
    
    void fonksiyon();
    
private:

    char* city;
    double price;
    char* vehicle;
    
};


#endif
