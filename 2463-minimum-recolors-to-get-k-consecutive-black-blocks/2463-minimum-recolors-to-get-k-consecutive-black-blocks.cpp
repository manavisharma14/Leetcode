class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whitecount = 0;

        for(int i=0; i<k; i++){
            if(blocks[i] == 'W'){
                whitecount++;
            }
        }

        int minwhite = whitecount;

        for(int i=k; i<blocks.size(); i++){
            if(blocks[i-k] == 'W') whitecount--;
            if(blocks[i] == 'W') whitecount++;

            
            minwhite = min(minwhite, whitecount);      
        }
        return minwhite;
    }
};
