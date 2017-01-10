//
//  main.cpp
//  leetcode52
//
//  Created by 李林 on 2017/1/10.
//  Copyright © 2017年 lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<string>cur, int row, int col){
        int count = 0;
        
        // 行（不用检查，每行只会有一个）
        
        // 列
        for(int i=0; i<=row; i++){
            if(cur[i][col] == 'Q')
                count++;
            if(count > 1)  return false;
        }
    
        // 左对角线
        count = 0;
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(cur[i][j] == 'Q')
                count++;
            if(count > 1)   return false;
        }
        
        // 右对角线
        count = 0;
        for(int i=row, j=col; i>=0 && j<cur[0].size(); i--, j++){
            if(cur[i][j] == 'Q')
                count++;
            if(count > 1)   return  false;
        }
        
        return true;
    }
    
    void DFS(int n, int row, vector<string>temp){
        if(n == row){
            result.push_back(temp);
            return ;
        }else{
            for(int i=0; i<n; i++){         // 遍历一个row中每个元素，深搜。
                string str(n, '.');
                str[i] = 'Q';
                temp.push_back(str);
                
                if(isValid(temp, row, i))
                    DFS(n, row+1, temp);
                
                temp.pop_back();
            }
        }
    }
    
    int totalNQueens(int n) {
        if(n == 0)  return 0;
        
        vector<string> temp;
        DFS(n, 0, temp);
        
        return result.size();
    }
private:
    vector<vector<string>> result;
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    int result = s.totalNQueens(4);
    printf("%d\n", result);
    
    return 0;
}
