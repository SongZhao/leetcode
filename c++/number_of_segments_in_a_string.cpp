/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5

*/

/*
 *
*/


#include "helper.h"

class Solution {
public:
    int countSegments(string s) {
      int res = 0;
      bool start = false;
      for (char c:s) {
        if (!isspace(c)) {
          if (!start) {
              res++;
              start = true;
          }
        } else {
          start = false;
        }
      }
      return res;
    }
};

int main() {
  Solution s;
  cout << s.countSegments("Hello, my name is John") << endl;
  cout << s.countSegments("love live! mu'sic forever") << endl;
  cout << s.countSegments(", , , ,        a, eaefa") << endl;

  return 0;
}
