//============================================================================
// Name        : Pharmacy.cpp
// Author      : Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
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
