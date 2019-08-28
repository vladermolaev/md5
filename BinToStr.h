#ifndef BINTOSTR_H
#define BINTOSTR_H
#include <string>
#include "Byte2Hex.h"

template <class It>
std::string BytesToHexString(It first, It last) {
  std::string s;
  s.reserve((last - first + 1) * 3 + (last - first) / 16);
  for (unsigned char count = 1; first != last && count < 32; ++first, ++count) {
    if (count % 32 == 0) {
      count = 0;
      s += '\n';
    }
    s += ' ';
    addByte(*first, s);
  }
  if (first != last) s += " ...";
  return s;
}

template <class T>
std::string BytesToHexString(const T& v) {
  auto first = std::begin(v), last = std::end(v);
  return BytesToHexString(first, last);
}

//template <class It>
//std::ofstream& BytesToHexStream(std::ofstream& s, It first, It last) {
//  for (; first != last; ++first) {
//    s << ' ';
//    addByte(*first, s);
//  }
//  return s;
//}

#endif  // BINTOSTR_H