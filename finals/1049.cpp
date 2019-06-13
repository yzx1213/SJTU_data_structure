#include <iostream>

using namespace std;

template <class T>
class seqStack {
   private:
    T* data;
    int nowSize;
    int maxSize;
    void doublespace();

   public:
    seqStack(int initSize = 10);
    seqStack(const seqStack<T>&);
    ~seqStack();
    int size() const;
    void push(T);
    T top();
    T pop();
    bool isEmpty();
    T find(T) const;
    seqStack<T>& operator=(const seqStack<T>&);
    T& operator[](int);
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, m, n, temp;

    cin >> N;
    for (int i = 0; i < N; i++) {
        bool flag = 1;
        int k = 1;
        cin >> n >> m;
        cin >> temp;
        seqStack<int> sta(m + 5);

        for (int j = 0; j < n; j++) {
            sta.push(j);
            while (sta.top() == temp) {
                sta.pop();
                // 防止多读数据
                if (k < n) {
                    cin >> temp;
                    k++;
                }
            }
            if (sta.size() > m) {
                flag = 0;
                break;
            }
        }

        // 将未读入数据全部读入
        while (k < n) {
            flag = 0;
            cin >> temp;
            k++;
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

template <class T>
seqStack<T>::seqStack(int initSize) {
    data = new T[initSize];
    nowSize = 0;
    maxSize = initSize;
}

template <class T>
seqStack<T>::seqStack(const seqStack<T>& right) {
    nowSize = right.nowSize;
    maxSize = right.maxSize;
    data = new T[maxSize];
    for (int i = 0; i < nowSize; i++) {
        data[i] = right.data[i];
    }
}

template <class T>
seqStack<T>::~seqStack() {
    delete[] data;
    data = NULL;
}

template <class T>
void seqStack<T>::doublespace() {
    maxSize *= 2;
    T* tmp;
    tmp = new T[maxSize];

    for (int i = 0; i < nowSize; i++) {
        tmp[i] = data[i];
    }

    delete[] data;
    data = tmp;

    tmp = NULL;
}

template <class T>
int seqStack<T>::size() const {
    return nowSize;
}

template <class T>
void seqStack<T>::push(T x) {
    if (nowSize == maxSize) {
        doublespace();
    }
    data[nowSize++] = x;
}

template <class T>
T seqStack<T>::top() {
    if (nowSize > 0) {
        return data[nowSize - 1];
    } else {
        return -1;
    }
}

template <class T>
T seqStack<T>::pop() {
    if (nowSize > 0) {
        return data[--nowSize];
    }
}

template <class T>
bool seqStack<T>::isEmpty() {
    return (nowSize == 0);
}

template <class T>
T seqStack<T>::find(T x) const {
    for (int i = 0; i < nowSize; i++) {
        if (data[i] == x) {
            return x;
        }
    }
    return -1;
}

template <class T>
seqStack<T>& seqStack<T>::operator=(const seqStack<T>& right) {
    if (this != &right) {
        delete[] data;

        nowSize = right.nowSize;
        maxSize = right.maxSize;
        data = new T[maxSize];
        for (int i = 0; i < nowSize; i++) {
            data[i] = right.data[i];
        }
    }

    return *this;
}

template <class T>
T& seqStack<T>::operator[](int x) {
    return data[nowSize - x - 1];
}