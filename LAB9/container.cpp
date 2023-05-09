#include <iostream>
#include <vector>

using namespace std;

int capacity, num_boxes;
vector<int> boxes;
vector<bool> chosen;

void backtracking(int current_capacity, int current_box) {
    // If we've reached the end of the boxes or the container is full, print the solution
    if (current_box == num_boxes || current_capacity >= capacity) {
        for (int i = 0; i < num_boxes; i++) {
            if (chosen[i]) {
                cout << boxes[i] << " ";
            }
        }
        cout << endl;
        return;
    }

    // Try including the current box
    if (current_capacity + boxes[current_box] <= capacity) {
        chosen[current_box] = true;
        backtracking(current_capacity + boxes[current_box], current_box + 1);
        chosen[current_box] = false;
    }

    // Try excluding the current box
    backtracking(current_capacity, current_box + 1);
}

int main() {
    cout << "Enter the capacity of the container: ";
    cin >> capacity;

    cout << "Enter the number of boxes: ";
    cin >> num_boxes;

    cout << "Enter the sizes of the boxes: ";
    for (int i = 0; i < num_boxes; i++) {
        int box_size;
        cin >> box_size;
        boxes.push_back(box_size);
        chosen.push_back(false);
    }

    backtracking(0, 0);

    return 0;
}
