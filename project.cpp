#include <iostream>   
#include <fstream>   
#include <vector>
#include <string>
using namespace std;
struct Member {
    int id;             
    string name;       
    string type;        
    string expiry;    
};
struct Trainer {
    int id;                    
    string name;                
    string specialization;
};
struct Attendance {
    int memberID;      
    string date;       
};
struct Fee {
    int memberID;      
    int amount;         
    string date;        
};
vector<Member> members;
vector<Trainer> trainers;
void loadMembers() {
    ifstream file("members.txt");   
    Member m;
    while (file >> m.id) {
        file.ignore();
        getline(file, m.name);
        getline(file, m.type);
        getline(file, m.expiry);
        members.push_back(m);    
    }
    file.close();
}
void saveMembers() {
    ofstream file("members.txt");  
    for (auto& m : members) {
        file << m.id << "\n"
            << m.name << "\n"
            << m.type << "\n"
            << m.expiry << "\n";
    }
    file.close();
}
void addMember() {
    Member m;
    cout << "Enter Member ID: ";
    cin >> m.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, m.name);
    cout << "Enter Membership Type: ";
    getline(cin, m.type);
    cout << "Enter Expiry Date: ";
    getline(cin, m.expiry);
    members.push_back(m);   
    saveMembers();          
    cout << "Member Added Successfully!\n";
}
void displayMembers() {
    if (members.empty()) {
        cout << "No Members Found!\n";
        return;
    }
    for (auto& m : members) {
        cout << "\nID: " << m.id
            << "\nName: " << m.name
            << "\nType: " << m.type
            << "\nExpiry: " << m.expiry << "\n";
    }
}
void searchMember() {
    int id;
    cout << "Enter Member ID: ";
    cin >> id;
    for (auto& m : members) {
        if (m.id == id) {
            cout << "\nName: " << m.name
                << "\nType: " << m.type
                << "\nExpiry: " << m.expiry << "\n";
            return;
        }
    }
    cout << "Member Not Found!\n";
}
void loadTrainers() {
    ifstream file("trainers.txt");
    Trainer t;
    while (file >> t.id) {
        file.ignore();
        getline(file, t.name);
        getline(file, t.specialization);
        trainers.push_back(t);
    }
    file.close();
}
void saveTrainers() {
    ofstream file("trainers.txt");
    for (auto& t : trainers) {
        file << t.id << "\n"
            << t.name << "\n"
            << t.specialization << "\n";
    }
    file.close();
}
void addTrainer() {
    Trainer t;
    cout << "Enter Trainer ID: ";
    cin >> t.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, t.name);
    cout << "Enter Specialization: ";
    getline(cin, t.specialization);
    trainers.push_back(t);
    saveTrainers();
    cout << "Trainer Added Successfully!\n";
}
void displayTrainers() {
    if (trainers.empty()) {
        cout << "No Trainers Found!\n";
        return;
    }

    for (auto& t : trainers) {
        cout << "\nID: " << t.id
            << "\nName: " << t.name
            << "\nSpecialization: " << t.specialization << "\n";
    }
}
void markAttendance() {
    Attendance a;
    cout << "Enter Member ID: ";
    cin >> a.memberID;
    cin.ignore();
    cout << "Enter Date (dd/mm/yyyy): ";
    getline(cin, a.date);
    ofstream file("attendance.txt", ios::app);
    file << a.memberID << "\n" << a.date << "\n";
    file.close();
    cout << "Attendance Marked Successfully!\n";
}
void viewAttendance() {
    ifstream file("attendance.txt");
    int id;
    string date;
    while (file >> id) {
        file.ignore();
        getline(file, date);
        cout << "Member ID: " << id << " Date: " << date << "\n";
    }
    file.close();
}
void addFee() {
    Fee f;
    cout << "Enter Member ID: ";
    cin >> f.memberID;
    cout << "Enter Fee Amount: ";
    cin >> f.amount;
    cin.ignore();
    cout << "Enter Date: ";
    getline(cin, f.date);
    ofstream file("fees.txt", ios::app);
    file << f.memberID << "\n"
        << f.amount << "\n"
        << f.date << "\n";
    file.close();
    cout << "Fee Added Successfully!\n";
}
void searchFee() {
    int id, mid, amount;
    string date;
    bool found = false;
    cout << "Enter Member ID: ";
    cin >> id;
    ifstream file("fees.txt");
    while (file >> mid >> amount) {
        file.ignore();
        getline(file, date);
        if (mid == id) {
            cout << "Amount: " << amount << " Date: " << date << "\n";
            found = true;
        }
    }
    file.close();
    if (!found)
        cout << "No Fee Record Found!\n";
}

void viewFees() {
    ifstream file("fees.txt");
    int mid, amount;
    string date;
    while (file >> mid >> amount) {
        file.ignore();
        getline(file, date);
        cout << "Member ID: " << mid
            << " Amount: " << amount
            << " Date: " << date << "\n";
    }
    file.close();
}
int main() {
    loadMembers();
    loadTrainers();
    int choice;
    while (true) {
        cout << "\n======== GYM MANAGEMENT SYSTEM ========\n";
        cout << "1. Add Member\n";
        cout << "2. Display Members\n";
        cout << "3. Search Member\n";
        cout << "4. Add Trainer\n";
        cout << "5. Display Trainers\n";
        cout << "6. Mark Attendance\n";
        cout << "7. View Attendance\n";
        cout << "8. Add Fee\n";
        cout << "9. Search Fee\n";
        cout << "10. View Fees\n";
        cout << "11. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice) {
        case 1: addMember(); break;
        case 2: displayMembers(); break;
        case 3: searchMember(); break;
        case 4: addTrainer(); break;
        case 5: displayTrainers(); break;
        case 6: markAttendance(); break;
        case 7: viewAttendance(); break;
        case 8: addFee(); break;
        case 9: searchFee(); break;
        case 10: viewFees(); break;
        case 11: cout << "Exiting Program...\n"; return 0;
        default: cout << "Invalid Choice. Enter the valid choice between 1 to1. \n";
        }
    }
}
