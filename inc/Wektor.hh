#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*!
 * \file  Wektor.hh
 *  
 *  Plik zawiera definicję klasy realizującej wektor 
 */


/*!
 * \brief Moduł narzędzi umożliwiających dzialania na wektorze
 *
 * Niniejsza przestrzeń nazw stanowi moduł zawierający
 * narzędzia umożliwiające realizację metod klasy wektor.
 */
template <int Wymiar>
class Wektor {
  double Wspolrzedne[Wymiar];
  
 public:
   /*!
    * \brief Przeciazenie operatora [](modyfikacja wartosci)
    *
    * Funkcja przeciążająca operator [], zwraca tablice jednowymiarową w nawiasach kwadratowych,
    * wywoływaną z jedną  zmienną typu int (Mozemy modyfikowac wartosc)
    */
    double &operator [] (int i)      {return Wspolrzedne[i];}
   /*!
    * \brief Przeciazenie operatora []
    *
    * Funkcja przeciążająca operator [], zwraca tablice jednowymiarową w nawiasach kwadratowych,
    * wywoływaną z jedną  zmienną typu int (Nie Mozemy modyfikowac wartosci)
    */
    double operator [] (int i)const {return Wspolrzedne[i];}
  /*!
   * \brief Przeciazenie operatora -
   *
   * Funkcja przeciążająca operator odejmowania, odpowiada za odejmowanie od siebie dwóch wektorów,
   *  wywoływana z jednym argumentem klasy Wektor , zwraca także wartość wektora,będącego
   *  wynikiem odejmowania oraz należacym do klasy Wektor 
   */
    Wektor<Wymiar> operator - (const Wektor<Wymiar> &Wek);

   /*!
    * \brief Przeciazenie operatora +
    *
    * Funkcja przeciążająca operator dodawania, odpowiada za dodawanie do  siebie dwóch wektorów,
    *  wywoływana z jednym argumentem klasy Wektor , zwraca także wartość wektora,będącego
    *  wynikiem dodawania oraz należacym do klasy Wektor
    */
    Wektor<Wymiar> operator + (const Wektor<Wymiar> &Wek);

    /*!
     * \brief Funkcja obliczajaca dlugosc wektora
     *
     * Funkcja odpowiedzialna za obliczenie odleglosci pomiedzy dwoma wektorami; wywołana bez
     * zadnego argumentu, zwraca odległość będącą zmeinna typu double 
     */
    double DlugoscWektora();
};



/*!
 * \brief Przeciazenie operatora >> umozliwiajaca pobranie wspolrzednych wektora z strumienia wej
 *
 * Funkcja przeciaza operator prawostronnego przesuniecia bitowego
 * ktory pozwala nam na wczytanie ze strumienia wejsciowego wspolrzednych wektora
 * \param[in] Strm - Strumien wejsciowy
 * \param[in] Wek - Wektor  ktory ma zostac wczytany ze strumienia
 * \return Zwraca strumien z ktorego wczytano wektor
 */
template<int Wymiar>
istream& operator >> (istream &Strm, Wektor <Wymiar> &Wek)
{
  int i;
  int j;
  for(i = 0;i<Wymiar && !Strm.fail();i++)
  {
    Strm>>Wek[i];
    if(Strm.fail()) 
    {
      cout<<"Podales bledne Wspolrzedne wektora\n";
      Strm.clear();
      Strm.ignore(1000,'\n');
      for(j=0;j<Wymiar;j++)    //Jesli ktos poda pierwsza wspolrzedna dobra a przy drugiej popelni blad to:
      {             // Wektor i tak zostanie wyzerowany.
        Wek[j]=0;
      }
      return Strm;
    }
  }
  return Strm;
}



/*!
 * \brief Przeciazenie operatora << ktory umozliwia przekazanie wspolrzednych wektora na Strumien wyjsciowy
 *
 * Funkcja ktory  przeciaza operator lewostronnego przesuniecia bitowego
 * ktory pozwala nam wypisanie na strumien wyjsciowy Wektora
 * \param[in] Strm - strumien wyjsciowy
 * \param[in] Wek - Wektor ktorego wspolrzedne maja byc wyswietlone
 * \return Zwraca strumien na ktory zostal wypisany Wektor
 */
template <int Wymiar>
ostream& operator << (ostream &Strm, const Wektor <Wymiar> &Wek)
{
  int i;
  for(i = 0;i<Wymiar;i++)
  {
    Strm<<setw(16)<<fixed<< setprecision(10)<<Wek[i]<<" ";
  }
  return Strm;
}



template<int Wymiar>
inline
Wektor<Wymiar> Wektor<Wymiar>::operator - (const Wektor<Wymiar> &Wek)
{
  int i;
  Wektor<Wymiar> Wynik;
  for(i=0;i<Wymiar;i++)
  {
    Wynik[i]=Wek[i]-Wspolrzedne[i];
  }
  return Wynik;
}



template<int Wymiar>
inline
Wektor<Wymiar> Wektor<Wymiar>::operator + (const Wektor<Wymiar> &Wek)
{
  int i;
  Wektor<Wymiar> Wynik;
  for(i=0;i<Wymiar;i++)
  {
    Wynik[i]=Wek[i]+Wspolrzedne[i];
  }
  return Wynik;
}



template<int Wymiar>
inline 
double Wektor<Wymiar>::DlugoscWektora()
{
  int i;
  double wynik=0;
  for(i = 0;i<Wymiar;i++)
  {
    wynik += Wspolrzedne[i] * Wspolrzedne[i];
  }
  return sqrt(wynik);
}


#endif
