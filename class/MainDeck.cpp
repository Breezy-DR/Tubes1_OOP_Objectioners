#include "MainDeck.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>
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

            if(j > 3 || j < 2){
                cout << "error jumlah char" << endl;
                //Error jumlah char
            }

            if(linews[0] != 'G' && linews[0] != 'g' && linews[0] != 'B' && linews[0] != 'b' && linews[0] != 'Y' && linews[0] != 'y' && linews[0] != 'R' && linews[0] != 'r'){
                cout << "error invalid color" << endl;
                //Error invalid color
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
                cout << "error invalid number" << endl;
                //Erorr invalid number
            }else{
                number = linews[1] - '0';
                if(j == 3){
                    number += (linews[2] - '0') + 9;
                }
                //cout << number << endl;
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

        // if(count != 52){
        //     //Error card amount
        // }
        size = count;

        file.close();
    }else{
        //CAN'T OPEN FILE ERROR
    }


}

MainDeck::~MainDeck(){}

int MainDeck::getSize(){
    return size;
}

MainCard MainDeck::draw(){
    MainCard drew = Cards.top();
    Cards.pop();
    size--;
    return drew;
}
