#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>//��������̨����
#include<stdio.h>
#include<stdlib.h>//��Ҫ���ڵ���system����
#include<string.h>
#include<conio.h>//��Ҫ���ڵ���getch����

//��Ա��Ϣ�ṹ��
struct tex1         //�ַ��������ʼ��һ��0���Է�ֹ������ʱ���ڴ�й¶�����������
{
	char name[250] = { 0 };//����       
	char office[250] = { 0 };//��λ
	char telephone[250] = { 0 };//�̶��绰 
	char smartphone[250] = { 0 };//�ƶ��绰 
	char type[250] = { 0 };//����
	char email[250] = { 0 };//�����ʼ� 
	char qq[250] = { 0 };//QQ
	char mark[20] = { 0 };//������ϵ�˵ı�־
};

//���ڴ�������Ľṹ��
struct tex
{
	struct tex1 tex1;//��ϵ����Ϣ�ṹ�� 
	struct tex* next;//����ָ��
};

//���ڴ���ҳ����Ϣ�Ľṹ��
struct page
{
	struct page* previous = NULL;//��һҳλ��

	struct tex* stu[9];//������ÿ9���洢ÿ����Ա��ָ�룬����ͨѶ¼�б��ȡ��Ա��Ϣ

	struct page* next = NULL;//��һҳλ��
};

//�������Ʋ���Ϊ��������

int maincai();//���˵���ʾ����

int filetest();//ͨѶ¼�ļ��пպ���

void create();//��ʼ��ϵ��¼�뺯��

void adding();//������ϵ��ĸ����

void add2();//������ϵ���Ӻ���

void finding();//������ϵ�˺���

struct page* search_v3(struct tex* head, char search_name[250]);//ģ������ģ��

int del(struct tex* p, struct tex* head_member);//ɾ����ϵ��ģ��

void changing(struct tex* q,struct tex* head_member);//�޸���ϵ��ģ��

struct page* addpage();//ҳ�洴������

int culpage();//ҳ����㺯��

struct tex* show(char search_name[250], struct page* head_page);//��ҳ��ʾ����

void inizaize();// ��ʼ��ͨѶ¼����
 
struct tex* reading();//�ļ�����������

void writing(struct tex* head);//����д���ļ�����

void display(struct tex* gp,int i);//��ʾ������ϵ�˺���

void destroy(struct tex* head);//�������ٺ���

void often();//������ϵ�˺���

void often_out(struct tex* q, struct tex* head_member);//������ϵ���Ƴ�ģ��

void often_in(struct tex* q, struct tex* head_member);//������ϵ������ģ��

struct page* often_distinguish(struct tex* head, char mark[20]);//������ϵ���ж�ģ��

int exiting();    //�û��˳�ȷ�Ϻ���

int people;//ȫ�ֱ��������ڼ�¼¼������

//������
//�����򱻵�һ�δ�ʱ���������ļ�����δ�˳��������ѭ�����й���ѡ��
int main() {
	system("color F1");          //��������̨����ɫ��������ɫ

	FILE* fpq, * fpz, * file;    //�����￪ʼ�Ĳ������ڼ���û��Ƿ�Ϊ��һ�δ򿪳���ifer.dat�����������
	file = fopen("ifer.dat", "r");
	if (file == NULL) {
		fpz = fopen("tencures.txt", "w+"); fclose(fpz);
	}
	fpq = fopen("ifer.dat", "w+");
	fclose(fpq);                 //����һע������ʾ�ķ�Χ
	                  
	int menu,pan=0;             //menu���ڵ�����ʾ���˵�����,pan�����ж��û����˳���Ը
	char ch,s[]="/e";          //��¼�û��Ĺ���ѡ��/e�ǳ�����ϵ�˵ĸ����
	menu = maincai();         //��ʾ���˵�
	printf("\t\t\t\t��������ѡ������Ҫ�Ĺ��ܣ�");
	do {
		ch = _getch();
		switch (ch)
		{
		case '1': system("cls"); adding(); system("cls"); menu = maincai(); //������ϵ��
			printf("\t\t\t\t��������ѡ������Ҫ�Ĺ��ܣ�"); break;

		case '2': system("cls"); finding(); system("cls"); menu = maincai(); //������ϵ��
			printf("\t\t\t\t��������ѡ������Ҫ�Ĺ��ܣ�"); break;

		case '3': system("cls"); often(); system("cls"); menu = maincai(); //������ϵ��
			printf("\t\t\t\t��������ѡ������Ҫ�Ĺ��ܣ�"); break;

		case '4':system("cls"); show(s, NULL); system("cls"); menu = maincai(); //�鿴������ϵ��
			printf("\t\t\t\t��������ѡ������Ҫ�Ĺ��ܣ�"); break;

		case '5':system("cls"); inizaize(); system("cls"); menu = maincai(); //��ʼ����ϵ��
			printf("\t\t\t\t��������ѡ������Ҫ�Ĺ��ܣ�"); break;

		case '6': system("cls"); pan = exiting();  if (pan == 1) { break; }system("cls"); menu = maincai(); //�˳�ϵͳ
			printf("\t\t\t\t��������ѡ������Ҫ�Ĺ��ܣ�"); break;

		default: system("cls");  menu = maincai(); 
			printf("\t\t\t\t�����������Ĺ������֣�\a"); break; //��ֹ�û������쳣�Ĺ�������
		}
	} while (pan != 1 );
            printf("\n\n\n\n\n\n\n\t\t\t\t���ѳɹ��˳�ϵͳ��\n\n\n\n\n\n\n\n\t\t\t\t");
	return 0;
}

//���ͨѶ¼�ļ��Ƿ�Ϊ�յĺ���
//������ֹͨѶ¼Ϊ��ʱ�û�ʹ�ò��ң��鿴�ȹ��ܴӶ����Ǳ�ڵı���
int filetest()
{
	FILE* fp;
	fp = fopen("tencures.txt", "r");
	getc(fp);//feof������Ч��ǰ�������ٶ�ȡ�ļ��е�һ���ַ�
	if (feof(fp))
	{
		printf("\n\n\n\n\n\n\n\t\t\t\t��ǰͨѶ¼Ϊ�գ�����¼����ϵ��\n\n\t\t\t\t");
		system("pause");
		fclose(fp);
		return 1;
	}
	else
	{
		fclose(fp);
		return 0;
	}
}

//�˳�ȷ��ģ��
 int exiting() {
	int pan=0;
	char ch;
	printf("\n\n\n\n\n\n\n\t\t\t\t��ȷ��Ҫ�˳�������\n");
	printf("\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t1.��\n\t\t\t\t2.��\n");
	do {
        ch = _getch();
		switch (ch) {
		case '1': system("cls"); pan = 1; goto ending;
		case '2':system("cls"); pan = 2; goto ending;
		default:system("cls"); 
			printf("\n\n\n\n\n\n\n\t\t\t\t��ȷ��Ҫ�˳�������\n\t\t\t\t----------------------------------\n\t\t\t\t1.��\n\t\t\t\t2.��\n\n"); 
			printf("\n\n\n\n\n\n\n\t\t\t\t��������ȷ��ѡ��\n"); break;
		}
	} while (1);
	ending:
	return pan;
}

