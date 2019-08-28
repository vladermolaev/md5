#pragma once
#include <string>

const char hexDigits[] = "0123456789abcdef";

inline void addByte(const unsigned char byte, std::string& res) {
  res += hexDigits[(byte >> 4) & 15];
  res += hexDigits[byte & 15];
}

template <class T>
inline void addByte(const unsigned char byte, T& res) {
  res << hexDigits[(byte >> 4) & 15];
  res << hexDigits[byte & 15];
}
