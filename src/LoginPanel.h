/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G�owi�ski, Bartosz So�oducha, Tomasz Siwiec, Piotr K�pa
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
