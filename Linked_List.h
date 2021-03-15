#pragma once
#include<cassert>
#include "Node.h"
template <typename T> class Iterator;
template <typename T> class Node;
template<typename T>
class Linked_List
{
public:
	Linked_List()
	{
		first_ = new Node<T>;
		last_ = first_;
	}
	~Linked_List()
	{
		Node<T>* i = first_;
		while (i != last_)
		{
			Node<T>* j = i->next_;
			delete i;
			i = j;
		}
		delete i;
	}
	Linked_List(Linked_List const& old): size_ (old.size_)
	{
		first_ = new Node<T>;
		Node<T>* i = first_;
		Node<T>* j = old.first_;
		while (j = j->next_) //assign j to j->next and check if it exists
		{
			i->next_ = new Node<T>(*j);
			i = i->next_;
		}
		last_ = i;
	}
	Linked_List& operator= (Linked_List const& rhs)
	{
		if (this == &rhs)
			return *this;

		Node<T>* i = first_;
		while (i != last_)
		{
			Node<T>* j = i->next_;
			delete i;
			i = j;
		}
		delete i;

		first_ = new Node<T>;
		Node<T>* i = first_;
		Node<T>* j = rhs.first_;
		while (j = j->next_) //assign j to j->next and check if it exists
		{
			i = new Node<T>(j);
		}
		last_ = i;

		return *this;
	}
	int size() const { return size_; }
	bool empty() const { return !size_; }
	void push_back(T const& input)
	{
		++size_;
		last_->next_ = new Node<T>(input);
		last_ = last_->next_;
	}
	Iterator<T> insert(int position, T const& input)
	{
		assert(position < size_ && position >= 0);
		Node<T>* old_node = get(position);
		Node<T>* new_node = new Node<T>(input);
		new_node->next_ = old_node->next_;
		old_node->next_ = new_node;
		++size_;
		return Iterator<T>(new_node);
	}
	void remove(int position)
	{
		assert(position < size_ && position >= 0);
		--size_;
		Node<T>* i = get(position - 1);
		if (i->next_ == last_)
		{
			delete last_;
			last_ = i;
		}
		else
		{
			Node<T>* j = i->next_->next_;
			delete i->next_;
			i->next_ = j;
		}
	}
	T& front() { return first_->next_->data_; }
	T& back() { return last_->data_; }
	T const& front() const { return first_->next_->data_; }
	T const& back() const { return last_->data_; }
	Iterator<T> begin() const { return Iterator<T>(first_->next_); }
	Iterator<T> end() const { return Iterator<T>(last_); }
private:
	friend class Iterator<T>;
	Node<T>* first_;
	Node<T>* last_;
	int size_ = 0;
	Node<T>* get(int pos)
	{
		assert(pos < size_ && pos >= -1);
		Node<T>* node = first_;
		for (int i = -1; i < pos; ++i) // If the inout is -1 we want to return the dummy node. This will be used by the removal method which needs the node prior to the removed node.
		{
			node = node->next_;
		}
		return node;
	}
};

