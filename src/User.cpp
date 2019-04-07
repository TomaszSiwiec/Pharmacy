/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */


#include "User.h"
#include <iostream>
#include <cstdlib>
#include <fstream>


fstream plik_, plik1, plik2;
int miejsce;

User::User()
{

}

User::~User() {
	// TODO Auto-generated destructor stub
}

bool User::FindUser(string log)//sprawdzanie czy uzytkownik o takim loginie istnieje
{

	string tmp;
	int a;
	line = 0;
	userData = "";
	plik_.open("src/dane.txt", ios::in);
	while(!plik_.eof())
	{
		line++;
		loginFromFile = "";
		tmp = "";
		getline(plik_, tmp);
		a = tmp.find("|");
		for(int i = 0; i < a; i++)
		{
			loginFromFile += tmp[i];
		}

		if(loginFromFile == log)
		{
			userData = tmp;
			plik_.close();
			return true;
			break;
		}
		else
		{
			if(plik_.eof())
			{
				plik_.close();
				return false;
			}
		}

	}

	plik_.close();
}

bool User::ConverterStringToBool(string txt)//konwersja zmiennej typu string do bool
{
	if(txt == "1" || txt == "true")
		return true;
	else
		return false;
}

void User::DownloadingDataFromFile() //pobieranie danych z pliku do zmiennych w klasie
{
	plik_.close();
	string tmp;
	int a;
	plik_.open("src/dane.txt", ios::in);


	for(int i = 0; i < line; i++)
	{
		tmp = "";
		getline( plik_, tmp );
	}


	for(int i = 0; i < amountDataToLoad; i++)
	{
		switch(i)
		{
		case 0:
			a = tmp.find("|");
			tmp.erase(0, loginFromFile.length()+1);
			break;
		case 1:
			a = tmp.find("|");
			for(int j = 0; j < a; j++)
			{
				passwordFromFile += tmp[j];
			}
			tmp.erase(0, passwordFromFile.length()+1);
			break;
		case 2:
			a = tmp.find("|");
			for(int j = 0; j < a; j++)
			{
				name += tmp[j];
			}
			tmp.erase(0, name.length()+1);
			break;
		case 3:
			a = tmp.find("|");
			for(int j = 0; j < a; j++)
			{
				surname += tmp[j];
			}
			tmp.erase(0, surname.length()+1);
			break;
		case 4:
			status = ConverterStringToBool(tmp);
			break;
		default:
			cout << "Wystapil blad podczas ladowania danych!" << endl;
			break;
		}
	}

	plik_.close();
}

void User::AddNewUser() // dodawanie nowego uzytkownika
{
	string tmp;
	system("cls");
	cout << "Dodaj nowego uzytkownika!" << endl;

		do
		{
		cout << "Login: ";
		cin >> temporary[0];
		if(FindUser(temporary[0]))
			cout << "Uzytkownik o takim loginie juz istanieje!" << endl;
		}while(FindUser(temporary[0]));

		do
		{
			cout << "Haslo: ";
			cin >> temporary[1];
			if(temporary[1].length() < 3 ||temporary[1].length() > 32)
			{
				cout << "Haslo musi zawierac od 3 do 32 znakow!" << endl;
			}
		}while(temporary[1].length() < 3 ||temporary[1].length() > 32);

		cout << "Imie: ";
		cin >> temporary[2];

		cout << "Nazwisko: ";
		cin >> temporary[3];

		while(true)
		{
		cout << "Status (1 jesli administator lub 0 jeœli uzytkownik): ";
		cin >> temporary[4];

		if(temporary[4] == "1")
			break;

		if(temporary[4] == "0")
					break;

		}

	plik_.open("src/dane.txt", ios::app);
	if(plik_.good())//sprawdzamy czy plik istnieje
	{
	tmp = temporary[0] + "|" + temporary[1] + "|" + temporary[2] + "|" + temporary[3] + "|" + temporary[4];
	plik_ << tmp << endl;
	cout << "Poprawnie zapisano dane!" << endl;
	}
	else
		cout << "Wystapil blad podczas zapisywania danych!" << endl;
	plik_.close();
	system("pause");
}

int User::DataValue()
{
	int i = 0;
	string linia;
	plik_.open("src/dane.txt", ios::in);
	while(getline(plik_, linia))
		i++;

	plik_.close();
	return i;
}

bool User::DeleteUser()
{
	int i = 0;
	int rozmiar = DataValue() + 2;
	string tmp, userToDelete;
	cout << "Wprowadz login uzytkownika ktorego chcesz usunac: ";
	cin >> userToDelete;
	plik2.open("src/dane.txt", ios::in | ios::out);
	if(plik2.good())
	{
		if(FindUser(userToDelete))
		{
			cout << rozmiar << endl;
			string *b = new string [rozmiar];
			i = 0;
			while(!plik2.eof())
			{
				tmp = "";
				i++;
				getline(plik2, tmp);
				if(tmp != userData)
					b[i-1] = tmp;

				cout << b[i-1] << endl;
			}

			plik2.close();
			plik2.open("src/dane.txt", ios::trunc);
			plik2.close();
			remove("src/dane.txt");
			plik2.open("src/dane.txt", ios::out);
			for(int j = 0; j < rozmiar - 1; j++)
			{
				if(j == line-1)
					continue;
				plik2 << b[j] << endl;
			}
			plik2.close();
			delete[] b;
			system("cls");
			cout << "Usuniecie uzytkownika " << userToDelete << " powiodlo sie" << endl;
			system("pause");
			return true;
		}
		else
		{
			cout << "Brak uzytkownika o takiej nazwie!" << endl;
			plik2.close();
			system("pause");
			return false;
		}
	}
	else
	{
		cout << "Nie mozna otworzyc pliku dane.txt" << endl;
		plik2.close();
		system("pause");
		return false;
	}
}
