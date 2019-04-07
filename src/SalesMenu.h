/*
 * SalesMenu.h
 *
 *  Created on: 2 wrz 2018
 *      Author: XR
 */

#ifndef SALESMENU_H_
#define SALESMENU_H_

#include "../src/Receipt/Receipt.h"
#include "Warehouse.h"
#include "SearchResult.h"
#include "MenuOptions.h"

using namespace std;

class SalesMenu {
private:
	Warehouse * w_pointer;
	Receipt currentReceipt;



public:
	SalesMenu(Warehouse *);
	virtual ~SalesMenu();

	void showSalesMenu();

	//choiceConfirmation
	bool choiceConfirmation();
	void quantityCheck(SearchResult *);
	void idCheck(SearchResult *);
	void nameCheck(SearchResult *);
	void returnProductToShelves();
};

#endif /* SALESMENU_H_ */
