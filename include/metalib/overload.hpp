/// \file overload.hpp
/// \brief Includes functions for resolving overloads.

#ifndef METALIB_METALIB_OVERLOAD_HPP
#define METALIB_METALIB_OVERLOAD_HPP

#include "config.hpp"

#include <concepts>

namespace METALIB_NAMESPACE {
    /// \brief Resolves an overload of a member function.
    /// \tparam R result type
    /// \tparam C class type
    /// \param f member function pointer
    /// \return resolved function
    template<typename R, typename C>
    [[nodiscard]] constexpr auto overload(R C::*f) noexcept {
        return f;
    }

    /// \brief Resolves an overload of a function.
    /// \tparam F target function type
    /// \param func overloaded function
    /// \return target function
    template<typename F>
    [[nodiscard]] constexpr auto overload(F func) noexcept {
        return func;
    }
}

#endif //METALIB_METALIB_OVERLOAD_HPP
