#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "country.h"
using namespace std;

/*Author: Edward Wong ewong385
  Date: October 7 2020
  Course: CS3307
  This file is the main program responsible for interaction with the user, calling for a country class creation from country.h, creation of a vector containing the country data and printing out the horizontal graphs.
*/

vector<Country> createVector(ifstream& fileName);

int main() {
  string input;
  cout << "Welcome to the Global Covid-19 Database, created by Edward Wong" << endl;

  while(true){  // Forces the user to input a dataset until it is valid
    cout << "Please specify a dataset to use! (ex: \"summary.csv\")." << endl;
    cin >> input;
    ifstream covidData(input);
    if (covidData){
      covidData.close();
      break;
    }
    else
      cout << "Please provide a valid dataset!" << endl;
  }
  ifstream covidData(input);

  int sortMethod;
  while(true){  // Forces the user to input a valid selection
    int input = 0;
    cout << "How would you like your data to be sorted? Input:" << endl;
    cout << "\"1\" for new confirmed cases" << endl;
    cout << "\"2\" for new deaths" << endl;
    cout << "\"3\" for new recovered cases" << endl;
    cout << "\"4\" for total confirmed cases" << endl;
    cout << "\"5\" for total deaths" << endl;
    cout << "\"6\" for total recovered cases" << endl;
    cin >> input;
    if (input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6){
      sortMethod = input;
      break;
    }
    else{
      cout << "Please enter an integer between 1 and 6!" << endl;
    }
  }

  int sortType;
  while(true){  //Forces the user to input a valid selection
    int input = 0;
    cout << "Would you like your data to be sorted descending or ascending? Input:" << endl;
    cout << "\"1\" for descending" << endl;
    cout << "\"2\" for ascending" << endl;
    cin >> input;
    if (input == 1 || input == 2){
      sortType = input;
      break;
    }    
    else{
      cout << "Please enter either 1 or 2!" << endl;
    }
  }
  
  vector <Country> countryVector = createVector(covidData); //Calls for the creation of a vector containing country data from the dataset
  cout << "\n\n\n\n\n" << endl;

  float scale = 0;
  if (sortMethod == 1 && sortType == 1){ //Descending graph for new confirmed cases
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getNewConfirmed() > right.getNewConfirmed();});
    for (int i=0; i < 10; i++){ // search for the top 10 countries
      int numSymbols = 0;
      if (i == 0){  //calculates the scale in relation of the largest value
        scale = countryVector.at(i).getNewConfirmed() / 70;
        numSymbols = 70;
      }
      else
        numSymbols = floor(countryVector.at(i).getNewConfirmed()/scale); 
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "New Confirmed Cases, where each $ is approximately " << scale << " cases." << endl;
  }
  else if (sortMethod == 1 && sortType == 2){ //Ascending graph for new confirmed cases
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getNewConfirmed() < right.getNewConfirmed();});
    for (int i=0; i < 10; i++){ //search for the bottom 10 countries
      int numSymbols = 0;
      numSymbols = countryVector.at(i).getNewConfirmed();
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "New Confirmed Cases, where each $ is 1 case." << endl;
  }
  else if (sortMethod == 2 && sortType == 1){ //Descending graph for new deaths
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getNewDeath() > right.getNewDeath();});
    for (int i=0; i < 10; i++){ //search for the top 10 countries
      int numSymbols = 0;
      if (i == 0){ //calculates the scale in relation of the largest value
        scale = countryVector.at(i).getNewDeath() / 70; 
        numSymbols = 70;
      }
      else
        numSymbols = floor(countryVector.at(i).getNewDeath()/scale);
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "New Deaths, where each $ is approximately " << scale << " cases." << endl;
  }
  else if (sortMethod == 2 && sortType == 2){ //Ascending graph for new deaths
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getNewDeath() < right.getNewDeath();});
    for (int i=0; i < 10; i++){ //search for the bottom 10 countries
      int numSymbols = 0;
      numSymbols = countryVector.at(i).getNewDeath();
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "New Death, where each $ is 1 death." << endl;
  }
  else if (sortMethod == 3 && sortType == 1){ //Descending graph for new recoveries
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getNewRecovered() > right.getNewRecovered();});
    for (int i=0; i < 10; i++){ // search for the top 10 countries
      int numSymbols = 0;
      if (i == 0){ //calculates the scale in relation of the largest value
        scale = countryVector.at(i).getNewRecovered() / 70;
        numSymbols = 70;
      }
      else
        numSymbols = floor(countryVector.at(i).getNewRecovered()/scale);
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "New Recovered Cases, where each $ is approximately " << scale << " cases." << endl;
  }
  else if (sortMethod == 3 && sortType == 2){ //Ascending graph for new recoveries
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getNewRecovered() < right.getNewRecovered();});
    for (int i=0; i < 10; i++){ // search for the bottom 10 countries
      int numSymbols = 0;
      numSymbols = countryVector.at(i).getNewRecovered();
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "New Recovered Cases, where each $ is 1 case." << endl;
  }
  else if (sortMethod == 4 && sortType == 1){ //Descending graph for total confirmed cases
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getTotalConfirmed() > right.getTotalConfirmed();});
    for (int i=0; i < 10; i++){ // search for the top 10 countries
      int numSymbols = 0;
      if (i == 0){ //calculates the scale in relation of the largest value
        scale = countryVector.at(i).getTotalConfirmed() / 70;
        numSymbols = 70;
      }
      else
        numSymbols = floor(countryVector.at(i).getTotalConfirmed()/scale);
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "Total Confirmed Cases, where each $ is approximately " << scale << " cases." << endl;
  }
  else if (sortMethod == 4 && sortType == 2){ //Ascending graph for total confirmed cases
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getTotalConfirmed() < right.getTotalConfirmed();});
    for (int i=0; i < 10; i++){ // search for the bottom 10 countries
      int numSymbols = 0;
      if (i == 0){
        scale = countryVector.at(10).getTotalConfirmed() / 70;
      }
      numSymbols = floor(countryVector.at(i).getTotalConfirmed()/scale);
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "Total Confirmed Cases, where each $ is approximately " << scale << " cases." << endl;
  }
  else if (sortMethod == 5 && sortType == 1){ //Descending graph for total deaths
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getTotalDeath() > right.getTotalDeath();});
    for (int i=0; i < 10; i++){ // search for the top 10 countries
      int numSymbols = 0;
      if (i == 0){ //calculates the scale in relation of the largest value
        scale = countryVector.at(i).getTotalDeath() / 70;
        numSymbols = 70;
      }
      else
        numSymbols = floor(countryVector.at(i).getTotalDeath()/scale);
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "Total Deaths, where each $ is approximately " << scale << " deaths." << endl;
  }
  else if (sortMethod == 5 && sortType == 2){ //Ascending graph for total deaths
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getTotalDeath() < right.getTotalDeath();});
    for (int i=0; i < 10; i++){ //search for the bottom 10 countries
      int numSymbols = 0;
      if (i == 0){
        scale = countryVector.at(10).getTotalDeath() / 70;
      }
      numSymbols = floor(countryVector.at(i).getTotalDeath()/scale);
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "Total Deaths, where each $ is 1 death." << endl;
  }
  else if (sortMethod == 6 && sortType == 1){ //Descending graph for total recoveries
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getTotalRecovered() > right.getTotalRecovered();});
    for (int i=0; i < 10; i++){ // search for the top 10 countries
      int numSymbols = 0;
      if (i == 0){ //calculates the scale in relation of the largest value
        scale = countryVector.at(i).getTotalRecovered() / 70;
        numSymbols = 70;
      }
      else
        numSymbols = floor(countryVector.at(i).getTotalRecovered()/scale);
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "Total Recovered Cases, where each $ is approximately " << scale << " cases." << endl;
  }
  else if (sortMethod == 6 && sortType == 2){ //Ascending graph for total recoveries
    sort(countryVector.begin(), countryVector.end(), [](Country& left, Country& right){
    return left.getTotalRecovered() < right.getTotalRecovered();});
    for (int i=0; i < 10; i++){ // search for the bottom 10 countries
      int numSymbols = 0;
      if (i == 0){
        scale = countryVector.at(10).getTotalRecovered() / 70;
      }
      numSymbols = floor(countryVector.at(i).getTotalRecovered()/scale);
      cout << countryVector.at(i).getCode() << " | ";
      for (int j=0; j < numSymbols; j++) //calculates the number of symbols printed
        cout << "$";
      cout << "" << endl;
      cout << "   |" << endl;
    }
    cout << "Total Recovered Cases, where each $ is 1 case." << endl;
  }
  cout << "Input anything to exit: ";
  cin >> input;
  return 0;
}

