#include <iostream>
#include <list>
#include <cstdlib>
#include <vector>
#include "Product.cpp"

class ProductList {
private:
	std::vector <Product> pList;
	int selectedProduct;

public:
	//getter
	int getSelectedProduct() {
		return selectedProduct;
	}
	//setter
	void setSelectedProduct(int s) {
		this->selectedProduct = s;
	}
	//Other Methods
	void addProduct(Product p) {
		pList.push_back(p);
	}
	void clearCurrentProduct() {
		pList.clear();
	}
	Product getProductAt(int i) {
		return pList[i];
	}
	void displayProduct() {
		for (std::vector <Product>::iterator i = pList.begin(); i != pList.end(); i++) {
			std::cout << *i<< "\n";
		}
	}
};