#include <iostream>
#include <vector>
#include <algorithm>

#include "sort.h"

Sort::Sort()
{
    this->vec = {};
}

Sort::Sort(int size)
{
    this->vec = {};
    for (int i = 0; i < size; i++)
    {
        vec.push_back(randNum(0, 999));
    }
}

bool Sort::isEmpty()
{
    return this->vec.empty();
}

int Sort::randNum(int min, int max)
{
    return rand() % (max - min) + min;
}

int Sort::getMin()
{
    int m{MAX_VAL + 1};

    for (auto e : vec)
    {
        if (e < m)
            m = e;
    }

    return m;
}

int Sort::getMax()
{
    int M{MIN_VAL - 1};

    for (auto e : vec)
    {
        if (e > M)
            M = e;
    }

    return M;
}

void Sort::countingSort(int place)
{
    const int countSize = 10;
    int *count = new int[countSize];

    for (int i = 0; i < countSize; i++)
        count[i] = 0;

    for (auto e : vec)
        count[(e / place) % 10]++;

    for (int i = 1; i < countSize; i++)
        count[i] += count[i - 1];

    int *output = new int[vec.size()];

    for (long i = vec.size() - 1; i >= 0; i--)
    {
        output[count[(vec[i] / place) % 10] - 1] = vec[i];
        count[(vec[i] / place) % 10]--;
    }

    for (unsigned long j = 0; j < vec.size(); j++)
        vec[j] = output[j];

    delete[] count;
    delete[] output;
}

void Sort::radixSort()
{
    int max = this->getMax();

    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(place);
    }
}

std::ostream &operator<<(std::ostream &out, const Sort &s)
{
    if (s.vec.empty())
    {
        out << "Vector is empty" << std::endl;
        return out;
    }

    for (auto e : s.vec)
    {
        out << e << " ";
    }

    out << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Sort &s)
{
    int x{0};
    in >> x;
    s.vec.push_back(x);
    return in;
}