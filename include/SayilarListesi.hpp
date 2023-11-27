/*
* @file          SayilarListesi.hpp
* @description   SayilarListesi sınıfı oluşturulur, gerekli veriler tanımlanır ve fonksiyon imzaları yazılır
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp

#include "Dugum.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib> 
using namespace std;

// SayilarListesi sınıfı, bir dizi Sayi nesnesini içeren ve bu sayılar üzerinde çeşitli işlemler gerçekleştiren bir veri yapısını temsil eder
class SayilarListesi {
public:
    Dugum* ilkDugum;                // Listenin ilk düğümünü gösteren işaretçi
    
    SayilarListesi();
    ~SayilarListesi();
    void sayiEkle(Sayi* sayi);
    void tekBasamaklariBasaAl(Sayi* sayi);
    void basamaklariTersCevir(Sayi* sayi);
    void enBuyuguCikar();
    void dosyadanSayilariOkuVeEkle(const char* dosyaAdi, SayilarListesi& sayilarListesi);
    void sayiBilgileriniYazdir();
};

#endif