#include<iostream>
#include<string.h>
#include<queue>
#include<list>
#include<vector>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<limits>
using namespace std;
template<typename K,typename V>
struct BSTNode{//二叉搜索树——节点 
	K key;
	V value;
	BSTNode*left;
	BSTNode*right;
	BSTNode(K k,V v):key(k),value(v),left(NULL),right(NULL){}
}; 
template<typename K,typename V>
struct BST{
	BSTNode<K,V>*root;
	BST<K,V>*insertNode(BSTNode<K,V>*node,K key,V value){
		if(node==NULL) return new BSTNode<K,V>(key,value);
		if(key<node->key) node->left=insertNode(node->left,key,value);
		else if(key>node->key) node->right=insertNode(node->right,key,value);
		return node;
	} 
	BSTNode<K,V>*searchNode(BSTNode<K,V>*node,K key){
		if(node==NULL||node->key==key) return node;
		return key<node->key?searchNode(node->left,key):searchNode(node->right,key);
	}
	void destroyNode(BSTNode<K,V>*node){
		if(node!=NULL){
			destroyNode(node->left);
			destroyNode(node->right);
			delete node;
		}
	}
	public:
		BST():root(NULL){}
		~BST(){destroyNode(root);}
		void insert(K key,V value){
		root=insertNode(root,key,value);
		}
		V search(K key){
			BSTNode<K,V>*node=searchNode(root,key);
			return node==NULL?NULL:node->value;
		}
}; 
class Movie{
	private:
		string name;
		string type;
		int duration;
		double score;
		double price;
	public:
		Movie(string n="",string t="",int d=0,double s=0.0,double p=0.0):
		name(n),type(t),duration(d),score(s),price(p){}	
		string getname()const{return name;}
		string gettype()const{return type;}
		int getduration()const{return duration;}
		double getscore()const{return score;}
		double getprice()const{return price;}
		void showinfo()const{
		cout<<"电影:"<<name<<",类型："<<type<<",时长："<<duration<<"分钟,评分："<<score
		<<",票价："<<price<<"元"<<endl; 
		} 
	string tofilestring()const{
	stringstream ss;
	ss<<name<<"|"<<type<<"|"<<duration<<"|"<<score<<"|"<<price;
	return ss.str(); 
	}
	static Movie fromfilestring(const string&line){
		vector<string>parts=splitstring(line,'|');
		if(parts.size()!=5) return Movie();
		return Movie(
		 	parts[0],
        	parts[1],
            atoi(parts[2].c_str()),//字符串转int类型 
            atof(parts[3].c_str()),//字符串转double类型 
            atof(parts[4].c_str())
		);//.c_str的意思是将c++中的string字符串转换成c语言的char*字符串
	}
	static vector<string> splitstring(const string& str, char delimiter) {
        vector<string> result;
        stringstream ss(str);
        string item;
        while (getline(ss, item, delimiter)) {//从ss中读到'|'为止，存入item 
            result.push_back(item);
        }
        return result;
    }		
};
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
    int getRows()const{return rows; }
    int getCols()const{return cols; }
    bool occupySeat(int row, int col) {
        if (row>= 0&&row<rows &&col>=0&&col<cols&&!seatMap[row][col]){
            seatMap[row][col]=true;
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
    cout << "\n影厅"<< hallId << "座位图：" << endl;
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
        cout << "影厅" << hallId << "，座位：" << rows << "行x" << cols << "列" << endl;
    }
string toFileString() const {
    stringstream ss;
    ss << hallId << "|" << rows << "|" << cols;
    return ss.str();
    }
static Hall fromFileString(const string& line) {
    vector<string> parts = Movie::splitstring(line, '|');
    if (parts.size() != 3) return Hall();
    return Hall(
        atoi(parts[0].c_str()),
        atoi(parts[1].c_str()),
        atoi(parts[2].c_str())
        );
    }
};
class Session{
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
        if (movie) movieName = movie->getname();
        if (hall) hallId = hall->getHallId();
    }
    void showInfo(Movie* movie, Hall* hall) const {
        cout << "场次" << sessionId << "，电影：" << (movie ? movie->getname() : "未知")
             << "，影厅：" << (hall ? hall->getHallId() : 0) << "，时间：" << time << endl;
    }
	string toFileString() const {
        stringstream ss;
        ss << sessionId << "|" << movieName << "|" << hallId << "|" << time;
        return ss.str();
    }
	static Session fromFileString(const string& line) {
	    vector<string> parts = Movie::splitstring(line, '|');
	    if (parts.size() != 4) return Session();
	    return Session(
	        atoi(parts[0].c_str()),
	    	parts[1],
	        atoi(parts[2].c_str()),
	        parts[3]
	    );
	}
};
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
             << "，电话;" << userPhone << ",数量；" << ticketCount
             << "张，总价：" << totalPrice << "元，座位：" << seats << endl;
    }
    string toFileString() const {
        stringstream ss;
        ss << orderId << "|" << sessionId << "|" << userName << "|" << userPhone
           << "|" << ticketCount << "|" << seats << "|" << totalPrice << "|" << priority;
        return ss.str();
    }
static Order fromFileString(const string& line) {
        vector<string> parts = Movie::splitstring(line, '|');
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
list<Movie*> movieList;
list<Hall*> hallList;
list<Session*> sessionList;
list<Order*> orderList;

priority_queue<Order> bookingHeap;
priority_queue<Order> refundHeap;

BST<string, Movie*> movieBST;
BST<int, Hall*> hallBST;
BST<int, Session*> sessionBST;






