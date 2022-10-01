#include <iostream>
#include <string>//only necessary if trying to concatenate integers

/*
	Here we define the famer class, inclduing the call to a function that will allow the user to create
	a name for the farmer and farm.
	We establish the initial money on hand for the farmer.
	We establish how the balance is calculated and updated as well.
*/

class Farmer {
  private:
	  std::string farmerName;
	  std::string farmName;
	  double startBalance;
	  double profit;
	  double loss;
  public:
	  //constructor
	  Farmer() {
		  this->farmerName = "";
		  this->farmName = "";
	  	  this->startBalance = 1000.00;
	  	  this->profit = 0.00;
		  this->loss = 0.00;
	  }
	  //getters
	  std::string getFarmerName() {
		  return farmerName;	
	  }
	  std::string getFarmName() {
		  return farmName;
	  }	  
	  double getStartBalance() {
		  return startBalance;
	  }     	  
	  double getProfit() {
		  return profit;
	  }
	  double getLoss() {
		  return loss;
	  }  
	  double getCurrentBalance() {//method to calculate remaining/new balance
		  return startBalance + profit + loss;
	  }	  
	  //setters
	  void setFarmerName(std::string f) {
		  this->farmerName = f;
	  }
	  void setFarmName(std::string fN) {
		  this->farmName = fN;
	  } 
	  void setStartBalance(double b) {
		  this->startBalance = b;
	  }  
	  void setProfit(double p) {
		  this->profit = p;
	  }
	  void setLoss(double l) {
		  this->loss = l;
	  }
	  //other methods
	  void seasonalEvent(double p, double l) {
		  this->profit += p;
		  this->loss += l;
	  }
};