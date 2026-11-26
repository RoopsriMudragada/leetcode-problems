class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        int aliceturn  = true;

        while(n >= remove){
            n = n - remove;
            remove--;

            aliceturn  = !aliceturn;
        }
        return !aliceturn;
    }
};