#include <iostream>

using namespace std;

class UnionFind final
{
    public:
        UnionFind(const int& n) : m_parent{new int[n]}, m_rank{new int[n]} {
            for(int i = 0; i < n; ++i)
            {
                m_parent[i] = i;
                m_rank[i] = 0;
            }
        }

        int find(const int& i)
        {
            if(m_parent[i] == i)
                return i;
            return m_parent[i] = find(m_parent[i]);
        }
        void make_union(const int& i,const int& j)
        {
            int a = find(i);
            int b = find(j); 
            if(a!=b)
                if(m_rank[a] < m_rank[b])
                    m_parent[a] = b;
                else if(m_rank[b] < m_rank[a])
                    m_parent[b] = a;
                else
                {
                    m_parent[a] = b;
                    ++m_rank[b];
                }
        }
        ~UnionFind() {
            delete[] m_rank;
            delete[] m_parent;
        }
    
    private:
    
        int* m_parent;
        int* m_rank;
};
bool DoesPathExistA(const int& n,const bool t[][5]) {
    if(!t[0][0])
        return 0;
    UnionFind obj(n*n); 
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            if(t[i][j])
            {
                if(i+1 < n && t[i+1][j]) //right
                    obj.make_union(i*n+j,(i+1)*n+j);
                if(j+1 < n && t[i][j+1]) //down
                    obj.make_union(i*n+j,i*n+j+1);
                }
        }
    return obj.find(0) == obj.find(n*n-1) ? 1 : 0;
}
bool DoesPathExistB(const int& n,const bool t[][5]) {
    UnionFind obj(n*n); 
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            if(t[i][j])
            {
                if(i+1 < n && t[i+1][j]) //right
                    obj.make_union(i*n+j,(i+1)*n+j);
                if(i-1 >= 0 && t[i-1][j]) //left
                    obj.make_union(i*n+j,(i-1)*n+j);
                if(j+1 < n && t[i][j+1]) //down
                    obj.make_union(i*n+j,i*n+j+1);
                }
        }

    for(int i = 0; i < n; ++i)
        if(t[0][i])
            for(int j = 0; j < n; ++j)
                if(t[n-1][j])
                    if(obj.find(i) == obj.find((n-1)*n+j))
                        return 1;
    return 0;
}

int main() {
    const int n = 5;

    bool t1[n][n] ={{1,1,0,0,1},
                    {0,1,0,0,1},
                    {0,1,1,0,0},
                    {0,1,1,1,1},
                    {1,0,1,0,1}};

    bool t2[n][n] ={{1,1,1,0,0},
                    {1,1,1,0,1},
                    {1,0,1,0,0},
                    {0,1,1,1,0},
                    {1,0,1,0,1}};

    bool t3[n][n] ={{0,0,1,0,1},
                    {1,0,1,0,1},
                    {0,1,0,0,1},
                    {0,1,1,1,0},
                    {1,1,1,0,1}};


    cout<<"t1: \n";
    cout << "a: " << DoesPathExistA(n,t1) << endl;
    cout << "b: " << DoesPathExistB(n,t1) << endl;

    cout<<"t2: \n";
    cout << "a: " << DoesPathExistA(n,t2) << endl;
    cout << "b: " << DoesPathExistB(n,t2) << endl;

    cout<<"t3: \n";
    cout << "a: " << DoesPathExistA(n,t3) << endl;
    cout << "b: " << DoesPathExistB(n,t3) << endl;
}