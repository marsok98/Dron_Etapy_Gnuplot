#ifndef FUNKCJEDOMENU_HH
#define FUNKCJEDOMENU_HH
#include "Prostopadloscian.hh"
#include <fstream>
#include <iostream>
#include <iomanip>


/*!
 * \file  FunkcjeDoMenu.hh
 *  
 *  Plik zawiera naglowki funkcji ktore sluza wczytywaniu danych oraz zapisu 
 */



/*!
 * \brief Funkcja zapisująca wspolrzedne Prostopadloscianu do pliku
 *
 * Zapis wspolrzednych  do pliku z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 20 miejsca po przecinku.
 * \param[in] Pr - Prostopadloscian ktorego chcemy zapisac do pliku
 * \param[in] sNazwaPliku - Nazwa pliku do ktorego chcemy zapisac dane
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool ZapisDoPliku(const Prostopadloscian &Pr, const char  *sNazwaPliku);



/*!
* \brief Funkcja wyswietlajaca menu na cout
*/
	
void WyswietlMenu();


/*!
 * \brief Funkcja oblugujaca Inicjalizacje Prostopadloscianu w menu
 *
 * Funkcja wczytuje wartosci ze strumienia wejsciowego oraz inicjuje
 * obiekt klasy Prostopadloscian poprzez dlugosc,szerokosc,wysokosc
 * \return Zwraca Prostopadloscian ktory zostal zainicjowany
 */

Prostopadloscian Wczytaj_Dane_Inicjuj_Prostopadloscian();



/*!
 * \brief Funkcja wczytujaca sekwencje obrotow wedlug osi
 *
 * Funkcja wczytujaca sekwencje obrotow ze strumienia wejsciowego
 * Dane sa formatu : < os obrotu [spacja] kat o ktory ma obracac>
 * Mozliwe sa do wpisania 3 osie x,y,z
 * Funkcje umozliwia skladanie osi i tworzenie jednej macierzy obrotu
 * \return Zwraca koncowa Macierz Obrotu ktora zostala zainicjowana
 */

Macierz3x3 Wczytaj_Sekwencje_Zwroc_Macierz_Obrotu();




/*!
 * \brief Funkcja pozwalajaca na wczytanie sprawdzenie zapisanie liczby ze strumienia Strm 
 *
 * Dane zapisuje do zmiennej typu double
 * Funkcja posiada zabezpieczenie przed wpisaniem czegos innego niz liczba typu int
 * \param[in] Strm - Strumien wejsciowy
 * \param[in] liczba - zmienna do ktorej zapisuje poprawnie wczytana liczbe
 * \retval true - gdy operacja wczytania powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool wczytaj_sprawdz_zapisz_liczbe(istream &Strm, double &liczba);


/*!
 * \brief Funkcja pozwalajaca na wczytanie sprawdzenie zapisanie liczby ze strumienia Strm 
 *
 * Dane zapisuje do zmiennej typu int
 * Funkcja posiada zabezpieczenie przed wpisaniem czegos innego niz liczba typu int
 * \param[in] Strm - Strumien wejsciowy
 * \param[in] liczba - zmienna do ktorej zapisuje poprawnie wczytana liczbe
 * \retval true - gdy operacja wczytania powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool wczytaj_sprawdz_zapisz_liczbe(istream &Strm, int &liczba);



/*!
 * \brief Funkcja pozwalajaca na wczytanie sprawdzenie zapisanie znaku ze strumienia Strm
 *
 * Dane zapisuje do zmiennej typu char
 * Funkcja posiada zabezpieczenie przez wpisaniem czegos innego niz znak
 * \param[in] Strm - Strumien wejsciowy
 * \param[in] znak - zmienna do ktorej zapisuje poprawnie wczytany znak
 * \retval true - gdy operacja wczytania powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool wczytaj_sprawdz_zapisz_znak(istream &Strm, char &znak);




























#endif