/*
 * LoginPanel.cpp
 *
 *  Created on: 6 wrz 2018
 *      Author: Kamil G³owiñski, Bartosz So³oducha, Tomasz Siwiec, Piotr Kêpa
 */

#include "Product.h"

//Product::Product(){

//}

Product::Product(int number, string name, float price, int quantity) {
	product_number = number;
	product_name = name;
	product_price = price;
	product_quantity = quantity;
	// TODO Auto-generated constructor stub

}

Product::Product(int number, string name, string category, string desc,
				float price, int quantity, string prescription)
{
	product_number = number;
	product_name = name;
	product_category = category;
	product_description = desc;
	product_price = price;
	product_quantity = quantity;
	product_prescription_required = prescription;

}

Product::~Product() {
	// TODO Auto-generated destructor stub
}

void Product::display_product(int nameLength, int categoryLength) const{
	/*
	 * TODO - Sprobowac skasowac magic numbers, ustalanie dydanmiczne tresci na podstawie dlugosci
	 */
	cout << setw(5) << left << product_number << "|";
	cout << setw(nameLength) << left << product_name << "|";
	cout << setw(categoryLength) << left << product_category << "|";
	cout << fixed << setprecision(2) << setw(10) << left  << product_price << "|";
	cout << setw(10) << left << product_quantity << "|";
	cout << setw(10) << left << product_prescription_required << endl;
}

void Product::display_table_names(int nameLength, int categoryLength) {

	int idLength = 5;
	int priceLength = 10;
	int quantityLength = 10;
	int prescriptionLength = 10;
	int separatorQuantity = 5;

	cout << setw(idLength) << left << "ID" << "|";
	cout << setw(nameLength) << left << "Nazwa" << "|";
	cout << setw(categoryLength) << left << "Kategoria" << "|";
	cout << setw(priceLength) << left << "Cena" << "|";
	cout << setw(quantityLength) << left << "Ilosc" << "|";
	cout << setw(prescriptionLength) << left << "W.Recepty" << endl;
	int sumLenght = idLength + nameLength + categoryLength + priceLength + quantityLength + prescriptionLength + separatorQuantity;

	for(int i = 0; i < sumLenght; i++){
		cout << "-";
	}
	cout << endl;
}

void Product::display_full_information(){
	cout << "*******************************" << endl;
	cout << setw(30) << left << "Szczegoly produktu: " << product_name << endl;
	cout << setw(30) << left << "Nazwa produktu: " << product_name << endl;
	cout << setw(30) << left << "Kategoria produktowa: " << product_category << endl;
	cout << setw(30) << left << "Szczegolowy opis produktu: " << endl;
	cout << product_description << endl;
	cout << endl;
	cout << setw(30) << left << "Cena produktu:" <<  product_price << endl;
	cout << setw(30) << left << "Dostepna ilosc: " << product_quantity <<endl;
	cout << "*******************************" << endl;
}

ostream& operator << (ostream &out, const Product &p){
	cout << setw(30) << left << "Nazwa produktu: " << p.product_name << endl;
	cout << setw(30) << left << "Kategoria produktowa: " << p.product_category <<"\n";
	cout << setw(30) << left << "Cena produktu:" <<  p.product_price << "\n";
	cout << setw(30) << left << "Dostepna ilosc: " << p.product_quantity <<"\n";
	return out;
}

