/*
* @file          SayilarListesi.cpp
* @description   SayilarListesi sınıfına ait olan fonksiyonların yazılı olduğu dosya
* @course        2. Öğretim C Grubu
* @assignment    1. Ödev
* @date          13.11.2023
* @author        Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/
#include <SayilarListesi.hpp>

SayilarListesi::SayilarListesi() {
    ilkDugum = NULL;
}
SayilarListesi::~SayilarListesi() {
    // SayilarListesi yokedici fonksiyonu
    // Yapılması gereken temizleme işlemleri burada yapılır
    Dugum* gec=ilkDugum;
    while(gec !=NULL){
        Dugum* sil = gec;
        gec=gec->siradakiDugum;
        delete sil;
    }
}

// Sayıyı listeye ekle
void SayilarListesi::sayiEkle(Sayi* sayi) {
    Dugum* yeniDugum = new Dugum(sayi);
    yeniDugum->siradakiDugum = ilkDugum;
    ilkDugum = yeniDugum;
}

// Tek basamakları başa alma fonksiyonu
void SayilarListesi::tekBasamaklariBasaAl(Sayi* sayi) {
    Basamak* guncelBasamak = sayi->ilkBasamak;
    Basamak* onceki = NULL;
    Basamak* tekSayilar = NULL;
    Basamak* digerSayilar = NULL;

    while (guncelBasamak != NULL) {
        Basamak* gec = guncelBasamak->siradaki;

        if (guncelBasamak->data % 2 != 0) {
            // Tek sayıları başa al
            guncelBasamak->siradaki = tekSayilar;
            tekSayilar = guncelBasamak;
        }
        else {
            // Diğer sayıları sona ekle
            guncelBasamak->siradaki = digerSayilar;
            digerSayilar = guncelBasamak;
        }

        guncelBasamak = gec;
    }

    // Tek sayıları diğer sayıların önüne ekle
    if (tekSayilar != NULL) {
        Basamak* sonTekSayi = tekSayilar;
        while (sonTekSayi->siradaki != NULL) {
            sonTekSayi = sonTekSayi->siradaki;
        }
        sonTekSayi->siradaki = digerSayilar;
        sayi->ilkBasamak = tekSayilar;
    }
    else {
        sayi->ilkBasamak = digerSayilar;
    }
}

// Basamakları ters çevirme fonksiyonu
void SayilarListesi::basamaklariTersCevir(Sayi* sayi) {
    Basamak* onceki = NULL;
    Basamak* simdiki = sayi->ilkBasamak;
    Basamak* sonraki = NULL;

    while (simdiki != NULL) {
        sonraki = simdiki->siradaki;
        simdiki->siradaki = onceki;
        onceki = simdiki;
        simdiki = sonraki;
    }

    sayi->ilkBasamak = onceki;
}

void SayilarListesi::enBuyuguCikar() {
    // Eğer liste boşsa, işlem yapılamaz.
    if (ilkDugum == NULL) {
        cout << "Liste bos. Silme islemi yapilamaz." << endl;
        return;
    }

    Dugum* enBuyukDugum = NULL;
    Dugum* gecici = ilkDugum;
    int enBuyukSayi = std::numeric_limits<int>::min();

    // Listede en büyük sayıyı bul
    while (gecici != NULL) {
        Sayi* sayi = gecici->sayiAdres;
        stringstream ss(sayi->sayiButun());
        int guncelSayi;
        ss >> guncelSayi;

        if (guncelSayi > enBuyukSayi) {
            enBuyukSayi = guncelSayi;
            enBuyukDugum = gecici;
        }
        gecici = gecici->siradakiDugum;
    }

    if (enBuyukDugum != NULL) {
        // En büyük sayının düğümünü bul
        Dugum* onceki = NULL;
        gecici = ilkDugum;
        while (gecici != enBuyukDugum) {
            onceki = gecici;
            gecici = gecici->siradakiDugum;
        }
         // En büyük sayıyı listenin içinden çıkar
        if (onceki != NULL) {
            onceki->siradakiDugum = enBuyukDugum->siradakiDugum;
        } else {
            ilkDugum = enBuyukDugum->siradakiDugum;
        }

        delete enBuyukDugum;
        cout << "En buyuk sayi silindi." << endl;
    } else {
        cout << "Listede silinecek bir sayi bulunamadi." << endl;
    }
}

// Dosyadan sayıları okuyup SayilarListesi'ne ekleyen fonksiyon
void SayilarListesi::dosyadanSayilariOkuVeEkle(const char* dosyaAdi, SayilarListesi& sayilarListesi) {
    ifstream dosya(dosyaAdi);

    if (!dosya) {
        cerr << "Dosya acilamadi." << endl;
        return;
    }

    // Dosyadan sayıları oku ve doğru sırayla ekle
    int sayi;
    while (dosya >> sayi) {
        Sayi* yeniSayi = new Sayi();
        Basamak* sonBasamak = NULL;

        // Sayıyı basamaklara ayır
        while (sayi > 0) {
            int basamakDegeri = sayi % 10;
            Basamak* yeniBasamak = new Basamak(basamakDegeri);
            yeniBasamak->siradaki = sonBasamak;
            sonBasamak = yeniBasamak;
            sayi /= 10;
        }

        yeniSayi->ilkBasamak = sonBasamak;

        // Sayıyı SayilarListesi'ne doğru sırayla ekle
        Dugum* yeniDugum = new Dugum(yeniSayi);
        yeniDugum->siradakiDugum = NULL;

        if (sayilarListesi.ilkDugum == NULL) {
            // Liste boşsa direkt ekleyebiliriz
            sayilarListesi.ilkDugum = yeniDugum;
        } else {
            // Listenin sonuna kadar gidip ekleyeceğiz
            Dugum* gecDugum = sayilarListesi.ilkDugum;
            while (gecDugum->siradakiDugum != NULL) {
                gecDugum = gecDugum->siradakiDugum;
            }
            gecDugum->siradakiDugum = yeniDugum;
        }
    }

    dosya.close();
}

// Ekrana gösterilmesi gerek tabloyu yazdıran fonksiyon
void SayilarListesi::sayiBilgileriniYazdir() {
    Dugum* gecici = ilkDugum;

    while (gecici != NULL) {
        Sayi* sayi = gecici->sayiAdres;

        // Sayı bilgilerini yazdır
        cout << "##################   ";
        for (int i = 0; i < sayi->ToplamBasamakSayisi(); i++) {
            cout << "*******  ";
        }
        cout << endl;

        // Sayı nesnesinin adresini yazdır
        cout << "#       " << setw(9) << gecici->sayiAdres << "#" << setw(5);

        // Basamakları yazdır
        Basamak* basamak = sayi->ilkBasamak;
        while (basamak != NULL) {
            stringstream sonUcHane;
            sonUcHane << basamak;
            string adresString = sonUcHane.str();
            string adresStringSonUcHane = adresString.substr(adresString.length() - 3);
            cout << " * " << adresStringSonUcHane << " * " << setw(2);
            basamak = basamak->siradaki;
        }
        cout << endl;

        // Alt çizgiyi yazdır
        cout << "#----------------#   ";
        for (int i = 0; i < sayi->ToplamBasamakSayisi(); i++) {
            cout << "*******  ";
        }
        cout << endl;

        // Sayının tüm hali ve basamakları
        cout << "#        " << setw(8);
        sayi->sayiButun2();
        cout << "#" << setw(6);
        basamak = sayi->ilkBasamak;
        while (basamak != NULL) {
            cout << "  *  " << basamak->data << "  *" << setw(2);
            basamak = basamak->siradaki;
        }
        cout << setw(12) << endl;

        // Alt çizgiyi yazdır
        cout << "##################   ";
        for (int i = 0; i < sayi->ToplamBasamakSayisi(); i++) {
            cout << "*******  ";
        }
        cout << endl;

        // Her yeni sayı bilgisi için iki satır boşluk bırak
        cout << endl << endl;

        gecici = gecici->siradakiDugum;
    }
}