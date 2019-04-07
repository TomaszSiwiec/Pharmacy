/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#include "MenuOptions.h"

MenuOptions::MenuOptions() {
	// TODO Auto-generated constructor stub

}

MenuOptions::~MenuOptions() {
	// TODO Auto-generated destructor stub
}


bool MenuOptions::choiceConfirmation(){
	char confirmation;
	cin >> confirmation;
	if(confirmation == 'T' || confirmation == 't' || confirmation == 'y' || confirmation == 'Y'){
		return true;
	}else{
		return false;
	}
}

int MenuOptions::checkInput(int defaultValue){
	int  menuChoice = 0;
	bool bad = false;
	cin >> menuChoice;
	bad = cin.fail();
	if(bad){
		menuChoice = defaultValue;
	}
	cin.clear();
	cin.ignore(10,'\n');
	return menuChoice;
}

float MenuOptions::checkInput(float defaultValue){
	float  menuChoice = 0;
	bool bad = false;
	cin >> menuChoice;
	bad = cin.fail();
	if(bad){
		menuChoice = defaultValue;
	}
	cin.clear();
	cin.ignore(10,'\n');
	return menuChoice;
}

void MenuOptions::eraseProductOption(Warehouse * apteka){
	system("cls");
	cout << "W jaki sposob chcesz usunac produkty?" << endl;
	cout << "1) Poprzez ID produktu" << endl;
	cout << "2) Poprzez Nazwe produktu" << endl;
	cout << "3) Poprzez Kategorie produktu" << endl;
	cout << "4) Anuluj operacje" << endl;
	cout << "Wprowadz wybor: ";
	int eraseChoice = 0;
	eraseChoice = checkInput(5);

		switch(eraseChoice)
		{
			case 1 :
			{
				eraseByID(apteka);
				system("Pause");
				break;
			}
			case 2 :
			{
				eraseByName(apteka);
				system("Pause");
				break;
			}
			case 3 :
			{
				eraseByCategory(apteka);
				system("Pause");
				break;
			}
			case 4 :
				break;
			default :
			{
				cout << "Nieprawidlowa operacja. Przerywam..." << endl;
				system("Pause");
				break;
			}
		}
}

void MenuOptions::eraseByID(Warehouse * apteka){
	cout << "Jaki produkt wg indeksu chcesz skasowac" << endl;
	int index = 0;
	index = checkInput(-1);
	SearchResult searchResult;
	searchResult.populateSearchResultsById(apteka, index);
	if(searchResult.searchResults.size() == 0){
		cout << "Nie ma takiego indeksu" << endl;
		searchResult.showAllProducts();
		cout << "Czy chcesz ponowanie wpisac produkt? T/N ";
		if(choiceConfirmation()){
			eraseByID(apteka);
			return;
		}
		return;
	}
	searchResult.showAllProducts();
	cout << endl;
	cout << "Czy na pewno chcesz skasowac ten produkt? T/N ";
	if(choiceConfirmation()){
		apteka->eraseElementById(index);
		cout << "Produkt wykasowany" << endl;
	}else{
		cout << "Przerywam...";
	}
}

void MenuOptions::eraseByName(Warehouse * apteka){
	cout << "Jaki produkty wg Nazwy chcesz skasowac" << endl;
	string eraseName;
	cin >> eraseName;
	SearchResult searchResult;
	searchResult.populateSearchRusultsByName(apteka, eraseName);
	if(searchResult.searchResults.size() == 0){
		cout << "Brak rezultatow dla takiego rekordu" << endl;
		searchResult.showAllProducts();
		cout << "Czy chcesz ponowic zapytanie? T/N" << endl;
		if(choiceConfirmation()){
			eraseByName(apteka);
			return;
		}else{
			return;
		}
	}else if(searchResult.searchResults.size() > 1){
		cout << "Wiecej niz 1 rezultat dla zapytania" << endl;
		searchResult.showAllProducts();
		cout << "Czy chcesz ponowic zapytanie? T/N" << endl;
		if(choiceConfirmation()){
			eraseByName(apteka);
			return;
		}else{
			return;
		}
	}else if(searchResult.searchResults.size() == 1){
		searchResult.showAllProducts();
		cout << endl << "Czy na pewno chcesz skasowac ten produkt? T/N ";
		if(choiceConfirmation()){
			apteka->eraseElementByName(eraseName);
			cout << "Produkt wykasowany" << endl;
			system("Pause");
		}
	}
}

