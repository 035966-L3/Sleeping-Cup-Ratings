// Step 3: Calculate Performances
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
    ifstream f1("standings.txt");
    vector<Participant> records;
    priority_queue<int> ratings;
    Participant cur = (Participant) {0, 0, 0, 0, 0};
    records.push(cur);
    int cid;
    f1 << cid;
    f2 << cid << '\n';
    int count = 0;
    while (f1 >> cur.place >> cur.uid)
    {
        if (cur.place == -1) break;
        count++;
        records.push(cur);
        if (argv[1] == "NO")
        {
            stringstream temp;
            temp << "../user/" << cur.place << ".txt\n";
            string archive;
            temp >> archive;
            ifstream f3(archive.c_str());
            int rating = 0;
            if (f3) f3 >> rating;
            ratings.push(rating);
            f3.close();
        }
    }
    f1.close();
    if (argv[1] == "YES")
    {
        for (int i = 1; i <= count; i++)
            records[i].S = 1000 * (count + 1 - i) / count;
    }
    if (argv[1] == "NO")
    {
        for (int i = 1; i <= count; i++)
        {
            records[i].S = ratings.top();
            ratings.pop();
            int delta = records[i].place - records[i - 1].place;
            if (delta == 0) records[i].S = records[i - 1].S;
        }
    }
    ofstream f2("performances.txt");
    for (int i = 1; i <= count; i++)
    {
        f2 << records[i].place << ' ' << records[i].uid << ' ';
        long double ratio = log(records[i].place) / log(count + 1);
        records[i].T = floor((records[1].S + 200) * ratio);
        records[i].P = (records[i].S + records[i].T) / 2;
        f2 << records[i].P << '\n';
    }
    f2.close();
    return 0;
}