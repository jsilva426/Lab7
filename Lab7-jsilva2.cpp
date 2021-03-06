﻿// Lab7.cpp : Defines the entry point for the console application.
//Jacob Silva
//11.19.18
//I could not get merge sort and quick sort to work correctly

#include "stdafx.h"
#include "Lab7-jsilva2.h"
#include "winTimer.h"//CHANGE: this to unixTimer.h if on mac/linux
#include <list>
using std::iterator;
#include <iostream>
#include <vector>
#include <algorithm>
#include "RandomUtilites.h"
#include "ContainerPrinting.h"

using namespace std;

int main()

{
	vector<double> stlSort;
	stlSort = randomVec(2000000);
	Timer getS;
	getS.start();
	sort(begin(stlSort), end(stlSort));
	getS.stop();
	cout << "stl sort Constructed in " << getS() << " seconds"
		<< endl;
	for (int i = 0; i < 10; i++)
	{
		cout << stlSort[i] << endl;
	}


	
	vector<double> v1;
	v1 = randomVec(12000);
	Timer get;
	get.start();
	bubbleSort(v1); //tests bubble sort
	get.stop();
	cout << "Bubble sort Constructed in " << get() << " seconds"
		<< endl;
	for (int i = 0; i < 10; i++)
	{
		cout << v1[i] << endl;
	}
	
	cout << endl << endl;
	vector<double> v2;
	v2 = randomVec(11000);
	Timer get1;
	get1.start();
	insertionSort(v2); //tests insertion sort
	get1.stop();
	cout << "Insertion sort Constructed in " << get1() << " seconds"
		<< endl;
	for (int i = 0; i < 10; i++)
	{
		cout << v2[i] << endl;
	}
	cout << endl << endl;
	vector<double> v3;
	v3 = randomVec(1800);
	Timer get2;
	get2.start();
	selectionSort(v3);	//tests selection sort
	get2.stop();
	cout << " Seletion sort Constructed in " << get2() << " seconds"
		<< endl;
	
	for (int i = 0; i < 10; i++)
	{
		cout << v3[i] << endl;
	}

	cout << endl << endl;

	
	vector<double> v4=(randomVec(10));
	vector<double>v41;
	Timer get3;
	get3.start();
	v41 = mergeSort(v4);;	//tests merge sort
	get3.stop();
	cout << "merge sort Constructed in " << get3() << " seconds"
		<< endl;

	for (int i = 0; i < 10; i++)
	{
		cout << v4[i] << endl;
	}

	cout << endl << endl;

	vector<double> v5 = (randomVec(10));
	Timer get4;
	get4.start();
	quickSort(v5,0,10);;	//tests quick sort
	get4.stop();
	cout << "quick sort Constructed in " << get4() << " seconds"
		<< endl;

	for (int i = 0; i < 10; i++)
	{
		cout << v5[i] << endl;
	}

	cout << endl << endl;

	


	return 0;
}

