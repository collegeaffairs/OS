#include <iostream>
using namespace std;

#define MAX 10

int pId[MAX];
int pSize[MAX];
int bSize[MAX];
int abn[MAX];

//Function to input of sizes of blocks
void getBlockSize(int totalBlocks)
{
    cout<<endl<< "------------------------------------------------------------------------";
    cout<<endl<< "...Enter the Block Details..."<<endl<<endl;
    for (int i = 0; i < totalBlocks; i++)
    {
        cout<<endl<<".... For Block No.: "<<i+1;
        cout<<endl<<">> Enter Size of Block : ";
        cin>>bSize[i];
    }
    cout<<endl<< "------------------------------------------------------------------------";
}

//Function to input of sizes of process
void getProcessSize(int totalProcess)
{
    cout<<endl<< "------------------------------------------------------------------------";
    cout<<endl<< "...Enter the process Details..."<<endl<<endl;
    for(int i = 0; i<totalProcess; i++)
    {
        cout << ".... For Process "<< i+1 << " ...."<<endl;
		cout << ">> Enter Process Id: ";
		cin >> pId[i];
        cout<<">> Enter Size of Process No. "<<pId[i]<<": ";
        cin>>pSize[i];
    }
    cout<<endl<< "------------------------------------------------------------------------";
}

void copyArray(int src[], int dst[], int size)
{
    for(int i = 0; i<size; i++)
    {
        dst[i] = src[i];
    }
}

void firstFit( int totalProcess, int totalBlocks)
{
    int blockSize[totalBlocks] ={0};
    copyArray(bSize, blockSize, totalBlocks);
    for (int i = 0; i < totalProcess; i++)
    {
        for (int j = 0; j < totalBlocks; j++)
        {
            if (blockSize[j] >= pSize[i])
            {
                abn[i] = j+1;
                blockSize[j] -= pSize[i];
                break;
            }
        }
    }
}

void bestFit(int totalProcess, int totalBlocks)
{
    int blockSize[totalBlocks] ={0};
    copyArray(bSize, blockSize, totalBlocks);
    for (int i = 0; i < totalProcess; i++)
    {
        int bestBlockIndex = -1;
        for (int j = 0; j < totalBlocks; j++)
        {
            if (blockSize[j] >= pSize[i])
            {
                if (bestBlockIndex == -1)
                    bestBlockIndex = j;
                else if (blockSize[bestBlockIndex] > blockSize[j])
                    bestBlockIndex = j;
            }
        }
        if(bestBlockIndex != -1)
        {
            abn[i] = bestBlockIndex+1;
            blockSize[bestBlockIndex] -= pSize[i];
        }
    }
}

void worstFit(int totalProcess, int totalBlocks)
{
    int blockSize[totalBlocks] ={0};
    copyArray(bSize, blockSize, totalBlocks);
    for (int i = 0; i < totalProcess; i++)
    {
        int worstBlockIndex = -1;
        for (int j = 0; j < totalBlocks; j++)
        {
            if (blockSize[j] >= pSize[i])
            {
                if (worstBlockIndex == -1)
                    worstBlockIndex = j;
                else if (blockSize[worstBlockIndex] < blockSize[j])
                    worstBlockIndex = j;
            }
        }
        if(worstBlockIndex != -1)
        {
            abn[i]= worstBlockIndex+1;
            blockSize[worstBlockIndex] -= pSize[i];
        }
    }
}

void printTable(int totalProcess )
{
    cout<<endl<< "------------------------------------------------------------------------";
	cout<<endl<< ">> After Calculation, Final Result...";
    cout<<endl<< "------------------------------------------------------------------------";
	cout<<endl<<"    Process No.\t   Process Size\t    Allocated Block no."<<endl;
    
    for (int i = 0; i < totalProcess; i++)
    {
        cout<<"|\tP" << pId[i]<< "\t||\t" << pSize[i]<< "\t||\t  ";
        if (abn[i] != 0)
            cout<<abn[i]<<"\t\t|";
        else
            cout<<"\b\b\b\b-NOT Allocated-\t|";
        cout<<endl;
    }
    cout<< "------------------------------------------------------------------------"<<endl;
    
}

int main()
{
    int totalProcess, totalBlocks;
    cout<<endl<<"----> Enter total number of Processes : ";
    cin>>totalProcess;
    getProcessSize(totalProcess);

    cout<<endl<<"----> Enter total number of Blocks : ";
    cin>>totalBlocks;
    getBlockSize(totalBlocks);
    
    abn[MAX] = {0};
    cout<<endl<<"--------------------------FirstFit Algorithm----------------------------"<<endl;
    firstFit(totalProcess, totalBlocks);
    printTable(totalProcess);
    abn[MAX] = {0};
    cout<<endl<<"--------------------------BestFit Algorithm----------------------------"<<endl;
    bestFit(totalProcess, totalBlocks);
    printTable(totalProcess);
    abn[MAX] = {0};
    cout<<endl<<"--------------------------WorstFit Algorithm----------------------------"<<endl;
    worstFit(totalProcess, totalBlocks);
    printTable(totalProcess);

    return 0;
}