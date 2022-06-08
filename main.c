# include <stdio.h>
# include <string.h>

typedef char Str[32];
typedef char StrL[64];

typedef enum Item {
    idle,
    running,
    jump,
    swim,
}Item;

char const* itemStr[4]={"��","�ﾶ","��Զ","��Ӿ"};

typedef enum Country {
    cn,
    en,
    fc,
    gm,
};
char const* countryStr[4] = { "�й�","Ӣ��","����","�¹�" };
char const* langStr[4] = { "����","Ӣ��","����","����" };

typedef struct Vlt {
    int id          ;   // ���
    Str name        ;   // ����
    Str gender      ;   // �Ա�
    int age         ;   // ����
    Str phone       ;   // ��ϵ�绰
    Str idNum       ;   // ���֤��
    Str company     ;   // ��λ��Ϣ
    int yyh         ;   // �Ƿ�������˻�
    int ycyh        ;   // �Ƿ�����ǲ��˻�
    Item tc         ;   // �س�
    int lang[4]     ;   // ���Ժ͵ȼ�
    Item time[10][2] ;  // ����ʱ�� 10�� ���� ����
}Vlt;

# define MAX_SZ 1024

Vlt v[MAX_SZ];
int sz = 0;

void save() {
	int i; 
    FILE* fp = fopen("./data.txt", "w+");
    fprintf(fp,"%d\n", sz);
    for ( i = 0; i < sz; ++i) {
        fprintf(fp,
            "%d %s %s %d %s %s %s %d %d %d\n"
            "\t%d %d %d %d\n"
            "\t%d %d %d %d %d %d %d %d %d %d\n"
            "\t%d %d %d %d %d %d %d %d %d %d\n"
            , v[i].id, v[i].name, v[i].gender, v[i].age, v[i].phone, v[i].idNum, v[i].company, v[i].yyh, v[i].ycyh, v[i].tc
            , v[i].lang[0], v[i].lang[1], v[i].lang[2], v[i].lang[3]
            , v[i].time[0][0], v[i].time[1][0], v[i].time[2][0], v[i].time[3][0], v[i].time[4][0], v[i].time[5][0], v[i].time[6][0], v[i].time[7][0], v[i].time[8][0], v[i].time[9][0]
            , v[i].time[0][1], v[i].time[1][1], v[i].time[2][1], v[i].time[3][1], v[i].time[4][1], v[i].time[5][1], v[i].time[6][1], v[i].time[7][1], v[i].time[8][1], v[i].time[9][1]
        );
    }
    fclose(fp);
}

void load() {
    FILE* fp = fopen("./data.txt", "r");
    fscanf(fp, "%d", &sz);
    for (int i = 0; i < sz; ++i) {
        fscanf(fp,
            "%d %s %s %d %s %s %s %d %d %d\n"
            "\t%d %d %d %d\n"
            "\t%d %d %d %d %d %d %d %d %d %d\n"
            "\t%d %d %d %d %d %d %d %d %d %d\n"
            , &v[i].id, v[i].name, v[i].gender, &v[i].age, v[i].phone, v[i].idNum, v[i].company, &v[i].yyh, &v[i].ycyh, &v[i].tc
            , &v[i].lang[0], &v[i].lang[1], &v[i].lang[2], &v[i].lang[3]
            , &v[i].time[0][0], &v[i].time[1][0], &v[i].time[2][0], &v[i].time[3][0], &v[i].time[4][0], &v[i].time[5][0], &v[i].time[6][0], &v[i].time[7][0], &v[i].time[8][0], &v[i].time[9][0]
            , &v[i].time[0][1], &v[i].time[1][1], &v[i].time[2][1], &v[i].time[3][1], &v[i].time[4][1], &v[i].time[5][1], &v[i].time[6][1], &v[i].time[7][1], &v[i].time[8][1], &v[i].time[9][1]
        );
    }
    fclose(fp);
}


int nInput(char const* info, int min, int max) {
    printf(info);
    int c;
    while (scanf("%d", &c) != 1 && c >= min && c <= max) {
        printf("�������� ����������");
    }
    return c;
}

