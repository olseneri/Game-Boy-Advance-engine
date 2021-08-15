//
// Created by eri on 8/9/21.
//

#ifndef GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H
#define GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H

#include "types.h"

template <typename data_width, uintptr_t register_address, data_width shift_amount, data_width bitmask, bool readable, bool writable>
class abstract_register_manipulation {
public:
    static_assert(((register_address % sizeof(data_width)) == 0), "Input is improperly aligned");

    static void write(data_width value){
        static_assert(writable, "Cannot write to this register");
        (*(data_width *)register_address) = ((*(data_width *)register_address) & ~bitmask) | (value << shift_amount);
    };

    static data_width read(){
        static_assert(readable, "Cannot read this register");
        return (*(data_width *)register_address & bitmask) >> shift_amount;
    };
};

#endif //GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H
