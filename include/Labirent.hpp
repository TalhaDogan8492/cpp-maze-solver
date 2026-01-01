#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include "Stack.hpp"
#include "Konum.hpp"
#include <string>

#define YUKSEKLIK 20
#define GENISLIK 50

class Labirent {
private:
    char harita[YUKSEKLIK][GENISLIK];
    Konum baslangic;
    Konum bitis;
    Stack<Konum> yolStack;

public:
    Labirent(std::string dosyaAdi);
    void coz();
    void yazdir();
};

#endif