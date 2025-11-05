// queue_sandwich_problem.cpp
// Number of students unable to eat lunch (students queue and sandwiches stack)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int> students, vector<int> sandwiches){
    queue<int> q;
    for(int s: students) q.push(s);
    int i=0, cycles=0;
    while(!q.empty() && i < sandwiches.size()){
        if(q.front()==sandwiches[i]){ q.pop(); i++; cycles=0; }
        else { int x=q.front(); q.pop(); q.push(x); cycles++; if(cycles==q.size()) break; }
    }
    return q.size();
}

int main(){
    vector<int> students={1,1,0,0}, sandwiches={0,1,0,1};
    cout<<countStudents(students, sandwiches)<<"\n";
    return 0;
}