
#include "bracket_push.h"


#include <stack>

bool bracket_push::check(const std::string& bracket_string) {
    // store each bracket on a stack and ensure that the next closing one
    // matches the top most one, then pop it.
    std::stack<char> bracket_stack;
    for (char c : bracket_string) {
        if (is_closing(c)) {
            if (bracket_stack.size() == 0) return false;
            // incorrect most recent bracket?
            if (!matching(bracket_stack.top(), c)) return false;

            bracket_stack.pop();
        } else if (is_opening(c)) {
            bracket_stack.push(c);
        }
        // otherwise ignore non bracket chars
    }
    // we made it here? check if we haven't got any more unmatched brackets in our stack
    return bracket_stack.empty();
}


bool bracket_push::matching(const char& opening, const char& closing) {
    switch (opening) {
        case '[':
            return closing == ']';
        case '(':
            return closing == ')';
        case '{':
            return closing == '}';
    }
    throw std::runtime_error("invalid bracket character provided");
}
