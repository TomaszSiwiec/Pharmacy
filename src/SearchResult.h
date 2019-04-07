/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#ifndef SEARCHRESULT_H_
#define SEARCHRESULT_H_

#include <string>
#include <vector>
#include <algorithm>

#include "Product.h"
#include "Warehouse.h"

using namespace std;

class SearchResult {
public:
	vector<string> categoryList;
	vector<Product> searchResults;
public:
	SearchResult();
	virtual ~SearchResult();

	void populateCategoryList(Warehouse *);
	int showCategoryList();
	void populateSearchResultsByCategory(Warehouse *, int);
	string populateSearchResultsByCategoryReturnCategoryName(Warehouse *, int);
	void populateSearchRusultsByName(Warehouse *, string);
	void populateSearchResultsByPrice(Warehouse *, float, float);
	void populateSearchResultsById(Warehouse *, int);
	void sortSearchResultsByPrice();
	/*
	 * Cztery kolejne funkcje to powtorzony kod z Warehouse z innym Ÿrod³em danych
	 */
	void showProductColumns();
	void showAllProducts();
	int checkNameColumnLength();
	int checkCategoryColumnLength();
	int checkCategoryColumnLength(string);

	//Wyczysc wektor rezultatow;
	void clearResults();
};

#endif /* SEARCHRESULT_H_ */
