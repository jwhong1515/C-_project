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
	void push_front(T x) { //������ ���� ��
		if (isEmpty()) { //list�� ����� ��
			first = new MyLink(x, first, last);
			last = first;
		}
		else {
			MyLink* temp = new MyLink(x, first, 0);
			first = temp;
			temp = last; //temp ����
			while (temp->prev_ != 0) {
				temp = temp->prev_;
			}
			temp->prev_ = first;
		}
	}
	void push_back(T x) { //�Ʒ����� ���� ��
		if (isEmpty()) { //list�� ����� ��
			first = new MyLink(x, first, last);
			last = first;
		}
		else {
			MyLink* temp = new MyLink(x, 0, last);
			last = temp;
			temp = first; //temp ����
			while (temp->next_ != 0) {
				temp = temp->next_;
			}
			temp->next_ = last;
		}
	}
	void remove(T t) { //parameter�� �� �־�� ����?
		if (isEmpty()) { //list�� ����� ��
			return;
		}
		else if (first->next_ == 0 && last->prev_ == 0) { //list�� link�� 1���� ��
			delete first;
			first = 0;
			last = 0;
		}
		else { //list�� link�� 2�� �̻��� ��,
			if (first->data_ == t) { //�� ó���� ��ǥ�� ��
				MyLink* temp = first;
				first->next_->prev_ = 0;
				first = temp->next_;
				delete temp;
			}
			else if (last->data_ == t) { //�� �������� ��ǥ�� ��
				MyLink* temp = last;
				last->prev_->next_ = 0;
				last = temp->prev_;
				delete temp;
			}
			else { //ó���� ���� �ƴ� �� //�ּ� 3�� �̻��߿� ��� ��
				MyLink* temp = first;
				while (temp->next_->data_ != t) {
					temp = temp->next_;
				}
				//temp->next_ == target�� ��
				//temp == front�̹Ƿ�
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
			/* ������ ptr_�� ���� */
			ptr_ = ptr_->next_;
		}
		bool operator != (iterator x) {
			//������ ���� ��.
			return ptr_ != x.ptr_;
		}
		T& operator * () {
			// ������ ptr_�� ����Ű�� ���� ���� �����ش�.
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
			/* ������ ptr_�� ���� */
			ptr_ = ptr_->prev_;
		}
		bool operator != (reverse_iterator x) {
			//������ ���� ��.
			return ptr_ != x.ptr_;
		}
		T& operator * () {
			// ������ ptr_�� ����Ű�� ���� ���� �����ش�.
			return ptr_->data_;
		}
	};

	MyLink* first;
	MyLink* last;
public:
	iterator begin() {
		//first�� ������ ���� �ݺ��ڸ� ����� �����ش�.
		return iterator(first);
	}
	iterator end() {
		//0�� ������ ���� �ݺ��ڸ� ����� �����ش�.
		return iterator(0);
	}
	reverse_iterator rbegin() {
		//last�� ������ ���� �ݺ��ڸ� ����� �����ش�.
		return reverse_iterator(last);
	}
	reverse_iterator rend() {
		//0�� ������ ���� �ݺ��ڸ� ����� �����ش�.
		return reverse_iterator(0);
	}
};