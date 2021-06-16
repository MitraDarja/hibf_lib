#include <gtest/gtest.h>

#include <hibf/count/count_config.hpp>
#include <hibf/count/count_kmers.hpp>

#include "../api_test.hpp"

TEST(count_kmers_test, small_example_serial)
{
    count_config config;
    config.k = 15;
    config.w = 25;
    config.num_threads = 1;

    std::string input_file = data("small.fa");

    robin_hood::unordered_map<std::string, std::vector<std::string>> filename_clusters
    {
        {"TAX1", {input_file}},
        {"TAX2", {input_file, input_file}}
    };

    std::string expected
    {
        input_file + "\t95\tTAX1\n" +
        input_file + ";" + input_file + "\t95\tTAX2\n"
    };

    testing::internal::CaptureStdout();
    count_kmers(filename_clusters, config);
    std::string std_cout = testing::internal::GetCapturedStdout();
    EXPECT_EQ(expected, std_cout);
}

TEST(count_kmers_test, small_example_parallel_2_threads)
{
    count_config config;
    config.k = 15;
    config.w = 25;
    config.num_threads = 2;

    std::string input_file = data("small.fa");

    robin_hood::unordered_map<std::string, std::vector<std::string>> filename_clusters
    {
        {"TAX1", {input_file}},
        {"TAX2", {input_file, input_file}}
    };

    std::string expected
    {
        input_file + "\t95\tTAX1\n" +
        input_file + ";" + input_file + "\t95\tTAX2\n"
    };

    testing::internal::CaptureStdout();
    count_kmers(filename_clusters, config);
    std::string std_cout = testing::internal::GetCapturedStdout();
    EXPECT_EQ(expected, std_cout);
}
