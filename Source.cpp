#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

typedef vector<vector<int>> V_V_int;
typedef vector<int> V_int;
typedef vector<string> V_str;

typedef map<string, int> Map_int;
typedef map<string, bool> Map_bool;
typedef map<int, string> Map_str;
typedef map<string, int> Map_str_int;

V_str::iterator It_str;

template<class T>
class Graf
{
public:
	Graf();

	void InsertNode();
	void InsertEdge();

	void Print();

	void DelNode();
	void DelEdge();

	int ChekNode(string str);

	V_V_int CreateMatrix();

	void AlgorithmDijkstra();
	int MinAlgortmD(Map_bool, Map_int, Map_str, int);
	~Graf();
private:
	V_V_int Matrix;
	V_str Title;
	int Node;
	int Edge;
};

template<class T>
Graf<T>::Graf()
{
	Node = 0;
	Edge = 0;
}
template<class T>
Graf<T>::~Graf()
{
	Title.clear();
	Matrix.clear();
}

template<class T>
V_V_int Graf<T>:: CreateMatrix()
{
	for(int i = 0; i < this->Node; i++)
	 this->Vec.push_back(V_int);
	for (int i = 0; i < this->Node; i++)
		for (int j = 0; j < this->Node; j++)
			this->Vec[i].push_back(0);
	return* this;
}
template<class T>
void Graf<T>::Print()
{
	cout << '\t';
	for (int i = 0; i < this->Node;i++)
		cout << this->Title[i] << '\t';
	cout << endl;
	cout << "-----------------------------------------------" << endl;
	for (int i = 0; i < this->Node; i++)
	{
		cout << Title[i] << "\t|";
		for (int j = 0;j < this->Node; j++)
			cout << this->Matrix[i][j] << '\t';
		cout << endl;
	}
}

template<class T>
int Graf<T>::ChekNode(string str)
{
	bool f = 1;
	int n = 0;
	while ((n < Node) && f)
		if (Title[n] == str)
			f = 0;
		else
			n++;
	if (f)
		return -1;
	else
		return n;
}

template<class T>
void Graf<T>::InsertNode()
{
	string str;
	cout << "Enter the name of the node" << endl;
	getline(cin >> ws, str);
	Title.push_back(str);
	Node++;
	V_int NewV;
	Matrix.push_back(NewV);
	for (int i = 0; i < Node - 1; i++)
		Matrix[i].push_back(0);
	for (int i = 0; i < Node; i++)
		Matrix[Node - 1].push_back(0);
}
template<class T>
void Graf<T>::InsertEdge()
{
	string str;
	int n, i, j;
	bool f;
	cout << "The edge being created has a direction:" << endl;
	cout << "1) Yes" << endl;
	cout << "2) No" << endl;
	cout << "Enter the selected refinement" << endl;
	cin >> n;
	if (n == 1)
		f = 1;
	else
		f = 0;
	if (f)
	{
		cout << "Enter the name of the node from which the edge comes" << endl;
		getline(cin >> ws, str);

		n = ChekNode(str);
		if (n < 0)
		{
			cout << "There is no node with this name" << endl;
		}
		else
		{
			i = n;
			cout << "Enter the name of the node to which the edge goes" << endl;
			getline(cin >> ws, str);

			n = ChekNode(str);
			if (n < 0)
			{
				cout << "There is no node with this name" << endl;
			}
			else
			{
				j = n;
				if (Matrix[i][j] == 0)
				{
					cout << "Enter the edge weight" << endl;
					cin >> n;
					Matrix[i][j] = n;
				}
				else
				{
					cout << "There is an edge between the selected nodes." << endl;
					cout << "Replace the existing edge with a new one?" << endl;
					cout << "1) Yes" << endl;
					cout << "2) No" << endl;
					cout << "Enter the selected refinement" << endl;
					cin >> n;
					if (n == 1)
						f = 1;
					if (f)
					{
						cout << "Enter the edge weight" << endl;
						cin >> n;
						Matrix[i][j] = n;
						Matrix[j][i] = 0;
					}
				}
			}
		}
	}
	else
	{
		cout << "Enter the name of the first node" << endl;
		getline(cin >> ws, str);

		n = ChekNode(str);
		if (n < 0)
		{
			cout << "There is no node with this name" << endl;
		}
		else
		{
			i = n;
			cout << "Enter the name of the second node" << endl;
			getline(cin >> ws, str);

			n = ChekNode(str);
			if (n < 0)
			{
				cout << "There is no node with this name" << endl;
			}
			else
			{
				j = n;
				if (Matrix[i][j] == 0)
				{
					cout << "Enter the edge weight" << endl;
					cin >> n;
					Matrix[i][j] = n;
					Matrix[j][i] = n;
				}
				else
				{
					cout << "There is an edge between the selected nodes." << endl;
					cout << "Replace the existing edge with a new one?" << endl;
					cout << "1) Yes" << endl;
					cout << "2) No" << endl;
					cout << "Enter the selected refinement" << endl;
					cin >> n;
					if (n == 1)
						f = 1;
					if (f)
					{
						cout << "Enter the edge weight" << endl;
						cin >> n;
						Matrix[i][j] = n;
						Matrix[j][i] = n;
					}
				}
			}
		}
	}
}

