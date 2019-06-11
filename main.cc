#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <list>
#include <queue>
#include <unordered_map>
#include "time.h"
#include "network_manager.h"
#include "gplot.h"
#include "path.h"
#include <limits.h> 

using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();
NetworkManager *nm_temp = nm;
const int stop_time = 100;
int target_sum = 0;
vector<string> node_name;
vector<int> node_diff_degree;
vector<pair<string, int>> node_avail_pos;
vector<pair<string, int>> node_avail_neg;
vector<pair<string, int>> node_avail_pos_t;
vector<pair<string, int>> node_avail_neg_t;
vector<int> gold_i;
vector<int> gold_i_ss;
vector<int> weight;
vector<pair<string, string>> gold_s;
int temp_sum = 1000000;
bool a = false;
vector<pair<int, int>> temp_sss;

void printpath(vector<int>& path , vector<vector<int>>&graph) 
{ 
    int temp_sum_sum = 0;
	for(int i = 0 ; i < path.size()-1 ; i++)
	{
		temp_sss.push_back(pair<int,int>(path[i],path[i+1]));
	}
    for (int i = 0; i < path.size() - 1; i++)  
	{
		temp_sum_sum += graph[path[i]][path[i+1]];
	}
	if(temp_sum_sum < temp_sum){
		temp_sss.clear();
		for(int i = 0 ; i < path.size()-1 ; i++)
		{
			temp_sss.push_back(pair<int,int>(path[i],path[i+1]));
		}
		temp_sum = temp_sum_sum;
		
	}
} 
int isNotVisited(int x, vector<int>& path) 
{ 
    for (int i = 0; i < path.size(); i++)  
        if (path[i] == x)  
            return 0;  
    return 1; 
} 
 
void findpaths(vector<vector<int> >&g, int src, int dst, int v,vector<vector<int>>&graph) 
{ 
    queue<vector<int> > q; 
    vector<int> path; 
    path.push_back(src); 
    q.push(path); 
    while (!q.empty()) { 
        path = q.front(); 
        q.pop(); 
        int last = path[path.size() - 1]; 
        if (last == dst)  {
			printpath(path,graph);  
		}       
        for (int i = 0; i < g[last].size(); i++) { 
            if (isNotVisited(g[last][i], path)) { 
                vector<int> newpath(path); 
                newpath.push_back(g[last][i]); 
                q.push(newpath); 
            } 
        } 
    } 
} 

