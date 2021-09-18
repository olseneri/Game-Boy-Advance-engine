

#include "types.h"
#include "abstract_register_manipulation.h"
#include "registers.h"

//TODO: Enforce enums within the same scope as the class that they are used with
//TODO: Is it possible to static_assert() so that you can't pass enums that collapse to ints?
enum lobster {kids, are, kinda, smelly};

using foo = abstract_register_manipulation<u32,0x02000000,0b00000000000000000000000000000010,true,true>;
using bar = abstract_register_manipulation<u32,0x02000000,0x07,true,true>;
//using bar = abstract_register_manipulation<u16,0x06000010,0,0xff,true,true>;
//using bang = abstract_register_manipulation<u16,0x06000014,0,0xff,true,true>;

int main() {
    foo::write(0xffff);

    while(true){}
    return 0;
}
