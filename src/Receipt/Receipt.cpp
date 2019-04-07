/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#include "Receipt.h"

void drawLine(){
	int count = 30;
	for (int i = 0; i<count ; i++){
		cout << "*";
	}
	cout << endl;
}

Receipt::~Receipt() {
	// TODO Auto-generated destructor stub
}

Receipt::Receipt() : receiptId(recepitCount++){
	time_t now = time(0);
	sellTime = ctime(&now);
	sum = 0;

}

void Receipt::addPosition(ReceiptPosition position){
	/*
	 * TODO - Wyszukiwanie czy taka pozycja juz sie znajduje i tylko korekta ilosci
	 */
	this->positionsOnReceipt.push_back(position);
	this->calculateSum();
}

void Receipt::calculateSum(){
	float result = 0;
	for(ReceiptPosition rp : this->positionsOnReceipt){
		result += rp.calculateSum();
	}
	this->setSum(result);
}

void Receipt::printPositionsOnReceipt(){
	int i = 1;
	for (ReceiptPosition rp : this->positionsOnReceipt){
		string temp;
		temp = rp.getPositionName();
		temp.resize(12);
		cout << i << ") ";
		cout << temp << " ";
		cout << setw(5) << right << rp.getQuantity() << "x ";
		cout << fixed << setprecision(2) << setw(6) << right << rp.getPrice();
		cout <<  right << "zl" << endl;
		i++;
	}

}

void Receipt::printReceipt(){
	drawLine();
	cout << "         Local Pharmacy    " << endl;
	cout << "          00-840 Krakow    " << endl;
	cout << "           UL. WLOSKA 1    " << endl;
	cout << "        NIP 444-555-66-66  " << endl;
	drawLine();
	cout << "            RECEIPT        " << endl;
	drawLine();
	cout << "   " << sellTime;
	drawLine();
	printPositionsOnReceipt();
	drawLine();
	cout << setw(10) << left << "SUM PLN: ";
	cout << setw(18) << right << this->getSum() << "zl" << endl;
	drawLine();

}

int Receipt::recepitCount = 0;
