#include <iostream>
#include "../src/LCGenerator.hpp"
#include "../src/xoroshiro.hpp"
#include "../src/mixer.h"
#include <cstdio>
#include <cstdlib>

uint64_t identity_mixer(uint64_t val)
{
  return val;
}

int main()
{
  std::deque<uint64_t> a1{5}, a2{2};
  std::deque<uint64_t> b1{1,2}, b2 {1,2};
  LCGenerator l(a1, a2);
  xoroshiroGenerator x(b1, b2);
  //  combinationGenerator<uint64_t> c(l, x, &degski64);
  combinationGenerator<uint64_t> c(l, x, &lea64);  
  while(true) {
    auto o = c.generateNumber();
    fwrite((void *) &o, sizeof(o), 1, stdout);
  }

  return 0;
}
