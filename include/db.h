#include <stdexcept>
#include <string>
#include <iostream>

class Database{

    private: 
    
    //constructor that helps creating instance of db(e.g. sales.db) accepts name of the database, username, password. 
    //ToDo
    Database(const std::string &database, const std::string &username, const std::string &password);
    //destructor that disconnects the connection if connected.
    //ToDo
    ~Database() {
        if(connected)
            connected = false;
    }
    public:
    //member variable "db" is of string type
    //ToDo
    std::string db;
    //member variable "username" is of string type
    //ToDo
    std::string username;
    //member variable "password" is of string type
    //ToDo
    std::string password;
    //member variable "connected" is of boolean type
    //The "connected" is set to false initially.
    //ToDo
    bool connected {false};
    //member variable "instance" is static 
    //"instance" (pointer to Database) is a staic variable that stores the instance of the database. Its value is set in the function "getInstance"
    //ToDo
    static Database* instance;
    //"getInstance" that creates and returns the instance of the database. If called first time it sets the username and password. However, subsequent time, it matches the database name, username and password and returns the previous instance if matched else it throws std::runtime_error("invalid database name, username or password"). We are using Singleton Design Pattern that creates only one instance of the databse. The instance is still created by the constructor.
    //ToDo
    static Database* getInstance(const std::string& database, const std::string& username, const std::string& password) {
        if (!instance) 
            instance = new Database(database, username, password);
        else {
            if ((instance->db == database) && (instance->username == username) && (instance->password == password)) {
                return instance;
            }
            else 
                throw std::runtime_error("invalid database name, username, or password");
        }
        return instance;
    }
    
    //"connect" that sets "connected" to true (return void)
    //ToDo
    void connect() {
        connected = true;
    }
    //"disconnect" that sets "connected" to false (return void)
    //ToDo
    void disconnect() {
        connected = false;
    }
    // retrun status of connected true/false (return bool)
    //ToDo
    bool isConnected() const {
        return connected;
    }
    //overload the new operator that allocates memory using malloc of given size and returns pointer of type void and prints " overloaded new " (cout is okay in this case). std::cout << "overloaded new ";
    //If the memory allocation fails it should throw std::bad_alloc()
    //ToDo
    void *operator new(size_t size) {
        void* ptr = malloc(size);
        std::cout << "overloaded new ";
        if(ptr == nullptr)
            throw std::bad_alloc();
    }
    //overload the delete operator that deallocates memory and prints "overloaded delete " (cout is okay in this). std::cout << "overloaded delete ";
    //ToDo
    void operator delete(void* ptr) {
        free(ptr);
        std::cout << "overloaded delete ";
    }
    //set_username and get_username for username
    //ToDo
    void set_username(const std::string& user) {
        username = user;
    }
    //ToDo
    std::string get_username()  const {
        return username;
    }
    //set_password and get_password for password.
    //ToDo
    void set_password(const std::string& pass) {
        password = pass;
    }
    //ToDo
    std::string get_password() const {
        return password;
    }
    //The static "resetInstance" as defined below.
    static void resetInstance();
};