void helpInfo() {
    printf(
        "=========================================================="
        "1�� ʹ�ð���\n"
        "   ��ʾ��ϸ�Ĺ���˵��"
        "2��־Ը����Ϣ�Ǽ�"
        "   ���������������Ա����䡢��ϵ�绰�����֤�š���λ��Ϣ�������������(������������ࡢ�����̶�)���Ƿ��ι��������־Ը�ߣ� �ܹ��ṩ־Ը�����ʱ��(��������ѡ��������˻�ͷ������˻��Լ��ǲ��˻�)"
        "3�� ־Ը����Ϣ��ѯ"
        "    ����־Ը�߱��"
        "    ���ݱ����ʾ��Ϣ"
        "- 4��־Ը����Ϣ�޸�һ ����־Ը�߱��\n"
        "   ѡ���޸�����\n"
        "   ��ʾ�޸�ǰ������\n"
        "   �����޸�֮�������\n"
        "5.־Ը�߹�������\n"
        "   ��������йص���Ϣ\n"
        "   ��ɸѡ��ʱ��ο��е�־Ը��\n"
        "   �ٸ��ݹ���ɸѡ־Ը�ߣ��������������س�ɸѡ�� ��������ֱ�Ӵ�ʱ����е�־Ը���м���\n"
        "6��־Ը����ٻ���ϵͳһ����־Ը�߱��һ ѡ�񻻰��ʱ��(��֮ǰ��ʱ��ͻ�֮���ʱ��)һ������Ҫ������˵ı��һ �ж��Ƿ���ϻ�������(��Ҫ��ʱ���Ƿ���ڳ�ͻ)\n"
        "10.־Ը����Ϣͳ��һ�� ����Ҫչʾ����Ϣ\n"
        "   չʾ��Ӧ��Ϣ\n"
        "   ����������������\n"
        "   �������˻�־Ը�߹���ϵͳ\n"
        "============================================================"
    );
}

int findVltByID(int id) {
    for (int i = 0; i < sz; ++i) {
        if (id == v[i].id) {
            return i;
        }
    }
    return -1;
}

int findVlt() {
    printf("������־Ը�߱��:");
    int id;
    scanf("%d", &id);
    return findVltByID(id);
}

void showVltByIndex(int idx) {
    printf("=======================\n����            :%s\n",v[idx].name);
    printf("�Ա�            :%s\n",v[idx].gender);
    printf("����            :%d\n",v[idx].age);
    printf("��ϵ�绰        :%s\n",v[idx].phone);
    printf("���֤��        :%s\n",v[idx].idNum);
    printf("��λ��Ϣ        :%s\n",v[idx].company);
    printf("�Ƿ�������˻�  :%s\n",v[idx].yyh?"��":"��");
    printf("�Ƿ�����ǲ��˻�:%s\n",v[idx].ycyh?"��":"��");
    printf("�س�            :%s\n", itemStr[v[idx].tc]);
    printf("����            :����:%d Ӣ��:%d ����:%d ����:%d\n", v[idx].lang[0], v[idx].lang[1], v[idx].lang[2], v[idx].lang[3]);
    int n = 0, m = 0;
    if (v[idx].yyh) {
        n = 0;
        m = 7;
    }
    else {
        n = 7;
        m = 7;
    }
    if (v[idx].ycyh) {
        m = 10;
    }

    for (int i = n; i < m; ++i) {
        printf("��%d�� ����:%s ����:%s\n",i+1, itemStr[v[idx].time[i][0]], itemStr[v[idx].time[i][1]]);
    }
    printf("\n");
}

void inputVltIndex(int index) {
    printf("������ ����:"            ); scanf("%s", v[index].name);
    printf("������ �Ա�:"            ); scanf("%s", v[index].gender);
    printf("������ ����:"            ); scanf("%d", &v[index].age);
    printf("������ ��ϵ�绰:"        ); scanf("%s", v[index].phone);
    printf("������ ���֤��:"        ); scanf("%s", v[index].idNum);
    printf("������ ��λ��Ϣ:"        ); scanf("%s", v[index].company);
    printf("������ �Ƿ�������˻�:"  ); scanf("%d", &v[index].yyh);
    printf("������ �Ƿ�����ǲ��˻�:"); scanf("%d", &v[index].ycyh);
    printf("������ �س� 1.�ﾶ 2.��Զ 3.��Ӿ:"); scanf("%d", &v[index].tc);
    printf("������ �����������\n");
    v[index].lang[0] = v[index].lang[1] = v[index].lang[2] = v[index].lang[3] = 0;
    int goon = 1;
    while (goon) {
        int l = nInput("�������� 1.���� 2.Ӣ�� 3.���� 4.����", 1, 4) - 1;
        v[index].lang[l] = nInput("�������������ճ̶� 0~8:", 0, 8);
        goon = nInput("�Ƿ���� 0/1:", 0, 1);
    }
}

void addVlt() {
    printf("���־Ը��\n������ ���:"            );
    int id;
    scanf("%d", &id);
    if (findVltByID(v[sz].id)!=-1) {
        printf("id�ظ�!");
        return;
    }
    for (int i = 0; i < 10; ++i) {
        v[sz].time[i][0] = idle;
        v[sz].time[i][1] = idle;
    }
    inputVltIndex(sz);
    v[sz].id = id;
    showVltByIndex(sz);
    ++sz;
}

