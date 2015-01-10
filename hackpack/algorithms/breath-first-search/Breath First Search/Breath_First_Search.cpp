//BFS.cpp
//http://www.youtube.com/watch?v=s-CYnVz-uh4

#include <cstdlib> 
#include <iostream>

using namespace std;
 
struct node {
    int info;
    node *next;
};
 
class Queue {
    private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        void display();
 
};
 
      void Queue::display(){
          node *p = new node;
          p = front;
          if(front == NULL){
              cout<<"\nNothing to Display\n";
          }else{
              while(p!=NULL){
                  cout<<endl<<p->info;
                  p = p->next;
              }
          }
      }
       
      Queue::Queue() {
          front = NULL;
          rear = NULL;
      }
       
      Queue::~Queue() {
          delete front;
      }
       
      void Queue::enqueue(int data) {
          node *temp = new node();
          temp->info = data;
          temp->next = NULL;
          if(front == NULL){
              front = temp;
          }else{
              rear->next = temp;
          }
          rear = temp;
      }
       
      int Queue::dequeue() {
          node *temp = new node();
          int value;
          if(front == NULL){
              cout<<"\nQueue is Emtpty\n";
          }else{
              temp = front;
              value = temp->info;
              front = front->next;
              delete temp;
          }
          return value;
      }
       
      bool Queue::isEmpty() {
          return (front == NULL);
      }
  
class Graph {
    private:
        int n; /// n is the number of vertices in the graph
        int **A; /// A stores the edges between two vertices
    public:
        Graph(int size = 2);
        ~Graph();
        bool isConnected(int, int);
        void addEdge(int u, int v);
        void BFS(int );
};
 
         Graph::Graph(int size) {
             int i, j;
             if (size < 2) n = 2;
             else n = size;
             A = new int*[n];
             for (i = 0; i < n; ++i)
                 A[i] = new int[n];
             for (i = 0; i < n; ++i)
                 for (j = 0; j < n; ++j)
                     A[i][j] = 0;
         }
          
         Graph::~Graph() {
             for (int i = 0; i < n; ++i)
             delete [] A[i];
             delete [] A;
         }

         bool Graph::isConnected(int u, int v) {
             return (A[u-1][v-1] == 1);
         }

         void Graph::addEdge(int u, int v) {
             A[u-1][v-1] = A[v-1][u-1] = 1;
         }

         void Graph::BFS(int c) {
             Queue Q;
          
             /** Keeps track of explored vertices */
             bool *explored = new bool[n+1];
          
             /** Initailized all vertices as unexplored */
             for (int i = 1; i <= n; ++i)
             explored[i] = false;
          
             /** Push initial vertex to the queue */
             Q.enqueue(c);
             explored[c] = true; /** mark it as explored */
             cout << "BFS starting from vertex ";
             cout << c << " : " << endl;
          
             /** Unless the queue is empty */
             while (!Q.isEmpty()) {
                 /** Pop the vertex from the queue */
                 int v = Q.dequeue();
          
                 /** display the explored vertices */
                 cout << v << " ";
          
                 /** From the explored vertex v try to explore all the
                 connected vertices */
                 for (int w = 1; w <= n; ++w)
          
                     /** Explores the vertex w if it is connected to v
                     and and if it is unexplored */
                     if (isConnected(v, w) && !explored[w]) {
                         /** adds the vertex w to the queue */
                         Q.enqueue(w);
                         /** marks the vertex w as visited */
                         explored[w] = true;
                     }
             }
             cout << endl;
             delete [] explored;
         }
 
int main() {
 
    int x,y,a,b,c; // varible for number of verticies on the graph or max x axis value
    cout << "Please enter number of graph vertacies" << "\n";
    cin >> x ; 
    Graph g(x);
     
    cout << "Please enter the total number of edges" << "\n";
    cin  >> y;
    
    for(int i=0; i<y; i++){
      cout << "Please enter edge "<< i << " x and y values" << "\n";
      cout << "x="; cin  >> a;
      cout << "y="; cin  >>  b;
      g.addEdge(x,y); 
    }
    cout << "Please enter starting vertex:";
    cin  >> c;
    g.BFS(c);
}
