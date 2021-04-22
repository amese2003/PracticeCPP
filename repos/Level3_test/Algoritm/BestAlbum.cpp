#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}
bool compare_map_value(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> BestAlbum(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector<pair<int, int>>> genre_play;
    unordered_map<string, int> genre_total;

    vector<pair<string, int>> genre_list;

    int size = genres.size();

    for (int i = 0; i < size; i++) {
        genre_play[genres[i]].push_back(make_pair(plays[i], i));
        genre_total[genres[i]] += plays[i];
    }

    for (auto& k : genre_play) {
        sort(k.second.begin(), k.second.end(), compare);
    }

    genre_list.assign(genre_total.begin(), genre_total.end());
    sort(genre_list.begin(), genre_list.end(), compare_map_value);

    for (int i = 0; i < genre_list.size(); i++) {
        string most_genres = genre_list[i].first;

        for (int j = 0; (j < genre_play[most_genres].size()) && (j < 2); j++) {
            answer.push_back(genre_play[most_genres][j].second);
        }
    }

    return answer;
}