#include <iostream>
#include <list>

using namespace std;

void showList(list<int> l)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        cout << "\t" << *it;
    cout << endl;
}

int main()
{
    list<int> list1, list2;

    for (int i = 0; i < 10; i++)
    {
        list1.push_back(i * 2);
        list2.push_back(i * 3);
    }
    cout << "\nList 1 (list1) is : ";
    showList(list1);
 
    cout << "\nList 2 (list2) is : ";
    showList(list2);
 
    cout << "\nlist1.front() : " << list1.front();
    cout << "\nlist1.back() : " << list1.back();
 
    cout << "\nlist1.pop_front() : ";
    list1.pop_front();
    showList(list1);
 
    cout << "\nlist2.pop_back() : ";
    list2.pop_back();
    showList(list2);
 
    cout << "\nlist1.reverse() : ";
    list1.reverse();
    showList(list1);
 
    cout << "\nlist2.sort(): ";
    list2.sort();
    showList(list2);
 
    return 0;

}