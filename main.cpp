#include <iostream>
#include "string_utils.h"
#include "colour.h"
#include "segment.h"


int main(int argc, char* argv[])
{
  std::cout << "function smithg_prompt {" << std::endl;

  std::cout << "PS1=\"\"" << std::endl;

  auto basicPrompt = segment_sequence(
    make_segment<DARK_GREY, WHITE>(make_string(" \\w ")),
    segment_sequence(
      git_segment<WHITE, BLACK>(),
      end_of_segment_sequence()
    )
  );

  if (argc == 2) {
    std::string shellType = argv[1];
    if (shellType == "cygwin") {
      auto cygwinPrompt = segment_sequence(
					   make_segment<MAGENTA, BLACK>(make_string(" Cygwin ")),
					   basicPrompt
					   );
      std::cout << cygwinPrompt.as_bash().c_str() << std::endl;
    } else if (shellType == "gitbash") {
      auto gitBashPrompt = segment_sequence(
					    make_segment<GREEN, BLACK>(make_string(" Git Bash ")),
					    basicPrompt
					    );
      std::cout << gitBashPrompt.as_bash().c_str() << std::endl;
    } else {
      std::cout << basicPrompt.as_bash().c_str() << std::endl;
    }
  } else {
    std::cout << basicPrompt.as_bash().c_str() << std::endl;
  }

  std::cout << "}" << std::endl;
}


