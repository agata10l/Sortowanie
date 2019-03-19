#ifndef INTROSPECTIVE_H
#define INTROSPECTIVE_H

#include <cmath>

         


template <class T>
void zamien_miejscami(T* tablica, int element1, int element2)
{
	T pomocnicze = tablica[element1];

	tablica[element1] = tablica[element2];
	tablica[element2] = pomocnicze;
}
template <class T>
void sterta(T* tablica, int rozmiar, int i)
{
	int j;

	while (i <= rozmiar / 2)
	{
		j = i * 2;

		if (j + 1 <= rozmiar && tablica[j] < tablica[j + 1])
		{
			++j;
		}

		if (tablica[i] < tablica[j])
		{
			zamien_miejscami(tablica, i, j);
		}
		else
		{
			break;
		}

		i = j;
	}
}
template <class T>
void heapsort(T* tablica, int rozmiar)
{
	for (int i = rozmiar / 2; i > 0; --i)
	{
		sterta(tablica - 1, rozmiar, i);
	}

	for (int i = rozmiar - 1; i > 0; --i)
	{
		zamien_miejscami(tablica, 0, i);
		sterta(tablica - 1, i, 1);
	}
}
template <class T>
int podziel(T* tablica, int lewy, int prawy)
{
	if (prawy >= 3)
	{
		if (tablica[++lewy - 1] > tablica[--prawy])
		{
			zamien_miejscami(tablica, lewy - 1, prawy);
		}
		if (tablica[lewy - 1] > tablica[prawy / 2])
		{
			zamien_miejscami(tablica, lewy - 1, prawy / 2);
		}
		if (tablica[prawy / 2] > tablica[prawy])
		{
			zamien_miejscami(tablica, prawy / 2, prawy);
		}

		zamien_miejscami(tablica, prawy / 2, prawy - 1);
	}

	int i = lewy, j = prawy - 2;

	do
	{
		while (tablica[i] < tablica[prawy - 1])
		{
			++i;
		}
		while (j >= lewy && tablica[j] > tablica[prawy - 1])
		{
			--j;
		}

		if (i < j)
		{
			zamien_miejscami(tablica, i++, j--);
		}
	} while (i < j);

	zamien_miejscami(tablica, i, prawy - 1);

	return i;
}
template <class T>
void introsort(T* tablica, int rozmiar, int glebokosc)
{
	if (glebokosc <= 0)
	{
		heapsort(tablica, rozmiar);
		return;
	}

	int i = podziel(tablica, 0, rozmiar);

	if (i > 9)
	{
		introsort(tablica, i, glebokosc - 1);
	}
	if (rozmiar - i - 1 > 9)
	{
		introsort(tablica + i + 1, rozmiar - i - 1, glebokosc - 1);
	}
}
template <class T>
void insertsort(T *tablica, int rozmiar)
{
	for (int i = 1; i < rozmiar; ++i)
	{
		int j = i - 1;
		T pomocnicze = tablica[i];

		while (j >= 0 && tablica[j] > pomocnicze)
		{
			tablica[j + 1] = tablica[j--];
		}

		tablica[j + 1] = pomocnicze;
	}
}
template <class T>
void introspective(T* tablica, int rozmiar)
{
	introsort(tablica, rozmiar, (int)floor(log(rozmiar) / 0.693147));
	insertsort(tablica, rozmiar);
}

#endif
