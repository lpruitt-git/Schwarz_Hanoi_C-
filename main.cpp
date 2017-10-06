// Schwarz_Hanoi_C++
// By Lucas Pruitt
// 10/6/2017

// This program is an implementation of a Towers of Hanoi problem
// solution the algorithm for which is described in this video:
// https://www.youtube.com/watch?v=2SUvWfNJSsM

#include <cstdlib>
#include <string>
#include <stack>
#include <iterator>
#include <iostream>

using namespace std;

void pushPopper(stack<int>* peg)
{
	if(!(peg->empty()))
	{
		int disk = peg->top();
		peg->pop();
		pushPopper(peg);
		cout << disk << "\t";
		peg->push(disk);
	}
}

void boardPrinter(stack<int>** board)
{
	char c = 'A';

	for (int x = 0; x < 3; ++x, ++c)
	{
		cout << "Peg " << c << ":\t";
		pushPopper(board[x]);
		cout << endl;
	}
	cout << endl;
}

void moveDisk(stack<int>** board, int n)
{
	int hand;
	bool found = false;

	for (int i = 0; i < 3 && !found; ++i)
	{
		if ((board[i]->size() > 0) && (board[i]->top() == n))
		{
			found = true;
			hand = board[i]->top();
			board[i]->pop();

			if ((board[((i + 1) % 3)]->size() == 0) || (board[((i + 1) % 3)]->top() > hand))
				board[((i + 1) % 3)]->push(hand);
			else
				board[((i + 2) % 3)]->push(hand);
		}
	}
}

void diskMover(stack<int>** board, int n)
{
	if (n == 1)
	{
		moveDisk(board, n - 1);
		boardPrinter(board);
	}
	else
	{
		diskMover(board, n - 1);
		moveDisk(board, n - 1);
		boardPrinter(board);
		diskMover(board, n - 1);
	}
}

int main()
{
	string input;
	int n;
	cout << "Enter a value for n: ";
	cin >> input;
	char* cstring = new char[input.size()];
	for (unsigned int i = 0; i < input.size(); ++i)
		cstring[i] = input[i];
	n = atoi(cstring);

	stack<int>* a = new stack<int>;
	stack<int>* b = new stack<int>;
	stack<int>* c = new stack<int>;
	stack<int>* board[3] = { a, b, c };
	for (int i = n; i > 0; --i)
		board[0]->push(i - 1);

	boardPrinter(board);
	diskMover(board, n);
	system("Pause");

    return 0;
}