template<class T>
void Graf<T>::DelNode()
{
	bool Fstr = 1;
	string str;
	int n;
	cout << "Enter the name of the node being deleted" << endl;
	getline(cin >> ws, str);

	n = ChekNode(str);
	if (n < 0)
	{
		cout << "There is no node with this name" << endl;
	}
	else
	{
		V_V_int temp;
		V_str tempTit;
		for (int i = 0; i < Node; i++)
		{
			if (i != n)
			{
				str = Title[i];
				tempTit.push_back(str);
			}
		}
		Title.clear();
		Title = tempTit;
		
		for (int i = 0; i < Node - 1; i++)
		{
			V_int V;
			temp.push_back(V);
		}

		for (int i = 0; i < Node; i++)
		{
			Matrix[n][i] = -1;
			Matrix[i][n] = -1;
		}

		for (int i = 0; i < Node; i++)
		{
			if (Matrix[i][0] > -1)
			{
				for (int j = 0; j < Node; j++)
					if (Matrix[i][j] > -1)
						if (Fstr)
							temp[i].push_back(Matrix[i][j]);
						else
							temp[i - 1].push_back(Matrix[i][j]);
			}
			else
				Fstr = 0;

		}
		Matrix.clear();
	    Matrix = temp;
		Node--;
	}

}
template<class T>
void Graf<T>::DelEdge()
{
	string str;
	int n, i, j;
	cout << "Enter the name of the nodes between which you want to remove the edge" << endl;
	cout << "Enter the name of the first node" << endl;
	getline(cin >> ws, str);
	n = ChekNode(str);
	if (n < 0)
	{
		cout << "There is no node with this name" << endl;
	}
	else
	{
		i = n;
		cout << "Enter the name of the second node" << endl;
		getline(cin >> ws, str);
		n = ChekNode(str);
		if (n < 0)
		{
			cout << "There is no node with this name" << endl;
		}
		else
		{
			j = n;
			Matrix[i][j] = 0;
			Matrix[j][i] = 0;
			cout << "Edge removed" << endl;
		}
	}
}