void MenuOptions::eraseByCategory(Warehouse * apteka){
	SearchResult searchResult;
	searchResult.populateCategoryList(apteka);
	searchResult.showCategoryList();
	cout << "Podaj numer kategorii, ktora chcesz skasowac" << endl;
	int eraseCategory;
	eraseCategory = checkInput(-1);
	if(eraseCategory <= -1 || eraseCategory >= signed(searchResult.categoryList.size())){
		cout << "Nie ma takiego indeksu" << endl;
		searchResult.showAllProducts();
		cout << "Czy chcesz ponowic zapytanie? T/N" << endl;
		if(choiceConfirmation()){
			system("cls");
			eraseByCategory(apteka);
			return;
		}
		return;
	}else{
		string eraseCat = searchResult.populateSearchResultsByCategoryReturnCategoryName(apteka, eraseCategory);
		searchResult.showAllProducts();
		if(searchResult.searchResults.size() >= 1){
			cout << "Czy na pewno chcesz skasowac te produkty? T/N ";
			if(choiceConfirmation()){
				apteka->eraseElementByCategory(eraseCat);
				cout << "Produkty wykasowane" << endl;
			}
		}
	}
}


void MenuOptions::showProductDetailsOption(Warehouse * apteka, int clearScreenFlag){

	if(clearScreenFlag == 1){
		system("cls");
	}
	cout << "W jaki sposob wyswietlic szczegoly produktu?" << endl;
	cout << "1) Poprzez ID produktu" << endl;
	cout << "2) Poprzez Nazwe produktu" << endl;
	cout << "3) Anuluj operacje" << endl;
	cout << "Wprowadz wybor: ";

	int showDetailsChoice = 0;
	showDetailsChoice= checkInput(4);

		switch(showDetailsChoice)
		{
			case 1 :
			{
				showDetailsById(apteka);
				system("Pause");
				break;
			}
			case 2 :
			{
				showDetailsByName(apteka);
				system("Pause");
				break;
			}
			case 3 :
				cout << endl << "Anulowanie..." << endl;
				system("Pause");
				break;
			default :
				cout << "Nieprawidlowa operacja. Przerywam.." << endl;
				system("Pause");
				break;
		}
}

void MenuOptions::showDetailsById(Warehouse *apteka){
	cout << "Podaj ID do pokazania szczeglow" << endl;
	int byIndex = 0;
	byIndex = checkInput(-1);
	SearchResult searchResult;
	searchResult.populateSearchResultsById(apteka, byIndex);
	if(searchResult.searchResults.size() == 0){
		cout << "Brak takiego rekordu w bazie" << endl;
		cout << "Czy chcesz powtorzyc zapytanie? T/N ";
		if(choiceConfirmation()){
			showDetailsById(apteka);
			return;
		}
	}else{
		apteka->showProductDetailsThroughIndex(byIndex);
	}
}

void MenuOptions::showDetailsByName(Warehouse *apteka){
	cout << "Podaj Nazwe dla pokazania szczegolow" << endl;
	string byName;
	cin >> byName;
	SearchResult searchResult;
	searchResult.populateSearchRusultsByName(apteka, byName);
	if(searchResult.searchResults.size() == 0){
		cout << "Brak takiego rekordu w bazie" << endl;
		cout << "Czy chcesz powtorzyc zapytanie? T/N ";
		if(choiceConfirmation()){
			showDetailsByName(apteka);
			return;
		}
		return;
	}else if(searchResult.searchResults.size() == 1){
		int byIndex = -1;
		for(Product p : apteka->availableProducts){
			if(p.getProductName() == byName){
				byIndex = p.getProductNumber();
			}
		}
		apteka->showProductDetailsThroughIndex(byIndex);
	}else if(searchResult.searchResults.size() > 1){
		searchResult.showAllProducts();
		cout << "Czy chcesz powtorzyc zapytanie? T/N ";
		if(choiceConfirmation()){
			showDetailsByName(apteka);
			return;
		}
		return;
	}
}


