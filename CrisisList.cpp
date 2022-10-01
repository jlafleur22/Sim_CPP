#include <iostream>
#include <list>
#include <cstdlib>
#include <vector>
#include "Crisis.cpp"

//generate random event for each month
class CrisisList {
  private:
	  std::vector <Crisis> cList;

  public:
	  //Random # generation
	  Crisis generateRandCrisis() {
		  srand(time(0));
		  if (cList.size() > 0) {
			  return cList[(rand() % cList.size())];
		  }
		  return Crisis("ERROR", 0.00);
	  }
	  //works with vector list
	  void addCrisis(Crisis c) {
		  cList.push_back(c);
	  }
	  //remove info from memory, allowing new generation later.
	  void clearCurrentCrisis() {
		  cList.clear();
	  }
	  //display text from a file.
	  void displayCrisis() {
		  for (std::vector <Crisis>::iterator i = cList.begin(); i != cList.end(); i++) {
			  std::cout << *i << "\n";
		  }
	  }
};