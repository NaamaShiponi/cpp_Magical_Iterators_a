

#include "MagicalContainer.hpp"
#include <algorithm>

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}

AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container) {}

int* AscendingIterator::begin() {
    std::sort(container.elements.begin(), container.elements.end());
    return container.elements.data();
}

int* AscendingIterator::end() {
    return container.elements.data() + container.elements.size();
}

SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container) {}

int* SideCrossIterator::begin() {
    return container.elements.data();
}

int* SideCrossIterator::end() {
    return container.elements.data() + container.elements.size();
}

PrimeIterator::PrimeIterator(MagicalContainer& container) : container(container) {}

bool PrimeIterator::isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int* PrimeIterator::begin() {
    std::vector<int> primes;
    for (int element : container.elements) {
        if (isPrime(element)) {
            primes.push_back(element);
        }
    }
    container.elements = primes;
    return container.elements.data();
}

int* PrimeIterator::end() {
    return container.elements.data() + container.elements.size();
}