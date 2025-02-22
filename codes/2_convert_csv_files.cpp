// Step 2: Dispose original CSV leaderboard
// Command: 2_convert_csv_files [CONTEST_NAME] [CSV_FILENAME]
#include <bits/stdc++.h>
using namespace std;
pair<int, string> dispose(string cur)
{
    int place = 0;
    int pos = 0;
    while (cur[pos] != ',')
    {
        place = place * 10 + cur[pos] - '0';
        pos++;
    }
    pos++;
    string username = "";
    while (cur[pos] != ',')
    {
        username += cur[pos];
        pos++;
    }
    return make_pair(place, username);
}
int main(int argc, char** argv)
{
    ifstream f1("list.txt");
    string cur;
    string lists = "";
    int cid = 1;
    while (getline(f1, cur))
    {
        if (cur == "!") break;
        lists += cur + '\n';
        cid++;
    }
    lists += argv[1];
    f1.close();
    ofstream f2("list.txt");
    f2 << lists << "\n!\n";
    f2.close();
    map<string, int> dict;
    ifstream f3("usernames.txt");
    int uid = 1;
    while (getline(f3, cur))
    {
        if (cur == "!") break;
        dict[cur] = uid;
        uid++;
    }
    f3.close();
    ifstream f4(argv[2]);
    ofstream f5("standings.txt");
    getline(f4, cur);
    f5 << cid << '\n';
    int count = 0;
    while (getline(f4, cur))
    {
        pair<int, string> info = dispose(cur);
        if (info.first == 0) continue;
        f5 << info.first << ' ' << dict[info.second] << '\n';
        count++;
    }
    f5 << "-1 -1\n";
    f4.close();
    f5.close();
    printf("OK! This is contest #%d. %d rated participants detected.", cid, count);
    return 0;
}
