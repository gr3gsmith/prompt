#include <iostream>
#include "string_utils.h"
#include "colour.h"
#include "segment.h"


int main()
{
  std::cout << "function smithg_powerline_prompt {" << std::endl;

  std::cout << "PS1=\"\"" << std::endl;

  auto prompt = segment_sequence(
    make_segment<DARK_GREY, WHITE>(make_string(" \\w ")),
    segment_sequence(
      git_segment<WHITE, BLACK>(),
      end_of_segment_sequence()
    )
  );

  std::cout << prompt.as_bash().c_str() << std::endl;

  std::cout << "}" << std::endl;
}


