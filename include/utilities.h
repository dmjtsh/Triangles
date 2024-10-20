#pragma once

constexpr inline double DOUBLE_TOLERANCE = 1e-9;

bool CheckDoublesEqual(double f1, double f2);

bool CheckLessOrZero(double a, double b);

bool HasDifferentSign(double a, double b, double c);
