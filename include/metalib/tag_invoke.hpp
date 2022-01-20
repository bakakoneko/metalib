#ifndef METALIB_METALIB_TAG_INVOKE_HPP
#define METALIB_METALIB_TAG_INVOKE_HPP

#include "config.hpp"

namespace METALIB_NAMESPACE {
    namespace detail {
        struct tag_invoke_fn {
            template <typename CPO, typename... Args>
            constexpr auto operator()(CPO&& cpo, Args&&... args) const {
                return tag_invoke(std::forward<CPO>(cpo), std::forward<Args>(args)...);
            }
        };
    }

    inline namespace tag_invoke_ns {
        constexpr detail::tag_invoke_fn tag_invoke{};
    }
}

#endif //METALIB_METALIB_TAG_INVOKE_HPP
