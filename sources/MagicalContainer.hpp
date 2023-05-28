
#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>

// Forward declarations
class MagicalContainer;

// Iterator interface
class Iterator
{
public:
    virtual int *begin() = 0;
    virtual int *end() = 0;

    virtual ~Iterator() = default;
    Iterator(){}; // default constructor
    // Copy constructor
    Iterator(const Iterator &other) = default;

    // Copy assignment operator
    Iterator &operator=(const Iterator &other) = default;

    // Move constructor
    Iterator(Iterator &&other) = default;

    // Move assignment operator
    Iterator &operator=(Iterator &&other) = default;
};

// Container class
class MagicalContainer
{
private:
    std::vector<int> elements;

public:
    MagicalContainer() = default;
    void addElement(int element);
    void removeElement(int element);
    int size() const;

    friend class AscendingIterator;
    friend class SideCrossIterator;
    friend class PrimeIterator;
};

// AscendingIterator class
class AscendingIterator : public Iterator
{
private:
    MagicalContainer &container;

public:

    AscendingIterator(MagicalContainer &container);

    int *begin() override;
    int *end() override;
};

// SideCrossIterator class
class SideCrossIterator : public Iterator
{
private:
    MagicalContainer &container;

public:
    SideCrossIterator(MagicalContainer &container);

    int *begin() override;
    int *end() override;
};

// PrimeIterator class
class PrimeIterator : public Iterator
{
private:
    MagicalContainer &container;

public:
    PrimeIterator(MagicalContainer &container);

    bool isPrime(int number);
    int *begin() override;
    int *end() override;
};

#endif