#include "spdlog/spdlog.h"
#include "spdlog/sinks/ansicolor_sink.h"
#include "spdlog/sinks/basic_file_sink.h"

static const char *logger_name = "logger";

static void SetupLogging() {
    auto log_level = spdlog::level::debug;

    std::vector<spdlog::sink_ptr> sinks;

    sinks.push_back(std::make_shared<spdlog::sinks::ansicolor_stdout_sink_st>());

    const auto *log_path = "learn_sip.log";
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_path, true));

    // create logger
    auto combined_logger = std::make_shared<spdlog::logger>(logger_name, begin(sinks), end(sinks));
    const auto *pattern = "%Y-%m-%d %H:%M:%S.%f [%t] %^[%8l]%$ [%s:%#] [%!] %v";
    combined_logger->set_pattern(pattern);
    combined_logger->set_level(static_cast<spdlog::level::level_enum>(spdlog::level::trace + log_level));

    register_logger(combined_logger);
    set_default_logger(combined_logger);

    spdlog::flush_on(spdlog::level::debug);
}

int main(int argc, char *argv[]) {
    SetupLogging();
    SPDLOG_INFO("start learn SIP");

    spdlog::shutdown();

    return 0;
}
