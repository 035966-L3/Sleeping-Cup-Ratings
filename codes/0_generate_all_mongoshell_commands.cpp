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
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"level\": 0 } } );\n", argv[1] + 8);
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rp\": %s } } );\n", argv[1] + 8, u.c_str());
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.problem\": 0 } } );\n", argv[1] + 8);
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.contest\": %s } } );\n", argv[1] + 8, u.c_str());
	printf("db.domain.user.updateOne( { domainId: 'system', uid: %s }, { $set: { \"rpInfo.delta\": `%s` } } );\n", argv[1] + 8, t.c_str());
	return 0;
}
