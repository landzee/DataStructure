#include <iostream>
#include <stdexcept>
using namespace std;

//线性表中的顺序表
//时间复杂度比链表高

template <typename T>
class LinearList {
private:
    T* data;           // 存储数据的数组
    int capacity;      // 容量
    int length;        // 当前长度

public:
    // 构造函数
    //传参赋值默认值，调用时如果不输入参数就是默认值赋值
    LinearList(int cap = 10) : capacity(cap), length(0) {
        data = new T[capacity];
    }

    // 析构函数
    ~LinearList() {
        delete[] data;
    }

    // 拷贝构造函数
    LinearList(const LinearList& other) : capacity(other.capacity), length(other.length) {
        data = new T[capacity];
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    // 赋值运算符重载
    LinearList& operator=(const LinearList& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            length = other.length;
            data = new T[capacity];
            for (int i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // 获取线性表长度
    int size() const {
        return length;
    }

    // 判断线性表是否为空
    bool empty() const {
        return length == 0;
    }

    // 在指定位置插入元素
    // 如果在第一个位置插入，那时间复杂度是O(n)
    void insert(int index, const T& element) {
        if (index < 0 || index > length) {
            throw out_of_range("Index out of range");
        }
        if (length >= capacity) {
            resize();
        }
        for (int i = length; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = element;
        length++;
    }

    // 在末尾添加元素
    void push_back(const T& element) {
        insert(length, element);
    }

    // 删除指定位置的元素
    void remove(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }

    // 获取指定位置的元素
    T& get(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // 获取指定位置的元素（常量版本）
    const T& get(int index) const {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // 查找元素，返回第一次出现的位置
    int find(const T& element) const {
        for (int i = 0; i < length; i++) {
            if (data[i] == element) {
                return i;
            }
        }
        return -1; // 未找到返回-1
    }

    // 清空线性表
    void clear() {
        length = 0;
    }

    // 重载[]运算符
    T& operator[](int index) {
        return get(index);
    }

    // 重载[]运算符（常量版本）
    const T& operator[](int index) const {
        return get(index);
    }

    // 打印线性表内容
    void display() const {
        cout << "Linear List: ";
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    // 扩容函数
    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};

// 使用示例
int main() {
    LinearList<int> list;
    
    // 添加元素
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    // 显示列表
    list.display(); // 输出: Linear List: 1 2 3
    // 插入元素
    list.insert(1, 10);
    list.display(); // 输出: Linear List: 1 10 2 3
    
    // 获取元素
    cout << "Element at index 2: " << list.get(2) << endl; // 输出: Element at index 2: 2
    
    // 查找元素
    int index = list.find(10);
    cout << "Index of 10: " << index << endl; // 输出: Index of 10: 1
    
    // 删除元素
    list.remove(0);
    list.display(); // 输出: Linear List: 10 2 3
    
    return 0;
}