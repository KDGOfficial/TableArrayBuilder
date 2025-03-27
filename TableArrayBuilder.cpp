#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TableArrayBuilder {
public:
    static void printTable(const vector<vector<int>>& arr) {
        if (arr.empty()) return;

        int rows = static_cast<int>(arr.size());
        int cols = static_cast<int>(arr[0].size());
        int maxWidth = 2;

        // Определяю максимальную ширину колонки
        for (const auto& row : arr) {
            for (int num : row) {
                maxWidth = max(maxWidth, static_cast<int>(to_string(num).length()));
            }
        }

        maxWidth += 2; // Добавляю запас для красивого вида

        int totalWidth = 12 + cols * (maxWidth + 3);

        cout << "Table representation of an array:\n";
        cout << string(totalWidth, '-') << '\n';
        cout << "| Num R/C  |";

        // Заголовки столбцов
        for (int j = 0; j < cols; j++) {
            cout << " " << setw(maxWidth) << ("#" + to_string(j + 1)) << " |";
        }
        cout << "\n" << string(totalWidth, '-') << '\n';

        // Вывод данных
        for (int i = 0; i < rows; i++) {
            cout << "| Row #" << setw(2) << i + 1 << "  |";
            for (int j = 0; j < cols; j++) {
                cout << " " << setw(maxWidth) << arr[i][j] << " |";
            }
            cout << "\n" << string(totalWidth, '-') << '\n';
        }
    }

    static void printTextRepresentation(const vector<vector<int>>& arr) {
        cout << "\nText representation of an array:\n";
        for (const auto& row : arr) {
            for (int num : row) {
                cout << setw(3) << num << " ";
            }
            cout << '\n';
        }
    }
};

int main() {
    vector<vector<int>> array = {
        { 14, 23, 11, 18, 15,  9, 11, 14 },
        { 20, 18,  7, 21,  5,  1, 29, 20 },
        { 24,  9,  8,  7, 27,  0,  4,  6 },
        {  1,  8,  3,  9, 10, 15, 25,  4 },
        { 12, 11, 10, 20, 22,  7,  7, 14 },
        { 21, 10, 11,  9, 26, 16, 16, 14 },
        { 21, 16, 24,  4, 22, 11,  1, 26 },
        { 20, 19, 23,  1,  8,  1, 16,  4 }
    };

    TableArrayBuilder::printTable(array);
    TableArrayBuilder::printTextRepresentation(array);

    return 0;
}
