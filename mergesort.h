#ifndef MERGESORT_H
#define MERGESORT_H

template <class T>
void merge(T* tablica, int lewy, int srodek, int prawy)
{
	int i = lewy, w = srodek + 1; //pocz¹tki podtablic
	int k = 0;
	T* pomocnicze = new T[prawy - lewy + 1]; //tablica wynikowa,przechowuj¹ca kopie podtablic do scalenia

	/*Przechodzi przez obie tablice, dodaje do pomocniczej mniejsz¹ z obu elementów*/
	while (i <= srodek && w <= prawy) //dopóki nie wyczerpi¹ siê elementy jednej z podtablic
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

	while (i <= srodek) //wstawienie wartoœci od i do œrodka w tabelê pomocnicz¹
	{
		pomocnicze[k++] = tablica[i++];
	}

	while (w <= prawy) //wstawienie wartoœci od w do koñca(prawy) w tabelê pomocnicz¹
	{
		pomocnicze[k++] = tablica[w++];
	}

	for (k = 0, i = lewy; i <= prawy; ++i, ++k)
	{
		tablica[i] = pomocnicze[k];		//kopiowanie z powrotem wynikowej tablicy(pomocniczej) do pierwotnej
	}

	delete[]pomocnicze;
}

template <class T>
void mergesort(T* tablica, int lewy, int prawy)
{
	int srodek;

	if (lewy < prawy) //jeœli jest wiêcej ni¿ jeden element
	{
		srodek = (lewy + prawy) >> 1;

		mergesort(tablica, lewy, srodek);
		mergesort(tablica, srodek + 1, prawy);
		merge(tablica, lewy, srodek, prawy);
	}
}

#endif