//���˵���ʾ
int maincai() { 
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t��ӭʹ�ñ�ͨѶ¼��\n");
	printf("\t\t\t\t--------------------------------------------------------------\n");
	printf("\t\t\t\t|                 1.������ϵ��                               |\n");
	printf("\t\t\t\t|                 2.������ϵ��                               |\n");
	printf("\t\t\t\t|                 3.������ϵ��                               |\n");
	printf("\t\t\t\t|                 4.�鿴��ϵ��                               |\n");
	printf("\t\t\t\t|                 5.��ʼ��ͨѶ¼                             |\n");
	printf("\t\t\t\t|                 6.�˳�ϵͳ                                 |\n");
	printf("\t\t\t\t--------------------------------------------------------------\n");
	return 0;
}

//��ʼ��ϵ��¼�� 
//��һ��¼��ʹ�ñ�������Ϣ�ߴ���ķ�ʽ��������ļ�����������������鷳
void create()
{
	FILE* fp;
	char n1,n2,oi;            //n1�����ж��û��Ƿ���Ҫ����¼����ϵ�ˣ�n2�����ж��û��Ƿ���Ҫֱ���˳���oi�����ж��Ƿ����������
	struct tex1 tex1;        //�����ṹ���Դ�����ϵ����Ϣ
	struct tex *p2;         //p2����Ϊ������ʾ��������ʵʱ������ָ�룬��ͨ��������ʾ����ʵ�����õĽ������Ч��
	int i=0, mem = 1;      //i������ʾ��¼����ϵ�˸�����mem�����ƶ�д���ļ��Ĺ��

	fp = fopen("tencures.txt", "w"); //�˲���Ϊ���ļ�
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}                               //����һע��

	printf("\n\n\n\n\n\t\t\t\t��1�½���ϵ�ˣ���e�˳�");  //�˲���Ϊ�ж��û��Ƿ���Ҫֱ���˳���ʹ��goto�����������ת
	while (1) {
        n2 = _getch();
		switch (n2) {
		case 'e':system("cls"); goto end;
		case '1':system("cls"); goto begin;
		default: system("cls"); printf("\n\n\n\n\n\t\t\t\t��������ȷ��ѡ�\n\n\t\t\t\t"); system("pause");
			system("cls"); printf("\n\n\n\n\n\t\t\t\t��1�½���ϵ�ˣ���e�˳�"); break;
		}
	}                                  //����һע��

begin:               // ¼�����ʼ��ת�ڵ�
	p2 = (struct tex*)malloc(sizeof(struct tex));
	
	    tex1.name[0] = '\0';//��ֹ������ʱ�������
	    tex1.office[0] = '\0';
	    tex1.telephone[0] = '\0';
	    tex1.smartphone[0] = '\0';
	    tex1.type[0] = '\0';
	    tex1.email[0] = '\0';
        tex1.qq[0] = '\0';
		tex1.mark[0] = '\0';
		

	   //�˲���һ����¼�����ݲ�д���ļ���ʹ��[^\n]����֤��������ո�
		i++;                           
	name:                //�����������ֵ���ת�ڵ�
		p2->tex1 = tex1;//������ʾ��Ϣ
		display(p2, i);

		printf("������������");
		scanf("%[^\n]", tex1.name);
		getchar();                    //getchar�������ջ������еĻس�
		if (!strcmp(tex1.name, "\0"))//����������Ϊ��ѡ���������Ϊ�ջ�Ӱ���ҳ��ʾ����������
		{
			system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t����������Ϊ�գ��Ƿ�ȷ������?\n"); 
			printf("\n\t\t\t\t----------------------------------\n"); 
			printf("\t\t\t\tȷ�ϣ�y��  �������루��������\n"); 
			oi = _getch(); system("cls"); if (oi != 'y') goto name;
			else
			{
				strcpy(tex1.name, "δ����");
			}
		}

		p2->tex1 = tex1;
		display(p2, i);
		printf("�����뵥λ��");
		scanf("%[^\n]", tex1.office);
		getchar();

		p2->tex1 = tex1;
		display(p2, i);
		printf("������̶��绰��");
		scanf("%[^\n]", tex1.telephone);
		getchar();

		p2->tex1 = tex1;
		display(p2, i);
		printf("�������ƶ��绰��");
		scanf("%[^\n]", tex1.smartphone);
		getchar();

		p2->tex1 = tex1;
		display(p2, i);
		printf("��������ࣺ");
		scanf("%[^\n]", tex1.type);
		getchar();

		p2->tex1 = tex1;
		display(p2, i);
		printf("����������ʼ���");
		scanf("%[^\n]", tex1.email);
		getchar();

		p2->tex1 = tex1;
		display(p2, i);
		printf("������QQ��");
		scanf("%[^\n]", tex1.qq);
		getchar();

		p2->tex1 = tex1;
		display(p2, i);
		fprintf(fp, "%d.", mem);
		fprintf(fp, "%s\n\n��λ��%s\n�̶��绰��%s\n�ƶ��绰��%s\n���ࣺ%s\n�����ʼ���%s\nQQ��%s\n��־��%s\n\n",
			tex1.name, tex1.office, tex1.telephone, tex1.smartphone, tex1.type, tex1.email, tex1.qq,tex1.mark);
		mem++;      //����һע��
		
		system("pause");
		system("cls");
		while (1) {   
			printf("\n\n\n\n\n\n\n\t\t\t\t������Ҫ���������");          //�˲����ж��û��Ƿ���Ҫ����¼�룬ʹ��goto�����������ת
			printf("\n\t\t\t\t----------------------------------\n");
			printf("\t\t\t\t1.��\n\t\t\t\t2.��\n");         
			n1 = _getch();
			switch (n1) {
			case '1':system("cls"); goto begin;
			case '2':system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t��ϵ����ӳɹ�.\n\n\n\n\n\n\n\n\t\t\t\t"); system("pause"); system("cls"); goto end;
			default:system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t��������ȷ��ѡ��\n\n\n\n\n\n\n\t\t\t\t"); system("pause"); system("cls"); break;
			}
		}                                              //����һע��

    end:              //����¼�붼�ѽ�������ת�ڵ�
	fclose(fp);
}

//������ϵ��ĸ���� 	
//ͨ���ж�ͨѶ¼�ļ��Ƿ�Ϊ���������ǵ��ó�ʼ¼�뺯���������Ӻ���
//�����������������������Ҫ��Ϊ�˱�����ļ��Ϳ������������Ĳ���Ҫ���鷳
void adding() {         
	char ch;           
	FILE* fp;
	fp = fopen("tencures.txt", "r");
	ch = fgetc(fp);
	if (ch == EOF){
		create();
	}
	else{
		add2();
	}
	fclose(fp);
}

