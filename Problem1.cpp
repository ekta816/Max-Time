#include <iostream>;
#include <string>;
#include <array>;

using namespace std;
void getInput();
string MaxTime(int A, int B, int C, int D);

int main()
{

	getInput();
	
	

	system("PAUSE");
	return 0;
}


void getInput()
{
	string s;
	cout << "Please enter 4 numbers without spaces: ";
	getline(cin, s);

	int A, B, C, D;
	
	A = s[0] - 48;
	B = s[1] - 48;
	C = s[2] - 48;
	D = s[3] - 48;


	

	if ((A >= 0 && A < 9) && (B >= 0 && B < 9) && (C >= 0 && C < 9) && (D >= 0 && D < 9))
	{
		cout << " YOU entered : " << A << " " << B << " " << C << " " << D << endl;
		
		cout<< MaxTime(A, B, C, D);
	}
	else
	{
		cout << "Please enter numbers between 0 and 9" << endl;
		getInput();
	}
	
}

string MaxTime(int A, int B, int C, int D)
{
	string s = "NOT POSSIBLE!";
	
	int numbers[]{ A, B, C, D };
	bool valid[4] = { true, true,true,true };
	int hour = 0;
	int minute = 0;
	bool success = false;

	for (int h = 24; h > 0; h--)
	{
		for (int i = 0; i < 4; i++)
		{
			if (h / 10 == numbers[i] && valid[i])
			{
				valid[i] = false;
				for (int j = 0; j < 4; j++)
				{
					if (h % 10 == numbers[j] && valid[j])
					{
						valid[j] = false;
						hour = numbers[i] * 10 + numbers[j];
						success = true;
						break;
					}
				}
				if (success != true)
				{
					valid[i] = true;
				}
				else
				{
					break;
				}
			}
		}
		if (success == true)
		{
			success = false;
			break;
		}
	}

	for (int m = 60; m > 0; m--)
	{
		for (int i = 0; i < 4; i++)
		{
			if (m / 10 == numbers[i] && valid[i])
			{
				valid[i] = false;
				for (int j = 0; j < 4; j++)
				{
					if (m % 10 == numbers[j] && valid[j])
					{
						valid[j] = false;
						minute = numbers[i] * 10 + numbers[j];
						success = true;
						break;
					}
				}
				if (success != true)
				{
					valid[i] = true;
				}
				else
				{
					break;
				}
			}
		}
		if (success == true)
		{
			success = false;
			break;
		}
	}

	if ((valid[0] || valid[1] || valid[2] || valid[3]) != false)
	{
		return "Not Possible!";
	}
	else
	{
		cout << hour << ":" << minute << endl;
		return hour + ":" + minute;
	}
	
	
}

