/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#ifndef LOGINPANEL_H_
#define LOGINPANEL_H_

#include <iostream>
#include <stdlib.h>
#include <process.h>
#include <cstdio>
#include <fstream>
#include "User.h"


using namespace std;

class LoginPanel {
public:
	LoginPanel();
	virtual ~LoginPanel();
	void ShowLoggingPanel(User*);
	bool IfExist();
};

#endif /* LOGINPANEL_H_ */
