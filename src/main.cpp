#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "lacze_do_gnuplota.hh"
#include "FunkcjeDoMenu.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Dron.hh"


using namespace std;

int main()
{
  //PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  PzG::LaczeDoGNUPlota  Lacze;

  Lacze.DodajNazwePliku(PLIK_KORPUS,PzG::SR_Ciagly);
  Lacze.DodajNazwePliku(PLIK_WIRNIK1,PzG::SR_Ciagly);
  Lacze.DodajNazwePliku(PLIK_WIRNIK2,PzG::SR_Ciagly);
  Lacze.DodajNazwePliku(PLIK_WIRNIK3,PzG::SR_Ciagly);
  Lacze.DodajNazwePliku(PLIK_WIRNIK4,PzG::SR_Ciagly);

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-150, 150);
  Lacze.UstawZakresY(-150, 150);
  Lacze.UstawZakresZ(-150, 150);


 
  char wybor_uzytkownika;
  cout<<endl;
  Dron D1;
  D1.WczytajSkaleDrona();
  D1.Inicjalizuj();
  D1.ZapiszDronaDoPlikow();
  Lacze.Rysuj();

  WyswietlMenu();
  cout<<"\nTwój wybor? (w - menu) > ";
  cin>>wybor_uzytkownika;
  cout<<endl;


  while(wybor_uzytkownika!='k')
  {
    switch(wybor_uzytkownika)
    {
      case 'j':
      {
        D1.AnimowanyRuchNaWprost(Lacze);
        break;
      }
      case 'o':
      {
        D1.AnimowanyObrotDrona(Lacze);
        break;
      }
      case 'w':
      {
        WyswietlMenu();
        break;
      }
      default:
      {
        cout<<"Zla opcja\n";
        break;
      }
      
    }
    cout<<"\nTwój wybor? (w - menu) > ";
      cin>>wybor_uzytkownika;
      cout<<endl;
  }

}

