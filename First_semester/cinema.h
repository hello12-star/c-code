#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

namespace Cinema {
    // 异常类
    class CinemaException : public std::exception {
    private:
        std::string message;
    public:
        CinemaException(const std::string& msg) : message(msg) {}
        const char* what() const throw() {
            return message.c_str();
        }
    };

    // 电影类
    class Movie {
    private:
        std::string name;
        std::string type;
        int duration; // 分钟
        double rating;
        double price;
    public:
        // 构造函数
        Movie(const std::string& name = "", const std::string& type = "", 
              int duration = 0, double rating = 0.0, double price = 0.0)
            : name(name), type(type), duration(duration), rating(rating), price(price) {}

        // 友元函数，用于输出
        friend std::ostream& operator<<(std::ostream& os, const Movie& movie) {
            os << movie.name << " " << movie.type << " " << movie.duration << " " 
               << movie.rating << " " << movie.price;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Movie& movie) {
            is >> movie.name >> movie.type >> movie.duration >> movie.rating >> movie.price;
            return is;
        }

        // 获取属性的方法
        std::string getName() const { return name; }
        std::string getType() const { return type; }
        int getDuration() const { return duration; }
        double getRating() const { return rating; }
        double getPrice() const { return price; }

        // 设置属性的方法
        void setName(const std::string& name) { this->name = name; }
        void setType(const std::string& type) { this->type = type; }
        void setDuration(int duration) { this->duration = duration; }
        void setRating(double rating) { this->rating = rating; }
        void setPrice(double price) { this->price = price; }
    };

    // 影厅类
    class Hall {
    private:
        int hallId;
        int totalSeats;
        std::vector<std::vector<bool>> seats; // 座位分布，true表示已售出
    public:
        // 构造函数
        Hall(int hallId = 0, int rows = 0, int cols = 0)
            : hallId(hallId), totalSeats(rows * cols) {
            seats.resize(rows, std::vector<bool>(cols, false));
        }

        // 友元函数
        friend std::ostream& operator<<(std::ostream& os, const Hall& hall) {
            os << hall.hallId << " " << hall.seats.size() << " " << hall.seats[0].size();
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Hall& hall) {
            int rows, cols;
            is >> hall.hallId >> rows >> cols;
            hall.totalSeats = rows * cols;
            hall.seats.resize(rows, std::vector<bool>(cols, false));
            return is;
        }

        // 座位管理
        bool bookSeat(int row, int col) {
            if (row >= 0 && row < seats.size() && col >= 0 && col < seats[row].size()) {
                if (!seats[row][col]) {
                    seats[row][col] = true;
                    return true;
                }
            }
            return false;
        }

        bool cancelSeat(int row, int col) {
            if (row >= 0 && row < seats.size() && col >= 0 && col < seats[row].size()) {
                if (seats[row][col]) {
                    seats[row][col] = false;
                    return true;
                }
            }
            return false;
        }

        bool isSeatAvailable(int row, int col) const {
            if (row >= 0 && row < seats.size() && col >= 0 && col < seats[row].size()) {
                return !seats[row][col];
            }
            return false;
        }

        // 获取属性的方法
        int getHallId() const { return hallId; }
        int getTotalSeats() const { return totalSeats; }
        int getAvailableSeats() const {
            int count = 0;
            for (size_t i = 0; i < seats.size(); i++) {
                for (size_t j = 0; j < seats[i].size(); j++) {
                    if (!seats[i][j]) count++;
                }
            }
            return count;
        }
        const std::vector<std::vector<bool>>& getSeats() const { return seats; }
    };

    // 场次类
    class Showtime {
    private:
        int showtimeId;
        Movie* movie;
        Hall* hall;
        std::string time;
    public:
        // 构造函数
        Showtime(int showtimeId = 0, Movie* movie = NULL, Hall* hall = NULL, const std::string& time = "")
            : showtimeId(showtimeId), movie(movie), hall(hall), time(time) {}

        // 友元函数
        friend std::ostream& operator<<(std::ostream& os, const Showtime& showtime) {
            os << showtime.showtimeId << " " << showtime.movie->getName() << " " 
               << showtime.hall->getHallId() << " " << showtime.time;
            return os;
        }

        // 获取属性的方法
        int getShowtimeId() const { return showtimeId; }
        Movie* getMovie() const { return movie; }
        Hall* getHall() const { return hall; }
        std::string getTime() const { return time; }

        // 设置属性的方法
        void setShowtimeId(int id) { showtimeId = id; }
        void setMovie(Movie* m) { movie = m; }
        void setHall(Hall* h) { hall = h; }
        void setTime(const std::string& t) { time = t; }
    };

    // 订单类
    class Order {
    private:
        int orderId;
        Showtime* showtime;
        std::string customerName;
        std::string customerPhone;
        int ticketCount;
        std::vector<std::pair<int, int>> seats; // 座位，row, col
    public:
        // 构造函数
        Order(int orderId = 0, Showtime* showtime = NULL, const std::string& name = "",
              const std::string& phone = "", int count = 0, const std::vector<std::pair<int, int>>& seats = std::vector<std::pair<int, int>>())
            : orderId(orderId), showtime(showtime), customerName(name), customerPhone(phone), 
              ticketCount(count), seats(seats) {}

