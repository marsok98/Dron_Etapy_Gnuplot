#include "FunkcjeDoMenu.hh"

bool ZapisDoPliku(const Prostokat Pr, const char  *sNazwaPliku)
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  StrmPlikowy<<fixed << setprecision(20)<<Pr;
  StrmPlikowy<<fixed << setprecision(20)<<Pr[0]<<defaultfloat<<endl;

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

void WyswietlMenu()
{
	cout<<endl;
	cout<<"o - Obrot prostokata o zadany kat\n";
	cout<<"p - Przesuniecie prostokata o zadany wektor\n";
	cout<<"w - Wyswietlenie wspolrzednych wierzcholkow\n";
	cout<<"b - Porownaj ze soba boki prostokata\n";
	cout<<"g - Rysuj prostokat w gnuplocie\n";
	cout<<"m - Wyswietl menu\n";
	cout<<"k - Koniec dzialania programu\n\n";
}

bool wczytaj_sprawdz_zapisz_liczbe(istream &Strm, double &liczba)
{
	double temp;
	Strm >> temp;
	if(Strm.fail()){
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
		Strm.ignore(1000, '\n');        										//jesli zostalo wczytanego cos nieprawidlowego to zwroc strumien
		return false;
	}
	else
	{
		liczba = temp;												//jesli wszystko ok to przypisz do liczby wartosc wczytana
		return true;
	}
}







