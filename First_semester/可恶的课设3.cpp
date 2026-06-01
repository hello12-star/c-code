#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <limits>
using namespace std;
// ==================== 二叉搜索树节点（通用，存储键值对）====================
template <typename K, typename V>
struct BSTNode {
    K key;
    V value;
    BSTNode* left;
    BSTNode* right;

    BSTNode(K k, V v) : key(k), value(v), left(NULL), right(NULL) {}
};

// ==================== 二叉搜索树（实现快速查找）====================
template <typename K, typename V>
class BST {
private:
    BSTNode<K, V>* root;

    BSTNode<K, V>* insertNode(BSTNode<K, V>* node, K key, V value) {
        if (node == NULL) return new BSTNode<K, V>(key, value);
        if (key < node->key) node->left = insertNode(node->left, key, value);
        else if (key > node->key) node->right = insertNode(node->right, key, value);
        return node;
    }

    BSTNode<K, V>* searchNode(BSTNode<K, V>* node, K key) {
        if (node == NULL || node->key == key) return node;
        return key < node->key ? searchNode(node->left, key) : searchNode(node->right, key);
    }

    void destroyNode(BSTNode<K, V>* node) {
        if (node != NULL) {
            destroyNode(node->left);
            destroyNode(node->right);
            delete node;
        }
    }
public:
    BST() : root(NULL) {}
    ~BST() { destroyNode(root); }

    void insert(K key, V value) { root = insertNode(root, key, value); }
    V search(K key) {
        BSTNode<K, V>* node = searchNode(root, key);
        return node == NULL ? V() : node->value;
    }
};

// ==================== 电影类 ====================
class Movie {
private:
    string name;
    string type;
    int duration;
    double score;
    double price;

public:
    Movie(string n = "", string t = "", int d = 0, double s = 0.0, double p = 0.0)
        : name(n), type(t), duration(d), score(s), price(p) {}

    string getName() const { return name; }
    string getType() const { return type; }
    int getDuration() const { return duration; }
    double getScore() const { return score; }
    double getPrice() const { return price; }

    void showInfo() const {
        cout << "电影：" << name << "，类型：" << type
             << "，时长：" << duration << "分钟，评分：" << score
             << "，票价：" << price << "元" << endl;
    }

    // 保存到文件的格式：name|type|duration|score|price
    string toFileString() const {
        stringstream ss;
        ss << name << "|" << type << "|" << duration << "|" << score << "|" << price;
        return ss.str();
    }

    // 从文件字符串加载数据
    static Movie fromFileString(const string& line) {
        vector<string> parts = splitString(line, '|');
        if (parts.size() != 5) return Movie();
        return Movie(
            parts[0],
            parts[1],
            atoi(parts[2].c_str()),//字符串转int类型 
            atof(parts[3].c_str()),//字符串转double类型 
            atof(parts[4].c_str())
        );//.c_str的意思是将c++中的string字符串转换成c语言的char*字符串 
    }

    // 辅助：字符串分割（内部使用）
    static vector<string> splitString(const string& str, char delimiter) {
        vector<string> result;
        stringstream ss(str);
        string item;
        while (getline(ss, item, delimiter)) {//从ss中读到'|'为止，存入item 
            result.push_back(item);
        }
        return result;
    }
};

// ==================== 影厅类 ====================
class Hall {
private:
    int hallId;
    int rows;
    int cols;
    bool** seatMap;
public:
    Hall(int id = 0, int r = 0, int c = 0) : hallId(id), rows(r), cols(c) {
        seatMap = new bool*[rows];
        for (int i = 0; i < rows; i++) {
            seatMap[i] = new bool[cols];
            for (int j = 0; j < cols; j++) {
                seatMap[i][j] = false;
            }
        }
    }
    ~Hall() {
        for (int i = 0; i < rows; i++) delete[] seatMap[i];
        delete[] seatMap;
    }
    int getHallId() const { return hallId; }
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    bool occupySeat(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols && !seatMap[row][col]) {
            seatMap[row][col] = true;
            return true;
        }
        return false;
    }

    bool releaseSeat(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols && seatMap[row][col]) {
            seatMap[row][col] = false;
            return true;
        }
        return false;
    }

    void showSeatMap() const {
        cout << "\n影厅" << hallId << "座位图：" << endl;
        cout << "   ";
        for (int j = 0; j < cols; j++) cout << j << " ";
        cout << endl;
        for (int i = 0; i < rows; i++) {
            cout << i << ": ";
            for (int j = 0; j < cols; j++) {
                cout << (seatMap[i][j] ? "X " : "O ");
            }
            cout << endl;
        }
        cout << "O=空位 X=已占" << endl;
    }

    void showInfo() const {
        cout << "影厅" << hallId << "，座位：" << rows << "行×" << cols << "列" << endl;
    }

    // 保存到文件的格式：hallId|rows|cols
    string toFileString() const {
        stringstream ss;
        ss << hallId << "|" << rows << "|" << cols;
        return ss.str();
    }

    // 从文件字符串加载数据
    static Hall fromFileString(const string& line) {
        vector<string> parts = Movie::splitString(line, '|');
        if (parts.size() != 3) return Hall();
        return Hall(
            atoi(parts[0].c_str()),
            atoi(parts[1].c_str()),
            atoi(parts[2].c_str())
        );
    }
};

