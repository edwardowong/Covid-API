#include <iostream>
#include "country.h"
using namespace std;

/*Author: Edward Wong ewong385
  Date: October 7 2020
  Course: CS3307
  This file creates a Country class used to store data from the dataset
*/

Country::Country(string name, string code, int newConfirmed, int newDeath, int newRecovered, int totalConfirmed, int totalDeath, int totalRecovered){ //country constructor
      this->name = name;
      this->code = code;
      this-> newConfirmed = newConfirmed;
      this->newDeath = newDeath;
      this->newRecovered = newRecovered;
      this->totalConfirmed = totalConfirmed;
      this->totalDeath = totalDeath;
      this->totalRecovered = totalRecovered;
}
  void Country::setName(string name){ //sets the country name
    this->name = name;
  }
  void Country::setCode(std::string code){ //sets the country code
    this->code = code;
  }
  void Country::setNewConfirmed(int newConfirmed){ //sets the new confirmed cases
    this->newConfirmed = newConfirmed;
  }
  void Country::setNewDeath(int newDeath){ //sets the new death count
    this->newDeath = newDeath;
  }
  void Country::setNewRecovered(int newRecovered){ //sets the new recovered count
    this->newRecovered = newRecovered;
  }
  void Country::setTotalConfirmed(int totalConfirmed){ //sets the total confirmed cases
    this->totalConfirmed = totalConfirmed;
  }
  void Country::setTotalDeath(int totalDeath){ //sets the total death count
    this->totalDeath = totalDeath;
  }
  void Country::setTotalRecovered(int totalRecovered){ //sets the total recovered cases
    this->totalRecovered = totalRecovered;
  }
