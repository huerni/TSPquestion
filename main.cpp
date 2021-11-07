//模拟退火算法,2.6s
# include <bits/stdc++.h>
using namespace std;
const int num = 5;
double T0 = 18000;
double T1 = 1e-9;
double r = 0.98;
int len = 1000;
double mp[num+3][num+3];
struct node{
    double x, y;
}point[num+3];
double dis(int u, int v){
    double x = point[u].x-point[v].x;
    double y = point[u].y-point[v].y;
    return sqrt(x*x+y*y);
}
void init_map(){  //初始化边的情况
    for(int i=0; i<num; ++i){
        scanf("%lf%lf",&point[i].x,&point[i].y);
    }
    for(int i=0; i<num; ++i){
        for(int j=0; j<num; ++j){
            mp[i][j] = dis(i,j);
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
}
double cal_distance(vector<int>x){//计算染色体的距离
    double res = mp[x[0]][x[num-1]];
    for(int i=0; i<num-1; ++i)
        res += mp[x[i]][x[i+1]];
    return res;
}

void change(vector<int>&v){
    int x = rand()%num;
    int y = rand()%num;
    while(y == x) y = rand()%num;
    for(int i=0; i+x<=(x+y>>1); ++i)
        swap(v[i+x], v[y-i]);
}
int main(){
    //freopen("a.txt", "r", stdin);
    //reopen("3.txt", "w", stdout);
    srand(time(0));
    vector<int>ans;
    init_map();
    int icount = 0, cnt = 0;
    for(int i=0; i<num; ++i) ans.push_back(i);
    random_shuffle(ans.begin(), ans.end());
    while(T0 > T1){
        for(int i=0; i<len; ++i){
            vector<int>tmp = ans;
            change(tmp);
            double pre = cal_distance(ans);//前
            double cur = cal_distance(tmp);//后
            if(cur < pre || exp(-(cur-pre)/T0) > ((double)rand())/RAND_MAX){
                ans = tmp;

            }
        }
        ++icount;
        T0 *= r;
    }
    printf("run %d %d times\n",icount,cnt);
    printf("%f\n",cal_distance(ans));
    for(int i:ans) printf("%d ",i);
    return 0;
}