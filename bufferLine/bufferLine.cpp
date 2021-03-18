// bufferLine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
constexpr auto SIZE_ARR = 10;


class BuferLine
{
    public:
        BuferLine();
        ~BuferLine();
        void buffer_init();
        void push_back(int &data);
        void pop_front();
        void print_buffer();
        bool is_empty();
        void print_all();

    
    private:

        int arr[SIZE_ARR]{};
        int head;
        int tail;
};

void mng(BuferLine* q);



int main()
{
    /*int m[] = { 1,2,3,4 };
    BuferLine Q;

    if (Q.is_empty())
    {
        std::cout << "Q empty" << '\n';
    }
    else
    {
        std::cout << "Q No empty" << '\n';
    }

    for (int i = 0; i < sizeof(m)/sizeof(m[0]);i++)
    {
        Q.push_back(m[i]);
    }*/

    BuferLine Q;
    mng(&Q);
    
 
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

BuferLine::BuferLine()
{
   buffer_init();
}

BuferLine::~BuferLine()
{
}

void BuferLine::buffer_init()
{
    this->head = 1;
    this->tail = NULL;
}

void BuferLine::push_back(int &data)
{
    if (this->tail < SIZE_ARR)
    {
        this->arr[this->tail] = data;
        this->tail += 1;
    }
    else if (is_empty())
    {
        buffer_init();
		arr[tail] = data;
		this->tail += 1;
    }
    else
    {
        std::cout << "Queue full "<< '\n';
    }
    
}

void BuferLine::pop_front()
{
    int data_local = 0;

    if (!is_empty())
    {
        data_local = this->arr[this->head - 1];
        this->head += 1;
        std::cout<< "    "<< data_local<< '\n';

    }
    else
    {
        this->buffer_init();
    }


    //return 0;
}



void BuferLine::print_buffer()
{
    for (int i = this->head - 1; i < this->tail; i++)
    {
        std::cout << this->arr[i]<< " ";
    }
}

bool BuferLine::is_empty()
{
    if (this->head <= this->tail)
    {
        return false;
    } 
    else
    {
        return true;
    }
    
}

void BuferLine::print_all()
{
    for (int i = 0; i < SIZE_ARR; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}


void mng(BuferLine* q)
{
    int marker_out = 1;
    int sw_marker = 0;
    while (marker_out)
    {
        switch (sw_marker)
        {
        case 0: {
            std::cout << "Add press 1 " << '\n';
            std::cout << "Remove press 2 " << '\n';
            std::cout << "Exit program press 3 " << '\n';
            std::cout << "Repeat press 0 " << '\n';
            std::cin >> sw_marker;
                }
              break;
        case 1: {
            int temp = 0;
            std::cin >> temp;
            std::cout <<"Before push_back "<< "================================" << '\n';
            std::cout << "PrinALL " << '\n';
            q->print_all();
            std::cout << "PrinBody " << '\n';
            q->print_buffer();
            std::cout<<'\n'<< "================================" << '\n';
            q->push_back(temp);

			std::cout << "After push_back " << "================================" << '\n';
			std::cout << "PrinALL " << '\n';
			q->print_all();
			std::cout << "Print Body "<<'\n';
			q->print_buffer();
            std::cout <<'\n'<< "=========================================================" << '\n';
            std::cout << "Exit Main Menu Press 0, Add Next Element Press 1 " << '\n';
            std::cin >> sw_marker;
            system("cls");
            
        }
            break;
        case 2: {
			std::cout << "Before POP_FRONT " << "================================" << '\n';
			std::cout << "PrinALL " << '\n';
			q->print_all();
			std::cout << "PrinBody " << '\n';
			q->print_buffer();
			std::cout << '\n' << "================================" << '\n';
            q->pop_front();

			std::cout << "After POP_FRONT " << "================================" << '\n';
			std::cout << "PrinALL " << '\n';
			q->print_all();
			std::cout << "PrinBody " << '\n';
			q->print_buffer();
         
			std::cout <<'\n'<<"=========================================================" << '\n';
			std::cout << "Exit Main Menu Press 0, Remove Next Element Press  " << '\n';
			std::cin >> sw_marker;
            system("cls");
        }
            break;
        case 3: marker_out = 0;
            break;
        
        }
    }
}