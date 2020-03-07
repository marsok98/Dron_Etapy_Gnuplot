#include "Prostopadloscian.hh"



Prostopadloscian::Prostopadloscian(double dlugosc, double szerokosc, double wysokosc)
{
	Wierzcholek[0][0]=0;
	Wierzcholek[0][1]=0;
	Wierzcholek[0][2]=0;

	Wierzcholek[1][0]=dlugosc;
	Wierzcholek[1][1]=0;
	Wierzcholek[1][2]=0;

	Wierzcholek[2][0]=0;
	Wierzcholek[2][1]=szerokosc;
	Wierzcholek[2][2]=0;

	Wierzcholek[3][0]=dlugosc;
	Wierzcholek[3][1]=szerokosc;
	Wierzcholek[3][2]=0;

	Wierzcholek[4][0]=0;
	Wierzcholek[4][1]=szerokosc;
	Wierzcholek[4][2]=wysokosc;

	Wierzcholek[5][0]=dlugosc;
	Wierzcholek[5][1]=szerokosc;
	Wierzcholek[5][2]=wysokosc;

	Wierzcholek[6][0]=0;
	Wierzcholek[6][1]=0;
	Wierzcholek[6][2]=wysokosc;

	Wierzcholek[7][0]=dlugosc;
	Wierzcholek[7][1]=0;
	Wierzcholek[7][2]=wysokosc;
	
}

void Prostopadloscian::PrzesunProstopadloscianoWektor(const Wektor3D &Wek)
{
	int i = 0;
	for(i=0;i<ILOSC;i++)
	{
		Wierzcholek[i]= Wierzcholek[i] + Wek;
	}
}


void Prostopadloscian::ObliczDlugoscBokow()
{
 
  Wektor3D Wynik;
  Wynik=Wierzcholek[0] - Wierzcholek[1];
  DlugoscBoku[0] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[2] - Wierzcholek[3];
  DlugoscBoku[1] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[4] - Wierzcholek[5];
  DlugoscBoku[2] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[6] - Wierzcholek[7];
  DlugoscBoku[3] = Wynik.DlugoscWektora();


  Wynik=Wierzcholek[0] - Wierzcholek[2];
  DlugoscBoku[4] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[1] - Wierzcholek[3];
  DlugoscBoku[5] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[4] - Wierzcholek[6];
  DlugoscBoku[6] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[5] - Wierzcholek[7];
  DlugoscBoku[7] = Wynik.DlugoscWektora();


  Wynik=Wierzcholek[0] - Wierzcholek[6];
  DlugoscBoku[8] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[1] - Wierzcholek[7];
  DlugoscBoku[9] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[2] - Wierzcholek[4];
  DlugoscBoku[10] = Wynik.DlugoscWektora();
  Wynik=Wierzcholek[3] - Wierzcholek[5];
  DlugoscBoku[11] = Wynik.DlugoscWektora();
}




void Prostopadloscian::WyswietlPorownajBoki()
{
  cout<<"\nWyswietlam dlugosci bokow\n\n";
  int i = 0;
  double Suma=0;
  double epsilon = 0.0000000000000001;
  for(i=0;i<ILOSCBOKOW;i++)
  {
  	  cout<< fixed << setprecision(20) << "   Dlugosc boku nr.  "<<i%4+1<<"  "<<DlugoscBoku[i]<<endl; 
  	  Suma+=DlugoscBoku[i];
  	  if(i == 3 or i == 7 or i == 11)
  	  {
  	  	if((fabs(Suma/4.0 - DlugoscBoku[i]) < epsilon) && (fabs(Suma/4.0 - DlugoscBoku[i-1]) < epsilon) &&
  	  	   (fabs(Suma/4.0 - DlugoscBoku[i-2]) < epsilon) && (fabs(Suma/4.0 - DlugoscBoku[i-3]) < epsilon))
		{
			cout<<"Powyzsze boki sa sobie rowne.\n\n";
		}
		else
		{
			cout<<"Powyzsze boki nie sa sobie rowne!!!\n\n";
		}
  	  	Suma = 0;
  	  }  
  } 
}

void Prostopadloscian::ObrocProstopadloscian_o_Kat_i_Powtorz(Macierz3x3 &MacierzObrotu,int ilosc_powtorzen)
{
  	int i,j;
  	for(j=0;j<ilosc_powtorzen;j++)
  	{
    	for(i=0;i<8;i++)
    	{
			Wierzcholek[i] = MacierzObrotu * Wierzcholek[i];
    	}
  	}
}


ostream& operator << (ostream &Strm, const Prostopadloscian &Pr)
{
	int i;
	for(i=0;i<ILOSC;)
	{
		Strm<<Pr[i];
		Strm<<"\n"<<defaultfloat;
		i++;
		if(i%2 == 0) Strm<<endl;
	}
	return Strm;
}



/*
istream & operator >> (istream & Strm, Prostopadloscian &Pr)
{
	int i;
	for(i =0; i<ILOSC;i++)
	{
		Strm>>Pr[i];
	}
	return Strm;
}
*/



