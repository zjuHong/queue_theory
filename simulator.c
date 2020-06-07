#include <bits/stdc++.h>
using namespace std;

default_random_engine seed((unsigned)time(0));
double max_find(double a, double b) //This utility function is used to find the maximum of two doubles.
{
	if (a > b)
		return a;
	else
		return b;
}

double poisson_distributed_random_variables(double mean) //This Function is used to generate
{														 //poisson distributed random varibles.

	poisson_distribution<long unsigned int> random(mean);
	double temp = random(seed);
	//cout<<temp<<endl;
	return temp;
}

double exponentially_distributed_random_variables(double mean) //This function is used to generate
{															   //exponentially distributed random varibles.
	double temp, temp1;
	do
	{
		temp = ((double)rand() / (RAND_MAX));
	} while (temp == 0 || temp == 1);
	temp1 = (-log(temp) * mean);
	//cout<<temp1<<endl;
	return temp1;
}

void case_B(double arrival_rate, double service_rate, float hour) //This function is used to implement the case B of the problem.
{
	if (service_rate < arrival_rate) //Arrival rate must be greater than service rate to be in steady state
	{
		cout << "Arrival rate must be greater than service rate to be in stable state\n ";
		return;
	}

	double n = hour;
	double inspected = 0, arrival[3] = {0};
	srand((unsigned)time(0));
	queue<pair<double, double>> q1;
	double finish_time = 0, wait_time = 0, ser_time = 0, no_waiting = 0;
	vector<double> map1;
	for (long int i = 1; i <= n; i++)
	{
		double at = poisson_distributed_random_variables(3600 / arrival_rate);		 //poisson distributed arrival time
		double st = exponentially_distributed_random_variables(3600 / service_rate); //exponentially distributed service time
		at = at + arrival[0];
		q1.push(make_pair(at, st));
		map1.push_back(at);
		arrival[0] = at;
	}
	cout << "\nplease wait ........\n";
	int j = 0;
	while (true)
	{
		if (q1.empty()) //if queue1 is not empty i.e. it has some passengers
		{
			break;
		}

		for (auto i = map1.begin(); i != map1.end() && *i <= finish_time; i++)
		{
			no_waiting++; //no. of passengers waiting in queue
		}

		pair<double, double> temp = q1.front();

		if (temp.first < finish_time)
			wait_time += finish_time - temp.first;

		if (q1.front().first <= finish_time)
			inspected++; //passenger got inspected from queue
		if (q1.front().first <= finish_time)
			inspected++; //passenger got inspected from queue
		if (temp.first >= finish_time)
		{
			finish_time = temp.first;
		}

		if (q1.front().first <= finish_time)
			inspected++;		  //passenger got inspected from queue
		map1.erase(map1.begin()); //see here
		ser_time += temp.second;
		finish_time += temp.second;

		q1.pop();
	}

	inspected = (inspected / (n));											//average no. of passengers getting inspected
	double avg_wt = wait_time / n; //average waiting time for all passengers
	double avg_st = ser_time / n;	//average service time for all officers
	double avg_rt = avg_wt + avg_st;										//average response time for all passengers
	double waiting = no_waiting / n;										//average no. of passengers waiting in queue

	cout << "Avg no of inspected passenges : " << inspected << " passenger/sec" << endl;
	cout << "Avg response time : " << avg_rt << " seconds" << endl;
	cout << "Avg Waiting time : " << avg_wt << " seconds" << endl;

	cout << "Avg no of passenger waiting :" << waiting << " passenger/sec" << endl;
}

int main()
{
	float arrival_rate = 0, service_rate = 0, h = 60000;

	// cout << "Enter arrival rate (λ in sec/passenger) : ";
	// cin >> arrival_rate; 
	// cout << "Enter service rate (µ in sec/passenger) : ";
	// cin >> service_rate; 
	arrival_rate = 0.8 * 3600;
	service_rate = 1.5 * 3600;
	case_B(arrival_rate, service_rate, h);
	printf("theory %f\n", 3600 / (service_rate - arrival_rate));
	system("pause");
	return 0;
}
