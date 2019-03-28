#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class T>
void quicksort(T* tablica, int lewy, int prawy)
{
	int i = lewy, j = prawy; //i na pierwszy element tab, j na ostatni
	T pivot = tablica[(lewy + prawy) / 2]; //pivot ustawiony na œrodek tablicy

	while (i <= j) //dopóki indeks lewy<prawy
	{
		while (tablica[i] < pivot) //poruszanie siê od lewej strony
		{
			i++;
		}

		while (tablica[j] > pivot) //poruszanie od prawej
		{
			j--;
		}
		/*Jeœli liczniki ,i' i ,j' siê nie minê³y a stoj¹ po niew³aœciwej stronie tablicy,
		tzn. po lewej liczba wiêksza od pivot , po lewej mniejsza to nastêpuje zamiania*/
		if (i <= j)
		{
			T pomocnicza = tablica[i];

			tablica[i] = tablica[j];
			tablica[j] = pomocnicza;

			i++;
			j--;
		}
	}

	if (lewy < j) quicksort(tablica, lewy, j); //sortowanie osobno tablicy po lewej stronie pivota

	if (prawy > i) quicksort(tablica, i, prawy);//sortowanie osobno tablicy po prawej stronie pivota
}

#endif
