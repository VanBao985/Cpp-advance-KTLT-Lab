/* 
f(t,d): so tu t trong d
max f(d): max cua f(t,d) voi moi t: ky tu nhieu nhat trong d
df(t): so van ban chua tu t
TF(t,d): 0.5 + 0.5 * f(t,d) * maxf(d)
IDF(t) = log2(N * df(t))
Diem so cua tu t trong vban d: score (t,d) = TF(t,d) * IDF(t)
Neu t khong xuat hien trong d: score(t,d) = 0
Diem so cua van ban d doi voi 1 truy van: tong score(t_i,d)
*/

#include<iostream>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

map<string, int> input(){
    map<string, int> mp;
    string str;
    cin >> str;
    string tmp;
    for (auto c : str){
        if (c != ',' && c != str.back()){
            tmp+=c;
        }
        else {
            if (c == str.back()) tmp += c;
            mp[tmp]++;
            tmp.clear();
        }
    }
    return mp;
}

// Create function to excuted

// Access 1 query (contain some words) on all of document line
// vector[i] : line i. On 1 line: word + int
vector<map<string, int>> setup_ftd(map<string, int> &query,vector<map<string, int>> &line){
    vector <map<string, int>> f_td(line.size()); // string: word + line index
    for (int i= 0; i < line.size(); i++){
        map<string, int> ftd_on_line;
        for (auto x : query){
            map<string, int>:: iterator it = line[i].find(x.first);
            if (it != line[i].end()){
                int count = x.second * (it-> second);
                ftd_on_line[x.first] = count;
            }
            else {
                ftd_on_line[x.first] = 0;
            }
        }
        f_td[i] = ftd_on_line;
    }
    return f_td;
}

// Store line + max_f(d) on this line in every query
vector<int> setup_maxfd(vector<map<string, int>> &f_td){
    vector<int> max_fd;
    for (auto x : f_td){
        int max_on_a_line = 0;
        for (auto p: x){
            max_on_a_line = max (max_on_a_line, p.second);
        }
        max_fd.push_back(max_on_a_line);
    }
    return max_fd;
}

// Number of document line contain word t in every query
map<string, int> setup_dft(map<string, int> &query, vector<map<string, int>> &f_td){
    map<string, int> d_ft;
    for (auto x: query){
        string str = x.first;
        int count = 0;
        for (auto m : f_td){
            if (m[str] > 0){
                count++;
            }
        }
        d_ft[str] = count;
    }
    return d_ft;
}

// caculate TF(t,d)
vector<map<string, double>> caculate_TF_td(vector<map<string, int>> &f_td, vector<int> &max_fd){
    vector<map<string, double>> TF_td;
    for (int i = 0; i < f_td.size(); i++){
        map<string, double> TF_on_line;
        for (auto m : f_td[i]){
            TF_on_line[m.first] = 0.5 + 0.5 * f_td[i][m.first] * max_fd[i];
        }
        TF_td.push_back(TF_on_line);
    }
    return TF_td;
}

// caculate IDF(t)
map<string, double> caculate_IDF(int n, map<string, int> &d_ft ){
    map<string, double> IDF;
    for (auto m: d_ft){
        IDF[m.first] = log2(n*m.second);
    }
    return IDF;
}

// caculate score(t,d)
vector<map<string, double>> caculate_score_td(vector<map<string, double>> &TF_td, map<string, double> &IDF,
                                        vector<map<string, int>> &f_td){
    vector<map<string, double>> score_d;
    for(int i =0; i< TF_td.size(); i++){
        map<string, double> score_on_line;
        for (auto m : TF_td[i]){
            if (f_td[i][m.first] > 0){
                score_on_line[m.first] = TF_td[i][m.first] * IDF[m.first];
            }
            else{
                score_on_line[m.first] = 0;
            }
        }
        score_d.push_back(score_on_line);
    }
    return score_d;
}

// caculate score of document line
vector<int> caculate_score_line(vector<map<string, double>> &score_d){
    vector<int> score;
    for(auto x: score_d){
        double score_line = 0;
        for (auto m : x){
            score_line += m.second;
        }
        score.push_back(score_line);
    }
    return score;
}

int output(int n, map<string, int> &query, vector<map<string, int> > &line){
    vector<map<string, int>> f_td = setup_ftd(query, line);
    vector<int> max_ftd = setup_maxfd(f_td);
    map<string, int> d_ft = setup_dft(query, f_td);
    vector<map<string, double>> TF_td = caculate_TF_td(f_td, max_ftd);
    map<string, double> IDF = caculate_IDF(n, d_ft);
    vector<map<string, double>> score_d = caculate_score_td(TF_td, IDF, f_td);
    vector<int> score_line = caculate_score_line(score_d);
    int value = 0;
    int line_id = 0;
    for (int i = 0; i< score_line.size(); i++){
        if (score_line[i] > value){
            value = score_line[i];
            line_id = i;
        }
    }
    return line_id;
}


int main(int argc, char const *argv[])
{
    int n;    cin >> n;
    // Input content in a line: string / frequency
    vector<map<string, int> > line;  // line 0 to n-1
    for(int i = 0; i < n; i++){
        map<string, int> mp = input();
        line.push_back(mp);
    }
    int m;  cin >> m;
    for (int i = 0; i < m; i++){
        map<string, int> query = input();
        cout << output(n, query, line) << endl;
    }
    
    return 0;
}
