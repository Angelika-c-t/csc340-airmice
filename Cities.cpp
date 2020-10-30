#include <iostream>
#include <algorithm>
#include "Cities.h"
#include "rapidcsv.h"

using namespace std;

void Cities::fileRead() {
    // create instance of Document
    rapidcsv::Document doc("data/California_airquality.csv");

    // create vectors to hold various data types
    names = doc.GetColumn<string>("Site Name");
    dates = doc.GetColumn<string>("Date");
    aqi = doc.GetColumn<int>("DAILY_AQI_VALUE");

    // print the amount of data read
    // cout << "Read " << aqi.size() << " values for AQI." << endl; 
    // cout << "Read " << names.size() << " values for city names." << endl; 
    // cout << "Read " << dates.size() << " values for dates." << endl; 

}

void Cities::addData() {
    City tempCity;
    int count = 2;
    tempCity = setInitialCityName(names.at(0));
    //tempCity.setCityDateAQI(dates.at(0),aqi.at(0));
    setDateAQI(dates.at(0), aqi.at(0), tempCity);
    cout << "City 1: " << tempCity.getName() << endl;

    for(int i = 1; i < dates.size(); i++) {
        if(names.at(i) == tempCity.getName()) {
            setDateAQI(dates.at(i), aqi.at(i), tempCity);
        } else if (names.at(i) != tempCity.getName()) {
            cityList.push_back(tempCity);
            tempCity = setInitialCityName(names.at(i));
            setDateAQI(dates.at(i), aqi.at(i), tempCity);
            cout << "City " << count << ": " << tempCity.getName() << endl;
            count++;
        }
        //cout << tempCity.getName() << endl;
    }

}

// set the city name by calling City's member function setName() and push that city object into cityList vector
City Cities::setInitialCityName(string name) {
    City city;
    city.setName(name);
    // cityList.push_back(city);
    return city;
}

// returns the city name by going to the index i of cityList
string Cities::getCityName(int i) const {
    return cityList.at(i).getName();
}

void Cities::printList() {
    for(auto i : cityList) {
        cout << i.getName() << endl;
    }
}

void Cities::setDateAQI(string &date, int &aqi, City &city) {
    city.setCityDateAQI(date,aqi);
}

void Cities::getDateAQI(City city) {

}

void Cities::printCityMapSize(City city) {
    cout << city.getMapSize() << endl;
}

void Cities::lookUpCity(string name) {
    for(auto i : cityList) {
        if(i.getName() == name) {
            cout << "Found city!" << endl;
            i.printInfo();
            break;
        }
    }
}