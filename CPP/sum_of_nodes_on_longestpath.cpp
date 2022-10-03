

/*

Given a binary tree of size n. Your task is to find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.



Sol:
The longest path from root to leaf is always the height of binary tree.

Every node will return a pair of <height, max sum along longest path ie height sum>



*/




// vector stores the height at 0th index and sum at 1st index.
vector<int> sumOfLongRootToLeafPath_helper(Node* root){

    if(root == NULL){
        return {0,0};
    }

    // get ans from left and right:
    vector<int> l = sumOfLongRootToLeafPath_helper(root->left);
    vector<int> r = sumOfLongRootToLeafPath_helper(root->right);

    if(l[0]>r[0]){
        return {l[0]+1, l[1] + root->data};
    }
    else if(l[0]<r[0]){
        return {r[0]+1, r[1] + root->data};
    }
    else{
        // both left and right height is same. So use the path which has larger height sum:
        return {l[0]+1, max(l[1], r[1]) + root->data};
    }



}






int sumOfLongRootToLeafPath(Node* root){

    vector<int> ans = sumOfLongRootToLeafPath_helper(root);
    return ans[1];

}