// ==================== 场次类 ====================
class Session {
private:
    int sessionId;
    string movieName;  // 存储电影名，避免指针序列化问题
    int hallId;        // 存储影厅号，避免指针序列化问题
    string time;

public:
    Session(int id = 0, string m = "", int h = 0, string t = "")
        : sessionId(id), movieName(m), hallId(h), time(t) {};
    int getSessionId() const { return sessionId; }
    string getMovieName() const { return movieName; }
    int getHallId() const { return hallId; }
    string getTime() const { return time; }
    // 关联电影和影厅（加载后调用）
    void link(Movie* movie, Hall* hall) {
        if (movie) movieName = movie->getName();
        if (hall) hallId = hall->getHallId();
    }
    void showInfo(Movie* movie, Hall* hall) const {
        cout << "场次" << sessionId << "，电影：" << (movie ? movie->getName() : "未知")
             << "，影厅：" << (hall ? hall->getHallId() : 0) << "，时间：" << time << endl;
    }
    // 保存到文件的格式：sessionId|movieName|hallId|time
    string toFileString() const {
        stringstream ss;
        ss << sessionId << "|" << movieName << "|" << hallId << "|" << time;
        return ss.str();
    }

    // 从文件字符串加载数据
    static Session fromFileString(const string& line) {
        vector<string> parts = Movie::splitString(line, '|');
        if (parts.size() != 4) return Session();
        return Session(
            atoi(parts[0].c_str()),
            parts[1],
            atoi(parts[2].c_str()),
            parts[3]
        );
    }
};

// ==================== 订单类 ====================
class Order {
private:
    string orderId;
    int sessionId;
    string userName;
    string userPhone;
    int ticketCount;
    string seats;
    double totalPrice;
    int priority;

public:
    Order(string id = "", int s = 0, string name = "", string phone = "", int count = 0, string seatStr = "", double price = 0.0, int pri = 1)
        : orderId(id), sessionId(s), userName(name), userPhone(phone), ticketCount(count), seats(seatStr), totalPrice(price), priority(pri) {}

    bool operator<(const Order& other) const {
        return this->priority < other.priority;
    }

    string getOrderId() const { return orderId; }
    int getSessionId() const { return sessionId; }
    string getUserName() const { return userName; }
    string getUserPhone() const { return userPhone; }
    int getTicketCount() const { return ticketCount; }
    string getSeats() const { return seats; }
    double getTotalPrice() const { return totalPrice; }
    int getPriority() const { return priority; }

    void showInfo() const {
        cout << "订单" << orderId << "，用户：" << userName
             << "，电话：" << userPhone << "，数量：" << ticketCount
             << "张，总价：" << totalPrice << "元，座位：" << seats << endl;
    }

    // 保存到文件的格式：orderId|sessionId|userName|userPhone|ticketCount|seats|totalPrice|priority
    string toFileString() const {
        stringstream ss;
        ss << orderId << "|" << sessionId << "|" << userName << "|" << userPhone
           << "|" << ticketCount << "|" << seats << "|" << totalPrice << "|" << priority;
        return ss.str();
    }

    // 从文件字符串加载数据
    static Order fromFileString(const string& line) {
        vector<string> parts = Movie::splitString(line, '|');
        if (parts.size() != 8) return Order();
        return Order(
            parts[0],
            atoi(parts[1].c_str()),
            parts[2],
            parts[3],
            atoi(parts[4].c_str()),
            parts[5],
            atof(parts[6].c_str()),
            atoi(parts[7].c_str())
        );
    }
};

