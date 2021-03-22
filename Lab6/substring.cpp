#include <iostream>

int max(int a, int b)
{
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

int min(int a, int b)
{
    return -max(-a, -b);
}


struct string {
    char* str;
    size_t size;
    size_t capacity;

    string()
    {
        size = 0;
        str = new char [1];
        *str = '\0';
        capacity = 1;
        }  // Конструктор пустой строки

    string(size_t cnt, char c)
    {
        str = new char [2 * cnt];
        for (int i=0; i < cnt; ++i){
            str[i] = c;
        }
        str[cnt] = '\0';
        size = cnt;
        capacity = 2 * cnt;
    }  // Заполняющий конструктор

    string(const string& s)
    {
        size = s.size;
        capacity = s.capacity;
        str = new char [capacity];
        for (int i=0; i<capacity; ++i){
            str[i] = s.str[i];
        }
    }  // Копирующий конструктор

    string(char c)
    {
        //string(1, c);
        str = new char [2];
        str[0] = c;
        str[1] = '\0';
        size = 1;
        capacity = 2;

    }  // Конструктор строки из одного символа

    string(const char* c_str)
    {
        size_t I = 0;
        while(c_str[I]!= '\0'){
            I += 1;
        }
        size = I;
        capacity = 2*size+1;
        str = new char [capacity];
        for (int i=0; i<=size; ++i){
            str[i] = c_str[i];
        }
    }  // Конструктор строки из c-style строки (массива символов)

    ~string()
    {
        delete[] str;
    }     //очистить всю используемую память

    string& operator= (const string& new_str)
    {
        size_t new_capacity = max(capacity, new_str.capacity);
        size_t new_size = new_str.size;
        str = new char [new_capacity];
        for (int i=0; i<size;++i){
            str[i] = new_str.str[i];
        }
        return *this;
    }

    bool operator== (const string& other)
    {
        for (int i=0; i<size; ++i) {
            if (str[i] != other.str[i]){
                return false;
            }
        }
        return true;
    }

    bool operator!= (const string& other)
    {
        for (int i=0; i<size; ++i) {
            if (str[i] != other.str[i]){
                return true;
            }
        }
        return false;
    }

    bool operator> (const string& other)
    {
        for(int i = 0; i < min(size, other.size); ++i){
            if(str[i] > (other.str)[i]){
            return true;
            }
            else if(str[i] < (other.str)[i]){
                return false;
            }
        }
        if (size > other.size){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator< (const string& other)
    {
        for(int i = 0; i < min(size, other.size); ++i){
            if(str[i] < (other.str)[i]){
            return true;
            }
            else if(str[i] > (other.str)[i]){
                return false;
            }
        }
        if (size < other.size){
            return true;
        }
        else{
            return false;
        }
    }

    string& operator+= (const string& other)
    {
        append(other);
        return *this;
    }

    char operator[] (unsigned int pos)
    {
        return str[pos];
    } const

    void append(const string other)
    {
        size_t new_size = size + other.size;
        size_t new_capacity = 2*new_size;
        //char* old_str = str;
        char* new_str = new char [new_capacity];
        for (int i=0; i<size;++i){
            new_str[i] = str[i];
        }
        for (int i = size; i <= size + other.size; ++i){
            new_str[i] = other.str[i-size];
        }
        size = new_size;
        capacity = new_capacity;
        delete [] str;
        str = new_str;
    }  // дописать в конец данной строки другую

    void resize(unsigned int new_capacity)
    {
        //char* old_str = str;
        capacity = new_capacity;
        char* new_str = new char [capacity];
        size = min(size, capacity);
        for (int i=0; i<size;++i){
            new_str[i] = str[i];
        }
        new_str[size] = '\0';
        delete [] str;
        str = new_str;
    }  // увеличить/уменьшить емкость строки

    void reserve(unsigned int capacity)
    {
        resize(capacity);
    } // зарезервировать память в нужном объеме

    void insert(unsigned int pos, string other)
    {
        size += other.size;
        capacity += other.capacity;
        char* new_str = new char [capacity];
        int i;
        for(i = 0; i <= size; ++i){
            if( (i >= pos) && (i < pos + other.size)){
                new_str[i] = other.str[i-pos];
            }
            else{
                new_str[i] = str[i];
            }
        }
        delete [] str;
        str = new_str;
        ///size = new_size;
        ///capacity = new_capacity;
    }  // Вставка другой строки внутрь данной

    void shrink_to_fit()
    {
        char* new_str = new char [size+1];
        for(int i = 0; i <= size; ++i){
            new_str[i] = str[i];
        }
        delete [] str;
        str = new_str;
        capacity = size;
    }  //очистить неиспользуемую память

    void clear()
    {
        size = 0;
        str[0] = '\0';
    }   //очистить содержимое строки, занимаемое место при этом не меняется

    friend std::ostream& operator<< (std::ostream& ostr, const string& str)
    {
        return ostr << str.str;
    }
    friend std::istream& operator>> (std::istream& istr, const string& str)
    {
        return istr >> str.str;
    }

};

string operator + (const string& str1, const string& str2)
{
    string s = str1;
    s += str2;
    return s;
}


int stoi(const string str, size_t pos = 0, int base = 10 );
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.

int main()
{
    string s1 = "123abcdef";
    //string s2;
    //std::cout << s1 << '\n';
    //std::cin >> s2;
    //std::cout << s2 << '\n';
    string s_copy = s1;
    std::cout << s_copy << '\n';

    string s3(s1);
    std::cout << s3 << '\n';

    string s4(5, 'o');
    std::cout << s4 << '\n';

    string s5('V');
    std::cout << s5 << '\n';

    string s6 = 'V';
    std::cout << (s6==s5) << '\n';

    string s7 = "123abcdf";
    std::cout << (s7 < s1) << '\n';

    std::cout << (s7 += s1) << '\n';

    s7.insert(4, s6);
    std::cout << s7 << '\n';

    s7.clear();
    std::cout << s7 << '\n';

    std::cout << (s6 + s4) << '\n';

    return 0;
}
