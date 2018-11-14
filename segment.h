#pragma once

#include "string_utils.h"
#include "colour.h"

template <typename tBACKGROUND, typename tFOREGROUND, unsigned tTEXT_SIZE>
class segment {
public:
  constexpr segment(const array_string<tTEXT_SIZE>& text)
    : m_text(text)
  {}

  constexpr auto as_bash() const
  {
    return tBACKGROUND::as_bash + m_text + tFOREGROUND::as_bash;
  }

private:
  const array_string<tTEXT_SIZE> m_text;
};

