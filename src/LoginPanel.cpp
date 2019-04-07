/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#include "LoginPanel.h"

LoginPanel::LoginPanel() {
	// TODO Auto-generated constructor stub

}

LoginPanel::~LoginPanel() {
	// TODO Auto-generated destructor stub
}

void LoginPanel::ShowLoggingPanel(User *u1)
{
	char a;
	start:

	if(IfExist() == true)
	{
		//jeœli znajdzie plik z danymi do logowania
		cout << "Witamy w apteka management soft" <<endl << endl;
		cout << "Wprowadz dane do logowania! \n\nLogin: ";
		cin >> u1->enteredLogin;
		cout << "Haslo: ";
		cin >> u1->enteredPassword;

		if(u1->FindUser(u1->enteredLogin) == true)
		{
			//jeœli znajdzie u¿ytkownika o takim loginie
			u1->DownloadingDataFromFile(); //pobieramy dane z pliku (haslo, imie, nazwisko)
			cout << endl << "Znaleziono uzytkownika o loginie " << u1->loginFromFile << endl << endl;
			if(u1->enteredPassword == u1->passwordFromFile)
			{
				cout << "-----------------------------------------------" << endl;
				cout << "Pomyslnie zalogowano jako ";
				if(u1->status == true)
				{
					cout << "administrator";
				}
				else
				{
					cout << "uzytkownik";
				}

				cout << " " << u1->name << " " << u1->surname << endl;
				cout << "-----------------------------------------------" << endl;
				u1->logged = true;
				system("pause");
				//return u1;
			}
			else
			{
				cout << "Bledne haslo!" << endl;
				cout << "Czy chcesz sprobowac zalogowac siê ponownie? (y/n)" << endl;
				cin >> a;

				if(a == 'y' || a == 'Y')
					goto start;
				if(a =='n')
					system("pause");
					//return u1;
			}

		}
		else
		{
			//je¿eli nie znajdzie u¿ytkownika o takim loginie
			cout << "Brak uzytkownika o loginie: " << u1->enteredLogin << endl;
			cout << "Czy chcesz sprobowac zalogowac siê ponownie? (y/n)" << endl;
			cin >> a;

			if(a == 'y' || a == 'Y')
				goto start;
			if(a =='n')
				system("pause");
				//return u1;
		}

	}
	else
	{
		//jeœli nie znajdzie pliku z danymi do logowania
		cout << "Nie znaleziono pliku. Logowanie jest niemozliwe!" << endl;
		cout << "Czy chcesz dodac nowego uzytkownika aby utworzyc plik?(y/n)" << endl;
		cin >> a;
		if(a == 'y' || a == 'Y')
		{
			u1->AddNewUser();
			system("cls");
			goto start;
		}
	}
}


bool LoginPanel::IfExist()//funkcja sprawdza czy plik istnieje
{
	fstream plik;
	plik.open("src/dane.txt", ios::in);

	if(plik.good()){
		plik.close();
		return true;
	}else{
		plik.close();
		return false;
	}

}
