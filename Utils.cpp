
#include <random>
#include "Utils.h"

using namespace std;

// Use a constant seed value (e.g., 42)
const unsigned int seedValue = 42;

mt19937 gen(seedValue); // Standard mersenne_twister_engine seeded with rd()

float generateRandomAngle() {
    uniform_real_distribution<float> distribution(0.0f, 360.0f);
    return distribution(gen);
}
