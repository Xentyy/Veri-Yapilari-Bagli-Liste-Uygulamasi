/*
* @file          Basamak.cpp
* @description   Basamak sınıfına ait olan fonksiyonların yazılı olduğu dosya
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#include <Basamak.hpp>

// Basamak sınıfının yapıcı fonksiyonu
// Parametre olarak bir 'veri' alır ve Basamak nesnesini oluşturur.
// 'data' üye değişkenine, verilen 'veri' değerini atar.
// 'siradaki' üye değişkeni başlangıçta NULL olarak ayarlanır.

Basamak::Basamak(int veri) {
    this->data = veri;
    this->siradaki = NULL;
}


