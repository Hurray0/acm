int erfen(int a[], int start,int end)
{
	int middle = (int)(start + end)/2;
	if(middle == a[middle])
		return middle;
	else if(middle > a[middle])
		return erfen(int a[], start, middle-1);
	else
		return erfen(int a[], middle+1, end);
}