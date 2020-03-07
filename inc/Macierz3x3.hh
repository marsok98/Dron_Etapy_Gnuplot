#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>

#include "Macierz.hh"




/*!
 * \file  Macierz3x3.hh
 *  
 *  Plik zawiera instancje szablonu Macierz - Klasa Macierz3x3
 *  oraz funkcje obslugujace te klase
 */







/*!
 * \brief Klasa Macierz3x3 jest instancją szablonu Macierz
 *
 *  Klasa Macierz inicjuje  Macierz3x3 bedącą szablonem wywolana z wartoscia 3
 */
typedef Macierz<3>  Macierz3x3;



/*!
 * \brief Przeciazenie operatora mnozenia dla dwoch obiektow klasy Macierz3x3
 *
 * Funkcja przeciaza operator mnozenia, realizuje mnozenie oraz zwraca Macierz wynikowa
 * \param[in] MacierzA - Macierz z lewej strony znaku mnozenia
 * \param[in] MacierzB - Macierz z prawej strony znaku mnozenia
 * \return Macierz3x3 wyniku
 */
Macierz3x3 operator * (const Macierz3x3 &MacierzA ,const Macierz3x3 &MacierzB);

/*!
 * \brief Inicjalizuje Macierz3x3 obrotu w zaleznosci od osi i katu
 *
 * Funkcja Inicjalizuje Macierz3x3 ktora jest potrzebna do obracania obiektu trojwymiarowego
 * wzgledem osi x,y albo z oraz o kat podawany w stopniach
 * \param[in] axis os wedlug ktorej chcemy tworzyc macierz
 * \param[in] kat kat dzieki ktoremu chcemy stworzyc macierz
 * \return Macierz3x3 ktora jest wynikiem odpowiednich podstawien
 */
Macierz3x3 InicjalizujMacierz_obrotu(char axis,double kat);









/*
 * \brief Inicjalizuje Macierz3x3 ktora ma byc jednostkowa
 *
 * Funkcja Inicjalizuje Macierz3x3 ktora jest do mnozenia
 * Korzystamy z faktu ze dowolna macierz przemnozona przez macierz jednostkowa 
 * nadal pozostaje ta sama Macierza
 * \return Macierz3x3 ktora jest macierza jednostkowa
 */
//Macierz3x3 InicjalizujMacierz_jednostkowa();

#endif
