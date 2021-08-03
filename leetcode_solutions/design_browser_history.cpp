#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
public:
    string history[5001];
    int curr = 0;
    int end = 0;
    
    BrowserHistory(string homepage) {
        history[curr] = homepage;
    }
    
    void visit(string url) {
        curr++;
        history[curr] = url;
        end = curr;
    }
    
    string back(int steps) {
        if (curr-steps <= 0){
            curr = 0;
            return history[curr];
        }
        else {
            curr -= steps;
            return history[curr]; 
        }
        
    }
    
    string forward(int steps) {
        if (curr + steps >= end){
            curr = end;
            return history[end];
        }
        else {
            curr += steps;
            return history[curr]; 
        }
        
    }
};
