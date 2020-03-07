#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#include "Wektor2D.hh"
#define PI 3.14//159265359

#include <iostream>


/*
 *  Klasa modeluje pojecie Macierzy. Macierz to dwuelementowa tablica Wektorow
 *  Zapewnia przeciazenia operatorow indeksowania i mnożenia macierzy przez wektor
 *  Zawiera metode Inicjalizujaca Macierz.
 */
class Macierz2x2 {

	  Wektor Macierz[ROZMIAR];
	  double kat_w_rad;
public:
/*
    Przeciazenie operatora indeksowania
    Możemy modyfikować wartosc
*/
  	Wektor operator [] (int i) const {return Macierz[i];}



/*
  Przeciazenie operatora indeksowania
  Nie możemy modyfikować wartosci const na koncu oznacza ze nie zmienia stanu klasy
*/
  	Wektor &operator [] (int i) {return Macierz[i];}






/*                                                                           
 * Metoda umozliwiajaca zainicjowanie Macierzy
 * Macierz będzie zawierać na odpowiednich polach funkcje trygonometryczne
 * Po zainicjowaniu będzie to Macierz która przemnożona przez Wektor
 * Umozliwi nam to przesuniecie o kat wzgledem poczatku ukladu wspolrzednych 
 *
 *    kat - kat w stopniach przekazywany do metody                                                                                                                         
 * 
 *                                                                           
 *  Warunki wstepne:
 *    kat musi byc zmienna typu double
 * 
 *  Warunki koncowe:
 *     kat zostaje przekonwertowany do radianow i zapisany w zmiennej kat_w_rad
 *
 *  Zwracane wartosci:
 *    brak
 */   
    void InicjalizujMacierz(double kat);








/*                                                                           
 * Przeciazenie  operatora mnozenia
 *          Domniemany argument przekazywany z klasy                                                                                                                         
 *       Wek      - Obiekt klasy Wektor. Drugi argument odejmowania
 *                                                                           
 *  Warunki wstepne:
 *    Wek - Obiekt przekazany przez referencje ale nie modyfikowalny
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *    Wynik - Obiekt do ktorego zapisany jest wynik mnozenia Macierzy i Wektora Wek
 */ 
  	Wektor operator * (const Wektor &Wek);
};


#endif
