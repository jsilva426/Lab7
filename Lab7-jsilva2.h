#pragma once

#include <vector>
using std::vector;
#include <algorithm>
double Random()
{
	double min = 0, max = 500;
	double a = (double)rand() / RAND_MAX;
	return (a*(max - min));
}

vector<double> randomVec(int size)
{
	double a;
	vector<double> theList;
	for (int i = 0; i < size; i++)
	{
		a = Random();
		theList.push_back(a);

	}
	return theList;
}


void bubbleSort(vector<double> &a)
{
	double temp, temp2;
	bool swapp = true;
	while (swapp)
	{
		swapp = false;
		for (int i = 0; i < (a.size() - 1); i++)
		{
			temp = a[i];
			temp2 = a[i + 1];
			if (temp > temp2)
			{
				a[i] = temp2;
				a[i + 1] = temp;
				swapp = true;
			}
		}
		
	}

}

void insertionSort(vector<double> &a)
{
	int size = a.size();
	double j=0,temp=0;
	for (double i = 0; i < size; i++)
	{
		j = i-1;
		temp = a[i];
		while(j>=0 && a[j]>temp)
		{
			a[j + 1] = a[j];
				j = j - 1;

		}
		a[j + 1] = temp;
	}
}

void selectionSort(vector<double> &a)
{
	int  b = 0, min = 0, temp = 0;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (b = i + 1; b < a.size(); b++)
		{
			
			if (a[b] < a[min])
			{
				min = b;
			}
	
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}


vector<double> merge(vector<double> left, vector<double> right) // received help on this code from BogotoBogo.com. Modified the code found on this site. 
{																// The code will merge the vectors.https://www.bogotobogo.com/Algorithms/mergesort.php Once again
	vector<double> output;										// not my original code, found on the source above, and slightly modified to fit the lab and proper syntax
	while ((left.size() > 0) || (right.size() > 0))
	{
			if (left.size() > 0 && right.size() > 0)
			{
				if (left.front() <= right.front())
				{
					output.push_back(left.front());
					left.erase(left.begin());

				}
				else
				{
					output.push_back(right.front());
					right.erase(right.begin());
				}
			}
			else if (left.size() > 0)
			{
				for (int i = 0; i < left.size(); i++)
				{
					output.push_back(left[i]);
				
				}
			}
			else if (right.size() > 0)
			{
				for (int i = 0; i < right.size(); i++)
				{
					output.push_back(right[i]);
			}
				
			}

		
	}
	return output;
}



vector<double> mergeSort(vector<double> m) // also recieved help on this code from bogotogo.com. Modified the code found as it didnt account for the error that can occur when finding mid point.
{
	int middle = 0;
	vector<double> l, r, output;
	if (m.size() % 2 == 0)
	{
		middle = (m.size()) / 2;
	}
	else
	{
		middle = (m.size() + 1) / 2;
	}
	for (int i = 0; i < middle; i++) {
		l.push_back(m[i]);
	}

	for (int i = middle; i < (int)m.size(); i++) {
		r.push_back(m[i]);
	}

	l = mergeSort(l);
	r = mergeSort(r);
	output = merge(l, r);

	return output;
}

double partition(vector<double> &a, double l, double r) //recieved definition from http://notes4programs.blogspot.com/2013/05/quicksort.html
{
	double left = l, right = r;
	double x = a[left];
	while (left < right)
	{
		while (a[left] <= x)
		{
			left++;
			while (a[right] > x)
			{
				right++;
				if (left < right)
				{
					double temp = a[left];
					a[left] = a[right];
					a[right] = temp;
				}
			}
		}
	}
	double temp1 = a[l];
	a[l] = a[right];
	a[right] = temp1;
	return right;
}
void quickSort(vector<double> &a,double l,double r)	//recieved definition from http://notes4programs.blogspot.com/2013/05/quicksort.html
{
	double piv = partition(a, l, r);
	quickSort(a, l, piv - 1);
	quickSort(a, piv + 1, r);

}

