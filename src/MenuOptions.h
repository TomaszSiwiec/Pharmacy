/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#ifndef MENUOPTIONS_H_
#define MENUOPTIONS_H_

#include "Warehouse.h"
#include "SearchResult.h"

class MenuOptions {
	//Wskaznik na Warehouse moglby byc czescia tej klasy, nie trzba byloby
	//miec takiego wskaznika w kazdej metodzie
public:
	MenuOptions();
	virtual ~MenuOptions();
	void eraseProductOption(Warehouse *);
	void showProductDetailsOption(Warehouse *, int);
	void searchOption(Warehouse *, int);

	//SearchFunctions
	void categorySearch(Warehouse *);
	void nameSearch(Warehouse *);
	void priceSearch(Warehouse *);

	//eraseFunction
	void eraseByName(Warehouse *);
	void eraseByID(Warehouse *);
	void eraseByCategory(Warehouse*);

	//confirmation -
	bool choiceConfirmation();

	//menu editProduct product
	void editSubmenuOptions(Warehouse *);
	void editName(Warehouse *);
	void editCategory(Warehouse *);
	void editPrice(Warehouse*);
	void editQuantity(Warehouse*);
	void editDetalis(Warehouse*);
	void editQuantitySubstract(Warehouse *, int, int);
	void editQuantityAdd(Warehouse *, int, int);

	//details
	void showDetailsById(Warehouse *);
	void showDetailsByName(Warehouse *);

	//sprawdzenie wprowadzonych danych
	int checkInput(int);
	float checkInput(float);
};

#endif /* MENUOPTIONS_H_ */
