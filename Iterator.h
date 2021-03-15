#pragma once
template<typename T> class Node;
template<typename T>
class Iterator
{
public:
	Iterator(Node<T>* target): target_(target) {}

	T operator* ()
	{
		return target_->data_;
	}

	Iterator& operator++ ()
	{
		target_ = target_->next_;
		return *this;
	}
	Iterator operator+ (int rhs) const
	{
		Iterator result(*this);
		for (int i = 0; i != rhs && result != nullptr; ++i)
		{
			++result;
		}
		return result;
	}

	bool operator== (Iterator const& rhs) const
	{
		return (target_ == rhs.target_);
	}
	bool operator!= (Iterator const& rhs) const
	{
		return !(target_ == rhs.target_);
	}

private:
	Node<T>* target_;
};

