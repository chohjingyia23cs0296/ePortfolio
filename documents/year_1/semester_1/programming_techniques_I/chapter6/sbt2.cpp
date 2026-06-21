#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

//----------------- Function prototypes ---------------------------
double gradeToPoint(char);
void readFile(string, string[], double[], char[], double[], int &);
double sum(const double[], int);
double multiply(const double[], const double[], double[], int);

// Function : gradeToPoint
// Purpose : To determine the point value for a letter grade.
// Parameters : grade - the letter grade
// Return value: the point value of the grade
double gradeToPoint(char grade)
{
    if (grade == 'A') return 4.0;
    if (grade == 'B') return 3.0;
    if (grade == 'C') return 2.0;
    if (grade == 'D') return 1.0;
    return 0.0;
}

// Function : readFile
// Purpose : To read inputs from a file consisting of the list of
// subjects along with their credit hours and grades earned by the student.
// Parameters:
// fileName : the name of the input file
// subjects : the array to hold the list of subjects read from the file
// credits : the array to hold the list of credit hours
// grades : the array to hold the list of grades
// points : the array to hold the list of point values for corresponding grades
// count : the number of subjects read
void readFile(string fileName, string subjects[], double credits[], char grades[], double points[], int &count)
{
    string sn; // subject name
    double ch; // credit hour
    char g;    // grade earned
    double gp; // grade point

    ifstream fin(fileName.c_str());
    count = 0;

    while (getline(fin, sn, '\t'))
    {
        fin >> ch;
        fin.ignore();
        fin >> g;
        fin.ignore();

        // complete these lines such that the read data
        // are stored into arrays accordingly.
        subjects[count] = sn;  // 1m
        credits[count] = ch;   // 1m
        grades[count] = g;     // 1m
        points[count] = gradeToPoint(g);  // 2m

        count++;
    }

    fin.close();
}

// Function : sum
// Purpose : To calculate the sum of elements of an array.
// Parameters:
// a - the array
// n - the size of array
// Return value: the sum of all the elements of the array
double sum(const double a[], int n)
{
    double s = 0;

    for (int i = 0; i < n; i++)
        s += a[i];

    return s;
}

// Function : multiply
// Purpose : to multiply the elements of arrays a and b correspondingly,
// and puts the result into another array, c.
// Parameters:
// a, b - the input arrays
// c - the array that holds the results of the multiplication.
double multiply(const double a[], const double b[], double c[], int n)
{
    for (int i = 0; i < n; i++)
        c[i] = a[i] * b[i];
}

int main()
{
    string inputFile;
    string s[10]; // The list (array) of subjects
    double c[10]; // The list (array) of credits
    char g[10];    // The list (array) of grades
    double p[10];   // The list (array) of points (i.e., the point value for each grade)
    int n;          // The number of subjects

    double cp[10];  // The list of credit points, i.e., creditHour x gradePoint
    double tc;      // Total credit hour
    double tcp;     // Total credit point
    double cgpa;

    cout << "Enter the input file => ";
    cin >> inputFile;

    // Read inputs from the input file
    readFile(inputFile, s, c, g, p, n);

    // Using appropriate functions defined above, calculate the total credit hours,
    // total credit points and CGPA.
    multiply(c, p, cp, n);
    tc = sum(c, n);
    tcp = sum(cp, n);
    cgpa = tcp / tc;

    cout << endl << endl;

    // Print the list of subjects along with their credit hours, grades earned and grade points.
    cout << setw(30) << left << "Subject Name"
         << setw(15) << left << "Credit Hour"
         << setw(15) << left << "Grade Earned"
         << setw(15) << left << "Grade Point"
         << endl << endl;

    for (int i = 0; i < n; i++)
        cout << setw(30) << left << s[i]
             << setw(15) << c[i]
             << setw(15) << g[i]
             << setw(15) << p[i]
             << endl;

    cout << endl;

    // Print the number of subjects, total credit hours, total credit points and CGPA.
    cout << "Number of subject : " << n << endl;
    cout << "Total credit hours : " << tc << endl;
    cout << "Total credit points : " << tcp << endl;
    cout << showpoint << fixed << setprecision(2);
    cout << "CGPA : " << cgpa << endl;

    return 0;
}
