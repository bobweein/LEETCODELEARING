#include <iostream>
const int Infinity = 6666;
typedef int  Typename;
void Merge (Typename* A,int p,int q,int r)
{
	int n1 = q - p +1;
	int n2 = r - q;
	Typename* L=new Typename[n1+1];
	Typename* R=new Typename[n2+1];
	int i=0,j=0,k=0;
	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + j+1];
	L[n1] = Infinity;
	R[n2] = Infinity;
	i = j = 0;
	for (k = p; k <=r; k++)
	{
		if (L[i]<=R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
		std::cout << A[k] << "  ";
		
	}
	std::cout << "\n\n";
	delete[]L;
	delete[]R;
}
void MergeSort(Typename* A, int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		/*for (int k = p; k <= r; k++)
			std::cout << A[k] << "  ";
		std::cout << "\n";*/
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}
int main()
{
	int A[8] = {5,2,4,7,1,3,2,6};
	MergeSort(A, 0, 7);
	for (int i = 0; i < 8; i++)
		std::cout << A[i] << "\t";
	std::cout<<std::endl;
	return 0;

}
