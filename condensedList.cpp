#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    //a list of names
    vector<string> names = { "Tom", "Jim", "Sue", "Tom",
    "Kim", "Sue", "Tom", "Jon", "Sam" };
    //maps a name to its occurrence count
    unordered_map<string, int> condensedList;
    //keep a tally of each name
    for (auto name : names)
    condensedList[name]++;
    //traverse each element in the map
    for (auto name : condensedList)
    {
        //output the entry's key (name)
        cout << name.first;
        //if its tally amount is more than 1, this name
        //is duplicated in the original list
        if (name.second > 1)
        cout << " (Duplicated)";
        cout << endl;
    }
    return 0;
}
