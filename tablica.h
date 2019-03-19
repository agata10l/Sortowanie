#ifndef TABLICA_H
#define TABLICA_H
#include<iostream>

template<class T>
T* generuj_tablice(int rozmiar)
{
	T* wsk = new T[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		wsk[i] = rand();
	}
	return wsk;
}

template<class T>
void wyswietl_tablice(T* wsk, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		std::cout << wsk[i] << std::endl;
	}
}

template<class T>
void odwroc_tablice(T* wsk, int rozmiar)
{
	double pomocnicza;
	for (int i = 0; i < rozmiar/2; i++)
	{
		pomocnicza = wsk[rozmiar - i - 1];
		wsk[rozmiar - i - 1] = wsk[i];
		wsk[i] = pomocnicza;
	}
}


#endif
