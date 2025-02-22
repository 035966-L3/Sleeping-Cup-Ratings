// Step 4: Calculate ratings and generate contest reports
// Command: 4_update_ratings_and_reports
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream f5("performances.txt");
    string arg;
    int uid;
    int cid;
    int place;
    int perf;
    f5 >> arg >> cid;
    stringstream temp_contest;
    temp_contest << "../contest/" << cid << ".txt\n";
    string contest_path;
    temp_contest >> contest_path;
    ofstream f6(contest_path.c_str(), ios::out | ios::binary);
    f6 << arg << '\n';
    printf("[Contest #%d, Special Rules: %s]\n", cid, arg.c_str());
    while (f5 >> place >> uid >> perf)
    {
        printf("Rank %d (UID = %d, Performance = %d): ", place, uid, perf);
        priority_queue<int> sort_agent;
        stringstream temp;
        temp << "../user/" << uid << ".txt\n";
        string archive;
        temp >> archive;
        ifstream f1(archive.c_str());
        if (!f1)
        {
            f1.close();
            int R = perf / 2;
            ofstream f2(archive.c_str(), ios::out | ios::binary);
            f2 << R << '\n';
            f2 << cid << ' ' << place << ' ' << perf;
            f2 << " 0 " << R << ' ' << R << '\n';
            f2 << "-1 -1 -1 -1 -1 -1\n";
            f6 << place << ' ' << uid << ' ' << perf << " 0 ";
            f6 << R << ' ' << R << '\n';
            if (R > 0) putchar('+');
            printf("%d (0 -> %d)\n", R, R);
            f2.close();
            continue;
        }
        int data[7] = {0, 0, 0, 0, 0, 0, 0};
        int old_rating;
        f1 >> old_rating;
        int count = 1;
        vector<int> W(1, 0);
        vector<int> X(1, 0);
        W.push_back(perf);
        X.push_back(perf);
        sort_agent.push(perf);
        while (f1)
        {
            for (int i = 1; i <= 6; i++)
                f1 >> data[i];
            if (data[3] == -1) break;
            count++;
            W.push_back(data[3]);
            X.push_back(data[3] - 100 * (count - 1));
            sort_agent.push(X[count]);
        }
        f1.close();
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
        ifstream f3(archive.c_str());
        string lines;
        string history = "";
        getline(f3, lines);
        while (getline(f3, lines))
        {
            history += lines;
            history += '\n';
        }
        f3.close();
        ofstream f4(archive.c_str(), ios::out | ios::binary);
        f4 << R << '\n';
        f4 << cid << ' ' << place << ' ' << perf << ' ';
        f4 << old_rating << ' ' << delta << ' ' << R << '\n';
        f4 << history;
        f6 << place << ' ' << uid << ' ' << perf << ' ';
        f6 << old_rating << ' ' << delta << ' ' << R << '\n';
        if (delta > 0) putchar('+');
        if (delta < 0) putchar('-');
        printf("%d (%d -> %d)\n", abs(delta), old_rating, R);
        f4.close();
    }
    f5.close();
    f6.close();
    return 0;
}