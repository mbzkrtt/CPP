
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        bool dejaCompte = false;

        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                dejaCompte = true;
                break;
            }
        }

        if (!dejaCompte) {
            int frequence = 0;

            for (int j = 0; j < numbers.size(); j++) {
                if (numbers[i] == numbers[j]) {
                    frequence++;
                }
            }

            cout << numbers[i] << " : " << frequence << " times" << endl;
        }
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequences;

    for (int nombre : numbers) {
        frequences[nombre]++;
    }

    return frequences;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "Frequency (Brute-Force):" << endl;
    countFrequencyBruteForce(numbers);

    cout << "\nFrequency (Optimal):" << endl;
    map<int, int> frequencyMapOptimal =
        countFrequencyOptimal(numbers);

    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : "
             << entry.second << " times" << endl;
    }

    return 0;
}



vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {};
}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> numbers;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (numbers.find(complement) != numbers.end()) {
            return {numbers[complement], i};
        }

        numbers[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);

    cout << "Brute-Force Solution: ["
         << indicesBruteForce[0] << ", "
         << indicesBruteForce[1] << "]"
         << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);

    cout << "Optimal-Solution: ["
         << indicesOptimal[0] << ", "
         << indicesOptimal[1] << "]"
         << endl;

    return 0;
}



using namespace std;

bool isPalindrome(const string& input) {
    queue<char> q;
    stack<char> s;

    for (char c : input) {
        q.push(c);
        s.push(c);
    }

    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false;
        }

        q.pop();
        s.pop();
    }

    return true;
}

int main() {
    cout << boolalpha;

    cout << "Is 'racecar'-a-palindrome?-"
         << isPalindrome("racecar") << endl;

    cout << "Is 'hello'-a-palindrome?-"
         << isPalindrome("hello") << endl;

    return 0;
}