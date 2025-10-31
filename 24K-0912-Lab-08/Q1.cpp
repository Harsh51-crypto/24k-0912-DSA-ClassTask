#include<iostream>
#include<queue>
using namespace std;

class Node{
	
	public:
	string package;
	Node *left;
	Node *right;
	
	Node(string package):package(package){
		left=right=NULL;
	}
		
};

Node *buildTree(Node *&root){
	
	string data;
	cout<<"Enter the Tour Package: "<<endl;
	cin>>data;
	
	root=new Node(data);
	
	if(data=="stop"){
		return NULL;
	}
	
	cout<<"Enter the Tour Package of left child: "<<root->package<<endl;
	
	
	root->left=buildTree(root->left);
	
	
		
	cout<<"Enter the Tour Package of Right child: "<<endl;

	
	root->right=buildTree(root->right);
	
	return root;
		
}


void levelOrder(Node *&root){
	queue<Node*>level;
	
	level.push(root);

	
	
	while(!level.empty()){
		Node *temp=level.front();
		
		level.pop();
		
	
	    cout<<temp->package<<" ";
			
		if(temp->left) level.push(temp->left);
		if(temp->right) level.push(temp->right);
			
	
	}
	
}
int main(){
	Node *root;
	buildTree(root);
	levelOrder(root);
	
}