void fetch_node_name()
{
	Vertex* all_node = nm->get_all_nodes(); // get all node
	while(all_node != NULL){
		node_name.push_back(all_node->name);
		all_node = all_node->next;
	} // put the all node into the vector
	if(node_name.size() == 1)
	{
		node_name.clear();
		node_name.push_back("a");
	}
	if(node_name.size() == 2)
	{
		node_name.clear();
		node_name.push_back("a"); 
		node_name.push_back("b");
	}
	if(node_name.size() == 3)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
	}
	if(node_name.size() == 4)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
	}
	if(node_name.size() == 5)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
	}
	if(node_name.size() == 6)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
	}
	if(node_name.size() == 7)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
	}
	if(node_name.size() == 8)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
	}
	if(node_name.size() == 9)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
		node_name.push_back("i");
	}
	if(node_name.size() == 10)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
		node_name.push_back("i");
		node_name.push_back("j");
	}
	if(node_name.size() == 11)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
		node_name.push_back("i");
		node_name.push_back("j");
		node_name.push_back("k");
	}
	if(node_name.size() == 12)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
		node_name.push_back("i");
		node_name.push_back("j");
		node_name.push_back("k");
		node_name.push_back("l");
	}
	if(node_name.size() == 13)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
		node_name.push_back("i");
		node_name.push_back("j");
		node_name.push_back("k");
		node_name.push_back("l");
		node_name.push_back("m");
	}
	if(node_name.size() == 14)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
		node_name.push_back("i");
		node_name.push_back("j");
		node_name.push_back("k");
		node_name.push_back("l");
		node_name.push_back("m");
		node_name.push_back("n");
	}
	if(node_name.size() == 15)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
		node_name.push_back("i");
		node_name.push_back("j");
		node_name.push_back("k");
		node_name.push_back("l");
		node_name.push_back("m");
		node_name.push_back("n");
		node_name.push_back("o");
	}
	if(node_name.size() == 16)
	{
		node_name.clear();
		node_name.push_back("a");
		node_name.push_back("b");
		node_name.push_back("c");
		node_name.push_back("d");
		node_name.push_back("e");
		node_name.push_back("f");
		node_name.push_back("g");
		node_name.push_back("h");
		node_name.push_back("i");
		node_name.push_back("j");
		node_name.push_back("k");
		node_name.push_back("l");
		node_name.push_back("m");
		node_name.push_back("n");
		node_name.push_back("o");
		node_name.push_back("p");
	}
}
void Construct_adj_list(vector<vector<int>>& adj_list)
{
	Edge* all_edge = nm->elist;
	while(all_edge != NULL){
		for(int i = 0 ; i < node_name.size() ; ++i){
		if(all_edge->head->name == node_name[i]){
			for(int j = 0 ; j < node_name.size() ; ++j){
				if(all_edge->tail->name == node_name[j])
					adj_list[i].push_back(j);
			}
			}
		}
		if(a){
		target_sum+=all_edge->flowval;
		}
		all_edge = all_edge->next;
	}
	a= false;
}
void Construct_adj_matrix(vector<vector<int>>& graph)
{
	for(int i = 0 ; i < graph.size() ; ++i)   //construct NxN vector
	{
		for(int j = 0 ; j < graph.size() ; ++j)
			graph[i].push_back(0);
	}
	Edge* all_edge = nm->elist;
	while(all_edge != NULL){
		for(int i = 0 ; i < node_name.size() ; ++i){
		if(all_edge->head->name == node_name[i]){
			for(int j = 0 ; j < node_name.size() ; ++j){
				if(all_edge->tail->name == node_name[j])
					graph[i][j] = (all_edge->flowval);
			}
			}
		}
		all_edge = all_edge->next;
	}
}
void Cal_Degree(vector<int>& node_in_degree , vector<int>& node_out_degree,vector<vector<int>>& adj_list)
{
	Edge* all_edge = nm->elist;
	while(all_edge != NULL){
		for(int i = 0 ; i < node_name.size() ; ++i){
			if(all_edge->head->name == node_name[i])
				node_out_degree[i]++;
			if(all_edge->tail->name == node_name[i])
				node_in_degree[i]++;
		}
		all_edge = all_edge->next;
	}
	for(int i = 0 ; i < node_name.size() ; ++i){
		node_diff_degree.push_back(node_out_degree[i] - node_in_degree[i]);
	}
	for(int i = 0 ; i < node_name.size() ; ++i){
		if(node_diff_degree[i] > 0){
			node_avail_pos.push_back(pair<string,int>(node_name[i],node_diff_degree[i]));
		}
		else if(node_diff_degree[i] < 0){
			node_avail_neg.push_back(pair<string,int>(node_name[i],node_diff_degree[i]));
		}
	}
}

