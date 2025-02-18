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
        CarCollection();
        CarCollection(const int& size);
        virtual int getCurrentSize() const;
        virtual bool isEmpty() const;
        virtual bool add(const T& newEntry);
        virtual bool remove(const T& anEntry);
        virtual void clear();
        virtual int getFrequencyOf(const T& anEntry);
        virtual bool contains(const T& anEntry);
        virtual vector<T> toVector() const;
        virtual void display() const;
        virtual vector<T> duplicate(const T& anEntry);

    private:

        vector<T> Cars;
        int current_size_;

};

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