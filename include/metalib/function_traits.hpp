/// \file function_traits.hpp
/// \brief Includes utilities for introspecting function types.

#ifndef METALIB_METALIB_FUNCTION_TRAITS_HPP
#define METALIB_METALIB_FUNCTION_TRAITS_HPP

#include "config.hpp"

#include <tuple>

namespace METALIB_NAMESPACE {
    /// \brief Traits for function types.
    ///
    /// Allows introspection of functions and function objects.
    /// \tparam T functional type
    template<typename T>
    struct function_traits;

    /// \private
    template<typename T> requires requires{ &T::operator(); }
    struct function_traits<T> : function_traits<decltype(&T::operator())> {};

    /// \private
    template<typename R, typename... Args>
    struct function_traits<R(Args...)> {
        using result_type = R;
        using args = std::tuple<Args...>;
    };

    /// \private
    template<typename R, typename ...Args>
    struct function_traits<R(*)(Args...)> : function_traits<R(Args...)> {};

    /// \private
    template<typename R, typename ...Args>
    struct function_traits<R(*)(Args...) noexcept> : function_traits<R(Args...)> {};

    /// \private
    template<typename R, typename ...Args>
    struct function_traits<R(&)(Args...)> : function_traits<R(Args...)> {};

    /// \private
    template<typename R, typename ...Args>
    struct function_traits<R(&)(Args...) noexcept> : function_traits<R(Args...)> {};

    /// \private
    template<typename R, typename C, typename ...Args>
    struct function_traits<R(C::*)(Args...)> : function_traits<R(Args...)> { using class_type = C; };

    /// \private
    template<typename R, typename C, typename ...Args>
    struct function_traits<R(C::*)(Args...) noexcept> : function_traits<R(C::*)(Args...)> {};

    /// \private
    template<typename R, typename C, typename ...Args>
    struct function_traits<R(C::*)(Args...) const> : function_traits<R(C::*)(Args...)> {};

    /// \private
    template<typename R, typename C, typename ...Args>
    struct function_traits<R(C::*)(Args...) const noexcept> : function_traits<R(C::*)(Args...)> {};
}

#endif //METALIB_METALIB_FUNCTION_TRAITS_HPP
