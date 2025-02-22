#include <iostream>
#include <sstream>


class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int balance = 100;
        balance -= purchaseAmount % 10 < 5
                       ? purchaseAmount - (purchaseAmount % 10)
                       : purchaseAmount + (10 - (purchaseAmount % 10));
        // if the last char < 5 -> remove it from the purchase amount, otherwise add just enough to add to the 10th number
        return balance;
    }
};

int main() {
    Solution s;

    std::cout << s.accountBalanceAfterPurchase(10);
    return 0;
}
