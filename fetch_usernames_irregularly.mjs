// Create username dictionary (irregularly)
// Command: node ../fetch_usernames_irregularly.mjs
// You must PLACE this OUT OF the 'codes' directory and CALL this IN the 'codes' directory!
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
fs.writeFileSync('../usernames.txt', '');
let names = await f(1);
let index = 1;
while (names != '')
{
    fs.appendFileSync('../usernames.txt', `${names}\n`);
    index = index + 1;
    names = await f(index);
    if (index % 75 === 0) await new Promise(resolve => setTimeout(resolve, 5000));
}
fs.appendFileSync('../usernames.txt', `\n`);
let now = new Date();
fs.appendFileSync('../usernames.txt', `// Updated at: ${now.toString()}\n`);
index = index - 1;
console.log(`OK! ${index} registered users detected.`);
