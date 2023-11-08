#pragma once

#include "spdlog/spdlog.h"

#define POLY_DEFAULT_LOGGER_NAME "PolyLogger"

#ifndef POLY_CONFIG_RELEASE
#define POLY_TRACE(...) if(spdlog::get(POLY_DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(POLY_DEFAULT_LOGGER_NAME)->trace(__VA_ARGS__);};
#define POLY_DEBUG(...) if(spdlog::get(POLY_DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(POLY_DEFAULT_LOGGER_NAME)->debug(__VA_ARGS__);};
#define POLY_INFO(...) if(spdlog::get(POLY_DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(POLY_DEFAULT_LOGGER_NAME)->info(__VA_ARGS__);};
#define POLY_WARN(...) if(spdlog::get(POLY_DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(POLY_DEFAULT_LOGGER_NAME)->warn(__VA_ARGS__);};
#define POLY_ERROR(...) if(spdlog::get(POLY_DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(POLY_DEFAULT_LOGGER_NAME)->error(__VA_ARGS__);};
#define POLY_FATAL(...) if(spdlog::get(POLY_DEFAULT_LOGGER_NAME) != nullptr) {spdlog::get(POLY_DEFAULT_LOGGER_NAME)->critical(__VA_ARGS__);};
#else
#define POLY_TRACE(...) (void)0;
#define POLY_DEBUG(...) (void)0;
#define POLY_INFO(...) (void)0;
#define POLY_WARN(...) (void)0;
#define POLY_ERROR(...) (void)0;
#define POLY_FATAL(...) (void)0;
#endif