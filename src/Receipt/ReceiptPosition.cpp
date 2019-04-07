/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G�owi�ski, Bartosz So�oducha, Tomasz Siwiec, Piotr K�pa
 */

#include "ReceiptPosition.h"

ReceiptPosition::ReceiptPosition() {

}

ReceiptPosition::ReceiptPosition(string positionName, int quantity, float price){
	this->positionName = positionName;
	this->quantity = quantity;
	this->price = price;
	this->sum = calculateSum();
}

ReceiptPosition::ReceiptPosition(Product p, int quantity){
	this->positionName = p.getProductName();
	this->price = p.getProductPrice();
	this->quantity = quantity;
	this->sum = calculateSum();
	this->productId = p.getProductNumber();

}

ReceiptPosition::~ReceiptPosition() {
	// TODO Auto-generated destructor stub
}

float ReceiptPosition::calculateSum(){
	float result = 0;
	result = this->quantity * this->price;
	return result;
}
