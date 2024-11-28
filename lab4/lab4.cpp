#include <iostream>
#include <vector>

using namespace std;

// Funkcja do generowania strumienia bitów z LFSR
vector<int> lfsr(vector<int> initial_state, vector<int> feedback_taps, int output_length) {
    vector<int> output_stream;
    int m = initial_state.size();  // długość rejestru

    // Główna pętla generowania strumienia bitów
    for (int i = 0; i < output_length; ++i) {
        // Pierwszy bit w rejestrze to wyjściowy bit
        int output_bit = initial_state[0];
        output_stream.push_back(output_bit);

        // Obliczanie bitu sprzężenia zwrotnego
        int feedback_bit = 0;
        for (int tap : feedback_taps) {
            feedback_bit ^= initial_state[tap];  // XOR na odpowiednich bitach
        }

        // Przesunięcie rejestru w lewo o jeden bit
        initial_state.erase(initial_state.begin());  // Usuwamy najstarszy bit
        initial_state.push_back(feedback_bit);  // Dodajemy obliczony bit sprzężenia zwrotnego na koniec
    }

    return output_stream;
}

int main() {
    // Stan początkowy rejestru (przykład: m = 3)
    vector<int> initial_state = { 0, 0, 1 };

    // Połączenia sprzężenia zwrotnego (przykład: C(x) = 1 + x + x^3, więc feedback_taps = {0, 1})
    vector<int> feedback_taps = { 0, 1 };

    // Długość wyjściowego strumienia bitów
    int output_length = 14;

    // Generowanie strumienia bitów
    vector<int> output_stream = lfsr(initial_state, feedback_taps, output_length);

    // Wyświetlenie wygenerowanego strumienia bitów
    for (int bit : output_stream) {
        cout << bit << " ";
    }
    cout << endl;

    return 0;
}
