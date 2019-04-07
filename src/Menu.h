/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G�owi�ski, Bartosz So�oducha, Tomasz Siwiec, Piotr K�pa
 */

#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Warehouse.h"
#include "User.h"
#include "MenuOptions.h"
#include "SalesMenu.h"

using namespace std;

class Menu {
public:
	Menu();
	virtual ~Menu();
	void showUserMenu(Warehouse *, User *);
	//void showAdminMenu();
	//CheckInput
	int checkInput();
};

#endif /* MENU_H_ */
