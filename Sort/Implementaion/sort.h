#include <iostream>
#include <vector>

#ifndef SORT_H
#define SORT_H

class Sort
{
public:
    Sort();
    Sort(int size);

    bool isEmpty();
    void mergeSort();
    void quickSort();
    void radixSort();
    void shaffle();
    int getMin();
    int getMax();

    friend bool &operator==(const Sort &, const Sort &);
    friend std::ostream &operator<<(std::ostream &, const Sort &);
    friend std::istream &operator>>(std::istream &, Sort &);

private:
    std::vector<int> vec;
    void countingSort(int place);
    static int randNum(int min, int max);

    static const int MIN_VAL = 0;
    static const int MAX_VAL = 999;
};

#endif