#pragma once

#include "spdlog/spdlog.h"

#define POLY_DEFAULT_LOGGER_NAME "graphicraft"

#ifndef POLY_CONFIG_RELEASE
#define POLY_TRACE(...) if(spdlog::get(POLY_DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(POLY_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__)};
#else
#define POLY_TRACE(...) (void)0
#endif