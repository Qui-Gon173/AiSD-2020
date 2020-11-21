#include "Turn.h"
Turn::Turn()
{
	// инициализируем пустую очередь
	tail = nullptr;
	head = nullptr;
	turnSize = 0;
}

// очистить очередь
void Turn::deleteTurn()
{
	// удалим через извлечение всех эл-ов
	this->getElem(turnSize);
	turnSize = 0;
}

// добавить элемент
void Turn::pushElem(float number)
{
	// выделяем память под новый элемент
	Element* newElem = new Element(nullptr, number);

	if (tail != nullptr)
	{
		// если очередь не пуста
		// предудыщий текущего последнего эл-а - это новый эл-т
		head->setPrev(newElem);
		// новый последний - это новый эл-т
		head = newElem;
		// у последнего нет предыдущего - nullptr
		head->setPrev(nullptr);

	}
	else
	{
		// если пуста
		// и начало и конец - это добавляемый эл-т
		head = newElem;
		tail = newElem;
	}
	turnSize++;
}

// добавить несколько элементов в качестве массива
void Turn::pushArr(float numbers[], int count)
{
	// вычисляем размер массива
	// добавляем каждый по отдельности
	for (int i = 0; i < count; i++)
	{
		this->pushElem(numbers[i]);
	}
}

// смотрим последний элемент
void Turn::checkLast()
{
	std::cout << tail->getData() << std::endl;
}

// печатаем все элементы
void Turn::printTurn()
{
	if (turnSize > 0)
	{
		// если очередь не пуста
	    // печатаем с tail
	    // заканчивая head - его prev = nullptr
		for (Element* current = tail; current != nullptr; current = current->getPrev())
		{
			std::cout << current->getData() << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Очередь пуста" << std::endl;
	}
	
}

// извлечь элемент
float Turn::getElem()
{
	// запоминаем число
	float element = tail->getData();
	
	// запоминаем прошлый элемент первого в очереди и удаляем первый
	// новый первый - это предыдущий эл-т старого 
	Element* buff = new Element(nullptr, 0);
	buff = tail->getPrev();
	delete tail;
	tail = buff;

	// уменьшаем кол-во эл-ов
	turnSize--;
	// возвращаем запомненное число
	return element;
}

// извлечь элементы - указать их количество
float* Turn::getElem(int count)
{
	float* resultArr = new float[count - 1];
	for (int i = 0; i < count; i++)
	{
		resultArr[i] = this->getElem();
	}
	return resultArr;
}

// перенести эл-ты - указать их количество
Turn Turn::transfer(int count)
{
	// новая очередь
	Turn newTorn;

	// извлекаем из старой очереди
	float* transferArr = new float[count - 1];
	transferArr = this->getElem(count);

	// добавляем эл-ы к новой очереди
	for (int i = 0; i < count; i++)
	{
		newTorn.pushElem(transferArr[i]);
	}
	// возвращаем её
	return newTorn;
}

void Turn::showCharacters()
{
	float sum = 0, avg = 0;
	float min, max;
	min = max = tail->getData();

	for (Element* current = tail; current != nullptr; current = current->getPrev())
	{
		// считаем сумму
		sum += current->getData();
	    // ищем max
		if (current->getData() > max)
		{
			max = current->getData();
		}
		// ищем min
		if (current->getData() < min)
		{
			min = current->getData();
		}
	}
	// считаем среднее
	avg = sum / turnSize;
	std::cout << "max = " << max << std::endl;
	std::cout << "min = " << min << std::endl;
	std::cout << "sum = " << sum << std::endl;
	std::cout << "avg = " << avg << std::endl;
}

// генерация арифметической последовательности
void Turn::generateArifm(float firstElem, float raznost, int count)
{
	// для функции pushArr
	float* arrToPush = new float[count];

	// создаём новую последовательность
	// её эл-ы добавляем в массив
	ArifmGenerator sequence(firstElem, raznost, count);
	int i = 0;
	for (ArifmGenerator::iterator item = sequence.begin(); item != sequence.end(); ++item)
	{
		arrToPush[i] = *item;
		i++;
	}

	//добавляем в текущую очередь последовательность
	this->pushArr(arrToPush, count);
}
