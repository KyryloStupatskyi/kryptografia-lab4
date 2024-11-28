#include <iostream>
#include <vector>
using namespace std;

// Function to implement the LFSR
vector<int> LFSR(vector<int> initial_state, int m, vector<int> feedback_taps, int output_length) {
    vector<int> output_stream; // To store the output sequence
    vector<int> register_state = initial_state; // Copy the initial state into the LFSR register

    for (int i = 0; i < output_length; ++i) {
        // Capture the output bit (usually the least significant bit, s_0)
        output_stream.push_back(register_state[0]);

        // Calculate the feedback bit (XOR of selected feedback taps)
        int feedback = 0;
        for (int tap : feedback_taps) {
            feedback ^= register_state[tap]; // XOR the tapped bits
        }

        // Shift the register and insert the feedback bit into the most significant position
        for (int j = 0; j < m - 1; ++j) {
            register_state[j] = register_state[j + 1];
        }
        register_state[m - 1] = feedback; // Set the feedback bit
    }

    return output_stream;
}

int main() {
    // Example parameters
    vector<int> initial_state = { 1, 0, 0 }; // Initial state of the register
    int m = 3; // Degree of the LFSR
    vector<int> feedback_taps = { 0, 2 }; // Feedback connections (C(x) = 1 + x + x^3)
    int output_length = 14; // Length of the output stream

    // Run the LFSR
    vector<int> output = LFSR(initial_state, m, feedback_taps, output_length);

    // Print the output sequence
    cout << "Output sequence: ";
    for (int bit : output) {
        cout << bit << " ";
    }
    cout << endl;

    return 0;
}
