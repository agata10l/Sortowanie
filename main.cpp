#include<iostream>
#include<fstream>
#include<string>
#include "tablica.h"
#include "sortowanie.h"


using namespace std;

int tablica_rozmiary[] = { 10000,50000,100000,500000,1000000 };
double ile_posortowanych_tab[] = { 0,0.25,0.5,0.75,0.95,0.997};


int main()
{
	double czas;
	fstream plik;
	string nazwa;
	//for (int i = 0; i < 3; i++)//algorytm
	//{
	//	nazwa = "algorytm" + to_string(i) + ".txt";
	//	plik.open(nazwa, ios::out);

	//	for (int j = 0; j < 5; j++)//rozmiar tablicy
	//	{
	//		plik << tablica_rozmiary[j] << endl;
	//		for (int g = 0; g < 7; g++)//procent posortowania
	//		{
	//			plik << ile_posortowanych_tab[g]<< endl;
	//			czas = 0;
	//			for (int k = 0; k < 5; k++)// 100-liczba testow
	//			{
	//				system("cls");
	//				int ile_elementow_posortowanych = ile_posortowanych_tab[g] * tablica_rozmiary[j];
	//				cout << "Numer algorytmu: " << i << endl;
	//				cout << "Rozmiar tablicy: " << tablica_rozmiary[j] << endl;
	//				cout << "Procent: " << ile_posortowanych_tab[g] << endl;
	//				cout << "Numer testu: " << k << endl;
	//				cout << "Ile elementow: " << abs(ile_elementow_posortowanych) << endl;
	//				int* wsk = generuj_tablice<int>(tablica_rozmiary[j]);
	//				quicksort<int>(wsk, 0,abs(ile_elementow_posortowanych));
	//				if (ile_elementow_posortowanych < 0)
	//				{
	//					odwroc_tablice<int>(wsk, tablica_rozmiary[j]);
	//				}

	//				czas+=sortuj<int>(wsk, tablica_rozmiary[j], static_cast<ktory_algorytm_t>(i)).czas;
	//				delete[]wsk;
	//				
	//			}
	//			czas /= 5.0;
	//			plik << czas << endl << endl;
	//		}
	//	}
	//}

	for (int i = 0; i < 3; i++)//algorytm
	{
		nazwa = "algorytm" + to_string(i) +"odwrocone" + ".txt";
		plik.open(nazwa, ios::out);

		for (int j = 0; j < 5; j++)//rozmiar tablicy
		{
			plik << tablica_rozmiary[j] << endl;
			
			czas = 0;
			for (int k = 0; k < 5; k++)// 100-liczba testow
			{
				system("cls");
				cout << "Numer algorytmu: " << i << endl;
				cout << "Rozmiar tablicy: " << tablica_rozmiary[j] << endl;
				cout << "Numer testu: " << k << endl;
				int* wsk = generuj_tablice<int>(tablica_rozmiary[j]);
				quicksort<int>(wsk, 0, tablica_rozmiary[j] - 1);
				odwroc_tablice<int>(wsk, tablica_rozmiary[j]);

				czas += sortuj<int>(wsk, tablica_rozmiary[j], static_cast<ktory_algorytm_t>(i)).czas;
				delete[]wsk;

			}
			czas /= 5.0;
			plik << czas << endl << endl;
		}
	}
	

}