#include "rbt.h"
#include <random>
#include <algorithm>
#include <ctime>
#include <random>

void delete_duplicates(auto& vec)
{
        std::sort(vec.begin(), vec.end());

        const auto it = std::unique(vec.begin(), vec.end());
        vec.erase(it, vec.end());

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(vec.begin(), vec.end(), g);
}

int main()
{
        constexpr int size = 1 << 19;

        RedBlackTree<int> rbt;

        std::vector<int> random_keys;

        std::srand(std::time(0));
        for(int i = 0; i < size; ++i)
        {
                const int value = std::rand();
                random_keys.push_back(value);
        }

        delete_duplicates(random_keys);

        for(int key : random_keys)
        {
                rbt.insert(key);
        }

        // verifica daca valorile se gasesc in rbt
        for(int key : random_keys)
        {
                const auto node = rbt.find(key);
                assert(node != nullptr && node->key == key);
        }

        // verifica ordine corecta in parcurgerea inorder
        const std::vector<int> inorder_vec = rbt.get_inorder_vector();
        assert(std::is_sorted(inorder_vec.begin(), inorder_vec.end()));

        std::sort(random_keys.begin(), random_keys.end());

        // verifica predecesori, succesori inorder
        for(unsigned i = 1; i < random_keys.size() - 1; ++i)
        {
                const auto pred = rbt.inorder_predecessor(random_keys[i]);
                const auto suc = rbt.inorder_successor(random_keys[i]);

                // std::cout << pred->key << ' ' << random_keys[i - 1] << '\n';
                assert(pred->key == random_keys[i - 1]);
                // std::cout << suc->key << ' ' << random_keys[i + 1] << '\n';
                assert(suc->key == random_keys[i + 1]);
        }

        std::cerr << "ok\n";
}
