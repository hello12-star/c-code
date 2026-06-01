#include "include/cinema.h"
#include <iostream>
#include <string>

using namespace Cinema;
using namespace std;

void showMenu() {
    cout << "\n=== 电影院订票系统 ===\n";
    cout << "1. 添加电影\n";
    cout << "2. 添加影厅\n";
    cout << "3. 添加场次\n";
    cout << "4. 购票\n";
    cout << "5. 退票\n";
    cout << "6. 显示电影列表\n";
    cout << "7. 显示影厅列表\n";
    cout << "8. 显示场次列表\n";
    cout << "9. 显示订单列表\n";
    cout << "10. 按评分排序电影\n";
    cout << "11. 按时间排序场次\n";
    cout << "0. 退出系统\n";
    cout << "请选择操作: ";
}

int main() {
    try {
        CinemaManager manager;
        int choice;
        
        while (true) {
            showMenu();
            cin >> choice;
            
            switch (choice) {
                case 1: {
                    // 添加电影
                    string name, type;
                    int duration;
                    double rating, price;
                    cout << "请输入电影名称: ";
                    cin >> name;
                    cout << "请输入电影类型: ";
                    cin >> type;
                    cout << "请输入电影时长(分钟): ";
                    cin >> duration;
                    cout << "请输入电影评分: ";
                    cin >> rating;
                    cout << "请输入电影票价: ";
                    cin >> price;
                    
                    Movie movie(name, type, duration, rating, price);
                    manager.addMovie(movie);
                    cout << "电影添加成功!\n";
                    break;
                }
                
                case 2: {
                    // 添加影厅
                    int hallId, rows, cols;
                    cout << "请输入影厅编号: ";
                    cin >> hallId;
                    cout << "请输入影厅行数: ";
                    cin >> rows;
                    cout << "请输入影厅列数: ";
                    cin >> cols;
                    
                    Hall hall(hallId, rows, cols);
                    manager.addHall(hall);
                    cout << "影厅添加成功!\n";
                    break;
                }
                
                case 3: {
                    // 添加场次
                    int showtimeId, hallId;
                    string movieName, time;
                    cout << "请输入场次编号: ";
                    cin >> showtimeId;
                    cout << "请输入电影名称: ";
                    cin >> movieName;
                    cout << "请输入影厅编号: ";
                    cin >> hallId;
                    cout << "请输入放映时间: ";
                    cin >> time;
                    
                    Movie* movie = manager.findMovie(movieName);
                    if (!movie) {
                        cout << "电影不存在!\n";
                        break;
                    }
                    
                    Hall* hall = manager.findHall(hallId);
                    if (!hall) {
                        cout << "影厅不存在!\n";
                        break;
                    }
                    
                    Showtime showtime(showtimeId, movie, hall, time);
                    manager.addShowtime(showtime);
                    cout << "场次添加成功!\n";
                    break;
                }
                
                case 4: {
                    // 购票
                    int showtimeId, ticketCount;
                    string customerName, customerPhone;
                    cout << "请输入场次编号: ";
                    cin >> showtimeId;
                    cout << "请输入订票人姓名: ";
                    cin >> customerName;
                    cout << "请输入订票人电话: ";
                    cin >> customerPhone;
                    cout << "请输入订票数量: ";
                    cin >> ticketCount;
                    
                    Showtime* showtime = manager.findShowtime(showtimeId);
                    if (!showtime) {
                        cout << "场次不存在!\n";
                        break;
                    }
                    
                    vector<pair<int, int>> seats;
                    for (int i = 0; i < ticketCount; i++) {
                        int row, col;
                        cout << "请输入第" << i+1 << "个座位的行号和列号: ";
                        cin >> row >> col;
                        seats.push_back(std::make_pair(row, col));
                    }
                    
                    if (manager.bookTicket(showtime, customerName, customerPhone, ticketCount, seats)) {
                        cout << "购票成功!\n";
                    } else {
                        cout << "购票失败，座位已被占用!\n";
                    }
                    break;
                }
                
                case 5: {
                    // 退票
                    int orderId;
                    cout << "请输入订单编号: ";
                    cin >> orderId;
                    
                    if (manager.refundTicket(orderId)) {
                        cout << "退票成功!\n";
                    } else {
                        cout << "退票失败，订单不存在!\n";
                    }
                    break;
                }
                
                case 6: {
                    // 显示电影列表
                    manager.showMovies();
                    break;
                }
                
                case 7: {
                    // 显示影厅列表
                    manager.showHalls();
                    break;
                }
                
                case 8: {
                    // 显示场次列表
                    manager.showShowtimes();
                    break;
                }
                
                case 9: {
                    // 显示订单列表
                    manager.showOrders();
                    break;
                }
                
                case 10: {
                    // 按评分排序电影
                    manager.sortMoviesByRating();
                    cout << "电影已按评分排序!\n";
                    manager.showMovies();
                    break;
                }
                
                case 11: {
                    // 按时间排序场次
                    manager.sortShowtimesByTime();
                    cout << "场次已按时间排序!\n";
                    manager.showShowtimes();
                    break;
                }
                
                case 0: {
                    // 退出系统
                    cout << "感谢使用电影院订票系统!\n";
                    return 0;
                }
                
                default: {
                    cout << "无效的选择，请重新输入!\n";
                    break;
                }
            }
        }
    } catch (const CinemaException& e) {
        cerr << "系统错误: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "未知错误: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