void modify() {
    int index;
    if ((index = findVlt()) == -1) {
        printf("�����ڴ˱��\n");
        return;
    }
    showVltByIndex(index);
    switch (nInput(
        "��ѡ���޸�����:\n"
        "1 .����            \n"
        "2 .�Ա�            \n"
        "3 .����            \n"
        "4 .��ϵ�绰        \n"
        "5 .���֤��        \n"
        "6 .�Ƿ�������˻�  \n"
        "7 .�Ƿ�����ǲ��˻�\n"
        "8 .��λ��Ϣ        \n"
        "9 .�س�            \n"
        "10.�����������    \n"
        , 1,11 )
    ) {
    case 1 :printf("��ǰֵ:%s\n������ ����:"            , v[index].name   ); scanf("%s", v[index].name   ); break;
    case 2 :printf("��ǰֵ:%s\n������ �Ա�:"            , v[index].gender ); scanf("%s", v[index].gender ); break;
    case 3 :printf("��ǰֵ:%d\n������ ����:"            , v[index].age    ); scanf("%d", v[index].age    ); break;
    case 4 :printf("��ǰֵ:%s\n������ ��ϵ�绰:"        , v[index].phone  ); scanf("%s", v[index].phone  ); break;
    case 5 :printf("��ǰֵ:%s\n������ ���֤��:"        , v[index].idNum  ); scanf("%s", v[index].idNum  ); break;
    case 6 :printf("��ǰֵ:%d\n������ �Ƿ�����ǲ��˻�:", v[index].ycyh   ); scanf("%d", &v[index].ycyh  ); break;
    case 7 :printf("��ǰֵ:%d\n������ �Ƿ�������˻�:"  , v[index].yyh    ); scanf("%d", &v[index].yyh   ); break;
    case 8 :printf("��ǰֵ:%s\n������ ��λ��Ϣ:"        , v[index].company); scanf("%s", v[index].company); break;
    case 9 :printf("��ǰֵ:%d\n������ �س� 1.�ﾶ 2.��Զ 3.��Ӿ:", v[index].tc); scanf("%d", &v[index].tc); break;
    case 10: {
        int goon = 1;
        while (goon) {
            int l = nInput("�������� 1.���� 2.Ӣ�� 3.���� 4.����", 1, 4) - 1;
            v[index].lang[l] = nInput("�������������ճ̶� 0~8:", 0, 8);
            goon = nInput("�Ƿ���� 0/1:", 0, 1);
        }
    }break;
    }
}

void workPlan() {
    int item = nInput("־Ը�߹�������\n������������ 1.�ﾶ 2.��Զ 3.��Ӿ:", 1, 3) - 1;
    printf("����������ڵڼ���:");
    int day;
    scanf("%d", &day);
    --day;
    printf("��������� 0.���� 1.����");
    int ampm;
    scanf("%d", &ampm);
    int l = nInput("������ѡ�ֹ��� 1.�й� 2.Ӣ�� 3.���� 4.�¹�:", 1, 4) - 1;

    printf("��������Ҫ����λ־Ը��:");
    int n = 0;
    scanf("%d", &n);
    int idx[2][MAX_SZ];
    int isz[2] = { 0,0 };
    // ׼������������ xָ������ɸѡ������
    int x = 0;
    for (int i = 0; i < sz; ++i) {
        // ɸѡ��ʱ��ο��е�־Ը��
        if (v[i].time[day][ampm] != idle) {
            continue;
        }
        idx[0][isz[0]++] = i;
    }
    printf("��һ��ɸѡ ѡ����ʱ���־Ը��:");
    for (int i = 0; i < isz[0]; ++i) {
        printf("%s ", v[idx[0][i]].name);
    }
    printf("\n");
    do{
        if (isz[0] < n) {
            x = -1;
            break;
        }
        for (int i = 0; i < isz[0]; ++i) {
            Vlt* p = &v[idx[0][i]];
            // �ٴӸղŽ���� ����ѡ�ֹ���ɸѡ�����������־Ը��
            if (p->lang[l] == 0) {
                continue;
            }
            idx[1][isz[1]++] = idx[0][i];
        }
        printf("ͨ��ѡ�ֹ���ɸѡ�����������־Ը��:");
        for (int i = 0; i < isz[1]; ++i) {
            printf("%s ", v[idx[1][i]].name);
        }
        printf("\n");
        if (isz[1] >= n) {
            x = 1;
            break;
        }
        printf("������������ ��Ϊͨ���س�ɸѡ:");
        for (int i = 0; i < isz[0]; ++i) {
            Vlt* p = &v[idx[0][i]];
            // ͨ���س�ɸѡ
            if (p->tc != item) {
                continue;
            }
            idx[1][isz[1]++] = idx[0][i];
        }
        for (int i = 0; i < isz[1]; ++i) {
            printf("%s ", v[idx[1][i]].name);
        }
        printf("\n");
        // ��������� ��ֱ�Ӵӿ���ʱ���־Ը���м���
        x = 0;
    } while (0);
    if (x == -1) {
        printf("����������־Ը����������!����ӷ���������־Ը��!\n");
        return;
    }
    printf("Ϊ�ó����������%dλ־Ը��\n", n);
    // ���Գ̶��ɸߵ�������
    int flag = 1;
    int i = 0;
    for (i = 0; i < isz[x] - 1; i++) {
        int j = 0;
        for (j = 0; j < isz[x] - i - 1; j++) {
            if (v[idx[x][j]].lang[l] < v[idx[x][j+1]].lang[l]) {
                flag = 0;
                int t = idx[x][j];
                idx[x][j] = idx[x][j + 1];
                idx[x][j + 1] = t;
            }

        }
        if (flag == 1) {
            break;
        }
    }
    
    // Ϊɸѡ���־Ը������ʱ�䰲��
    for (int i = 0; i < n; ++i) {
        Vlt* p = &v[idx[x][i]];
        p->time[day][ampm] = item;
        printf("%s ", p->name);
    }
    printf("\n");
}

