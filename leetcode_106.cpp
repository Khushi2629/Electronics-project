Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.




  class Solution {
public:

     int findposition(vector<int> &inorder,int element)
     
     
     {
        for(int i=0;i<inorder.size();i++)
            if(inorder[i]==element)
               return i;      
        
        return -1;

     }
     TreeNode* buildTreeUtil(vector<int> &postorder,vector<int> &inorder,int &index,int start,int end)
     {
        if(index<0 or start>end)
        return nullptr;
        int element= postorder[index--];
        TreeNode *root = new TreeNode(element);
        int position = findposition(inorder,element);
        // right call
        root->right = buildTreeUtil(postorder,inorder,index,position+1,end);
        // left call
        root->left = buildTreeUtil(postorder,inorder,index,start,position-1);
        return root;


     }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int postorderindex=n-1;
        return buildTreeUtil(postorder,inorder,postorderindex,0,n-1);

        
    }
};
