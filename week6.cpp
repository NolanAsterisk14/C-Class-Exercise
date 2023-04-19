#include <iostream>
using namespace std;
int readDials(char &a, char &b, char &c, char &d, char &e, char &f, char &g, char &h);
int toDigit(char &x);
void AcknowledgeCall(char phone[8], int resultCode);

int main()
{
	char cont = 't';
	char input;
	char myinput[8];

	do
	{
		cout << "Enter a phone number (Q to quit): ";
		for (int i = 0; i < 8; i++)
		{
			cin >> input;
			if (toupper(input) == 'Q' && i == 0)
			{
				cont = 'f';
				break;
			}
			else
			{
				myinput[i] = input;
			}
		}
		if (cont == 't')
		{
			int result = readDials(myinput[0], myinput[1], myinput[2], myinput[3], myinput[4], myinput[5], myinput[6], myinput[7]);
			AcknowledgeCall(myinput, result);
		}
	} while (cont == 't');
	return 0;
}

int readDials(char &a, char &b, char &c, char &d, char &e, char &f, char &g, char &h)
{
	if (toDigit(a) == -1) 
		return -1;
	else if (toDigit(b) == -1) 
		return -1;
	else if (toDigit(c) == -1) 
		return -1;
	else if (toDigit(d) == -1) 
		return -1;
	else if (toDigit(e) == -1) 
		return -1;
	else if (toDigit(f) == -1) 
		return -1;
	else if (toDigit(g) == -1) 
		return -1;
	else if (toDigit(h) == -1) 
		return -1;
	
	else if (a == '0') return -2;
	else if (a == '5' && b == '5' && c == '5') return -3;
	else if (d != '-') return -4;
	else
	return 0;
}

int toDigit(char &x)
{
	int valid = 0;
	switch (toupper(x))
	{
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '-':
		break;
	case 'A': case 'B': case 'C':
		x = '2';
		break;
	case 'D': case 'E': case 'F':
		x = '3';
		break;
	case 'G': case 'H': case 'I':
		x = '4';
		break;
	case 'J': case 'K': case 'L':
		x = '5';
		break;
	case 'M': case 'N': case 'O':
		x = '6';
		break;
	case 'P': case 'Q': case 'R': case 'S':
		x = '7';
		break;
	case 'T': case 'U': case 'V':
		x = '8';
		break;
	case 'W': case 'X': case 'Y': case 'Z':
		x = '9';
		break;
	default:
		valid = -1;
		break;
	}
	return valid;
}

void AcknowledgeCall(char phone[8], int resultCode)
{
	switch (resultCode)
	{
	case -1:
		cout << "ERROR - An invalid character was entered" << endl;
		break;
	case -2:
		cout << "ERROR - Phone number cannot begin with 0" << endl;
		break;
	case -3:
		cout << "ERROR - Phone number cannot begin with 555" << endl;
		break;
	case -4:
		cout << "ERROR - Hyphen is not in the correct position" << endl;
		break;
	default:
		cout << endl << "Phone Number Dialed: " << phone[0] << phone[1] << phone[2] << phone[3] << phone[4] << phone[5] << phone[6] << phone[7] << endl;
		break;
	}
}