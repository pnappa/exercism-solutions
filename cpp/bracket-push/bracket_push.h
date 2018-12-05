
#pragma once

#include <string>
#include <stdexcept>

namespace bracket_push {
    bool check(const std::string& bracket_string);

    /* if opening & closing are of the same bracket type */
    bool matching(const char& opening, const char& closing);

    inline bool is_closing(const char& c) { return c == ']' || c == ')' || c == '}'; }
    inline bool is_opening(const char& c) { return c == '[' || c == '(' || c == '{'; }
}
