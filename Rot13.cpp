#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> dictionary = { "hello", "world", "goodbye", "moon", "sun", "star", "planet", "galaxy", "universe", "earth", "mars", "jupiter", "saturn", "neptune", "uranus", "pluto", "mercury", "venus", "asteroid", "comet", "meteor", "meteorite", "blackhole", "supernova", "quasar", "alien", "astronaut", "spaceship", "rocket", "satellite", "telescope", "observatory", "cosmos", "milkyway", "orbit", "eclipse", "astronomy", "astrophysics", "gravity", "nebula", "cluster", "constell" };

string rot_n(string str, int n)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = 'a' + (str[i] - 'a' + n) % 26;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = 'A' + (str[i] - 'A' + n) % 26;
		}
	}
	return str;
}

string rot_n_decrypt(const string str)
{
	for (int i = 0; i < 26; i++)
	{
		string result = rot_n(str, i);
		string word = "";
		int index = 0;
		bool found = true;
		while (index < result.length())
		{
			if (result[index] == ' ')
			{
				if (find(dictionary.begin(), dictionary.end(), word) == dictionary.end())
				{
					found = false;
					break;
				}
				else
				{
					word = "";
				}
			}
			else
			{
				word += result[index];
			}
			index++;
		}

		if (found) 
		{
			return result;
		}
	}
}

string rot13(const string s)
{
	string result = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'm')
		{
			result += s[i] + 13;
		}
		else if (s[i] >= 'n' && s[i] <= 'z')
		{
			result += s[i] - 13;
		}
		else if (s[i] >= 'A' && s[i] <= 'M')
		{
			result += s[i] + 13;
		}
		else if (s[i] >= 'N' && s[i] <= 'Z')
		{
			result += s[i] - 13;
		}
		else
		{
			result += s[i];
		}
	}
	return result;
}

bool TestRot13()
{
	string s = "Hello World!";
	string result = rot13(s);
	if (result != "Uryyb Jbeyq!")
	{
		return false;
	}
	return true;
}

bool TestRot13Decrypt()
{
	string s = "Hello World!";
	string result = rot13(s);
	result = rot13(result);
	if (result != s)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool TestRotN()
{
	srand(time(NULL));
	int N = 3 + rand() % 5;
	// generate a string of N length from words in dictionary
	string s = "";
	for (int i = 0; i < N; i++)
	{
		int index = rand() % dictionary.size();
		s += dictionary[index];
		s += " ";
	}

	// encrypt the string
	int M = 1 + rand() % 25;
	string result = rot_n(s, M);

	// decrypt the string
	string decrypted = rot_n_decrypt(result);
	return s == decrypted;
}

int main()
{
	if (TestRot13())
	{
		cout << "TestRot13 passed" << endl;
	}
	else
	{
		cout << "TestRot13 failed" << endl;
	}

	if (TestRot13Decrypt())
	{
		cout << "TestRot13Decrypt passed" << endl;
	}
	else
	{
		cout << "TestRot13Decrypt failed" << endl;
	}

	if (TestRotN())
	{
		cout << "TestRotN passed" << endl;
	}
	else
	{
		cout << "TestRotN failed" << endl;
	}

	const int numTests = 100;
	bool passed = true;
	for (int i = 0; i < numTests; i++)
	{
		if (!TestRotN())
		{
			passed = false;
			break;
		}
	}
	if (passed) 
	{
		cout << "All TestRotN tests Passed" << endl;
	}
	else
	{
		cout << "TestRotN failed" << endl;
	}
	return 0;
}
