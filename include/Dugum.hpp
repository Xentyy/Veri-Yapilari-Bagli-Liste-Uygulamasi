/*
* @file          Dugum.hpp
* @description   Düğüm sınıfı oluşturulur, gerekli veriler tanımlanır ve fonksiyon imzaları yazılır
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp

#include "Sayi.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

// Dugum sınıfı, bir Sayi nesnesini içeren düğümü temsil eder
class Dugum {
public:
    Sayi* sayiAdres;            // Düğümün içinde bulunan Sayi nesnesinin adresini tutan işaretçi
    Dugum* siradakiDugum;       // Sonraki düğümün adresini tutan işaretçi
    
    Dugum(Sayi* sayi);
};
#endif