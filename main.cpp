#include "rbt.h"
#include <random>

void pvec(const auto& vec)
{
        for(auto el : vec)
        {
                fmt::print("{}\n", el);
        }
        fmt::print("\n");
}

int main()
{
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> distrib(1, 100);

        RedBlackTree<int> rbt;

        for(int i = 0; i < 50; ++i)
        {
                const int value = distrib(gen);
                // fmt::print("Number inserted: {}\n", value);
                rbt.insert(value);
        }

        const std::vector<int> vec = rbt.get_inorder_vector();

        pvec(vec);
        assert(std::is_sorted(vec.begin(), vec.end()));
}
