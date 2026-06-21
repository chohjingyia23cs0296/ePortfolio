#include<iostream>
#include<iomanip>
using namespace std;
double* getTotalMark(int num_of_subject, double* arr);
double* getAverageMark(int num_of_subject, double total);
int main(){

    int num_of_subject;
    cout<<"Enter the number of subject in this semester: ";
    cin>>num_of_subject;
    double*arr=new double[num_of_subject];
    
    double *totalMark = getTotalMark(num_of_subject, arr);
    double *averageMark = getAverageMark(num_of_subject, *totalMark);

    cout<<fixed<<setprecision(2);
    cout<<"\nTotal mark: "<<*totalMark<<endl;
    cout<<"Average mark: "<<*averageMark<<endl;
    delete[] arr;
    arr=nullptr;

    return 0;
}
double* getTotalMark(int num_of_subject, double* arr){
    double* total_mark = new double;
 
    for(int x=0;x<num_of_subject;x++){
        cout<<"The subject mark "<<(x+1)<<": ";
        cin>>arr[x];
        cout<<"\n";
        *total_mark+=arr[x];
    }
    return total_mark;

}

double* getAverageMark(int num_of_subject, double total) {
    double *average=new double;
    *average = total / num_of_subject;

    return average;
}