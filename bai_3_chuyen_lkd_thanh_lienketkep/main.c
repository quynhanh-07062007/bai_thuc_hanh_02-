#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char hoten[30];
	int masv;
	float d1,d2,d3;
}Data;

typedef struct tagNode{
	Data infor;
	struct tagNode *next,*prev;
}Node;

typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
}DList;

void initList(DList *L)
{
	L->pHead =NULL;
	L->pTail=NULL;
	L->spt=0;
}

int emptyList(DList L){
	return (L.spt==0);
}

void insert_Head(DList *L,Data x)
{
	Node *pp;
	pp=(Node*) malloc(sizeof(Node));
	pp->infor=x;
	pp->next=NULL;
	pp->prev=NULL;
	if(emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else{
		pp->next=L->pHead;
		L->pHead->prev=pp;
		L->pHead=pp;
	}
	L->spt++;
}
//THEM CUOI
void insert_Tail(LList *L,Data x)
{
	Node *pp;
	pp=(Node*) malloc(sizeof(Node));
	pp->infor=x;
	pp->next=NULL;
	pp->prev=NULL;
	if(emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else{
	pp->prev=L->pTail;
    L->pTail->next=pp;
    L->pTail=pp;
	}
	L->spt++;
}

//Xoa dau
void delete_Head(DList *L)
{
	if(emptyList(*L)) return;
	Node *p=L->pHead;
	L->pHead=L->pHead->next;
	if(L->pHead!=NULL){
		L->pHead->prev=NULL;
	}
	else{
		L->pTail=NULL;
	}
	free(p);
	L->spt--;
}
//XOA CUOI
void delete_Tail(DList *L){
	if(emptyList(*L)) return;
	Node *p=L->pTail;
	L->pTail=L->pTail->prev;
	if(L->pTai!=NULL){
		L->pTail->next=NULL;
	}
	else{
		L->pHead=NULL;
	}
	free(p);
	L->spt--;
}
//Xoa sau 1 node 
void delete_After(DList *L,Node *q){
	Node *pp=q->next;
	q->next=pp->next;
	if(pp->next!=NULL){
		pp->next->prev=q;
	}
	else{
		L->pTail=q;
	}
	free(pp);
	L->spt--;
}

//Xoa theo ma
void delete_ID (DList *L,int id){
	Node *pp=L->pHead;
	while(pp!=NULL &&(pp->infor.masv !=id)){
		pp=pp->next;
	}
	if(pp!=NULL){
		if(pp==L->pHead) delete_Head(L);
		else if(pp==L->pTail) delete_Tail(L);
		else delete_After(L,pp->prev);
	}
}

//Xoa theo ten
void delete_Name(DList *L,char name[30]){
	Node *pp=L->pHead;
	while(pp!=NULL && !strstr(pp->infor.hoten,name)){
		pp=pp->next;
	}
	if(pp!=NULL){
		if(pp==L->pHead) delete_Head(L);
		else if (pp==L->pTail) delete_Tail(L);
		else delete_After(L,pp->prev);
	}
}

//Tim kiem theo ten
Node*search_Name(DList L, char name[30]){
	Node *pp=L.pHead;
	while(pp!=NULL && !strstr(pp->infor.hoten,name))
		pp=pp->next;
	return pp;
}

//Tim kiem theo ma
Node*search_ID(DList L, int id){
	Node *pp=L.pHead;
	while(pp!=NULL && (pp->infor.masv!=id))
		pp=pp->next;
	return pp;
}

//Sap xep dsach theo ten
void sort_Name(DList *L){
	if(L->spt<2) return;
	for(Node*p=L->pHead;p!=L->pTail;p=p->next){
		for(Node*q=p->next;q!=NULL;q=q->next){
			if(strcmp(p->infor.hoten,q->infor.hoten)>0){
				Data temp=p->infor;
				p->infor=q->infor;
				q->infor=temp;
			}
		}
	}
}


//Tach danh sach
void tach(DList L,DList *L1, DList *L2){
	initList(L1);
	initList(L2);
	Node *pp=L.pHead;
	while(pp!=NULL){
		if(pp->infor.d1<5|| 
			pp->infor.d2<5||
			pp->infor.d3<5){
			insert_Tail(L1,pp->infor);
		}	
		else{
			insert_Tail(L2,pp->infor);
		pp=pp->next;
		}
	}
}

//Ghep danh sach
void ghep(DList L1,DList L2,DList*L){
	initList(L); 
	Node*p1=L1.pHead;
	Node*p2=L2.pHead;
	if(L1.spt<L2.spt){
		while(p1!=NULL){
			insert_Head(L, p1->infor);
			insert_Head(L, p2->infor);
			p1=p1->next;
			p2=p2->next;
		}
		while(p2!=NULL){
			insert_Head(L,p2->infor);
			p2=p2->next;
		}
	}
	else{
		while(p2!=NULL){
			insert_Head(L, p1->infor);
			insert_Head(L, p2->infor);
			p1=p1->next;
			p2=p2->next;
		}
		while(p1!=NULL){
			insert_Head(L,p2->infor);
			p1=p1->next;
		}
	}
}

void nhap(Data *x){
	printf("Nhap ma sv: ");
	scanf("%d",&(x->masv));
	if(x->masv>0){
		printf("Nhap ho ten: ");
		scanf("%s",(x->hoten));
		printf("Nhap mon diem 1: ");
		scanf("%f",&(x->d1));
		printf("Nhap mon diem 2: ");
		scanf("%f",&(x->d2));
		printf("Nhap mon diem 3: ");
		scanf("%f",&(x->d3));
	}
}

void in(Data x){
	printf("Ten: %s,Ma: %d,Diem 1: %.2f,Diem 2: %.2f,Diem 3: %.2f\n",
			x.hoten,x.masv,x.d1,x.d2,x.d3);
}

void processList(LList L){
	Node *pp=L.pHead;
	while(pp != NULL){
		in(pp->infor);
		pp=pp->next;
	}
}

int main(){
	DList  L,L1, L2, L_Ghep;
	int kt=0, id;
	char name[30];
	Data x;
	Node *kq;
	initList(&L);
	initList(&L1);
	initList(&L2);
	initList(&L_Ghep);
	do{
		printf("\n====CHUONG TRINH LAM VIEC VOI DSLK DON SV====\n");
		printf("1: Them nut vao dau danh sach\n");
		printf("2: Them nut vao cuoi danh sach\n");
        printf("3. Xoa nut dau danh sach\n");
        printf("4. Xoa sinh vien theo ma\n");
        printf("5. Xoa sinh vien theo ten\n");
        printf("6. Tim sinh vien theo ma\n");
        printf("7. Tim sinh vien theo ten\n");
        printf("8. Sap xep danh sach theo ten\n");
        printf("9. Tach danh sach theo diem\n");
        printf("10. Ghep hai danh sach\n");
        printf("11. In danh sach\n");
        printf("0. Thoat chuong trinh\n");
        
        printf("Moi ban chon: ");
        int chon;
        scanf("%d",&chon);
        switch(chon){
        	case 1:
        		printf("Nhap thong tin sv can them dau: \n");
        		nhap(&x);
        		if(x.masv>0) insert_Head(&L,x);
        		break;
        	case 2:
        		printf("Nhap thong tin sv can them cuoi: \n");
        		nhap(&x);
        		if(x.masv>0) insert_Tail(&L,x);
        		break;
        	case 3:
        		if(!emptyList(L)){
        			delete_Head(&L);
        			printf("Da xoa nt dau danh sach\n");
				}
				else{
					printf("Danh sach rong");
				}
				break;
			case 4:
				printf("Nhap ma sv can xoa: ");
				scanf("%d",&id);
				delete_ID(&L,id);
				break;
			case 5:
				printf("Nhap ten sinh vien can xoa:");
				scanf(" %[^\n]",name);
				delete_Name(&L,name);
				break;
			case 6:
				printf("Nhap ma sv can tim:");
				scanf("%d",&id);
				kq=search_ID(L,id);
				if(kq!=NULL) in(kq->infor);
				else printf("Khong tim thay sv\n");
				break;
			case 7:
				printf("Nhap ten sv can tim:");
				scanf(" %[^\n]",name);
				kq=search_Name(L,name);
				if(kq!=NULL) in(kq->infor);
				else printf("Khong tim thay sv\n");
				break;
			case 8:
				sort_Name(&L);
				processList(L);
				break;
			case 9:
				tach(L,&L1,&L2);
				printf("Danh sach 1:\n");
				processList(L1);
				printf("Danh sach 2:\n");
				processList(L2);
				break;
			case 10:
				if(emptyList(L1) && emptyList(L2)){
					tach(L,&L1,&L2);
				}
				ghep(L1,L2,&L_Ghep);
				printf("Danh  sach sau khi ghep\n");
				processList(L_Ghep);
				break;
			case 11:
				printf("DANH SACH SV\n");
				processList(L);
				break;
			case 0:
				kt=1;
				break;
			default:
				printf("Lua chon khong hop le");
		}
	}while (kt==0);
		return 0;
}



