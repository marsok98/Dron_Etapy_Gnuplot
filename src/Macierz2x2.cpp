#include "Macierz2x2.hh"


void Macierz2x2::InicjalizujMacierz(double kat)
{
	kat_w_rad = (PI/180) * kat;
  	Macierz[0][0] = cos(kat_w_rad);
  	Macierz[0][1] = -sin(kat_w_rad);
 	Macierz[1][0] = sin(kat_w_rad);
 	Macierz[1][1] = cos(kat_w_rad); 
}


Wektor Macierz2x2::operator * (const Wektor &Wek)
{
	Wektor Wynik;
	Wynik[0]=0;
	Wynik[1]=0;
	int i,j;
	for(i=0;i<ROZMIAR;i++){
		for(j=0;j<ROZMIAR;j++)
		{
			Wynik[i]+=Macierz[i][j] * Wek[j];
		}	
	}
	return Wynik;
}