template<class T>
int Graf<T>::MinAlgortmD(Map_bool mb, Map_int mi, Map_str ms, int n)
{
	int K;
	V_str temp;
	string Min;
	for (int i = 0; i < Node; i++)
		if (Matrix[n][i] != 0)
			temp.push_back(ms[i]);

	K = temp.size();

	int mn = 100000;

	for (int i = 0; i < K; i++)
	{
		if (!mb[temp[i]])
		{
			if (mn > mi[temp[i]])
			{
				mn = mi[temp[i]];
				Min = temp[i];
			}
		}
	}

	if (mn != 100000)
		return ChekNode(Min);
	else
		return -1;
}
template<class T>
void Graf<T>::AlgorithmDijkstra()
{
	string str1;
	string str;
	cout << "Enter the number of the element for which you want to run Dijkstra's algorithm" << endl;
	getline(cin >> ws, str);
	str1 = str;
	int n = ChekNode(str);

	int k = 0;
	Map_bool Map_trav_node;
	Map_int Map_min_val;
	Map_str Map_node;
	Map_str_int Map_Num_node;
	for (int i = 0; i < Node; i++)
	{
		Map_min_val[Title[i]] = 100000;
		Map_trav_node[Title[i]] = 0;
		Map_node[i] = Title[i];
		Map_Num_node[Title[i]] = i;
	}

	Map_min_val[str] = 0;

	int K;
	bool f = 1, F;
	int nod = Node;
	V_int travNode;

	while ((nod > 0) && f)
	{
		V_str NodeT;
		for (int i = 0; i < Node; i++)
		{
			if (Matrix[n][i] != 0)
				NodeT.push_back(Map_node[i]);
		}
		K = NodeT.size();
		for (int i = 0; i < K; i++)
		{
			if (Map_min_val[NodeT[i]] > Map_min_val[str] + Matrix[Map_Num_node[str]][Map_Num_node[NodeT[i]]])
			{
				Map_min_val[NodeT[i]] = Map_min_val[str] + Matrix[Map_Num_node[str]][Map_Num_node[NodeT[i]]];
			};
		}


		K = MinAlgortmD(Map_trav_node, Map_min_val, Map_node, n);
		if (K < 0)
		{
			Map_trav_node[str] = 1;
			if (travNode[travNode.size() - 1] != Map_Num_node[str1])
			{
				n = travNode[travNode.size() - 1];
				str = Title[n];
				travNode.erase(travNode.end() - 1);
				for (int i = 0; i < Node; i++)
					F = Map_trav_node[Title[i]];
				if (F)
					nod--;
				else
					nod++;
			}
			else
			{
				f = 0;
			}
		}
		else
		{
				travNode.push_back(Map_Num_node[str]);
				Map_trav_node[str] = 1;
				n = K;
				str = Title[n];
		}
		NodeT.clear();
	}
	if (f)
		for (int i = 0; i < Node; i++)
		{
			cout << "The shortest distance from element " << str1 << " to element " << Title[i] << " is " << Map_min_val[Title[i]] << endl;
		}
	else
	{
		for (int i = 0; i < Node; i++)
		{
			if(Map_min_val[Title[i]] != 100000)
			cout << "The shortest distance from element " << str1 << " to element " << Title[i] << " is " << Map_min_val[Title[i]] << endl;
		}
		cout << "The minimum distance to the elements that the algorithm could calculate" << endl;
	} 
}

void Menu()
{
	cout << "\tMenu" << endl;
	cout << "1) Adding a node" << endl;
	cout << "2) Adding an edge" << endl;
	cout << "3) Deleting a node" << endl;
	cout << "4) Removing an edge" << endl;
	cout << "5) Entering the adjacency matrix" << endl;
	cout << "6) Dijkstra 's algorithm" << endl;
	cout << "7) Finish working with the graph" << endl;
}

int main()
{
	Graf<int> graf;

	bool F = 1;
	int n;

	while (F)
	{
		Menu();
		cout << "Select the action number:" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			graf.InsertNode();
			break;
		}
		case 2:
		{
			graf.InsertEdge();
			break;
		}
		case 3:
		{
			graf.DelNode();
			break;
		}
		case 4:
		{
			graf.DelEdge();
			break;
		}
		case 5:
		{
			graf.Print();
			break;
		}
		case 6:
		{
			graf.AlgorithmDijkstra();
			break;
		}
		case 7:
		{
			F = 0;
			break;
		}
		default:
			cout << "Select the action number that is in the menu" << endl;
		}
	}
}