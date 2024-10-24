#include "test_interface.h"

#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

std::stringstream OpenFileAndReturnStrStream(std::string file_name)
{
    std::ifstream file(file_name);

    if (!file)
    {
        std::cerr << "Could not open a test file!" << std::endl;
        return std::stringstream("");
    }

    std::stringstream ss ;
    std::string line;

    while (std::getline(file, line))
    {
        ss << line << '\n';
    }

    return ss;
}

std::set<size_t> GetSetFromStringStream(std::stringstream& ss)
{
    std::set<size_t> nums_set;
    size_t elems_count;

    ss >> elems_count;

    size_t elem;
    for (size_t i = 0; i < elems_count; i++)
    {
        ss >> elem;
        nums_set.insert(elem);
    }

    return nums_set;
}

TEST(TestIntersectionOfNTriangles, Subtest_1)
{
    std::stringstream ss = OpenFileAndReturnStrStream("../tests/test1.txt");
    ASSERT_FALSE(ss.str().empty());

    std::set<size_t> triangles_nums = GetIntersectingTrianglesNums(ss);

    ss = OpenFileAndReturnStrStream("../tests/test1_answ.txt");
    std::set<size_t> answers_nums = GetSetFromStringStream(ss);

    ASSERT_TRUE(triangles_nums == answers_nums);
}


TEST(TestIntersectionOfNTriangles, Subtest_2)
{
    std::stringstream ss = OpenFileAndReturnStrStream("../tests/test2.txt");
    ASSERT_FALSE(ss.str().empty());

    std::set<size_t> triangles_nums = GetIntersectingTrianglesNums(ss);

    ss = OpenFileAndReturnStrStream("../tests/test2_answ.txt");
    std::set<size_t> answers_nums = GetSetFromStringStream(ss);

    ASSERT_TRUE(triangles_nums == answers_nums);
}

TEST(TestIntersectionOfNTriangles, Subtest_3)
{
    std::stringstream ss = OpenFileAndReturnStrStream("../tests/test3.txt");
    ASSERT_FALSE(ss.str().empty());

    std::set<size_t> triangles_nums = GetIntersectingTrianglesNums(ss);

    ss = OpenFileAndReturnStrStream("../tests/test3_answ.txt");
    std::set<size_t> answers_nums = GetSetFromStringStream(ss);

    ASSERT_TRUE(triangles_nums == answers_nums);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
