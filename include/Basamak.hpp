/*
* @file          Basamak.hpp
* @description   Basamak sınıfı oluşturulur, gerekli veriler tanımlanır ve fonksiyon imzaları yazılır
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#ifndef Basamak_hpp
#define Basamak_hpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

// Basamak sınıfı, bir tam sayı basamağını temsil eden düğümü ifade eder
class Basamak {
public:
    int data;               // Basamağın içinde bulunan tam sayı değeri
    Basamak* siradaki;      // Sonraki basamağı gösteren işaretçi
    
    Basamak(int veri);
};

#endif