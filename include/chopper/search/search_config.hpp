#pragma once

struct search_config
{
    std::string chopper_index_filename{};
    std::string chopper_index_map_filename{};
    std::string query_filename{};
    uint8_t k{25};
    uint8_t errors{0};
    bool verbose{false};
};