vector<Country> createVector(ifstream& covidData){ //Function used to create a vector and store data into from the dataset
  vector<Country> countryVector;
  string divider = ",", line, data;
  size_t pos = 0;
  getline(covidData,line); //skips first line
  while (getline(covidData, line)){ //takes from the data line by line, country by country
    Country newCountry;
    int filterCount = 1;
    string datatemp;
    while ((pos = line.find(divider)) != std::string::npos) { //goes through the data and stops for the given divider
      data = line.substr(0, pos);
      if (line.substr(pos, 2) == ", "){
        datatemp = data + divider;
        line.erase(0, pos + divider.length());
        continue;
      }
      if (filterCount == 1){ //sets country name from the data
        newCountry.setName(datatemp + data);
      }
      else if (filterCount == 2){ //sets country code from the data
        newCountry.setCode(data);
      }
      else if (filterCount == 4){ //sets the country's new confirmed cases from the data
        newCountry.setNewConfirmed(stoi(data, nullptr));
      }
      else if (filterCount == 5){ //sets the country's new deaths from the data
        newCountry.setNewDeath(stoi(data, nullptr));
      }
      else if (filterCount == 6){ //sets the country's new recoveries from the data
        newCountry.setNewRecovered(stoi(data, nullptr));
      }
      else if (filterCount == 9){ //sets the country's total confirmed cases from the data
        newCountry.setTotalConfirmed(stoi(data, nullptr));
      }
      else if (filterCount == 10){ //sets the country's total deaths from the data
        newCountry.setTotalDeath(stoi(data, nullptr));
      }
      filterCount++;
      line.erase(0, pos + divider.length());
      if ((pos = line.find(divider)) == std::string::npos)
        newCountry.setTotalRecovered(stoi(line, nullptr));
    }
    countryVector.push_back(newCountry);
  }
  covidData.close();
  return countryVector;
}

