/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#ifndef RECEIPT_RECEIPTPOSITION_H_
#define RECEIPT_RECEIPTPOSITION_H_

#include <string>
#include <iomanip>
#include "../Product.h"

using namespace std;

class ReceiptPosition {
private:
	string positionName;
	int quantity;
	float price;
	float sum;
	int productId;


public:
	ReceiptPosition();
	ReceiptPosition(string, int, float);
	ReceiptPosition(Product, int);
	virtual ~ReceiptPosition();

	float calculateSum();

	const string& getPositionName() const {
		return positionName;
	}

	float getPrice() const {
		return price;
	}

	int getQuantity() const {
		return quantity;
	}

	float getSum() const {
		return sum;
	}

	int getProductId() const {
		return productId;
	}
};

#endif /* RECEIPT_RECEIPTPOSITION_H_ */
