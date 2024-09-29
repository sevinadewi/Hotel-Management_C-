#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void daftar(int *std, int *suit, int *dlx, int *pre){
	cout<<"\n-----------------------KAMAR--------------------\n";
	cout<<"|----TIPE KAMAR-----------------|-----TARIF-----|\n";
	cout<<"|1. Standart Room		|Rp"<<*std<<"/hari	|\n";
	cout<<"|2. Deluxe Room			|Rp"<<*dlx<<"/hari	|\n";
	cout<<"|2. Suite Room			|Rp"<<*suit<<"/hari	|\n";
	cout<<"|2. Presidential  Room		|Rp"<<*pre<<"/hari	|\n";
	cout<<"-------------------------------------------------\n";
			
	cout<<"\n----------------------MEETING ROOM---------------------\n";
	cout<<"| NO	| Tipe Ruangan 	| Kapasitas 	| Harga 	|\n";
	cout<<"|-------------------------------------------------------|\n";
	cout<<"| 1.	| Jodipati Room	| 100 seat	| Rp.4500000	|\n";
	cout<<"| 2.	| Amarta Room	| 50 seat	| Rp.3500000	|\n";
	cout<<"|-------------------------------------------------------|\n";
}
void tipekamar(){
	cout<<"\n---------TIPE KAMAR-------------\n";
	cout<<"|1. Standart Room		|\n";
	cout<<"|2. Deluxe Room			|\n";
	cout<<"|2. Suite Room			|\n";
	cout<<"|2. Presidential  Room		|\n";
	cout<<"----------------------------------\n";
}

void lambang(){	 
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<"\t\t\t\t*";
		}
	}
}

int durasi(int m,int dur){
	
	if(dur==1){
		return m;
	}else{
		return m+durasi(m, dur-1);
	}
}

struct data{
	string nama, telp, ktp, alamat, gr;
};