//������ϵ���Ӻ���
//�ȶ�ȡ�ļ������������û�����������󸲸�д���ļ�
void add2()
{
	int i=0;              //i������ʾ��¼����ϵ�˸���
	char n1,n2,oi;          //n1�����ж��û��Ƿ���Ҫ����¼����ϵ�ˣ�n2�����ж��û��Ƿ���Ҫֱ���˳�,oi�����ж��Ƿ����������
	struct tex* p1 = NULL, * head = NULL, * p2;   //�ֱ�Ϊ��תָ�룬ͷָ���βָ��
	system("cls");
	head = reading();   //���ļ���ȡ���� 

	printf("\n\n\n\n\n\t\t\t\t��1�½���ϵ�ˣ���e�˳�");        //�˲���Ϊ�ж��û��Ƿ���Ҫֱ���˳���ʹ��goto�����������ת	
	while (1) {
        n2 = _getch();
		switch (n2) {
		case 'e':system("cls");  goto end1;
		case '1':system("cls"); goto begin;
		default:system("cls"); printf("\n\n\n\n\n\t\t\t\t��������ȷ��ѡ�\n\n\t\t\t\t"); system("pause"); 
			system("cls"); printf("\n\n\n\n\n\t\t\t\t��1�½���ϵ�ˣ���e�˳�"); 
		}
	}                                        //����һע��

	    begin:       // �������ʼ��ת�ڵ�
	               
		p2 = (struct tex*)malloc(sizeof(struct tex));//�˲���һ����¼�����ݲ�д���ļ���ʹ��[^\n]����֤��������ո�
		
		p2->tex1.name[0] = '\0'; //�˴���ֹ������ʱ�������
		p2->tex1.office[0] = '\0';
		p2->tex1.telephone[0] = '\0';
		p2->tex1.smartphone[0] = '\0';
		p2->tex1.type[0] = '\0';
		p2->tex1.email[0] = '\0';
		p2->tex1.qq[0] = '\0';
		p2->tex1.mark[0] = '\0';

		i++;
	name:              //�����������ֵ���ת�ڵ�
		display(p2,i);//������ʾ��Ϣ
		printf("������������");
		scanf("%[^\n]", p2->tex1.name);
		getchar();    //getchar�������ջ������еĻس�
		if (!strcmp(p2->tex1.name, "\0"))//����������Ϊ��ѡ���������Ϊ�ջ�Ӱ���ҳ����������
		{
			system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t����������Ϊ�գ��Ƿ�ȷ������?\n"); 
			printf("\n\t\t\t\t----------------------------------\n"); printf("\t\t\t\tȷ�ϣ�y��  �������루��������\n"); 
			oi = _getch(); system("cls"); if (oi != 'y') goto name;
			else
			{
				strcpy(p2->tex1.name, "δ����");
			}
		}

		display(p2, i);
		printf("�����뵥λ��");
		scanf("%[^\n]", p2->tex1.office);
		getchar();

		display(p2, i);
		printf("������̶��绰��");
		scanf("%[^\n]", p2->tex1.telephone);
		getchar();

		display(p2, i);
		printf("�������ƶ��绰��");
		scanf("%[^\n]", p2->tex1.smartphone);
		getchar();

		display(p2, i);
		printf("��������ࣺ");
		scanf("%[^\n]", p2->tex1.type);
		getchar();

		display(p2, i);
		printf("����������ʼ���");
		scanf("%[^\n]", p2->tex1.email);
		getchar();

		display(p2, i);
		printf("������QQ��");
		scanf("%[^\n]", p2->tex1.qq);
		getchar();

		display(p2, i);
											 
		p1 = head;                    //�˲���Ϊ����β���������
		while (p1->next != NULL)
			p1 = p1->next;
		p1->next = p2;
		p2->next = NULL;             //����һע��
        writing(head);	//������д���ļ�

		system("pause");
		system("cls");
	while (1) {
		printf("\n\n\n\n\n\n\n\t\t\t\t������Ҫ���������");          //�˲����ж��û��Ƿ���Ҫ����¼�룬ʹ��goto�����������ת
		printf("\n\t\t\t\t----------------------------------\n");
		printf("\t\t\t\t1.��\n\t\t\t\t2.��\n");
		n1 = _getch();
		switch (n1) {
		case '1':system("cls"); goto begin;
		case '2':system("cls");  goto end2;
		default:system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t��������ȷ��ѡ��\n\n\n\n\n\n\n\t\t\t\t"); system("pause"); system("cls"); break;
		}
	}                      //����һע��
 
 end2://���������������ת�ڵ�
	
	printf("\n\n\n\n\n\n\n\t\t\t\t��ϵ����ӳɹ�.\n\n\n\n\n\n\n\n\t\t\t\t");
	system("pause");
 end1:               //ֱ���˳�����ת�ڵ�
	destroy(head);    //���������ͷ��ڴ�
}

//������ϵ��ĸ����
//�����Ϊģ������ģ��
void finding()
{
	struct tex* head = NULL;  //ͷָ��
	struct page* p;          //Ϊģ������ģ�鴫�������ؼ���
	
	if (filetest())//����ļ��Ƿ�Ϊ��
	{
		goto end;
	}
	head = reading();      //��ȡ�ļ����ݲ��������� 

	while (1) {
	begin:  //����Ϊ��ʱ����ת�ڵ�
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t��������ҵĹؼ���,����/e���˳�\n");
		printf("\t\t\t\t-------------------------------\n\t\t\t\t");
		char  searches[250] = { '\0' };
		fflush(stdin);     //������뻺��������ֹ��һ���ؼ��ָ��ŵ�ǰ�Ĺؼ���
		scanf("%[^\n]", searches);
		getchar();

		if (!strcmp(searches, "/e"))   //�ж��û��Ƿ�����/e���˳�
			goto end;
		else if (!strcmp(searches, "")) //�ؼ����п�
		{
			system("cls");
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t\t����������Ϊ�գ�����������!\n\n\t\t\t\t");
			system("pause");
			system("cls");
			goto begin;
		}

		p = search_v3(head, searches);  //����ģ������ģ�飬�޽���򷵻ؿ�
		if (p == NULL)
		{
			system("cls");
			printf("δ�ҵ������ϵ�ˣ���ȷ��������Ϣ�Ƿ���ȷ!\n\n");
			system("pause");
			system("cls");
		}
		else 
		{
			show(searches,p);  //�Է�ҳ��ʽչʾ�������
		}
	}

end:   //�������в��ҵ���ת�ڵ�
	destroy(head);  //���������ͷ��ڴ�
}

//ģ������ģ�飬ʹ��strstr������ʵ��ģ������
struct page* search_v3(struct tex*head,char search_name[250])
{
	struct tex* p1 = NULL, * p2 = NULL;            //p1��p2���ڶ�λ��Ա
	struct page* head_page=NULL,*aim_page=NULL,*previous_page=NULL;//head_page���ڶ�λ��ҳ��aim_page���ڶ�λҳ��
	p1 = p2 = head;                              //��p1��p2��λ����һ����Ա
	int i = 0, stui_last_member;                //i���ڶ�λ��ǰҳ��Աλ�ã�stui_last_member���ڶ�λ���һ���������ĳ�Ա
	
	while (p1 != NULL)
	{
		if (strstr(p1->tex1.name, search_name) || strstr(p1->tex1.office, search_name) || strstr(p1->tex1.telephone, search_name) || strstr(p1->tex1.smartphone, search_name)
			|| strstr(p1->tex1.type, search_name) || strstr(p1->tex1.email, search_name) || strstr(p1->tex1.qq, search_name))//�����������������������¼���Ա
		{

			//�����տ�ʼ����ʱ����Ҫ������ҳ�Լ���head_page��λ��һҳ���Դ�����������Ҫ���ڹ�����ʾҳ��
			if (head_page == NULL)
			{
				head_page = aim_page = (struct page*)malloc(sizeof(struct page));
				aim_page->next = NULL;
			}

			//�����ǰҳ¼��ĳ�Ա������������ҳ
			else if (i >= 9)
			{
				i = 0;
				previous_page=aim_page;//��¼��һҳ
				aim_page->next= (struct page*)malloc(sizeof(struct page));
				aim_page = aim_page->next;
				aim_page->next = NULL;
				aim_page->previous = previous_page;
				previous_page = NULL;
			}

			//¼���������ĳ�Ա�����ڴ�λ�ã�¼��ָ�룩
			if(aim_page!=NULL)
				aim_page->stu[i] = p1;
			stui_last_member = i;
			i++;
		}

		//��λ����һ����Ա
		p2 = p1;
		p1 = p1->next;
		
	}
	//���������ĳ�Ա�����һҳ������
	if (aim_page != NULL)
	{
		aim_page->next = NULL;
		for (i = 8; i > stui_last_member; i--)//���һҳ�Ĵ���
		{
			aim_page->stu[i] = (struct tex*)malloc(sizeof(struct tex));
			if(aim_page->stu[i]!=NULL)
				strcpy(aim_page->stu[i]->tex1.name, "");
		}
	}                  //����һָ��

