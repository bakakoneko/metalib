#include <metalib/tag_invoke.hpp>

#include <iostream>

struct printer {
    std::ostream& os;
};

// tag_invoke function can be created in the same namespace as the object to allow usage with meta::tag_invoke
template<typename Arg>
void tag_invoke(printer&& p, Arg&& arg) {
    p.os << arg;
}

struct printer_with_friend {
    std::ostream& os;

    // tag_invoke can also be added as a friend
    template<typename Arg>
    friend void tag_invoke(printer_with_friend&& p, Arg&& arg) noexcept {
        p.os << arg;
    }
};

int main() {
    meta::tag_invoke(printer{std::cout}, "Hello from printer\n");
    meta::tag_invoke(printer_with_friend{std::cout}, "Hello from printer_with_friend\n");
}
