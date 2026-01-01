# Custom Stack Based Maze Solver

![Language](https://img.shields.io/badge/language-C++-00599C?style=flat-square)
![Architecture](https://img.shields.io/badge/structure-MVC%20Inspired-orange?style=flat-square)
![Algorithm](https://img.shields.io/badge/algorithm-DFS%20%2F%20Backtracking-green?style=flat-square)

Bu proje, C++ programlama dili kullanılarak geliştirilmiş, **özel veri yapıları (custom data structures)** içeren bir labirent çözme simülasyonudur. Standart kütüphaneler yerine, dinamik bellek yönetimi ile oluşturulmuş **Generic Stack** yapısını kullanarak **Backtracking (Geri İzleme)** algoritmasını uygular.

## Proje Mimarisi

Proje, temiz kod prensiplerine uygun olarak modüler bir yapıda geliştirilmiştir:

* `src/`      -> Algoritma ve mantık kodları (`Labirent.cpp`, `Konum.cpp`, `main.cpp`).
* `include/`  -> Header dosyaları ve Template yapıları (`Stack.hpp`, `Labirent.hpp`).
* `makefile`  -> Derleme ve bağlama (linking) işlemlerini otomatize eden yapılandırma dosyası.
* `Harita.txt` -> Labirentin ASCII tabanlı harita verisi.

## Teknik Yetkinlikler ve Algoritma

Bu projede, bilgisayar mühendisliği temel taşları olan şu konseptler uygulanmıştır:

### 1. Custom Stack Implementation (Özel Yığın Yapısı)
Standart `std::stack` yerine, **Linked List (Bağlı Liste)** mantığıyla çalışan kendi Stack sınıfım geliştirilmiştir.
* **Generic Programming:** `template <typename T>` yapısı kullanılarak Stack sınıfı her türlü veri tipiyle çalışabilir hale getirilmiştir.
* **Memory Management:** `Node` yapıları dinamik olarak (`new`) oluşturulur ve yıkıcı metod (`destructor`) ile bellek sızıntıları (`memory leak`) engellenir.

### 2. Depth-First Search (DFS) & Backtracking
Labirent çözümü için **Derinlik Öncelikli Arama** algoritması kullanılmıştır:
* Algoritma, çıkmaz sokağa (dead-end) girene kadar ilerler.
* İlerleyemediği noktada Stack yapısını kullanarak bir önceki adıma geri döner (`pop` işlemi) ve alternatif yolları dener.

## Kurulum ve Çalıştırma

Proje, `Makefile` sistemi ile kolayca derlenebilir. Terminal üzerinden proje dizinine gelerek:

### 1. Derleme ve Çalıştırma
```bash
make
