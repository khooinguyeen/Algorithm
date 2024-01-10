#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    map<int, int> myMap;

    // insert element in random order
    myMap.insert(pair<int, int>(1, 40));
    myMap.insert(pair<int, int>(2, 30));
    myMap.insert(pair<int, int>(3, 60));
    myMap.insert(pair<int, int>(4, 20));
    myMap.insert(pair<int, int>(5, 50));
    myMap.insert(pair<int, int>(6, 50));

    // alternative way to insert a value
    myMap[7] = 10;

    // printing map
    map<int, int>::iterator it;
    cout << "\nThe map is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << '\t' << it->first << '\t' << it->second << '\n';
    }
    cout << endl;

    map<int, int> anotherMap(myMap.begin(), myMap.end());
    // assigning element from myMap to anotherMap
    cout << "\nThe map anotherMap after assigning from myMap is :\n \tKEY\tELEMENT\n";
    for (it = anotherMap.begin(); it != anotherMap.end(); ++it)
    {
        cout << '\t' << it->first << '\t' << it->second << '\n';
    }
    cout << endl;

    // remove all elements up to
    // element with key=3 in anotherMap
    cout << "\nanotherMap after removal of"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    anotherMap.erase(anotherMap.begin(), anotherMap.find(3));
    for (it = anotherMap.begin(); it != anotherMap.end(); ++it) {
        cout << '\t' << it->first << '\t' << it->second
             << '\n';
    }

    // remove all elements with key = 4
    int num;
    num = anotherMap.erase(4);
    cout << "\nanotherMap.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    for (it = anotherMap.begin(); it != anotherMap.end(); ++it) {
        cout << '\t' << it->first << '\t' << it->second
             << '\n';
    }
 
    cout << endl;
 
    // lower bound and upper bound for map myMap key = 5
    cout << "myMap.lower_bound(5) : "
         << "\tKEY = ";
    cout << myMap.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = " << myMap.lower_bound(5)->second
         << endl;
    cout << "myMap.upper_bound(5) : "
         << "\tKEY = ";
    cout << myMap.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = " << myMap.upper_bound(5)->second
         << endl;
 
    return 0;
}