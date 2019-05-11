//
// Created by marcel on 5/5/19.
//

#ifndef SKILLED_TYPE_H
#define SKILLED_TYPE_H

#include <istream>
namespace skilled_type
{
template <typename T, typename TypeTag, template <typename> typename... Skills> class SkilledType;

template <typename T, typename TypeTag, template <typename> typename... Skills>
std::istream& operator>>(std::istream& is, SkilledType<T, TypeTag, Skills...>& target);

template <typename T, typename TypeTag, template <typename> typename... Skills>
std::ostream& operator<<(std::ostream& os, SkilledType<T, TypeTag, Skills...> const& target);

template <typename T, typename TypeTag, template <typename> typename... Skills>
class SkilledType : public Skills<SkilledType<T, TypeTag, Skills...>>...
{
    T value;

  public:
    using type         = T;
    SkilledType() = default;
    constexpr explicit SkilledType(T t_)
        : value(std::move(t_))
    {
    }
    constexpr T const& Get() const
    {
        return value;
    }
    constexpr T& Get()
    {
        return value;
    }

  private:
    friend std::istream&
    operator>><T, TypeTag, Skills...>(std::istream& is, SkilledType<T, TypeTag, Skills...>& target);

    friend std::ostream&
    operator<<<T, TypeTag, Skills...>(std::ostream& os, SkilledType<T, TypeTag, Skills...> const& target);
};

} // namespace skilled_type
#endif // SKILLED_TYPE_H
