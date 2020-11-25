#ifndef country_h
#define country_h

/*Author: Edward Wong ewong385
  Date: October 7 2020
  Course: CS3307
  This file is the Country header used as a template for country.cpp
*/

class Country {
  private:
    std::string name, code;
    int newConfirmed, newDeath, newRecovered, totalConfirmed, totalDeath, totalRecovered;

  public:
    Country(){};
    ~Country(){};
    Country(std::string name, std::string code, int newConfirmed, int newDeath, int newRecovered, int totalConfirmed, int totalDeath, int totalRecovered);
    std::string getName(){return name;}
    void setName(std::string name);
    std::string getCode(){return code;}
    void setCode(std::string code);
    int getNewConfirmed(){return newConfirmed;}
    void setNewConfirmed(int newConfirmed);
    int getNewDeath(){return newDeath;}
    void setNewDeath(int newDeath);
    int getNewRecovered(){return newRecovered;}
    void setNewRecovered(int newRecovered);
    int getTotalConfirmed(){return totalConfirmed;}
    void setTotalConfirmed(int totalConfirmed);
    int getTotalDeath(){return totalDeath;}
    void setTotalDeath(int totalDeath);
    int getTotalRecovered(){return totalRecovered;}
    void setTotalRecovered(int totalRecovered);
};

#endif