

#include "types.h"
#include "abstract_register_manipulation.h"

using foo = abstract_register_manipulation<u16,0x02000000,0,0xff,true,true>;
using bar = abstract_register_manipulation<u16,0x02000003,0,0xff,true,true>;

int main() {



        //foo::write(0xbf);
        //bar::write(foo::read());
        while(1){}
    return 0;
}