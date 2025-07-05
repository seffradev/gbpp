#ifndef __CARTRIDGE_HPP__
#define __CARTRIDGE_HPP__

#include <array>
#include <cstdint>
#include <map>
#include <string>

namespace gameboy::cartridge {

const auto ENTRY_POINT_LENGTH = 0x4;
const auto LOGO_LENGTH        = 0x30;

// Account for manufacturer code and CGB flag being part of the
// title in older cartridges.
const auto TITLE_LENGTH           = 0x10 - 4 - 1;
const auto MANUFACTURER_LENGTH    = 0x4;
const auto GLOBAL_CHECKSUM_LENGTH = 0x2;

enum struct CgbFlag : uint8_t {
    /// The game supports CGB enhancements, but is backwards
    /// compatible with monochrome Game Boys.
    CgbEnhancements = 0x80,
    /// The game works on CGB only (the hardware ignores bit 6, so
    /// this really functions the same as $80).
    CgbOnly = 0xC0,
};

const auto NEW_LICENSEES = std::map<std::pair<char, char>, std::string>{
    {{'0', '0'}, "None"},
    {{'0', '1'}, "Nintendo Research & Development 1"},
    {{'0', '8'}, "Capcom"},
    {{'1', '3'}, "EA (Electronic Arts)"},
    {{'1', '8'}, "Hudson Soft"},
    {{'1', '9'}, "B-AI"},
    {{'2', '0'}, "KSS"},
    {{'2', '2'}, "Planning Office WADA"},
    {{'2', '4'}, "PCM Complete"},
    {{'2', '5'}, "San-X"},
    {{'2', '8'}, "Kemco"},
    {{'2', '9'}, "SETA Corporation"},
    {{'3', '0'}, "Viacom"},
    {{'3', '1'}, "Nintendo"},
    {{'3', '2'}, "Bandai"},
    {{'3', '3'}, "Ocean Software/Acclaim Entertainment"},
    {{'3', '4'}, "Konami"},
    {{'3', '5'}, "HectorSoft"},
    {{'3', '7'}, "Taito"},
    {{'3', '8'}, "Hudson Soft"},
    {{'3', '9'}, "Banpresto"},
    {{'4', '1'}, "Ubi Soft"},
    {{'4', '2'}, "Atlus"},
    {{'4', '4'}, "Malibu Interactive"},
    {{'4', '6'}, "Angel"},
    {{'4', '7'}, "Bullet-Proof Software"},
    {{'4', '9'}, "Irem"},
    {{'5', '0'}, "Absolute"},
    {{'5', '1'}, "Acclaim Entertainment"},
    {{'5', '2'}, "Activision"},
    {{'5', '3'}, "Sammy USA Corporation"},
    {{'5', '4'}, "Konami"},
    {{'5', '5'}, "Hi Tech Expressions"},
    {{'5', '6'}, "LJN"},
    {{'5', '7'}, "Matchbox"},
    {{'5', '8'}, "Mattel"},
    {{'5', '9'}, "Milton Bradley Company"},
    {{'6', '0'}, "Titus Interactive"},
    {{'6', '1'}, "Virgin Games Ltd."},
    {{'6', '4'}, "Lucasfilm Games"},
    {{'6', '7'}, "Ocean Software"},
    {{'6', '9'}, "EA (Electronic Arts)"},
    {{'7', '0'}, "Infogrames"},
    {{'7', '1'}, "Interplay Entertainment"},
    {{'7', '2'}, "Broderbund"},
    {{'7', '3'}, "Sculptured Software"},
    {{'7', '5'}, "The Sales Curve Limited"},
    {{'7', '8'}, "THQ"},
    {{'7', '9'}, "Accolade"},
    {{'8', '0'}, "Misawa Entertainment"},
    {{'8', '3'}, "lozc"},
    {{'8', '6'}, "Tokuma Shoten"},
    {{'8', '7'}, "Tsukuda Original"},
    {{'9', '1'}, "Chunsoft Co."},
    {{'9', '2'}, "Video System"},
    {{'9', '3'}, "Ocean Software/Acclaim Entertainment"},
    {{'9', '5'}, "Varie"},
    {{'9', '6'}, "Yonezawa/s'pal"},
    {{'9', '7'}, "Kaneko"},
    {{'9', '9'}, "Pack-In-Video"},
    {{'9', 'H'}, "Bottom Up"},
    {{'A', '4'}, "Konami (Yu-Gi-Oh!)"},
    {{'B', 'L'}, "MTO"},
    {{'D', 'K'}, "Kodansha"},
};

/// Cartridge types
enum struct Type : uint8_t {
    RomOnly                    = 0x00,
    Mbc1                       = 0x01,
    Mbc1Ram                    = 0x02,
    Mbc1RamBattery             = 0x03,
    Mbc2                       = 0x05,
    Mbc2Battery                = 0x06,
    RomRam                     = 0x08,
    RomRamBattery              = 0x09,
    Mmm01                      = 0x0B,
    Mmm01Ram                   = 0x0C,
    Mmm01RamBattery            = 0x0D,
    Mbc3TimerBattery           = 0x0F,
    Mbc3TimerRamBattery        = 0x10,
    Mbc3                       = 0x11,
    Mbc3Ram                    = 0x12,
    Mbc3RamBattery             = 0x13,
    Mbc5                       = 0x19,
    Mbc5Ram                    = 0x1A,
    Mbc5RamBattery             = 0x1B,
    Mbc5Rumble                 = 0x1C,
    Mbc5RumbleRam              = 0x1D,
    Mbc5RumbleRamBattery       = 0x1E,
    Mbc6                       = 0x20,
    Mbc7SensorRumbleRamBattery = 0x22,
    PocketCamera               = 0xFC,
    BandaiTama5                = 0xFD,
    HuC3                       = 0xFE,
    HuC1RamBattery             = 0xFF,
};

const auto ROM_SIZES = std::map<std::byte, std::pair<std::string, std::string>>{
    {std::byte{0x00}, {"32 KiB", "2 (no banking)"}},
    {std::byte{0x01}, {"64 KiB", "4"}},
    {std::byte{0x02}, {"128 KiB", "8"}},
    {std::byte{0x03}, {"256 KiB", "16"}},
    {std::byte{0x04}, {"512 KiB", "32"}},
    {std::byte{0x05}, {"1 MiB", "64"}},
    {std::byte{0x06}, {"2 MiB", "128"}},
    {std::byte{0x07}, {"4 MiB", "256"}},
    {std::byte{0x08}, {"8 MiB", "512"}},
    {std::byte{0x52}, {"1.1 MiB", "72"}},
    {std::byte{0x53}, {"1.2 MiB", "80"}},
    {std::byte{0x54}, {"1.5 MiB", "96"}},
};

const auto RAM_SIZES = std::map<std::byte, std::pair<std::string, std::string>>{
    {std::byte{0x00}, {"0", "No RAM"}},
    {std::byte{0x01}, {"-", "Unused"}},
    {std::byte{0x02}, {"8 KiB", "1 bank"}},
    {std::byte{0x03}, {"32 KiB", "4 banks of 8 KiB each"}},
    {std::byte{0x04}, {"128 KiB", "16 banks of 8 KiB each"}},
    {std::byte{0x05}, {"64 KiB", "8 banks of 8 KiB each"}},
};

const auto DESTINATION_CODES = std::map<std::byte, std::string>{
    {std::byte{0x00}, "Japan (and possibly overseas)"},
    {std::byte{0x01}, "Overseas only"},
};

const auto OLD_LICENSEES = std::map<std::byte, std::string>{
    {std::byte{0x00}, "None"},
    {std::byte{0x01}, "Nintendo"},
    {std::byte{0x08}, "Capcom"},
    {std::byte{0x09}, "HOT-B"},
    {std::byte{0x0A}, "Jaleco"},
    {std::byte{0x0B}, "Coconuts Japan"},
    {std::byte{0x0C}, "Elite Systems"},
    {std::byte{0x13}, "EA (Electronic Arts)"},
    {std::byte{0x18}, "Hudson Soft"},
    {std::byte{0x19}, "ITC Entertainment"},
    {std::byte{0x1A}, "Yanoman"},
    {std::byte{0x1D}, "Japan Clary"},
    {std::byte{0x1F}, "Virgin Games Ltd."},
    {std::byte{0x24}, "PCM Complete"},
    {std::byte{0x25}, "San-X"},
    {std::byte{0x28}, "Kemco"},
    {std::byte{0x29}, "SETA Corporation"},
    {std::byte{0x30}, "Infogrames"},
    {std::byte{0x31}, "Nintendo"},
    {std::byte{0x32}, "Bandai"},
    {std::byte{0x33}, "New licensee code should be used"},
    {std::byte{0x34}, "Konami"},
    {std::byte{0x35}, "HectorSoft"},
    {std::byte{0x38}, "Capcom"},
    {std::byte{0x39}, "Banpresto"},
    {std::byte{0x3C}, "Entertainment Interactive (stub)"},
    {std::byte{0x3E}, "Gremlin"},
    {std::byte{0x41}, "Ubi Soft"},
    {std::byte{0x42}, "Atlus"},
    {std::byte{0x44}, "Malibu Interactive"},
    {std::byte{0x46}, "Angel"},
    {std::byte{0x47}, "Spectrum HoloByte"},
    {std::byte{0x49}, "Irem"},
    {std::byte{0x4A}, "Virgin Games Ltd."},
    {std::byte{0x4D}, "Malibu Interactive"},
    {std::byte{0x4F}, "U.S. Gold"},
    {std::byte{0x50}, "Absolute"},
    {std::byte{0x51}, "Acclaim Entertainment"},
    {std::byte{0x52}, "Activision"},
    {std::byte{0x53}, "Sammy USA Corporation"},
    {std::byte{0x54}, "GameTek"},
    {std::byte{0x55}, "Park Place"},
    {std::byte{0x56}, "LJN"},
    {std::byte{0x57}, "Matchbox"},
    {std::byte{0x59}, "Milton Bradley Company"},
    {std::byte{0x5A}, "Mindscape"},
    {std::byte{0x5B}, "Romstar"},
    {std::byte{0x5C}, "Naxat Soft"},
    {std::byte{0x5D}, "Tradewest"},
    {std::byte{0x60}, "Titus Interactive"},
    {std::byte{0x61}, "Virgin Games Ltd."},
    {std::byte{0x67}, "Ocean Software"},
    {std::byte{0x69}, "EA (Electronic Arts)"},
    {std::byte{0x6E}, "Elite Systems"},
    {std::byte{0x6F}, "Electro Brain"},
    {std::byte{0x70}, "Infogrames"},
    {std::byte{0x71}, "Interplay Entertainment"},
    {std::byte{0x72}, "Broderbund"},
    {std::byte{0x73}, "Sculptured Software"},
    {std::byte{0x75}, "The Sales Curve Limited"},
    {std::byte{0x78}, "THQ"},
    {std::byte{0x79}, "Accolade"},
    {std::byte{0x7A}, "Triffix Entertainment"},
    {std::byte{0x7C}, "MicroProse"},
    {std::byte{0x7F}, "Kemco"},
    {std::byte{0x80}, "Misawa Entertainment"},
    {std::byte{0x83}, "LOZC G."},
    {std::byte{0x86}, "Tokuma Shoten"},
    {std::byte{0x8B}, "Bullet-Proof Software"},
    {std::byte{0x8C}, "Vic Tokai Corp."},
    {std::byte{0x8E}, "Ape Inc."},
    {std::byte{0x8F}, "I'Max"},
    {std::byte{0x91}, "Chunsoft Co."},
    {std::byte{0x92}, "Video System"},
    {std::byte{0x93}, "Tsubaraya Productions"},
    {std::byte{0x95}, "Varie"},
    {std::byte{0x96}, "Yonezawa/S'pal"},
    {std::byte{0x97}, "Kemco"},
    {std::byte{0x99}, "Arc"},
    {std::byte{0x9A}, "Nihon Bussan"},
    {std::byte{0x9B}, "Tecmo"},
    {std::byte{0x9C}, "Imagineer"},
    {std::byte{0x6D}, "Banpresto"},
    {std::byte{0x6F}, "Nova"},
    {std::byte{0xA1}, "Hori Electric"},
    {std::byte{0xA2}, "Bandai"},
    {std::byte{0xA4}, "Konami"},
    {std::byte{0xA6}, "Kawada"},
    {std::byte{0xA7}, "Takara"},
    {std::byte{0xA9}, "Technos Japan"},
    {std::byte{0xAA}, "Broderbund"},
    {std::byte{0xAC}, "Toei Animation"},
    {std::byte{0xAD}, "Toho"},
    {std::byte{0xAF}, "Namco"},
    {std::byte{0xB0}, "Acclaim Entertainment"},
    {std::byte{0xB1}, "ASCII Corporation or Nexsoft"},
    {std::byte{0xB2}, "Bandai"},
    {std::byte{0xB4}, "Square Enix"},
    {std::byte{0xB6}, "HAL Laboratory"},
    {std::byte{0xB7}, "SNK"},
    {std::byte{0xB9}, "Pony Canyon"},
    {std::byte{0xBA}, "Culture Brain"},
    {std::byte{0xBB}, "Sunsoft"},
    {std::byte{0xBD}, "Sony Imagesoft"},
    {std::byte{0xBF}, "Sammy Corporation"},
    {std::byte{0xC0}, "Taito"},
    {std::byte{0xC2}, "Kemco"},
    {std::byte{0xC3}, "Square"},
    {std::byte{0xC4}, "Tokuma Shoten"},
    {std::byte{0xC5}, "Data East"},
    {std::byte{0xC6}, "Tonkin House"},
    {std::byte{0xC8}, "Koei"},
    {std::byte{0xC9}, "UFL"},
    {std::byte{0xCA}, "Ultra Games"},
    {std::byte{0xCB}, "VAP, Inc."},
    {std::byte{0xCC}, "Use Corporation"},
    {std::byte{0xCD}, "Meldac"},
    {std::byte{0xCE}, "Pony Canyon"},
    {std::byte{0xCF}, "Angel"},
    {std::byte{0xD0}, "Taito"},
    {std::byte{0xD1}, "SOFEL (Software Engineering Lab)"},
    {std::byte{0xD2}, "Quest"},
    {std::byte{0xD3}, "Sigma Enterprises"},
    {std::byte{0xD4}, "ASK Kodansha Co."},
    {std::byte{0xD6}, "Naxat Soft"},
    {std::byte{0xD7}, "Copya System"},
    {std::byte{0xD9}, "Banpresto"},
    {std::byte{0xDA}, "Tomy"},
    {std::byte{0xDB}, "LQN"},
    {std::byte{0xDD}, "Nippon Computer Systems"},
    {std::byte{0xDE}, "Human Ent."},
    {std::byte{0xDF}, "Altron"},
    {std::byte{0xE0}, "Jaleco"},
    {std::byte{0xE1}, "Towa Chiki"},
    {std::byte{0xE2}, "Yutaka"},
    {std::byte{0xE3}, "Varie"},
    {std::byte{0xE5}, "Epoch"},
    {std::byte{0xE7}, "Athena"},
    {std::byte{0xE8}, "Asmik Ace Entertainment"},
    {std::byte{0xE9}, "Natsume"},
    {std::byte{0xEA}, "King Records"},
    {std::byte{0xEB}, "Atlus"},
    {std::byte{0xEC}, "Epic/Sony Records"},
    {std::byte{0xEE}, "IGS"},
    {std::byte{0xF0}, "A Wave"},
    {std::byte{0xF3}, "Extreme Entertainment"},
    {std::byte{0xFF}, "LJN"},
};

struct Header {
    template <size_t size>
    using Bytes = std::array<std::byte, size>;

    Bytes<ENTRY_POINT_LENGTH>     entry_point;
    Bytes<LOGO_LENGTH>            logo;
    Bytes<TITLE_LENGTH>           title;
    Bytes<MANUFACTURER_LENGTH>    manufacturer_code;
    std::byte                     cgb_flag;
    std::pair<char, char>         new_licensee_code;
    std::byte                     sgb_flag;
    std::byte                     cartridge_type;
    std::byte                     rom_size;
    std::byte                     ram_size;
    std::byte                     destination_code;
    std::byte                     old_licensee_code;
    std::byte                     mask_rom_version_number;
    std::byte                     header_checksum;
    Bytes<GLOBAL_CHECKSUM_LENGTH> global_checksum;
};

const auto HEADER_START = 0x100;
const auto HEADER_END   = 0x14F;

// Increment by one to account for the number of slots in the
// address space.
const auto RANGE = HEADER_END - HEADER_START + 1;

static_assert(sizeof(Header) == RANGE, "Header must be this size");

struct Cartridge {
    Header header;
};

}

#endif
