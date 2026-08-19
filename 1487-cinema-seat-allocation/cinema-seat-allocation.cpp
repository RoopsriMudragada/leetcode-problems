class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>>mp;
        //mapping row -> seats;
        for(auto & reserved : reservedSeats){
            int row = reserved[0];
            int seat = reserved[1];

            mp[row].insert(seat);
        }

        int result = (n - mp.size()) * 2; //Each Empty row Having 2 groups (it checking empty rows and multiplying (emptyRows*2);
        
        for(auto &[row, bookedSeats] : mp){

            auto isAvailable = [&](int seat){
            return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(groupA && groupC){
                result += 2;
            }
            else if(groupA || groupB || groupC){
                result += 1;
            }
            else{
                result += 0;
            }
        }
        return result;
    }
};