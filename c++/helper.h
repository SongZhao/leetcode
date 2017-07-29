#include <iostream>
#include <ostream>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;

template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& out, const map<T1,T2>& m) {
  if (m.empty()) {
    out << "{}";
  }
  for(auto it = m.begin(); it != m.end(); ++it) {
    out << it->first << ":" << it->second << ";";
  }
  return out;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& out, const unordered_map<T1,T2>& m) {
  if (m.empty()) {
    out << "{}";
  }
  for(auto it = m.begin(); it != m.end(); ++it) {
    out << it->first << ":" << it->second << ";";
  }
  return out;
}
