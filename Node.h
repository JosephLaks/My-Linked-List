#pragma once
template<typename T> class Linked_List;
template<typename T> class Iterator;
template<typename T>
class Node
{
private:
	Node() = default;
	Node(T data) : data_(data) {}
	Node(Node const& old) = default;
	T data_;
	Node<T>* next_ = nullptr;
	friend class Linked_List<T>;
	friend class Iterator<T>;
};