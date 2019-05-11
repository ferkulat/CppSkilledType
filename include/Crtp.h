//
// Created by marcel on 5/5/19.
//

#ifndef SKILLED_TYPE_CRTP_H
#define SKILLED_TYPE_CRTP_H
template <typename T, template<typename> class crtpType>
struct Crtp
{
    T& underlying() { return static_cast<T&>(*this); }
    T const& underlying() const { return static_cast<T const&>(*this); }
};

#endif //SKILLED_TYPE_CRTP_H
