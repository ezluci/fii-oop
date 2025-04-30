#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

const std::string DELIM = "., ?!";

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      std::cout << "The first parameter must be a text file.\n";
      return 1;
   }

   std::ifstream fin(argv[1]);
   if (!fin.is_open())
   {
      std::cout << "The file " << argv[1] << " does not exist.\n";
      return 2;
   }

   std::string line;
   std::getline(fin, line);

   size_t pos = 0;
   std::unordered_map<std::string, size_t> words;

   while (true)
   {
      size_t pos2 = line.find_first_of(DELIM, pos);
      std::string word;

      if (pos2 == std::string::npos)
      {
         word = line.substr(pos);
      }
      else
      {
         word = line.substr(pos, pos2 - pos);
         pos = pos2 + 1;
      }

      if (!word.empty())
      {
         std::transform(word.cbegin(), word.cend(), word.begin(), tolower);
         words[word]++;
      }

      if (pos2 == std::string::npos)   break;
   }

   struct Pair {
      size_t count;
      std::string word;

      Pair(size_t count, std::string word) : count(count), word(word) {}

      bool operator< (const Pair &other) const
      {
         if (count != other.count)
            return other.count > count;
         return other.word < word;
      }
   };
   std::priority_queue<Pair> queue;

   for (auto &[word, count] : words)
      queue.push(Pair(count, word));

   
   while (!queue.empty())
   {
      std::cout << queue.top().word << " => " << queue.top().count << '\n';
      queue.pop();
   }
}