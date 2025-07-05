#ifndef __LOG_HPP__
#define __LOG_HPP__

#include <print>
#include <source_location>
#include <utility>

namespace logging {

/// ASCII foreground color escape codes
enum struct ForegroundColor {
    Black         = 30,
    Red           = 31,
    Green         = 32,
    Yellow        = 33,
    Blue          = 34,
    Magenta       = 35,
    Cyan          = 36,
    White         = 37,
    BrightBlack   = 90,
    BrightRed     = 91,
    BrightGreen   = 92,
    BrightYellow  = 93,
    BrightBlue    = 94,
    BrightMagenta = 95,
    BrightCyan    = 96,
    BrightWhite   = 97,
};

/// ASCII background color escape codes
enum struct BackgroundColor {
    Black         = 40,
    Red           = 41,
    Green         = 42,
    Yellow        = 43,
    Blue          = 44,
    Magenta       = 45,
    Cyan          = 46,
    White         = 47,
    BrightBlack   = 100,
    BrightRed     = 101,
    BrightGreen   = 102,
    BrightYellow  = 103,
    BrightBlue    = 104,
    BrightMagenta = 105,
    BrightCyan    = 106,
    BrightWhite   = 107,
};

enum struct Level {
    Error,
    Warning,
    Info,
    Trace,
};

class Logger final {
public:
    Level level;

    constexpr void
    info(std::string&& string, std::source_location source_location = std::source_location::current()) const noexcept {
        if (level < Level::Info) {
            return;
        }

        log<Level::Info>(std::move(string), source_location);
    }

    constexpr void
    error(std::string&& string, std::source_location source_location = std::source_location::current()) const noexcept {
        if (level < Level::Error) {
            return;
        }

        log<Level::Error>(std::move(string), source_location);
    }

    constexpr void
    trace(std::string&& string, std::source_location source_location = std::source_location::current()) const noexcept {
        if (level < Level::Trace) {
            return;
        }

        log<Level::Trace>(std::move(string), source_location);
    }

    constexpr void warning(std::string&&        string,
                           std::source_location source_location = std::source_location::current()) const noexcept {
        if (level < Level::Warning) {
            return;
        }

        log<Level::Warning>(std::move(string), source_location);
    }

private:
    template <Level level>
    static constexpr void log(std::string string, std::source_location source_location) noexcept {
        auto location = std::format("{}:{}", source_location.file_name(), source_location.line());

        if constexpr (level == Level::Info) {
            std::print("INFO({}): ", location);
        } else if constexpr (level == Level::Error) {
            std::print("\x1B[{}mERROR({})\033[0m: ", std::to_underlying(ForegroundColor::Red), location);
        } else if constexpr (level == Level::Trace) {
            std::print("\x1B[{}mTRACE({})\033[0m: ", std::to_underlying(ForegroundColor::Blue), location);
        } else if constexpr (level == Level::Warning) {
            std::print("\x1B[{}mWARNING({})\033[0m: ", std::to_underlying(ForegroundColor::Yellow), location);
        }

        std::println("{}", string);
    }
};

}

#endif  // !__LOG_HPP__
