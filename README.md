master: [![Build Status](https://travis-ci.org/ferkulat/CppSkilledType.svg?branch=master)](https://travis-ci.org/ferkulat/CppSkilledType)
[![Build status](https://ci.appveyor.com/api/projects/status/github/ferkulat/CppSkilledType?brach=master&svg=true)](https://ci.appveyor.com/project/ferkulat/CppSkilledType)

# CppSkilledType
This a header only library for creating type safe wrappers around primitive types.

```Cpp
    TEST_CASE("skilled with equality and additivity")
    {
        using CompInt = SkilledType<int,
                                    struct CompIntTypeTag, 
                                    skilled_type::Equality,
                                    skilled_type::Additivity>;

        CompInt ci1(1);
        CompInt ci2(1);
        CompInt ci3(2);
        REQUIRE( ci1 == ci2);
        REQUIRE( (ci1 + ci2) == ci3);
    }

```
