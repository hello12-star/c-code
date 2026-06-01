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
			//二叉搜索树节点
template <typename K, typename V>
struct BSTNode {
    K key;
    V value;
    BSTNode* left;
    BSTNode* right;

    BSTNode(K k, V v) : key(k), value(v), left(NULL), right(NULL) {}
};
			//二叉搜索树
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
        // 对于指针，特殊处理
        if (node == NULL) return NULL;
        return node->value;
    }
};
// 电影类 
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
            atoi(parts[2].c_str()),
            atof(parts[3].c_str()),
            atof(parts[4].c_str())
        );
    }
    // 字符串分隔 
    static vector<string> splitString(const string& str, char delimiter) {
        vector<string> result;
        stringstream ss(str);
        string item;
        while (getline(ss, item, delimiter)) {
            result.push_back(item);
        }
        return result;
    }
};
//影厅类
class Hall {
private:
    int hallId;
    int rows;
    int cols;
    bool** seatMap;
    // 将座位图转换为字符串
    string seatMapToString() const {
        stringstream ss;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ss << (seatMap[i][j] ? '1' : '0');
            }
            if (i != rows - 1) ss << ",";
        }
        return ss.str();
    }
    // 从字符串恢复座位图
    void stringToSeatMap(const string& seatStr) {
        vector<string> rowsStr = Movie::splitString(seatStr, ',');
        for (int i = 0; i < rows && i < (int)rowsStr.size(); i++) {
            for (int j = 0; j < cols && j < (int)rowsStr[i].length(); j++) {
                seatMap[i][j] = (rowsStr[i][j] == '1');
            }
        }
    }
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
    // 拷贝构造函数
    Hall(const Hall& other) : hallId(other.hallId), rows(other.rows), cols(other.cols) {
        seatMap = new bool*[rows];
        for (int i = 0; i < rows; i++) {
            seatMap[i] = new bool[cols];
            for (int j = 0; j < cols; j++) {
                seatMap[i][j] = other.seatMap[i][j];
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

    // 保存到文件的格式：hallId|rows|cols|seatMapString
    string toFileString() const {
        stringstream ss;
        ss << hallId << "|" << rows << "|" << cols << "|" << seatMapToString();
        return ss.str();
    }

    // 从文件字符串加载数据
    static Hall fromFileString(const string& line) {
        vector<string> parts = Movie::splitString(line, '|');
        if (parts.size() < 3) return Hall();
        
        Hall hall(atoi(parts[0].c_str()), atoi(parts[1].c_str()), atoi(parts[2].c_str()));
        
        // 如果文件中有座位图信息，则恢复座位图
        if (parts.size() >= 4) {
            hall.stringToSeatMap(parts[3]);
        }
        
        return hall;
    }
};
// 场次类
class Session {
private:
    int sessionId;
    string movieName;
    int hallId;
    string time;

public:
    Session(int id = 0, string m = "", int h = 0, string t = "")
        : sessionId(id), movieName(m), hallId(h), time(t) {};
        
    int getSessionId() const { return sessionId; }
    string getMovieName() const { return movieName; }
    int getHallId() const { return hallId; }
    string getTime() const { return time; }
    
    void link(Movie* movie, Hall* hall) {
        // 用于检查数据完整性
        if (movie && movie->getName() != movieName) {
            cout << "警告：电影名称不匹配！" << endl;
        }
        if (hall && hall->getHallId() != hallId) {
            cout << "警告：影厅ID不匹配！" << endl;
        }
    }
    
    void showInfo(Movie* movie, Hall* hall) const {
        cout << "场次" << sessionId << "，电影：" << movieName
             << "，影厅：" << hallId << "，时间：" << time << endl;
        if (movie) {
            cout << "  电影详情：";
            movie->showInfo();
        }
        if (hall) {
            cout << "  影厅详情：";
            hall->showInfo();
        }
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

// 订单类
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
    Order(string id = "", int s = 0, string name = "", string phone = "", 
          int count = 0, string seatStr = "", double price = 0.0, int pri = 1)
        : orderId(id), sessionId(s), userName(name), userPhone(phone), 
          ticketCount(count), seats(seatStr), totalPrice(price), priority(pri) {}

    bool operator<(const Order& other) const {
        // 优先级数字越小优先级越高，但优先队列默认是大顶堆，所以反过来
        return this->priority > other.priority;
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
             << "张，总价：" << totalPrice << "元，座位：" << seats 
             << "，优先级：" << priority << endl;
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

// 全局数据
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


vector<string> splitString(const string& str, char delimiter) {
    return Movie::splitString(str, delimiter);
}


// 保存电影数据到文件
void saveMovies() {
    ofstream fout(MOVIE_FILE.c_str());
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
    movieBST = BST<string, Movie*>();
    
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
            Movie* m = new Movie(movie);
            movieList.push_back(m);
            movieBST.insert(m->getName(), m);
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
    
    // 重新初始化BST
    hallBST = BST<int, Hall*>();

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
    
    // 重新初始化BST
    sessionBST = BST<int, Session*>();

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
    
    // 注意：加载订单后，需要根据订单恢复座位图状态
    // 因为座位图只保存了当前状态，但订单信息中有历史座位占用情况
    for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) {
        Order* order = *it;
        Session* session = sessionBST.search(order->getSessionId());
        if (session) {
            Hall* hall = hallBST.search(session->getHallId());
            if (hall) {
                // 解析座位字符串
                string seatsStr = order->getSeats();
                vector<string> seatPairs = splitString(seatsStr, ',');
                for (vector<string>::iterator sit = seatPairs.begin(); sit != seatPairs.end(); sit++) {
                    vector<string> rc = splitString(*sit, '-');
                    if (rc.size() == 2) {
                        int row = atoi(rc[0].c_str());
                        int col = atoi(rc[1].c_str());
                        hall->occupySeat(row, col);
                    }
                }
            }
        }
    }
    cout << "座位图状态已根据订单恢复！" << endl;
}
//菜单函数 
void showMenu() {
    cout << "\n========== 电影院订票系统==========" << endl;
    cout << "1. 添加电影" << endl;
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
    cout << "12. 从文件加载数据" << endl;
    cout << "0. 退出" << endl;
    cout << "请选择: ";
}

void addMovie() {
    string name, type;
    int duration;
    double score, price;
    cout << "\n添加电影" << endl;
    cout << "电影名称: ";
    cin.ignore();
    getline(cin, name);
    
    if (movieBST.search(name) != NULL) {
        cout << "电影已存在！" << endl;
        return;
    }
    
    cout << "类型: ";
    getline(cin, type);
    
    cout << "时长(分钟): ";
    while (!(cin >> duration) || duration <= 0) {
        cout << "输入无效，请重新输入时长: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "评分(0-10): ";
    while (!(cin >> score) || score < 0 || score > 10) {
        cout << "输入无效，请重新输入评分(0-10): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "票价: ";
    while (!(cin >> price) || price < 0) {
        cout << "输入无效，请重新输入票价: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Movie* movie = new Movie(name, type, duration, score, price);
    movieList.push_back(movie);
    movieBST.insert(name, movie);
    cout << "电影添加成功！" << endl;
}

void addHall() {
    int id, rows, cols;

    cout << "\n添加影厅" << endl;
    cout << "影厅编号: ";
    while (!(cin >> id) || id <= 0) {
        cout << "输入无效，请重新输入影厅编号: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    if (hallBST.search(id) != NULL) {
        cout << "影厅已存在！" << endl;
        return;
    }
    
    cout << "行数: ";
    while (!(cin >> rows) || rows <= 0) {
        cout << "输入无效，请重新输入行数: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "列数: ";
    while (!(cin >> cols) || cols <= 0) {
        cout << "输入无效，请重新输入列数: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

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
    while (!(cin >> sessionId) || sessionId <= 0) {
        cout << "输入无效，请重新输入场次编号: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
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
    while (!(cin >> movieIdx) || movieIdx < 0 || movieIdx >= (int)movieList.size()) {
        cout << "输入无效，请重新选择电影编号: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    while (!(cin >> hallIdx) || hallIdx < 0 || hallIdx >= (int)hallList.size()) {
        cout << "输入无效，请重新选择影厅编号: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    cout << "放映时间(格式: YYYY-MM-DD HH:MM): ";
    cin.ignore();
    getline(cin, time);
    
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

    cout << "\n购票（优先级1-10，数字越小优先级越高）" << endl;
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
    while (!(cin >> sessIdx) || sessIdx < 0 || sessIdx >= (int)sessionList.size()) {
        cout << "输入无效，请重新选择场次编号: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    cin.ignore();
    getline(cin, orderId);
    
    cout << "姓名: ";
    getline(cin, userName);
    
    cout << "电话: ";
    getline(cin, userPhone);
    
    cout << "票数: ";
    while (!(cin >> ticketCount) || ticketCount <= 0) {
        cout << "输入无效，请重新输入票数: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "优先级(1-10，1为最高): ";
    while (!(cin >> priority) || priority < 1 || priority > 10) {
        cout << "输入无效，请重新输入优先级(1-10): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string seats = "";
    for (int i = 0; i < ticketCount; i++) {
        selectedHall->showSeatMap();
        cout << "选择第" << i+1 << "张票的座位（行 列）: ";
        int row, col;
        while (!(cin >> row >> col) || row < 0 || row >= selectedHall->getRows() || 
               col < 0 || col >= selectedHall->getCols()) {
            cout << "座位超出范围！请重新输入（行 列）: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        cout << "处理订单: ";
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
    cout << "3. 按编号查找影厅" << endl;
    cout << "选择: ";
    
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "输入无效，请重新选择(1-3): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (choice == 1) {
        string name;
        cout << "电影名称: ";
        cin.ignore();
        getline(cin, name);
        Movie* m = movieBST.search(name);
        if (m) m->showInfo();
        else cout << "未找到该电影！" << endl;
    } else if (choice == 2) {
        int id;
        cout << "场次编号: ";
        while (!(cin >> id) || id <= 0) {
            cout << "输入无效，请重新输入场次编号: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        Session* s = sessionBST.search(id);
        if (s) {
            Movie* m = movieBST.search(s->getMovieName());
            Hall* h = hallBST.search(s->getHallId());
            s->showInfo(m, h);
        } else {
            cout << "未找到该场次！" << endl;
        }
    } else if (choice == 3) {
        int id;
        cout << "影厅编号: ";
        while (!(cin >> id) || id <= 0) {
            cout << "输入无效，请重新输入影厅编号: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        Hall* h = hallBST.search(id);
        if (h) {
            h->showInfo();
            h->showSeatMap();
        } else {
            cout << "未找到该影厅！" << endl;
        }
    }
}

void showOrders() {
    if (orderList.empty()) {
        cout << "无已处理订单！" << endl;
        return;
    }

    cout << "\n所有订单列表" << endl;
    int idx = 1;
    for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) {
        cout << idx << ". ";
        (*it)->showInfo();
        idx++;
    }
}

void refundTicket() {
    if (orderList.empty()) {
        cout << "无订单可退！" << endl;
        return;
    }

    cout << "\n退票（优先级1-10，数字越小优先级越高）" << endl;
    int idx = 0;
    for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) {
        cout << idx << ". ";
        (*it)->showInfo();
        idx++;
    }
    
    int orderIdx;
    cout << "选择订单编号: ";
    while (!(cin >> orderIdx) || orderIdx < 0 || orderIdx >= (int)orderList.size()) {
        cout << "输入无效，请重新选择订单编号: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    cout << "退票优先级(1-10，1为最高): ";
    while (!(cin >> priority) || priority < 1 || priority > 10) {
        cout << "输入无效，请重新输入优先级(1-10): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
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
        cout << "处理退票: ";
        top.showInfo();

        // 释放座位
        Session* s = sessionBST.search(top.getSessionId());
        if (s) {
            Hall* h = hallBST.search(s->getHallId());
            if (h) {
                vector<string> seatList = splitString(top.getSeats(), ',');
                for (size_t i = 0; i < seatList.size(); i++) {
                    vector<string> rc = splitString(seatList[i], '-');
                    if (rc.size() == 2) {
                        int row = atoi(rc[0].c_str());
                        int col = atoi(rc[1].c_str());
                        h->releaseSeat(row, col);
                    }
                }
            }
        }

        // 从订单列表中删除该订单
        bool found = false;
        for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); ++it) {
            if ((*it)->getOrderId() == top.getOrderId()) {
                delete *it;
                orderList.erase(it);
                found = true;
                cout << "订单已从订单列表中删除！" << endl;
                break;
            }
        }
        
        if (!found) {
            cout << "警告：未在订单列表中找到该订单！" << endl;
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
    while (!(cin >> hallIdx) || hallIdx < 0 || hallIdx >= (int)hallList.size()) {
        cout << "输入无效，请重新选择影厅编号: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

// 主函数 
int main() {
    int choice;
    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cout << "输入无效，请重新选择！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

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
                saveAllData();
                for (list<Movie*>::iterator it = movieList.begin(); it != movieList.end(); it++) delete *it;
                for (list<Hall*>::iterator it = hallList.begin(); it != hallList.end(); it++) delete *it;
                for (list<Session*>::iterator it = sessionList.begin(); it != sessionList.end(); it++) delete *it;
                for (list<Order*>::iterator it = orderList.begin(); it != orderList.end(); it++) delete *it;
                cout << "谢谢使用！" << endl;
                return 0;
            default: 
                cout << "选择错误，请重新选择！" << endl;
                break;
        }

        cout << "\n按回车继续...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();


        system("cls");

    }
    return 0;
}