        // 友元函数
        friend std::ostream& operator<<(std::ostream& os, const Order& order) {
            os << order.orderId << " " << order.showtime->getShowtimeId() << " " 
               << order.customerName << " " << order.customerPhone << " " << order.ticketCount;
            for (const auto& seat : order.seats) {
                os << " " << seat.first << " " << seat.second;
            }
            return os;
        }

        // 获取属性的方法
        int getOrderId() const { return orderId; }
        Showtime* getShowtime() const { return showtime; }
        std::string getCustomerName() const { return customerName; }
        std::string getCustomerPhone() const { return customerPhone; }
        int getTicketCount() const { return ticketCount; }
        const std::vector<std::pair<int, int>>& getSeats() const { return seats; }

        // 设置属性的方法
        void setOrderId(int id) { orderId = id; }
        void setShowtime(Showtime* s) { showtime = s; }
        void setCustomerName(const std::string& name) { customerName = name; }
        void setCustomerPhone(const std::string& phone) { customerPhone = phone; }
        void setTicketCount(int count) { ticketCount = count; }
        void setSeats(const std::vector<std::pair<int, int>>& s) { seats = s; }
    };

    // 电影院管理类
    class CinemaManager {
    private:
        std::vector<Movie> movies;
        std::vector<Hall> halls;
        std::vector<Showtime> showtimes;
        std::vector<Order> orders;
        
        // 快速查找的映射
        std::map<std::string, Movie*> movieMap; // 电影名称到电影对象的映射
        std::map<int, Showtime*> showtimeMap; // 场次编号到场次对象的映射
        
        // 购票和退票的队列
        std::queue<Order> bookingQueue;
        std::stack<Order> refundStack;
        
        // 静态成员，用于生成唯一ID
        static int nextMovieId;
        static int nextHallId;
        static int nextShowtimeId;
        static int nextOrderId;
        
        // 文件路径
        const std::string moviesFile;
        const std::string hallsFile;
        const std::string showtimesFile;
        const std::string ordersFile;
        
        // 构造函数初始化列表初始化文件路径
        CinemaManager() : 
            moviesFile("movies.txt"),
            hallsFile("halls.txt"),
            showtimesFile("showtimes.txt"),
            ordersFile("orders.txt") {
            loadData();
        }
    
    public:
        CinemaManager() {
            loadData();
        }
        
        ~CinemaManager() {
            saveData();
        }
        
        // 电影管理
        void addMovie(const Movie& movie) {
            movies.push_back(movie);
            movieMap[movie.getName()] = &movies.back();
        }
        
        Movie* findMovie(const std::string& name) {
            std::map<std::string, Movie*>::iterator it = movieMap.find(name);
            if (it != movieMap.end()) {
                return it->second;
            }
            return NULL;
        }
        
        // 影厅管理
        void addHall(const Hall& hall) {
            halls.push_back(hall);
        }
        
        Hall* findHall(int hallId) {
            for (size_t i = 0; i < halls.size(); i++) {
                if (halls[i].getHallId() == hallId) {
                    return &halls[i];
                }
            }
            return NULL;
        }
        
        // 场次管理
        void addShowtime(const Showtime& showtime) {
            showtimes.push_back(showtime);
            showtimeMap[showtime.getShowtimeId()] = &showtimes.back();
        }
        
        Showtime* findShowtime(int showtimeId) {
            std::map<int, Showtime*>::iterator it = showtimeMap.find(showtimeId);
            if (it != showtimeMap.end()) {
                return it->second;
            }
            return NULL;
        }
        
        // 订单管理
        bool bookTicket(Showtime* showtime, const std::string& name, 
                       const std::string& phone, int count, const std::vector<std::pair<int, int>>& seats) {
            // 检查座位是否可用
            for (size_t i = 0; i < seats.size(); i++) {
                if (!showtime->getHall()->isSeatAvailable(seats[i].first, seats[i].second)) {
                    return false;
                }
            }
            
            // 预订座位
            for (size_t i = 0; i < seats.size(); i++) {
                showtime->getHall()->bookSeat(seats[i].first, seats[i].second);
            }
            
            // 创建订单
            Order order(nextOrderId++, showtime, name, phone, count, seats);
            orders.push_back(order);
            bookingQueue.push(order);
            
            return true;
        }
        
        bool refundTicket(int orderId) {
            for (size_t i = 0; i < orders.size(); i++) {
                if (orders[i].getOrderId() == orderId) {
                    // 取消座位预订
                    Showtime* showtime = orders[i].getShowtime();
                    const std::vector<std::pair<int, int>>& orderSeats = orders[i].getSeats();
                    for (size_t j = 0; j < orderSeats.size(); j++) {
                        showtime->getHall()->cancelSeat(orderSeats[j].first, orderSeats[j].second);
                    }
                    
                    // 添加到退票栈
                    refundStack.push(orders[i]);
                    return true;
                }
            }
            return false;
        }
        
