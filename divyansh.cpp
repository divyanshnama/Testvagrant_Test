#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxGSTfunc(unordered_map<int, int> &unitPrice, unordered_map<int, int> &GST, unordered_map<int, int> &quantity)
    {
        int maxi = 0;
        int index = 0;

        for (int i = 0; i < GST.size(); i++)
        {
            int cmax = GST[i] * quantity[i] * unitPrice[i];
            if (cmax > maxi)
            {
                maxi = cmax;
                index = i;
            }
        }
        return index;
    }

    int totalAmount(unordered_map<int, int> &unitPrice, unordered_map<int, int> &GST, unordered_map<int, int> &quantity)
    {
        double totalPrice = 0;
        double pricecurrent;
        for (int i = 0; i < unitPrice.size(); i++)
        {
            if (unitPrice[i] >= 500)
            {
                pricecurrent = unitPrice[i] * quantity[i] + (18 / 100 * unitPrice[i]) * quantity[i];
                pricecurrent = pricecurrent - 5 / 100 * pricecurrent;
                totalPrice += pricecurrent;
            }
            else
            {
                totalPrice += unitPrice[i] * quantity[i] + (18 / 100 * unitPrice[i]) * quantity[i];
            }
        }
        return totalPrice;
    }
};

int main()
{
    unordered_map<int, string> product;
    unordered_map<int, int> unitPrice;
    unordered_map<int, int> GST;
    unordered_map<int, int> quantity;

    product[0] = "Leather Wallet";
    product[1] = "Umbrella";
    product[2] = "Cigratte";
    product[3] = "Honey";

    unitPrice[0] = 1100;
    unitPrice[1] = 900;
    unitPrice[2] = 200;
    unitPrice[3] = 100;

    GST[0] = 18;
    GST[1] = 12;
    GST[2] = 28;
    GST[3] = 0;

    quantity[0] = 1;
    quantity[1] = 4;
    quantity[2] = 3;
    quantity[3] = 2;

    Solution obj1;

    int maxGST = obj1.maxGSTfunc(unitPrice, GST, quantity);
    cout << product[maxGST] << endl;

    double totalPrice = obj1.totalAmount(unitPrice, GST, quantity);
    cout << totalPrice << endl;
}
