#include<stdlib.h>
#include<stdio.h>
#include <string.h>
		int counter = 0 ;
		struct bin_tree {
		int data ;
		struct bin_tree * right, * left;
		};
		typedef struct bin_tree node;
		
		void insert(node ** tree, int val)
		{ //inserting the given values to the tree
		    node *temp = NULL;
		    if(!(*tree))
		    {
		        temp = (node *)malloc(sizeof(node));
		        temp->left = temp->right = NULL;
		        temp->data = val;
		        *tree = temp;
		        return;
		    }
		
		    if(val < (*tree)->data)
		    {
		        insert(&(*tree)->left, val);
		    }
		    else if(val > (*tree)->data)
		    {
		        insert(&(*tree)->right, val);
		    }
		
		}
		
		void swap(int a, int b , int c , int d , int arr[1000]) 
		{ // swapping the needed values
		    arr[c] =  b ;
		    arr[d] = a ;
		    
		    
		}
		void generatorFunc(int arr[1000], int l, int r , int rootArr[1000] ) 
		{ //this function compares given 2 sequences depending on their left and right subtrees 
		   int i , k ;
		   if (l == r) {
		   		if(isSameBST(arr, rootArr, r)) { // function call for comparison session
		   		counter++;
				   	printf("{") ;
					for(k = 0 ; k < r; k++) {
		   				printf("%d" , arr[k]) ;
		   					if(k != r-1) {
		   						printf(",") ;
							}
							else if (k == r-1) {
								printf("}.") ;
							}
					}	
		   		}
			}
	
		   else
		   {
		       for (i = l; i <= r; i++)
		       {
				  swap(arr[l], arr[i] , l , i , arr) ;
		          generatorFunc(arr, l+1, r , rootArr); 
		          swap(arr[l], arr[i] , l , i , arr);
		       }
		   }
		}
		
		// Recursive function to check if X[0..n) and Y[0..n)
	// represent same BSTs or not
	int isSameBST(int X[], int Y[], int n)
	{
	// if no element is present in the array, return true
	if (n == 0)
		return 1;

	// if 1st element differs in both array (root node key),
	// return false
	if (X[0] != Y[0])
		return 0;

	// if array contains only one key, return true
	if (n == 1)
		return 1;

	// take four auxiliary arrays of size n-1 each (as maximum
	// keys in left or right subtree can be n-1)
	int leftX[n-1], rightX[n-1], leftY[n-1], rightY[n-1];

	int k = 0, l = 0, m = 0, o = 0 , i;

	// process remaining keys and divide them into two groups
	for ( i = 1; i < n; i++)
	{
		// leftX[] will contain all elements less than X[0]
		if (X[i] < X[0])
			leftX[k++] = X[i];

		// rightX[] will contain all elements more than X[0]
		else
			rightX[l++] = X[i];

		// leftY[] will contain all elements less than Y[0]
		if (Y[i] < Y[0])
			leftY[m++] = Y[i];

		// rightY[] will contain all elements more than Y[0]
		else
			rightY[o++] = Y[i];
	}

	// return false if size of leftX[] & leftY[] differs i.e.
	// number of nodes in left subtree of both trees differs
	if (k != m)
		return 0;

	// return false if size of rightX[] & rightY[] differs i.e.
	// number of nodes in right subtree of both trees differs
	if (l != o)
		return 0;

	// check left subtree and right subtree
	return isSameBST(leftX, leftY, k) &&
			isSameBST(rightX, rightY, l);
}

		void print_preorder(node * tree)
		{
		    if (tree)
		    {
		        printf("%d\t",tree->data);
		        print_preorder(tree->left);
		        print_preorder(tree->right);
		    }
		
		}
		
		void print_inorder(node * tree)
		{
		    if (tree)
		    {
		        print_inorder(tree->left);
		        
		        printf("%d\t",tree->data);
		        print_inorder(tree->right);
		    }
		}
		
		void print_postorder(node * tree)
		{
		    if (tree)
		    {
		        print_postorder(tree->left);
		        print_postorder(tree->right);
		        printf("%d\t",tree->data);
		    }
		}
			
		void main()
		{
		    node *root;
		    node *tmp;
		    root = NULL;
		    int arr[1000] ;
			int rootArr[1000] ;
			
			int j = 0 ; // value of nodes in the tree that is entered from user
		    char* str  = (char*) malloc(500*sizeof(char));
			char element[1000] ;
			printf("Enter sequence of numbers: ") ;
		    scanf("%[^\n]" , str) ;
			char* ptr = strtok(str , " ");
			int  x ;
			while(ptr != NULL) { // tokenize the current line
			rootArr[j] = atoi(ptr) ; 
			arr[j] = atoi(ptr);  
			j++ ;
			ptr = strtok(NULL , " ") ;
			}
			for(x = 0 ; x < j ; x++) {			
			insert(&root, arr[x]);		
			}
			printf("BST that user enters: ") ;
			printf("\nPre Order Display\n");
		    print_preorder(root);
		    
		
		    printf("\nIn Order Display\n");
		    print_inorder(root);
		
		    printf("\nPost Order Display\n");
		    print_postorder(root);
		    
		    printf("\nThe sequances are: \n") ;  
		    generatorFunc(arr, 0, j , rootArr);
		    printf("\nThe total number of sequences is %d." , counter) ;
		    
		}
