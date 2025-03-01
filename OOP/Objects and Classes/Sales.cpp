#include <iostream>
#include <sstream>
#include <map>
#include <vector>


class Sale {
    std::string town;
    std::string product;
    double price;
    double quantity;

public:
    Sale() :
        price(), quantity() {}

    Sale(const std::string &town, const std::string &product, const double &price, const double &quantity) :
        town(town), product(product), price(price), quantity(quantity) {
    }

    std::string getTownName() const {
        return this->town;
    }

    double getTotalPrice() const {
        return this->price * this->quantity;
    }

    friend std::istream& operator>>(std::istream& is, Sale& sale);
};

std::istream& operator>>(std::istream& is, Sale& sale) {
    return is >> sale.town >> sale.product >> sale.price >> sale.quantity;
}


int main() {
    std::map<std::string, std::vector<Sale>> citySales;

    int numberOfSales;
    std::cin >> numberOfSales;

    for (int i = 0; i < numberOfSales; ++i) {
        Sale sale{};
        std::cin >> sale;
        citySales[sale.getTownName()].push_back(sale);
    }

    for (const auto& citySale : citySales) {
        double cityTotalPrice{};
        for (auto& sale : citySale.second)
            cityTotalPrice += sale.getTotalPrice();
        printf("%s -> %.2f\n", citySale.first.c_str(), cityTotalPrice);
    }

    return 0;
}

// 5
// Sofia beer 1.20 160
// Varna chocolate 2.35 86
// Sofia coffee 0.40 853
// Varna apple 0.86 75.44
// Plovdiv beer 1.10 88
