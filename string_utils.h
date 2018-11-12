#pragma once

namespace num_to_string_impl
{
  template <unsigned... digits>
  struct to_chars {
    static const char value[];
  };

  template <unsigned... digits>
  constexpr char to_chars<digits...>::value[] = {('0' + digits)..., 0};

  template <unsigned rem, unsigned... digits>
  struct explode : explode<rem / 10, rem % 10, digits...> {};

  template <unsigned... digits>
  struct explode<0, digits...> : to_chars<digits...> {};
}

// Convert an integral value to a string literal.
// Use this like:
// num_to_string<42>::value;
template <unsigned num>
struct num_to_string : num_to_string_impl::explode<num> {};


// Compile time constant string.
template <unsigned tSIZE>
class array_string {
public:
  constexpr array_string(const char (str)[tSIZE + 1])
    : m_chars{{0}}
  {
    for (unsigned i = 0; i <= tSIZE; ++i) {
      m_chars[i] = str[i];
    }
  } 

  template <unsigned tSIZE_1>
  constexpr array_string(const array_string<tSIZE_1>& str1, const array_string<tSIZE - tSIZE_1>& str2)
    : m_chars{{0}}
  {
    for (int i = 0; i < tSIZE_1; ++i) {
      m_chars[i] = str1[i];
    }
    for (int i = 0; i < tSIZE - tSIZE_1; ++i) {
      m_chars[tSIZE_1 + i] = str2[i];
    }
    m_chars[tSIZE] = '\0';
  }
  
  constexpr char operator[](const unsigned index) const
  {
    /* static_assert(index <= tSIZE); // Why doesn't this work? */
    return m_chars[index];
  }

  constexpr const char* c_str() const
  {
    return m_chars;
  }

private:
  char m_chars[tSIZE + 1];
};

// Create an array_string from a string literal.
// Allows usage like:
// auto str = literal("Hello world");
// Without having to include the string length argument.
template <unsigned tSIZE_PLUS_1>
constexpr array_string<tSIZE_PLUS_1 - 1> make_string(const char (&lit)[tSIZE_PLUS_1])
{
  return array_string<tSIZE_PLUS_1 - 1>(lit);
}

// Concatenate two array strings.
template <unsigned tSIZE_1, unsigned tSIZE_2>
constexpr array_string<tSIZE_1 + tSIZE_2> operator+(
  const array_string<tSIZE_1>& str1,
  const array_string<tSIZE_2>& str2
)
{
  return array_string<tSIZE_1 + tSIZE_2>(str1, str2);
}

// Length of string (not including terminating null).
constexpr unsigned length(const char* str)
{
    int result = 0;
    while (*str) {
        ++result;
        ++str;
    }
    return result;
}


// This implementation of concatenation works but with some fairly nasty restrictions.
/* template <const char*, typename, const char*, typename> */
/* struct concat_impl; */

/* template <int... I> */
/* using IntSeq = std::integer_sequence<int, I...>; */
/* template <int N> */
/* using MakeIntSeq = std::make_integer_sequence<int, N>; */

/* template <const char* tSTR1, int... tINT_SEQ1, const char* tSTR2, int... tINT_SEQ2> */
/* struct concat_impl<tSTR1, IntSeq<tINT_SEQ1...>, tSTR2, IntSeq<tINT_SEQ2...>> { */
/*     static constexpr const char value[] { */
/*         tSTR1[tINT_SEQ1]..., tSTR2[tINT_SEQ2]..., 0 */
/*     }; */
/* }; */

/* template <const char* tSTR1, const char* tSTR2> */
/* constexpr auto concat { */
/*     concat_impl<tSTR1, MakeIntSeq<length(tSTR1)>, tSTR2, MakeIntSeq<length(tSTR2)>>::value */
/* }; */

