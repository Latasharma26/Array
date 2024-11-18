class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size(), 0);
        
        if (k > 0) {
            for (int i = 0; i < code.size(); ++i) {
                int sum = 0;

                for (int j = i + 1; j <= i + k; ++j) {
                    sum += code[j % code.size()];    
                }
                res[i] = sum;
            }
        }
        else if (k < 0) {
            for (int i = 0; i < code.size(); ++i) {
                int sum = 0;
                int size = code.size();

                for (int j = i - 1; j >= i + k; --j) {
                    int temp = j % size;
                                        
                    temp = temp < 0 ? size + temp : temp;
                    
                    sum += code[temp];    
                }
                res[i] = sum;
            }            
        }
        return res;
    }
};