	//������ҳָ��
	return head_page;
}

//ɾ����ϵ��ģ��
//��Ҫͨ������д��ʵ��ɾ��
int del(struct tex* p, struct tex* head_member)
{
	char ch;    //ch����ȷ��ɾ����ѡ��
	struct tex* aim_member=head_member;//aim_page���ڶ�λ��һ����Ա
retype:   //�����û�ѡ�����ת�ڵ�

	system("cls");
	
	display(p,-1);  //չʾҪɾ������ϵ�˲��ṩɾ��ȷ��ѡ��
	printf("ȷ��ɾ������ϵ��?");
	printf("\n\t\t\t\tȷ����y��  ȡ����n��\n");
	ch = _getch();
	if (ch == 'y')
		goto deling;
	else if (ch == 'n')
	{
		return 0;
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t����ѡ���������������룡\n");
		system("pause");
		system("cls");
		goto retype;
	}



deling:   //ִ��ɾ����������ת�ڵ�
	FILE* fp;
	int mem = 1;  //memΪ�ļ���ÿ����ϵ��ǰ������ֱ�ţ����û��޹أ���Ҫ���ڳ�����

	if (!(fp = fopen("tencures.txt", "w")))  //���ļ�
	{
		printf("cannot open file\n");
		exit(0);
	}

	//����ɾ����Ա����ĳ�Ա��Ϣ����д���ļ�����ʵ��ɾ����Ŀ��
	while (aim_member != NULL)
	{
		if (p != aim_member)
			if (strcmp(aim_member->tex1.name, ""))//д���ļ�����������Ҫɾ���ĳ�ԱҲ��������Ϊ�յĳ�Ա
			{
				//д�뵽�ļ�
				fprintf(fp, "%d.", mem);
				fprintf(fp, "%s\n\n��λ��%s\n�̶��绰��%s\n�ƶ��绰��%s\n���ࣺ%s\n�����ʼ���%s\nQQ��%s\n��־��%s\n\n",
					aim_member->tex1.name, aim_member->tex1.office, aim_member->tex1.telephone,
					aim_member->tex1.smartphone, aim_member->tex1.type, aim_member->tex1.email,
					aim_member->tex1.qq, aim_member->tex1.mark);
				mem++;
			}
		aim_member = aim_member->next;  //���ݿ���ת
	}
		fclose(fp);
		system("cls");
		printf("\n\n\n\n\n\t\t\t\tɾ���ɹ���\n");
		printf("\n\t\t\t\t");
		system("pause");
		return 1;
		               //����һע��
}

//�޸���ϵ��ģ��
void changing(struct tex* q,struct tex* head_member)
{
	char ch, oi;   //���ڶ��޸����ѡ��

	while (1) {
		char  name[250] = { '\0' }, smartphone[250] = { '\0' }, office[250] = { '\0' }, type[250] = { '\0' };  //�˴��������ڱ����û����޸���Ϣ
		char qq[250] = { '\0' }, telephone[250] = { '\0' }, email[250] = { '\0' };
	retype:              //�����������ת�ڵ�
		system("cls");  //����һע��
		display(q,-1); //��ʾ�޸�ǰ����Ϣ

		printf("��ѡ����Ҫ�޸ĵ���Ϣ,�˳��޸��밴0\n");
		printf("\t\t\t\t*------------------------------------------------*\n");
		printf("\t\t\t\t*1.�޸���ϵ������          2.�޸���ϵ�˵�λ      *\n");
		printf("\t\t\t\t*3.�޸���ϵ�˹̶��绰      4.�޸���ϵ���ƶ��绰  *\n");
		printf("\t\t\t\t*5.�޸���ϵ�˷���          6.�޸���ϵ�˵�������  *\n");
		printf("\t\t\t\t*7.�޸���ϵ��QQ                                  *\n");
		printf("\t\t\t\t*------------------------------------------------*\n");
		ch = _getch();

		switch (ch)   //�����޸���Ϣ����
		{
		case '1':printf("\t\t\t\t�����µ���ϵ��������");  scanf("%[^\n]", name); getchar();
			if (!strcmp(name, "\0"))      //����������Ϊ��ѡ���������Ϊ�ջ�Ӱ���ҳ����������
			{
				system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t����������Ϊ�գ��Ƿ�ȷ�ϸ���?\n");
				printf("\t\t\t\t----------------------------------\n");
				printf("\t\t\t\tȷ�� 1  ȡ����������\n"); oi = _getch(); 
				system("cls"); if (oi != '1') goto retype;
				else
				{
					strcpy(q->tex1.name, "δ����");
					break;
				}
			}
			strcpy(q->tex1.name, name); break;

		case '2':printf("\t\t\t\t�����µ���ϵ�˵�λ��");  scanf("%[^\n]", office); getchar();
			if (!strcmp(office, "\0"))//�����뵥λΪ��ѡ��
			{
				system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t�����뵥λΪ�գ��Ƿ�ȷ�ϸ���?\n"); 
				printf("\t\t\t\t----------------------------------\n"); printf("\t\t\t\tȷ�� 1  ȡ����������\n");
				oi = _getch(); system("cls"); if (oi != '1') goto retype;
			}
			strcpy(q->tex1.office, office); break;

		case '3':printf("\t\t\t\t�����µ���ϵ�˹̶��绰��"); scanf("%[^\n]", telephone); getchar();
			if (!strcmp(telephone, "\0"))//������̶��绰Ϊ��ѡ��
			{
				system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t������̶��绰Ϊ�գ��Ƿ�ȷ�ϸ���?\n");
				printf("\t\t\t\t----------------------------------\n"); printf("\t\t\t\tȷ�� 1  ȡ����������\n"); 
				oi = _getch(); system("cls"); if (oi != '1') goto retype;
			}
			strcpy(q->tex1.telephone, telephone); break;

		case '4':printf("\t\t\t\t�����µ���ϵ���ƶ��绰��");      scanf("%[^\n]", smartphone); getchar();
			if (!strcmp(smartphone, "\0"))//�������ƶ��绰Ϊ��ѡ��
			{
				system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t�������ƶ��绰Ϊ�գ��Ƿ�ȷ�ϸ���?\n"); 
				printf("\t\t\t\t----------------------------------\n"); printf("\t\t\t\tȷ�� 1  ȡ����������\n"); 
				oi = _getch(); system("cls"); if (oi != '1') goto retype;
			}
			strcpy(q->tex1.smartphone, smartphone); break;

		case '5':printf("\t\t\t\t�����µ���ϵ�˷��ࣺ");      scanf("%[^\n]", type); getchar();
			if (!strcmp(type, "\0"))//���������Ϊ��ѡ��
			{
				system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t��������ϵ�˷���Ϊ�գ��Ƿ�ȷ�ϸ���?\n"); 
				printf("\t\t\t\t----------------------------------\n"); printf("\t\t\t\tȷ�� 1  ȡ����������\n"); 
				oi = _getch(); system("cls"); if (oi != '1') goto retype;
			}
			strcpy(q->tex1.type, type); break;

		case '6':printf("\t\t\t\t�����µ���ϵ�˵������䣺");      scanf("%[^\n]", email); getchar();
			if (!strcmp(email, "\0"))//����������Ϊ��ѡ��
			{
				system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t�������������Ϊ�գ��Ƿ�ȷ�ϸ���?\n");
				printf("\t\t\t\t----------------------------------\n"); printf("\t\t\t\tȷ�� 1  ȡ����������\n");
				oi = _getch(); system("cls"); if (oi != '1') goto retype;
			}
			strcpy(q->tex1.email, email); break;

		case '7': printf("\t\t\t\t�����µ���ϵ��QQ��");    scanf("%[^\n]", qq); getchar();
			if (!strcmp(qq, "\0"))//������QQΪ��ѡ��
			{
				system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t������QQΪ�գ��Ƿ�ȷ�ϸ���?\n"); 
				printf("\t\t\t\t----------------------------------\n"); printf("\t\t\t\tȷ�� 1  ȡ����������\n");
				oi = _getch(); system("cls"); if (oi != '1') goto retype;
			}
			strcpy(q->tex1.qq, qq); break;

		case '0':system("cls"); goto end;
		default:system("cls"); printf("\n\n\n\n\n\n\n\t\t\t\t�����������������!\n\t\t\t\t"); system("pause"); goto retype;
		}         //����һע��

		writing(head_member);			//���޸ĺ����Ϣ�����ļ�
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t�޸ĳɹ�!\n\n\t\t\t\t");
		system("pause");
	}
end:         //�����޸Ļ�ֱ���˳�����ת�ڵ�
	printf("\n");
	system("cls");
}

