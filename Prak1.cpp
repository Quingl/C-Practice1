// Prak1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Построить все максимальные по числу элементов компоненты связности
//неориентированного графа через алгоритм поиска в глубину.
/*5: 0 1 2 3 4 5
0->1,2
g[0] = 1,2;
g[0][0]
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m, v, u;
vector<int> g[100];
vector<int> gsv[100];
vector<int> gcount;
bool used[100];
vector<int> comp;
// поиск в глубину
void dfs(int v) {
	used[v] = true;
	comp.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

void find_comps() {
	int k = 0;
	int maxsize = 0;
	for (int i = 0; i < n; ++i)
		used[i] = false;
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			comp.clear();
			dfs(i);

			cout << "Компонента связанности: ";
			for (size_t j = 0; j < comp.size(); ++j)
				cout << ' ' << comp[j];
			cout << endl;

			for (int j = 0; j < comp.size(); j++)
				gsv[k].push_back(comp[j]);
			if (maxsize < comp.size())
				maxsize = comp.size();
			k++;
		}
	cout << "Все максимальные по числу элементов компоненты связности" << endl;
	for (int i = 0; i < k; i++)
	{
		if (gsv[i].size() == maxsize)
		{
			cout << "Компонента связанности: ";
			for (int j = 0; j < gsv[i].size(); j++)
			{				
				cout << gsv[i][j] << ' ' ;
			}
			cout << endl;
		}
	}
	
	}

//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Кол. вершин >> "; cin >> n;
	cout << "Кол. ребер >> "; cin >> m; // 
	for (int i = 0; i < n; i++)
	{
		gcount.push_back(0);
	}

	cout << "Вводите смежные вершины:" << endl;
    for (int i = 0; i < m; i++)
	{
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
		cout << "..." << endl;
	}
	//вывод списка смежности
	cout << "Список смежности графа:"<< endl;
	for (int i = 0; i < n; i++)
	{
		cout << i << "->";
		for (int j = 0;j<g[i].size();j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	find_comps();




	system("pause>>void");
}