//
// Created by eri on 8/9/21.
//

#ifndef GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H
#define GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H

#include "types.h"

template <typename data_width, uintptr_t register_address, data_width shift_amount, data_width bitmask, bool readable, bool writable, typename access_type = data_width>
class abstract_register_manipulation {
public:
    static_assert(((register_address % sizeof(data_width)) == 0), "Input is improperly aligned");

    static constinit inline volatile data_width* const _register = reinterpret_cast<volatile data_width*>(register_address);

    static void write(access_type value){
        static_assert(writable, "Cannot write to this register");
        *_register = (*_register & ~bitmask) | ((data_width)value << shift_amount);
    };

    static access_type read(){
        static_assert(readable, "Cannot read this register");
        return (access_type)((*_register & bitmask) >> shift_amount);
    };
};

#endif //GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H