// ==================== 全局数据 ====================
list<Movie*> movieList;
list<Hall*> hallList;
list<Session*> sessionList;
list<Order*> orderList;

priority_queue<Order> bookingHeap;
priority_queue<Order> refundHeap;

BST<string, Movie*> movieBST;
BST<int, Hall*> hallBST;
BST<int, Session*> sessionBST;

// 数据文件路径
const string MOVIE_FILE = "movies.txt";
const string HALL_FILE = "halls.txt";
const string SESSION_FILE = "sessions.txt";
const string ORDER_FILE = "orders.txt";

// ==================== 辅助函数 ====================
vector<string> splitString(const string& str, char delimiter) {
    return Movie::splitString(str, delimiter);
}

// ==================== 文件持久化函数 ====================
// 保存电影数据到文件
void saveMovies() {
    ofstream fout(MOVIE_FILE.c_str());//打开文件 
    if (!fout.is_open()) {
        cout << "无法保存电影数据！" << endl;
        return;
    }
    for (list<Movie*>::iterator it = movieList.begin(); it != movieList.end(); it++) {
        fout << (*it)->toFileString() << endl;
    }
    fout.close();
    cout << "电影数据保存成功！" << endl;
}

// 加载电影数据
void loadMovies() {
    // 清空原有数据
    for (list<Movie*>::iterator it = movieList.begin(); it != movieList.end(); it++) delete *it;
    movieList.clear();
    // 重新加载
    ifstream fin(MOVIE_FILE.c_str());
    if (!fin.is_open()) {
        cout << "无电影数据文件，跳过加载！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        Movie movie = Movie::fromFileString(line);
        if (!movie.getName().empty()) {
            Movie* m = new Movie(movie);//用new创建Movie对象的指针 
            movieList.push_back(m);//Movie指针加入movielist（链表容器，管理所有的电影） 
            movieBST.insert(m->getName(), m);//把电影名作为键，m作为指针绑定存入二叉搜索树 
        }
    }
    fin.close();
    cout << "电影数据加载成功！" << endl;
}

// 保存影厅数据
void saveHalls() {
    ofstream fout(HALL_FILE.c_str());
    if (!fout.is_open()) {
        cout << "无法保存影厅数据！" << endl;
        return;
    }
    for (list<Hall*>::iterator it = hallList.begin(); it != hallList.end(); it++) {
        fout << (*it)->toFileString() << endl;
    }
    fout.close();
    cout << "影厅数据保存成功！" << endl;
}

// 加载影厅数据
void loadHalls() {
    for (list<Hall*>::iterator it = hallList.begin(); it != hallList.end(); it++) delete *it;
    hallList.clear();

    ifstream fin(HALL_FILE.c_str());
    if (!fin.is_open()) {
        cout << "无影厅数据文件，跳过加载！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        Hall hall = Hall::fromFileString(line);
        if (hall.getHallId() != 0) {
            Hall* h = new Hall(hall);
            hallList.push_back(h);
            hallBST.insert(h->getHallId(), h);
        }
    }
    fin.close();
    cout << "影厅数据加载成功！" << endl;
}
// 保存场次数据
void saveSessions() {
    ofstream fout(SESSION_FILE.c_str());
    if (!fout.is_open()) {
        cout << "无法保存场次数据！" << endl;
        return;
    }
    for (list<Session*>::iterator it = sessionList.begin(); it != sessionList.end(); it++) {
        fout << (*it)->toFileString() << endl;
    }
    fout.close();
    cout << "场次数据保存成功！" << endl;
}

// 加载场次数据
void loadSessions() {
    for (list<Session*>::iterator it = sessionList.begin(); it != sessionList.end(); it++) delete *it;
    sessionList.clear();

    ifstream fin(SESSION_FILE.c_str());
    if (!fin.is_open()) {
        cout << "无场次数据文件，跳过加载！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        Session session = Session::fromFileString(line);
        if (session.getSessionId() != 0) {
            Session* s = new Session(session);
            sessionList.push_back(s);
            sessionBST.insert(s->getSessionId(), s);
        }
    }
    fin.close();
    cout << "场次数据加载成功！" << endl;
}

// 保存订单数据
void saveOrders() {
    ofstream fout(ORDER_FILE.c_str());
    if (!fout.is_open()) {
        cout << "无法保存订单数据！" << endl;
        return;
    }
    for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) {
        fout << (*it)->toFileString() << endl;
    }
    fout.close();
    cout << "订单数据保存成功！" << endl;
}

