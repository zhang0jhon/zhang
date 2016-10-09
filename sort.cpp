#include<iostream>
#include<functional>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

void stl_heapsort(int *a, int length){
	multiset<int, greater<int> > set;
	multiset<int, greater<int> >::iterator iter;
	for (int i = 0; i < length; i++){
		set.insert(a[i]);
	}
	for (iter = set.begin(); iter != set.end(); iter++){
		cout << *iter << " ";
	}
}

void quick_sort(int *a, int left, int right){
	if (left < right){
		int i = left, j = right, temp = a[left];
		while (i < j){
			while (i<j&&a[j]>temp)
				j--;
			if (i < j)
				a[i++] = a[j];

			while (i < j&&a[i] < temp)
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = temp;
		quick_sort(a, left, i - 1);
		quick_sort(a, i + 1, right);
	}
}

void max_heapify(int *a, int start, int end){
	int dad = start;
	int son = 2 * dad + 1;
	while (son <= end){
		if (son + 1 <= end&&a[son] < a[son + 1])
			son++;
		if (a[dad] > a[son])
			return;
		else{
			swap(a[dad], a[son]);
			dad = son;
			son = 2 * dad + 1;
		}
	}
}
void heap_sort(int *a, int len){
	int i;
	for (i = len / 2 - 1; i >= 0; i--)
		max_heapify(a, i, len - 1);
	for (i = len - 1; i > 0; i--){
		swap(a[0], a[i]);
		max_heapify(a, 0, i - 1);
	}
}

void merge(int *arr, int *a, int start, int end){
	if (start >= end) return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge(arr, a, start1, end1);
	merge(arr, a, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2)
		a[k++] = (arr[start1]<arr[start2]) ? arr[start1++] : arr[start2++];
	while (start1 <= end1)
		a[k++] = arr[start1++];
	while (start2 <= end2)
		a[k++] = arr[start2++];
	for (k = start; k <= end; k++)
		arr[k] = a[k];
}
void merge_sort(int *arr, int len){
	int *a = new int[len];
	merge(arr, a, 0, len - 1);
	delete[] a;
}

void merge_sort1(int arr[], int len) {
	int* a = arr;
	int* b = new int[len];
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}

int partition(int *a, int left, int right){
	int low = left, high = right, temp = a[left];
	while (low < high){
		while (low<high&&a[high]>temp)
			high--;
		if (low < high)
			a[low++] = a[high];
		while (low < high&&a[low] < temp)
			low++;
		if (low < high)
			a[high--] = a[low];
	}
	a[low] = temp;
	return low;
}
int topk(int *a, int n,int k){
	int index = partition(a, 0, n - 1);
	while (index != k - 1){
		if (index > k - 1){
			index = partition(a, 0, index - 1);
		}
		else{
			index = partition(a, index + 1, n - 1);
		}
	}
	return a[k - 1];
}

int stl_topk(int *a,int n,int k){
	multiset<int, greater<int>> set;
	multiset<int, greater<int>>::iterator iter;
	int res;
	for (int i = 0; i < n - 1; i++){
		if (set.size() < k){
			set.insert(a[i]);
		}
		else{
			iter = set.begin();
			if ((*iter) > a[i]){
				set.erase(iter);
				set.insert(a[i]);
			}
		}
	}
	iter = set.begin();
	res = *iter;
	return res;
}

int main(){
	int a[10] = { 1,2, 4, 7, 8, 9,  5, 6, 3 ,10};
	for (int i = 0; i < 10; i++)
	cout << a[i]<<" ";
	cout << endl;
	//quick_sort(a, 0, 9);
	//heap_sort(a, 10);
	//merge_sort1(a, 10);
	
	int res = stl_topk(a, 10, 6);
	cout << res << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	//stl_heapsort(a, 10);


	system("pause");
}








/*
class A{
public:
	A(){
		cout << "A" << endl;
	}

	A(const A &rhs){
		cout << "A copy" << endl;
	}
	A& operator=(const A &rhs){
		
		this->a = rhs.a;
		cout << "A =====" << endl;
		return *this;
	}

	~A(){
		cout << "~~~~A" << endl;
	}
private:
	int a;
};

class B : public A{
public:
	B():A(){
		cout << "B" << endl;
	}

	B(const B &rhs):A(rhs){
		cout << "B copy" << endl;
	}

	B& operator=(const B &rhs){
		A::operator=(rhs);
		this->b = rhs.b;
		cout << "B =====" << endl;
		return *this;
		
	}

	~B(){
		cout << "~~~~~B" << endl;
	}
private:
	int b;
};

void test(){	
	B b;
	B b1;
	b1 = b;

	
}

int main(){
	test();

	system("pause");
	return 0;
}
*/