#include "Labirent.hpp"
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

char YonChr[] = {31, 17, 30, 16}; 

Labirent::Labirent(string dosyaAdi) {
    for(int i = 0; i < YUKSEKLIK; i++) {
        for(int j = 0; j < GENISLIK; j++) {
            harita[i][j] = ' '; 
        }
    }

    ifstream dosya(dosyaAdi.c_str());
    string satir;
    int s = 0;
    
    if(dosya.is_open()) {
        while(getline(dosya, satir) && s < YUKSEKLIK) {    
            for(int k = 0; k < satir.length() && k < GENISLIK; k++) { 
                if(satir[k] != '\r') {
                    harita[s][k] = satir[k];
                    if(satir[k] == 'b' || satir[k] == 'B') baslangic = Konum(s, k);
                    if(satir[k] == 'c' || satir[k] == 'C') bitis = Konum(s, k);
                }
            }
            s++;
        }
        dosya.close();
        cout << "Harita Okundu." << endl;
        cout << "Baslangic Noktasi: (" << baslangic.x << ", " << baslangic.y << ")" << endl;
        cout << "Bitis Noktasi:     (" << bitis.x << ", " << bitis.y << ")" << endl;
        
        if (bitis.x == 0 && bitis.y == 0) {
            cout << "HATA: Bitis noktasi (c) bulunamadi! Harita.txt'yi kontrol et." << endl;
            system("pause");
            exit(1);
        }
        system("pause");

    } else {
        cout << "HATA: Dosya acilamadi! Ismi kontrol et: " << dosyaAdi << endl;
        system("pause"); 
        exit(1);
    }
}

void Labirent::yazdir() {
    system("cls");
    for(int i = 0; i < YUKSEKLIK; i++) {
        for(int j = 0; j < GENISLIK; j++) {
            cout << harita[i][j];
        }
        cout << endl;
    }
}

void Labirent::coz() {
    yolStack.push(baslangic);
    harita[baslangic.x][baslangic.y] = '*';

    while(!yolStack.isEmpty()) {
        
        Konum mevcut = yolStack.peek();

        if(mevcut.x == bitis.x && mevcut.y == bitis.y) {
            harita[mevcut.x][mevcut.y] = '*'; 
            yazdir(); 
            cout << "CIKISA GELINDI" << endl;
            return;
        }
        
        bool hareketEtti = false;
        int x = mevcut.x;
        int y = mevcut.y;

        if(x+1 < YUKSEKLIK && harita[x+1][y] != '#' && harita[x+1][y] != '*' && harita[x+1][y] != '.') {
            harita[x][y] = '*'; 
            yolStack.push(Konum(x+1, y));
            harita[x+1][y] = YonChr[0];
            hareketEtti = true;
        }
        else if(y-1 >= 0 && harita[x][y-1] != '#' && harita[x][y-1] != '*' && harita[x][y-1] != '.') {
            harita[x][y] = '*';  
            yolStack.push(Konum(x, y-1));
            harita[x][y-1] = YonChr[1]; 
            hareketEtti = true;
        }
        else if(x-1 >= 0 && harita[x-1][y] != '#' && harita[x-1][y] != '*' && harita[x-1][y] != '.') {
            harita[x][y] = '*'; 
            yolStack.push(Konum(x-1, y));
            harita[x-1][y] = YonChr[2]; 
            hareketEtti = true;
        }
        else if(y+1 < GENISLIK && harita[x][y+1] != '#' && harita[x][y+1] != '*' && harita[x][y+1] != '.') {
            harita[x][y] = '*'; 
            yolStack.push(Konum(x, y+1));
            harita[x][y+1] = YonChr[3];
            hareketEtti = true;
        }

        if(!hareketEtti) {
            harita[mevcut.x][mevcut.y] = '.'; 
            yolStack.pop();
        }

        yazdir();
        Sleep(50);
    }
    
    cout << "Cikis bulunamadi!" << endl;
}