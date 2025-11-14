// Step 2: Calculate performances
// Command: 2_calculate_performances [SPECIAL_RULES_"YES"/"NO"]
#include <bits/stdc++.h>
using namespace std;
struct Participant
{
	int uid;
	int place;
	int S;
	int T;
	int P;
	bool is_new;
};
int main(int argc, char** argv)
{
	int arglen = strlen(argv[1]);
	string arg = "";
	for (int i = 0; i <= arglen - 1; i++)
		arg += argv[1][i];
	ifstream f1("standings.txt");
	vector<Participant> records;
	priority_queue<int> sort_agent;
	sort_agent.push(0);
	Participant cur = (Participant) {0, 0, 0, 0, 0, true};
	records.push_back(cur);
	int cid;
	f1 >> cid;
	int count = 0;
	while (f1 >> cur.place >> cur.uid)
	{
		if (cur.place == -1) break;
		count++;
		if (arg == "NO")
		{
			cur.is_new = true;
			stringstream temp;
			temp << "../user/" << cur.uid << ".txt\n";
			string archive;
			temp >> archive;
			ifstream f3(archive.c_str());
			int rating = 0;
			int quality = 0;
			int contests = -1;
			if (f3)
			{
				if (f3 >> rating)
				{
					cur.is_new = false;
					while (getline(f3, archive))
					{
						if (archive[0] == '-') break;
						contests++;
					}
					if (contests <= 15) quality = rating * (1 << contests) / ((1 << contests) - 1);
					else quality = rating;
				}
			}
			sort_agent.push(quality);
			f3.close();
		}
		records.push_back(cur);
	}
	f1.close();
	if (arg == "YES")
	{
		for (int i = 1; i <= count; i++)
			records[i].S = 1000 * (count + 1 - records[i].place) / count;
	}
	if (arg == "NO")
	{
		int last_S = sort_agent.top();
		for (int i = 1; i <= count; i++)
		{
			int now = 1;
			while (i < count && records[i + 1].place == records[i].place)
			{
				now++;
				i++;
			}
			for (int j = i - now + 1; j <= i; j++)
				if (!records[j].is_new) last_S = sort_agent.top();
			for (int j = i - now + 1; j <= i; j++)
			{
				if (!records[j].is_new) records[j].S = sort_agent.top();
				else records[j].S = last_S;
			}
			for (int j = i - now + 1; j <= i; j++)
				if (!records[j].is_new) sort_agent.pop();
		}
	}
	ofstream f2("performances.txt", ios::out | ios::binary);
	f2 << arg << '\n';
	f2 << cid << '\n';
	printf("[Contest #%d, Special Rules: %s]\n", cid, arg.c_str());
	for (int i = 1; i <= count; i++)
	{
		f2 << records[i].place << ' ' << records[i].uid << ' ';
		printf("Rank %d (UID = %d): ", records[i].place, records[i].uid);
		long double ratio = log(records[i].place) / log(count + 1);
		records[i].T = floor((records[1].S + 200) * (1 - ratio));
		records[i].P = (records[i].S + records[i].T) / 2;
		f2 << records[i].P << '\n';
		printf("Performance is %d\n", records[i].P);
	}
	f2.close();
	return 0;
}
