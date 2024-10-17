#include <iostream>

#include "interval.h"

#include <gtest/gtest.h>

TEST(IntervalTest, Overlap_CompleteContainment)
{
    Interval interval1(1, 5);
    Interval interval2(2, 3);
    ASSERT_TRUE(interval1.overlap(interval2));
    ASSERT_TRUE(interval2.overlap(interval1));
}

TEST(IntervalTest, Overlap_PartialOverlap)
{
    Interval interval1(1, 5);
    Interval interval2(4, 8);
    ASSERT_TRUE(interval1.overlap(interval2));
    ASSERT_TRUE(interval2.overlap(interval1));
}

TEST(IntervalTest, Overlap_TouchingEdges)
{
    Interval interval1(1, 5);
    Interval interval2(5, 8);
    ASSERT_TRUE(interval1.overlap(interval2));
    ASSERT_TRUE(interval2.overlap(interval1));
}

TEST(IntervalTest, Overlap_NoOverlap)
{
    Interval interval1(1, 5);
    Interval interval2(6, 10);
    ASSERT_FALSE(interval1.overlap(interval2));
    ASSERT_FALSE(interval2.overlap(interval1));
}

TEST(IntervalTest, Overlap_EqualIntervals)
{
    Interval interval1(2, 4);
    ASSERT_TRUE(interval1.overlap(interval1));
}

TEST(IntervalTest, Overlap_ParallelIntervals)
{
    Interval interval1(5, 10);
    Interval interval2(1, 2);
    ASSERT_FALSE(interval1.overlap(interval2));
    ASSERT_FALSE(interval2.overlap(interval1));
}

TEST(IntervalTest, Overlap_BoundaryConditions)
{
    Interval interval1(1, 1);
    Interval interval2(1, 2);
    ASSERT_TRUE(interval1.overlap(interval2));
    ASSERT_TRUE(interval2.overlap(interval1));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
