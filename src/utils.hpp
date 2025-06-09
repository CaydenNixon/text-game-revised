#pragma once

#include <iostream>
#include <random>

struct Utils
{
    static int num_gen(int seed, int min, int max) // generates a random number given the save's seed and the range
    {
        std::mt19937 gen(get_seed()); // primary seed initializes the generator
        gen.seed(get_seed() + seed);

        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
    static void seed_gen() { std::random_device new_seed; set_seed(new_seed()); } // generates a new seed and calls the function below
    static void set_seed(int new_seed) { game_seed = new_seed; } // sets the new seed
    static int get_seed() { return game_seed; } // used to return the seed

    private:
    static int game_seed;
};
