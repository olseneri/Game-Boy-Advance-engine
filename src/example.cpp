

#include "types.h"
#include "abstract_register_manipulation.h"

using foo = abstract_register_manipulation<u16,0x04000000,0,0xff,true,true>;
using bar = abstract_register_manipulation<u16,0x06000010,0,0xff,true,true>;
using bang = abstract_register_manipulation<u16,0x06000014,0,0xff,true,true>;

int main() {



        foo::write(0x0403);
        bar::write(0x001f);
        bang::write(bar::read());
        while(1){}
    return 0;
}