// 加载订单数据
void loadOrders() {
    for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) delete *it;
    orderList.clear();

    ifstream fin(ORDER_FILE.c_str());
    if (!fin.is_open()) {
        cout << "无订单数据文件，跳过加载！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        Order order = Order::fromFileString(line);
        if (!order.getOrderId().empty()) {
            Order* o = new Order(order);
            orderList.push_back(o);
        }
    }
    fin.close();
    cout << "订单数据加载成功！" << endl;
}

// 一键保存所有数据
void saveAllData() {
    saveMovies();
    saveHalls();
    saveSessions();
    saveOrders();
}

// 一键加载所有数据
void loadAllData() {
    loadMovies();
    loadHalls();
    loadSessions();
    loadOrders();
}

// ==================== 菜单函数 ====================
void showMenu() {
    cout << "\n========== 电影院订票系统（ 完整版）==========" << endl;
    cout <<"1.电影添加"<< endl;
    cout << "2. 添加影厅" << endl;
    cout << "3. 添加场次" << endl;
    cout << "4. 购票（堆排队）" << endl;
    cout << "5. 处理购票堆" << endl;
    cout << "6. 查找（二叉搜索树）" << endl;
    cout << "7. 查看订单（链表）" << endl;
    cout << "8. 退票（堆排队）" << endl;
    cout << "9. 处理退票堆" << endl;
    cout << "10. 查看座位图" << endl;
    cout << "11. 保存数据到文件" << endl;
    cout << "12.从文件加载数据" << endl;
    cout << "0. 退出" << endl;
    cout << "请选择: ";
}

void addMovie() {
    string name, type;
    int duration;
    double score, price;

    cout << "\n添加电影" << endl;
    cout << "电影名称: ";
    cin >> name;
    if (movieBST.search(name) != NULL) {
        cout << "电影已存在！" << endl;
        return;
    }
    cout << "类型: ";
    cin >> type;
    cout << "时长(分钟): ";
    cin >> duration;
    cout << "评分(0-10): ";
    cin >> score;
    cout << "票价: ";
    cin >> price;

    Movie* movie = new Movie(name, type, duration, score, price);//在堆内存中创建一个Movie类的具体对象，并返回该对象的内存地址，赋值给指针movie
    movieList.push_back(movie);//将Movie对象的指针movie添加到双向链表的容器的尾部 
    movieBST.insert(name, movie);//将电影名name与对象movie绑定在一起，插入到二叉搜索树中，从而实现电影名快速查找电影对象 
    cout << "电影添加成功！" << endl;
}

void addHall() {
    int id, rows, cols;

    cout << "\n添加影厅" << endl;
    cout << "影厅编号: ";
    cin >> id;
    if (hallBST.search(id) != NULL) {
        cout << "影厅已存在！" << endl;
        return;
    }
    cout << "行数: ";
    cin >> rows;
    cout << "列数: ";
    cin >> cols;

    Hall* hall = new Hall(id, rows, cols);
    hallList.push_back(hall);
    hallBST.insert(id, hall);
    cout << "影厅添加成功！" << endl;
}

