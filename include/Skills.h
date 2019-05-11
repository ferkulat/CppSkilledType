//
// Created by marcel on 5/11/19.
//

#ifndef SKILLED_TYPE_SKILLS_H
#define SKILLED_TYPE_SKILLS_H
#include "SkilledType.h"
#include "Crtp.h"
namespace skilled_type {
    template <typename T, typename TypeTag, template <typename> typename... Skills>
    std::istream& operator>>(std::istream& is, SkilledType<T, TypeTag, Skills...>& target)
    {
        is >> target.value;
        return is;
    }

    template <typename T, typename TypeTag, template <typename> typename... Skills>
    std::ostream& operator<<(std::ostream& os, SkilledType<T, TypeTag, Skills...> const& target)
    {
        os << target.value;
        return os;
    }

    template <typename T> struct Equality : public Crtp<T, Equality>
    {
        constexpr bool operator==(T const& other) const
        {
            return other.Get() == this->underlying().Get();
        }
        constexpr bool operator!=(T const& other) const
        {
            return other.Get() != this->underlying().Get();
        }
    };

    template <typename T> struct Relativity : public Crtp<T, Relativity>
    {
        constexpr bool operator<(T const& other) const
        {
            return this->underlying().Get() < other.Get();
        }
        constexpr bool operator>(T const& other) const
        {
            return this->underlying().Get() > other.Get();
        }
    };

    template <typename T> struct Additivity : public Crtp<T, Additivity>
    {
        constexpr T operator+(T const& other) const
        {
            return T(other.Get() + this->underlying().Get());
        }
    };

    template <typename T> struct Incrementability : public Crtp<T, Incrementability>
    {
        T& operator++()
        {
            ++(this->underlying().Get());
            return this->underlying();
        }
        T operator++(int)
        {
            T tmp(this->underlying().Get());
            operator++();
            return tmp;
        }
    };

    template <typename T> struct Comparability : public Crtp<T, Comparability>
    {
        //ToDo: figure out using Equality and Relativity to deduplicate
        constexpr bool operator==(T const& other) const
        {
            return other.Get() == this->underlying().Get();
        }
        constexpr bool operator!=(T const& other) const
        {
            return other.Get() != this->underlying().Get();
        }
        constexpr bool operator<(T const& other) const
        {
            return this->underlying().Get() < other.Get();
        }
        constexpr bool operator>(T const& other) const
        {
            return this->underlying().Get() > other.Get();
        }
        constexpr bool operator<=(T const& other) const
        {
            return this->underlying().Get() <= other.Get();
        }
        constexpr bool operator>=(T const& other) const
        {
            return this->underlying().Get() >= other.Get();
        }
    };
}
#endif //SKILLED_TYPE_SKILLS_H
