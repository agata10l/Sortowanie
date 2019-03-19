#ifndef SORTOWANIE_H
#define SORTOWANIE_H
#include<chrono>
#include "quicksort.h"
#include "mergesort.h"
#include "introspective.h"


enum ktory_algorytm_t
{
	QUICKSORT = 0,
	MERGESORT,
	INTROSPECTIVE,
};

struct wynik_sortowania_t
{
	double czas;
	bool poprawnie;
};

template<class T>
bool czy_posortowane(T* wsk, int rozmiar)
{
	for (int i = 0; i < rozmiar - 1; i++)
	{
		if (wsk[i] > wsk[i + 1])
		{
			return false;
		}
	}
	return true;
}

template<class T>
wynik_sortowania_t sortuj(T* wsk, int rozmiar, ktory_algorytm_t numer)
{
	wynik_sortowania_t wynik;
	auto start = std::chrono::high_resolution_clock::now();
	
	switch (numer)
	{
	case QUICKSORT:
		quicksort(wsk, 0, rozmiar - 1);
		break;
	case MERGESORT:
		mergesort(wsk, 0, rozmiar - 1);
		break;
	case INTROSPECTIVE:
		introspective(wsk, rozmiar);
		break;
	}
	auto koniec = std::chrono::high_resolution_clock::now();
	wynik.czas= std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - start).count()/1000000.0;
	wynik.poprawnie = czy_posortowane(wsk, rozmiar);
	return wynik;

}
#endif