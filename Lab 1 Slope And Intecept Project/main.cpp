//AUTHOR: Emiliano Panday Manalo IV
//PURPOSE: Caculates the slope and intercept of a given scale and error filled measurment
//DATE: 04/02/2025

//Required libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Summation functions for a given array
float sumArray(float*, int);
float sumProductTwoArrayElements(float*, float*, int);
float sumArrayElementSquared(float*, int);

//Given functions to transfer file data into array
int measurmentSize(std::ifstream&);
void CopyFileDataIntoArray(float*, int, std::ifstream&);

int main()
{
    //Opened file objects
    std::ifstream degFFile("degf.dat");
    std::ifstream degCFile("degcerror.dat");
    std::ofstream slopeAndInterceptFile("slopeAndIntercept.dat");
  
    //Gives measurment of rows for a given file
    int N = measurmentSize(degCFile);

    //Allocate the new array with how many data points are in the file
    float* degfArray = new float[N];
    float* degcArray = new float[N];
    float slope, intercept;
    
    //Copy file data new allocated array
    CopyFileDataIntoArray(degfArray, N, degFFile);
    CopyFileDataIntoArray(degcArray, N, degCFile);

    //Calculate the slope
    slope = ((sumArray(degcArray,N)*sumArray(degfArray,N))-N*sumProductTwoArrayElements(degcArray,degfArray,N))/
    (sumArray(degfArray,N)*sumArray(degfArray,N)-N*sumArrayElementSquared(degfArray,N));

    //Calculate the intercept
    intercept = (sumArray(degcArray, N)-slope*sumArray(degfArray,N))/N;

    //Write the data into the file
    slopeAndInterceptFile << "SLOPE: " << slope << endl << "INTERCEPT: " << intercept << endl;

    //Deallocate the memory used
    delete[] degfArray;
    delete[] degcArray;

    //Close all required files
    degFFile.close();
    degCFile.close();
    slopeAndInterceptFile.close();

    //End program and tell user process is complete
    cout << "PROGRAM COMPLETE";
    return 0;
}

//Adds all elements of the array
float sumArray(float* arr, int SIZE) 
{
    float sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    return sum;
}

//Adds all the elements of an array which is multiplies with another array
float sumProductTwoArrayElements(float* ar1, float* ar2, int SIZE)
{
    float sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += (ar1[i] * ar2[i]);
    }
    return sum;
}

//First squares the elements, then sums them all up
float sumArrayElementSquared(float* arr, int SIZE)
{
    float sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += (arr[i] * arr[i]);
    }
    return sum;
}

//Measures amount of rows in that given file
int measurmentSize(std::ifstream& fileToMeasure)
{
    int N = 0;
    float null;
    if(fileToMeasure.is_open())
    {
        while(fileToMeasure >> null)
        {
            N++;
        }
    }
    fileToMeasure.clear();
    fileToMeasure.seekg(0, ios::beg);
    return N;
}

//Copies data from file into an array
void CopyFileDataIntoArray(float* arr, int N, std::ifstream& file)
{
    int i = 0;
    if(file.is_open())
    {
        while(file >> arr[i])
        {
            i++;
        }
    }
    file.clear();
    file.seekg(0, ios::beg);
}
