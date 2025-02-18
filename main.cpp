/* 
Author: Cheng Yue
Date: 2/17/2025
Descrpition: practice for ADT BAG
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#include"CarCollection.hpp"


int main(){

vector<string> Cars = {"Toyota", "Mercedes-Benz",
                        "Honda", "BMW", "Jeep",
                        "Tesla", "Land Rover"  };

CarCollection <string> car_collection;

for(const auto& car: Cars){

    car_collection.add(car);

}

car_collection.add("Royals Rollers");
car_collection.add("Ford");
car_collection.add("BMW");
car_collection.add("Ferrari");

car_collection.display();

vector<string>duplicates = car_collection.duplicate("BMW");

cout <<"The duplicates of 'BMW': " << endl;

for(const auto& car : duplicates){

    cout << car << endl;

}

cout <<"Frequency of 'Mercedes-Benz': " << car_collection.getFrequencyOf("Mercedes-Benz") << endl;

cout <<"Frequency of 'BMW': " << car_collection.getFrequencyOf("BMW") << endl;

cout <<"Contains 'Lexus': " << car_collection.contains("Lexus") << endl;


}