#ifndef PRODUCT_CPP//This allows me to call this class in multiple files with the #define and #endif
#define PRODUCT_CPP
#include <iostream>
#include <string>

/*
	a product class
	product costs and calculations for money on hand (balance). This needs to dynamically update the 
	remaining balance after each season ends, taking into account money invested in product, crisis, and 
	return on investment.
*/
class Product {
  private:
	  std::string productName;
	  double investmentCost;
	  double sellPrice;

  public:
	  //constructor
	  Product(std::string pN, double iC, double sP) {
		  this->productName = pN;
		  this->investmentCost = iC;
		  this->sellPrice = sP;
	  }
	  //getter
	  std::string getProductName() {
		  return productName;
	  }
	  double getInvestmentCost() {
		  return investmentCost;
	  }
	  double getSellPrice() {
		  return sellPrice;
	  }
	  //overload
	  friend std::ostream& operator<<(std::ostream& o, const Product& p) {
		  o << p.productName << "Investment Cost: $" << p.investmentCost << ", Sell Price: $" 
			  << p.sellPrice << "\n";
		  return o;
	  }
};
#endif//PRODUCT_CPP