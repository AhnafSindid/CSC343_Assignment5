#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 5;

void FCFS(int burstTime[]) {
    int waiting_time[N];
    int turnAround_time[N];
    waiting_time[0] = 0;
    turnAround_time[0] = burstTime[0];
    for (int i = 1; i < N; i++) {
        waiting_time[i] = waiting_time[i - 1] + burstTime[i-1];
        turnAround_time[i] = waiting_time[i] + burstTime[i];
    }
    double total_waiting_time = 0;
    double total_turn_around_time = 0;

    cout << "----------------FCFS----------------\n";
    cout << left << setw(12) << "Process ID" << setw(15)<<"  Waiting Time" << setw(17) <<" Turnaround Time" << "\n";
    for (int i = 0; i < N; i++) {
        cout << left << setw(18) <<("P" + to_string(i+1))<< setw(15) << waiting_time[i] << setw(30) << turnAround_time[i] << "\n";
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turnAround_time[i];
    }
    cout<< "Average waiting time: " << total_waiting_time / N << "\n";
    cout<< "Average turnaround time: " << total_turn_around_time / N << "\n\n";
}
void SJF(int burstTime[]) {
    int index[N];
    for (int i = 0; i < N; i++)
        index[i] = i;

    sort(index, index + N, [&](int i, int j) {
        return burstTime[i] < burstTime[j];
    });
    int waiting_time[N];
    int turnAround_time[N];
    turnAround_time[index[0]] = burstTime[index[0]];
    for (int i = 1; i < N; i++) {
        waiting_time[index[i]] = waiting_time[index[i - 1]] + burstTime[index[i-1]];
    }
    double total_waiting_time = 0;
    double total_turn_around_time = 0;
    cout << "----------------SJF----------------\n";
    cout << left << setw(12) << "Process ID" << setw(15)<<"  Waiting Time" << setw(17) <<" Turnaround Time" << "\n";
    for (int i = 0; i < N; i++) {
        cout << left << setw(18) <<("P" + to_string(i+1))<< setw(15) << waiting_time[i] << setw(30) << turnAround_time[i] << "\n";

        total_waiting_time += waiting_time[i];
        total_turn_around_time += turnAround_time[i];
    }
    cout<< "Average waiting time: " << total_waiting_time / N << "\n";
    cout<< "Average turnaround time: " << total_turn_around_time / N << "\n";

}

int main() {
int burstTime[N] ={2,1,8,4,5};
    FCFS(burstTime);
    SJF(burstTime);
    return 0;
}