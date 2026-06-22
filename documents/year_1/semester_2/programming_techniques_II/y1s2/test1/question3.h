#ifndef QUESTION3_H
#define QUESTION3_H

class Counter{
    private:
    int count;
    int maxValue;
    public:
    Counter(int maxVal);
    void increment();
    void decrement();
    void setCount(int c);
    void setMaxVal(int maxVal);
    int getCount();
    int getMaxVal();

};

#endif

