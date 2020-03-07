#include "Dron.hh"

void Dron::WczytajSkaleDrona()
{
    cout<<"\n Podaj skale do drona: ";
    cin>>SkalaDrona;
    cout<<"\n Podana przez Ciebie skala wynosi:  "<<SkalaDrona;
    cout<<endl;
}


void Dron::Inicjalizuj()
{
    Korpus.Inicjalizuj(SkalaDrona * Wymiar_Korpusu);

    Rotor[0].Inicjalizuj(SkalaDrona * Wymiar_Wirnika, SkalaDrona * Grubosc_Wirnika);
    Rotor[1].Inicjalizuj(SkalaDrona * Wymiar_Wirnika, SkalaDrona * Grubosc_Wirnika);
    Rotor[2].Inicjalizuj(SkalaDrona * Wymiar_Wirnika, SkalaDrona * Grubosc_Wirnika);
    Rotor[3].Inicjalizuj(SkalaDrona * Wymiar_Wirnika, SkalaDrona * Grubosc_Wirnika);

    Wektor3D Wek0 (-SkalaDrona * Wymiar_Korpusu,     SkalaDrona * Wymiar_Korpusu,     SkalaDrona * Wymiar_Korpusu + SkalaDrona * Grubosc_Wirnika);
    Wektor3D Wek1 (-SkalaDrona * Wymiar_Korpusu,     -SkalaDrona * Wymiar_Korpusu,    SkalaDrona * Wymiar_Korpusu + SkalaDrona * Grubosc_Wirnika);
    Wektor3D Wek2 (SkalaDrona * Wymiar_Korpusu,      SkalaDrona * Wymiar_Korpusu,     SkalaDrona * Wymiar_Korpusu + SkalaDrona * Grubosc_Wirnika);
    Wektor3D Wek3 (SkalaDrona * Wymiar_Korpusu,      -SkalaDrona * Wymiar_Korpusu,    SkalaDrona * Wymiar_Korpusu + SkalaDrona * Grubosc_Wirnika);

    Rotor[0].Ustaw_Offset_DodajDo_Offsetu_(Wek0);
    Rotor[1].Ustaw_Offset_DodajDo_Offsetu_(Wek1);
    Rotor[2].Ustaw_Offset_DodajDo_Offsetu_(Wek2);
    Rotor[3].Ustaw_Offset_DodajDo_Offsetu_(Wek3);

}

void Dron::ZapiszDronaDoPlikow()
{
    Korpus.ZapisFiguryDoPliku(PLIK_KORPUS);
    Rotor[0].ZapisFiguryDoPliku(PLIK_WIRNIK1);
    Rotor[1].ZapisFiguryDoPliku(PLIK_WIRNIK2);
    Rotor[2].ZapisFiguryDoPliku(PLIK_WIRNIK3);
    Rotor[3].ZapisFiguryDoPliku(PLIK_WIRNIK4);
}

void Dron::PrzesunDronaDodajDoWektoraPrzesuniecia(const Wektor3D &Wek)
{
    Korpus.PrzesunDodajDoWektoraPrzesuniecia(Wek);
    int i;
    for(i=0;i<ILOSCROTOROW;i++)
    {
        Rotor[i].PrzesunDodajDoWektoraPrzesuniecia(Wek);
    }
}

void Dron::AnimowanyRuchNaWprost(PzG::LaczeDoGNUPlota &Lacze)
{
  double droga;
  double kat_wznoszenia;
  cout<<"Podaj dlugosc drogi : ";
  cin>>droga;
  cout<<"\n Podaj kat_wznoszenia wznoszenia: ";
  cin>>kat_wznoszenia;
  while(kat_wznoszenia>=90 or kat_wznoszenia<=-90)
  {
      cout<<"Nieprawidlowy kat, kat musi zawierac w przedziale (-90,90)"<<endl<<endl;
  }
  double kat_wznoszenia_w_rad = M_PI/180.0 * kat_wznoszenia;
  double kat_obrotu_z_klasy_w_rad = M_PI/180.0 *KatZ_stopnie ;
  Wektor3D Wektor;

  Wektor[0] = droga * cos(kat_obrotu_z_klasy_w_rad);
  Wektor[1] = droga * sin(kat_obrotu_z_klasy_w_rad);
  Wektor[2] = tan(kat_wznoszenia_w_rad) * abs(droga);

  Wektor3D WektorCzastkowy = Wektor * (1.0/40.0);

  int i;
  for(i=0;i<40;i++)
  {
    AnimowanyObrotSmigiel(Lacze);
    PrzesunDronaDodajDoWektoraPrzesuniecia(WektorCzastkowy);
    ZapiszDronaDoPlikow();
    usleep(5000);
    Lacze.Rysuj();
  }
}

void Dron::PrzesunDronaNaSrodekUkladuWspolrzednych()
{
    Korpus.PrzesunNaSrodekUkladuWspolrzednych();
    int i;
    for(i=0;i<ILOSCROTOROW;i++)
    {
        Rotor[i].PrzesunNaSrodekUkladuWspolrzednych();
    }
}


void Dron::WrocNaPozycjeDronemPoLekkimObrocie()
{
    Korpus.WrocNaPozycjePoLekkimObrocie();
    int i;
    for(i=0;i<ILOSCROTOROW;i++)
    {
        Rotor[i].WrocNaPozycjePoLekkimObrocie();
    }
}


void Dron::ObrocDrona(Macierz3x3 &MacierzObrotu)
{
    Korpus.ObrocFigure(MacierzObrotu);
    int i;
    for(i=0;i<ILOSCROTOROW;i++)
    {
        Rotor[i].ObrocFigure(MacierzObrotu);
    }
}

void Dron::AnimowanyObrotSmigiel(PzG::LaczeDoGNUPlota &Lacze)
{
    int i,j;
    Macierz3x3 MacierzObrotu;
    double kat =360;
    double kat_czastkowy = kat * 1/5.0;
    double suma_kata=0;

    for(j=0;j<5;j++)
    {
        suma_kata += kat_czastkowy;
        MacierzObrotu = UtworzMacierzZ(suma_kata);
        for(i=0;i<ILOSCROTOROW;i++)
        {
            Rotor[i].Cofnij_Offset_();
            Rotor[i].PrzesunNaSrodekUkladuWspolrzednych();
            Rotor[i].ObrocFigure(MacierzObrotu);
            Rotor[i].Ustaw_Offset_();
            Rotor[i].WrocNaPozycjePoLekkimObrocie();
        }
        ZapiszDronaDoPlikow();
        usleep(10000);
        Lacze.Rysuj();
    }
}

void Dron::AnimowanyObrotDrona(PzG::LaczeDoGNUPlota &Lacze)
{
  double kat;
  cout<<"Podaj kat do obrocenia prostopadloscianu: "<<endl;
  cin>>kat;
  Macierz3x3 MacierzObrotu;
  double Czastkowy_kat = kat * (1/40.0);
  
  int i;
  for(i=0;i<40;i++)
  {
    AnimowanyObrotSmigiel(Lacze);
    PrzesunDronaNaSrodekUkladuWspolrzednych();
    KatZ_stopnie += Czastkowy_kat;
    MacierzObrotu=UtworzMacierzZ(KatZ_stopnie);
    ObrocDrona(MacierzObrotu);
    WrocNaPozycjeDronemPoLekkimObrocie();
    ZapiszDronaDoPlikow();
    usleep(5000);
    Lacze.Rysuj();
   }
}