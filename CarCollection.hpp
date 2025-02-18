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
#ifndef CARCOLLECTION_HPP
#define CARCOLLECTION_HPP

template<class T>

class CarCollection{

    public:
        /* default constructor */
        CarCollection();

        /* parameterized constructor with parameter const int& size */
        CarCollection(const int& size);

        /** Gets the current number of entries in this bag.
         @return The integer number of entries currently in the bag. 
        */
        virtual int getCurrentSize() const;

        /** Sees whether this bag is empty. 
         @return True if the bag is empty, or false if not.
         */
        virtual bool isEmpty() const;

        /** Adds a new entry to this bag. 
        @post If successful, newEntry is stored in the bag and 
        the count of items in the bag has increased by 1. 
        @param newEntry The object to be added as a new entry. 
        @return True if addition was successful, or false if not.
         */
        virtual bool add(const T& newEntry);

        /** Removes one occurrence of a given entry from this bag, 
        if possible. 
        @post If successful, anEntry has been removed from the bag
        and the count of items in the bag has decreased by 1. 
        @param anEntry The entry to be removed. 
        @return True if removal was successful, or false if not.
         */
        virtual bool remove(const T& anEntry);

        /** Removes all entries from this bag.
        @post Bag contains no items, and the count of items is 0. 
        */
        virtual void clear();

        /** Counts the number of times a given entry appears in bag. 
        @param anEntry The entry to be counted. 
        @return The number of times anEntry appears in the bag.
         */
        virtual int getFrequencyOf(const T& anEntry);

        /** Tests whether this bag contains a given entry. 
        @param anEntry The entry to locate. 
        @return True if bag contains anEntry, or false otherwise. 
        */
        virtual bool contains(const T& anEntry);

        /** Empties and then f ills a given vector with all entries that
        are in this bag. 
        @return A vector containing all the entries in the bag. 
        */
        virtual vector<T> toVector() const;

        /* display information */
        virtual void display() const;

        /* check the duplications
           para: anEntry
           return: duplicates
         */
        virtual vector<T> duplicate(const T& anEntry);

    private:
        /* private date members */
        vector<T> Cars;
        int current_size_;

};


/* Implementations for functions */
template<class T>
CarCollection<T>::CarCollection(): current_size_ (0){}

template<class T>
CarCollection<T>::CarCollection(const int& size): current_size_(size){}


template<class T>
int CarCollection<T>::getCurrentSize() const{

    return current_size_;

}

template<class T>
bool CarCollection<T>::isEmpty() const{

    return current_size_ == 0;
    
}

template<class T>
bool CarCollection<T>::add(const T& newEntry){

    Cars.push_back(newEntry);

    current_size_++;

    return true;

}

template<class T>
bool CarCollection<T>::remove(const T& anEntry){

    auto it = find(Cars.begin(), Cars.end(), anEntry);
    if(it != Cars.end()){

        Cars.erase(it);
    
         current_size_--;

         return true;
    }

        return false;

}

template<class T>
void CarCollection<T>::clear(){

    Cars.clear();
    current_size_ = 0;

}

template<class T>
int CarCollection<T>::getFrequencyOf(const T& anEntry){

    int count = 0;

    for(const auto& car: Cars){

     if(car == anEntry){

        count++;
     }

    }

    return count;

}

template<class T>
bool CarCollection<T>::contains(const T& anEntry){

    for(const auto& car: Cars){
        
        if(car == anEntry){

            return true;
        }
    }
        return false;

}


template<class T>

vector<T> CarCollection<T>::toVector() const {

    return Cars;
}

template<class T>

vector<T> CarCollection<T>::duplicate(const T& anEntry){

    vector<T> duplicates;

    for(auto& car: Cars){

        if(car == anEntry){

            duplicates.push_back(car);
        }

    }

    return duplicates;

}

template<class T>

void CarCollection<T>::display() const{

vector <T> myCarList = this->toVector();

cout <<"The number of my cars: " << myCarList.size() << endl;

cout <<"All the cars in my collection: " << endl;

for(auto& car: myCarList){

    cout << car << endl;
}

}



#endif // CARCOLLECTION_HPP