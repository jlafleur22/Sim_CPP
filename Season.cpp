#include <iostream>

/*
	This is time advancement. There are 4 phases, likely that will be all. After each choice for investment
	every season a crisis will roll and then calculate. If the farm can proceed, then a new balance will
	display and the need for seasonal advancement will take place here, pushing into the next season, or 
	ending the game as appropriate.
*/

class Season {
  private:
	  //std::string seasonIndicator;
	  std::string currentSeason;
	  //std::string crisis;
  public:
	  //constructor
	  Season() {
		  //this->seasonIndicator = "s";
		  this->currentSeason = "summer";
	  } 
	  std::string getCurrentSeason() {
		  return currentSeason;
	  }
	  //Change Season
	  void advanceSeason() {
		  if (currentSeason == "summer") {
			  currentSeason = "fall";
		  }
		  else if (currentSeason == "fall") {
			  currentSeason = "winter";
		  }
		  else if (currentSeason == "winter") {
			  currentSeason = "spring";
		  }
		  else if (currentSeason == "spring") {
			  currentSeason = "end";//if I want to loop this, set this to summer and have user input after year
		  }
		  else {
			  std::cout << "Error Message";
		  }
	  }
};