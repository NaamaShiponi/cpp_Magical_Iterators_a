#include "MagicalContainer.hpp"

namespace ariel
{

    MagicalContainer::MagicalContainer() {}

    void MagicalContainer::addElement(int element)
    {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element)
    {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end())
        {
            elements.erase(it);
        }
    }

    int MagicalContainer::size() const
    {
        return elements.size();
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : container(container)
    {
    }

    int &MagicalContainer::AscendingIterator::operator*()
    {
            return container.elements[index];

    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        ++index;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return &container == &(other.container) && index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }
         bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return !(*this == other);
    }
     bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return !(*this == other);
    }
     bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator &other) const
    {
        return !(*this == other);
    } bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    int *MagicalContainer::AscendingIterator::begin()
    {

        std::sort(container.elements.begin(), container.elements.end());
        return container.elements.data();
    }
    int *MagicalContainer::AscendingIterator::end()
    {
        return container.elements.data() + container.elements.size();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        : container(container) {}

    int &MagicalContainer::SideCrossIterator::operator*()
    {
        if (isForward)
        {
            return container.elements[forwardIndex];
        }
        else
        {
            return container.elements[backwardIndex];
        }
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (isForward)
        {
            ++forwardIndex;
            isForward = false;
        }
        else
        {
            --backwardIndex;
            isForward = true;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return &container == &(other.container) && forwardIndex == other.forwardIndex &&
               backwardIndex == other.backwardIndex && isForward == other.isForward;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }
     bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }
     bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }
     bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    } bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }
    int *MagicalContainer::SideCrossIterator::begin()
    {
        return container.elements.data();
    }
    int *MagicalContainer::SideCrossIterator::end()
    {
        return container.elements.data() + container.elements.size();
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        : container(container){}

    int &MagicalContainer::PrimeIterator::operator*()
    {
            return container.elements[index];

    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        ++index;
        while (index < container.elements.size() && !isPrime(container.elements[index]))
        {
            ++index;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return &container == &(other.container) && index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }
     bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return !(*this == other);
    }
     bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return !(*this == other);
    }
     bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator &other) const
    {
        return !(*this == other);
    } bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::isPrime(int num)
    {
        if (num < 2)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int *MagicalContainer::PrimeIterator::begin()
    {
        std::vector<int> primes;
        for (int element : container.elements)
        {
            if (isPrime(element))
            {
                primes.push_back(element);
            }
        }
        container.elements = primes;
        return container.elements.data();
    }
    int *MagicalContainer::PrimeIterator::end()
    {
        return container.elements.data() + container.elements.size();
    }

}
