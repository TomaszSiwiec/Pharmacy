//============================================================================
// Name        : Pharmacy.cpp
// Author      : Kamil G�owi�ski, Bartosz So�oducha, Tomasz Siwiec, Piotr K�pa
// Version     :
// Copyright   :
// Description : WIEiK PP Project
//============================================================================


#include <string>
#include <process.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>

#include "Product.h"
#include "Warehouse.h"
#include "Menu.h"
#include "User.h"
#include "LoginPanel.h"

using namespace std;

int main()
{

	LoginPanel loginPanel;
	User u1;
	loginPanel.ShowLoggingPanel(&u1);

	if(u1.logged == true)
	{
		Warehouse apteka;
		apteka.fillWarehouseWithProducts();

		Menu menu;
		menu.showUserMenu(&apteka, &u1);
		//menu.showAdminMenu();
	}
	return 0;
}
