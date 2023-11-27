/*
* @file          main.cpp
* @description   Menü oluşturarak gerekli fonksiyonların çağırıldığı main() fonksiyonunun bulunduğu dosya
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#include "Sayi.hpp"
#include "SayilarListesi.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    SayilarListesi sayilarListesi;                                                  // SayilarListesi sınıfından bir nesne oluştur
    sayilarListesi.dosyadanSayilariOkuVeEkle("Sayilar.txt", sayilarListesi);        // "Sayilar.txt" dosyasından sayıları oku ve listeye ekle
    sayilarListesi.sayiBilgileriniYazdir();                                         // Liste içindeki sayıların bilgilerini ekrana yazdır

    int secim;
    do {
        cout << "1. Tek Basamaklari Basa Alma" << endl;
        cout << "2. Basamaklari Ters Cevirme" << endl;
        cout << "3. En Buyuk Sayiyi Cikarma" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminizi yapin: ";
        cin >> secim;
        cout << endl << endl;
        if (secim == 1) {
            // Tek basamakları başa alma
            cout << "Tek basamaklari basa alma islemi yapiliyor..." << endl;
            Dugum* guncelDugum = sayilarListesi.ilkDugum;
            while (guncelDugum != NULL) {
                sayilarListesi.tekBasamaklariBasaAl(guncelDugum->sayiAdres);
                guncelDugum = guncelDugum->siradakiDugum;
            }
            sayilarListesi.sayiBilgileriniYazdir();
        }
        else if (secim == 2) {
            // Basamakları ters çevirme
            cout << "Basamaklari ters cevirme işlemi yapiliyor..." << endl;
            Dugum* guncelDugum = sayilarListesi.ilkDugum;
            while (guncelDugum != NULL) {
                sayilarListesi.basamaklariTersCevir(guncelDugum->sayiAdres);
                guncelDugum = guncelDugum->siradakiDugum;
            }
            sayilarListesi.sayiBilgileriniYazdir();
        }
        else if (secim == 3) {
            // En büyük sayıyı çıkarma
            cout << "En buyuk sayiyi cikarma islemi yapiliyor..." << endl;
            sayilarListesi.enBuyuguCikar();
            sayilarListesi.sayiBilgileriniYazdir();
        }
        else if (secim == 4) {
            // Çıkış
            cout << "Programdan cikiliyor..." << endl;
        }
        else {
            cout << "Gecersiz secim. Tekrar deneyin." << endl;
        }
    } while (secim != 4);

    sayilarListesi.~SayilarListesi();                           // SayilarListesi sınıfının yıkıcı fonksiyonunu çağırarak bellekten ayrılan kaynakları temizle

    return 0;
}