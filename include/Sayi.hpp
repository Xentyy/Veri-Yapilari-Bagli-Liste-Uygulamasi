/*
* @file          Sayi.hpp
* @description   Sayi sınıfı oluşturulur, gerekli veriler tanımlanır ve fonksiyon imzaları yazılır
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#ifndef Sayi_hpp
#define Sayi_hpp

#include "Basamak.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

// Sayi sınıfı, tam sayıları basamaklarına ayıran ve işleyen bir veri yapısını temsil eder
class Sayi {
public:
    Basamak* ilkBasamak;        // Sayının ilk basamağını gösteren işaretçi
    
    Sayi();
    ~Sayi();
    string sayiButun();
    void sayiButun2();
    int ToplamBasamakSayisi();
};

#endif