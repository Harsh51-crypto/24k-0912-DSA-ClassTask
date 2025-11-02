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
int sum(Node *&root)
{
   if (root == NULL)
   {
      return 0;
   }

   int ans = root->data;

   return ans + sum(root->left) + sum(root->right);
}


bool isFound(Node *&root, int target)
{

   if (root == NULL)
   {
      return false;
   }

   if (sum(root) == target)
      return true;

   return isFound(root->left, target) || isFound(root->right, target);
}



int main(){
	Node *root;
	buildTree(root);
	levelOrder(root);
	
}

