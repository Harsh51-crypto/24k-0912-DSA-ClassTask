#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Node{
	
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int data):data(data){
		left=right=NULL;
	}
		
};

Node *buildTree(Node *&root){
	
	int data;
	cout<<"Enter the data: "<<endl;
	cin>>data;
	
	root=new Node(data);
	
	if(data==-1){
		return NULL;
	}
	
	cout<<"Enter the data of left: "<<root->data<<endl;
	
	
	root->left=buildTree(root->left);
	
	
		
	cout<<"Enter the data of Right: "<<root->data<<endl;

	
	root->right=buildTree(root->right);
	
	return root;
		
}
void levelOrder(Node *&root){
	queue<Node*>level;
	
	level.push(root);

	
	
	while(!level.empty()){
		Node *temp=level.front();
		
		level.pop();
		
	
	    cout<<temp->data<<" ";
			
		if(temp->left) level.push(temp->left);
		if(temp->right) level.push(temp->right);
			
	
	}
	
}

bool isEqual(Node *&root,int target, int &sum){
	
	if(root==NULL){
		return false;
	}
	
	sum+=root->data;
	if(sum==root->data){
		return true;
	}
	
	
	
	
}

int main(){
	Node *root;
	buildTree(root);
	levelOrder(root);
	
}
