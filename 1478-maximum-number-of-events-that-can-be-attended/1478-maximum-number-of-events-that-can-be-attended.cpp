class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = events.size();
        int res = 0, i = 0, day = 0;

        while(i < n || !minHeap.empty()) {

            if(minHeap.empty()) {
                day = events[i][0]; 
            }

            while(i<n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }

            while(!minHeap.empty() && minHeap.top() < day) { // have more number of events on a single day
                minHeap.pop();
            }

            if(!minHeap.empty()) {
                minHeap.pop();
                res++;
            }

            day++;
        }

        return res;
    }
};


// always attend the event that ends the earliest among all available events on the current day
// Events with earlier end dates have a shorter window of opportunity, so they should be attended 
// first to avoid missing them.
// Sort the events based on their start day.

// Use a min-heap (priority queue) to keep track of the end days of all events that are available to attend on the current day.

// Iterate over each day from the earliest start day to the latest end day:

// Add all events starting on this day to the heap.

// Remove events from the heap that have already ended.

// If the heap is not empty:

// Attend the event that ends the earliest (pop from heap).

// Increment count.