/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#include "SearchResult.h"

SearchResult::SearchResult() {
	// TODO Auto-generated constructor stub

}

SearchResult::~SearchResult() {
	// TODO Auto-generated destructor stub
}

struct compare{
	string key;
	compare(string const &i): key(i){}

	bool operator()(string const&i){
		return (i == key);
	}
};

void SearchResult::populateCategoryList(Warehouse * apteka){
	for(Product p : apteka->availableProducts){
		string temp = p.getProductCategory();
		if( this->categoryList.empty()){
			this->categoryList.push_back(temp);
		}else{
			if(any_of(this->categoryList.begin(), this->categoryList.end(), compare(temp))){
				// Nic nie robi (tzn robi, sprawdza czy w vectorze znajduje sie dany element a jak znajdzie to nic nie robi)
			}else{
				this->categoryList.push_back(temp);
			}
		}
	}
	sort(this->categoryList.begin(), this->categoryList.end());
}

int SearchResult::showCategoryList(){
	int i = 0;
	cout << setw(5) << left << "ID" << "|";
	int categoryColumnLength = this->checkCategoryColumnLength("check this");
	cout << setw(categoryColumnLength) << left << "Kategoria" << endl;
	for(int i = 0; i<categoryColumnLength+5;i++){
		cout <<"-";
	}
	cout << endl;
	for(string s : this->categoryList){
		cout << setw(5) << left <<i << "|" << s << endl;
		i++;
	}
	return i;
}


void SearchResult::populateSearchResultsByCategory(Warehouse * apteka, int categoryNumber){

	string catName = this->categoryList.at(categoryNumber);
	for(Product p : apteka->availableProducts){
		if(p.getProductCategory() == catName){
			this->searchResults.push_back(p);
		}
	}
	sortSearchResultsByPrice();
}

string SearchResult::populateSearchResultsByCategoryReturnCategoryName(Warehouse * apteka, int categoryNumber){
	string catName = this->categoryList.at(categoryNumber);
		for(Product p : apteka->availableProducts){
			if(p.getProductCategory() == catName){
				this->searchResults.push_back(p);
			}
		}
		sortSearchResultsByPrice();
		return catName;
}

void SearchResult::populateSearchRusultsByName(Warehouse * apteka, string searchedName){
	for(Product p : apteka->availableProducts){
		if(p.getProductName().find(searchedName) != string::npos){
			this->searchResults.push_back(p);
		}
	}
	//this->showAllProducts();
}


void SearchResult::populateSearchResultsByPrice(Warehouse * apteka, float min, float max){
	for(Product p : apteka->availableProducts){
		if(p.getProductPrice() <= max && p.getProductPrice() >= min){
			this->searchResults.push_back(p);
		}
	}
	cout << "Posortowac wyniki malejaco? T/N ";
	char confirmation;
	cin >> confirmation;
	if(confirmation == 'T' || confirmation == 't' || confirmation == 'y' || confirmation == 'Y'){
		sortSearchResultsByPrice();
	}
	this->showAllProducts();
}

void SearchResult::showProductColumns(){
	Product *temp = new Product(1, "temp", 1,1);
	temp->display_table_names(this->checkNameColumnLength(), this->checkCategoryColumnLength());
	delete temp;
}

void SearchResult::showAllProducts(){
	this->showProductColumns();

	for(Product p : this->searchResults){
		p.display_product(this->checkNameColumnLength(), this->checkCategoryColumnLength());
	}
}

int  SearchResult::checkNameColumnLength(){
	int unsigned nameColumnLength = 6;
		for(Product p : this->searchResults){
			if (p.getProductName().length() > nameColumnLength){
				nameColumnLength = p.getProductName().length();
			}
		}
	return nameColumnLength+1;
}

int SearchResult::checkCategoryColumnLength(){
	int unsigned categoryColumnLenght = 10;
		for(Product p : this->searchResults){
			if (p.getProductCategory().length() > categoryColumnLenght){
				categoryColumnLenght = p.getProductCategory().length();
			}
		}
	return categoryColumnLenght+1;
}

int SearchResult::checkCategoryColumnLength(string s){
	int unsigned categoryColumnLenght = 2;
		for(string p : this->categoryList){
			if (p.length() > categoryColumnLenght){
				categoryColumnLenght = p.length();
			}
		}
	return categoryColumnLenght+1;
}

void SearchResult::sortSearchResultsByPrice(){
	sort(this->searchResults.begin(), this->searchResults.end(), [](const Product& p1, const Product &p2){
			return p1.product_price < p2.product_price;
		});
}

void SearchResult::populateSearchResultsById(Warehouse *apteka, int index){
	for(Product p : apteka->availableProducts){
		if(p.getProductNumber() == index){
				this->searchResults.push_back(p);
			}
	}
	//this->showAllProducts();
}

void SearchResult::clearResults(){
	this->categoryList.clear();
	this->searchResults.clear();
}
