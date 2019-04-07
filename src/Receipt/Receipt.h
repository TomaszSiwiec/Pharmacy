/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#ifndef RECEIPT_RECEIPT_H_
#define RECEIPT_RECEIPT_H_

#include <vector>
#include <string>
#include <ctime>
#include <iostream>

#include "../Receipt/ReceiptPosition.h"

using namespace std;

class Receipt {
private:
	vector<ReceiptPosition> positionsOnReceipt;
	char * sellTime;
	static int recepitCount;
	const int receiptId;
	float sum;

public:
	Receipt();
	virtual ~Receipt();
	void printReceipt();
	void printPositionsOnReceipt();
	void addPosition(ReceiptPosition);
	void calculateSum();

	float getSum() const {
		return sum;
	}

	void setSum(float sum) {
		this->sum = sum;
	}

	const vector<ReceiptPosition>& getPositionsOnReceipt() const {
		return positionsOnReceipt;
	}
};

#endif /* RECEIPT_RECEIPT_H_ */
