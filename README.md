我所實做出來用於尋找chinese postman的主要流程分為四個步驟 : 

一.先求出每個node的degree差異 degree_diff = (out_degree - in_degree),
如果每個node的degree_diff都為0則原圖即為尤拉圖,
則直接跳去第四步驟,如果存在不為0的點,則往第二步驟.

二.判斷出degree_diff不為0的node以後,
透過match的方式,將positive degree_diff node及negative degree_diff node
進行match並且會將所有配對的方式都試過一次,
而找到一個graph中任兩點最短cost路徑的方法為透過實作BFS來找到兩點間所有的paht,
並且將每個path所需的cost都算出來,最後選出最小cost那條path,
在每一次的配對中會找尋最小的路徑和,
直到找到所有配對中最小cost的配對方法.
Ex : 
node a's and b's degree_diff = -1 , node c's and d's degree_diff = 1,
則配對兩次 1.(a->c b->d) 2.(a->d b->c)如果第一種配對方式a到c以及b到d的最小路徑和比第二種小,
則選擇第一種配對,紀錄這個最小路徑和的weight後進入到第三步驟.

三.這個步驟會將剛剛決定的配對進行add edge的動作,以剛剛第二步驟的舉例來說,
假設a->c的最短路徑為a->e->d->c,而b->d的最短路徑為b->e->c->d
那在這個步驟則會加上1.a->e 2.e->d 3.d->c 4.b->e 5.e->c 6.c->d這六個edge,並且進入第四步驟.

四. 在加完edge以後這張圖形成一個尤拉圖,即可以求尤拉路徑,我所使用的演算法為Hierholzer’s Algorithm,
透過實作這個演算法即可求得尤拉路徑,而minimun cost的求法,
是將加完edge後的圖每一個edge's weight做相加再加上剛剛第二步驟紀錄的weight即為答案,
會這樣分開加的原因是我的實作在加edge時沒有設定它的weight所以加上的edge's weight都會是0,
最後透過std::cout將結果印在螢幕上.


程式碼解釋: 

void fetch_node_name() : 
這個function會將建立好的graph裡面node的名字存放在我的global variable: node_name.

void Cal_Degree(vector<int>& node_in_degree , vector<int>& node_out_degree,vector<vector<int>>& adj_list) : 
這個function會計算出第一步驟out_degree.in_degree 和 degree_diff.

void Construct_adj_list(vector<vector<int>>& adj_list) : 
建立adjacency list的function.

void Construct_adj_matrix(vector<vector<int>>& graph) :
建立adjacency matrix的function.

void findpaths(vector<vector<int> >&g, int src, int dst, int v,vector<vector<int>>&graph) :
實作BFS來尋找兩點間的所有PATH.

void printCircuit(vector< vector<int> > adj) :
透過Hierholzer’s Algorithm來尋找一張尤拉圖的尤拉路徑並且印在螢幕上.

void AddEdgeToGraph(vector<vector<int>> adj_list , vector<vector<int>> graph) :
在這個function中會尋找所有的matching並且在找到最小路徑和後加上edge至graph中,
我所尋找所有match的方式是透過random的方式任選一個positive degree_diff node以及
一個negative degree_diff node來進行配對直到我所給定loop的次數即停止.
