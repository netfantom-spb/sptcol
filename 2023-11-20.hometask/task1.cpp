#include <iostream>
#include <vector>
using namespace std;

int findPosition(const vector<int> &heights, int petyaHeight)
{
    int position = heights.size() + 1;

    for (int i = 0; i < heights.size(); ++i)
    {
        if (heights[i] < petyaHeight)
        {
            position = i + 1;
            break;
        }
    }

    return position;
}

bool isNumber(const std::string &s)
{
    try
    {
        std::stoi(s);
        return true;
    }
    catch (const std::invalid_argument &)
    {
        return false;
    }
}

int main()
{
    vector<int> heights;
    int height, petyaHeight;
    string input;

    cout << "Введите росты учеников (в невозрастающем порядке), для завершения ввода введите любую букву:" << endl;
    // Ввод последовательности ростов
    cin >> input;
    while (isNumber(input))
    {
        height = stoi(input);
        heights.push_back(height);
        cin >> input;
    }
    cin.clear();
    cout << "Введите рост Пети:" << endl;
    // Ввод роста Пети

    cin >> petyaHeight;

    int result = findPosition(heights, petyaHeight);
    cout << "Петя должен встать на позицию " << result << " в строю." << endl;

    return 0;
}