void printCircuit(vector< vector<int> > adj) 
{ 
    unordered_map<int,int> edge_count; 
  
    for (int i=0; i<adj.size(); i++) 
    { 
        edge_count[i] = adj[i].size(); 
    } 
    if (!adj.size()) 
        return; //empty graph 
  
    stack<int> curr_path; 
    vector<int> circuit; 
    curr_path.push(0); 
    int curr_v = 0; // Current vertex 
    while (!curr_path.empty()) 
    { 
        if (edge_count[curr_v]) 
        { 
            curr_path.push(curr_v); 
            int next_v = adj[curr_v].back(); 
            edge_count[curr_v]--; 
            adj[curr_v].pop_back(); 
            curr_v = next_v; 
        } 
        else
        { 
            circuit.push_back(curr_v); 
            // Back-tracking 
            curr_v = curr_path.top(); 
            curr_path.pop(); 
        } 
    } 
	cout << "Chinese Postman Path : \n";
    for (int i=circuit.size()-1; i>=0; i--) 
    { 
		switch(circuit[i])
		{
			case 0: cout << "a"; break;
			case 1: cout << "b"; break;
			case 2: cout << "c"; break;
			case 3: cout << "d"; break;
			case 4: cout << "e"; break;
			case 5: cout << "f"; break;
			case 6: cout << "g"; break;
			case 7: cout << "h"; break;
			case 8: cout << "i"; break;
			case 9: cout << "j"; break;
			case 10:cout << "k"; break;
			case 11:cout << "l"; break;
			case 12:cout << "m"; break;
			case 13:cout << "n"; break;
			case 14:cout << "o"; break;
			case 15:cout << "p"; break;
			case 16:cout << "q"; break;
			case 17:cout << "r"; break;
			case 18:cout << "s"; break;
			case 19:cout << "t"; break;
			case 20:cout << "u"; break;
			case 21:cout << "v"; break;
			case 22:cout << "w"; break;
			case 23:cout << "x"; break;
			case 24:cout << "y"; break;
			case 25:cout << "z"; break;
			default: cout << circuit[i];break;
		}
        if (i) cout<<" -> "; 
    } 
	cout << endl<< "The Cost : " << target_sum << endl;
	cout << "-------------------------\n";
} 
void AddEdgeToGraph(vector<vector<int>> adj_list , vector<vector<int>> graph)
{
	srand(time(NULL));
	vector<int> temp_i;
	vector<pair<string, string>> temp_s;
	int now_sum = 0;
	int iteration = 0;
	node_avail_pos_t.assign(node_avail_pos.begin() , node_avail_pos.end());
	node_avail_neg_t.assign(node_avail_neg.begin() , node_avail_neg.end());
	while(true){
		int sum = 0;
		for(int i = 0 ; i < node_avail_pos_t.size() ; i++)
			sum += node_avail_pos_t[i].second;
		
		//============================
		//random select the pos vertex
		//============================
		int ran_index1 ;
		int ran_index2 ;
		ran_index1= rand()% node_avail_pos_t.size();
		ran_index2= rand()% node_avail_neg_t.size();
		int source = -1;
		int target = -1;
		if(node_avail_neg_t[ran_index2].first == "a" || node_avail_neg_t[ran_index2].first == "A")source = 0;
		else if(node_avail_neg_t[ran_index2].first == "b"|| node_avail_neg_t[ran_index2].first == "B")source = 1;
		else if(node_avail_neg_t[ran_index2].first == "c"|| node_avail_neg_t[ran_index2].first == "C")source = 2;
		else if(node_avail_neg_t[ran_index2].first == "d"|| node_avail_neg_t[ran_index2].first == "D")source = 3;
		else if(node_avail_neg_t[ran_index2].first == "e"|| node_avail_neg_t[ran_index2].first == "E")source = 4;
		else if(node_avail_neg_t[ran_index2].first == "f"|| node_avail_neg_t[ran_index2].first == "F")source = 5;
		else if(node_avail_neg_t[ran_index2].first == "g"|| node_avail_neg_t[ran_index2].first == "G")source = 6;
		else if(node_avail_neg_t[ran_index2].first == "h"|| node_avail_neg_t[ran_index2].first == "H")source = 7;
		else if(node_avail_neg_t[ran_index2].first == "i"|| node_avail_neg_t[ran_index2].first == "I")source = 8;
		else if(node_avail_neg_t[ran_index2].first == "j"|| node_avail_neg_t[ran_index2].first == "J")source = 9;
		else if(node_avail_neg_t[ran_index2].first == "k"|| node_avail_neg_t[ran_index2].first == "K")source = 10;
		else if(node_avail_neg_t[ran_index2].first == "l"|| node_avail_neg_t[ran_index2].first == "L")source = 11;
		else if(node_avail_neg_t[ran_index2].first == "m"|| node_avail_neg_t[ran_index2].first == "M")source = 12;
		else if(node_avail_neg_t[ran_index2].first == "n"|| node_avail_neg_t[ran_index2].first == "N")source = 13;
		else if(node_avail_neg_t[ran_index2].first == "o"|| node_avail_neg_t[ran_index2].first == "O")source = 14;
		else if(node_avail_neg_t[ran_index2].first == "p"|| node_avail_neg_t[ran_index2].first == "P")source = 15;
		else if(node_avail_neg_t[ran_index2].first == "q"|| node_avail_neg_t[ran_index2].first == "Q")source = 16;
		else if(node_avail_neg_t[ran_index2].first == "r"|| node_avail_neg_t[ran_index2].first == "R")source = 17;
		else if(node_avail_neg_t[ran_index2].first == "s"|| node_avail_neg_t[ran_index2].first == "S")source = 18;
		else if(node_avail_neg_t[ran_index2].first == "t"|| node_avail_neg_t[ran_index2].first == "T")source = 19;
		else if(node_avail_neg_t[ran_index2].first == "u"|| node_avail_neg_t[ran_index2].first == "Y")source = 20;
		else if(node_avail_neg_t[ran_index2].first == "v"|| node_avail_neg_t[ran_index2].first == "V")source = 21;
		else if(node_avail_neg_t[ran_index2].first == "w"|| node_avail_neg_t[ran_index2].first == "W")source = 22;
		else if(node_avail_neg_t[ran_index2].first == "x"|| node_avail_neg_t[ran_index2].first == "X")source = 23;
		else if(node_avail_neg_t[ran_index2].first == "y"|| node_avail_neg_t[ran_index2].first == "Y")source = 24;
		else if(node_avail_neg_t[ran_index2].first == "z"|| node_avail_neg_t[ran_index2].first == "Z")source = 25;
		if(node_avail_pos_t[ran_index1].first == "a" || node_avail_pos_t[ran_index1].first == "A")target = 0;
		else if(node_avail_pos_t[ran_index1].first == "b"|| node_avail_pos_t[ran_index1].first == "B")target = 1;
		else if(node_avail_pos_t[ran_index1].first == "c"|| node_avail_pos_t[ran_index1].first == "C")target = 2;
		else if(node_avail_pos_t[ran_index1].first == "d"|| node_avail_pos_t[ran_index1].first == "D")target = 3;
		else if(node_avail_pos_t[ran_index1].first == "e"|| node_avail_pos_t[ran_index1].first == "E")target = 4;
		else if(node_avail_pos_t[ran_index1].first == "f"|| node_avail_pos_t[ran_index1].first == "F")target = 5;
		else if(node_avail_pos_t[ran_index1].first == "g"|| node_avail_pos_t[ran_index1].first == "G")target = 6;
		else if(node_avail_pos_t[ran_index1].first == "h"|| node_avail_pos_t[ran_index1].first == "H")target = 7;
		else if(node_avail_pos_t[ran_index1].first == "i"|| node_avail_pos_t[ran_index1].first == "I")target = 8;
		else if(node_avail_pos_t[ran_index1].first == "j"|| node_avail_pos_t[ran_index1].first == "J")target = 9;
		else if(node_avail_pos_t[ran_index1].first == "k"|| node_avail_pos_t[ran_index1].first == "K")target = 10;
		else if(node_avail_pos_t[ran_index1].first == "l"|| node_avail_pos_t[ran_index1].first == "L")target = 11;
		else if(node_avail_pos_t[ran_index1].first == "m"|| node_avail_pos_t[ran_index1].first == "M")target = 12;
		else if(node_avail_pos_t[ran_index1].first == "n"|| node_avail_pos_t[ran_index1].first == "N")target = 13;
		else if(node_avail_pos_t[ran_index1].first == "o"|| node_avail_pos_t[ran_index1].first == "O")target = 14;
		else if(node_avail_pos_t[ran_index1].first == "p"|| node_avail_pos_t[ran_index1].first == "P")target = 15;
		else if(node_avail_pos_t[ran_index1].first == "q"|| node_avail_pos_t[ran_index1].first == "Q")target = 16;
		else if(node_avail_pos_t[ran_index1].first == "r"|| node_avail_pos_t[ran_index1].first == "R")target = 17;
		else if(node_avail_pos_t[ran_index1].first == "s"|| node_avail_pos_t[ran_index1].first == "S")target = 18;
		else if(node_avail_pos_t[ran_index1].first == "t"|| node_avail_pos_t[ran_index1].first == "T")target = 19;
		else if(node_avail_pos_t[ran_index1].first == "u"|| node_avail_pos_t[ran_index1].first == "U")target = 20;
		else if(node_avail_pos_t[ran_index1].first == "v"|| node_avail_pos_t[ran_index1].first == "V")target = 21;
		else if(node_avail_pos_t[ran_index1].first == "w"|| node_avail_pos_t[ran_index1].first == "W")target = 22;
		else if(node_avail_pos_t[ran_index1].first == "x"|| node_avail_pos_t[ran_index1].first == "X")target = 23;
		else if(node_avail_pos_t[ran_index1].first == "y"|| node_avail_pos_t[ran_index1].first == "Y")target = 24;
		else if(node_avail_pos_t[ran_index1].first == "z"|| node_avail_pos_t[ran_index1].first == "Z")target = 25;
			
		findpaths(adj_list , source , target , node_name.size(), graph);
		temp_i.push_back(temp_sum);
		temp_sum = 1000000;
		for(int i = 0 ; i < temp_sss.size() ; ++i)
			temp_s.push_back(pair<string,string>(node_name[temp_sss[i].first] , node_name[temp_sss[i].second]));
		
		temp_sss.clear();
		node_avail_pos_t[ran_index1].second --;
		node_avail_neg_t[ran_index2].second ++;
		
		if(node_avail_pos_t[ran_index1].second == 0)
			node_avail_pos_t.erase(node_avail_pos_t.begin() + ran_index1);
		if(node_avail_neg_t[ran_index2].second == 0)
			node_avail_neg_t.erase(node_avail_neg_t.begin() + ran_index2);
		
		//====================
		//jump out the while
		//====================
		if(node_avail_pos_t.size() == 0){
			for(int i = 0 ; i < temp_i.size() ;++i)
			{
				now_sum += temp_i[i];
			}
			if(now_sum < target_sum || iteration == 0)
			{
				target_sum = now_sum;
				gold_i.clear();
				gold_s.clear();
				gold_i.assign(temp_i.begin() , temp_i.end());
				gold_s.assign(temp_s.begin() , temp_s.end());
			}
			++iteration;
			now_sum = 0;
			temp_i.clear();
			temp_s.clear();
			
			gold_i_ss.clear();
			node_avail_pos_t.assign(node_avail_pos.begin() , node_avail_pos.end());
			node_avail_neg_t.assign(node_avail_neg.begin() , node_avail_neg.end());
		}
		if(iteration == stop_time){
			for(int i = 0 ; i < gold_s.size() ; ++i){
					nm->connect(gold_s[i].first , gold_s[i].second);
			}
			cout << "-------------------------\n";
			cout << "Traverse Complete!!!\n";
			break;
		}
	}
}
void min_cost()
{
	Edge* all_edge = nm->elist;
	while(all_edge != NULL){
		target_sum += all_edge->flowval;
		all_edge = all_edge->next;
	}
}
int main(int argc, char** argv){
	//============================
	//        Main Process
	//============================
	nm->interpret("topo.txt");
    nm->print_all_e();
	fetch_node_name();
	vector<int> node_out_degree(node_name.size(),0);
	vector<int> node_in_degree(node_name.size(),0);
	vector<vector<int>> adj_list(node_name.size());
	vector<vector<int>> adj_list1(node_name.size());
	vector<vector<int>>graph(node_name.size());
	Cal_Degree(node_in_degree, node_out_degree, adj_list);
	Construct_adj_matrix(graph);
	Construct_adj_list(adj_list);
	if(node_avail_pos.size() != 0){
		AddEdgeToGraph(adj_list,graph);
		min_cost();
		Construct_adj_list(adj_list1);
		printCircuit(adj_list1);
	}
	else{
		cout << "else";
		min_cost();
		Construct_adj_list(adj_list1);
		printCircuit(adj_list1);
	}
	a = true;
	
	
	
	//====================
	//        Test
	//====================
	/*int a = 5;
	int b =1;
	findpaths(adj_list , a , b , node_name.size(), graph);*/
	//dijkstra(graph,a, b);
	/*for(int i = 0 ; i < gold_i_ss.size() ; ++i){
					cout << gold_i_ss[i] << endl;
				}
	for(int i = 0 ; i < node_name.size() ; ++i)
	{
		cout << node_name[i] << "  in_degree : " << node_in_degree[i] << " out_degree : " << node_out_degree[i];
		cout << "\n";
	}*/
	//cout << Find_Minimum_Path("f" , "b");
	//nm->print_all_v();
	//nm->print_all_e();
	/*vector<vector<int>> a(n);
	cout << n << endl;
	int perm[12];
	for (int i = 0; i < n; i++) perm[i] = 1;
	do
		if (isValid(perm, n))
			printPerm(perm, n, a);
	while (next(perm, n));*/
	/*for(int i = 0 ; i < graph.size() ; ++i)
	{
		for(int j = 0 ; j < graph[i].size() ; ++j)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/
	/*for(int i = 0 ; i < node_name.size() ; ++i)
	{
		cout << node_name[i] << "  in_degree : " << node_in_degree[i] << " out_degree : " << node_out_degree[i];
		cout << "\n";
	}*/
	/*for(int i = 0 ; i < adj_list.size() ; ++i)
	{
		for(int j = 0 ; j < adj_list[i].size() ; ++j){
			cout << i << " : " << adj_list[i][j] ;
			cout << "\n";
		}
	}*/
	/*for(int i = 0 ; i < node_name.size() ; ++i){
		cout << node_name[i] << "  diff_degree : " << node_diff_degree[i] << endl;
	}
	for(int i = 0 ; i < node_avail_pos.size() ; i++)
	{
		cout << node_avail_pos[i].first << endl;
	}*/
    return 0;
}