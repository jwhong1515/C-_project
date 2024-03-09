#pragma once

#include <iostream>
using namespace std;

template <class T>
class MyList {
public:
	class iterator;
	class reverse_iterator;

	class MyLink {
	public:
		T data_;
		MyLink* next_;
		MyLink* prev_;
		MyLink(T n, MyLink* nxt, MyLink* prv) : data_(n), next_(nxt), prev_(prv) {}
		//T& getdata() { return data_; }
		//MyLink* getnext() { return next_; }
		//MyLink* getprev() { return prev_; }
	};

	MyList() :first(0), last(0) {}

	bool isEmpty() {
		if (first == 0 && last == 0) {
			return true;
		}
		return false;
	}
	void push_front(T x) { //위에다 놓는 것
		if (isEmpty()) { //list가 비었을 때
			first = new MyLink(x, first, last);
			last = first;
		}
		else {
			MyLink* temp = new MyLink(x, first, 0);
			first = temp;
			temp = last; //temp 재사용
			while (temp->prev_ != 0) {
				temp = temp->prev_;
			}
			temp->prev_ = first;
		}
	}
	void push_back(T x) { //아래에다 놓는 것
		if (isEmpty()) { //list가 비었을 때
			first = new MyLink(x, first, last);
			last = first;
		}
		else {
			MyLink* temp = new MyLink(x, 0, last);
			last = temp;
			temp = first; //temp 재사용
			while (temp->next_ != 0) {
				temp = temp->next_;
			}
			temp->next_ = last;
		}
	}
	void remove(T t) { //parameter에 뭘 넣어야 하지?
		if (isEmpty()) { //list가 비었을 때
			return;
		}
		else if (first->next_ == 0 && last->prev_ == 0) { //list에 link가 1개일 때
			delete first;
			first = 0;
			last = 0;
		}
		else { //list에 link가 2개 이상일 때,
			if (first->data_ == t) { //맨 처음이 목표일 때
				MyLink* temp = first;
				first->next_->prev_ = 0;
				first = temp->next_;
				delete temp;
			}
			else if (last->data_ == t) { //맨 마지막이 목표일 때
				MyLink* temp = last;
				last->prev_->next_ = 0;
				last = temp->prev_;
				delete temp;
			}
			else { //처음과 끝이 아닐 때 //최소 3개 이상중에 가운데 쪽
				MyLink* temp = first;
				while (temp->next_->data_ != t) {
					temp = temp->next_;
				}
				//temp->next_ == target일 때
				//temp == front이므로
				MyLink* target = temp->next_;
				MyLink* back = target->next_;
				temp->next_ = target->next_;
				back->prev_ = target->prev_;
				delete target;
			}
		}
	}

	class iterator {
	private:
		MyLink* ptr_;
	public:
		iterator() { ptr_ = 0; }
		iterator(MyLink* pp) { ptr_ = pp; }
		void operator ++ (int a) {
			/* 포인터 ptr_를 변경 */
			ptr_ = ptr_->next_;
		}
		bool operator != (iterator x) {
			//포인터 값을 비교.
			return ptr_ != x.ptr_;
		}
		T& operator * () {
			// 포인터 ptr_가 가리키는 실제 값을 돌려준다.
			return ptr_->data_;
		}
	};

	class reverse_iterator {
	private:
		MyLink* ptr_;
	public:
		reverse_iterator() { ptr_ = 0; }
		reverse_iterator(MyLink* pp) { ptr_ = pp; }
		void operator ++ (int a) {
			/* 포인터 ptr_를 변경 */
			ptr_ = ptr_->prev_;
		}
		bool operator != (reverse_iterator x) {
			//포인터 값을 비교.
			return ptr_ != x.ptr_;
		}
		T& operator * () {
			// 포인터 ptr_가 가리키는 실제 값을 돌려준다.
			return ptr_->data_;
		}
	};

	MyLink* first;
	MyLink* last;
public:
	iterator begin() {
		//first를 값으로 갖는 반복자를 만들어 돌려준다.
		return iterator(first);
	}
	iterator end() {
		//0을 값으로 갖는 반복자를 만들어 돌려준다.
		return iterator(0);
	}
	reverse_iterator rbegin() {
		//last를 값으로 갖는 반복자를 만들어 돌려준다.
		return reverse_iterator(last);
	}
	reverse_iterator rend() {
		//0을 값으로 갖는 반복자를 만들어 돌려준다.
		return reverse_iterator(0);
	}
};