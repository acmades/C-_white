#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
   ReversibleString() {}
   ReversibleString (const string& b) {
      a = b;
   }
   void Reverse() {
      reverse(begin(a), end(a));
   }
   string ToString() const {
      return a;
   }
private:
   string a;
};