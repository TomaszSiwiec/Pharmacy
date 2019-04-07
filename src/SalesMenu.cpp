/*
 * SalesMenu.cpp
 *
 *  Created on: 2 wrz 2018
 *      Author: XR
 */

#include "SalesMenu.h"

SalesMenu::SalesMenu(Warehouse * apteka) {
	w_pointer = apteka;
	// TODO Auto-generated constructor stub

}

SalesMenu::~SalesMenu() {
	// TODO Auto-generated destructor stub
}

bool SalesMenu::choiceConfirmation(){
	char confirmation;
	cin >> confirmation;
	if(confirmation == 'T' || confirmation == 't' || confirmation == 'y' || confirmation == 'Y'){
		return true;
	}else{
		return false;
	}
}

void SalesMenu::showSalesMenu(){
	char editOptionChoice;

	    do {
	    	system("cls");
	    	cout << "************* WITAMY W MODULE SPRZEDAZY ********************" << endl;
	    	cout << "Wybierz sposob dodawnia produktu: \n" ;
	    	cout << "1) ID \n";
	    	cout << "2) Nazwa \n";
	    	cout << "3) Kategoria + ID \n" ;
	    	cout << "4) Wyœwietl aktualne pozycje na paragonie \n";
	    	cout << "5) Zatwierdz zamowienie i wydrukuj paragon \n";
	    	cout << "Q) Anuluj zamowienie i wyjdz \n ";
	    cout << "\n" ;
	    cout << "Wprowadz wartosc: ";
	    cin >> editOptionChoice ;

	    switch (editOptionChoice) {
			case '1':
			{
				SearchResult sr;
				idCheck(&sr);
				system("Pause");
				break;
			}
			case '2':
			{
				SearchResult sr;
				nameCheck(&sr);
				system("Pause");
				break;
			}
			case '3':
			{
				SearchResult sr;
				sr.populateCategoryList(w_pointer);
				sr.showCategoryList();
				cout << endl << "Wybierz kategorie: ";
				int chosenCategory;
				cin >> chosenCategory;
				sr.populateSearchResultsByCategory(w_pointer, chosenCategory);
				sr.showAllProducts();
				sr.clearResults();
				idCheck(&sr);
				system("Pause");
				//TestTest
				break;
			}
			case '4':
			{
				system("cls");
				cout << "Pozycje na aktualnym paragonie :" << endl;
				currentReceipt.printPositionsOnReceipt();
				cout << endl << "Suma: " << this->currentReceipt.getSum() << "zl" <<endl;
				system("Pause");
				break;
			}
			case '5':
			{
				system("cls");
				currentReceipt.printReceipt();
				w_pointer->addReceiptToReceiptArchive(currentReceipt);
				system("Pause");
				editOptionChoice = 'q';
				break;
			}

			case 'q':
			{
				returnProductToShelves();
				break;
			}
			default:
				cout << "Niepoprawne dane \n";
				system("Pause");
			}
	    }while(editOptionChoice !='q' && editOptionChoice !='Q');
}

void SalesMenu::quantityCheck(SearchResult *sr){
	int quantity;
	cout << "Podaj liczbe sztuk: ";
	cin >> quantity;
	if(sr->searchResults[0].getProductQuantity() <quantity ){
		cout << "Wymagana ilosc nie znajduje sie na magazynie. " << "Max: " << sr->searchResults[0].getProductQuantity() << endl;
		quantityCheck(sr);
		return;
	}else if( quantity < 0){
		cout << "Wartosc ujemna nie jest przyjmowana " << "Min: 0 " <<  "Max: " << sr->searchResults[0].getProductQuantity() << endl;
		quantityCheck(sr);
		return;
	}else{
		ReceiptPosition rp(sr->searchResults[0],quantity);
		currentReceipt.addPosition(rp);
		cout << "Na paragonie znajduje sie: " << endl;
		currentReceipt.printPositionsOnReceipt();
		MenuOptions *mo = new MenuOptions();
		mo->editQuantitySubstract(w_pointer,quantity,sr->searchResults[0].getProductNumber());
		delete mo;
		return;
	}
}

void SalesMenu::idCheck(SearchResult * sr){
	cout << "Wprowadz ID wyszukiwanego produktu: ";
	int searchedID;
	cin >> searchedID;
	sr->populateSearchResultsById(this->w_pointer, searchedID);
	if(sr->searchResults.empty()){
		cout << "Przepraszamy. Nie ma takiego produktu w bazie" << endl;
		cout << "Czy chcesz wyszukac ponownie? T/N ";
		if(choiceConfirmation()){
			idCheck(sr);
			return;
		}
		return;
	}
	sr->showAllProducts();
	cout << "\nCzy chcesz dodac ten produkt? T/N ";
	if(choiceConfirmation()){
		this->quantityCheck(sr);
	}
}

void SalesMenu::nameCheck(SearchResult * sr){
	cout << "Wprowadz nazwe wyszukiwanego produktu: ";
	string searchedName;
	cin >> searchedName;
	sr->populateSearchRusultsByName(this->w_pointer, searchedName);
	if(sr->searchResults.empty()){
		cout << "Przepraszamy. Nie ma takiego produktu w bazie" << endl;
		cout << "Czy chcesz wyszukac ponownie? T/N ";
		if(choiceConfirmation()){
			nameCheck(sr);
			return;
		}
	}else if(sr->searchResults.size() > 1){
		system("cls");
		cout << "W bazie jest "<< sr->searchResults.size() << " wynikow spelniajacych kryteria:" << endl;
		sr->showAllProducts();
		cout << endl <<"Czy chcesz wyszukac ponownie? 1/2"<< endl;
		cout << "1) Podajac ID" << endl;
		cout << "2) Podajac nazwe" << endl;
		cout << "Inna opca: Anuluj"<< endl;
		cout << "Podaj wartosc" << endl;
		int choice = 0;
		cin >> choice;
		switch(choice){
		case 1:
		{
			sr->clearResults();
			idCheck(sr);
			return;
		}
		case 2:
		{
			sr->clearResults();
			nameCheck(sr);
			return;
		}
		default:
			cout << "Wychodze..." << endl;
			system("Pause");
			break;
		}
		return;
	}else if(sr->searchResults.size() == 1){
		sr->showAllProducts();
		cout << "\nCzy chcesz dodac ten produkt? T/N ";
		if(choiceConfirmation()){
			this->quantityCheck(sr);
		}
	}

}

void SalesMenu::returnProductToShelves(){
	MenuOptions *mo = new MenuOptions;
	for(ReceiptPosition rp : currentReceipt.getPositionsOnReceipt()){
		mo->editQuantityAdd(w_pointer, rp.getQuantity(), rp.getProductId());
	}
	delete mo;
}

