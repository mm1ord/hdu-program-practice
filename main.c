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

char const* itemStr[4]={"无","田径","跳远","游泳"};

typedef enum Country {
    cn,
    en,
    fc,
    gm,
};
char const* countryStr[4] = { "中国","英国","法国","德国" };
char const* langStr[4] = { "中文","英文","法文","德文" };

typedef struct Vlt {
    int id          ;   // 编号
    Str name        ;   // 姓名
    Str gender      ;   // 性别
    int age         ;   // 年龄
    Str phone       ;   // 联系电话
    Str idNum       ;   // 身份证号
    Str company     ;   // 单位信息
    int yyh         ;   // 是否服务亚运会
    int ycyh        ;   // 是否服务亚残运会
    Item tc         ;   // 特长
    int lang[4]     ;   // 语言和等级
    Item time[10][2] ;  // 服务时间 10天 上午 下午
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
        printf("输入有误 请重新输入");
    }
    return c;
}

void helpInfo() {
    printf(
        "=========================================================="
        "1、 使用帮助\n"
        "   显示详细的功能说明"
        "2、志愿者信息登记"
        "   依次输入姓名、性别、年龄、联系电话、身份证号、单位信息、外语掌握情况(掌握外语的种类、熟练程度)、是否担任过其他活动的志愿者， 能够提供志愿服务的时间(仅给两个选项，服务亚运会和服务亚运会以及亚残运会)"
        "3、 志愿者信息查询"
        "    输入志愿者编号"
        "    根据编号显示信息"
        "- 4、志愿者信息修改一 输入志愿者编号\n"
        "   选择修改内容\n"
        "   显示修改前的内容\n"
        "   输入修改之后的内容\n"
        "5.志愿者工作安排\n"
        "   输入比赛有关的信息\n"
        "   先筛选该时间段空闲的志愿者\n"
        "   再根据国别筛选志愿者，若不足则再用特长筛选， 还不够就直接从时间空闲的志愿者中加入\n"
        "6、志愿者请假换班系统一输入志愿者编号一 选择换班的时间(换之前的时间和换之后的时间)一输入想要换班的人的编号一 判断是否符合换班条件(主要是时间是否存在冲突)\n"
        "10.志愿者信息统计一输 入想要展示的信息\n"
        "   展示相应信息\n"
        "   不符合则重新输入\n"
        "   杭州亚运会志愿者管理系统\n"
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
    printf("请输入志愿者编号:");
    int id;
    scanf("%d", &id);
    return findVltByID(id);
}

void showVltByIndex(int idx) {
    printf("=======================\n姓名            :%s\n",v[idx].name);
    printf("性别            :%s\n",v[idx].gender);
    printf("年龄            :%d\n",v[idx].age);
    printf("联系电话        :%s\n",v[idx].phone);
    printf("身份证号        :%s\n",v[idx].idNum);
    printf("单位信息        :%s\n",v[idx].company);
    printf("是否服务亚运会  :%s\n",v[idx].yyh?"是":"否");
    printf("是否服务亚残运会:%s\n",v[idx].ycyh?"是":"否");
    printf("特长            :%s\n", itemStr[v[idx].tc]);
    printf("语言            :中文:%d 英文:%d 法文:%d 德文:%d\n", v[idx].lang[0], v[idx].lang[1], v[idx].lang[2], v[idx].lang[3]);
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
        printf("第%d天 上午:%s 下午:%s\n",i+1, itemStr[v[idx].time[i][0]], itemStr[v[idx].time[i][1]]);
    }
    printf("\n");
}

void inputVltIndex(int index) {
    printf("请输入 姓名:"            ); scanf("%s", v[index].name);
    printf("请输入 性别:"            ); scanf("%s", v[index].gender);
    printf("请输入 年龄:"            ); scanf("%d", &v[index].age);
    printf("请输入 联系电话:"        ); scanf("%s", v[index].phone);
    printf("请输入 身份证号:"        ); scanf("%s", v[index].idNum);
    printf("请输入 单位信息:"        ); scanf("%s", v[index].company);
    printf("请输入 是否服务亚运会:"  ); scanf("%d", &v[index].yyh);
    printf("请输入 是否服务亚残运会:"); scanf("%d", &v[index].ycyh);
    printf("请输入 特长 1.田径 2.跳远 3.游泳:"); scanf("%d", &v[index].tc);
    printf("请输入 语言掌握情况\n");
    v[index].lang[0] = v[index].lang[1] = v[index].lang[2] = v[index].lang[3] = 0;
    int goon = 1;
    while (goon) {
        int l = nInput("语言种类 1.中文 2.英文 3.法文 4.德文", 1, 4) - 1;
        v[index].lang[l] = nInput("请输入语言掌握程度 0~8:", 0, 8);
        goon = nInput("是否继续 0/1:", 0, 1);
    }
}

