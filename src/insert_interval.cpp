#include <vector>

using namespace std;

/*

*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

cluass Solution {

private:
	/*
		return the position that should be change
	*/
	int search(const vector<Interval> &intervals, const int key)
	{
		int i = 0;
		int j = intervals.size() - 1;

		int position = 0;

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
 		int position = search(intervals, newInterval.start);

		if (newInterval.start <= intervals[position].end) {
			intervals[position].end = newInterval.end;
		}
		else {
			intervals.insert(intervals.begin() + position + 1, newInterval);
			position++;
		}

		if (1)

		return intervals;
	}
};
