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

	void DeepCrawl();

	void BreadthTraversal();

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
	temp.clear();
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
	Map_trav_node.clear();
	Map_min_val.clear();
	Map_node.clear();
	Map_Num_node.clear();
	travNode.clear();
}

template<class T>
void Graf<T>::DeepCrawl()
{
	string str1;
	string str;
	cout << "Enter the element from which the crawl will begin" << endl;
	getline(cin >> ws, str);
	str1 = str;

	Map_str NumTitl;
	Map_str_int TitlNum;
	Map_bool Passed_elements;

	for (int i = 0; i < Node; i++)
	{
		NumTitl[i] = Title[i];
		TitlNum[Title[i]] = i;
		Passed_elements[Title[i]] = 0;
	}

	V_int Chain;
	V_int Ways;

	bool f = 1, fi = 1;
	int nod = Node;

	int K;
	int k;
	while ((nod > 0) && f)
	{
		for (int i = 0; i < Node; i++)
			if (Matrix[TitlNum[str]][i] != 0)
				Ways.push_back(i);

		K = Ways.size();
		k = 0;
		if (!Passed_elements[str])
		{	
			nod--;
			cout << str << "->";
			Passed_elements[str] = 1;
			while ((K > k) && fi)
			{
				if (!Passed_elements[NumTitl[Ways[k]]])
				{
					fi = 0;
				}
				else
				{
					k++;
				}
			}

			if (!fi)
			{
				Chain.push_back(TitlNum[str]);
				str = NumTitl[Ways[k]];	
			
			}
			else
			{
				str = NumTitl[Chain[Chain.size() - 1]];
				Chain.erase(Chain.end() - 1);
				cout << endl;
			}
		}
		else
		{
			cout << str << "->";
			if (str == str1)
			{
				while ((K > k) && fi)
				{
					if (!Passed_elements[NumTitl[Ways[k]]])
					{
						fi = 0;
					}
					else
						k++;
				}
				if (fi)
				{
					f = 0;
				}
				else
				{
					Chain.push_back(TitlNum[str]);
					str = NumTitl[Ways[k]];
				}
			}
			else
			{
				while ((K > k) && fi)
				{
					if (!Passed_elements[NumTitl[Ways[k]]])
					{
						fi = 0;
					}
					else					
						k++;
				}
				if (!fi)
				{
					Chain.push_back(TitlNum[str]);
					str = NumTitl[Ways[k]];
				}
				else
				{
					str = NumTitl[Chain[Chain.size() - 1]];
					Chain.erase(Chain.end() - 1);
				}
			}
		}
		Ways.clear();
		fi = 1;
	}
	NumTitl.clear();
	TitlNum.clear();
	Passed_elements.clear();
	Chain.clear();
	Ways.clear();
}
template<class T>
void Graf<T>::BreadthTraversal()
{
	string str1;
	string str;
	cout << "Enter the element from which the crawl will begin" << endl;
	getline(cin >> ws, str);
	str1 = str;

	Map_str NumTitl;
	Map_str_int TitlNum;
	Map_bool Passed_elements;

	for (int i = 0; i < Node; i++)
	{
		NumTitl[i] = Title[i];
		TitlNum[Title[i]] = i;
		Passed_elements[Title[i]] = 0;
	}

	V_int Chain;
	V_int Ways;

	bool f = 1, fi = 1;
	int nod = Node;

	int K = 1, Kp = 0;
	int k;

	Chain.push_back(TitlNum[str]);
	Passed_elements[str] = 1;

	while (f)
	{
		if (K == Kp)
		{
			f = 0;
		}
		else
		{
			for (int i = Kp; i < K; i++)
			{
				str = NumTitl[Chain[i]];
				cout << str << "->";
				for (int i = 0; i < Node; i++)
					if (Matrix[TitlNum[str]][i] != 0)
						Ways.push_back(i);

				for (int i = 0; i < Ways.size();i++)
					if (!Passed_elements[NumTitl[Ways[i]]])
					{
						Passed_elements[NumTitl[Ways[i]]] = 1;
						Chain.push_back(Ways[i]);
					}
			}
			Kp = K;
			K = Chain.size();
			Ways.clear();
		}
	}
	f = 1;
	for (int i = 0; i < Node; i++)
	{
		if(!Passed_elements[Title[i]])
			f = Passed_elements[Title[i]];
	}
	if (f)
	{
		cout << "The algorithm bypassed all the elements" << endl;
	}
	else
	{
		cout << "The algorithm did not bypass all the elements" << endl;
	}
	NumTitl.clear();
	TitlNum.clear();
	Passed_elements.clear();
	Chain.clear();
	Ways.clear();
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
	cout << "7) Deep Crawl" << endl;
	cout << "8) Bypass in width" << endl;
	cout << "9) Finish working with the graph" << endl;
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
			system("cls");
			graf.InsertNode();
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			graf.InsertEdge();
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			graf.DelNode();
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			graf.DelEdge();
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			graf.Print();
			break;
		}
		case 6:
		{
			system("cls");
			graf.AlgorithmDijkstra();
			break;
		}
		case 7:
		{
			system("cls");
			graf.DeepCrawl();
			break;
		}
		case 8:
		{
			system("cls");
			graf.BreadthTraversal();
			break;
		}
		case 9:
		{
			system("cls");
			F = 0;
			break;
		}
		default:
			cout << "Select the action number that is in the menu" << endl;
		}
	}
}