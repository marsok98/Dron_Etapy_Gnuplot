#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor2D.hh"
#include <string.h>
#include "Macierz2x2.hh"

using namespace std;

/*
 *  Klasa modeluje pojecie Prostokata. Prostokat to czteroelementowa tablica Wektorow
 *  Zapewnia przeciazenia operatorow indeksowania
 *  Zawiera metode InicjalizujProstokat, ObliczDlugoscBokow, WyswietlPorownajBoki,
 *  PrzesunProstokatoWektor, ObrocProstokat_o_Kat_i_Powtorz
 */

class Prostokat {
  Wektor Wierzcholek[4];
  double DlugosciBokow[4];

public:

/*
  Przeciazenie operatora indeksowania
  Nie możemy modyfikować wartosci const na koncu oznacza ze nie zmienia stanu klasy
*/
  Wektor operator []   (int i) const {return Wierzcholek[i];}



/*
    Przeciazenie operatora indeksowania
    Możemy modyfikować wartosc
*/
  Wektor &operator [] (int i) {return Wierzcholek[i];}

  



/*                                                                           
 * Metoda umozliwiajaca Inicjowanie Prostokata zaleznego od dwoch parametrow:dlugosci i szerokosci
 *
 * dlugosc - przesuniecie po osi OX
 * szerokosc - przesuniecie po osi OY
 * Domniemany argument przekazywany z klasy                                                                                                                          
 * 
 *                                                                           
 *  Warunki wstepne:
 *    Obie zmienne muszą być typu double
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		brak
 */ 	
  void InicjalizujProstokat(double dlugosc, double szerokosc);






/*                                                                           
 * Metoda umozliwiajaca Obliczenie dlugosci bokow prostokata
 *
 * 		Domniemany argument przekazywany z klasy                                                                                                                         
 * 
 *                                                                           
 *  Warunki wstepne:
 *    Brak
 * 
 *  Warunki koncowe:
 *     Zapisuje do tablicy DlugosciBokow[] dlugosci bokow
 *
 *  Zwracane wartosci:
 *		Brak
 */
  void ObliczDlugoscBokow();








/*                                                                           
 * Metoda umozliwiajaca Wyswietlenie porownanianie Bokow obiektu klasy prostokat

 * 		Domniemany argument przekazywany z klasy                                                                                                                         
 * 
 *                                                                           
 *  Warunki wstepne:
 *    Brak
 * 
 *  Warunki koncowe:
 *     Wypisuje boki i informuje czy boki są rowne czy też nie 
 *
 *  Zwracane wartosci:
 *		Brak
 */
  void WyswietlPorownajBoki();





/*                                                                           
 * Metoda umozliwiajaca Przesuwanie prostokata o wektor
 *
 * 		Domniemany argument przekazywany z klasy  
 *       Wek     - Obiekt klasy Wektor, o ten wektor prostokat zostanie przesuniety
 * 
 *                                                                           
 *  Warunki wstepne:
 *    Wek - Obiekt przekazany przez referencje ale nie modyfikowalny
 * 
 *  Warunki koncowe:
 *    Brak 
 *
 *  Zwracane wartosci:
 *		Wynik   - Obiekt klasy Prostokat który jest przesuniety o wektor 
 */
  Prostokat PrzesunProstokatoWektor(Wektor Wek);







/*                                                                           
 * Metoda umozliwiajaca Obrot Prostokata o Kat oraz powtorzenie tej operacji
 *
 * 		Domniemany argument przekazywany z klasy  
 *      kat_w_stopniach
 *      ilosc powtorzen - ilosc powtorzen obrotu
 * 
 *                                                                           
 *  Warunki wstepne:
 *    Obie wartosci typu double
 * 
 *  Warunki koncowe:
 *    Brak 
 *
 *  Zwracane wartosci:
 *		Wynikowy   - Prostokat obrocony o kat i powtorzony proces w zaleznosci od ilosci powtorzen
 */
  void ObrocProstokat_o_Kat_i_Powtorz(double kat_w_stopniach,int ilosc_powtorzen);
};




/*                                                                           
 * Przeciazenie  strumienia pozwalajace na wyswietlenie Prostokata Pr na strumien Strm
 * Wyswietla na 16 miejscach i z 10 miejscami po przecinku                                                                                                  
 *  	 Strm     - Strumien wyjsciowy                         
 *       Pr      - Obiekt klasy Prostokat. Z tego zostana pobrane wartosci i wrzucone na strumien
 *                                                                           
 *  Warunki wstepne:
 *    Strm - Strumien przekazany przez referencje
 *    Pr - Obiekt przekazany przez referencje ale niemodyfikowalny
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		Strm      -Strumien wyjsciowy
 */ 
ostream & operator << (ostream &Strm, const Prostokat &Pr);  









/*                                                                           
 * Przeciazenie  strumienia pozwalajace na wczytanie  Prostokata Pr ze strumienia Strm
 *                                                                                                    
 *  	 Strm     - Strumien wejsciowy                         
 *       Pr      - Obiekt klasy Prostokat. Do tego obiektu zostana wczytane wartosci
 *                                                                           
 *  Warunki wstepne:
 *    Strm - Strumien przekazany przez referencje
 *    Pr - Obiekt przekazany przez referencje
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		Strm     - Strumien wejsciowy
 */ 

istream & operator >> (istream & Strm, Prostokat &Pr);


#endif
