#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: Dron
	./Dron

Dron: obj obj/main.o obj/FiguraGeometryczna.o obj/Macierz3x3.o obj/Wektor3D.o\
           obj/lacze_do_gnuplota.o obj/Graniastoslup6.o obj/Prostopadloscian.o obj/Dron.o obj/FunkcjeDoMenu.o
	g++ -Wall -pedantic -std=c++0x -o Dron obj/main.o obj/Wektor3D.o\
                        obj/Macierz3x3.o obj/FiguraGeometryczna.o obj/lacze_do_gnuplota.o\
                        obj/Graniastoslup6.o obj/Prostopadloscian.o obj/Dron.o obj/FunkcjeDoMenu.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/FiguraGeometryczna.hh inc/Macierz3x3.hh inc/Macierz.hh\
           inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/FiguraGeometryczna.o: src/FiguraGeometryczna.cpp inc/FiguraGeometryczna.hh\
         inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/FiguraGeometryczna.o src/FiguraGeometryczna.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/Graniastoslup6.o: src/Graniastoslup6.cpp inc/Graniastoslup6.hh inc/FiguraGeometryczna.hh
	g++ -c ${CXXFLAGS} -o obj/Graniastoslup6.o src/Graniastoslup6.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh inc/FiguraGeometryczna.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh inc/FiguraGeometryczna.hh
	g++ -c ${CXXFLAGS} -o obj/Dron.o src/Dron.cpp

obj/FunkcjeDoMenu.o: src/FunkcjeDoMenu.cpp inc/FunkcjeDoMenu.hh
	g++ -c ${CXXFLAGS} -o obj/FunkcjeDoMenu.o src/FunkcjeDoMenu.cpp

clean:
	rm -f obj/*.o Dron
