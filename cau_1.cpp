#include<bits/stdc++.h>
using namespace std;
struct Node {
    string ten;
    string msv;
    string ngaysinh;
    string que; // dd/mm/yyyy
    Node* next;
};

typedef Node* node;

node makeNode(string x, string y, string z,string v) {
    node tmp = new Node();
    tmp->ten = x;
    tmp->msv = y;
    tmp->ngaysinh = z;
    tmp->que=v;
    tmp->next = NULL;
    return tmp;
}

// Thêm vào cuoi danh sách
void insertLast(node &head, string x, string y, string z,string v) {
    node tmp = makeNode(x, y, z,v);
    if (head == NULL) head = tmp;
    else {
        node p = head;
        while (p->next != NULL) p = p->next;
        p->next = tmp;
    }
}

// In danh sách
void in(node a) {
    if (a == NULL) {
        cout << "Danh sach trong.\n";
        return;
    }
    while (a != NULL) {
        cout << a->ten << " | " << a->msv << " | " << a->ngaysinh << " | "<<a->que<<endl;
        a = a->next;
    }
}
//y 2 cau 1
void xuLyChuoiGhep(node &head) {
    node current = head;
    while (current != NULL) {
        // ghep 
        string chuoiGhep = current->msv + current->ngaysinh;
        vector<char> mangGhep(chuoiGhep.begin(), chuoiGhep.end());
        vector<int> mangSo;
        vector<char> mangKyTu;

        for (char c : chuoiGhep) {
            if (isdigit(c)) mangSo.push_back(c - '0');
            else mangKyTu.push_back(c);
        }

        // hien thi thong tin
        cout << "---------------------------------\n";
        cout << "Thanh vien: " << current->ten << endl;
        cout << "Chuoi ghep (MSSV + NgaySinh): " << chuoiGhep << endl;

        cout << "Mang Ghep: ";
        for (char c : mangGhep) cout << c << ' ';
        cout << endl;

        cout << "Mang So: ";
        for (int n : mangSo) cout << n << ' ';
        cout << endl;

        cout << "Mang Ky Tu: ";
        for (char c : mangKyTu) cout << c << ' ';
        cout << endl;

        current = current->next;
    }
}
void sapXepMangSoGiamDan(node &head) {
    node current = head;
    while (current != NULL) {
        string ghep = current->msv + current->ngaysinh;
        vector<int> mangSo;
        for (char c : ghep)
            if (isdigit(c)) mangSo.push_back(c - '0');

        sort(mangSo.begin(), mangSo.end(), greater<int>()); 

        cout << "Thanh vien: " << current->ten << endl;
        cout << "Mang so sau khi sap xep giam dan: ";
        for (int x : mangSo) cout << x << ' ';
        cout << endl;
        cout << "Do phuc tap sap xep: O(n log n)\n\n";

        current = current->next;
    }
}
void timKiem(node &head, string key) {
    bool timThay = false;
    node cur=head;
    while (cur != NULL) {
        if (cur->ten == key || cur->que == key) {
            cout << "Tim thay: " << cur->ten << " | " << cur->que << endl;
            timThay = true;
        }
        cur = cur->next;
    }

    if (!timThay) cout << "Khong tim thay.\n";
}
// Menu chuong trình
void menu() {
    cout << "\n==================== MENU ====================\n";
    cout << "1. Them sinh vien\n";
    cout << "2. Hien thi danh sach sinh vien\n";
    cout << "3. xu li ghep chuoi\n";
    cout << "4. sap xep chuoi ghep vua tao\n";
    cout << "5. tim kiem theo que hoac ten\n";
    cout << "6. Thoat\n";
    cout << "=============================================\n";
}

int main(){
	node head=NULL;
	int choice;
	do{
		menu();
		cin>>choice;
		cin.ignore();
		if(choice==1){
			string ten,msv,ngaysinh,que;
			cout << "Nhap ten sinh vien: ";
        	getline(cin, ten);
        	cout << "Nhap ma sinh vien: ";
        	getline(cin, msv);
        	cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        	getline(cin, ngaysinh);
        	cout<<"Nhap que quan: ";
        	getline(cin,que);
        	insertLast(head, ten, msv,ngaysinh,que);
    	}
    	if(choice==2){
    		in(head);
		}
		if(choice==3){
			xuLyChuoiGhep(head);
		}
		if(choice==4){
			sapXepMangSoGiamDan(head);
		}
		if(choice==5){
			cout<<"Nhap ten hoac que can tim: ";
			string x;
			getline(cin,x);
			timKiem(head,x);
		}
		if(choice==6){
			cout<<"thoat chuong trinh";
		}
	}
	while(choice!=6);
	return 0;
}
