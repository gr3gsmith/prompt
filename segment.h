#pragma once

#include "string_utils.h"
#include "colour.h"

template <typename tBACKGROUND, typename tFOREGROUND, unsigned tTEXT_SIZE>
constexpr auto segment(const array_string<tTEXT_SIZE>& text)
{
  return tBACKGROUND::as_bash + tFOREGROUND::as_bash + text;
}

