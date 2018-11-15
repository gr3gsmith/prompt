#pragma once

#include "string_utils.h"

// Struct for defining colours and converting them to their bash representation.
template <unsigned tVALUE>
struct colour {
    constexpr static auto as_bash = make_string("\\033[") + make_string(num_to_string<tVALUE>::value) + make_string("m");
    constexpr static unsigned value = tVALUE;
};

template <typename tCOLOUR>
struct background_colour : colour<tCOLOUR::value + 10> {};

/* namespace to_background_impl { */
/*   // Convert a foreground colour to a background colour. */
/*   template <unsigned tFOREGROUND_VALUE> */
/*   colour<tFOREGROUND_VALUE + 10> background_equivalent(colour<tFOREGROUND_VALUE>); */
/* } */

/* template <typename tCOLOUR> */
/* struct to_background { */
/*   constexpr static auto as_bash = decltype(to_background_impl::background_equivalent(tCOLOUR()))::as_bash; */
/* }; */


// Specific colour values.
using BLACK = colour<30>;
using RED = colour<31>;
using GREEN = colour<32>;
using DEFAULT = colour<39>;
using WHITE = colour<97>;

