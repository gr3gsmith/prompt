#pragma once

#include "string_utils.h"
#include "colour.h"

template <unsigned tSIZE>
constexpr auto add_to_prompt(const array_string<tSIZE>& to_add)
{
  return make_string("PS1+=\"") + to_add + make_string("\"\n");
}

template <typename tBACKGROUND, typename tFOREGROUND, unsigned tTEXT_SIZE>
class segment {
public:
  constexpr segment(const array_string<tTEXT_SIZE>& text) : m_text(text) {}

  constexpr auto as_bash() const
  {
    return add_to_prompt(background_colour<tBACKGROUND>::as_bash + tFOREGROUND::as_bash + m_text);
  }

private:
  const array_string<tTEXT_SIZE> m_text;
};


// Convenience function for creating segments without having to specify the text string size.
template <typename tBACKGROUND, typename tFOREGROUND, typename tTEXT>
constexpr auto make_segment(const tTEXT& text)
{
  return segment<tBACKGROUND, tFOREGROUND, tTEXT::size>(text);
}

template <typename tBACKGROUND, typename tFOREGROUND>
class git_segment {
public:
  constexpr auto as_bash() const
  {
    // Get git branch.
    constexpr auto setup = make_string("local git_branch=\"$(fast_git_branch)\"\n");
    constexpr auto condition = make_string("if [[ ! -z \"$git_branch\" ]]; then\n");
    constexpr auto segment = make_segment<tBACKGROUND, tFOREGROUND>(make_string("$git_branch"));
    constexpr auto end_if = make_string("fi\n");
    return setup + condition + segment.as_bash() + end_if;
  }
};


class end_of_segment_sequence {
public:
  constexpr auto as_bash() const
  {
    return add_to_prompt(DEFAULT::as_bash + background_colour<DEFAULT>::as_bash + make_string("\\n"));
  }
};

template <typename tSEGMENT, typename tNEXT>
class segment_sequence {
public:
  constexpr segment_sequence(const tSEGMENT& seg, const tNEXT& next)
    : m_segment(seg),
      m_next(next)
  {}

  constexpr auto as_bash() const
  {
    return m_segment.as_bash() + m_next.as_bash();
  }

private:
  const tSEGMENT m_segment;
  const tNEXT m_next;
};

