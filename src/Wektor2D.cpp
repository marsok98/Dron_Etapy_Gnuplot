#include "Wektor2D.hh"
#include <iomanip>



Wektor Wektor::operator - (const Wektor &Wek)
{
	int i;
	Wektor Wynik;
	for(i=0;i<ROZMIAR;i++)
	{
		Wynik[i]=Wek[i]-wspolrzedne[i];
	}
	return Wynik;
}

Wektor Wektor::operator + (const Wektor &Wek)
{
	int i;
	Wektor Wynik;
	for(i=0;i<ROZMIAR;i++)
	{
		Wynik[i]=Wek[i]+wspolrzedne[i];
	}
	return Wynik;
}

double Wektor::DlugoscWektora()
{
	int i;
	double wynik=0;
	for(i = 0;i<ROZMIAR;i++)
	{
		wynik += wspolrzedne[i] * wspolrzedne[i];
	}
	return sqrt(wynik);
}



istream& operator >> (istream &Strm, Wektor &Wek)
{
	int i;
	int j;
	for(i = 0;i<ROZMIAR && !Strm.fail();i++)
	{
		Strm>>Wek[i];
		if(Strm.fail()) 
		{
			cout<<"Podales bledne wspolrzedne wektora\n";
			Strm.clear();
			Strm.ignore(1000,'\n');
			for(j=0;j<ROZMIAR;j++)    //Jesli ktos poda pierwsza wspolrzedna dobra a przy drugiej popelni blad to:
			{						  // Wektor i tak zostanie wyzerowany.
				Wek[j]=0;
			}
			return Strm;
		}
	}
	return Strm;
}





ostream& operator << (ostream &Strm, const Wektor &Wek)
{
	int i;
	for(i = 0;i<ROZMIAR;i++)
	{
		Strm<<setw(16)<<fixed<< setprecision(10)<<Wek[i]<<" ";
	}
	return Strm;
}



