// Step 4: Calculate ratings and generate contest reports
// Command: 4_update_ratings_and_reports
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream f1("performances.txt");
    string arg;
    int uid;
    int cid;
    int place;
    int perf;
    f1 >> arg >> cid;
    stringstream temp_contest;
    temp_contest << "../contest/" << cid << ".txt\n";
    string contest_path;
    temp_contest >> contest_path;
    ofstream f2(contest_path.c_str(), ios::out | ios::binary);
    f2 << arg << '\n';
    printf("[Contest #%d, Special Rules: %s]\n", cid, arg.c_str());
    while (f1 >> place >> uid >> perf)
    {
        printf("Rank %d (UID = %d, Performance = %d): ", place, uid, perf);
        priority_queue<int> sort_agent;
        stringstream temp;
        temp << "../user/" << uid << ".txt\n";
        string archive;
        temp >> archive;
        ifstream f3(archive.c_str());
        if (!f3)
        {
            f3.close();
            int R = perf / 2;
            ofstream f4(archive.c_str(), ios::out | ios::binary);
            f4 << R << '\n';
            f4 << cid << ' ' << place << ' ' << perf;
            f4 << " 0 " << R << ' ' << R << '\n';
            f4 << "-1 -1 -1 -1 -1 -1\n";
            f2 << place << ' ' << uid << ' ' << perf << " 0 ";
            f2 << R << ' ' << R << '\n';
            if (R > 0) putchar('+');
            printf("%d (0 -> %d)\n", R, R);
            f4.close();
            continue;
        }
        int data[7] = {0, 0, 0, 0, 0, 0, 0};
        int old_rating;
        f3 >> old_rating;
        int count = 1;
        vector<int> W(1, 0);
        vector<int> X(1, 0);
        W.push_back(perf);
        X.push_back(perf);
        sort_agent.push(perf);
        while (f3)
        {
            for (int i = 1; i <= 6; i++)
                f3 >> data[i];
            if (data[3] == -1) break;
            count++;
            W.push_back(data[3]);
            X.push_back(data[3] - 100 * (count - 1));
            sort_agent.push(X[count]);
        }
        f3.close();
        vector<int> Y(count + 1, 0);
        for (int i = 1; i <= count; i++)
        {
            Y[i] = sort_agent.top();
            sort_agent.pop();
        }
        vector<int> Z(count + 1, 0);
        for (int i = 1; i <= count; i++)
            Z[i] = Y[i] + 100 * (i - 1);
        int R = 0;
        for (int i = count; i >= 1; i--)
            R = (R + Z[i]) / 2;
        int delta = R - old_rating;
        ifstream f5(archive.c_str());
        string lines;
        string history = "";
        getline(f5, lines);
        while (getline(f5, lines))
        {
            history += lines;
            history += '\n';
        }
        f5.close();
        ofstream f6(archive.c_str(), ios::out | ios::binary);
        f6 << R << '\n';
        f6 << cid << ' ' << place << ' ' << perf << ' ';
        f6 << old_rating << ' ' << delta << ' ' << R << '\n';
        f6 << history;
        f2 << place << ' ' << uid << ' ' << perf << ' ';
        f2 << old_rating << ' ' << delta << ' ' << R << '\n';
        if (delta > 0) putchar('+');
        if (delta < 0) putchar('-');
        printf("%d (%d -> %d)\n", abs(delta), old_rating, R);
        f6.close();
    }
    f2 << "-1 -1 -1 -1 -1 -1\n";
    f1.close();
    f2.close();
    return 0;
}