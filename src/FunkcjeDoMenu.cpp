#include "FunkcjeDoMenu.hh"


bool ZapisDoPliku(const Prostopadloscian &Pr, const char  *sNazwaPliku)
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  StrmPlikowy<<fixed << setprecision(20)<<Pr;
  StrmPlikowy<<fixed << setprecision(20)<<Pr[0]<<endl<<Pr[1]<<defaultfloat<<endl;

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


void WyswietlMenu()
{
	cout<<endl;
	cout<<"i - Inicjalizuj bryle(dlugosc,szerokosc,wysokosc)\n";
	cout<<"o - Obrot bryly o zadana sekwencje katow\n";
	cout<<"t - Powtorzenie poprzedniego obrotu\n";
	cout<<"r - Wyswietlenie macierzy rotacji\n";
	cout<<"p - Przesuniecie prostokata o zadany wektor\n";
	cout<<"w - Wyswietlenie wspolrzednych wierzcholkow\n";
	cout<<"s - Sprawdzenie dlugosci przeciwleglych bokow\n";
	cout<<"g - Rysuj bryle w gnuplocie\n";
	cout<<"m - Wyswietl menu\n";
	cout<<"k - Koniec dzialania programu\n\n";
}


Prostopadloscian Wczytaj_Dane_Inicjuj_Prostopadloscian()
{
	  double dlugosc,szerokosc,wysokosc;
    cout<<"Podaj dlugosc szerokosc wysokosc prostopadloscianu\n";
    wczytaj_sprawdz_zapisz_liczbe(cin,dlugosc);
    wczytaj_sprawdz_zapisz_liczbe(cin,szerokosc);
    wczytaj_sprawdz_zapisz_liczbe(cin,wysokosc);
    cout<<"Dlugosc: "<<dlugosc<<endl;
    cout<<"Szerokość: "<<szerokosc<<endl;
    cout<<"Wysokosc: "<<wysokosc<<endl;
    Prostopadloscian Pr(dlugosc,szerokosc,wysokosc);       //wywolanie konstruktora`
    return Pr;
}

Macierz3x3 Wczytaj_Sekwencje_Zwroc_Macierz_Obrotu()
{
		Macierz3x3 MacierzObrotu;    //Macierz odrazu bedzie Macierza jednostkowa

		double kat_w_stopniachX = 0;
		double kat_w_stopniachY = 0;
		double kat_w_stopniachZ = 0;
    char axis;
        cout<<"Podaj sekwencje oznaczen osi oraz katy obrotu w stopniach\n";
        while(axis != '.')
        {
          wczytaj_sprawdz_zapisz_znak(cin,axis);
          switch(axis)
          {
            case 'x':
            {
               wczytaj_sprawdz_zapisz_liczbe(cin,kat_w_stopniachX);
               Macierz3x3 MacX = InicjalizujMacierz_obrotu('x',kat_w_stopniachX);
               MacierzObrotu = MacierzObrotu * MacX;  //mnozymy przez dotychczasowa macierz obrotu
               break;
             }
            case 'y':
            {
              wczytaj_sprawdz_zapisz_liczbe(cin,kat_w_stopniachY);
              Macierz3x3 MacY = InicjalizujMacierz_obrotu('y',kat_w_stopniachY);
              MacierzObrotu = MacierzObrotu * MacY;
              break;
            }
            case 'z':
            {
              wczytaj_sprawdz_zapisz_liczbe(cin,kat_w_stopniachZ);
              Macierz3x3 MacZ = InicjalizujMacierz_obrotu('z',kat_w_stopniachZ);
              MacierzObrotu = MacierzObrotu * MacZ;
              break;
            }
            case '.':
            {
              break;
            }
            default:
            {
              cout<<"Bledne oznaczenie osi\n";
              cout<<"Sprobuj jeszcze raz, dobrze wpisane parametry sa nadal w pamieci\n";
              cin.clear();
              cin.ignore(1000, '\n');
              break;
            }
          }
        }
        cout<<"Twoj wybor to: \n";
        cout<<"X "<<kat_w_stopniachX<<endl;
        cout<<"Y "<<kat_w_stopniachY<<endl;
        cout<<"Z "<<kat_w_stopniachZ<<endl;

        return MacierzObrotu;
}


bool wczytaj_sprawdz_zapisz_znak(istream &Strm, char &znak)
{
	char temp;
	Strm >> temp;
	if(Strm.fail())
	{
		cout<<"Nie podales znaku, Blad\n";
		Strm.clear();
		Strm.ignore(1000, '\n');         										
		return false;
	}
	else
	{
		znak = temp;
		return true;
	}

}

bool wczytaj_sprawdz_zapisz_liczbe(istream &Strm, double &liczba)
{
	double temp;
	Strm >> temp;
	if(Strm.fail())
  {
		cout<<"Nie podales liczby, Blad\n";
		Strm.clear();
		Strm.ignore(1000, '\n');         										
		return false;
	}
	else
	{
		liczba = temp;			//jesli wszystko ok to przypisz do liczby wartosc wczytana
		return true;
	}
}


bool wczytaj_sprawdz_zapisz_liczbe(istream &Strm, int &liczba)
{
	int temp;
	Strm >> temp;
	if(Strm.fail())
	{
		cout<<"Nie podales liczby, Blad\n";   
		Strm.clear();
		Strm.ignore(1000, '\n');        				//jesli zostalo wczytanego cos nieprawidlowego to zwroc strumien
		return false;
	}
	else
	{
		liczba = temp;												//jesli wszystko ok to przypisz do liczby wartosc wczytana
		return true;
	}
}