void MenuOptions::searchOption(Warehouse *apteka, int clearScreenFlag){
	if(clearScreenFlag == 1){
			system("cls");
	}
	cout << "W jaki sposob chcesz przeszukac baze: " << endl;
	cout << "1) Po nazwie produktu" << endl;
	cout << "2) Po kategorii produktu" << endl;
	cout << "3) Po cenie produktu (min/max)" << endl;
	cout << "4) Anuluj " << endl;
	cout << "Wprowadz wybor: ";

	int searchOptionChoice = 0;
	searchOptionChoice = checkInput(-1);

		switch(searchOptionChoice)
		{
			case 1 :
			{
				system("cls");
				nameSearch(apteka);
				break;
			}
			case 2 :
			{
				system("cls");
				categorySearch(apteka);
				break;
			}
			case 3 :
			{
				system("cls");
				priceSearch(apteka);
				break;
			}
			case 4 :
				cout << endl << "Anulowanie..." << endl;
				system("Pause");
				break;
			default :
				cout << "Niepoprawna operacja. Przerywam..." << endl;
				system("Pause");
				break;
		}
}

void MenuOptions::categorySearch(Warehouse * apteka){
	cout << "********** Wyszukiwanie po kategorii produktu **********" << endl;
	cout << "Dostepne kategorie do przeszukania: " << endl << endl;
	SearchResult searchResult;
	searchResult.populateCategoryList(apteka);
	int rangeControl = searchResult.showCategoryList();
	cout<< endl << "Podaj numer kategorii do wyswietelnia: ";
	int categoryNumber;
	categoryNumber = checkInput(-1);
	if(categoryNumber < 0 || categoryNumber > rangeControl){
		cout << "Nie ma takiej kategorii. Przerywam..." << endl;
		system("Pause");
	}else{
		cout << endl;
		searchResult.populateSearchResultsByCategory(apteka, categoryNumber);
		searchResult.showAllProducts();
		cout << endl;
		system("Pause");
	}
}


void MenuOptions::nameSearch(Warehouse * apteka){
	cout << "********** Wyszukiwanie po nazwie produktu **********" << endl;
	cout << "Podaj nazwe produktu do wyszukania" << endl;
	string searchedName;
	cin >> searchedName;
	SearchResult searchResult;
	searchResult.populateSearchRusultsByName(apteka, searchedName);
	searchResult.showAllProducts();
	cout << endl;
	system("Pause");
}

void MenuOptions::priceSearch(Warehouse * apteka){
	cout << "********** Wyszukiwanie po cenie (min/max) **********" << endl;
	cout << "Podaj minimalna wartosc minimalna: ";
	float minValue;
	minValue = checkInput(0);
	cout << "Podaj wartosc maksymalna: ";
	float maxValue;
	maxValue = checkInput(0);
	cout << endl;
	SearchResult searchResult;
	searchResult.populateSearchResultsByPrice(apteka, minValue, maxValue);
	cout << endl;
	system("Pause");
}

void MenuOptions::editSubmenuOptions(Warehouse *apteka){

	char editOptionChoice;

    do {
    	system("cls");
    	cout << "Wybierz co chcesz edytowac : \n" ;
    	cout << "1) Nazwe produktu \n";
    	cout << "2) Kategorie produktu \n";
    	cout << "3) Cene produktu  \n" ;
    	cout << "4) Ilosc sztuk produktu  \n" ;
    	cout << "q. Wyjscie \n ";
    cout << "\n" ;
    cin >> editOptionChoice ;
    cout << "\n";

    switch (editOptionChoice) {
		case '1':
					this->editName(apteka);
					cout << "\n";
					break;
		case '2':
					this->editCategory(apteka);
					cout << "\n";
					break;
		case '3':
					this->editPrice(apteka);
					cout << "\n";
					break;
		case '4':
					this->editQuantity(apteka);
					cout << "\n";
					break;
		case 'q':
					cout << "\n";
					break;
		default:
			cout << "Niepoprawne dane \n";
		}
		system("Pause");
    }while((editOptionChoice !='q'));
}

