#ifndef FUNKCJEDOMENU_HH
#define FUNKCJEDOMENU_HH
#include "Prostokat.hh"
#include <fstream>
#include <iostream>
#include <iomanip>

/*                                                                           
 * Metoda umozliwiajaca Zapis do pliku wierzcholkow  obiektu klasy Prostokat
 * Nie mylic z przeciazeniem. Ta funkcja otwiera plik, jak i rowniez dopisuje 1 wierzcholek rowniez na koncu
 * Wyswietla z 20 miejscami po przecinku                                
 *       Pr      - Obiekt klasy Prostokat. Z tego zostana pobrane wartosci i wrzucone do pliku
 *       sNazwaPliku - nazwa pliku
 *                                                                           
 *  Warunki wstepne:
 *    
 *    Pr- Obiekt przekazany przez referencje ale niemodyfikowalny
 *    sNazwaPliku nie moze byc wskaznikiem pustym
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		Jesli wszystko sie powiedzie to true
 *		Jesli plik nie zostanie otwarty to false
 * 
 */
bool ZapisDoPliku(const Prostokat Pr, const char  *sNazwaPliku);



/*                                                                           
 * Metoda umozliwiajaca Wyswietlenie Menu dla uzytkownika                                                                                                                      
 * 
 *                                                                           
 *  Warunki wstepne:
 *    Brak
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		brak
 */ 	
void WyswietlMenu();




/*                                                                           
 * Funkcja pozwalajaca na wczytanie sprawdzenie zapisanie liczby ze strumienia Strm 
 *                                                                                                    
 *  	 Strm     - Strumien wejsciowy                         
 *       liczba    Do tej zmiennej zostana wczytane wartosci
 *                                                                           
 *  Warunki wstepne:
 *    Strm - Strumien przekazany przez referencje
 *    liczba - zmienna modyfikowalna
 * 
 *  Warunki koncowe:
 *     brak
 *
 *  Zwracane wartosci:
 *		true jesli wczytana zmienna jest liczba
 		false jesli wczytana zmienna nie jest liczba
 */ 

bool wczytaj_sprawdz_zapisz_liczbe(istream &Strm, double &liczba);

bool wczytaj_sprawdz_zapisz_liczbe(istream &Strm, int &liczba);
























#endif