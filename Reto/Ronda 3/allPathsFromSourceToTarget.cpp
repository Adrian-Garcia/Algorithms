/* 
797. All Paths From Source to Target
	Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
	The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
	Input: [[1,2], [3], [3], []] 
	Output: [[0,1,3],[0,2,3]] 
	Explanation: The graph looks like this:
	0--->1
	|    |
	v    v
	2--->3
	There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Note:
	The number of nodes in the graph will be in the range [2, 15].
	You can print different paths in any order, but you should keep the order of nodes inside one path.
*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void path(vector<vector<int>> &graph, vector<vector<int>> &result, vector<int>& nodes, int index){
        
        // Terminamos funcion si ya recorrimos todo el grafo
        if(index == graph.size()-1){
            
            result.push_back(nodes);
            return;
        }

        //Recorremos nodos del grafo
        for(int i=0; i<graph[index].size(); i++){
        
            nodes.push_back(graph[index][i]);
            path(graph, result, nodes, graph[index][i]);
            nodes.pop_back();
        }    
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;		//Resultado
        vector<int> nodes;				//Nodos del grafo
        
        //Indice del nodo
        int index=0;
        
        // Valor inicial no valido
        nodes.push_back(0);
        
        // Recorremos grafo
        path(graph, result, nodes, index);
        
        // Regresamos valor final
        return result;
    }
};