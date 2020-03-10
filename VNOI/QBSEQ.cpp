//Dãy con dài nhất có tổng chia hết cho K, không cần liên tục
//Xem ví dụ trong sách thầy hoàng
#include<iostream>
#include<fstream>
#include<vector>
#define INF 1000000;
using namespace std;
int main(){
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    } 
    int n, k;
    int sum = 0;
    fi >> n >> k;
    vector<int> arr(n + 1, 0);
    vector<vector<int>> DP(n + 1,vector<int>(k + 1,0));
    for(int i = 1;i <= n;i++){
        int temp;
        fi >> temp;
        arr[i] = temp;
        sum = (sum + arr[i]) % k;
    }
    for(int i = 1;i <= k;i++){
        DP[0][i] = INF;
    }
    for(int i = 1;i <= n;i++){
        for(int t = 0;t <= k;t++){
            DP[i][t] = min(DP[i - 1][t], DP[i - 1][((t - arr[i]) % k + k) % k] + 1);
        }
    }
    cout << n - DP[n][sum % k];
    return 0;
}