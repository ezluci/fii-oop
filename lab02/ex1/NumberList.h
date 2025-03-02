class NumberList
{
    int numbers[10];
    int count;

public:
    // count will be 0
    void Init();

    // adds X to the numbers list and increase the data member count.
    // if count is bigger or equal to 10, the function will return false
    bool Add(int x);

    // will sort the numbers vector in non-decreasing order
    void Sort();

    // will print the current vector
    void Print();
};