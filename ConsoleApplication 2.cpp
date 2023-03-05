#include<iostream>
#include<vector>
using namespace std;


class AbstractContainer {
public:
	virtual int Size() const = 0;
	virtual bool IsEmpty() const = 0;
};

class AbstractStack : public AbstractContainer {
public:
	virtual void Push(int value) = 0;
	virtual void Pop() = 0;
	virtual int Top() const = 0;
};

class LimitedArrayStack : public AbstractStack {
public:
	LimitedArrayStack(int limit) : array_(new int[size_]), size_(0) {
		limit_ = limit;
		cin >> size_;
		if (size_ >= limit_) {
			cout << " Oblast " << endl;
		}
		for (int i = 0; i < size_; i++) {
			cin >> array_[i];
		}
	}
	void Push(int value) {
		size_ = size_ + 1;
		array_[size_ - 1] = value;
		if (size_ >= limit_) {
			cout << " Oblast " << endl;
		}
	}
	void Pop() {
		size_ = size_ - 1;
		array_[size_];
	}
	int Top() const {
		return array_[size_ - 1];
	}
	bool IsEmpty() const {
		if (size_ == 0) return false;
		return true;
	}
	int Size() const {
		return size_;
	}
	void Print() {
		for (int i = 0; i < size_; i++) {
			cout << array_[i] << " " << endl;
		}
	}
private:
	int* array_;
	int size_;
	int limit_;
};



	class UnlimitedArrayStack : public AbstractStack {
	public:
		UnlimitedArrayStack() : array_(new int[size_]), size_(0) {
			cin >> size_;
			for (int i = 0; i < size_; i++) {
				cin >> array_[i];
			}
		}
		void Push(int value) {
			size_ = size_ + 1;
			array_[size_ - 1] = value;
		}
		void Pop() {
			size_ = size_ - 1;
			array_[size_];
		}
		int Top() const {
			return array_[size_ - 1];
		}
		bool IsEmpty() const {
			if (size_ == 0) return false;
			return true;
		}
		int Size() const {
			return size_;
		}
		void Print() {
			for (int i = 0; i < size_; i++) {
				cout << array_[i] << " " << endl;
			}
		}
	private:
		int* array_;
		int size_;
	};

	class Queue : public AbstractStack {
	public:
		Queue() : array_(new int[size_]), size_(0) {
			cin >> size_;
			for (int i = 0; i < size_; i++) {
				cin >> array_[i];
			}
		}
		void Push(int value) {
			size_ = size_ + 1;
			array_[size_ - 1] = value;
		}
		void Pop() {
			int size_2;
			size_2 = size_;
			int* b = new int[size_2];
			for (int t = 0; t < size_2; t++) {
				b[t] = array_[t + 1];
			}
			size_ = size_ - 1;
			for (int s = 0; s < size_; s++) {
				array_[s] = b[s];
			}
		}
		int Top() const {
			return array_[0];
		}
		bool IsEmpty() const {
			if (size_ == 0) return false;
			return true;
		}
		int Size() const {
			return size_;
		}
		void Print() {
			for (int i = 0; i < size_; i++) {
				cout << array_[i] << " " << endl;
			}
		}
	private:
		int* array_;
		int size_;
	};



	int main() {
		LimitedArrayStack Lstack = LimitedArrayStack(5);
		cout << Lstack.Size() << endl;
		cout << " Empty or not = " << Lstack.IsEmpty() << endl;
		Lstack.Pop();
		Lstack.Push(8);
		Lstack.Print();
		cout << Lstack.Top() << endl;
		UnlimitedArrayStack Ustack;
		cout << Ustack.Size() << endl;
		cout << " Empty or not = " << Ustack.IsEmpty() << endl;
		Ustack.Pop();
		Ustack.Push(12);
		Ustack.Print();
		cout << Ustack.Top();
		Queue q;
		q.Pop();
		q.Print();
		q.Push(6);
		q.Print();
		cout << q.Top() << endl;
	}
