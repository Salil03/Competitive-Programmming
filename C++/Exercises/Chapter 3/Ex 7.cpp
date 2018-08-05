#include "std_lib_facilities.h"
int main()
{
  cout << "Please type three integers\n";
  string val1, val2, val3;
  cin >> val1 >> val2 >> val3;
  if (val1 < val2)
  {
    if (val2 < val3)
      cout << val1 << ',' << val2 << ',' << val3 << endl;
    else
    {
      if (val3 < val1)
        cout << val3 << ',' << val1 << ',' << val2 << endl;
      else
        cout << val1 << ',' << val3 << ',' << val2 << endl;
    }
  }
  else
  {
    if (val1 < val3)
      cout << val2 << ',' << val1 << ',' << val3 << endl;
    else
    {
      if (val3 < val2)
        cout << val3 << ',' << val2 << ',' << val1 << endl;
      else
        cout << val2 << ',' << val3 << ',' << val1 << endl;
    }
  }

  // keep_window_open();
  return 0;
}