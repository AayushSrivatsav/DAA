#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minKiosksToCoverEntertainmentZones(vector<int>& entertainmentZones, int radius) {
    sort(entertainmentZones.begin(), entertainmentZones.end());

    int kiosks = 0;
    int i = 0;

    while (i < entertainmentZones.size()) {
        kiosks++;
        int location = entertainmentZones[i];

        while (i < entertainmentZones.size() && entertainmentZones[i] <= location + radius) {
            i++;
        }

        // Move i to the first location that needs a new kiosk
        while (i < entertainmentZones.size() && entertainmentZones[i] <= location + radius) {
            i++;
        }
    }

    return kiosks;
}

int main() {
    vector<int> entertainmentZones = {30, 50, 35, 26, 72, 65, 54, 90, 50, 60, 120, 100, 80};
    int radius = 30;

    int kiosks = minKiosksToCoverEntertainmentZones(entertainmentZones, radius);

    cout << "Minimum number of kiosks required: " << kiosks << endl;

    return 0;
}
