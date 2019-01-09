#pragma once

#include "string_utils.h"

constexpr auto SEGMENT_SEPARATOR = make_string("$SEGMENT_SEPARATOR");

template <unsigned tSIZE>
constexpr auto add_to_prompt(const array_string<tSIZE>& to_add)
{
  return make_string("PS1+=\"") + to_add + make_string("\"\n");
}

