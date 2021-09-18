//
// Created by eri on 8/9/21.
//

#ifndef GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H
#define GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H

#include "types.h"


consteval int ctz(int value) {
    int counter = 0;
    // If clearing the mask bit does nothing, the mask bit covers a 0
    //Thanks Caro, you got your order of operations wrong
    while ((value & ~ (1 << counter)) == value) {
        counter++;
    }
    return counter;
}


//TODO: remove shift_amount template argument using a consteval function that takes the bitmask as an input
template <typename data_width, uintptr_t register_address, data_width bitmask, bool readable, bool writable, typename access_type = data_width>
class abstract_register_manipulation {
private:
    const static u8 shift_amount = ctz(bitmask);
public:
    static_assert(((register_address % sizeof(data_width)) == 0), "Input is improperly aligned");

    static constinit inline volatile data_width* const _register = reinterpret_cast<volatile data_width*>(register_address);

    static void clear(){
        static_assert(writable, "Cannot write to this register");
        *_register = ~(bitmask | (~*_register));
    };

    static void write(access_type value){
        static_assert(writable, "Cannot write to this register");
        //*_register = (*_register & ~bitmask) | ((data_width)value << shift_amount);
        *_register = (~((~(*_register)) | bitmask)) ^ ((data_width)value << shift_amount);
    };

    static access_type read(){
        static_assert(readable, "Cannot read this register");
        return (access_type)((*_register & bitmask) >> shift_amount);
    };
};

#endif //GBA_GAMEDEV_ABSTRACT_REGISTER_MANIPULATION_H
