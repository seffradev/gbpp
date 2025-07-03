#include "log.hpp"

using namespace logging;

auto main(int, char*[]) noexcept -> int {
    auto logger = Logger<Level::Trace>{};

    logger.trace("Hello, world!");
    logger.info("Hello, world!");
    logger.warning("Hello, world!");
    logger.error("Hello, world!");

    return 0;
}