        // 排序功能的比较函数
        static bool compareMoviesByRating(const Movie& m1, const Movie& m2) {
            return m1.getRating() > m2.getRating();
        }
        
        static bool compareShowtimesByTime(const Showtime& s1, const Showtime& s2) {
            return s1.getTime() < s2.getTime();
        }
        
        void sortMoviesByRating() {
            std::sort(movies.begin(), movies.end(), compareMoviesByRating);
        }
        
        void sortShowtimesByTime() {
            std::sort(showtimes.begin(), showtimes.end(), compareShowtimesByTime);
        }
        
        // 数据持久化
        void saveData() {
            saveMovies();
            saveHalls();
            saveShowtimes();
            saveOrders();
        }
        
        void loadData() {
            loadMovies();
            loadHalls();
            loadShowtimes();
            loadOrders();
        }
        
        // 显示功能
        void showMovies() const {
            std::cout << "\n=== 电影列表 ===\n";
            for (size_t i = 0; i < movies.size(); i++) {
                std::cout << movies[i] << std::endl;
            }
        }
        
        void showHalls() const {
            std::cout << "\n=== 影厅列表 ===\n";
            for (size_t i = 0; i < halls.size(); i++) {
                std::cout << halls[i] << " 总座位数: " << halls[i].getTotalSeats() 
                          << " 可用座位数: " << halls[i].getAvailableSeats() << std::endl;
            }
        }
        
        void showShowtimes() const {
            std::cout << "\n=== 场次列表 ===\n";
            for (size_t i = 0; i < showtimes.size(); i++) {
                std::cout << showtimes[i] << std::endl;
            }
        }
        
        void showOrders() const {
            std::cout << "\n=== 订单列表 ===\n";
            for (size_t i = 0; i < orders.size(); i++) {
                std::cout << orders[i] << std::endl;
            }
        }
        
    private:
        // 保存数据到文件
        void saveMovies() {
            std::ofstream ofs(moviesFile.c_str());
            if (!ofs) {
                throw CinemaException("无法打开电影文件进行写入");
            }
            for (size_t i = 0; i < movies.size(); i++) {
                ofs << movies[i] << std::endl;
            }
        }
        
        void saveHalls() {
            std::ofstream ofs(hallsFile.c_str());
            if (!ofs) {
                throw CinemaException("无法打开影厅文件进行写入");
            }
            for (size_t i = 0; i < halls.size(); i++) {
                ofs << halls[i] << std::endl;
            }
        }
        
        void saveShowtimes() {
            std::ofstream ofs(showtimesFile.c_str());
            if (!ofs) {
                throw CinemaException("无法打开场次文件进行写入");
            }
            for (size_t i = 0; i < showtimes.size(); i++) {
                ofs << showtimes[i] << std::endl;
            }
        }
        
        void saveOrders() {
            std::ofstream ofs(ordersFile.c_str());
            if (!ofs) {
                throw CinemaException("无法打开订单文件进行写入");
            }
            for (size_t i = 0; i < orders.size(); i++) {
                ofs << orders[i] << std::endl;
            }
        }
        
        // 从文件加载数据
        void loadMovies() {
            std::ifstream ifs(moviesFile.c_str());
            if (!ifs) {
                return; // 文件不存在，返回
            }
            Movie movie;
            while (ifs >> movie) {
                addMovie(movie);
            }
        }
        
        void loadHalls() {
            std::ifstream ifs(hallsFile.c_str());
            if (!ifs) {
                return; // 文件不存在，返回
            }
            Hall hall;
            while (ifs >> hall) {
                addHall(hall);
            }
        }
        
        void loadShowtimes() {
            std::ifstream ifs(showtimesFile.c_str());
            if (!ifs) {
                return; // 文件不存在，返回
            }
            int showtimeId;
            std::string movieName, time;
            int hallId;
            while (ifs >> showtimeId >> movieName >> hallId >> time) {
                Movie* movie = findMovie(movieName);
                Hall* hall = findHall(hallId);
                if (movie && hall) {
                    Showtime showtime(showtimeId, movie, hall, time);
                    addShowtime(showtime);
                }
            }
        }
        
        void loadOrders() {
            std::ifstream ifs(ordersFile.c_str());
            if (!ifs) {
                return; // 文件不存在，返回
            }
            int orderId, showtimeId, ticketCount, row, col;
            std::string customerName, customerPhone;
            while (ifs >> orderId >> showtimeId >> customerName >> customerPhone >> ticketCount) {
                Showtime* showtime = findShowtime(showtimeId);
                if (showtime) {
                    std::vector<std::pair<int, int>> seats;
                    for (int i = 0; i < ticketCount; i++) {
                        ifs >> row >> col;
                        seats.push_back(std::make_pair(row, col));
                    }
                    Order order(orderId, showtime, customerName, customerPhone, ticketCount, seats);
                    orders.push_back(order);
                }
            }
        }
    };
    
    // 初始化静态成员
    int CinemaManager::nextMovieId = 1;
    int CinemaManager::nextHallId = 1;
    int CinemaManager::nextShowtimeId = 1;
    int CinemaManager::nextOrderId = 1;
}