int main(){
	int pilihan, h;
	int *pil=&pilihan, total;
	int bayar, kembali;
	data cust;
	string t, s, q, w;
	
	lambang();	
	cout<<"\n\n\n\n\n\n";
	
	cout<<"\n\t\t\t\t=========================================================\n";
	cout<<"\t\t\t\t|		SELAMAT DATANG DI HOTEL PENTIUM		|\n";
	cout<<"\t\t\t\t=========================================================\n";
	
	cout<<"\n\n\n\n\n\n";
	lambang();
	
	system("pause");
	system("cls");
	int std = 400000, dlx=600000, suit=1000000, pre=1500000;
	bool loop=true;
	
	while(loop){
		
	cout<<"+---------------------------------------+\n";
	cout<<"|		MENU CUSTOMER		|\n";
	cout<<"+---------------------------------------+\n";
	cout<<"|1. Daftar Penawaran			|\n";
	cout<<"|2. Pemesanan				|\n";
	cout<<"|3. Pembayaran				|\n";
	cout<<"|4. Riwayat Pemesan			|\n";
	cout<<"|5. Exit				|\n";
	cout<<"+---------------------------------------+\n";
	
	cout<<"\nMasukkan pilihan : ";cin>>*pil;
	
	switch(*pil){
		case 1:
			daftar(&std, &dlx, &suit, &pre);
			
			system("pause");
			system("cls");
			break;
		case 2 :
			int a, b, e;
			cout<<"\n---------PILIHAN PEMESANAN--------------\n";
			cout<<"|1. Kamar				|\n";
			cout<<"|2. Ruang pertemuan			|\n";
			cout<<"------------------------------------------\n";
			
			cout<<"\nMasukkan pilihan : ";cin>>a;
			cin.ignore();
;			if(a==1){
				ofstream file("datacust.txt", ios::app);
				cout<<"\nNama\t: ";getline(cin,cust.nama);
				cout<<"NO.HP\t: ";cin>>cust.telp;
				cin.ignore();
				cout<<"Alamat\t: ";getline(cin,cust.alamat);
				cout<<"NO.KTP\t: ";cin>>cust.ktp;
				
				
				file<<"\nNama\t: "<<cust.nama<<endl;
				file<<"NO.HP\t: "<<cust.telp<<endl;
				file<<"Alamat\t: "<<cust.alamat<<endl;
				file<<"NO.KTP\t: "<<cust.ktp<<endl;
				file.close();
				system("START /MIN NOTEPAD datacust.txt");
				tipekamar();
				
				cout<<"\nJumlah tipe kamar yang anda pesan : ";
				cin>>b;
				
				int jml_pesan[b], tipe[b], jml_kmr[b], tagihan[b];
				int in[b], lama[b];
				
				for(int i=0;i<b;i++){
					cout<<"\nPilih tipe kamar ke-"<<i+1<<": ";cin>>tipe[i];
				
				
					if(tipe[i]==1){
						cout<<"\n**Standart Room**\n";
						cout<<"Jumlah kamar		: ";cin>>jml_kmr[i];
						cout<<"Tanggal check in	: ";cin>>in[i];
						cout<<"Lama menginap		: ";cin>>lama[i];
						tagihan[i]=std * jml_kmr[i] * lama[i];
						cout<<"Biaya kamar 		: "<<tagihan[i]<<endl;
						
					}else if(tipe[i]==2){
						cout<<"\n**Deluxe Room**\n";
						cout<<"Jumlah kamar		: ";cin>>jml_kmr[i];
						cout<<"Tanggal check in	: ";cin>>in[i];
						cout<<"Lama menginap		: ";cin>>lama[i];
						
						tagihan[i]=dlx * jml_kmr[i]*lama[i];
						cout<<"Biaya kamar 		: "<<tagihan[i]<<endl;
						
					}else if(tipe[i]==3){
						cout<<"\n**Suite Room**\n";
						cout<<"Jumlah kamar		: ";cin>>jml_kmr[i];
						cout<<"Tanggal check in	: ";cin>>in[i];
						cout<<"Lama menginap		: ";cin>>lama[i];
						tagihan[i]=suit * jml_kmr[i]*lama[i];
						cout<<"Biaya kamar 		: "<<tagihan[i]<<endl;
						
					}else if(tipe[i]==4){
						cout<<"\n**Presidential Room**\n";
						cout<<"Jumlah kamar		: ";cin>>jml_kmr[i];
						cout<<"Tanggal check in	: ";cin>>in[i];
						cout<<"Lama menginap		: ";cin>>lama[i];
						tagihan[i]=pre * jml_kmr[i]*lama[i];
						cout<<"Biaya kamar		: "<<tagihan[i]<<endl;
						
					}else{
						cout<<"Pilihan anda tidak tersedia\n";
					}		
				}
					for(int i=0;i<b;i++){
						total+=tagihan[i];
					}
					ofstream file2("tagihan.txt");
					cout<<"\nTotal yang harus dibayar	: "<<total<<endl;
					
					file2<<"\nTotal yang harus dibayar	: "<<total<<endl;
					
					file2.close();
					system("START /MIN NOTEPAD tagihan.txt");
					
					
	
			}if(a==2){
				cout<<"\nNama Group	: ";getline(cin,cust.gr);
				cout<<"NO.HP		: ";cin>>cust.telp;
				cout<<"Nama kontak	: ";cin>>cust.nama;
				cin.ignore();
				cout<<"Alamat		: ";getline(cin,cust.alamat);
				cout<<"NO.KTP		: ";cin>>cust.ktp;
				
				string meetroom[2][1]={"Jodipati Room","Amarta Room"};
				string kapasitas[2][1]={"100 seat","50 seat"};
				int harga[2][1]={4500000,3500000};
				
				cout<<"\n-----------------------MEETING ROOM-----------------------\n";
				
				cout<<"| NO	| Tipe Ruangan 	| Kapasitas 	| Harga 	|\n";
				cout<<"-------------------------------------------------------------\n";
				for(int i=0;i<2;i++){
						cout<<"| "<<i+1<<"	| "<<meetroom[i][0]<<"	| "<<kapasitas[i][0]<<"	| "<<harga[i][0]<<"	| \n";
				}
				cout<<"-------------------------------------------------------------\n";
				cout<<"NB : Harga sewa per durasi 12 jam\n";
				
				int  sewa, dur, waktu;
				int hasil;
				int m=12;
				
				
				cout<<"\nPilih tipe meeting room : ";cin>>h;
				
				if(h==1){
					cout<<"\n**Jodipati Room**\n";
					cout<<"Tanggal reservasi		: ";cin>>sewa;
					cout<<"Waktu reservasi			: ";cin>>waktu;
					cout<<"Kloter sewa (1 kloter=12 jam)	: ";cin>>dur;
					hasil=durasi(m, dur);
					cout<<"Durasi sewa			: "<<hasil<<endl;
					
					ofstream file3("bayar jodi.txt");
					total=harga[0][0];
					cout<<"Total harga yang perlu dibayar	: "<<total<<endl;
					file3<<"Total harga yang perlu dibayar	: "<<total<<endl;
					file3.close();
					system("START /MIN NOTEPAD bayar jodi.txt");
					
				} else if(h==2){
					cout<<"\n**Amarta Room**\n";
					cout<<"Tanggal reservasi		: ";cin>>sewa;
					cout<<"Waktu reservasi			: ";cin>>waktu;
					cout<<"Kloter sewa (1 kloter=12 jam)	: ";cin>>dur;
					hasil=durasi(m, dur);
					cout<<"Durasi sewa			: "<<hasil<<endl;
					
					ofstream file4("bayar amar.txt");
					total=harga[1][0]*dur;
					cout<<"Total harga yang perlu dibayar	: "<<total<<endl;
					file4<<"Total harga yang perlu dibayar	: "<<total<<endl;
					file4.close();
					system("START /MIN NOTEPAD bayar amar.txt");
				}				
			}
			system("pause");
			system("cls");
			break;
		
		case 3 :{
			ifstream readfile2("tagihan.txt");
			while(getline(readfile2,s)){
				cout<<s<<endl;
			}
			readfile2.close();
			
			if(h==1){
			ifstream readfile3("bayar jodi.txt");
			while(getline(readfile3,q)){
				cout<<q<<endl;
			}
			readfile3.close();
			
			}else if(h==2){
			ifstream readfile4("bayar amar.txt");
			while(getline(readfile4,w)){
				cout<<w<<endl;
			}
			readfile4.close();
			}
			
			byr :
			cout<<"Uang bayar			: ";cin>>bayar;
			
			if(bayar>=total){
				kembali=bayar-total;
				cout<<"Uang kembali			: "<<kembali<<endl;
			}else{
				cout<<"Uang yang anda bayarkan belum mencukupi\n";
				goto byr;
			}
			
			system("pause");
			system("cls");
			break;
		}
			
		case 4 :{
			ifstream readfile("datacust.txt");
			while(getline(readfile,t)){
				cout<<t<<endl;
			}
			readfile.close();
		
			system("pause");
			system("cls");
			break;
		}
		
		case 5 :{
	
			system("cls");
			
			cout<<"\n\t\t\t\t=========================================================\n";
			cout<<"\t\t\t\t|		TERIMA KASIH ATAS KUNJUNGANNYA		|\n";
			cout<<"\t\t\t\t=========================================================\n";
	
			loop=false;
			break;
		}
			
	}
}
}