void addSession() {
    if (movieList.empty() || hallList.empty()) {
        cout << "请先添加电影和影厅！" << endl;
        return;
    }
    int sessionId;
    cout << "\n添加场次" << endl;
    cout << "场次编号: ";
    cin >> sessionId;
    if (sessionBST.search(sessionId) != NULL) {
        cout << "场次已存在！" << endl;
        return;
    }

    // 选择电影
    cout << "\n电影列表:" << endl;
    int idx = 0;
    for (list<Movie*>::iterator it = movieList.begin(); it != movieList.end(); it++) {
        cout << idx << ". ";
        (*it)->showInfo();
        idx++;
    }
    int movieIdx;
    cout << "选择电影编号: ";
    cin >> movieIdx;
    if (movieIdx < 0 || movieIdx >= (int)movieList.size()) {
        cout << "电影编号错误！" << endl;
        return;
    }
    Movie* selectedMovie = NULL;
    idx = 0;
    for (list<Movie*>::iterator it = movieList.begin(); it != movieList.end(); it++) {
        if (idx == movieIdx) {
            selectedMovie = *it;
            break;
        }
        idx++;
    }

    // 选择影厅
    cout << "\n影厅列表:" << endl;
    idx = 0;
    for (list<Hall*>::iterator it = hallList.begin(); it != hallList.end(); it++) {
        cout << idx << ". ";
        (*it)->showInfo();
        idx++;
    }
    int hallIdx;
    cout << "选择影厅编号: ";
    cin >> hallIdx;
    if (hallIdx < 0 || hallIdx >= (int)hallList.size()) {
        cout << "影厅编号错误！" << endl;
        return;
    }
    Hall* selectedHall = NULL;
    idx = 0;
    for (list<Hall*>::iterator it = hallList.begin(); it != hallList.end(); it++) {
        if (idx == hallIdx) {
            selectedHall = *it;
            break;
        }
        idx++;
    }
    string time;
    cout << "放映时间: ";
    cin >> time;
    Session* session = new Session(sessionId, selectedMovie->getName(), selectedHall->getHallId(), time);
    sessionList.push_back(session);
    sessionBST.insert(sessionId, session);
    cout << "场次添加成功！" << endl;
}
void bookTicket() {
    if (sessionList.empty()) {
        cout << "无场次可选！" << endl;
        return;
    }

    cout << "\n购票（优先级1-10）" << endl;
    int idx = 0;
    for (list<Session*>::iterator it = sessionList.begin(); it != sessionList.end(); it++) {
        Movie* m = movieBST.search((*it)->getMovieName());
        Hall* h = hallBST.search((*it)->getHallId());
        cout << idx << ". ";
        (*it)->showInfo(m, h);
        idx++;
    }
    int sessIdx;
    cout << "选择场次编号: ";
    cin >> sessIdx;
    if (sessIdx < 0 || sessIdx >= (int)sessionList.size()) {
        cout << "场次编号错误！" << endl;
        return;
    }
    Session* selectedSession = NULL;
    idx = 0;
    for (list<Session*>::iterator it = sessionList.begin(); it != sessionList.end(); it++) {
        if (idx == sessIdx) {
            selectedSession = *it;
            break;
        }
        idx++;
    }
    Hall* selectedHall = hallBST.search(selectedSession->getHallId());
    Movie* selectedMovie = movieBST.search(selectedSession->getMovieName());

    string orderId, userName, userPhone;
    int ticketCount, priority;
    cout << "订单号: ";
    cin >> orderId;
    cout << "姓名: ";
    cin >> userName;
    cout << "电话: ";
    cin >> userPhone;
    cout << "票数: ";
    cin >> ticketCount;
    cout << "优先级(1-10): ";
    cin >> priority;

    string seats = "";
    for (int i = 0; i < ticketCount; i++) {
        selectedHall->showSeatMap();
        cout << "选择第" << i+1 << "张票的座位（行 列）: ";
        int row, col;
        cin >> row >> col;
        if (row < 0 || row >= selectedHall->getRows() || col < 0 || col >= selectedHall->getCols()) {
            cout << "座位超出范围！" << endl;
            i--;
            continue;
        }
        if (selectedHall->occupySeat(row, col)) {
            if (!seats.empty()) seats += ",";
            stringstream ss;
            ss << row << "-" << col;
            seats += ss.str();
            cout << "选座成功！" << endl;
        } else {
            cout << "座位已被占用！" << endl;
            i--;
        }
    }

    double totalPrice = selectedMovie->getPrice() * ticketCount;
    Order order(orderId, selectedSession->getSessionId(), userName, userPhone, ticketCount, seats, totalPrice, priority);
    bookingHeap.push(order);
    cout << "购票订单已加入堆！" << endl;
}

void processBookingHeap() {
    if (bookingHeap.empty()) {
        cout << "无待处理购票订单！" << endl;
        return;
    }

    cout << "\n处理购票堆（优先级从高到低）" << endl;
    while (!bookingHeap.empty()) {
        Order top = bookingHeap.top();
        top.showInfo();
        orderList.push_back(new Order(top));
        bookingHeap.pop();
    }
    cout << "购票订单处理完成！" << endl;
}

void search() {
    int choice;
    cout << "\n查找功能" << endl;
    cout << "1. 按名称查找电影" << endl;
    cout << "2. 按编号查找场次" << endl;
    cout << "选择: ";
    cin >> choice;

    if (choice == 1) {
        string name;
        cout << "电影名称: ";
        cin >> name;
        Movie* m = movieBST.search(name);
        if (m) m->showInfo();
        else cout << "未找到该电影！" << endl;
    } else if (choice == 2) {
        int id;
        cout << "场次编号: ";
        cin >> id;
        Session* s = sessionBST.search(id);
        if (s) {
            Movie* m = movieBST.search(s->getMovieName());
            Hall* h = hallBST.search(s->getHallId());
            s->showInfo(m, h);
        } else {
            cout << "未找到该场次！" << endl;
        }
    } else {
        cout << "选择错误！" << endl;
    }
}

