#pragma once
#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include"clsDate.h"

using namespace std;

class clsQueueLine
{

private:

	string _previx;
	short _TimeWating;
	short _CleintServiec = 0;
	short _TimeCount = 0;
	short _CountPrivex = 1;
	short _ClientWating = 0;
	short _TotalCLient = 0;
	

	struct _TecetInfo
	{
		string dateAndTimePrint;
		short ClientServec;
		short TimeServing;
		string previx;
		short ClientWating;
	};

	queue<_TecetInfo> QueueLine;
	stack<_TecetInfo> StackLine;

	_TecetInfo _FillTheTecetWithInformation()
	{
		_TecetInfo Tecet;

		Tecet.dateAndTimePrint = clsDate::GetSystemDateTimeString();
		Tecet.ClientServec = _CleintServiec;
		Tecet.TimeServing = _TimeCount;
		Tecet.previx = _previx + to_string(_CountPrivex);
		Tecet.ClientWating = _ClientWating;

		return Tecet;
	}

	void _PrintTicket(_TecetInfo Ticket)
	{
		cout << "\n\t\t\t___________________________________\n";
		cout << "\t\t\t\t " << Ticket.previx << "\t\t\n";
		cout << "\t\t\t" << Ticket.dateAndTimePrint << "\t\t\n";
		cout << "\t\t\t Wating Client = " << Ticket.ClientWating << endl;
		cout << "\t\t\t Serve Time In " << Ticket.TimeServing << endl;
		cout << "\t\t_________________________________________\n";
	}

	void  _Swap()
	{
		_TecetInfo Temp;

		for (short i = 0; i < QueueLine.size(); i++)
		{
			Temp = QueueLine.back();
			QueueLine.back() = QueueLine.front();
			QueueLine.front() = Temp;
		}
	}

public:

	clsQueueLine(string previx, short TimeWating)
	{
		_previx = previx;
		_TimeWating = TimeWating;
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t___________________________________\n";
		cout << "\n\t\t\t             Queue Info            \n";
		cout << "\n\t\t\t___________________________________\n";

		cout << "\n\t\t\t  Pervix :" << _previx << endl;
		cout << "\n\t\t\t  Total Client :" << _TotalCLient << endl;
		cout << "\n\t\t\t  Client Servid :" << _CleintServiec << endl;
		cout << "\n\t\t\t  Wating Client :" << QueueLine.size() << endl;
	}

	void IssueTicket()
	{
		_TecetInfo Ticket = _FillTheTecetWithInformation();
		QueueLine.push(Ticket);
		StackLine.push(Ticket);
		_TimeCount += _TimeWating;
		_CountPrivex++;
		_ClientWating++;
		_TotalCLient++;
	}

	void PrintTicketsLineRTL()
	{
		_TecetInfo Top;
		cout << "\n\t\t Ticket : ";
		for (short i = 0; i < QueueLine.size(); i++)
		{
			cout << QueueLine.front().previx << " <-- ";
			Top = QueueLine.front();
			QueueLine.pop();
			QueueLine.push(Top);
		}

		cout << endl;
	}

	void PrintTicketsLineLTR()
	{
		_TecetInfo Top;
		cout << "\n\t\t Ticket : ";
		for (short i = 0; i < QueueLine.size(); i++)
		{
			cout << StackLine.top().previx << " <-- ";
			Top = StackLine.top();
			StackLine.pop();
			//StackLine.push(Top);
		}

		cout << endl;

	}

	void PrintAllTickets()
	{
		_TecetInfo Ticket;
		for (short i = 0 ; i < QueueLine.size() ; i++)
		{
			Ticket = QueueLine.front();
			_PrintTicket(Ticket);
			QueueLine.pop();
			QueueLine.push(Ticket);
		}
	}

	void ServeNextClient()
	{
		QueueLine.pop();
		_TimeCount -= _TimeWating;
		_CountPrivex--;
		_ClientWating--;
		_CleintServiec++;
	}
};