void addVlt() {
    printf("添加志愿者\n请输入 编号:"            );
    int id;
    scanf("%d", &id);
    if (findVltByID(v[sz].id)!=-1) {
        printf("id重复!");
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
        printf("不存在此编号\n");
        return;
    }
    showVltByIndex(index);
    switch (nInput(
        "请选择修改内容:\n"
        "1 .姓名            \n"
        "2 .性别            \n"
        "3 .年龄            \n"
        "4 .联系电话        \n"
        "5 .身份证号        \n"
        "6 .是否服务亚运会  \n"
        "7 .是否服务亚残运会\n"
        "8 .单位信息        \n"
        "9 .特长            \n"
        "10.外语掌握情况    \n"
        , 1,11 )
    ) {
    case 1 :printf("当前值:%s\n请输入 姓名:"            , v[index].name   ); scanf("%s", v[index].name   ); break;
    case 2 :printf("当前值:%s\n请输入 性别:"            , v[index].gender ); scanf("%s", v[index].gender ); break;
    case 3 :printf("当前值:%d\n请输入 年龄:"            , v[index].age    ); scanf("%d", v[index].age    ); break;
    case 4 :printf("当前值:%s\n请输入 联系电话:"        , v[index].phone  ); scanf("%s", v[index].phone  ); break;
    case 5 :printf("当前值:%s\n请输入 身份证号:"        , v[index].idNum  ); scanf("%s", v[index].idNum  ); break;
    case 6 :printf("当前值:%d\n请输入 是否服务亚残运会:", v[index].ycyh   ); scanf("%d", &v[index].ycyh  ); break;
    case 7 :printf("当前值:%d\n请输入 是否服务亚运会:"  , v[index].yyh    ); scanf("%d", &v[index].yyh   ); break;
    case 8 :printf("当前值:%s\n请输入 单位信息:"        , v[index].company); scanf("%s", v[index].company); break;
    case 9 :printf("当前值:%d\n请输入 特长 1.田径 2.跳远 3.游泳:", v[index].tc); scanf("%d", &v[index].tc); break;
    case 10: {
        int goon = 1;
        while (goon) {
            int l = nInput("语言种类 1.中文 2.英文 3.法文 4.德文", 1, 4) - 1;
            v[index].lang[l] = nInput("请输入语言掌握程度 0~8:", 0, 8);
            goon = nInput("是否继续 0/1:", 0, 1);
        }
    }break;
    }
}

void workPlan() {
    int item = nInput("志愿者工作安排\n请输入比赛类别 1.田径 2.跳远 3.游泳:", 1, 3) - 1;
    printf("请输入比赛在第几天:");
    int day;
    scanf("%d", &day);
    --day;
    printf("请输入比赛 0.上午 1.下午");
    int ampm;
    scanf("%d", &ampm);
    int l = nInput("请输入选手国家 1.中国 2.英国 3.法国 4.德国:", 1, 4) - 1;

    printf("请输入需要多少位志愿者:");
    int n = 0;
    scanf("%d", &n);
    int idx[2][MAX_SZ];
    int isz[2] = { 0,0 };
    // 准备了两个数组 x指向最终筛选的数组
    int x = 0;
    for (int i = 0; i < sz; ++i) {
        // 筛选该时间段空闲的志愿者
        if (v[i].time[day][ampm] != idle) {
            continue;
        }
        idx[0][isz[0]++] = i;
    }
    printf("第一轮筛选 选择有时间的志愿者:");
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
            // 再从刚才结果中 根据选手国别筛选掌握其外语的志愿者
            if (p->lang[l] == 0) {
                continue;
            }
            idx[1][isz[1]++] = idx[0][i];
        }
        printf("通过选手国别筛选掌握其外语的志愿者:");
        for (int i = 0; i < isz[1]; ++i) {
            printf("%s ", v[idx[1][i]].name);
        }
        printf("\n");
        if (isz[1] >= n) {
            x = 1;
            break;
        }
        printf("外语人数不足 改为通过特长筛选:");
        for (int i = 0; i < isz[0]; ++i) {
            Vlt* p = &v[idx[0][i]];
            // 通过特长筛选
            if (p->tc != item) {
                continue;
            }
            idx[1][isz[1]++] = idx[0][i];
        }
        for (int i = 0; i < isz[1]; ++i) {
            printf("%s ", v[idx[1][i]].name);
        }
        printf("\n");
        // 如果都不足 则直接从空闲时间的志愿者中加入
        x = 0;
    } while (0);
    if (x == -1) {
        printf("符合条件的志愿者人数不足!请添加符合条件的志愿者!\n");
        return;
    }
    printf("为该场比赛添加了%d位志愿者\n", n);
    // 语言程度由高到低排序
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
    
    // 为筛选后的志愿者设置时间安排
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
        printf("没有相关信息\n");
        return;
    }
    int day = nInput("请输入目前想换第几天的班:", 1, 10);
    day--;
    printf("请输入想换上午还是下午:");
    int ampm;
    scanf("%d", &ampm);

    if (v[idx].time[day][ampm] == idle) {
        printf("该志愿者此时间无任务\n");
        return;
    }

    printf("输入换班人,");
    int idx2 = findVlt();
    if (idx2 == -1) {
        printf("没有相关信息\n");
        return;
    }
    if (v[idx2].time[day][ampm] != idle) {
        printf("对方在此时间也有安排! 换班失败!\n");
        return;
    }
    if (day < 7 && v[idx2].yyh==0) {
        printf("对方没有参加亚运会的志愿 所以不能在第1~7天内进行服务\n");
        return;
    }
    else if(day >7 && v[idx2].ycyh==0) {
        printf("对方没有参加亚残会的志愿 所以不能在第8~10天内进行服务\n");
        return;
    }
    Item t = v[idx].time[day][ampm];
    v[idx].time[day][ampm] = v[idx2].time[day][ampm];
    v[idx2].time[day][ampm] = t;
    printf("换班成功!\n");
}

void tj() {
    printf("统计各时间志愿者参与人数\n");
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
        printf("第%d天 上午:%d人 下午:%d人\n", i + 1, count[i][0], count[i][1]);
    }
}

int main() {
    while(1){
        switch (nInput(
            "欢迎使用杭州亚运会志愿者管理系统\n"
            "1.使用帮助\n"
            "2.志愿者信息登记\n"
            "3.志愿者信息查询\n"
            "4.志愿者信息修改\n"
            "5.志愿者工作安排\n"
            "6.志愿者请假换班系统\n"
            "7.保存\n"
            "8.加载\n"
            "9.志愿者信息统计\n"
            "10.显示所有志愿者\n"
            "0.退出\n"
            "请选择功能:",
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