//��ʼ��ͨѶ¼
//�˺���ͨ������һ��ͬ���ֵ��ļ�������ԭ�е��ļ����ɴ���ɳ�ʼ���Ĺ���
void inizaize() 
{
	char pan;  //���ڶ�ȡ�û�ѡ��
    printf("��ȷ��Ҫ��ʼ��ͨѶ¼���⽫�����������\n1.��\n2.ȡ��\n");
	begin:   //��ʼ��ת�ڵ�
	pan = _getch();
	switch (pan) {
	case '1': FILE * fp; fp = fopen("tencures.txt", "w+"); fclose(fp); system("cls");printf("��ʼ���ɹ���\n\n");  system("pause"); break;
	case '2':break;
	default:system("cls"); printf("��ȷ��Ҫ��ʼ��ͨѶ¼���⽫�����������\n1.��\n2.ȡ��\n"); printf("\n��������ȷ��ѡ�\n"); goto begin;
	}
	printf("\n");
}

//ҳ�洴������
/*���ļ���ȡ������¼����Ա��Ϣ����->����Ա��Ϣ�����г�ȡÿ�Ÿ��˿���һҳ��һ·�����Դ���ҳ������
stu[x]�����ڴ洢ÿ����ϵ�˳�Ա�ṹ���ָ�����飬ͨ�������ǵĵ��ÿ�����ʾ��������ϵ����Ϣ->һҳ����֮��
��¼��һҳ����һҳ��λ�ã�������ڵĻ���->�ж��Ƿ�Ϊ���һҳ����������жϺ���ִ�в�������ҳָ�룬
��������һҳ������������ϵ�������Դ�����ҳ*/
struct page* addpage()
{
	struct tex* reading();   //���á��ļ����ݴ�������������������ϵ����Ϣ����
	struct tex* aim_member; //��Ա��λָ��
	aim_member = reading();//��λ��һ����Ա���ڴ�λ��
	struct page* head_page = NULL/*ͷҳ��*/, * previous_page = NULL/*��һҳҳ�루����һҳ��˵��*/, * aim_page = NULL/*ҳ�붨λָ��*/;
	
	int stui, page, pagei, stui_last_member = -1, i;  
	//stui��i����ÿҳ��ϵ����Ϣ�ļ�����page��pagei����ҳ�������ļ����� stui_last_member�������һҳ����ϵ����Ϣ����
	
	page = culpage();    //������ҳ��
	
	//����ΪΪҳ��¼����Ϣ
	for (pagei = 0; pagei < page; pagei++)
	{
		aim_page = (struct page*)malloc(sizeof(struct page));//�����µ�ҳ��
		if (aim_page != NULL)
		{
			if (head_page == NULL)
			{
				head_page = aim_page;//��λ��һҳ��λ��
			}
			else
			{
				aim_page->previous = previous_page;//��¼��һҳ
				previous_page->next = aim_page;//����һҳ����ס����һҳ�����Ǳ�ҳ��λ��
				previous_page = NULL;
			}
			for (stui = 0; stui < 9; stui++)
			{
				aim_page->stu[stui] = aim_member;//¼���Ա��ַ
				if (aim_member->next != NULL)//����Ƿ�Ϊ���һ��¼��ĳ�Ա
					aim_member = aim_member->next;
				else//��������¼���һҳ���һ����Ա�ı��
				{
					stui_last_member = stui;
					for (i = 8; i > stui_last_member; i--)//���һҳ�Ĵ���
					{
						aim_page->stu[i] = (struct tex*)malloc(sizeof(struct tex));
						if(aim_page->stu[i]->tex1.name)
							strcpy(aim_page->stu[i]->tex1.name, "");
					}
					break;
				}
			}

			previous_page = aim_page;//��¼��ǰҳָ�룬Ϊ��һҳ��׼��
		}
	}

	//����ҳ��ָ��
	aim_page = NULL;
	previous_page = NULL;
	
	return(head_page);
}

//ҳ����㺯��
//һҳ�Ÿ���
int culpage()  
{
	int page;
	page = people / 9;
	if (page == 0)
	{
		if (people != 0)
			page = 1;
	}
	else if (people % 9)
		page++;
	return page;
}

/*������ʾ��������������ͨѶ¼����Ĺ�����Ŧ�����ȿ������û������޸ĺ�ɾ��ģ�飬Ҳ���Ա�����ģ��Ͳ鿴ģ��������
��ҳ��ʾΪ�û����������õ�ʹ������
�˺������ż��ֲ�ͬ�����з�ʽ��ͨ���ض����źŲ��������������ض������з�ʽ
��ʾ���з�ʽ����addpage��������ҳ�벢���ص�һҳָ��->��ʾ��ѡ���ҳ��->ѡ��Ҫ�鿴�ĳ�Ա��ѡ��ҳ����ת���˳���
�����ҳ��ʾ����������ʾȫ����Ա���������ص�ֵΪNULL
�������ѡ���Ա��ִ��ĳ��ܣ��򷵻ر�ѡ�г�Ա��ָ����������Ӧ����ģ������У��˳�����NULL*/
struct tex* show(char search_name[250], struct page* head_page)
{
    struct page* aim_page;   //aim_page���ڶ�λҳ��

	struct tex* f_aim_member, * f_head_member=NULL;  //f_head_member���ڶ�λ�׸���ϵ�˵�λ�ã� f_aim_member���ڶ�λ������ϵ��

	char choice, display_choice;                   //choiceΪ��ǰҳ�Ĺ���ѡ�display_choiceΪ��ʾ����ĳ����Ա��Ĺ���ѡ��
	char jc[200] = { 0 }, of[] = "*������ϵ��*";  //jc�ǽ���ҳ����ת���ܺ�Ĺ���ѡ�of����ˢ�³�����ϵ�˽���

