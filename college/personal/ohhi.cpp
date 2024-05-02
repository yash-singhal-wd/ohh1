#include <bits/stdc++.h>

using namespace std;

void adj_helper_each_row(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(matrix[i][j]==2) continue;
            else {
                if(j+1<n){
                    if(matrix[i][j]==matrix[i][j+1]){
                        if(j-1>=0){
                            matrix[i][j-1] = !matrix[i][j];
                        }
                        if(j+2<n){
                            matrix[i][j+2] = !matrix[i][j];
                        } 
                    }
                }
                if(j+2<n){
                    if(matrix[i][j]==matrix[i][j+2]){
                        matrix[i][j+1] = !matrix[i][j];
                    }
                }
            }
        }
    }
} 

void adj_helper_each_column(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    for(int j=0; j<n; ++j){
        for(int i=0; i<m; ++i){
            if(matrix[i][j]==2) continue;
            else {
                if(i+1<m){
                    if(matrix[i][j]==matrix[i+1][j]){
                        if(i-1>=0){
                            matrix[i-1][j] = !matrix[i][j];
                        }
                        if(i+2<m){
                            matrix[i+2][j] = !matrix[i][j];
                        }
                    }
                }
                if(i+2<m){
                    if(matrix[i][j]==matrix[i+2][j]){
                        matrix[i+1][j] = !matrix[i][j];
                    }
                }
            }
        }
    }
}

void complete_row_helper(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i=0; i<m; ++i){
        int count0 = 0;
        int count1 = 0;
        for(int j=0; j<n; ++j){
            if(matrix[i][j]==0) count0++;
            if(matrix[i][j]==1) count1++;
            if(count1==n/2){
                for(int k=0; k<n; ++k){
                    if(matrix[i][k]==2)
                        matrix[i][k] = 0;
                }
                break;
            }
            if(count0==n/2){
                for(int k=0; k<n; ++k){
                    if(matrix[i][k]==2)
                        matrix[i][k] = 1;
                }
                break;
            }
        }
    }
}

void complete_col_helper(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    for(int j=0; j<n; ++j){
        int count0 = 0;
        int count1 = 0;
        for(int i=0; i<m; ++i){
            if(matrix[i][j]==0) count0++;
            if(matrix[i][j]==1) count1++;
            if(count1==n/2){
                for(int k=0; k<n; ++k){
                    if(matrix[k][j]==2)
                        matrix[k][j] = 0;
                }
                break;
            }
            if(count0==n/2){
                for(int k=0; k<n; ++k){
                    if(matrix[k][j]==2)
                        matrix[k][j] = 1;
                }
                break;
            }
        }
    }
}

void row_similarity_checker(vector<vector<int>> &matrix){

}

void col_similarity_checker(vector<vector<int>> &matrix){
    
}

void solve_ohhi(vector<vector<int>> &matrix){
    for(int i=0; i<50; ++i){
        //check row adjacency
        adj_helper_each_row(matrix);
        
        //check column adjacency
        adj_helper_each_column(matrix);
        
        //complete row based on rule #2
        complete_row_helper(matrix);

        //complete column based on rule #2
        complete_col_helper(matrix);
    }
}

int main(){
    int n;
    cin >> n;
    cout << endl;
    vector<int> row(n,0);
    vector<vector<int>> matrix(n,row);

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> matrix[i][j];
        }
    }

    solve_ohhi(matrix);
    cout << endl;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    

    return 1;
}