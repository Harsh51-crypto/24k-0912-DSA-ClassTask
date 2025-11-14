#include<iostream>
using namespace std;

class TreeNode{

    public:
    TreeNode *right;
    TreeNode *left;
    int id;

    TreeNode(int id):id(id){
        left=right=NULL;
    }

    TreeNode *leftrotate(TreeNode *root){
     
        TreeNode *x=root->right;
        TreeNode *temp=x->left;

        x->left=root;
        root->right=temp;

        return x;
    }

    TreeNode *rightrotate(TreeNode *root){
        TreeNode *x=root->left;
       
        TreeNode *temp=x->right;

        x->left=root;
        root->right=temp;

        return x;
    }

    int height(TreeNode*&root){
        if(root==NULL) return 0;

        int left=height(root->left),right=height(root->right),ans=max(left,right)+1;

        return ans;
    }

    int getbalance(TreeNode* root){
        if(root==NULL) return 0;
        return height(root->left)-height(root->right);
    }

    TreeNode* insert(TreeNode*root,int key){
        if(root==NULL){
            root=new TreeNode(key);
            return root;
        }

        if(key<root->id){
            root->left=insert(root->left,key);
        }
     
        else if(key>root->id){
            root->right=insert(root->right,key);
        }
        else{
            return root;
        }

        int balance=getbalance(root);

        
        if(balance>1 && key<root->left->id){
            cout<<"Right Rotation: "<<endl;
            return rightrotate(root);
        }
    
        else if(balance<-1 && key>root->right->id){
               cout<<"Right Rotation: "<<endl;
            return leftrotate(root);
        }
        
        else if(balance<-1 && key<root->right->id){
               cout<<"Right Rotation and Left:  "<<endl;
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
       
        else if(balance>1 && key>root->left->id){
              cout<<"left Rotation and right:  "<<endl;
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }

        return root;
    }

    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        cout<<root->id<<" ";
        inorder(root->right);
    }
};


void inorder(TreeNode *&root){
    if(root==NULL) return;


    cout<<root->id<<" ";

    inorder(root->left);
    inorder(root->right);
}

int main(){
    TreeNode* root=NULL;
    TreeNode tree(0);
    
    
    root=tree.insert(root,10);
    root=tree.insert(root,20);
    root=tree.insert(root,30);
    root=tree.insert(root,40);
    root=tree.insert(root,50);

    inorder(root);
    cout<<endl<<endl;
    cout<<"After inserting 15: "<<endl;

    root=tree.insert(root,15);

    cout<<"height :"<<root->height(root)<<endl;
   
    
    return 0;
}