#include <iostream>
using namespace std;

int main()
{
  const int Nstart = 1000;
  const int Nend = 10000;
  const int deltaN = 1000;
  const int q = 10;

  for (int N = Nstart; N <= Nend; N += deltaN)
  {
    double times[q];

    for (int rep = 0; rep < q; ++rep)
    {
      int *arr = new int[N];

      for (int i = 0; i < N; ++i)
      {
        arr[i] = (i * 37 + rep * 61) % 101;
      }

      clock_t start = clock();

      int gap = N;
      bool sorted = false;
      float shrink = 1.247f;

      while (!sorted)
      {
        gap = int(gap / shrink);
        if (gap <= 1)
        {
          gap = 1;
          sorted = true;
        }

        for (int i = 0; i + gap < N; ++i)
        {
          if (arr[i] > arr[i + gap])
          {
            int temp = arr[i];
            arr[i] = arr[i + gap];
            arr[i + gap] = temp;
            sorted = false;
          }
        }
      }

      clock_t end = clock();
      double duration = 1000.0 * (end - start);
      times[rep] = duration;

      delete[] arr;
    }

    for (int i = 0; i < q - 1; ++i)
    {
      for (int j = 0; j < q - i - 1; ++j)
      {
        if (times[j] > times[j + 1])
        {
          double temp = times[j];
          times[j] = times[j + 1];
          times[j + 1] = temp;
        }
      }
    }

    int validCount = q * 4 / 5;
    double sum = 0;
    for (int i = 0; i < validCount; ++i)
    {
      sum += times[i];
    }

    double avgTime = sum / validCount;

    cout << "Average running time of the algorithm on input data of size " << N << ": " << avgTime << " milliseconds." << endl;
  }

  return 0;
}
