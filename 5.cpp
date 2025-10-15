#include <iostream>

void towerOfHanoi(int n, char source, char destination, char auxiliary, int &moveCount) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        moveCount++;
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination, moveCount);

    // Move the nth disk from source to destination
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    moveCount++;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source, moveCount);
}

int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Number of disks must be greater than 0.\n";
        return 1;
    }

    int moveCount = 0;
    std::cout << "\nSteps to solve Tower of Hanoi with " << n << " disks:\n\n";
    towerOfHanoi(n, 'A', 'C', 'B', moveCount);

    std::cout << "\nTotal moves required: " << moveCount << std::endl;

    return 0;
}
