#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <cmath>

namespace ariel
{

    class MagicalContainer
    {
    private:
        std::vector<int> elements;

    public:
        MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        int size() const;

        virtual int *begin()
        {
            return elements.data();
        }

        virtual int *end()
        {
            return elements.data() + elements.size();
        }

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

        public:
            AscendingIterator(MagicalContainer &container);

            int &operator*();

            AscendingIterator &operator++();

            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<=(const AscendingIterator &other) const;
            bool operator>=(const AscendingIterator &other) const;

            int *begin();
            int *end();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t forwardIndex;
            size_t backwardIndex;
            bool isForward;

        public:
            SideCrossIterator(MagicalContainer &container);

            int &operator*();

            SideCrossIterator &operator++();

            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<=(const SideCrossIterator &other) const;
            bool operator>=(const SideCrossIterator &other) const;

            int *begin();
            int *end();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

            bool isPrime(int num);

        public:
            PrimeIterator(MagicalContainer &container);

            int &operator*();

            PrimeIterator &operator++();

            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<=(const PrimeIterator &other) const;
            bool operator>=(const PrimeIterator &other) const;
            int *begin();
            int *end();
        };
    };

}
#endif
