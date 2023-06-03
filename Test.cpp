#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>

using namespace ariel;

TEST_CASE("Adding elements")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;
    
    // Adding an element to the container
    container.addElement(42);
    
    // Checking if the container size is 1
    CHECK(container.size() == 1);

    // Adding three more elements to the container
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    
    // Checking if the container size is 4
    CHECK(container.size() == 4);
}

TEST_CASE("Removing elements")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;
    
    // Adding four elements to the container
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    
    // Removing an element from the container
    container.removeElement(10);
    
    // Checking if the container size is 3
    CHECK(container.size() == 3);

    // Checking if removing a non-existent element throws a std::runtime_error
    CHECK_THROWS_AS(container.removeElement(50), std::runtime_error);
    
    // Checking if the container size is still 3
    CHECK(container.size() == 3);
}

TEST_CASE("Ascending iterator")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;
    
    // Adding four elements to the container
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    
    // Creating an array of expected values
    int expected[] = {10, 20, 30, 42};
    int index = 0;
    MagicalContainer::AscendingIterator it(container);

    // Iterating over the container using an ascending iterator
    while (*it != *(container.end()))
    {
        // Checking if the current value matches the expected value
        CHECK(*it == expected[index]);
        ++index;
        ++it;
    }
}

TEST_CASE("Side cross iterator")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;
    
    // Adding four elements to the container
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    
    // Creating an array of expected values
    int expected[] = {42, 30, 10, 20};
    int index = 0;
    
    MagicalContainer::SideCrossIterator it(container);

    // Iterating over the container using a side cross iterator
    while (*it != *(container.end()))
    {
        // Checking if the current value matches the expected value
        CHECK(*it == expected[index]);
        ++index;
        ++it;
    }
}

TEST_CASE("Prime iterator")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;
    
    // Adding four elements to the container
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(7);
    
    // Creating an array of expected values
    int expected[] = {7};
    int index = 0;
    
    MagicalContainer::PrimeIterator it(container);

    // Iterating over the container using a prime iterator
    while (*it != *(container.end()))
    {
        // Checking if the current value matches the expected value
        CHECK(*it == expected[index]);
        ++index;
        ++it;
    }
}

TEST_CASE("Iterator comparison")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;
    
    // Adding four elements to the container
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    
    // Creating iterators for comparison
    MagicalContainer::AscendingIterator ascIt1(container);
    MagicalContainer::AscendingIterator ascIt2(container);
    
    CHECK(ascIt1.begin() == ascIt2.begin());

    MagicalContainer::SideCrossIterator sideIt1(container);
    MagicalContainer::SideCrossIterator sideIt2(container);
    CHECK(sideIt1.begin() == sideIt2.begin());

    MagicalContainer::PrimeIterator primeIt1(container);
    MagicalContainer::PrimeIterator primeIt2(container);
    CHECK(primeIt1 == primeIt2);

    // Incrementing ascIt2
    ++ascIt2;
    
    // Checking iterator comparison and ordering
    CHECK(ascIt1 != ascIt2);
    CHECK(ascIt1 < ascIt2);
    CHECK(ascIt1 <= ascIt2);
    CHECK(ascIt2 > ascIt1);
    CHECK(ascIt2 >= ascIt1);

    // Incrementing sideIt2
    ++sideIt2;
    
    // Checking iterator comparison and ordering
    CHECK(sideIt1 != sideIt2);
    CHECK(sideIt1 < sideIt2);
    CHECK(sideIt1 <= sideIt2);
    CHECK(sideIt2 > sideIt1);
    CHECK(sideIt2 >= sideIt1);

    // Incrementing primeIt2
    ++primeIt2;
    
    // Checking iterator comparison and ordering
    CHECK(primeIt1 != primeIt2);
    CHECK(primeIt1 < primeIt2);
    CHECK(primeIt1 <= primeIt2);
    CHECK(primeIt2 > primeIt1);
    CHECK(primeIt2 >= primeIt1);
}

TEST_CASE("Multiple iterators")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;
    
    // Adding four elements to the container
    container.addElement(42);
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    // Creating iterators
    MagicalContainer::SideCrossIterator ascIt1(container);
    MagicalContainer::SideCrossIterator ascIt2(container);

    // Modifying the value using ascIt1
    *ascIt1 = 100;
    
    // Checking if the value is updated for ascIt2
    CHECK(*ascIt2 == 100);
}

TEST_CASE("Ascending iterator (negative, positive)")
{
    // Creating an instance of MagicalContainer
    MagicalContainer container;
    
    // Adding four elements to the container
    container.addElement(-10);
    container.addElement(20);
    container.addElement(-30);
    container.addElement(40);

    // Creating an array of expected values
    int expected[] = {-30, -10, 20, 40};
    int index = 0;
    
    MagicalContainer::AscendingIterator it(container);

    // Iterating over the container using an ascending iterator
    while (*it != *(container.end()))
    {
        // Checking if the current value matches the expected value
        CHECK(*it == expected[index]);
        ++index;
        ++it;

    }
}


