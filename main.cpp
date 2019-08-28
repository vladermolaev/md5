#include <iostream>
#include "md5.h"
#include "BinToStr.h"

int main(int argc, const char* argv[]) {
  int count = 1;
  if (argc > 1) count = atoi(argv[1]);
  unsigned char result[16] = {};
  MD5_CTX md5;
  while (count--) {
    const auto data = std::to_string(count);
    MD5_Init(&md5);
    MD5_Update(&md5, data.c_str(), data.length());
    MD5_Final(result, &md5);
    std::cout << BytesToHexString(result) << "\n";
  }
}
