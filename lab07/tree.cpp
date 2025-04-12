#include <iostream>
#define MAX_NODES 10

template <typename T>
class Node
{
public:
   T data;
   Node<T>* parent = nullptr;
   Node<T>* children[MAX_NODES];
   int count = 0;

   Node(T data)
   {
      this->data = data;
      for (int i = 0; i < MAX_NODES; i++)
         children[i] = nullptr;
   }
   Node()
   {
      this->data = 0;
      for (int i = 0; i < MAX_NODES; i++)
         this->children[i] = nullptr;
   }

   T getData()
   {
      return data;
   }
};

template <typename T>
class Tree
{
private:
   Node<T>* root = nullptr;
public:
   Tree()
   {
      root = new Node<T>(0);
   }

   void printNode(Node<T>* node)
   {
      if (node != nullptr)
      {
         printf("%d: [", node->data);
         for (int i = 0; i < MAX_NODES; ++i)
            if (node->children[i] != nullptr)
               this->printNode(node->children[i]);
         printf("%c ", ']');
      }
   }

   void add_node(Node<T>* node, T value)
   {
      if (node == nullptr)
      {
         delete_node(root);
         root = new Node<T>(value);
      }
      else if (node->count < MAX_NODES)
      {
         for (int i = 0; i < MAX_NODES; ++i)
            if (node->children[i] == nullptr)
            {
               node->children[i] = new Node<T>(value);
               break;
            }
         ++node->count;
      }
      else return;
   }

   Node<T>* getRoot()
   {
      return root;
   }

   Node<T>* get_node(Node<T>* parent_node, int index)
   {
      return parent_node->children[index];
   }

   void delete_node(Node<T>* node)
   {
      if (node == nullptr)
         return;
      for (int i = 0; i < MAX_NODES; ++i)
         if (node->children[i] != nullptr)
            this->delete_node(node->children[i]);
      delete node;
      node = nullptr;
   }

   Node<T>* find(Node<T>* node, bool(*compare)(const T&))
   {
      Node<T>* queue[100];
      int left = 0, right = 0;
      queue[right++] = node;
      while (left <= right)
      {
         if (queue[left] != nullptr && compare(queue[left]->data))
            return queue[left];
         for (int i = 0; i < MAX_NODES; ++i)
            if (queue[left]->children[i] != nullptr)
               queue[right++] = queue[left]->children[i];
         ++left;
      }
      return nullptr;
   }

   void insert(Node<T>* node, int index, T value)
   {
      if (node->children[index] == nullptr)
      {
         node->children[index] = new Node<T>(value);
         node->count++;
      }
      else
         node->children[index] = new Node<T>(value);
   }

   void sort(Node<T>* node, bool(*compare)(const T&, const T&))
   {
      for (int i = 0; i < MAX_NODES - 1; ++i)
         for (int j = i + 1; j < MAX_NODES; ++j)
            if (compare)
            {
               if (node->children[i] && node->children[j] && compare(node->children[i]->data, node->children[j]->data))
                  std::swap(node->children[i], node->children[j]);
               else if (node->children[j] && !node->children[i])
                  std::swap(node->children[i], node->children[j]);
            }
            else
            {
               if (node->children[i] && node->children[j] && node->children[i]->data > node->children[j]->data)
                  std::swap(node->children[i], node->children[j]);
               else if (node->children[j] && !node->children[i])
                  std::swap(node->children[i], node->children[j]);
            }
   }

   int childrenCount(Node<T>* node)
   {
      if (node == nullptr)
         return this->childrenCount(root);
      else
      {
         int cCount = node->count;
         for (int i = 0; i < MAX_NODES; ++i)
            if (node->children[i] != nullptr)
               cCount += this->childrenCount(node->children[i]);
         return cCount;
      }
   }
};