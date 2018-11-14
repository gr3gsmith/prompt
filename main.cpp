/* #include <cstdio> */
#include <iostream>
#include "string_utils.h"
#include "colour.h"
#include "segment.h"


int main()
{
  /* constexpr const char* prompt = "\\w"; */
  /* fwrite(prompt, length(prompt), 1, stdout); */

  /* auto str1 = literal(num_to_string<25>::value); */
  /* auto str2 = literal("Hello "); */
  /* auto str3 = str2 + str1; */
  /* std::cout << str3.c_str() << std::endl; */

  /* std::cout << RED::as_bash.c_str() << std::endl; */
  /* std::cout << to_background<RED>::as_bash.c_str() << std::endl; */

  std::cout << segment<background_colour<RED>, GREEN>(make_string("Hello world")).c_str();
  std::cout << (DEFAULT::as_bash + background_colour<DEFAULT>::as_bash).c_str() << std::endl;
}


