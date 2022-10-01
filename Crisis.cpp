#ifndef CRISIS_CPP//This allows me to call this class in multiple files with the #define and #endif
#define CRISIS_CPP

#include <iostream>

/*
	Here we set the function to call and calculate the crisis. In another part of our code we will establish
	a random number generator to actually generate the code, and call from the Crisis.txt file to figure out
	which crisis willl generate. This just defines the Crisis class to be utilized later on.
*/
class Crisis{
  private:
	  std::string scenario;
	  double cost;
  public:
	  //constructor
	  Crisis(std::string s, double c) {
		  this->scenario = s;
		  this->cost = c;
	  }
	  //getters
	  std::string getScenario() {
		  return this->scenario;
	  }
	  double getCost() {
		  return this->cost;
	  }
	  //overload
	  friend std::ostream& operator<<(std::ostream& o, const Crisis& c) {
		  o << c.scenario << " " << c.cost;
		  return o;
	  }
};
#endif // CRISIS_CPP