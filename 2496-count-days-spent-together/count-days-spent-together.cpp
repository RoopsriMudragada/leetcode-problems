class Solution {
public:
    int findDays(string date, vector<int>&cummDays){
        auto month = stoi(date.substr(0, 2));
        auto days = stoi(date.substr(3));

        return cummDays[month - 1] + days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int>cummDays(13, 0);
        cummDays[1] = 31;
        for(int i = 2; i <= 12; i++){
            cummDays[i] = cummDays[i - 1] + monthDays[i - 1];
        }

//Alice
        auto arriveAliceDays = findDays(arriveAlice, cummDays);
        auto leaveAliceDays = findDays(leaveAlice, cummDays);
        
//Bob
        auto arriveBobDays = findDays(arriveBob, cummDays);
        auto leaveBobDays = findDays(leaveBob, cummDays);

//Total SpentDays
        auto overlapDays = min(leaveAliceDays, leaveBobDays) - max(arriveAliceDays, arriveBobDays) + 1;

        return overlapDays < 0 ? 0 : overlapDays;
    }
};