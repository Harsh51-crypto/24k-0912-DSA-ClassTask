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
void countleaf(Node *&root,int &count){
	
	if(root==NULL) return ;
	
	if(root->left==NULL && root->right==NULL){
		++count;
}

	countleaf(root->left,count);
	countleaf(root->right,count);
	
}

void totalNode(Node*&root,int &count){
	
	if(root==NULL){
		return;
	}
	
	++count;
	totalNode(root->left,count);
	totalNode(root->right,count);
}

int height(Node *&root){
	
	if(root==NULL){
		return 0;
	}
	
	
	int left=height(root->left);
	int right=height(root->right);
	int ans=max(left,right)+1;
	return ans;
	
	
}

int main(){
	Node *root;
	buildTree(root);
	
	int count=0,node=0;
	countleaf(root,count);
	totalNode(root,node);
	cout<<endl<<"Total Node: "<<node<<endl;
	cout<<endl<<"Total Leaf: "<<count<<endl;
	cout<<"Total Height: "<<height(root)<<endl;
	
	
	
}
