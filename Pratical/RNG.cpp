#include <iostream>
#include <random>

int generateRandomNumber(int x, int y) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(x, y);

    return distribution(gen);
}

int main() {
    int x, y;

    // Get the range from the user
    std::cout << "Enter the range (x and y): ";
    std::cin >> x >> y;

    // Ensure x is less than y
    if (x >= y) {
        std::cerr << "Invalid range. Please make sure x is less than y." << std::endl;
        return 1;
    }

    // Generate and print a random number
    int randomNumber = generateRandomNumber(x, y);
    std::cout << "Random number between " << x << " and " << y << ": " << randomNumber << std::endl;

    return 0;
}
