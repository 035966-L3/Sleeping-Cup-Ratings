// Step 4: Update rating leaderboards and generate TOP_RATED.md
// Command: 4_roll_ranks_and_leaderboards
#include <bits/stdc++.h>
using namespace std;
const char* colors[8] =
{
	"808080", // Gray, 0 - 99
	"804000", // Brown, 100 - 199
	"008000", // Green, 200 - 299
	"00c0c0", // Cyan, 300 - 399
	"0000ff", // Blue, 400 - 499
	"c0c000", // Yellow, 500 - 599
	"ff8000", // Orange, 600 - 699
	"ff0000"  // Red, 700 - inf
};
struct User
{
	int uid;
	int rating;
};
bool operator<(User x, User y)
{
	if (x.rating != y.rating) return x.rating < y.rating;
	return x.uid < y.uid;
}
int main()
{
	ifstream f1("standings.txt");
	int cid;
	f1 >> cid;
	f1.close();
	stringstream temp_contest;
	temp_contest << "../contest/" << cid << ".txt\n";
	string contest_path;
	temp_contest >> contest_path;
	ifstream f2(contest_path.c_str());
	int data[7] = {0, 0, 0, 0, 0, 0, 0};
	map<int, int> ratings;
	string arg;
	getline(f2, arg);
	while (f2)
	{
		for (int i = 1; i <= 6; i++)
			f2 >> data[i];
		if (data[2] == -1) break;
		ratings[data[2]] = data[6];
	}
	f2.close();
	ifstream f3("../rank.txt");
	int place;
	int old_uid;
	int old_rating;
	while (f3 >> place >> old_uid >> old_rating)
	{
		if (old_uid == -1) break;
		if (!ratings.count(old_uid)) ratings[old_uid] = old_rating;
	}
	f3.close();
	priority_queue<User> sort_agent;
	for (map<int, int>::iterator i = ratings.begin(); i != ratings.end(); i++)
		sort_agent.push((User) {i -> first, i -> second});
	map<int, string> dict;
	ifstream f4("../usernames.txt");
	string cur;
	int uid_count = 1;
	while (getline(f4, cur))
	{
		if (cur == "") break;
		dict[uid_count] = cur;
		uid_count++;
	}
	f4.close();
	ofstream f5("../rank.txt", ios::out | ios::binary);
	FILE* f6 = fopen("../TOP_RATED.md", "wb");
	fputs("| Rank | Username | Rating |\n", f6);
	fputs("| -: | -: | -: |\n", f6);
	int count = 1;
	int cur_place = 1;
	int cur_rating = sort_agent.top().rating;
	sort_agent.push((User) {-1, -1});
	while (!sort_agent.empty())
	{
		int uid = sort_agent.top().uid;
		int rating = sort_agent.top().rating;
		sort_agent.pop();
		const char* username = dict[uid].c_str();
		const char* color = colors[min(rating / 100, 7)];
		fprintf(f6, "| $%d$ | ", cur_place);
		fprintf(f6, "[%s](http://8.136.99.126/user/%d)", username, uid);
		fprintf(f6, " | $\\color{#%s}%d$ |\n", color, rating);
		f5 << cur_place << ' ' << uid << ' ' << rating << '\n';
		if (sort_agent.top().uid == -1) break;
		count++;
		if (sort_agent.top().rating != cur_rating)
		{
			cur_rating = sort_agent.top().rating;
			cur_place = count;
		}
	}
	f5 << "-1 -1 -1\n";
	f5.close();
	fclose(f6);
	printf("OK! There are %d users on the leaderboard.", count);
	return 0;
}