	int pagei, page = 0, i, choice_member = -1; //pagei������ʾ�ڼ�ҳ���Լ���ֹ�û���ת�������ڵ�ҳ��,i���ڶ�λ��ǰҳ��9����ϵ�˳�Ա
	int del_choice = 0, page_jump = 0, x = 0;  //del_choice���ڰ���ȷ��ɾ�����Ƴ�������page_jump��Ҫ���ڵ���sscanf����
	                                          //x�����жϱ���������ϵ���Ƿ�Ϊ��ҳ���׳�Ա

	if (filetest())        //����ļ��Ƿ�Ϊ��
	{
		goto end;
	}
    
del_begin:
	if (head_page==NULL||del_choice && !strcmp(search_name, "/e"))//��������յ���head_pageΪ��,����ɾ������Ա����Ҫˢ��ҳ��
	{
		head_page = addpage();
		page = culpage();//����ҳ��
	}
	else
	{
		if ( !strcmp(search_name, ""))//����ˢ��ҳ��
		{
			if (!x&& del_choice)
				f_head_member = f_head_member->next;//�����ͷ��Ա��ɾ�������ͷ��Ա������һ����Ա
			f_head_member = reading();
			head_page = often_distinguish(f_head_member, of);
		}
		else if (strcmp(search_name, "/e"))//����ˢ��ҳ��
		{
			if (!x && del_choice)
				f_head_member = f_head_member->next;//�����ͷ��Ա��ɾ�������ͷ��Ա������һ����Ա
			f_head_member = reading();
			head_page = search_v3(f_head_member, search_name);
		}
		aim_page = head_page;
		page = 0;

		while (aim_page != NULL)
		{
			page++;//����ҳ��
			aim_page = aim_page->next;
		}
	}

	//��λ����һҳ
	aim_page = head_page;

	del_choice = 0;

	if (aim_page != NULL)
	{
		for (pagei = 0;; pagei++)
		{
		begin:system("cls");     //������Ҫ���ܵ���ʼ��ת�ڵ�
			//x��һ���жϱ�־����ͬ�ı���������´˺��������յ���x��ֵ��ͬ���ɴ˴�����ͬ����ʾ����
			printf("\n\n\n\n");
		    printf("\t\t\t\t��ѡ��Ҫ�鿴����ϵ��\n\n");
			printf("\t\t\t\t------------------------------------------------\n");
			//�˲���Ϊ������ʾ�б�
			for (i = 0; i < 9 && strcmp(aim_page->stu[i]->tex1.name, ""); i++)
			{
				printf("\t\t\t\t%d.%s\n", i + 1, aim_page->stu[i]->tex1.name);
			}
			printf("\t\t\t\t------------------------------------------------\n");
			printf("\n\t\t\t\t��һҳ��p��  ��һҳ��n�� ��ǰ�ǵ�%dҳ,��%dҳ\n", pagei + 1, page);
			printf("\t\t\t\t��������ǰ���ֻ�ѡ����һҳ����һҳ");
			printf("\n\t\t\t\t����j����ҳ����ת\n\t\t\t\t����e������һ��");                         //����һע��

			choice = _getch();//��ȡ�û�ѡ��

			switch (choice)//�˲��֣�ҳ���б���ÿһ����ϵ�˶�����һ����������ʾ����
			{
			case '1':choice_member = 0; goto play;
			case '2':choice_member = 1; goto play;
			case '3':choice_member = 2; goto play;
			case '4':choice_member = 3; goto play;
			case '5':choice_member = 4; goto play;
			case '6':choice_member = 5; goto play;
			case '7':choice_member = 6; goto play;
			case '8':choice_member = 7; goto play;
			case '9':choice_member = 8; goto play;
			case 'p': //pΪ��һҳ
				system("cls");
				if (!pagei || aim_page->previous == NULL)
				{
					system("cls");
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t��ǰ�ǵ�һҳ��\n\n\n\n\n\n\n\t\t\t\t");
					system("pause");
					goto begin;
				}
				else
				{
					aim_page = aim_page->previous;
					pagei -= 2;
					goto switch_continue;
				}
			case 'n'://nΪ��һҳ
				system("cls");
				if (pagei + 1 == page || aim_page->next == NULL)
				{
					system("cls");
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t��ǰ�����һҳ��\n\n\n\n\n\n\n\t\t\t\t");
					system("pause");
					goto begin;
				}
				else
				{
					aim_page = aim_page->next;
					goto switch_continue;
				}
			case 'j':jr://jΪҳ����ת
				page_jump=0;
				system("cls");
				printf("\n\n\n\n\n\n\n\t\t\t\t������Ҫ��ת��ҳ��\n\t\t\t\t������ת����һҳ��1�� ���һҳ��%d��  ���أ�e��",page);
				printf("\n\t\t\t\t------------------------------------------------\n\t\t\t\t");
				scanf("%s",&jc);
				getchar();
			     if (!strcmp(jc, "e"))
				{
					goto begin;
				}
				else if (strspn(jc, "-0123456789") == strlen(jc))//�ж�������Ƿ�Ϊ����
				{
					sscanf(jc, "%d", &page_jump);//ȡ���ֵ�int�͵ı���
					if (page_jump > page||page_jump<=0)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\t\t\t\t����ҳ����Ч������������\n\n\n\n\n\n\n\t\t\t\t");
						system("pause");
						goto jr;
					}
					else if (page_jump > pagei + 1)//����ҳ����ڵ�ǰҳ�����
					{
						page_jump -= pagei + 1;//��ʱpage_jumpΪ��ת����
						for (; page_jump > 0 && aim_page->next != NULL; --page_jump)
						{
							aim_page = aim_page->next;//��ת��Ҫ��ҳ
						}
						sscanf(jc, "%d", &pagei);//����ҳ�뵽pagei��
						pagei-=2;//����ҳ��
						goto switch_continue;
					}
					else if (page_jump < pagei + 1)//����ҳ��С�ڵ�ǰҳ�����
					{
						page_jump = pagei + 1- page_jump;
						for (; page_jump > 0 && aim_page->previous != NULL; page_jump--)
						{
							aim_page = aim_page->previous;//��ת��Ҫ��ҳ
						}
						sscanf(jc, "%d", &pagei);//����ҳ�뵽pagei��
						pagei -= 2;//����ҳ��
						goto switch_continue;
					}
					else if (page_jump == pagei + 1)//����ҳ����ڵ�ǰҳ�����
					{
						goto begin;//ֱ�ӷ���
					}
				}
				else
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\t\t\t\t����������������룡\n\n\n\n\n\n\n\t\t\t\t");
					system("pause");
				}
			case 'e'://eΪ�˳�
				goto end;//��ת�����������ڵ�
			default:error:  //�������ʱ����ת�ڵ�
				system("cls");
				printf("\n\n\n\n\n\n\n\t\t\t\t�������!\n\n\n\n\n\n\n\n\t\t\t\t");
				system("pause");
				system("cls");
				goto begin;
			}
			if (0)//��switch��ʹfor������
			{
			switch_continue:
				continue;
			}

