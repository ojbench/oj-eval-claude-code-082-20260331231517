#include <iostream>
#include "LinkedHashMap.hpp"

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if(cmd == "create") {
            int len;
            bool forEachByTime;
            cin >> len >> forEachByTime;
            LinkedHashMap* map = new LinkedHashMap(len, forEachByTime);

            int ops;
            cin >> ops;

            for(int j = 0; j < ops; j++) {
                string op;
                cin >> op;

                if(op == "insert") {
                    int key;
                    string value;
                    cin >> key >> value;
                    map->insert(key, value);
                } else if(op == "remove") {
                    int key;
                    string value;
                    cin >> key >> value;
                    map->remove(key, value);
                } else if(op == "ask") {
                    int key;
                    cin >> key;
                    vector<string> result = map->ask(key);
                    cout << result.size();
                    for(const string& s : result) {
                        cout << " " << s;
                    }
                    cout << endl;
                } else if(op == "forEach") {
                    vector<Data> result = map->forEach();
                    cout << result.size();
                    for(const Data& d : result) {
                        cout << " " << d.key << " " << d.value;
                    }
                    cout << endl;
                }
            }

            delete map;
        }
    }

    return 0;
}
