#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class DisjointSet 
{ //to represent disjoint set
   unordered_map<int, int> parent;
   public:
   void makeSet(vector<int> const &wholeset)
   {
   //perform makeset operation
      for (int i : wholeset) // create n disjoint sets
                             //(one for each item)
      parent[i] = i;
   }

   int Find(int l) 
   { // Find the root of the set in which element l belongs
      if (parent[l] == l) // if l is root
         return l;
      return Find(parent[l]); // recurs for parent till we find root
   }
   void Union(int m, int n) 
   { // perform Union of two subsets m and n  
      int x = Find(m);
      int y = Find(n);
      parent[x] = y;
   }
};


void print(vector<int> const &universe, DisjointSet &dis) 
{
   for (int i : universe)
   cout << dis.Find(i) << " ";
   cout << '\n';
}


int main() 
{
   vector<int> wholeset = { -3, 1, 1, 3, 1, 5, 5, 7, -3, 9, 9, 11, 9, 13, 13, 15 }; // items of whole set
   DisjointSet dis; //initialize DisjointSet class
   dis.makeSet(wholeset); // create individual set of the items of wholeset
   dis.Union(6, 14); // 7,6 are in same set
   dis.Union(7,15);
   print(wholeset, dis);
   if (dis.Find(6) == dis.Find(14)) // if they are belong to same set or not.
      cout<<"Yes"<<endl;
   else
      cout<<"No";
   if (dis.Find(3) == dis.Find(4))
      cout<<"Yes"<<endl;
   else
      cout<<"No";
   cout<< "dis.find(7) " <<dis.Find(7) << endl;
   cout<< "dis.find(15) " <<dis.Find(15) << endl;
   print(wholeset,dis);
   return 0;
}