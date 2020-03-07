#include "Scena.hh"
using namespace std;
void Scena::UstawDronaNaScenieWrzucNaListy(shared_ptr<Dron> Wsk,const Wektor3D &W)
{
  Wsk->Inicjalizuj();
  Wsk->DodajPlikiDronowi(Lacze);
  Wsk->PrzesunDronaDodajDoWektoraPrzesuniecia(W);
  Wsk->ZapiszDronaDoPlikow();
  ListaDronow.push_back(Wsk);
  ListaObiektowSceny.push_back(Wsk);
}

void Scena::UstawPrzeszkodeWrzucNaListe(shared_ptr<PrzeszkodaPr> Wsk,
double WymiarX, double WymiarY, double WymiarZ, const Wektor3D &W )
{
  Wsk->Inicjalizuj(WymiarX,WymiarY,WymiarZ);
  Wsk->DodajPlikPrzeszkodzie(Lacze);
  Wsk->PrzesunDodajDoWektoraPrzesuniecia(W);
  Wsk->ZapiszPrzeszkodeDoPliku();
  ListaObiektowSceny.push_back(Wsk);
}

Scena::Scena()
{
  shared_ptr<Dron> D1(new Dron);
  UstawDronaNaScenieWrzucNaListy(D1,Wektor3D(-100,-100,-100));

  shared_ptr<Dron> D2(new Dron);
  UstawDronaNaScenieWrzucNaListy(D2,Wektor3D(0,0,0));

  shared_ptr<Dron> D3(new Dron);
  UstawDronaNaScenieWrzucNaListy(D3,Wektor3D(100,100,100));

  shared_ptr<PrzeszkodaPr> Pr1(new PrzeszkodaPr);
  UstawPrzeszkodeWrzucNaListe(Pr1,5,40,30,Wektor3D(60,60,-60));
 
  shared_ptr<PrzeszkodaPr> Pr2(new PrzeszkodaPr);
  UstawPrzeszkodeWrzucNaListe(Pr2,20,30,40,Wektor3D(-80,-20,-20));

  shared_ptr<PrzeszkodaPr> Pr3(new PrzeszkodaPr);
  UstawPrzeszkodeWrzucNaListe(Pr3,10,20,30,Wektor3D(-80,60,60));

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj(); 

  Lacze.UstawZakresX(-150, 150);
  Lacze.UstawZakresY(-150, 150);
  Lacze.UstawZakresZ(-150, 150);
  Lacze.Rysuj();
  AktualnyDron = ListaDronow.begin();
}


 void Scena::SterowanieAktualnymDronem()
 {
  char wybor_uzytkownika;
  cout<<endl;
  WyswietlMenu();
  cout<<"\nTwój wybor? (w - menu) > ";
  cin>>wybor_uzytkownika;
  cout<<endl;

  Wektor3D WektorCzastkowy;
  while(wybor_uzytkownika!='k')
  {
    switch(wybor_uzytkownika)
    {
      case 'j':
      {
        WektorCzastkowy = WczytajDrogeZwrocWektorCzastkowy();
        bool Kolizja = false;
        int i;
        for(i = 0; i<40 && Kolizja == false;i++)
        {
          (*AktualnyDron)->AnimowanyRuchNaWprost(Lacze,WektorCzastkowy);
          for(auto elem : ListaObiektowSceny)
          {
            if(elem != *AktualnyDron){Kolizja=elem ->CzyZaszlaKolizja(*AktualnyDron);}
            if(Kolizja){break;}
          }  
        }
        break;
      }

      case 'o':
      {
        (*AktualnyDron)->AnimowanyObrotDrona(Lacze);
        break;
      }
      case 'w':
      {
        WyswietlMenu();
        break;
      }
      case 's':
      {
        int wybor;
        for(auto elem: ListaDronow)
        {
          cout<<"Dron "<<elem->getID()<<"   Wspolrzedne:  "<<elem->PobierzWektorPrzesuniecia()<<endl;
        }
        cout<<"Podaj numer drona: ";
        cin>>wybor;
        SelekcjaDrona(wybor);
        cout<<"Aktualnie wyselekcjonowanym dronem jest: "<<endl;
        cout<<"Dron "<<(*AktualnyDron)->getID() <<"  Wspolrzedne: "
        <<(*AktualnyDron)->PobierzWektorPrzesuniecia()<<endl;
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

 void Scena::SelekcjaDrona(int Numer)
 { 
   list< shared_ptr <Dron> >::iterator Ind =  ListaDronow.begin();
   switch(Numer)
   {
     case 1:
     {
        AktualnyDron = Ind;
        break;
     }
     case 2:
     {
        AktualnyDron = ++Ind;
        break;
     }
     case 3:
     {
        AktualnyDron = ++(++Ind);
        break;
     }
     case 0:
     {
        AktualnyDron = ListaDronow.begin();
        break;
     }
     default:
     {
       cout<<"Nie ma takiego numeru"<<endl;
       break;
     }
   }

 }


 Wektor3D Scena::WczytajDrogeZwrocWektorCzastkowy()
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
  double kat_obrotu_z_klasy_w_rad = M_PI/180.0 * (*AktualnyDron)->PobierzKat_Z() ;
  Wektor3D Wektor;

  Wektor[0] = droga * cos(kat_obrotu_z_klasy_w_rad);
  Wektor[1] = droga * sin(kat_obrotu_z_klasy_w_rad);
  Wektor[2] = tan(kat_wznoszenia_w_rad) * abs(droga);
  Wektor3D WektorCzastkowy = Wektor * (1.0/40.0);
  return WektorCzastkowy;
}