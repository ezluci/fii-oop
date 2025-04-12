#include "tree.cpp"

using namespace std;

float operator"" _Kelvin(unsigned long long int x)
{
   return x - 273.15;
}

float operator"" _Fahrenheit(unsigned long long int x)
{
   return (x - 32) / 1.8;
}

template <typename T>
bool isPositive(T& value)
{
   return value >= 0;
}

template <typename T>
bool cmp_non_decreasing(T& value1, T& value2)
{
   return value1 < value2;
}

int main()
{
   float a = 300_Kelvin;
   float b = 120_Fahrenheit;
   
   Tree<int> tree;
   tree.add_node(new Node<int>, 10);
   tree.add_node(tree.getRoot(), 30);
   tree.add_node(tree.getRoot(), 25);
   tree.add_node(tree.getRoot(), 70);
   tree.printNode(tree.getRoot());
   printf("\n");
   tree.delete_node(tree.get_node(tree.getRoot(), 0));
   tree.printNode(tree.getRoot());
   printf("\n");
   tree.insert(tree.getRoot(), 0, 35);
   tree.printNode(tree.getRoot());
   printf("\n");
   tree.sort(tree.getRoot(), cmp_non_decreasing);
   tree.printNode(tree.getRoot());
   printf("\nChildren count from root: %d\n", tree.childrenCount(tree.getRoot()));
   Node<int>* test = tree.find(tree.getRoot(), isPositive);
}