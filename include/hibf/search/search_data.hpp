#pragma once

#include <seqan3/search/dream_index/interleaved_bloom_filter.hpp>
#include <hibf/detail_hibf_user_bins.hpp>

namespace hibf
{
struct search_data
{
    std::vector<seqan3::interleaved_bloom_filter<>> hibf;
    std::vector<std::vector<int64_t>> hibf_bin_levels;
    hibf_user_bins user_bins;
};
} // namespace hibf
