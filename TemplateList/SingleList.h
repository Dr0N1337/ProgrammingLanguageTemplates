#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

namespace rut::miit
{
	template<typename T>
	struct Node
	{
		/*
		@brief �������, ������������� �������� ==.
		@param ������ ������, ������� ����� ����������� �� ����� Node.
		*/
		void operator= (const T& otherData);

		/*
		@brief �������, ������������� �������� [].
		@param ������ ������������ � Node.
		@param pNext ��������� �� ��������� Node.
		*/
		Node(T& data = 0, Node<T>* pNext = nullptr);

		Node<T>* pNext;
		T data;
	};


	template <typename T>
	class SingleList
	{
	public:
		/*
		@brief �������������� ����� SingleList.
		*/
		SingleList();

		/*
		@brief ���������� ������ SingleList.
		*/
		~SingleList();

		/*
		@brief �������� ������ ������ SingleList.
		@param ������ ����, ������� ����� ����������.
		*/
		SingleList(const SingleList& second);

		/*
		@brief ���������� ������ ������ SingleList � ������ �����.
		@param ������ ����, ������� ����� ���������.
		*/
		SingleList(SingleList&& second) noexcept;

		/*
		@brief �������, ������� ������� Node ����� �������.
		*/
		void popFront();

		/*
		@brief ������� ��� Node.
		*/
		void clear();

		/*
		@brief ������� ������� ��������� Node � ����� ������.
		@param ������ ������� ����� ���������.
		*/
		void pushBack(T data);

		/*
		@brief ������� ������� ��������� Node ����� �������.
		@param ������ ������� ����� ���������.
		*/
		void pushFront(T data);

		/*
		@brief ������� ������� ���������� ������ �����.
		@return ������ ������.
		*/
		size_t getSize() const noexcept;

		/*
		@brief �������, ������������� �������� [].
		@param ����������� ����� ��������.
		@return �������� � �������� ��������.
		*/
		T& operator[](int index);

		/*
		@brief �������, ������� ��������� ������ ���������.
		@return �������� true, ���� ��������� �������, �������� false, ���� ��������� �� �������.
		*/
		bool isEmpty() const noexcept;

		/*
		@brief �������, ������� ����������� ��������� � ������.
		@return ������, ��������� �� Nodes.
		*/
		std::string toString();

		/*
		@brief �������, ������������� �������� ==.
		@param ������ ������, ������� ����� ����������.
		@return ����� ������������� ������.
		*/
		SingleList<T>& operator=(const SingleList<T>& second);

		/*
		@brief �������, ������������� �������� ==.
		@param ������ ������, ������� ����� ���������.
		@return ������������ ������.
		*/
		SingleList<T>& operator=(SingleList<T>&& second) noexcept;

		/*
		@brief �������, ������������� �������� ���������.
		@param ���������� ������ ������.
		@return ���� ���������� ������ ����� ������� ������ �� �������� true � � ��������� ������ �������� false.
		*/
		bool operator==(SingleList<T>& second);

	private:
		size_t size;
		Node<T>* head;
	};

	template <typename T>
	Node<T>::Node(T& data, Node* pNext)
		: data(data), pNext(pNext)
	{
	}

	template <typename T>
	void Node<T>::operator=(const T& otherData)
	{
		this->data = otherData;
	}

	template <typename T>
	SingleList<T>::SingleList()
		:head(nullptr), size(0)
	{
	}

	template <typename T>
    void SingleList<T>::pushBack(T data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
		}
		else
		{
			Node<T>* current = head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(data);
		}
		this -> size++;
	}

	template <typename T>
	void SingleList<T>::pushFront(T data)
	{
		head = new Node<T>(data, head);
		this -> size++;
	}

	template <typename T>
	size_t SingleList<T>::getSize() const noexcept
	{
		return this->size;
	}

	template <typename T>
	T& SingleList<T>::operator[](int index)
	{
		int counter = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}

	template <typename T>
	bool SingleList<T>::isEmpty() const noexcept
	{
		return this->size == 0;
	}

	template <typename T>
	std::string SingleList<T>::toString()
	{
		std::stringstream buffer;
		if (head != nullptr)
		{
			Node<T>* current = head;
			for (size_t i = 0; i < size; i++)
			{
				buffer << current->data << ' ';
				current = current->pNext;
			}
		}
		return buffer.str();
	}

	template <typename T>
	void SingleList<T>::popFront()
	{
		if (head != nullptr)
		{
			Node<T>* temp = head;
			head = head->pNext;
			this -> size--;
			delete temp;
		}
	}

	template <typename T>
	void SingleList<T>::clear()
	{
		while (size)
		{
			popFront();
		}
	}

	template <typename T>
	SingleList<T>::~SingleList()
	{
		clear();
	}

	template <typename T>
	SingleList<T>::SingleList(SingleList&& second) noexcept
	{
		std::swap(this->head, second.head);
	}

	template <typename T>
	bool SingleList<T>::operator==(SingleList<T>& second)
	{
		return(this->toString() == second.toString());
	}

	template <typename T>
	SingleList<T>& SingleList<T>::operator=(const SingleList<T>& second)
	{
		if (this->head == nullptr)
		{
			for (Node<T>* node = second.head; node != nullptr; node = node->pNext)
			{
				this->pushBack(node->data);
			}
		}
		return *this;
	}

	template <typename T>
	SingleList<T>& SingleList<T>::operator=(SingleList<T>&& second) noexcept
	{
		std::swap(this->head, second.head);
		return *this;
	}

	template <typename T>
	SingleList<T>::SingleList(const SingleList<T>& second)
	{
		if (this->head == nullptr)
		{
			for (Node<T>* node = second.head; node != nullptr; node = node->pNext)
			{
				this->pushBack(node->data);
			}
		}
	}
}