#include "doctest.h"
#include "sources/MagicalContainer.h"
#include <stdexcept>
#include <iostream>

TEST_CASE("Tests")
{
    SUBCASE("Test adding elements and size")
    {
        MagicalContainer container;
        CHECK(container.size() == 0);

        container.addElement(5);
        CHECK(container.size() == 1);

        container.addElement(10);
        CHECK(container.size() == 2);

        container.addElement(15);
        CHECK(container.size() == 3);
    }

    SUBCASE("Test removing elements and size")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);

        CHECK(container.size() == 3);

        container.removeElement(10);
        CHECK(container.size() == 2);

        container.removeElement(5);
        CHECK(container.size() == 1);

        container.removeElement(15);
        CHECK(container.size() == 0);
    }

    SUBCASE("Test AscendingIterator")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        AscendingIterator ascIterator(container);

        int expectedValues[] = {3, 5, 10};
        int index = 0;
        for (int *it = ascIterator.begin(); it != ascIterator.end(); ++it)
        {
            CHECK(*it == expectedValues[index]);
            ++index;
        }
    }

    SUBCASE("Test SideCrossIterator")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        SideCrossIterator sideCrossIterator(container);

        int expectedValues[] = {5, 10, 3};
        int index = 0;
        for (int *it = sideCrossIterator.begin(); it != sideCrossIterator.end(); ++it)
        {
            CHECK(*it == expectedValues[index]);
            ++index;
        }
    }

    SUBCASE("Test PrimeIterator")
    {
        MagicalContainer container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(11);
        container.addElement(4);

        PrimeIterator primeIterator(container);

        int expectedValues[] = {7, 11};
        int index = 0;
        for (int *it = primeIterator.begin(); it != primeIterator.end(); ++it)
        {
            CHECK(*it == expectedValues[index]);
            ++index;
        }
    }

    SUBCASE("Test PrimeIterator with empty container")
    {
        MagicalContainer container;

        PrimeIterator primeIterator(container);

        CHECK(primeIterator.begin() == primeIterator.end());
    }

    SUBCASE("Test adding and removing large number of elements")
    {
        MagicalContainer container;

        const int numElements = 10000;

        // Add elements
        for (int i = 0; i < numElements; ++i)
        {
            container.addElement(i);
        }

        CHECK(container.size() == numElements);

        // Remove even elements
        for (int i = 0; i < numElements; i += 2)
        {
            container.removeElement(i);
        }

        CHECK(container.size() == numElements / 2);

        // Remove remaining elements
        for (int i = 1; i < numElements; i += 2)
        {
            container.removeElement(i);
        }

        CHECK(container.size() == 0);
    }

    SUBCASE("Test accessing iterators after modifying the container")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        AscendingIterator ascIterator(container);
        SideCrossIterator sideCrossIterator(container);
        PrimeIterator primeIterator(container);

        // Modify container after getting iterators
        container.addElement(7);
        container.removeElement(10);

        int expectedAscending[] = {3, 5, 7};
        int expectedSideCross[] = {5, 3, 7};
        int expectedPrime[] = {7};

        int index = 0;

        for (int *it = ascIterator.begin(); it != ascIterator.end(); ++it)
        {
            CHECK(*it == expectedAscending[index]);
            ++index;
        }

        index = 0;

        for (int *it = sideCrossIterator.begin(); it != sideCrossIterator.end(); ++it)
        {
            CHECK(*it == expectedSideCross[index]);
            ++index;
        }

        index = 0;

        for (int *it = primeIterator.begin(); it != primeIterator.end(); ++it)
        {
            CHECK(*it == expectedPrime[index]);
            ++index;
        }
    }

    // Add more test cases here...

    SUBCASE("Test throwing exception when removing non-existing element")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);

        CHECK(container.size() == 2);

        CHECK_THROWS_AS(container.removeElement(7), std::range_error);
        CHECK(container.size() == 2);
    }

    SUBCASE("Test throwing exception when accessing iterator with empty container")
    {
        MagicalContainer container;
        AscendingIterator ascIterator(container);

        CHECK_THROWS_AS(ascIterator.begin(), std::logic_error);
        CHECK_THROWS_AS(ascIterator.end(), std::logic_error);
    }
    SUBCASE("Test iterator behavior after modifying container during iteration")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        AscendingIterator ascIterator(container);

        // Remove an element during iteration
        container.removeElement(10);

        int expectedValues[] = {3, 5};
        int index = 0;
        for (int *it = ascIterator.begin(); it != ascIterator.end(); ++it)
        {
            CHECK(*it == expectedValues[index]);
            ++index;
        }
    }

    SUBCASE("Test iterator behavior after adding element during iteration")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        SideCrossIterator sideCrossIterator(container);

        // Add an element during iteration
        container.addElement(7);

        int expectedValues[] = {5, 10, 3, 7};
        int index = 0;
        for (int *it = sideCrossIterator.begin(); it != sideCrossIterator.end(); ++it)
        {
            CHECK(*it == expectedValues[index]);
            ++index;
        }
    }

    SUBCASE("Test multiple iterators on the same container")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(3);

        AscendingIterator ascIterator(container);
        SideCrossIterator sideCrossIterator(container);

        // Iterate over elements using AscendingIterator
        int expectedAscending[] = {3, 5, 10};
        int ascIndex = 0;
        for (int *it = ascIterator.begin(); it != ascIterator.end(); ++it)
        {
            CHECK(*it == expectedAscending[ascIndex]);
            ++ascIndex;
        }

        // Iterate over elements using SideCrossIterator
        int expectedSideCross[] = {5, 10, 3};
        int sideCrossIndex = 0;
        for (int *it = sideCrossIterator.begin(); it != sideCrossIterator.end(); ++it)
        {
            CHECK(*it == expectedSideCross[sideCrossIndex]);
            ++sideCrossIndex;
        }
    }
}
