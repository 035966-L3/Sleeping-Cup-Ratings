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
    fs.appendFileSync('usernames.txt', `${index} ${names}\n`);
    index = index + 1;
    names = await f(index);
}
fs.appendFileSync('usernames.txt', `${index} [NO_MORE_USERS!]\n`);
index = index - 1;
console.log('');
console.log(`OK! ${index} users detected!`);