			if (0)//�鿴ĳ����Աʱ�Ĺ���ѡ��
			{
			play:
				if (!strcmp(aim_page->stu[choice_member]->tex1.name, ""))goto error;
				display(aim_page->stu[choice_member], -1);
				printf("��ѡ�����蹦��\n\t\t\t\t���أ�e�� �޸ģ�c�� ɾ����d��\n\t\t\t\t��Ϊ������ϵ�ˣ�w�� �Ƴ�������ϵ�ˣ�r��\n\t\t\t\t");
				display_choice = _getch();
				switch (display_choice)
				{
				case 'e': goto begin;
				case 'c':
					if (f_head_member == NULL)
					{
						changing(aim_page->stu[choice_member], head_page->stu[0]); goto play;
					}
					else
					{
						f_aim_member = f_head_member;
						while (aim_page->stu[choice_member] != f_aim_member)
							f_aim_member = f_aim_member->next;
						changing(f_aim_member, f_head_member); goto play;
					}
				case 'w':
					if (f_head_member == NULL)
					{
						if(!strcmp(aim_page->stu[choice_member]->tex1.mark,"*������ϵ��*"))
						{
							system("cls");
							printf("\n\n\n\n\n\n\n\t\t\t\t���ѽ�����Ϊ������ϵ��!\n\n\t\t\t\t");
							system("pause");
						}
						else
						  often_in(aim_page->stu[choice_member], head_page->stu[0]); 
						goto play;
					}
					else
					{
						if (!strcmp(aim_page->stu[choice_member]->tex1.mark, "*������ϵ��*"))
						{
							system("cls");
							printf("\n\n\n\n\n\n\n\t\t\t\t���ѽ�����Ϊ������ϵ��!\n\n\t\t\t\t");
							system("pause");
						}
						else
						{
							f_aim_member = f_head_member;
							while (aim_page->stu[choice_member] != f_aim_member)
							     f_aim_member = f_aim_member->next;
								
							
							often_in(f_aim_member, f_head_member); goto play;
						}
						goto play;
					}
				case 'r':
					if (f_head_member == NULL)
					{
						often_out(aim_page->stu[choice_member], head_page->stu[0]); goto play;
					}
					else
					{
						f_aim_member = f_head_member;
						while (aim_page->stu[choice_member] != f_aim_member)
						{
							f_aim_member = f_aim_member->next;
							x++;//��ⱻ�Ƴ��ĳ�Ա�Ƿ�Ϊͷ��Ա
						}
						often_out(f_aim_member, f_head_member); if (!strcmp(search_name, "")) { del_choice = 1; goto del_begin; /*�ڡ�������ϵ�ˡ�������Ƴ���ϵ�˺���Ҫˢ��ҳ��*/ } else goto play;
					}
				case 'd':
					if (f_head_member == NULL)
					{
						if (del_choice = del(aim_page->stu[choice_member], head_page->stu[0]))goto del_begin; else { system("cls"); goto play; }
					}
					else
					{
						f_aim_member = f_head_member;//ȷ���������ͳ�����ϵ�˺�����������������ɾ����Ա��ĳ�Ա¼���ļ�
						while (aim_page->stu[choice_member] != f_aim_member)
						{
							f_aim_member = f_aim_member->next;
							x++;//��ⱻɾ���ĳ�Ա�Ƿ�Ϊͷ��Ա
						}
						if (del_choice = del(f_aim_member, f_head_member))
							goto del_begin; else { system("cls"); goto play; }
					}
				default:system("cls"); printf("\n\n\n\n\n\n\n"); printf("\t\t\t\t�������\n\t\t\t\t"); 
					system("pause"); system("cls"); goto play;
				}
				goto begin;
			}
		}

	}
end: 
	system("cls");
	return NULL;  //�����������е���ת�ڵ�
}

//�ļ���������
/*��fseek���������ļ�ָ���λ�ã���fgetsÿÿ������ȡ������Ϣ��Ȼ���fets���õ���\n��Ϊ\0������������ú����᷵�ص�һ����Ա��ָ�롣
�ú����ĺ�����һ��for��䣬��for���������ɨ����ϵ�˵�ÿһ����Ϣ�����ж�ȡ����ȡ��ɺ�¼������
�ɴ˱����һ����ϵ�˵Ķ�ȡ����������һ����ϵ�˵������ظ����������ȫ�����ݶ�ȡ���*/
struct tex* reading()
{
	FILE* fp;
	struct tex1 tex1;
	struct tex* p, * tail = NULL, * head = NULL;  //�ֱ�Ϊ��Ծָ�롢βָ���ͷָ��
	int len, x = 10, y = 4;    //len���ڴ洢��ϵ��ĳ����Ϣ�ĳ���

	fp = fopen("tencures.txt", "r");  //���ļ�
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}                             //����һע��

	//���ļ�δ����������־ʱ��ȡ����,��������һ����Ե�����ϵ����Ϣ��˳���ȡ
	people = 0;
	fseek(fp, 2L, 1);//��������Ϣ�в�Ӧ����ȡ�Ĳ���
	for (; fgets(tex1.name, 250, fp) != NULL; fseek(fp, y, 1)/*������һ����ϵ����Ϣ����*/)
	{
		len = strlen(tex1.name);//ȥ��fgets�е�\n,���ҿ��Է�ֹ������ȡ
		tex1.name[len - 1] = '\0';//��������
		fseek(fp, 8L, 1);//������һ��Ϣ�в�Ӧ����ȡ�Ĳ���

		if (fgets(tex1.office, 250, fp) != NULL)//���¼�����Ϣ�Ƿ���ȫΪ��
		{
			len = strlen(tex1.office);//ȥ��fgets�е�\n,���ҿ��Է�ֹ������ȡ
			tex1.office[len - 1] = '\0';//��������
			fseek(fp, 10L, 1);//������һ��Ϣ�в�Ӧ����ȡ�Ĳ���
		}
		if (fgets(tex1.telephone, 250, fp) != NULL)//���¼�����Ϣ�Ƿ���ȫΪ��
		{
			len = strlen(tex1.telephone);//ȥ��fgets�е�\n,���ҿ��Է�ֹ������ȡ
			tex1.telephone[len - 1] = '\0';//��������
			fseek(fp, 10L, 1);//������һ��Ϣ�в�Ӧ����ȡ�Ĳ���
		}
		if (fgets(tex1.smartphone, 250, fp) != NULL)
		{
			len = strlen(tex1.smartphone);//ȥ��fgets�е�\n,���ҿ��Է�ֹ������ȡ
			tex1.smartphone[len - 1] = '\0';//��������
			fseek(fp, 6L, 1);//������һ��Ϣ�в�Ӧ����ȡ�Ĳ���
		}
		if (fgets(tex1.type, 250, fp) != NULL)
		{
			len = strlen(tex1.type);//ȥ��fgets�е�\n,���ҿ��Է�ֹ������ȡ
			tex1.type[len - 1] = '\0';//��������
			fseek(fp, 10L, 1);//������һ��Ϣ�в�Ӧ����ȡ�Ĳ���
		}
		if (fgets(tex1.email, 250, fp) != NULL)
		{
			len = strlen(tex1.email);//ȥ��fgets�е�\n,���ҿ��Է�ֹ������ȡ
			tex1.email[len - 1] = '\0';//��������
			fseek(fp, 4L, 1);//������һ��Ϣ�в�Ӧ����ȡ�Ĳ���
		}
		if (fgets(tex1.qq, 250, fp) != NULL)
		{
			len = strlen(tex1.qq);//ȥ��fgets�е�\n,���ҿ��Է�ֹ������ȡ
			tex1.qq[len - 1] = '\0';//��������
			fseek(fp, 6L, 1);//������һ��Ϣ�в�Ӧ����ȡ�Ĳ���
		}
		if (fgets(tex1.mark, 20, fp) != NULL)
		{
			len = strlen(tex1.mark);//ȥ��fgets�е�\n,���ҿ��Է�ֹ������ȡ
			tex1.mark[len - 1] = '\0';//��������
		}
		p = (struct tex*)malloc(sizeof(struct tex));//���ٿռ䴴������ 
		p->tex1 = tex1;
		if (head == NULL)//��ͷ�ڵ�Ĵ���
		{
			head = p;
			people++;
		}
		if (tail != NULL)//��β�ڵ�Ĵ���
		{
			tail->next = p;
			people++;
		}
		tail = p;
		tail->next = NULL;


		//��Ϊ�ļ��е���ϵ����Ż�����λ����λ��������Ҫ���ļ�ָ����λ�Ʋ���
		if (people >= x - 1) { y++; x = x * x; }
	}
	fclose(fp);
	return head;
}

