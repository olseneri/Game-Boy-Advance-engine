//
// Created by eri on 8/15/21.
//

#ifndef GBA_GAMEDEV_REGISTERS_H
#define GBA_GAMEDEV_REGISTERS_H

#include "types.h"
#include "abstract_register_manipulation.h"

//typename data_width, uintptr_t register_address, data_width bitmask, bool readable, bool writable, typename access_type = data_width
//GBA video control register is at 0x04000000
enum ENUM_DISPCNT_MODE {BG_MODE_0,BG_MODE_1,BG_MODE_2,BG_MODE_3,BG_MODE_4,BG_MODE_5};
using REG_DISPCNT_MODE = abstract_register_manipulation<u16,0x04000000,0b0000000000000111,true,true,ENUM_DISPCNT_MODE>;

using REG_DISPCNT_PAGE_SELECT = abstract_register_manipulation<u16,0x04000000,0b00000000000010000,true,true,bool>;

using REG_DISPCNT_OBJ_PROCESSING_AT_HBLANK = abstract_register_manipulation<u16,0x04000000,0b0000000000100000,true,true,bool>;

using REG_DISPCNT_VRAM_OBJ_CHARACTER_MAPPING = abstract_register_manipulation<u16,0x04000000,0b00000000001000000,true,true,bool>;






#endif //GBA_GAMEDEV_REGISTERS_H
