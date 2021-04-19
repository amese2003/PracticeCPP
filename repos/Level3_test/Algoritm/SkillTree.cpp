#include <string>
#include <vector>
#include <map>

using namespace std;
int SkillTree(string skill, vector<string> skill_trees) {
	int answer = 0;

	map<char, int> skillRequire;

	string check_Tree = "";
	string requireSkill = skill;
	char learnSkill = requireSkill[0];


	for (int i = 0; i < skill.length(); i++) {
		skillRequire.insert({ skill[i], i });
	}

	for (int i = 0; i < skill_trees.size(); i++) {
		check_Tree.clear();
		check_Tree = skill_trees[i];

		while (check_Tree.size() > 0) {
			if (skillRequire.count(learnSkill) > 0 && skillRequire.count(check_Tree[0]) > 0 && skillRequire.find(learnSkill)->second < skillRequire.find(check_Tree[0])->second)
				break;

			if (skillRequire.count(learnSkill) > 0 && learnSkill == requireSkill[0]) {
				requireSkill.erase(0, 1);
				if (requireSkill.size() > 0)
					learnSkill = requireSkill[0];
			}
			check_Tree.erase(0, 1);

			if (requireSkill.size() == 0 || check_Tree.size() == 0) {
				answer++;
				break;
			}
		}

		requireSkill.clear();
		requireSkill = skill;
		learnSkill = requireSkill[0];
	}
	return answer;
}