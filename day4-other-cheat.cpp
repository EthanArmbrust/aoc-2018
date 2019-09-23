#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>


int main(int argc, char* argv[]) {
    std::ifstream ifs(argv[1]); std::vector<std::string> lines;
    for (std::string l; std::getline(ifs, l);) { lines.push_back(l); }
    std::sort(lines.begin(), lines.end());

    std::map<int, std::array<int, 60>> guards;
    int s = -1, id = -1, *g = nullptr; std::smatch m;
    for (const auto& l : lines)
        if (std::regex_match(l, m, std::regex(R"(.*Guard #(\d+) begins shift)")))
            g = guards[std::stoi(m[1])].data();
        else if (std::regex_match(l, m, std::regex(R"(.*:(\d+)\] wakes up)")))
            std::for_each(g+s, g+std::stoi(m[1]), [](auto& x){x++;});
        else if (std::regex_match(l, m, std::regex(R"(.*:(\d+)\] falls asleep)")))
            s = std::stoi(m[1]);

    auto maxMinute = [](const auto& gi) { return[&gi](auto m) -> std::pair<int,int>{
        return {std::distance(gi.begin(), m), *m};}(std::max_element(gi.begin(), gi.end()));};

    const auto& [id1,guardInfo1] = (*std::max_element(guards.begin(), guards.end(),
        [](auto& l, auto& r) { return std::reduce(l.second.begin(), l.second.end()) <
            std::reduce(r.second.begin(), r.second.end()); }));
    const auto& minute1 = maxMinute(guardInfo1).first;

    const auto& [id2,guardInfo2] = *std::max_element(guards.begin(), guards.end(),
        [&](auto& l, auto& r) { return maxMinute(l.second).second < maxMinute(r.second).second; });
    const auto& minute2 = maxMinute(guardInfo2).first;

    std::cout << "1: " << minute1 * id1 << "\n" << "2: " << minute2 * id2 << "\n";
}
