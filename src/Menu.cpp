/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#include "Menu.h"


Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

int Menu::checkInput(){
	int  menuChoice = 0;
	bool bad = false;
	cin >> menuChoice;
	bad = cin.fail();
	if(bad){
		menuChoice = 220;
	}
	cin.clear();
	cin.ignore();
	return menuChoice;
}

void Menu::showUserMenu(Warehouse *apteka, User *user){
		int  menuChoice = 0;
		MenuOptions menuOptions;
		cout << "Witamy w apteka management soft" <<endl << endl;

		do
		{
			system("cls");
			cout << "--------------------Pomyslnie zalogowano jako ";
			if(user->status == 1)
				cout << "administator ";
			else
				cout << "uzytkownik ";
			cout << "--------------------" << endl;
			cout << "                Login: " << user->loginFromFile << "   Imie: " << user->name << "   Nazwisko: "
				 << user->surname << endl;
			cout << "-------------------------------------------------------------------------------" << endl;


			cout << "Dostepne opcje wyboru" << endl;
			cout << "1) Stworz produkt" << endl;
			cout << "2) Wygeneruj zamowienie produktow "<< endl;
			cout << "3) Pokaz stan magazynowy "<< endl;
			cout << "4) Usun produkt"<< endl;
			cout << "5) Edycja danych produktow "<< endl;
			cout << "6) Wyswietl szczegolowe dane produktu"<< endl;
			cout << "7) Przeszukaj baze produktow" << endl;
			cout << "8) Pokaz towary o niskim stanie magazynowym" << endl;
			cout << "9) Sprzedaz produktu" << endl;
			cout << "10) EXIT" << endl;

			cout << "\nNarzedzia administratora: " << endl;
			if(user->status == 1)
			{
				cout << "11) Dodaj nowego uzytkownika" << endl;
				cout << "12) Usun uzytkownika" << endl;
			}
			cout << "\nWybierz opcje: ";
			menuChoice = checkInput();

			switch (menuChoice)
			{
				case 1://Dodaj nowy produkt do magazynu
					/*
					 * TODO - Dodanie zupelnie nowego produktu
					 */
					apteka->addProduct();
					break;
				case 2: //Opcja do rozszerzenia o uzupelnienie magazynu
				{
					apteka->orderProducts();
					break;
				}
				case 3: // Wypisywanie wszystkich produktow
				{
					system("cls");
					cout << " Wszystkie zaindeksowane produkty:" << endl;
					apteka->showAllProducts();
					cout << endl;
					system("Pause");
					cout << endl;
					cout << "Czy chcesz wyswietlic szczegoly jakiegos produktu? T/N :";
					if (menuOptions.choiceConfirmation()){
						menuOptions.showProductDetailsOption(apteka, 0);
					}
					break;
				}
				case 4: // Kasowanie produktu
				{
					menuOptions.eraseProductOption(apteka);
					break;
				}
				case 5: //Zmien dane produktu
					menuOptions.editSubmenuOptions(apteka);
					break;
				case 6: //Wyswietl pe³ne informacje na temat danego produktu + d³ugi opis,
					menuOptions.showProductDetailsOption(apteka, 1);
					break;
				case 7 : // Przeszukiwanie bazy produktów
					menuOptions.searchOption(apteka, 1);
					break;
				case 8:
					system("cls");
					int quantity;
					cout << "Podaj ponizej jakiej wartosci chcesz wyswietlic produkty:";
					cin >> quantity;
					apteka->showProductsLowQuantity(quantity);
					cout << endl;
					system("Pause");
					break;
				case 9:
				{
					system("cls");
					SalesMenu sm(apteka);
					sm.showSalesMenu();
					break;
				}
				case 10:
					cout << "Zakonczenie dzialnia programu" << endl;
					system("Pause");
					break;
				case 11:
					if(user->status == 1)
						user->AddNewUser();
					else
						cout << "Niepoprawne dane" << endl;
					break;
				case 12:
					if(user->status == 1)
					{
						system("cls");
						if(user->DeleteUser() == true)
							cout << "Pomyslnie usunieto uzytkwnika!" << endl;
						else
							cout << "Usuniecie uzytkownika nie powiodlo sie!" << endl;
					}
					else
					{
						cout << "Niepoprawne dane" << endl;
					}
					break;
				default:
				{
					cout << "Niepoprawne dane" << endl;
					break;
				}
			}

		}while(menuChoice != 10);
}
