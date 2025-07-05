#ifndef __DEVICE_HPP__
#define __DEVICE_HPP__

#include "bus.hpp"
#include "cartridge.hpp"
#include "cpu.hpp"

namespace gameboy {

struct Device {
    cartridge::Cartridge cartridge;
    Cpu                  cpu;
    Bus                  bus;
};

}

#endif
