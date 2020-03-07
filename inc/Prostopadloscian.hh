#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Macierz.hh"
#define ILOSC 8
#define ILOSCBOKOW 12

/*!
 * \file  Prostopadloscian.hh
 *  
 *  Plik zawiera definicję  klasy realizującej Prostopadloscian
 */


/*!
 * \brief klasa modeluje pojecie Prostopadloscianu 
 *
 * Klasa Prostopadloscian jest zrealizowana za pomoca tablicy wektorow ktore w tym wypadku interpretowane sa jako wspolrzedne 
 * Do klasy prostopadloscian wliczamy rowniez tablice typu double reprezentujaca dlugosci poszczegolnych bokow
 * Niniejsza przestrzeń nazw stanowi moduł zawierający
 * narzędzia umożliwiające realizację metod klasy prostopadloscian.
 */
class Prostopadloscian 
{
  Wektor3D Wierzcholek[ILOSC];
  double DlugoscBoku[ILOSCBOKOW];
  public:
  
    /*!
     * \brief Przeciazenie operatora [] (modyfikacja wartosci)
     *
     * Funkcja przeciążająca operator [], zwraca Wektor3D ktory jest wspolrzednymi wierzcholka
     * wywoływaną z jedną  zmienną typu int(mozna modyfikowac wartosc)
     */
  	Wektor3D &operator [] (int i)      {return Wierzcholek[i];}

    /*!
     * \brief Przeciazenie operatora []
     *
     * Funkcja przeciążająca operator [], zwraca Wektor3D ktory jest wspolrzednymi wierzcholka
     * wywoływaną z jedną  zmienną typu int( nie mozna modyfikowac wartosc)
     */
  	Wektor3D operator [] (int i)const {return Wierzcholek[i];}



    /*!
     * \brief Konstruktor klasy prostopadloscian
     *
     * Konstruktor Inicjalizuje prostopadloscian z wartosciami dlugosc szerokosc,wysokosc
     * Konstruktor Dziala polega na odpowiednim przypisaniu tych wartosci
     * \param[in] dlugosc
     * \param[in] szerokosc
     * \param[in] wysokosc
     */
  	 Prostopadloscian(double dlugosc  = 50, double szerokosc = 100, double wysokosc = 150);


     /*!
     * \brief Funkcja ktora umozliwia przesuniecie prostopadloscianu o Wektor3D
     *
     * \param[in] Wek obiekt klasy Wektor3D o ktory bedziemy przesuwac bryle
     */
  	void PrzesunProstopadloscianoWektor(const Wektor3D &Wek);

    /*!
     * \brief Funkcja obliczajaca dlugosci bokow prostopadloscianu
     */
  	void ObliczDlugoscBokow();

    /*!
     * \brief Funkcja porownujaca boki oraz wyswietlanie ich na cout
     */
  	void WyswietlPorownajBoki();
    
    /*!
     * \brief Funkcja ktora umozliwia obracanie prostopadloscianu o zadana ilosc razy
     *
     * Funkcja mnozy wspolrzedne prostopadloscianu przez MacierzObrotu zadana ilosc powtorzen
     * \param[in] MacierzObrotu Macierz ktora potrzebna jest do obracania wzgledem osi
     * \param[in] ilosc powtorzen, 
     */
    void ObrocProstopadloscian_o_Kat_i_Powtorz(Macierz3x3 &MacierzObrotu,int ilosc_powtorzen);
};


/*!
 * \brief Przeciazenie operatora << wypisujacego na strumien wyjscia wspolrzedne Prostopadloscianu
 *
 * Funkcja przeciaza operator lewostronnego przesuniecia bitowego
 * ktory pozwala nam na wypisanie na Strumien wyjsciowy wspolrzednych Prostopadloscianu
 * \param[in] Strm - Strumien wyjsciowy
 * \param[in] Pr - Prostopadloscian ktory ma zostac wyswietlony
 * \return Zwraca strumien na ktorym zostaly wypisane wspolrzedne Prostopadloscianu
 */
ostream& operator << (ostream &Strm, const Prostopadloscian &Pr);
//istream & operator >> (istream & Strm, Prostopadloscian &Pr);



#endif
