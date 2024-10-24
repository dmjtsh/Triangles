#include "test_interface.h"

#include <iostream>

int main()
{
    try
    {
        GetIntersectingTrianglesNums(std::cin);
    }

    catch (const std::invalid_argument& e)
    {
        std::cerr << "Input error: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Input error: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    return 0;
}