//����д���ļ�
void writing(struct tex* head)
{
	FILE* fp;
	struct tex* p = NULL;  //���Զ�ȡ����
	int mem = 1;          //���Զ���ϵ�˼���

	fp = fopen("tencures.txt", "w");  //���ļ�����
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}                             //����һע��

	p = head;
	while (p)           //��ѭ��������д���ļ���ֱ�����һ����ָ��Ϊ��ʱ��
	{
		fprintf(fp, "%d.", mem);   
		fprintf(fp, "%s\n\n��λ��%s\n�̶��绰��%s\n�ƶ��绰��%s\n���ࣺ%s\n�����ʼ���%s\nQQ��%s\n��־��%s\n\n", 
		p->tex1.name, p->tex1.office, p->tex1.telephone, p->tex1.smartphone, p->tex1.type, p->tex1.email, p->tex1.qq,p->tex1.mark);
		mem++;
		p = p->next;
	}
	fclose(fp);
}

//��ʾ������ϵ�˺���
//gp�ǳ�Աָ�룬�����Ӧָ�룬ֱ����ʾ��i����Ϣ������ͨ��Ϊ-1����-1ʱ�򼤻¼����ϵ�˺�������ʱ�Ĺ���
void display(struct tex* gp,int i)
{
	system("cls");
	if (i == -1)//������������
		printf("\n\n\n");
	else//������ϵ�˺�������
		printf("\n\t\t\t ��%d����ϵ�ˣ�\n\n", i);

	//��ʾ����
	printf("\t\t\t\t%s\n", gp->tex1.name);

	printf("\t\t\t\t------------------------------------------------\n\t\t\t\t");

	//��ʾ������Ϣ
	printf("��λ��%s\n\n\t\t\t\t�̶��绰��%s\n\n\t\t\t\t�ƶ��绰��%s\n\n\t\t\t\t���ࣺ%s\n\n\t\t\t\t�������䣺%s\n\n\t\t\t\tQQ��%s\n\n\n\t\t\t\t%s\n",
		gp->tex1.office, gp->tex1.telephone, gp->tex1.smartphone,
		gp->tex1.type, gp->tex1.email, gp->tex1.qq,gp->tex1.mark);

	printf("\t\t\t\t------------------------------------------------\n\n\t\t\t\t");
}

//�������ٺ���
//����ָ�뽻��ǰ����p����ɾ����ֱ�����һ��
void destroy(struct tex* head)
{
	struct tex* p;
	if (head != NULL)
	{
		while (head->next) 
		{
			p = head->next;
			head->next = p->next;
			free(p);
		}
	}
}

//������ϵ�˺���
void often() {
	struct tex* head = NULL; 
	struct page* p;  //���Զ�ȡ��ҳָ��

	if (filetest()) //����ļ��Ƿ�Ϊ��
	{
		goto end;
	}

	head = reading();      //��ȡ�ļ����ݲ��������� 

	while (1) {
		char  searches[20] = "*������ϵ��*",s[]="\0";
		p = often_distinguish(head, searches);  //������ϵ���б�ģ�飬�޽���򷵻ؿ�
		if (p == NULL)
		{
			system("cls");
			printf("\n\n\n\t\t\t��ǰ��û������κγ�����ϵ��\n\n");
			system("pause");
			goto end;
			system("cls");
		}
		else
		{
			show(s, p);
			goto end;
		}
	}

end:   //�������ܵ���ת�ڵ�
	destroy(head);  //���������ͷ��ڴ�
}

//������ϵ���ж�ģ�飬�ǳ�����ϵ�˺����ĺ���
//�ú�����������ͨ����*������ϵ��*������ض��ؼ��ֶ�������ϵ����Ϣ�����Զ�����������ҳ�洴���������߼������з�ҳ
struct page* often_distinguish(struct tex* head, char mark[20]) {

	struct tex* p1 = NULL, * p2 = NULL;               //p1��p2���ڶ�λ��ϵ�˳�Ա
	struct page* head_page = NULL, * aim_page = NULL;//head_page���ڶ�λ��ҳ��aim_page���ڶ�λҳ��
	p1 = p2 = head;                                 //��p1��p2��λ����һ����ϵ�˳�Ա
	int i = 0, stui_last_member;                   //i���ڶ�λ��ǰҳ��Աλ�ã�stui_last_member���ڶ�λ���һ���������ĳ�Ա
	while (p1 != NULL)
	{
		if (strstr(p1->tex1.mark, mark))//�б��������������������¼�볣�ó�Ա
		{			
			if (head_page == NULL)    //�����ҳ����Ҫ������ҳ�Լ���head_page��λ��һҳ
			{
				head_page = aim_page = (struct page*)malloc(sizeof(struct page)); //Ϊ����������ϵ����Ϣ�����ڴ�
				aim_page->next = NULL;
			}		
			else if (i >= 9)     //�����ǰҳ¼��ĳ�Ա������9������������ҳ
			{
				i = 0;
				aim_page->next = (struct page*)malloc(sizeof(struct page));
				aim_page = aim_page->next;
				aim_page->next = NULL;
			}

			//¼��������ĳ�Ա�����ڴ�λ�ã�¼��ָ�룩
			if (aim_page != NULL)
				aim_page->stu[i] = p1;
			stui_last_member = i;
			i++;
		}

		//��λ����һ����ϵ�˳�Ա
		p2 = p1;
		p1 = p1->next;

	}
	//���������ĳ�Ա���һҳ�Ĵ���
	if (aim_page != NULL)
	{
		for (i = 8; i > stui_last_member; i--)//���һҳ�Ĵ���
		{
			aim_page->stu[i] = (struct tex*)malloc(sizeof(struct tex));
			if (aim_page->stu[i] != NULL)
				strcpy(aim_page->stu[i]->tex1.name, "");
		}
	}
	//������ҳָ��
	return head_page;
}

//������ϵ������ģ��
//����Ϊ��mark���鸳ֵ��*������ϵ��*��
void often_in(struct tex* q, struct tex* head_member)
{
		char  in_mark[20] = "*������ϵ��*";          
		strcpy(q->tex1.mark, in_mark);         
		writing(head_member);			//���޸ĺ����Ϣ�����ļ�
		system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t����Ϊ������ϵ��!\n\n\t\t\t\t");
		system("pause");
		system("cls");
}
  
//������ϵ���Ƴ�ģ��
//����Ϊ��mark���鸳ֵ����
void often_out(struct tex* q, struct tex* head_member)
{
	char  out_mark[20] = "";
	strcpy(q->tex1.mark, out_mark);
	writing(head_member);			//���޸ĺ����Ϣ�����ļ�
	system("cls");
	printf("\n\n\n\n\n\n\n\t\t\t\t���Ƴ�������ϵ��\n\n\t\t\t\t");
	system("pause");
	system("cls");
}
