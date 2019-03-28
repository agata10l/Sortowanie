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
/*Szablon budowy kopca dla algorytmu Heapsort*/
template <class T>
void kopiec(T* tablica, int rozmiar, int i)	//i-rodzic
{
	int j;

	while (i <= rozmiar / 2)
	{
		j = i * 2;

		if (j + 1 <= rozmiar && tablica[j] < tablica[j + 1]) 
		{
			++j;
		}

		if (tablica[i] < tablica[j])	//jesli rodzic < od dziecka nast�puje zamiana
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
/*Sortowanie przez kopcowanie*/
template <class T>
void heapsort(T* tablica, int rozmiar)
{
	for (int i = rozmiar / 2; i > 0; --i)	//tworzenie kopca
	{
		kopiec(tablica - 1, rozmiar, i);
	}

	for (int i = rozmiar - 1; i > 0; --i)
	{
		zamien_miejscami(tablica, 0, i);	//przeniesienie rodzica na koniec kopca
		kopiec(tablica - 1, i, 1);
	}
}
/*Kod "podziel" jest taki sam jak dla sortowania szybkiego*/
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
/*Okre�la maks. g��boko�� wywo�a� rekurencyjnych,
ze wzgl�du na g��boko�� wywo�ywany jest odpowiedni algorytm*/
template <class T>
void introsort(T* tablica, int rozmiar, int glebokosc)
{
	if (glebokosc <= 0)
	{
		heapsort(tablica, rozmiar);
		return;
	}

	int i = podziel(tablica, 0, rozmiar);	//9 -og�lnie przzyj�ta min. warto�� tablicy

	if (i > 9)
	{
		introsort(tablica, i, glebokosc - 1);	//maks. g��boko�� rekurencyjnych wywo�a� kolejengo poziomu b�dzie o 1 mniejsza
	}
	if (rozmiar - i - 1 > 9)
	{
		introsort(tablica + i + 1, rozmiar - i - 1, glebokosc - 1);
	}
}
/*Sortowanie przez wstawianie*/
template <class T>
void insertsort(T *tablica, int rozmiar)
{
	for (int i = 1; i < rozmiar; ++i)
	{
		int j = i - 1;
		T pomocnicze = tablica[i]; //zapami�tywana warto�� elemntu wi�kszego o 1 od iteracji

		while (j >= 0 && tablica[j] > pomocnicze) //dop�ki nie dojdzie do pocz�tku tablicy i obecny element mniejszy od poprzedzaj�cego
		{
			tablica[j + 1] = tablica[j--]; //do obecnego nadpisujemy poprzedni� warto��
		}

		tablica[j + 1] = pomocnicze; //do poprzedniego nadpisujemy obecn� warto��
	}
}
template <class T>
void introspective(T* tablica, int rozmiar)
{
	introsort(tablica, rozmiar, (int)floor(log(rozmiar) / 0.693147));
	insertsort(tablica, rozmiar);
}

#endif
