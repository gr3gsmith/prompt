/* #include <cstdio> */
#include <iostream>
#include "string_utils.h"

int constexpr length(const char* str)
{
  return *str ? 1 + length(str + 1) : 0;
}


int main()
{
  /* constexpr const char* prompt = "\\w"; */
  /* fwrite(prompt, length(prompt), 1, stdout); */

  auto str1 = literal(num_to_string<25>::value);
  auto str2 = literal("Hello ");
  auto str3 = str2 + str1;
  std::cout << str3.c_str() << std::endl;
}


