#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class T>
void quicksort(T* tablica, int lewy, int prawy)
{
	int i = lewy, j = prawy;
	T pivot = tablica[(lewy + prawy) / 2];

	while (i <= j)
	{
		while (tablica[i] < pivot)
		{
			i++;
		}

		while (tablica[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			T pomocnicza = tablica[i];

			tablica[i] = tablica[j];
			tablica[j] = pomocnicza;

			i++;
			j--;
		}
	}

	if (lewy < j) quicksort(tablica, lewy, j);

	if (prawy > i) quicksort(tablica, i, prawy);
}

#endif
