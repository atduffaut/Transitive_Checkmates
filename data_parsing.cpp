#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//comment to publish

int main() {
    string line;
    string whiteUser;
    string blackUser;
    string blackElo;
    string whiteElo;
    bool whiteWin = false;
    bool blackWin = false;
    bool active = false;
    string filename;
    cout << "Input filename without extension: ";
    cin >> filename;
    ifstream inFile(filename + ".pgn");
    ofstream outFile(filename + ".csv");
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            if (line.length() > 1) {
                line = line.substr(1, line.length());
                if (line.substr(0, 5) == "White" && line.substr(5, 1) == " ") {
                    whiteUser = line.substr(7, line.length());
                    whiteUser = whiteUser.substr(0, whiteUser.find("\""));
                }
                if (line.substr(0, 5) == "Black" && line.substr(5, 1) == " ") {
                    blackUser = line.substr(7, line.length());
                    blackUser = blackUser.substr(0, blackUser.find("\""));
                }
                if (line.substr(0, 6) == "Result") {
                    if (line.substr(8, 1) == "1" && line.substr(9, 1) != "/") {
                        whiteWin = true;
                    }
                    if (line.substr(8, 1) == "0") {
                        blackWin = true;
                    }
                }
                if (line.substr(0, 8) == "WhiteElo") {
                    whiteElo = line.substr(10, line.length());
                    whiteElo = whiteElo.substr(0, whiteElo.find("\""));
                }
                if (line.substr(0, 8) == "BlackElo") {
                    blackElo = line.substr(10, line.length());
                    blackElo = blackElo.substr(0, blackElo.find("\""));
                    active = true;
                    if (blackElo == "?") {
                        active = false;
                    }
                }
                if (whiteWin && active) {
                    outFile << whiteUser << "," << blackUser << "," << blackElo << "\n";
                    active = false;
                    whiteWin = false;
                }
                else if (blackWin && active) {
                    outFile << blackUser << "," << whiteUser << "," << whiteElo << "\n";
                    active = false;
                    blackWin = false;
                }
                else if (active) {
                    active = false;
                }
            }
        }
        inFile.close();
    }

}
