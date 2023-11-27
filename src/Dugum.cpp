/*
* @file          Dugum.cpp
* @description   Düğüm sınıfına ait olan fonksiyonların yazılı olduğu dosya
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#include <Dugum.hpp>

// Dugum sınıfının yapıcı fonksiyonu
// Parametre olarak bir Sayi nesnesi alır ve Dugum nesnesini oluşturur.
Dugum::Dugum(Sayi* sayi) {
    this->sayiAdres = sayi;
    siradakiDugum = NULL;
}
