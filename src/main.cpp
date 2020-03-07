#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"
#include "FunkcjeDoMenu.hh"



using namespace std;



int main()
{
  Prostokat             Pr;   // To tylko przykladowe definicje zmiennej
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("Nowy.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("Nowy.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  //Inicjalizacja
  Lacze.ZmienTrybRys(PzG::TR_2D);


  double dlugosc=100;
  double szerokosc = 200;;
  
  Pr.InicjalizujProstokat(dlugosc,szerokosc);


  
  char wybor_uzytkownika;
  cout<<endl;
  WyswietlMenu();
  cout<<"Twój wybor? (m - menu) > ";
  cin>>wybor_uzytkownika;
  cout<<endl;
  
  while(wybor_uzytkownika!='k')
  {
    switch(wybor_uzytkownika)
    {
      case 'o':
        double kat_w_stopniach;
        int ilosc_powtorzen;
        cout<<"Podaj wartosc kata obrotu w stopniach: ";
        if(wczytaj_sprawdz_zapisz_liczbe(cin,kat_w_stopniach))
        {
            cout<<"\n Ile razy operacja ma byc powtorzona: ";
            if(wczytaj_sprawdz_zapisz_liczbe(cin,ilosc_powtorzen))
            {
              Pr.ObrocProstokat_o_Kat_i_Powtorz(kat_w_stopniach,ilosc_powtorzen);
            }
        }
        break;

      case 'p':
        Wektor W1;
        cout<<"Podaj wektor do przesuniecia: ";
        cin>>W1;
        Pr = Pr.PrzesunProstokatoWektor(W1);
        break;

      case 'w':
        cout<<"Wspolrzedne prostokata:\n";
        cout<<Pr;
        break;

      case 'b':   
        Pr.ObliczDlugoscBokow();
        Pr.WyswietlPorownajBoki();
        break;

      case 'g':
        if(!ZapisDoPliku(Pr,"Nowy.dat")) return 1;
        Lacze.Rysuj();
        break;

      case 'm':
        WyswietlMenu();
        break;

      default:
        cout<<"Niepoprawny wybor\n";
        break;

    }
    cout<<"\nTwój wybor? (m - menu) > ";
    cin>>wybor_uzytkownika;  
  }
}

