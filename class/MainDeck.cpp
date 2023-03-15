#include "MainDeck.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

MainDeck::MainDeck(){
    size = 52;

    vector<int> nums;
    for(int i = 0; i < 52; i++) {
        nums.push_back(i + 1);
        //cout << "Nums: " << i + 1 << endl;
        }

    for(int i = 0; i < 52; i++){
        srand(time(NULL));
        int upperBound = 52 - i;
        int random = rand() % upperBound;
        int picked = nums.at(random);
        
        if(picked <= 13){
            Cards.push(MainCard(Green, picked));
            //cout << "Color: Green" << " Number: " << picked << endl;
        }else if(picked <= 26 && picked > 13){
            Cards.push(MainCard(Blue, picked - 13));
            //cout << "Color: Blue" << " Number: " << picked - 13 << endl;
        }else if(picked <= 39 && picked > 26){
            Cards.push(MainCard(Yellow, picked - 26));
            //cout << "Color: Yellow" << " Number: " << picked - 26 << endl;
        }else{
            Cards.push(MainCard(Red, picked - 39));
            //cout << "Color: Red" << " Number: " << picked - 39 << endl;
        }  

        nums.erase(nums.begin() + random);
        nums.shrink_to_fit();

    }
}

MainDeck::MainDeck(const MainDeck& other){
    this->size = other.size;
    this->Cards = other.Cards;
}

MainDeck::MainDeck(string filepath){
    fstream file;

    //Check for errors
    file.open(filepath, ios::in);
    if(file.is_open()){
        string line;
        string linews;
        int count = 0;
        while(getline(file, line)){
            int j = 0;
            Colors color;
            int number;

            for(int i = 0; i < line.length(); i++){
                if(line[i] != ' '){
                    linews[j] = line[i];
                    j++;
                }
            }
            //cout << linews[0] << linews[1] << endl;

            // CHECK ERROR
            if(j > 3 || j < 2){
                //cout << "error jumlah char" << endl;
                //Error jumlah char
                throw InvalidCardException();
                
            }

            if(linews[0] != 'G' && linews[0] != 'g' && linews[0] != 'B' && linews[0] != 'b' && linews[0] != 'Y' && linews[0] != 'y' && linews[0] != 'R' && linews[0] != 'r'){
                //cout << "error invalid color" << endl;
                //Error invalid color
                throw InvalidCardException();
            }else{
                if(linews[0] == 'G' || linews[0] == 'g'){
                    color = Green;
                }else if(linews[0] == 'B' || linews[0] == 'b'){
                    color = Blue;
                }else if(linews[0] == 'Y' || linews[0] == 'y'){
                    color = Yellow;
                }else{
                    color = Red;
                }
            }

            if((j == 2 && (linews[1] < 49 || linews[1] > 57)) || (j == 3 && (linews[1] != '1' || linews[2] < 48 || linews[2] > 51))){
                //cout << "error invalid number" << endl;
                //Erorr invalid number
                throw InvalidCardException();
            }else{
                number = linews[1] - '0';
                if(j == 3){
                    number += (linews[2] - '0') + 9;
                }
                //cout << number << endl;
            }

            if(isInside(MainCard(color, number))){
                throw DuplicateCardsException();
            }

            Cards.push(MainCard(color, number));


            count++;
            // cout << "length: " << line.length() << endl;
            // cout << "Color: " << Cards.top().getColor() << endl;
            // cout << "Number " << number << endl;
            // if(line.length() > 2){
            //     cout << line[2];
            // }
            // cout << endl;
        }

        if(count > 52){
            throw TooManyCardsException();
        }else if(count < 52){
            throw TooFewCardsException();
        }

        size = count;
        file.close();
    }else{
        throw InvalidFileException();
    }


}

MainDeck::~MainDeck(){}

MainDeck& MainDeck::operator=(const MainDeck& other){
    this->size = other.size;
    this->Cards = other.Cards;
}

int MainDeck::getSize(){
    return size;
}

MainCard MainDeck::draw(){
    MainCard drew = Cards.top();
    Cards.pop();
    size--;
    return drew;
}

bool MainDeck::isInside(MainCard mc){
    vector<MainCard> cardVector;
    stack<MainCard> temp = Cards;
    for(int i = 0; i < Cards.size(); i++){
        cardVector.push_back(temp.top());
        temp.pop();
    }

    if(find(cardVector.begin(), cardVector.end(), mc) != cardVector.end()){
        return true;
    }
    return false;
}
