//
// Created by marcel on 5/5/19.
//

#include "catch.hpp"
#include <Skills.h>

namespace skilled_type_test{
    using skilled_type::SkilledType;

    TEST_CASE("skilled with equality")
    {
        using CompInt = SkilledType<int, struct CompIntTypeTag,  skilled_type::Equality>;

        CompInt ci1(1);
        CompInt ci2(1);
        CompInt ci3(2);
        REQUIRE( ci1 == ci2);
        REQUIRE( ci1 != ci3);

    }

    TEST_CASE("skilled with equality and additivity")
    {
        using CompInt = SkilledType<int, struct CompIntTypeTag, skilled_type::Equality, skilled_type::Additivity>;

        CompInt ci1(1);
        CompInt ci2(1);
        CompInt ci3(2);
        REQUIRE( ci1 == ci2);
        REQUIRE( (ci1 + ci2) == ci3);

    }

    TEST_CASE("skilled with relativity")
    {
        using CompInt = SkilledType<int, struct CompIntTypeTag, skilled_type::Relativity>;

        CompInt ci1(1);
        CompInt ci2(1);
        CompInt ci3(2);
        REQUIRE_FALSE( ci1 < ci2);
        REQUIRE( ci1 < ci3) ;
        REQUIRE_FALSE( ci1 > ci3) ;
    }

    TEST_CASE("skilled with incrementability")
    {
        using CompInt = SkilledType<int, struct CompIntTypeTag,
                                    skilled_type::Incrementability,
                                    skilled_type::Equality>;

        CompInt ci1(1);
        auto ci2 = ++ci1;
        auto ci3 = ci1++;

        REQUIRE( ci1 == CompInt(3));
        REQUIRE( ci2 == CompInt(2)) ;
        REQUIRE( ci3 == CompInt(2)) ;
    }

}