void workChange() {
    int idx = findVlt();
    if (idx == -1) {
        printf("û�������Ϣ\n");
        return;
    }
    int day = nInput("������Ŀǰ�뻻�ڼ���İ�:", 1, 10);
    day--;
    printf("�������뻻���绹������:");
    int ampm;
    scanf("%d", &ampm);

    if (v[idx].time[day][ampm] == idle) {
        printf("��־Ը�ߴ�ʱ��������\n");
        return;
    }

    printf("���뻻����,");
    int idx2 = findVlt();
    if (idx2 == -1) {
        printf("û�������Ϣ\n");
        return;
    }
    if (v[idx2].time[day][ampm] != idle) {
        printf("�Է��ڴ�ʱ��Ҳ�а���! ����ʧ��!\n");
        return;
    }
    if (day < 7 && v[idx2].yyh==0) {
        printf("�Է�û�вμ����˻��־Ը ���Բ����ڵ�1~7���ڽ��з���\n");
        return;
    }
    else if(day >7 && v[idx2].ycyh==0) {
        printf("�Է�û�вμ��ǲл��־Ը ���Բ����ڵ�8~10���ڽ��з���\n");
        return;
    }
    Item t = v[idx].time[day][ampm];
    v[idx].time[day][ampm] = v[idx2].time[day][ampm];
    v[idx2].time[day][ampm] = t;
    printf("����ɹ�!\n");
}

void tj() {
    printf("ͳ�Ƹ�ʱ��־Ը�߲�������\n");
    int count[10][2];
    for (int i = 0; i < 10; ++i) {
        count[i][0] = 0;
        count[i][1] = 0;
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < 10; ++j) {
            if( v[i].time[j][0]!=idle){
                count[j][0]++;
            }
            if (v[i].time[j][1] != idle) {
                count[j][1]++;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        printf("��%d�� ����:%d�� ����:%d��\n", i + 1, count[i][0], count[i][1]);
    }
}

int main() {
    while(1){
        switch (nInput(
            "��ӭʹ�ú������˻�־Ը�߹���ϵͳ\n"
            "1.ʹ�ð���\n"
            "2.־Ը����Ϣ�Ǽ�\n"
            "3.־Ը����Ϣ��ѯ\n"
            "4.־Ը����Ϣ�޸�\n"
            "5.־Ը�߹�������\n"
            "6.־Ը����ٻ���ϵͳ\n"
            "7.����\n"
            "8.����\n"
            "9.־Ը����Ϣͳ��\n"
            "10.��ʾ����־Ը��\n"
            "0.�˳�\n"
            "��ѡ����:",
            0, 10))
        {
        case 0:return 0;
        case 1:{
            helpInfo();
        }
        break;
        case 2:{
            addVlt();
        }
        break;
        case 3:{
            int idx = findVlt();
            if (idx!=-1) {
                showVltByIndex(idx);
            }
        }
        break;
        case 4:{
            modify();
        }
        break;
        case 5:{
            workPlan();
        }
        break;
        case 6:{
            workChange();
        }
        break;
        case 7: {
            save();
        }
        break;
        case 8: {
            load();
        }
        break;
        case 9:{
            tj();
        }
        break;

        case 10: {
            for (int i = 0; i < sz; ++i) {
                showVltByIndex(i);
            }
        }
        }
    }
    return 0;
}
