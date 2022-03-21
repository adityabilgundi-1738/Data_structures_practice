#include<iostream>
#include<vector>
using namespace std;

struct person{
    string name;
    vector<pair<string,int>> skill;
    bool busy;
};

void takeinput(vector<pair<string,vector<pair<string,int>>>> &contributors, vector<pair<string,pair<vector<int>,vector<pair<string,int>>>>> &projects, int people,int proj){
    while(people--){
        string name;
        int n;
        cin>>name;
        cin>>n;

        vector<pair<string,int>> temp;
        while(n--){
            string skill;
            int level;
            cin>>skill;
            cin>>level;
            temp.push_back({skill,level});
        }
        contributors.push_back({name,temp});
    }

    while(proj--){
        string name;
        int d,s,b,r;
        cin>>name>>d>>s>>b>>r;
        vector<int> data;
        data.push_back(d);
        data.push_back(s);
        data.push_back(b);

        vector<pair<string,int>> rolesreq;
        while(r--){
            string role;
            int level;
            cin>>role;
            cin>>level;
            rolesreq.push_back({role,level});
        }
        projects.push_back({name,{data,rolesreq}});
    }

}

void createNode(vector<vector<pair<int,vector<int>>>> &graph, int srcnode, int dstnode, int score, int days, int best){
    vector<int> vct;
    vct.push_back(score);
    vct.push_back(days);
    vct.push_back(best);
    graph[srcnode].push_back({dstnode,vct});
}

void takeinput2(vector<&person> peopleAddresses){
    int people,proj;
    cin>>people;
    cin>>proj;

    while(people--){
        person p;
        peopleAddresses.push_back(&p)
        string name;
        cin>>name;
        p.name = name;
        int skills;
        cin>>skills;
        while(skills--){
            string skill;
            int level;
            cin>>skill;
            cin>>level;
            p.skill.push_back({skill,level});
        }
        p.busy = 0;
    }

    while(proj--){
        
    }
    
}

int main(){
    int people,proj;
    cin>>people>>proj;
    vector<pair<string,vector<pair<string,int>>>> contributors;
    vector<pair<string,pair<vector<int>,vector<pair<string,int>>>>> projects;

    takeinput(contributors,projects,people,proj);

    vector<vector<pair<int,vector<int>>>> graph;


    return 0;
}