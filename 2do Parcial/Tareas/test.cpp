/*
Description:
You have to cut a wood stick into pieces. The most affordable company, The Analog Cutting Machinery, Inc. (ACM), charges money according to the length of the stick being cut. Their procedure of work requires that they only make one cut at a time.
It is easy to notice that different selections in the order of cutting can led to different prices. For example, consider a stick of length 10 meters that has to be cut at 2, 4 and 7 meters from one end. There are several choices. One can be cutting first at 2, then at 4, then at 7. This leads to a price of 10 + 8 + 6 = 24 because the first stick was of 10 meters, the resulting of 8 and the last one of 6. Another choice could be cutting at 4, then at 2, then at 7. This would lead to a price of 10 + 4 + 6 = 20, which is a better price.
Your boss trusts your computer abilities to find out the minimum cost for cutting a given stick.
Input:
The input will consist of several input cases. The first line of each test case will contain a positive number l that represents the length of the stick to be cut. You can assume l < 1000. The next line will contain the number n (n <= 50) of cuts to be made. The next line consists of n positive numbers ci ( 0 < ci < l) representing the places where the cuts have to be done, given in strictly increasing order. An input case with l = 0 will represent the end of the input.
Output:
You have to print the cost of the optimal solution of the cutting problem, that is the minimum cost of cutting the given stick. Format the output as shown below.
Sample Input:
100
3
25 50 75
10
4
4 5 7 8
0
Sample Output:
The minimum cutting is 200.
The minimum cutting is 22.
*/

#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

void MultM(int D[], int n, int l)
{
    int m[50][50];
    for (int i = 1; i <= n; i++)
	{
			cin >> D[i];
	}
		D[0] = 0;
		D[++n] = l;

		for (int j = 1; j <= n; j++)
		{
			for (int i = j - 1; i >= 0; i--) 
            {
				if (i + 1 == j)
				{
					m[i][j] = 0;
				}
				
				else 
				{
					m[i][j] = INT_MAX;
					for (int k = i + 1; k < j; k++) 
                    {
						if (m[i][k] + m[k][j] < m[i][j])
						{
							m[i][j] = m[i][k] + m[k][j];
						}
					}
					m[i][j] += D[j] - D[i];
				}
			}
		}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}

    cout << "The minimum cutting is " << m[0][n] << "." << endl;
}

int main()
{
    int l;
    cin >> l;
    while(l)
    {
        int n, D[50], m[50][50];
        cin >> n; 
        MultM(D, n, l);
        cin >> l;
    }

    return 0;
}
