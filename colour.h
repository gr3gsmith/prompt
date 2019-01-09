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

// Specific colour values.
using BLACK = colour<30>;
using RED = colour<31>;
using GREEN = colour<32>;
using YELLOW = colour<33>;
using BLUE = colour<34>;
using MAGENTA = colour<35>;
using CYAN = colour<36>;
using LIGHT_GREY = colour<37>;
using DEFAULT = colour<39>;
using DARK_GREY = colour<90>;
using LIGHT_RED = colour<91>;
using LIGHT_GREEN = colour<92>;
using LIGHT_YELLOW = colour<93>;
using LIGHT_BLUE = colour<94>;
using LIGHT_MAGENTA = colour<95>;
using LIGHT_CYAN = colour<96>;
using WHITE = colour<97>;

