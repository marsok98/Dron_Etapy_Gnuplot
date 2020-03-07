#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH
#define ROZMIAR 2
#include <iostream>
#include <cmath>

using namespace std;
/*
 *  Klasa modeluje pojecie Wektora
 * 	Zapewnia przeciazenia operatorow indeksowania dodawania i odejmowania
 *  Zawiera metode obliczajaca dlugosc wektora.
 */
class Wektor {
	double wspolrzedne[ROZMIAR];
 public:
 /*
 	Przeciazenie operatora indeksowania
 	Możemy modyfikować wartosc
 */
  	double &operator [] (int i)      {return wspolrzedne[i];}

/*
 	Przeciazenie operatora indeksowania
 	Nie możemy modyfikować wartosci const na koncu oznacza ze nie zmienia stanu klasy
*/
  	double operator [] (int i)const {return wspolrzedne[i];}



/*                                                                           
 * Przeciazenie  operatora odejmowania
 * 					Domniemany argument przekazywany z klasy                                                                                                                         
 *       Wek      - Obiekt klasy Wektor. Drugi argument odejmowania
 *                                                                           
 *  Warunki wstepne:
 *    Wek - Obiekt przekazany przez referencje ale nie modyfikowalny
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		Wynik - Obiekt do ktorego zapisany jest wynik odejmowania dwoch wektorow.
 */ 
	Wektor operator - (const Wektor &Wek);




/*                                                                           
 * Przeciazenie  operatora dodawania
 * 					Domniemany argument przekazywany z klasy                                                                                                                         
 *       Wek      - Obiekt klasy Wektor. Drugi argument dodawania
 *                                                                           
 *  Warunki wstepne:
 *    Wek - Obiekt przekazany przez referencje ale nie modyfikowalny
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		Wynik - Obiekt do ktorego zapisany jest wynik dodawania dwoch wektorow.
 */ 	
	Wektor operator + (const Wektor &Wek);




/*                                                                           
 * Metoda umozliwiajaca Obliczenie dlugosci wektora
 *
 * 		Domniemany argument przekazywany z klasy                                                                                                                         
 * 
 *                                                                           
 *  Warunki wstepne:
 *    Brak
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		sqrt(wynik) - Dlugosc Wektora
 */ 	
	double DlugoscWektora();
};



/*                                                                           
 * Przeciazenie  strumienia pozwalajace na wczytanie Wektora Wek ze strumienia Strm
 *                                                                                                    
 *  	 Strm     - Strumien wejsciowy                         
 *       Wek      - Obiekt klasy Wektor. Do tego obiektu zostana wczytane wartosci
 *                                                                           
 *  Warunki wstepne:
 *    Strm - Strumien przekazany przez referencje
 *    Wek - Obiekt przekazany przez referencje
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		Strm     - Strumien wejsciowy
 */ 

istream& operator >> (istream &Strm, Wektor &Wek);


/*                                                                           
 * Przeciazenie  strumienia pozwalajace na wyswietlenie Wektora Wek na strumien Strm
 * Wyswietla na 16 miejscach i z 10 miejscami po przecinku                                                                                                  
 *  	 Strm     - Strumien wyjsciowy                         
 *       Wek      - Obiekt klasy Wektor. Z tego zostana pobrane wartosci i wrzucone na strumien
 *                                                                           
 *  Warunki wstepne:
 *    Strm - Strumien przekazany przez referencje
 *    Wek - Obiekt przekazany przez referencje ale niemodyfikowalny
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		Strm      -Strumien wyjsciowy
 */ 

ostream& operator << (ostream &Strm, const Wektor &Wek);


#endif