void MenuOptions::editName(Warehouse *apteka){
	string prodName;
	int idFromUser=0;
	int i = 0;
	int indexToChange=0;
	system("cls");
	cout << "Podaj numer produktu do zmiany " << endl;
	idFromUser= checkInput(-1);
	if  ( idFromUser==-1) {
		cout << "bledny wpis \n";
	}
	else {
		for(Product p : apteka->availableProducts){
			if(p.getProductNumber() == idFromUser){
				indexToChange = i;
			}
			i++;
		}
		cout << apteka->availableProducts[indexToChange] << "\n";
		cout << "Podaj nowa nazwe produktu " << endl;
		cin >> prodName;
		cout << "ustawiam nowa wartosc ...\n" ;
		apteka->availableProducts[indexToChange].setProductName(prodName);
		cout << "\n";
		cout << apteka->availableProducts[indexToChange] << "\n";
	}
}

void MenuOptions::editCategory(Warehouse *apteka){
	string prodCat;
	int idFromUser=0;
	int i = 0;
	int indexToChange=0;
	system("cls");
	cout << "Podaj numer produktu do zmiany " << endl;
	idFromUser= checkInput(-1);
	if  ( idFromUser==-1) {
		cout << "bledny wpis \n";
	}
	else {
		for(Product p : apteka->availableProducts){
			if(p.getProductNumber() == idFromUser){
				indexToChange = i;
			}
			i++;
		}
		cout << apteka->availableProducts[indexToChange] << "\n";
		cout << "Podaj nowa kategorie produktu " << endl;
		cin >> prodCat;
		cout << "ustawiam nowa wartosc ...\n" ;
		apteka->availableProducts[indexToChange].setProductCategory(prodCat);
		cout << "\n";
		cout << apteka->availableProducts[indexToChange] << "\n";
	}
}

void MenuOptions::editPrice(Warehouse *apteka){
	float prodPrice;
	int idFromUser=0;
	int i = 0;
	int indexToChange=0;
	system("cls");
	cout << "Podaj numer produktu do zmiany " << endl;
	idFromUser= checkInput(-1);
	if  ( idFromUser==-1) {
		cout << "bledny wpis \n";
	}
	else {
		for(Product p : apteka->availableProducts){
			if(p.getProductNumber() == idFromUser){
				indexToChange = i;
			}
			i++;
		}
		cout << apteka->availableProducts[indexToChange] << "\n";
		cout << "Podaj nowa cene produktu " << endl;
		prodPrice= checkInput(-1);
		if  ( prodPrice==-1) {
			cout << "bledny wpis \n";
		}
		else {
			cout << "ustawiam nowa wartosc ...\n" ;
			apteka->availableProducts[indexToChange].setProductPrice(prodPrice);
			cout << "\n";
			cout << apteka->availableProducts[indexToChange] << "\n";
		}
	}
}

void MenuOptions::editQuantity(Warehouse *apteka){
	int prodQuant;
	int idFromUser=0;
	int i = 0;
	int indexToChange=0;
	system("cls");
	cout << "Podaj numer produktu do zmiany " << endl;
	idFromUser= checkInput(-1);
	if  ( idFromUser==-1) {
		cout << "bledny wpis \n";
	}
	else {
		for(Product p : apteka->availableProducts){
			if(p.getProductNumber() == idFromUser){
				indexToChange = i;
			}
			i++;
		}
		cout << apteka->availableProducts[indexToChange] << "\n";
		cout << "Podaj ilosc sztuk produktu do dodania " << endl;
		prodQuant= checkInput(-1);
		if  ( prodQuant==-1) {
			cout << "bledny wpis \n";
		}
		else {
			cout << "ustawiam nowa wartosc ...\n" ;
			editQuantityAdd(apteka, prodQuant, indexToChange);
			cout << "\n";
			cout << apteka->availableProducts[indexToChange] << "\n";
		}
	}
}

void MenuOptions::editQuantitySubstract(Warehouse *apteka, int quantity, int id){
	apteka->availableProducts[id].setProductQuantity( apteka->availableProducts[id].getProductQuantity() - quantity );
}

void MenuOptions::editQuantityAdd(Warehouse *apteka,int quantity, int id){
	apteka->availableProducts[id].setProductQuantity( apteka->availableProducts[id].getProductQuantity() + quantity );
}

void MenuOptions::editDetalis(Warehouse *apteka){
	cout << " tutaj nie ma implementacji \n";
}
