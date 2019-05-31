#include<bits/stdc++.h>

using namespace std;

vector<pair<bool, pair<string, long> > > disk; // disponível? [ nome, tamanho ]
long blocksize;

vector<pair<bool, pair<string, long> > >::iterator seek_space(long min);

vector<pair<bool, pair<string, long> > >::iterator seek_name(string file);

bool insert(string file, long size);

bool remove(string file);

void print_disk();

void optimize();

int main() {
    long n;

    cin >> n;

    while(n > 0) {
        bool broken = false;
        int d;
        char s, g;

        disk.clear();

        cin >> d >> s >> g;

        switch(s) {
            case 'K':
                blocksize = d / 8;
                disk.push_back({true, {"free", d}});
                break;
            case 'M':
                d *= 1024;
                blocksize = d / 8;
                disk.push_back({true, {"free", d}});
                break;
            case 'G':
                d *= 1024 * 1024;
                blocksize = d / 8;
                disk.push_back({true, {"free", d}});
                break;
        }

        for(int op = 0; op < n; op++) {
            string cmd;

            cin >> cmd;
            
            if(cmd == "insere") {
                string file;
                long size;

                cin >> file >> d >> s >> g;
                if(broken) continue;
            
                switch(s) {
                    case 'K':
                        size = d;
                        break;
                    case 'M':
                        size = d * 1024;
                        break;
                    case 'G':
                        size = d * 1024 * 1024;
                        break;
                }
                
                if(!insert(file, size)) {
                    optimize();
                    if(!insert(file, size)) {
                        broken = true;
                    }
                }

            } else if(cmd == "remove") {
                string file;

                cin >> file;
                if(broken) continue;

                remove(file);
            } else if(!broken) {
                optimize();
            }
        }

        if(broken)
            cout << "ERRO: disco cheio" << endl;
        else
            print_disk();

        cin >> n;
    }

    return 0;
}

vector<pair<bool, pair<string, long> > >::iterator seek_space(long min) {
    for(vector<pair<bool, pair<string, long> > >::iterator it = disk.begin(); it != disk.end(); it++) {
        if((*it).first && (*it).second.second >= min)
            return it;
    }
    return disk.end();
}

vector<pair<bool, pair<string, long> > >::iterator seek_name(string file) {
    for(vector<pair<bool, pair<string, long> > >::iterator it = disk.begin(); it != disk.end(); it++) {
        if(!(*it).first && (*it).second.first == file)
            return it;
    }
    return disk.end();
}

bool insert(string file, long size) {
    vector<pair<bool, pair<string, long> > >::iterator disp = seek_space(size);

    if(disp == disk.end()) {
        return false;
    }

    if((*disp).second.second - size <= 0)
        disk.erase(disp);
    else
        (*disp).second.second -= size;

    disk.insert(disp, {false, {file, size}});

    return true;
}

bool remove(string file) {
    vector<pair<bool, pair<string, long> > >::iterator fileit = seek_name(file);

    if(fileit == disk.end()) {
        return false;
    }

    (*fileit).first = true;

    if(fileit != disk.begin() && (*prev(fileit)).first) {
        (*fileit).second.second += (*prev(fileit)).second.second;
        disk.erase(prev(fileit));
    }
    if(next(fileit) != disk.end() && (*next(fileit)).first) {
        (*fileit).second.second += (*next(fileit)).second.second;
        disk.erase(next(fileit));
    }

    return true;
}

void print_disk() {
    long total = 0;
    double percentage = 0;
    for(long i = 0; i < disk.size(); i++) {
        total += disk[i].second.second;
        percentage += disk[i].first ? total / blocksize : 0;

        while(total >= blocksize) {
            if(percentage <= 0.25) {
                cout << "[ ]";
            } else if(percentage >= 0.75) {
                cout << "[#]";
            } else {
                cout << "[-]";
            }
            total -= blocksize;
        }
    }
    cout << endl;
}

void optimize() {
    sort(disk.begin(), disk.end(), [ ] (pair<bool, pair<string, long> > o1, pair<bool, pair<string, long> > o2) {
        return o2.first && !o1.first;
    });
    
    long freespace = 0;

    for(int i = 0; i < disk.size(); i++) {
        if(!disk[i].first) continue;
        freespace += disk[i].second.second;
    }

    for(vector<pair<bool, pair<string, long> > >::iterator it = disk.begin(); it != disk.end(); it++) {
        if(!(*it).first) continue;
        (*it).second.second = freespace;
        disk.erase(next(it), disk.end());
        break;
    }
}