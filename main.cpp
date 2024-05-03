#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

//This function takes the value(sortingVector.second) from a vector of pairs that I used
//and compares it with next value, returns true/false on whether or not to swap vector into decending order
bool decendingValueSort(pair<string, int>& a, pair<string, int>& b) 
{ 
    return a.second > b.second; 
} 

int main(int argc, char* argv[])
{
    vector<string> wordVector;  //stores words from file reading
    string str;     //tmp string to fill wordVector
    int groupCount = 0; //stores number of groups in umap
    int tmpCount = 1;   //used for cout'ing group number in final outputting

    ifstream fileRead(argv[1]);     //read file based off command line arg 1

    while (fileRead >> str)     //while reading in from file into temp string
    {
        sort(str.begin(), str.end());   //sort each individual word
        wordVector.push_back(str);      //add it to vector
    }

    unordered_map<string, int> umap;    //make unordered map

    for (auto anagram : wordVector)
        umap[anagram]++;                //populate umap

    vector<pair<string, int>> sortingVector;    //create vector of pairs

    for (auto anagram : umap)
        sortingVector.push_back(anagram);   //populate vector pairs

    sort(sortingVector.begin(), sortingVector.end(), decendingValueSort);   //sort in decennding order of value

    for (auto x : sortingVector)    //count number of groups
        groupCount++;
    
    cout << "Amount of Groups: " << groupCount << endl << endl;

    for (auto x : sortingVector)
        cout << "Group " << tmpCount++ << " contains " << x.second << " words" << endl;     //output to terminal

    return 0;
}
