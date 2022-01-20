/// \file tag_invoke.hpp
/// \brief Defines the tag_invoke function.

#ifndef METALIB_METALIB_TAG_INVOKE_HPP
#define METALIB_METALIB_TAG_INVOKE_HPP

#include "config.hpp"

#include <utility>

namespace METALIB_NAMESPACE {
    namespace detail {
        /// \private
        struct tag_invoke_fn {
            template <typename CPO, typename... Args>
            constexpr auto operator()(CPO&& cpo, Args&&... args) const {
                return tag_invoke(std::forward<CPO>(cpo), std::forward<Args>(args)...);
            }
        };
    }

    inline namespace tag_invoke_ns {
        /// \brief Invokes a CPO using tag_invoke.
        constexpr detail::tag_invoke_fn tag_invoke{};
    }
}

#endif //METALIB_METALIB_TAG_INVOKE_HPP
