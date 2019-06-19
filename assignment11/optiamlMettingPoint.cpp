#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstdlib>
#define N 9

using namespace std;

//simply from calulate the shortest distance once should go from p to one city and shortest distance one should cover to go in same city. 
//calculate their difference and then, store it in ds. Whose difference is the minimum is our answer. 
//returns the vertex with   
int shortestDistance(int distance[], bool pathSet[]){
    int min = INT_MAX;
    int index;

    for(int i = 0; i < N; i++){
        if(pathSet[i] == false && distance[i] <=min){
            min = distance[i];
            index = i;
        }
    }
    return index;
}

//dijkastra algorithm 
void dijkastra(int Cities[N][N], int *dist,bool *sptSet ,int City){
    //initilazing all of the distances and bool value for sptSet
    for(int i = 0; i < N; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[City] = 0;

    //Find the shortest path for all vertices
    for(int count = 0; count < N -1; count++){
            int u = shortestDistance(dist, sptSet);
            sptSet[u] = true;

            //update the distance weight of the  adjacent vertices  of the picked vertex
            for(int i = 0; i < N; i++){
                if(!sptSet[i] && Cities[u][i] && dist[u] != INT_MAX && dist[u] + Cities[u][i] < dist[i]){
                    dist[i] = dist[u]+ Cities[u][i];
                }
            }
    }
}

struct Choiche{
    int sd1, sd2, city;
};

int choice(int *distance1, int *distance2, int yourCity, int friendCity){
    Choiche arr[N];
    for(int i = 0; i < N ; i++){
        arr[i].city = i;
        arr[i].sd1 = distance1[i];
        arr[i].sd2 = distance2[i];
    }

    int newArray[N];
    
    for(int i = 0; i < N; i++){
        int temp = max(arr[i].sd1, arr[i].sd2);
        newArray[i] = temp;
    }
    for(int i = 0; i < N; i++){
        cout << newArray[i] << endl;
    }

    //finding the minimum element of in the array
    int min = newArray[0];
    int index;
    for(int i = 1; i < N; i++){
        if(newArray[i] < min){
            min = newArray[i];
            index = i;
        }
    }
    return index;
}

void findMeetUpCity(int adj_matrix[N][N], int yourCity, int friendCity){
    int *sdisto = new int[N];
    int *sdistf = new int[N];

    bool *sptSet1 = new bool[N];
    bool *sptSet2 = new bool[N];

    dijkastra(adj_matrix, sdisto, sptSet1 ,yourCity );
    dijkastra(adj_matrix, sdistf, sptSet2,friendCity );
    
    //we have now shortet distance of all cites from yourCity and friendCity
    //now exculude your city and friend city and minimum similar value will be the optimal choice
    int meetUpCity = choice(sdisto, sdistf, yourCity,friendCity); 
    cout << "So, the meet up city can be said to be " << meetUpCity << endl;
}

int main(){
    int Cities[N][N] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     };
    int yourCity = 0;
    int friendCity = 8;

    findMeetUpCity(Cities, yourCity, friendCity);
    return 0;
}