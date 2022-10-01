
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum operations
void solve(string str)
{
	// Length of the string
	int n = str.length();

	// answer variable for final answer
	// initializing it with INF
	int answer = n;

	// Iterating over characters
	// from '0' to '9' (string
	// consist of those characters only)
	for (char currentCharacter = '0';
		currentCharacter <= '9';
		currentCharacter++) {

		// i and j variables to check corresponding
		// characters from the start and the end
		int i = 0, j = n - 1;

		// toBeRemoved store the character of type
		// currentCharacter to be removed
		// to make the string palindrome

		int toBeRemoved = 0;
		bool possible = true;
		while (i < j) {
			// If corresponding currentCharacters are
			// already same
			if (str[i] == str[j]) {
				i++, j--;
			}

			// If corresponding currentCharacters are
			// not same and str[i] is equal to
			// currentCharacter
			// remove it and check for str[i + 1] and
			// str[j] in the next iteration
			else if (str[i] != str[j]
					&& str[i] == currentCharacter) {
				toBeRemoved++;
				i++;
			}

			// If corresponding currentCharacters are
			// not same and str[j] is equal to
			// currentCharacter
			// remove it and check for str[j - 1] and
			// str[i] in the next iteration
			else if (str[i] != str[j]
					&& str[j] == currentCharacter) {
				toBeRemoved++;
				j--;
			}

			// Character of currentCharacter type
			// can't be removed
			// to make the str palindrome.
			// Hence, we mark possible to false
			// break out of the loop
			else {
				possible = false;
				break;
			}
		}

		// If it is possible to remove
		// some occurrences of currentCharacters
		// we will update our answer
		if (possible)

			// Take the minimum value out
			// of answer and toBeRemoved
			answer = min(answer, toBeRemoved);
	}

	// Print the final answer
	if (answer == n)
		cout << "-1";
	else
		cout << answer;
}

// Driver Code
int main()
{
	// Given string
	string str = "11221";
	solve(str);
}
