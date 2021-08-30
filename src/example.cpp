

#include "types.h"
#include "abstract_register_manipulation.h"
#include "registers.h"

enum lobster {kids, are, kinda, smelly};


using foo = abstract_register_manipulation<u16,0x02000000,0,0xff,true,true,lobster>;
//using bar = abstract_register_manipulation<u16,0x06000010,0,0xff,true,true>;
//using bang = abstract_register_manipulation<u16,0x06000014,0,0xff,true,true>;

int main() {

    //DISPCNT_BG_MODE::write(0xff);
        foo::write(are);
        //bar::write(0x001f);
        //bang::write(bar::read());
        while(1){}
    return 0;
}
