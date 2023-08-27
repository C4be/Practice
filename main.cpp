#include <iostream>
#include <cmath>
#include <unordered_set>
#include <fstream>

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    int i = 5;
    while (i * i <= number) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }

    return true;
}

void generate_sequence(int p, std::ofstream &output_file) {
    std::string sequence;

    for (int i = 1; i < p; i++) {
        if ((int)pow(i, (p - 1) / 2) % p == 1) {
            sequence += "+";
        } else {
            sequence += "-";
        }
    }

    int min_length = 1;
    bool found = false;

    while (!found && min_length <= p - 1) {
        std::unordered_set<std::string> substrings;
        bool distinct = true;

        for (int i = 0; i <= p - min_length; i += min_length) {
            std::string substring = sequence.substr(i, min_length);
            if (substrings.count(substring) > 0) {
                distinct = false;
                break;
            }
            substrings.insert(substring);
        }

        if (distinct) {
            found = true;
            break;
        }
        min_length++;
    }

    output_file << min_length << " " << p << std::endl;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::ofstream output_file("../results.txt");
    if (!output_file) {
        std::cout << "Could not open file." << std::endl;
        return 1;
    }

    for (int p = 2; p <= n; p++) {
        if (is_prime(p)) {
            generate_sequence(p, output_file);
        }
        std::cout << p << std::endl;
    }

    output_file.close();

    std::cout << "Results written to 'results.txt'." << std::endl;
    return 0;
}