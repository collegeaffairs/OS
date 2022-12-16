
// Implementation of SJF scheduling

#include <iostream>
#include <conio.h>
using namespace std;

#define PId 0       //column 0 store PId
#define AvT 1       //column 1 store Arrival Time
#define BT 2        //column 2 store Burst Time
#define CT 3        //column 3 store Completion Time
#define WT 4        //column 4 store Waiting Time
#define TaT 5       //column 5 store Turnaround Time

//Program to print detail of processes in matrix 
void printPDetailTable(int mat[][6], int totalProcesses,  int uptoColumn=6)
{
    for (int i = 0; i < totalProcesses; i++)
    {
        cout<<"| P";
        for (int j = 0; j < uptoColumn; j++)
        {
            if(j==0)
            {
                cout<<mat[i][j]<<"\t\t|";
            }
            else
            {
                cout<<"|\t"<<mat[i][j]<<"\t|";
            }
            
        }
		cout<<endl;
	}
}

//Function to take input of details of processes
void getJobDetails(int mat[][6], int totalProcesses)
{
    cout<<endl<< "------------------------------------------------------------------------";
    cout<<endl<< "...Enter the process Details..."<<endl<<endl;
	for (int i = 0; i < totalProcesses; i++)
    {
		cout << "...For Process " << i + 1 << "..."<<endl;
		cout << "Enter Process Id: ";
		cin >> mat[i][PId];
		cout << "Enter Arrival Time: ";
		cin >> mat[i][AvT];
		cout << "Enter Burst Time: ";
		cin >> mat[i][BT];
	}
    cout<<endl<< "------------------------------------------------------------------------";
}

//function to swap value of two given variables
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Function to sort Matrix according to Process ID number
void sortMat(int mat[][6], int totalProcesses)
{
    for(int i=0;i<totalProcesses;i++)
	{		
		for(int j=i+1;j<totalProcesses;j++)
		{
			if(mat[i][PId]>mat[j][PId])
            {
                for(int k=0;k<6;k++)
                {
                    swap(mat[i][k],mat[j][k]);
                }
            }
        }
	}
}

//Function to arrange arrangeArrival time in ascending order
void arrangeArrival(int mat[][6], int totalProcesses)
{
	for (int i = 0; i < totalProcesses; i++)
	{
		for (int j = 0; j < totalProcesses - i - 1; j++)
		{
			if (mat[j][AvT] > mat[j + 1][AvT])
			{
				for (int k = 0; k < 5; k++)
				{
					swap(mat[j][k], mat[j + 1][k]);
				}
			}
			if(mat[j][AvT] == mat[j + 1][AvT])
			{
				if (mat[j][BT] > mat[j + 1][BT])
				{
					for (int k = 0; k < 5; k++)
					{
						swap(mat[j][k], mat[j + 1][k]);
					}
				}
			}
			
		}
	}
}

//Function to calculate average Waiting Time
float avgWaitingTime(int mat[][6], int totalProcesses)
{
    int sum = 0;
    for (int i = 0; i < totalProcesses; i++)
    {
        sum+=mat[i][WT];
    }
    return ((float)sum/(float)totalProcesses);
}

//Function to calculate average Turn Around Time
float avgTurnAroundTime(int mat[][6], int totalProcesses)
{
    int sum = 0;
    for (int i = 0; i < totalProcesses; i++)
    {
        sum+=mat[i][TaT];
    }
    return ((float)sum/(float)totalProcesses);
}

//Function to calculate Completion, Waiting and TurnAround Time
void calculate_time(int mat[][6], int totalProcesses)
{
	int temp, val;
    //As process at mar[0][0] has shortest burst time, so it will get cpu first
    //So, Completion time = Arrival time + Burst time
	mat[0][CT] = mat[0][AvT] + mat[0][BT];
    //Turnaround Time = Completion - Arrival time
	mat[0][TaT] = mat[0][CT] - mat[0][AvT];
    //Waiting time = Turnaround time - Burst time
	mat[0][WT] = mat[0][TaT] - mat[0][BT];

	for (int i = 1; i < totalProcesses; i++) {
		temp = mat[i - 1][CT];	//Completion time of process
		int low = mat[i][BT];	//Burst time of process1
		for (int j = i; j < totalProcesses; j++) {
			if (temp >= mat[j][AvT] && low >= mat[j][BT]) {
				low = mat[j][BT];
				val = j;
			}
		}

		mat[val][CT] = temp + mat[val][BT];
		mat[val][TaT] = mat[val][CT] - mat[val][AvT];
		mat[val][WT] = mat[val][TaT] - mat[val][BT];
		for (int k = 0; k < 6; k++) {
			swap(mat[val][k], mat[i][k]);
		}
	}
}

//Main function for execution of Program
int main()
{
	int totalProcesses;
	cout<<endl<<">> Enter Total Number of Processes: "<<endl<<">> ";
    cin>>totalProcesses;

    int mat[totalProcesses][6] = {0};
    getJobDetails(mat, totalProcesses);

	arrangeArrival(mat, totalProcesses);
	calculate_time(mat, totalProcesses);
	sortMat(mat, totalProcesses);

    cout<<endl<< "----------------------------------------------------------------------------------------------------";
	cout<<endl<< ">> After Calculation, Final Result...";
    cout<<endl<< "----------------------------------------------------------------------------------------------------"<<endl;
	cout<<"   Process ID\t   Arrival Time\t    Burst Time\t  Completion Time\t\b\b\b\b\bWaiting Time\t\b\b\b\b\b\bTurnaround Time"<<endl;
	printPDetailTable(mat, totalProcesses, 6);

    cout<<endl<<endl<<"Average Waiting Time = "<<avgWaitingTime(mat, totalProcesses);
    cout<<endl<<"Average Turn Around Time = "<<avgTurnAroundTime(mat, totalProcesses);
	getch();
    return 0;
}
