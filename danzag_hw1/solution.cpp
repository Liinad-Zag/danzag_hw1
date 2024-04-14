#include <iostream>
#include <cstdint>
#include <memory>
#include <random>

void printBitSequence(uint64_t data, size_t numBits) {
    std::cout << "BitSequence with " << numBits << " bits: ";
    for (size_t i = 0; i < numBits; ++i) {
        bool bitValue = data & (1ULL << i);
        std::cout << (bitValue ? "1" : "0");
    }
    std::cout << std::endl;
}

uint64_t generateRandomNumber(size_t numBits) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint64_t> dist(1ULL, (1ULL << numBits) - 1);
    return dist(gen);
}

size_t generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, 65);
    return dist(gen);
}

uint64_t generateRandomMask(size_t numBits)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint64_t> dist(0, (1ULL << numBits) - 1);
    return dist(gen);
}

class BitSequence {
private:
    uint64_t data;
    size_t numBits;
public:
    BitSequence(size_t numBits) : numBits(numBits)
     {
        data = generateRandomMask(numBits);
    }

    BitSequence() : BitSequence(generateRandomNumber()) {}

    void printBits() const {
        printBitSequence(data, numBits);
    }

    size_t getNumBits() const {
        return numBits;
    }

    void invertData(uint64_t newData) {
        data ^= newData;
    }
};


void invertRandomBits(std::unique_ptr<BitSequence>& ptr) {
    if (ptr) 
    {
        uint64_t mask = generateRandomMask(ptr->getNumBits());
        printBitSequence(mask, ptr->getNumBits());
        ptr->invertData(mask);
    }
}

int main() {
    size_t numBits = generateRandomNumber();
    std::unique_ptr<BitSequence> randomWithNumBits(new BitSequence(numBits));
    randomWithNumBits->printBits();
    invertRandomBits(randomWithNumBits);
    randomWithNumBits->printBits();
    std::unique_ptr<BitSequence> randomTotal(new BitSequence);
    randomTotal->printBits();
    invertRandomBits(randomTotal);
    randomTotal->printBits();
    return 0;
}
