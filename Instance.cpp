#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>//Eventually I want to read and write. Just reading could be done with ifstream
#include "Farmer.cpp"
#include "Season.cpp"
#include "Crisis.cpp"
#include "CrisisList.cpp"
#include "Product.cpp"
#include "ProductList.cpp"

class Instance{
  private:
	  Farmer f;
	  Season s;
	  CrisisList cl;
	  ProductList pl;

  public:
	  //constructor
	  Instance() {
      }
	  
  	  void run() {//input the functions to begin the program
		  initializeFarm();
		  welcomeMessage();
		  while (s.getCurrentSeason() != "end") {
			  seasonCycle();
		  }
		  finalMessage();
	  }
	  void seasonCycle() {//allows us to loop through certain methods each season
		  cl.clearCurrentCrisis();
		  pl.clearCurrentProduct();
		  seasonReader();
		  crisisReader();
		  setCrisisEvent();
		  endOfSeasonSummary();
		  s.advanceSeason();
	  }
	  void initializeFarm() {
		  std::string farmerName;
		  std::cout << "Enter your name:\n";
		  std::cin >> farmerName;
		  f.setFarmerName(farmerName);
		  std::cout << f.getFarmerName();
		  /*
			I am able to input only a single word. I need to either find a multi-word input, or restrict
			input to a single word. Many text games do the latter, but in deference to user preference, the 
			first solution would be preferred.
		  */
		  std::string farmName;
		  std::cout << ", Enter the name of your Farm:\n";
		  std::cin >> farmName;
		  f.setFarmName(farmName);
	  }
	  void endOfSeasonSummary() {
		  std::cout << "It's the end of the season. Your harvest earned you $" << 
			  pl.getProductAt(pl.getSelectedProduct() - 1).getSellPrice() << "\n" <<
			  "Your current balance is: $" << f.getCurrentBalance() <<"\n";
	  }
	  //other methods
	  void userSelectCurrentProduct() {//Add validation to ensure user enters valid integer.
		  int s;
		  std::cin >> s;
		  pl.setSelectedProduct(s);
	  }
	  
	  void setCrisisEvent() {
		  Crisis ce = cl.generateRandCrisis();
		  std::cout << ce.getScenario() << " $" << ce.getCost() << "\n";
		  if (ce.getCost() <= 0) {
			  f.seasonalEvent(0, ce.getCost());
		  }
		  else {
			  f.seasonalEvent(ce.getCost(), 0);
		  }
	  }
	  void seasonReader() {//iterate through season text file.
		  std::ifstream sr;
		  sr.open(s.getCurrentSeason() + ".txt");
		  std::string line;
		  if (sr.is_open()) {
			  while (std::getline(sr, line)) {
				  if (line[0] == '$') {
					  line.erase(0, 1);
					  std::cout << line << f.getCurrentBalance() << "\n";
				  }
				  else if (line[0] == '*') {
					  line.erase(0, 1);
					  std::string delim = "|";
					  std::size_t pos = 0;
					  std::string description;
					  std::string cost;
					  std::string profit;
					  pos = line.find(delim);
					  description = line.substr(0, pos);
					  line.erase(0, pos + delim.length());
					  pos = line.find(delim);
					  cost = line.substr(0, pos);
					  line.erase(0, pos + delim.length());
					  pos = line.find(delim);
					  profit = line.substr(0, pos);
					  pl.addProduct(Product(description, std::stod(cost), std::stod(profit)));
				  }
				  else if (line[0] == '~') {
					  userSelectCurrentProduct();
					  f.seasonalEvent(pl.getProductAt(pl.getSelectedProduct() - 1).getSellPrice(),
						  pl.getProductAt(pl.getSelectedProduct() - 1).getInvestmentCost());					  
				  }
				  else {
					  std::cout << line << "\n";
				  }
			  }
		  }
		  else {
			  std::cout << "Couldn't open file\n";//added after last run, outputs if bad text file
		  }
		  sr.close();
	  }
	  void crisisReader() {//iterate through crisis.txt file
		  std::ifstream cr;
		  cr.open("Crisis.txt");
		  std::string line;
		  if (cr.is_open()) {
			  while (std::getline(cr, line)) {
				  std::string delim = "|";//Declare my delimiter
				  std::size_t pos = 0;			  
				  std::string description;
				  std::string amount; 
				  pos = line.find(delim);
				  if (s.getCurrentSeason() == line.substr(0, pos)) {
					  line.erase(0, pos + delim.length());
					  pos = line.find(delim);
					  description = line.substr(0, pos);
					  line.erase(0, pos + delim.length());
					  pos = line.find(delim);
					  amount = line.substr(0, pos);
					  cl.addCrisis(Crisis(description, std::stod(amount)));//stod converts to double
				  }
			  }
		  }
		  else {
			  std::cout << "Couldn't open file\n";//added after last run, outputs if bad text file
		  }
		  cr.close();	  
	  }
	  void welcomeMessage() {
		  std::cout << "Welcome, " + f.getFarmerName() + ". Enjoy your time on " + f.getFarmName() +
			  ".\n";
	  }
	  //Final message should output all the information at the end.
	  void finalMessage() {
		  std::cout << "Thanks for playing, " + f.getFarmerName() + ". I hope you had fun.\n"
			  + "Your Final Balance was: $" << f.getCurrentBalance() << ".\n";
	  }
};