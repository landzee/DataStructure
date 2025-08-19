#include <iostream>
#include <vector>
// using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node<T> *next;

        /**
         * @brief 构造函数，用于创建一个新节点
         * @param data 节点存储的数据值
         * @return 无返回值
         * 
         * 该构造函数初始化节点的数据域和指针域，
         * 将数据域设置为传入的参数值，将指针域初始化为空指针
         */
        Node(T data){
                    this->data = data;
                    this->next = NULL;
        }
        Node() : data{}, next(nullptr) {}//用于给头节点定义
};

template<class T>
class LinkedList{
    private:
        Node<T>* head = new Node<T>();//头指针位置为0，头插法插在head后面，位置为1
    public:
        LinkedList(){
            head->next = NULL;
        }

    /**
     * @brief 在链表头部后一位插入新节点
     * head保持在第一位，头部插入在第二位。
     * @param data 要插入的数据
     */
    void insertHead(T data){
        Node<T>* newNode = new Node<T>(data);
        if(head->next != NULL)newNode->next = head->next;
        head->next = newNode;
    }

    /// @brief 在链表尾部插入新节点
    /// @param data 要插入的数据
    void insertTail(T data){ 
        Node<T>* newNode = new Node<T>(data);
        Node<T>* cur = head;
        //用cur指针找到链表尾部
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newNode;//在尾部插入新节点
    }

    /// @brief 在指定位置插入新节点
    /// @param pos 要插入的位置
    /// @param data 要插入的数据
    void insert(int pos, T data){
        if(pos<=0){
            std::cout<<data<<"的插入位置不合法"<<std::endl;
            return;
        }
        else{
            Node<T>* newNode = new Node<T>(data);
            Node<T>* cur = head;
            for(int i=1; i<pos; i++){
                cur = cur->next;
                if(cur == NULL){
                    std::cout<<data<<"的插入位置不合法"<<std::endl;
                    return;
                }
            }
            newNode->next = cur->next;//将pos-1的next指针赋值给新节点的next指针
            cur->next = newNode;
        }

        
    }

    /// @brief 删除指定位置的节点
    /// @param pos 删除节点位置
    void deleteNodePos(int pos){
            Node<T>* cur = head;//head位置是0
            if(pos <= 0){
                std::cout<<"删除位置不合法"<<std::endl;
                return;
            }
            else{
                for(int i = 1;i < pos;i++){
                    if(cur->next == NULL){
                        std::cout<<"删除位置不合法"<<std::endl;
                        return;
                    }
                    cur = cur->next;
                }//选中要删除的节点的前一个节点
                Node<T>* del = cur->next;
                cur->next = del->next;
            }
    }
    /// @brief 删除链表中所有指定元素
    /// @param data 要删除的元素
    void deleteNodeData(T data){ 
        Node<T>* cur = head->next;
        Node<T>* pre = head;

        while(cur != NULL){
            if(cur->data == data){
                pre->next = cur->next;
            }
            pre = cur;
            cur = cur->next;
        }
    }

    /**
     * 查找链表中所有等于指定数据值的节点位置
     * @param data 要查找的数据值
     * @return 包含所有匹配节点位置的向量，位置从1开始计数
     */
    std::vector<int> findAllNodePos(T data) {
        std::vector<int> positions;
        Node<T>* cur = head->next;
        int pos = 1;
        // 遍历链表查找匹配的节点
        while (cur != nullptr) {
            // 如果当前节点数据匹配，记录位置
            if (cur->data == data) {
                positions.push_back(pos);
            }
            cur = cur->next;
            pos++;
        }
        return positions;
    }

    /**
     * 获取链表指定位置的数据元素
     * @param pos 要获取数据的位置，从1开始计数
     * @return 返回指定位置的数据元素
     * @throws std::out_of_range 当位置不合法或超出链表长度时抛出异常
     */    
    T getData(int pos){
        if(pos <= 0){
            throw std::out_of_range("查找位置不合法");
        }
        Node<T>* cur = head;
        for(int i = 0; i < pos; i++){
            if(cur->next == nullptr){
                throw std::out_of_range("查找位置超过链表长度");
            }
            cur = cur->next;
        }
        return cur->data;
    }

    /// @brief 输出链表
    void printList(){
        Node<T>* cur = head;
        cur = cur->next;
        while(cur != NULL){
            std::cout<<cur->data<<" ";
            cur = cur->next;
        }
        std::cout<<std::endl;
    }
};

int main(){
    LinkedList<std::string> book;
    book.insertHead("microsoft");
    book.insertHead("apple");
    book.insertTail("google");
    book.insert(3,"baidu");
    book.insertTail("baidu");
    book.printList();

    std::vector<int> positions = book.findAllNodePos("baidu");

    /** print all positions
     * 初始化   |auto it = positions.begin()	|创建迭代器 it 指向容器起始位置
     * 条件检查	|it != positions.end()	        |检查是否到达容器末尾
     * 迭代	    |++it	                        |将迭代器移动到下一个元素
     * 循环体	|std::cout << *it << " ";	    |输出当前元素值
    */
    for (auto it = positions.begin(); it != positions.end(); ++it) {
    std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::string posdata = book.getData(2);
    std::cout << posdata << std::endl;

    return 0;
}