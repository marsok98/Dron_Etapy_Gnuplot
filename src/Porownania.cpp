void Prostokat::ObliczDlugoscBokow()
{
	int i;
	Wektor Wynik;
	for(i=0;i<4;i++)
	{
		if(i==3)
		{
			Wynik = this->Wierzcholek[i] - this->Wierzcholek[0];
			this->DlugosciBokow[i]= Wynik.DlugoscWektora();
		}
		else
		{
			Wynik = this->Wierzcholek[i+1] - this->Wierzcholek[i];
			this->DlugosciBokow[i] = Wynik.DlugoscWektora();
		}
	}

}

void Prostokat::WyswietlPorownajBoki()
{
	int i = 0;
	std::string Okreslenie;
	for(i=0;i<2;i++)
	{
		if(i==0) Okreslenie = "Dluzsze";
		else if (i==1) Okreslenie = "Krotsze";
		if(this->DlugosciBokow[i] == this->DlugosciBokow[i+2])
		{
			std::cout<<"\n:) "<<Okreslenie<<" przeciwlegle boki sa sobie rowne.\n";
			std::cout<<"   Dlugosc pierwszego boku: "<<DlugosciBokow[i]<<std::setprecision(15)<<std::endl;  
			std::cout<<"   Dlugosc drugiego boku: "<<DlugosciBokow[i+2]<<std::setprecision(15)<<std::endl;   
		}
		else
		{
			std::cout<<"\n:O "<<Okreslenie<<" przeciwlegle boki nie sa sobie rowne!!!\n";
			std::cout<<"   Dlugosc pierwszego boku: "<<DlugosciBokow[i]<<std::setprecision(15)<<std::endl;  
			std::cout<<"   Dlugosc drugiego boku: "<<DlugosciBokow[i+2]<<std::setprecision(15)<<std::endl;  
		}
	}
}

////////////////////////////////////////////////////////////////////
Skopiowany tekst z konsoli:


Wspolrzedne prostokata wejsciowego: 
1 1 
11 1 
11 6 
1 6 
1 1 
:) Dluzsze przeciwlegle boki sa sobie rowne.
   Dlugosc pierwszego boku: 10
   Dlugosc drugiego boku: 10

:) Krotsze przeciwlegle boki sa sobie rowne.
   Dlugosc pierwszego boku: 5
   Dlugosc drugiego boku: 5
Przesuwam o wektor:5 7 
Wspolrzedne prostokata wyjsciowego: 
6 8 
16 8 
16 13 
6 13 

:) Dluzsze przeciwlegle boki sa sobie rowne.
   Dlugosc pierwszego boku: 10
   Dlugosc drugiego boku: 10

:) Krotsze przeciwlegle boki sa sobie rowne.
   Dlugosc pierwszego boku: 5
   Dlugosc drugiego boku: 5
Naciśnij ENTER, aby kontynuowac

Boki po obracaniu

:) Dluzsze przeciwlegle boki sa sobie rowne.
   Dlugosc pierwszego boku: 10
   Dlugosc drugiego boku: 10

:) Krotsze przeciwlegle boki sa sobie rowne.
   Dlugosc pierwszego boku: 5
   Dlugosc drugiego boku: 5
Wierzcholki prostokota po obracaniu:                            
5.85946691944007 8.10349599987484         
15.857943871004 8.27802006424768 
15.7706818388176 13.2772585400296 
5.77220488725365 13.1027344756568 
Naciśnij ENTER, aby kontynuowac
