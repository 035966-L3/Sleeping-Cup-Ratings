// Step 3: Calculate performances
// Command: 3_calculate_performances [SPECIAL_RULES_"YES"/"NO"]
#include <bits/stdc++.h>
using namespace std;
struct Participant
{
    int uid;
    int place;
    int S;
    int T;
    int P;
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
    Participant cur = (Participant) {0, 0, 0, 0, 0};
    records.push_back(cur);
    int cid;
    f1 >> cid;
    int count = 0;
    while (f1 >> cur.place >> cur.uid)
    {
        if (cur.place == -1) break;
        count++;
        records.push_back(cur);
        if (arg == "NO")
        {
            stringstream temp;
            temp << "../user/" << cur.uid << ".txt\n";
            string archive;
            temp >> archive;
            ifstream f3(archive.c_str());
            int rating = 0;
            if (f3) f3 >> rating;
            sort_agent.push(rating);
            f3.close();
        }
    }
    f1.close();
    if (arg == "YES")
    {
        for (int i = 1; i <= count; i++)
            records[i].S = 1000 * (count + 1 - records[i].place) / count;
    }
    if (arg == "NO")
    {
        for (int i = 1; i <= count; i++)
        {
            records[i].S = sort_agent.top();
            sort_agent.pop();
            int delta = records[i].place - records[i - 1].place;
            if (delta == 0) records[i].S = records[i - 1].S;
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