#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: obroty_3D
	./obroty_3D

obroty_3D: obj obj/main.o obj/Prostopadloscian.o obj/Macierz3x3.o obj/Wektor3D.o\
           obj/lacze_do_gnuplota.o obj/FunkcjeDoMenu.o
	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor3D.o\
                        obj/Macierz3x3.o obj/Prostopadloscian.o obj/lacze_do_gnuplota.o\
                        obj/FunkcjeDoMenu.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Macierz3x3.hh inc/Macierz.hh\
           inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh\
         inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/FunkcjeDoMenu.o: src/FunkcjeDoMenu.cpp inc/FunkcjeDoMenu.hh
	g++ -c ${CXXFLAGS} -o obj/FunkcjeDoMenu.o src/FunkcjeDoMenu.cpp

clean:
	rm -f obj/*.o obroty_3D
