#include <iostream>
#include <set>
#include <algorithm>
#include <iterator> // ostream_iterator
using namespace std;
int main()
{
   double a[ 5 ] = { 2.1, 4.2, 9.5, 2.1, 3.7 };
   set< double, less< double > > doubleSet( a, a + 4);;
   ostream_iterator< double > output( cout, " " );

   cout << "doubleSet contains: ";
   copy( doubleSet.begin(), doubleSet.end(), output );

   cout << endl;
   return 0;
}
