#ifndef MERGESORT_H
#define MERGESORT_H

template <class T>
void merge(T* tablica, int lewy, int srodek, int prawy)
{
	int i = lewy, w = srodek + 1;
	int k = 0;
	T* pomocnicze = new T[prawy - lewy + 1];

	while (i <= srodek && w <= prawy)
	{
		if (tablica[i] <= tablica[w])
		{
			pomocnicze[k++] = tablica[i++];
		}
		else
		{
			pomocnicze[k++] = tablica[w++];
		}
	}

	while (i <= srodek)
	{
		pomocnicze[k++] = tablica[i++];
	}

	while (w <= prawy)
	{
		pomocnicze[k++] = tablica[w++];
	}

	for (k = 0, i = lewy; i <= prawy; ++i, ++k)
	{
		tablica[i] = pomocnicze[k];
	}

	delete[]pomocnicze;
}

template <class T>
void mergesort(T* tablica, int lewy, int prawy)
{
	int srodek;

	if (lewy < prawy)
	{
		srodek = (lewy + prawy) >> 1;

		mergesort(tablica, lewy, srodek);
		mergesort(tablica, srodek + 1, prawy);
		merge(tablica, lewy, srodek, prawy);
	}
}

#endif

