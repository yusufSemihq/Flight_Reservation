#include <iostream>
using namespace std;

class Ucak{

    double yakitKapasite;
    int toplamKoltukSayisi, koltukSayisi;
    double depo;
    string *koltuk;

public:

    Ucak() {

        yakitKapasite = 200;
        toplamKoltukSayisi = 100;
        depo = 0;
        koltukSayisi = 0;
      
        koltuk = new string[toplamKoltukSayisi];
        for(int i=0;i<toplamKoltukSayisi-1;i++)
            koltuk[i]="";
        cout<<"Yeni ucak oluşturuldu"<<"\n";
    }

    Ucak(double _yakitKapasitesi, int _toplamKoltukSayisi) {

        yakitKapasite = _yakitKapasitesi;
        toplamKoltukSayisi = _toplamKoltukSayisi;
        depo = 0;
        koltukSayisi = 0;
        koltuk = new string[toplamKoltukSayisi];
        for(int i=0;i<toplamKoltukSayisi-1;i++)
            koltuk[i]="";
        cout<<"Yeni ucak olusturuldu"<<"\n";
    }

    ~Ucak() {
        delete[] koltuk;
    }

    void yakitDoldur(double miktar) {

        if (depo + miktar > yakitKapasite)
            cout << "Maksimum " << yakitKapasite - depo 
            << " kadar daha doldurabilirsiniz, " << miktar 
            << " cok fazla"<<"\n";
        else
            depo += miktar;
    }

    void yakitGoster() {
        cout << "Depo durumu:" << depo << " litre"<<"\n";
    }

    void kolturkArtir() {
        koltukSayisi++;
    }
    void koltukSay(){
        cout<<"Toplam koltuk sayisi:"
            <<toplamKoltukSayisi<<"\n";
        int boskoltuksayisi=toplamKoltukSayisi-koltukSayisi;
        cout<<"Dolu koltuk sayisi:"
            <<koltukSayisi<<"\n";
        cout<<"Bos koltuk sayisi:"
            <<boskoltuksayisi<<"\n";

    };

    void koltuguRezerveEt(int koltukNo, string adsoyad) {
        if (koltukNo < toplamKoltukSayisi) {
            if (koltuk[koltukNo - 1] == "") {
                koltuk[koltukNo - 1] = adsoyad;
                kolturkArtir();
            } else
                cout << "Bu koltuk daha once " 
                << koltuk[koltukNo - 1] << 
                " isimli kisiye rezerve edilmis"
                << "\n";
        } else
            cout<<toplamKoltukSayisi
                <<" kadar koltuk bulunmaktadır";
    }

    void koltuklistele(){
        for(int i=0;i<toplamKoltukSayisi;i++)
            cout<<i+1<<".koltuk="<<koltuk[i]<<"\n";
    }
};

int main() {
    Ucak u1(200,5);
    u1.koltukSay();
    u1.koltuguRezerveEt(1,"Oguzhan TAS");
    u1.koltuguRezerveEt(2,"Sinan Can");
    u1.koltuguRezerveEt(2,"Ali Can");

    u1.koltukSay();
    u1.koltuklistele();
    u1.yakitDoldur(100);
    u1.yakitGoster();
    u1.yakitDoldur(250);


    return 0;
}
