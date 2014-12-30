#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {

private:
	/*
		return the position that should be change
			* can not handle the key less than the first interval, just return -1 
	*/
	int search(const vector<Interval> &intervals, const int key)
	{
		int i = 0;
		int j = intervals.size() - 1;

		int position = -1;

		/* hanlde the key bigger than last interval */
		if (key > (intervals.end() - 1)->start)
			return intervals.size() - 1;

		while (i < j) {
			int middle = ((j - i) >> 1) + i;

			if (intervals[middle].start <= key &&
				middle + 1 < intervals.size() &&
				key <= intervals[middle + 1].start)
			{
				position = middle;
				break;
			}
			else if (key > intervals[middle].start)
			{
				i = middle;
			}
			else if (key < intervals[middle].start)
			{
				j = middle;
			}
		}

		return position;
	}

public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

		if (intervals.size() == 0) {
			intervals.push_back(newInterval);
			return intervals;
		}

 		int position = search(intervals, newInterval.start);

		/* replace the interval end or insert a new interval */
		vector<Interval> ret;
		if (position == -1) {
			Interval t = newInterval;
			if (t.end >= intervals[0].start)
				t.end = newInterval.end > intervals[0].end ? newInterval.end : intervals[0].end;
			ret.push_back(t);
			position = 0;
		}
		else {
			for (int i = 0; i < position; ++i)
				ret.push_back(intervals[i]);

			if (newInterval.start > intervals[position].end) {
				ret.push_back(intervals[position]);
				ret.push_back(newInterval);
			}
			else {
				if (newInterval.end > intervals[position].end) {
					intervals[position].end = newInterval.end;
				}

				ret.push_back(intervals[position]);

				
			}
		}

		/* merge intervals */
		
		for (auto it = intervals.begin() + position; it != intervals.end(); ++it) {

			if (it->start > newInterval.end)
				ret.push_back(*it);	
			else if (it->start <= newInterval.end) {
				Interval t = *ret.rbegin();
				int end = it->end > newInterval.end ? it->end : newInterval.end;
				ret.pop_back();
				ret.push_back(Interval(t.start, end));
			}
		}

		return ret;
	}
};
