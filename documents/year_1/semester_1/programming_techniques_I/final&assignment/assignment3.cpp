#include <iostream>
#include<iomanip>
#include <fstream>
using namespace std;

const int SIZE=20;
//CHOH JING YI
//LIOW JIA FENG
void readFile(string fileName, string university[], int num_intake[], int enrolment[], int output[]);
int getLowest(const int array[], int SIZE,  string university[], string &lowestUni);
int getHighest(const int array[], int SIZE,  string university[], string &highestUni);
int calTotal(const int array[], int SIZE);
float average(const int array[], int SIZE);
int findRange(int highest, int lowest);
void printFile(string fileName,  string university[], int num_intake[], int enrolment[], int output[]);

int main() {
    string outputFile, university[SIZE];
    int num_intake[SIZE], enrolment[SIZE], output[SIZE];
    readFile("inputassign3.txt", university, num_intake, enrolment, output);
    printFile("outputassign3.txt", university, num_intake, enrolment, output);

    return 0;
}

void readFile(string fileName, string university[], int num_intake[], int enrolment[], int output[]) {
    ifstream inFile(fileName.c_str());
    if (!inFile.is_open()) {
        cout << "ERROR. File not exist\n";
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        inFile >> university[i] >> num_intake[i] >> enrolment[i] >> output[i];
    }

    inFile.close();
}

int calTotal(const int array[], int SIZE) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }
    return sum;
}

float average(const int array[], int SIZE) {
    int sum = calTotal(array, SIZE);
    return static_cast<float>(sum) / SIZE;
}

int getLowest(const int array[], int SIZE,  string university[], string &lowestUni) {
    int lowest = 99999;
    lowestUni = "";
    for (int i = 0; i < SIZE; i++) {
        if (array[i] < lowest) {
            lowest = array[i];
            lowestUni = university[i];
        }
    }
    return lowest;
}

int getHighest(const int array[], int SIZE,  string university[], string &highestUni) {
    int highest = -1;
    highestUni = "";
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > highest) {
            highest = array[i];
            highestUni = university[i];
        }
    }
    return highest;
}

int findRange(int highest, int lowest) {
    return highest - lowest;
}

void printFile(string fileName,  string university[], int num_intake[], int enrolment[], int output[]) {
    ofstream outFile(fileName.c_str());  
    outFile << "\t\t\t" << "NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT\n"
            << "\t\t\t\t\t" << "IN PUBLIC UNIVERSITIES (2023)\n"
            << string(70, '-') << "\n"
            << setw(15) << "UNIVERSITY"
            << setw(15) << "INTAKE"
            << setw(16) << "ENROLMENT"
            << setw(14) << "OUTPUT\n"
            << string(70, '-') << "\n";

    for (int i = 0; i < SIZE; i++) {
        outFile << "\t\t" << left << setw(12) << university[i]
                << right << setw(9) << num_intake[i]
                << right << setw(14) << enrolment[i]
                << right << setw(15) << output[i] << "\n";
    }

    outFile << string(70, '-') << "\n"
            << "\t\t" << left << setw(12) << "TOTAL"
            << right << setw(9) << calTotal(num_intake, 20)
            << right << setw(14) << calTotal(enrolment, 20) << "\t"
            << right << setw(15) << calTotal(output, 20) << "\t" << "\n"
            << "\t\t" << left << setw(12) << "AVERAGE"
            << fixed << setprecision(2)
            << right << setw(9) << average(num_intake, 20)
            << right << setw(14) << average(enrolment, 20) << "\t"
            << right << setw(15) << average(output, 20) << "\t" << "\n"
            << string(70, '-') << "\n\n";

    string lowUniIntake, lowUniEnrol, lowUniOutput;
    int lowestNumIntake = getLowest(num_intake, SIZE, university, lowUniIntake);
    int lowestEnrolment = getLowest(enrolment, SIZE, university, lowUniEnrol);
    int lowestOutput = getLowest(output, SIZE, university, lowUniOutput);

    outFile << "THE LOWEST NUMBER OF STUDENTS' INTAKE      =  " << lowestNumIntake << " (" << lowUniIntake << ")\n"
            << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT   =  " << lowestEnrolment << " (" << lowUniEnrol << ")\n"
            << "THE LOWEST NUMBER OF STUDENTS' OUTPUT      =  " << lowestOutput << " (" << lowUniOutput << ")\n\n";

    string higheUniIntake, highUniEnrol, highUniOutput;
    int highestNumIntake = getHighest(num_intake, SIZE, university, higheUniIntake);
    int highestEnrolment = getHighest(enrolment, SIZE, university, highUniEnrol);
    int highestOutput = getHighest(output, SIZE, university, highUniOutput);
    outFile << "THE HIGHEST NUMBER OF STUDENTS' INTAKE     =  " << highestNumIntake << " (" << higheUniIntake << ")\n"
            << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT  =  " << highestEnrolment << " (" << highUniEnrol << ")\n"
            << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT     =  " << highestOutput << " (" << highUniOutput << ")\n\n";

    outFile
            << "THE RANGE OF STUDENTS' INTAKE              =  "
            << findRange(highestNumIntake, lowestNumIntake) << "\n"
            << "THE RANGE NUMBER OF STUDENTS' ENROLMENT     =  "
            << findRange(highestEnrolment, lowestEnrolment) << "\n"
            << "THE RANGE NUMBER OF STUDENTS' OUTPUT        =  "
            << findRange(highestOutput, lowestOutput) << "\n";

    outFile.close();
}
