#pragma once
	template<typename T>
	class LinkedList
	{
	private:
		template<typename T>
		class Node
		{
		public:
			Node<T>* prev;
			Node<T>* next;
			T* elem;

			Node()
			{
				prev = nullptr;
				next = nullptr;
				T = nullptr;
			}

			Node(T* elem, Node<T>* prev = nullptr, Node<T>* next = nullptr)
			{
				this->elem = elem;
				this->next = next;
				this->prev = prev;
			}

			Node<T>* GetPrev()
			{
				return this->prev;
			}

			void SetPrev(Node<T>* prev)
			{
				this->prev = prev;
			}

			Node<T>* GetNext()
			{
				return this->next;
			}

			void SetNext(Node<T>* next)
			{
				this->next = next;
			}

			T* GetElem()
			{
				return this->elem;
			}

			void SetElem(T* elem)
			{
				this->elem = elem;
			}

			~Node() {}
		};

		int size;
		Node<T>* head;
		Node<T>* tail;

	public:

		LinkedList()
		{
			size = 0;
			head = nullptr;
			tail = nullptr;
		}

		int GetSize()
		{
			return this->size;
		}

		void SetSize(int size)
		{
			this->size = size;
		}

		Node<T>* GetHead()
		{
			return this->head;
		}

		void SetHead(Node<T>* head)
		{
			this->head = head;
		}

		Node<T>* GetTail()
		{
			return this->tail;
		}

		void SetTail(Node<T>* tail)
		{
			this->tail = tail;
		}

		void AddElement(T* elem, int position)
		{
			Node<T>* tmp = new Node<T>(elem);
			int count = 0;

			if (size == 0)
			{
				head = new Node<T>(elem);
				tail = head;
			}
			else if (position == size)
			{
				tail->next = tmp;
				tail->next->prev = tail;
				tail = tmp;
			}
			else 
			{
				Node<T>* current = this->head;
				Node<T>* buffer = nullptr; 

				while (count != position)
				{
					current = current->next;
					count++;
				}
				buffer = current->prev;
				current->SetPrev(tmp);
				buffer->SetNext(tmp);
				tmp->next = current;
				tmp->prev = buffer;
			}

			size++;
		}


		void DeleteElement(int c)
		{
			Node<T>* tmp = this->head;
			int count = 1;

			if (head == tail)
			{
				delete tmp->elem;
				size--;
			}
			else
			{
				if (c == 1)
				{
					head = head->next;
					delete (head->prev)->elem;
					delete head->prev;
					head->prev = nullptr;
				}

				if (c == size)
				{

					tail = tail->prev;
					delete (tail->next)->elem;
					delete tail->next;
					tail->next = nullptr;
				}

				if ((c > 1) && (c < size))
				{
					while (count != c)
					{
						tmp = tmp->next;
						count++;
					}

					(tmp->prev)->SetNext(tmp->next);
					(tmp->next)->SetPrev(tmp->prev);
					delete tmp->elem;
					delete tmp;
				}
				size--;
			}
		}

		void PrintList()
		{
			Node<T>* tmp = this->GetHead();
			int position = 1;

			if (this->GetSize() == 0)
			{
				std::cout << std::endl;
				std::cout << "Список пуст." << std::endl << std::endl;
			}
			else
			{
				while (tmp != nullptr)
				{
					std::cout << position << ") ";
					T* elem1 = (tmp->elem);
					std::cout << *(tmp->elem);
					std::cout << std::endl;
					tmp = tmp->next;
					position++;
				}
			}

		}

		void PrintReversedList()
		{
			Node<T>* tmp = this->GetTail();
			int position = 1;

			if (this->GetSize() == 0)
			{
				std::cout << std::endl;
				std::cout << "Список пуст." << std::endl << std::endl;
			}
			else
			{
				while (tmp != nullptr)
				{
					std::cout << position << ") ";
					T* elem1 = (tmp->elem);
					std::cout << *(tmp->elem);
					std::cout << std::endl;
					tmp = tmp->prev;
					position++;
				}
			}
		}

		long GetSum()
		{
			int sum = 0;
			Node<T>* tmp = this->GetHead();

			if (this->GetSize() == 0)
			{
				std::cout << std::endl;
				std::cout << "Список пуст." << std::endl << std::endl;
			}
			else
			{
				while (tmp != nullptr)
				{
					sum += *(tmp->elem);
					tmp = tmp->next;
				}
			}

			return sum;
		}

		long SearchMax()
		{
			long max = -2147483637;

			Node<T>* tmp = this->GetHead();

			if (this->GetSize() == 0)
			{
				std::cout << std::endl;
				std::cout << "Список пуст." << std::endl << std::endl;
			}
			else
			{
				while (tmp != nullptr)
				{
					if (*(tmp->elem) > max)
						max = *(tmp->elem);
					tmp = tmp->next;
				}
			}

			return max;
		}

		long SearchMin()
		{
			long min = 2147483637;

			Node<T>* tmp = this->GetHead();

			if (this->GetSize() == 0)
			{
				std::cout << std::endl;
				std::cout << "Список пуст." << std::endl << std::endl;
			}
			else
			{
				while (tmp != nullptr)
				{
					if (*(tmp->elem) < min)
						min = *(tmp->elem);
					tmp = tmp->next;
				}
			}

			return min;
		}

		float CountAverageValue()
		{
			int sum = 0;
			Node<T>* tmp = this->GetHead();

			if (this->GetSize() == 0)
			{
				std::cout << std::endl;
				std::cout << "Список пуст." << std::endl << std::endl;
			}
			else
			{
				while (tmp != nullptr)
				{
					sum += *(tmp->elem);
					tmp = tmp->next;
				}
			}

			return (float)sum/(this->GetSize());
		}
		
		~LinkedList() {};
	};



