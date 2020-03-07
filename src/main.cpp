#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include "FunkcjeDoMenu.hh"



using namespace std;

int main()
{
  Prostopadloscian             Pr;   // To tylko przykladowe definicje zmiennej
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostopadloscian.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-155,155);
  Lacze.UstawZakresX(-155,155);
  Lacze.UstawZakresZ(-155,155);

  
  Macierz3x3 MacierzObrotu;
  int ilosc_powtorzen;
  bool czy_byl_obrot = false;

  char wybor_uzytkownika;
  cout<<endl;

  WyswietlMenu();
  cout<<"\nTwój wybor? (m - menu) > ";
  cin>>wybor_uzytkownika;
  cout<<endl;


  while(wybor_uzytkownika!='k')
  {
    switch(wybor_uzytkownika)
    {

      case 'i':
      {
        Pr = Wczytaj_Dane_Inicjuj_Prostopadloscian();
        break;
      }

      case 'o':
      {
        czy_byl_obrot = true;
        MacierzObrotu = Wczytaj_Sekwencje_Zwroc_Macierz_Obrotu();
        cout<<"\n Ile razy operacja ma byc powtorzona: ";
        if(wczytaj_sprawdz_zapisz_liczbe(cin,ilosc_powtorzen))
        {
          Pr.ObrocProstopadloscian_o_Kat_i_Powtorz(MacierzObrotu,ilosc_powtorzen);
        }
        break;
      }


      case 't':
      {
        if(czy_byl_obrot)
        {
          cout<<endl<<"Powtarzam poprzedni obrót\n";
          Pr.ObrocProstopadloscian_o_Kat_i_Powtorz(MacierzObrotu,ilosc_powtorzen);
        }
        else
        {
          cout<<endl<<"Nie wykonales jeszcze zadnego obrotu\n";
        }
        break;
      }


      case 'r':
      {
        cout<<endl<<"Wyswietlam macierz rotacji : \n";
        cout<<MacierzObrotu;
        break;
      }


      case 'p':
      {
        Wektor3D W1;
        cout<<"Podaj wektor do przesuniecia: ";
        cin>>W1;
        Pr.PrzesunProstopadloscianoWektor(W1);
        break;
      }


      case 'w':
      {
        cout<<"Wspolrzedne Prostopadloscianu\n";
        cout<<Pr;
        break;
      }


      case 's':
      {
        Pr.ObliczDlugoscBokow();
        Pr.WyswietlPorownajBoki();
        break;
      }


      case 'g':
      {
        if(!ZapisDoPliku(Pr,"prostopadloscian.dat")) return 1;
        Lacze.Rysuj();
        break;
      }


      case 'm':
      {
        WyswietlMenu();
        break;
      } 


      default:
      {
        cout<<"Niepoprawny wybor\n";
        break;
      }
    }
    cout<<"\nTwój wybor? (m - menu) > ";
    cin>>wybor_uzytkownika;
  }

}
