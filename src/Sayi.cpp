/*
* @file          Sayi.cpp
* @description   Sayi sınıfına ait olan fonksiyonların yazılı olduğu dosya
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#include <Sayi.hpp>

// Sayi sınıfının yapıcı fonksiyonu
// İlk basamağı başlangıçta NULL olarak ayarlar.
Sayi::Sayi() {
    ilkBasamak = NULL;
}
Sayi::~Sayi() {
    // Sayi sınıfının yıkıcı (destructor) fonksiyonu
    // Bellekten ayrılan alanları temizler.
    Basamak* gec = ilkBasamak;
    while(gec !=0){
        Basamak* sil = gec;
        gec=gec->siradaki;
        delete sil;
    }
}

// Sayi nesnesini tam sayı değerine dönüştürüp string olarak döndüren fonksiyon
string Sayi::sayiButun() {
    Basamak* basamakDeger = ilkBasamak;
    string sayiTum = "";

    while (basamakDeger != NULL) {
        sayiTum += to_string(basamakDeger->data);
        basamakDeger = basamakDeger->siradaki;
    }

    return sayiTum;
}

// Sayi nesnesini tam sayı değerine dönüştürüp ekrana yazdıran fonksiyon
void Sayi::sayiButun2() {
    Basamak* basamakDeger = ilkBasamak;
    string sayiTum = "";

    while (basamakDeger != NULL) {
        sayiTum += to_string(basamakDeger->data);
        basamakDeger = basamakDeger->siradaki;
    }

    int sayi = stoi(sayiTum);

    cout << sayi;
}

// Sayi nesnesindeki toplam basamak sayısını hesaplayan fonksiyon
int Sayi::ToplamBasamakSayisi() {
    int count = 0;
    Basamak* basamakDeger = ilkBasamak;
    while (basamakDeger != NULL) {
        count++;
        basamakDeger = basamakDeger->siradaki;
    }
    return count;
}