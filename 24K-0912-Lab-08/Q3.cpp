#include<iostream>
#include<queue>
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
	
	int  data;
	cout<<"Enter the data: "<<endl;
	cin>>data;
	
	root=new Node(data);
	
	if(data==-1){
		return NULL;
	}
	
	cout<<"Enter the data of left child: "<<root->data<<endl;
	
	
	root->left=buildTree(root->left);
	
	
		
	cout<<"Enter the data of Right child: "<<root->data<<endl;

	
	root->right=buildTree(root->right);
	
	return root;
		
}

bool isFullbinary(Node *&root){
	if(root==NULL){
		return true;
	}
	
	if(root->left && root->right==NULL){
		return false;
	}
	
	if(root->left==NULL && root->right){
		return false;
	}
	
	if(isFullbinary(root->left));
	isFullbinary(root->right);
}

int main(){
	Node *root;
	buildTree(root);
	
	if(isFullbinary(root)){
		cout<<"Full Binary Tree: "<<endl;
	}
	else{
		cout<<"Not Full Binary Tree: "<<endl;
	}
	
	
	
	
	
}
