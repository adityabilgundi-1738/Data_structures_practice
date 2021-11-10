#include <array>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
 
int main() {
  array<int, 5> arr1;
  array<int, 5> arr2;
 
  cout << "Sizes of arrays are" << endl;
  cout << arr1.size() << endl;
  cout << arr2.size() << endl;
   
  cout << "\nInitial ar1 : ";
  array<int, 5>::iterator it1 = arr1.begin();
  for (auto i : ar1)
    cout << i << ' ';
 
  // container operations are supported
  sort(ar1.begin(), ar1.end());
 
  cout << "\nsorted ar1 : ";
  for (auto i : ar1)
    cout << i << ' ';
 
  // Filling ar2 with 10
  ar2.fill(10);
 
  cout << "\nFilled ar2 : ";
  for (auto i : ar2)
    cout << i << ' ';
 
 
  // ranged for loop is supported
  cout << "\nar3 : ";
  for (auto &s : ar3)
    cout << s << ' ';
 
  return 0;
}