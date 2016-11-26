#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void flatten(string* ride, string* row){
    for(int i = 0; i<ride->length(); i++)
        (*ride)[i] = (*row)[i] != '.' ? (*row)[i] : (*ride)[i];
}

void flip(string* ride){
    for(int i = 0; i<ride->length(); i++)
        (*ride)[i] = (*ride)[i] == '\\' ? '/' : ((*ride)[i] == '/' ? '\\' : (*ride)[i]);
}

int calc_inertia(string ride, int initial_inertia){
    int inertia = initial_inertia,
    ride_pos = 0,
    dir = 1;
    bool firstTurn = true;
    while(inertia != 0 || ride[ride_pos] != '_'){
        cerr << ride << endl << string(ride_pos, ' ') << '|' << inertia << endl;
        inertia += ride[ride_pos] == '_' ? -1 : (ride[ride_pos] == '\\' ? 9 : -10);
        if(inertia < 0){
            dir *= -1;
            flip(&ride);
            inertia *= -1;
        }
        if(inertia != 0)
            ride_pos += dir;
        if(ride_pos == ride.length()-1 || (ride_pos == 0 && !firstTurn) )
            inertia = 0;
        firstTurn = false;
    }
    return ride_pos;
}

int main()
{
    int inertia;
    cin >> inertia; cin.ignore();
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    string ride (W, '.');
    for (int i = 0; i < H; i++) {
        string row;
        getline(cin, row);
        flatten(&ride, &row);
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cerr << ride << endl << "Inertia: " << inertia << endl;
    cout << calc_inertia(ride, inertia) << endl;
}