class MyCalendarThree {
public:
    map<int, int> sweep;

    MyCalendarThree() {

    }

    int book(int startTime, int endTime) {
        sweep[startTime]++;
        sweep[endTime]--;

        int active = 0;
        int ans = 0;

        for (auto &[time, delta] : sweep) {
            active += delta;
            ans = max(ans, active);
        }

        return ans;
    }
};