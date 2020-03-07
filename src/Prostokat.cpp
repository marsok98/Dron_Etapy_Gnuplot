#include "Prostokat.hh"
#include <iomanip>

void Prostokat::InicjalizujProstokat(double dlugosc, double szerokosc)
{
	Wierzcholek[0][0]=0;
	Wierzcholek[0][1]=0;
	Wierzcholek[1][0]=dlugosc;
	Wierzcholek[1][1]=0;
	Wierzcholek[2][0]=dlugosc;
	Wierzcholek[2][1]=szerokosc;
	Wierzcholek[3][0]=0;
	Wierzcholek[3][1]=szerokosc;

}


void Prostokat::ObliczDlugoscBokow()
{
	int i;
	Wektor Wynik;
	for(i=0;i<4;i++)
	{
		if(i==3)
		{
			Wynik = Wierzcholek[i] - Wierzcholek[0];
			DlugosciBokow[i]= Wynik.DlugoscWektora();
		}
		else
		{
			Wynik = Wierzcholek[i+1] - Wierzcholek[i];
			DlugosciBokow[i] = Wynik.DlugoscWektora();
		}
	}

}




void Prostokat::WyswietlPorownajBoki()
{
	int i = 0;
	double epsilon = 0.00000000000001;
	string Okreslenie;
	for(i=0;i<2;i++)
	{
		if(DlugosciBokow[i]>DlugosciBokow[i+1]) Okreslenie = "Dluzsze";
		else Okreslenie = "Krotsze";
		if(fabs(DlugosciBokow[i] - DlugosciBokow[i+2]) < epsilon)
		{
			cout<<"\n:) "<<Okreslenie<<" przeciwlegle boki sa sobie rowne.\n";
			cout<< fixed << setprecision(20) << "   Dlugosc pierwszego boku: "<<DlugosciBokow[i]<<endl;  
			cout << "   Dlugosc drugiego boku: "<<DlugosciBokow[i+2]<<endl<<defaultfloat;

		}
		else
		{
			cout<<"\n:O "<<Okreslenie<<" przeciwlegle boki nie sa sobie rowne!!!\n";
			cout<< fixed << setprecision(20) << "   Dlugosc pierwszego boku: "<<DlugosciBokow[i]<<endl;  
			cout<< "   Dlugosc drugiego boku: "<<DlugosciBokow[i+2]<<endl<<defaultfloat;  
		}
	}
}


Prostokat Prostokat::PrzesunProstokatoWektor(Wektor Wek)
{
	int i = 0;
	Prostokat Wynik;
	for(i=0;i<4;i++)
	{
		Wynik[i]=Wierzcholek[i]+Wek;
	}
	return Wynik;
}





void Prostokat::ObrocProstokat_o_Kat_i_Powtorz(double kat_w_stopniach, int ilosc_powtorzen)
{
	Macierz2x2 B;
	B.InicjalizujMacierz(kat_w_stopniach);
  	int i,j;
  	for(j=0;j<ilosc_powtorzen;j++){
    	for(i=0;i<4;i++){
      		Wierzcholek[i] = B * Wierzcholek[i];
    	}
  	}

}
ostream& operator << (ostream &Strm, const Prostokat &Pr)
{
	int i;
	for(i=0;i<4;i++)
	{
		Strm<<Pr[i];
		Strm<<"\n"<<defaultfloat;
	}
	return Strm;
}




istream & operator >> (istream & Strm, Prostokat &Pr)
{
	int i;
	for(i =0; i<4;i++)
	{
		Strm>>Pr[i];
	}
	return Strm;
}