void showOrders() {
    if (orderList.empty()) {
        cout << "无已处理订单！" << endl;
        return;
    }

    cout << "\n所有订单列表" << endl;
    for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) {
        (*it)->showInfo();
    }
}

void refundTicket() {
    if (orderList.empty()) {
        cout << "无订单可退！" << endl;
        return;
    }

    cout << "\n退票（优先级1-10）" << endl;
    int idx = 0;
    for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) {
        cout << idx << ". ";
        (*it)->showInfo();
        idx++;
    }
    int orderIdx;
    cout << "选择订单编号: ";
    cin >> orderIdx;
    if (orderIdx < 0 || orderIdx >= (int)orderList.size()) {
        cout << "订单编号错误！" << endl;
        return;
    }
    Order* selectedOrder = NULL;
    idx = 0;
    for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) {
        if (idx == orderIdx) {
            selectedOrder = *it;
            break;
        }
        idx++;
    }

    int priority;
    cout << "退票优先级(1-10): ";
    cin >> priority;
    Order refundOrder(
        selectedOrder->getOrderId(),
        selectedOrder->getSessionId(),
        selectedOrder->getUserName(),
        selectedOrder->getUserPhone(),
        selectedOrder->getTicketCount(),
        selectedOrder->getSeats(),
        selectedOrder->getTotalPrice(),
        priority
    );
    refundHeap.push(refundOrder);
    cout << "退票订单已加入堆！" << endl;
}

void processRefundHeap() {
    if (refundHeap.empty()) {
        cout << "无待处理退票订单！" << endl;
        return;
    }

    cout << "\n处理退票堆（优先级从高到低）" << endl;
    while (!refundHeap.empty()) {
        Order top = refundHeap.top();
        top.showInfo();

        // 释放座位
        Session* s = sessionBST.search(top.getSessionId());
        Hall* h = hallBST.search(s->getHallId());
        vector<string> seatList = splitString(top.getSeats(), ',');
        for (size_t i = 0; i < seatList.size(); i++) {
            vector<string> rc = splitString(seatList[i], '-');
            if (rc.size() == 2) {
                int row = atoi(rc[0].c_str());
                int col = atoi(rc[1].c_str());
                h->releaseSeat(row, col);
            }
        }

        refundHeap.pop();
    }
    cout << "退票订单处理完成！" << endl;
}

void showSeatMap() {
    if (hallList.empty()) {
        cout << "无影厅！" << endl;
        return;
    }

    cout << "\n影厅列表" << endl;
    int idx = 0;
    for (list<Hall*>::iterator it = hallList.begin(); it != hallList.end(); it++) {
        cout << idx << ". ";
        (*it)->showInfo();
        idx++;
    }
    int hallIdx;
    cout << "选择影厅编号: ";
    cin >> hallIdx;
    if (hallIdx < 0 || hallIdx >= (int)hallList.size()) {
        cout << "影厅编号错误！" << endl;
        return;
    }
    Hall* selectedHall = NULL;
    idx = 0;
    for (list<Hall*>::iterator it = hallList.begin(); it != hallList.end(); it++) {
        if (idx == hallIdx) {
            selectedHall = *it;
            break;
        }
        idx++;
    }
    selectedHall->showSeatMap();
}

// ==================== 主函数 ====================
int main() {
    int choice;



    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addMovie(); break;
            case 2: addHall(); break;
            case 3: addSession(); break;
            case 4: bookTicket(); break;
            case 5: processBookingHeap(); break;
            case 6: search(); break;
            case 7: showOrders(); break;
            case 8: refundTicket(); break;
            case 9: processRefundHeap(); break;
            case 10: showSeatMap(); break;
            case 11: saveAllData(); break;
            case 12: loadAllData(); break;
            case 0:
                saveAllData(); // 退出时自动保存数据
                for (list<Movie*>::iterator it = movieList.begin(); it != movieList.end(); it++) delete *it;
                for (list<Hall*>::iterator it = hallList.begin(); it != hallList.end(); it++) delete *it;
                for (list<Session*>::iterator it = sessionList.begin(); it != sessionList.end(); it++) delete *it;
                for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) delete *it;
                cout << "谢谢使用！" << endl;
                return 0;
            default: cout << "选择错误！" << endl;
        }

        cout << "\n按回车继续...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    return 0;
}

