#include <iostream>
using namespace std;

void calculateCT(int ct[], int at[], int bt[], int k)
{
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < k; i++)
    {
        if (ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }
}

int main()
{
    const int n = 10;
    int k;
    int bt[n], at[n], wt[n], tt[n], ct[n];

    cout << "Enter number of processes: ";
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cout << "Enter Arrival Time for Process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
    }

    calculateCT(ct, at, bt, k);

    for (int i = 0; i < k; i++)
    {
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i] - bt[i];
    }

    cout << "\nP#\tA.T\tB.T\tC.T\tT.T\tW.T\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < k; i++)
    {
        cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i]
             << "\t" << ct[i] << "\t" << tt[i] << "\t" << wt[i] << endl;
    }

    float totalWT = 0, totalTT = 0;

    for (int i = 0; i < k; i++)
    {
        totalWT += wt[i];
        totalTT += tt[i];
    }

    cout << "\nAverage Waiting Time = " << totalWT / k << endl;
    cout << "Average Turnaround Time = " << totalTT / k << endl;

    return 0;
}
