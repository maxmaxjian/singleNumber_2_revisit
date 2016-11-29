#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <numeric>

class solution {
  public:
    int singleNumber(const std::vector<int> & nums) {
        std::string single = std::accumulate(nums.begin(), nums.end(), std::string("0"),
                                     [&](const std::string & s, int j){
                                         return mod3add(s,j);
                                     });
        std::bitset<12> bset(single);
        return int(bset.to_ulong());
    }

  private:
    std::string mod3add(const std::string &s, int n) {
        std::string sum;
        auto num1 = s;
        while (num1.size() < 12)
            num1.insert(0, "0");
        std::bitset<12> num2(n);
        for (size_t i = num2.size()-1; num2.size() > i; i--) {
            int bit1 = std::stoi(num1.substr(num2.size()-1-i,1)), bit2 = num2.test(i) ? 1 : 0;
            sum += std::to_string((bit1+bit2)%3);
        }
        return sum;
    }
};

int main() {
    std::vector<int> nums{1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,8};

    solution soln;
    int singleNum = soln.singleNumber(nums);
    std::cout << "The single number is:\n"
              << singleNum << std::endl;
}
