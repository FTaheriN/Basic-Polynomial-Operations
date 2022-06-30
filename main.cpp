#include <iostream>

using namespace std;

static float p = 0;
static float q = 0;


float DivAns(float z)
{
	q = p + z*q;
	return q;
}

float PolyAns(int i, float a, float z)
{
	p = (p*z) + a;
	return p;
}

void SumOfPoly()
{
	int a[50];
	int b[50];
	int na = 0;
	int nb = 0;
	int z;
	cout << "enter z" << endl;
	cin >> z;
	cout << "enter highest power of first poly" << endl;
	cin >> na;
	cout << "enter coeficiant of first polynomial including 0 by order" << endl;
	for (int i = 0;i <= na;i++)
		cin >> a[i];
	p = a[0];
	for (int i = 1;i <= na;i++)
	{
		PolyAns(i, a[i], z);
	}
	int ans1 = p;
	cout << "enter highest power of second poly" << endl;
	cin >> nb;
	cout << "enter coeficiant of second polynomial including 0 by order" << endl;
	for (int i = 0;i <= nb;i++)
		cin >> b[i];
	p = b[0];
	for (int i = 1;i <= nb;i++)
	{
		PolyAns(i, b[i], z);
	}
	int ans2 = p;
	cout << "Sum of two polys = " << ans1 + ans2 << endl;
}

void MultPoly()
{
	int a[50];
	int b[50];
	int c[2][50];
	int na = 0;
	int nb = 0;
	int z;
	cout << "enter z" << endl;
	cin >> z;
	cout << "enter highest power of first poly" << endl;
	cin >> na;
	cout << "enter coeficiant of first polynomial including 0 by order" << endl;
	for (int i = 0;i <= na;i++)
		cin >> a[i];
	cout << "enter highest power of second poly" << endl;
	cin >> nb;
	cout << "enter coeficiant of second polynomial including 0 by order" << endl;
	for (int i = 0;i <= nb;i++)
		cin >> b[i];
	for (int i = 0;i < 2;i++)
		for (int j = 0;j < 50;j++)
			c[i][j] = 0;
	int k = 0;
	for (int i = 0;i <= na;i++)
	{
		if (a[i]!=0)
			for (int j = 0;j <= nb;j++)
			{
				if (b[j] != 0)
				{
					c[0][k] = a[i] * b[j];
					c[1][k] = (na - i) + (nb - j);
					k++;
				}
			}
	}
	for (int i = 0;i < k;i++)
	{
		for (int j = i;j < k;j++)
		{
			if (c[0][j] < c[0][j + 1])
			{
				int cof = c[1][j + 1];
				int pow = c[0][j + 1];
				c[1][j + 1] = c[1][j];
				c[0][j + 1] = c[0][j];
				c[1][j] = cof;
				c[0][j] = pow;
			}
			if (c[0][j] == c[0][j + 1])
			{
				c[1][j] += c[1][j + 1];
				c[0][j + 1] = 0;
				c[1][j + 1] = 0;
			}
		}
	}
	p = c[1][0];
	int ord = c[0][0];
	float cof[50];
	for (int i = 1;c[1][i] = !0;i++)
	{
		if (c[0][i] == ord)
			cof[i] = c[0][i];
		else
			cof[i] = 0;
		ord--;
	}
	cout << "multiply of the two polys given with value of z= " << z << "is: " << p << endl;
}

int main()
{
	float a[50];
	int n = 0;
	float z = 0;
	int choice;
	
	cout << "what would you ike to do?(enter number)" << endl;
	cout << "1.ans of poly		2.ans of divertion" << endl
		<< "3.sum of two poly or divertion		4.multiply of polys" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "enter highest power" << endl;
		cin >> n;
		cout << "enter z" << endl;
		cin >> z;
		cout << "enter coeficiant of polynomial including 0 by order" << endl;
		for (int i = 0;i <= n;i++)
			cin >> a[i];
		p = a[0];
		for (int i = 1;i <= n;i++)
		{
			PolyAns(i, a[i], z);
		}
		cout << "value of p(" << z << ") is " << p << endl;
		break;
	case 2:
		cout << "enter highest power" << endl;
		cin >> n;
		cout << "enter z" << endl;
		cin >> z;
		cout << "enter coeficiant of polynomial including 0 by order" << endl;
		for (int i = 0;i <= n;i++)
			cin >> a[i];
		p = a[0];
		for (int i = 1;i <= n;i++)
		{
			DivAns(z);
			PolyAns(i, a[i], z);
		}
		cout << "value of p'(" << z << ") is " << q << endl;
		break;
	case 3:
		SumOfPoly();
		break;
	case 4:
		MultPoly();
		break;
	default:
		cout << "exit program" << endl;
	};
	
	return 0;
}