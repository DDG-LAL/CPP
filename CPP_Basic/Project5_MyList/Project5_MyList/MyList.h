#pragma once
#include<iostream>
#include<assert.h>
using std::cout;
using std::endl;

namespace MyList
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& val = T())
			: _data(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator //迭代器
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _it_node;

		__list_iterator(Node* it_node)
			: _it_node(it_node)
		{}

		Ptr operator->()
		{
			return &_it_node->_data; //返回值是_data的地址，再使用一次->运算符才能解引用
		}							 //所以it->a实际上是it->->a，编译器为了可读性省略了一个->

		Ref operator*()
		{
			return _it_node->_data;
		}
		self& operator++() //前置++
		{
			_it_node = _it_node->_next;
			return *this;
		}
		self operator++(int) //后置++
		{
			self tmp(_it_node);
			_it_node = _it_node->_next;
			return tmp;
		}
		self& operator--() //前置--
		{
			_it_node = _it_node->_prev;
			return *this;
		}
		self operator--(int) //后置--
		{
			self tmp(_it_node);
			_it_node = _it_node->_prev;
			return tmp;
		}
		bool operator==(const self& it)
		{
			return _it_node == it._it_node;
		}
		bool operator!=(const self& it)
		{
			return _it_node != it._it_node;
		}
	};

	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		const_iterator begin() const
		{
			//return const_iterator(_head->_next);
			return _head->_next;
		}
		const_iterator end() const
		{
			//return const_iterator(_head);
			return _head;
		}
		iterator begin()
		{
			//return iterator(_head->_next);
			return _head->_next;
		}
		iterator end()
		{
			//return iterator(_head);
			return _head;
		}

		size_t size()
		{
			return _size;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}
		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list() //构造
		{
			empty_init();
		}
		list(const list<T>& lt) //拷贝构造
		{
			empty_init();
			for (auto e : lt)
				push_back(e);
		}
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (auto e : lt)
		//			push_back(e);
		//	}
		//}
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void push_back(const T& val)
		{
			//Node* tail = _head->_prev;
			//Node* newnode = new Node(val);
			//tail->_next = newnode;
			//_head->_prev = newnode;
			//newnode->_next = _head;
			//newnode->_prev = tail;
			//--_size;

			insert(end(), val);
		}
		void push_front(const T& val)
		{
			insert(begin(), val);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* cur = pos._it_node;
			Node* prev = cur->_prev;
			newnode->_next = cur;
			newnode->_prev = prev;
			cur->_prev = newnode;
			prev->_next = newnode;
			++_size;
			//return iterator(newnode);
			return newnode;
		}
		iterator erase(iterator pos)
		{
			Node* del = pos._it_node;
			Node* next = del->_next;
			Node* prev = del->_prev;
			next->_prev = prev;
			prev->_next = next;
			delete del;
			--_size;
			//return iterator(next);
			return next;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
				it = erase(it);
		}

		~list() //析构
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	private:
		Node* _head;
		size_t _size;
	};
}

//template<typename T>
//void print_list(const list<T>& lt)
//{
//	typename list<T>::const_iterator it = lt.begin();
//	//此处的list<T>是未实例化的模板，编译器无法进入模板中查找const_iterator
//	//因此编译器无法确定list<T>::const_iterator是内嵌类型还是静态成员变量
//	//加typename表示此处是一个类型，需要等模板实例化之后进入模板再确定
//	//凡是类模板中取内嵌类型，都要在前面加typename
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

template<typename Container>
void print_container(const Container& con)
{
	typename Container::const_iterator it = con.begin();
	//此处的Container是未实例化的模板，编译器无法进入模板中查找const_iterator
	//因此编译器无法确定Container::const_iterator是内嵌类型还是静态成员变量
	//加typename表示此处是一个类型，需要等模板实例化之后进入模板再确定
	//凡是类模板中取内嵌类型，都要在前面加typename
	while (it != con.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}