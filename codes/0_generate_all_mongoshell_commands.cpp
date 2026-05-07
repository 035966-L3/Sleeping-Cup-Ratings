// Step 0: Convert rating records into MongoShell commands (Optional)
// Command:
// for %i in (../user/*) do 0_generate_all_mongoshell_commands.exe ../user/%i (Windows)
// for i in ../user/*; do ./0_generate_all_mongoshell_commands ../user/$i; done (Linux)
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	freopen(argv[1], "r", stdin);
	freopen("update.txt", "ab", stdout);
	argv[1][strlen(argv[1]) - 4] = '\0';
	string s;
	getline(cin, s);
	string t = s + "\n", u = s;
	while (getline(cin, s)) t = t + s + "\n";
	stringstream ss;
	ss << t;
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"level\": 0 } } );\n", argv[1] + 8);
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rp\": %s } } );\n", argv[1] + 8, u.c_str());
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.problem\": 0 } } );\n", argv[1] + 8);
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.contest\": %s } } );\n", argv[1] + 8, u.c_str());
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.delta\": `%s` } } );\n", argv[1] + 8, t.c_str());
	int o = 0, p = 0, q = 0, r = 0, e1, e2, e3, e4, e5, e6;
	ss >> p;
	q = p;
	while (ss >> e1 >> e2 >> e3 >> e4 >> e5 >> e6)
	{
		if (e1 == -1) break;
		o = max(o, e1);
		q = max(q, e6);
		r++;
	}
	if (r <= 15) p += p / ((1 << r) - 1);
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.maxRp\": %d } } );\n", argv[1] + 8, q);
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.participation\": %d } } );\n", argv[1] + 8, r);
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.quality\": %d } } );\n", argv[1] + 8, p);
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.lastParticipation\": %d } } );\n", argv[1] + 8, o);
	return 0;
}
