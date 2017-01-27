#include <stdlib.h>
#include <stdio.h>

typedef int EleType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position FindMin( SearchTree T );
Position FinsMax( SearchTree T );
SearchTree Insert( EleType X, SearchTree T );
SearchTree Delete( EleType X, SearchTree T );


struct TreeNode
{
    EleType      Data;
    SearchTree   Left;
    SearchTree   Right;
};


SearchTree MakeEmpty( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}

Position Find( EleType X, SearchTree T )
{
    if( T == NULL )
        return NULL;
    if( X < T->Data )
        return Find( X, T->Left );
    else if( X > T->Data )
        return Find( X, T->Right );
    else
        return T;
}

Position FindMin( SearchTree T )
{
    if( T == NULL )
        return NULL;
    else if( T->Left == NULL )
        return T;
    else
        return FindMin( T->Left );
}

Position FindMax( SearchTree T )
{
    if( T != NULL )
        while( T->Right != NULL )
            T = T->Right;

    return T;
}

SearchTree Insert( EleType X, SearchTree T )
{
    if( T == NULL )
    {
        /* Create and return a one-node tree */
        T = malloc( sizeof( struct TreeNode ) );
        if( T == NULL )
        {
            printf("Failed to malloc !!!\n!");
            exit(EXIT_FAILURE);
        }
        else
        {
            T->Data = X;
            T->Left = T->Right = NULL;
        }
    }
    else if( X < T->Data )
        T->Left = Insert( X, T->Left );
    else if( X > T->Data )
        T->Right = Insert( X, T->Right );
    /* else X is in the tree already, we'll do nothing */

    return T;
}

SearchTree Delete( EleType X, SearchTree T )
{
    Position TmpCell;

    if( T == NULL )
    {
        printf("Not have a SearchTree !!! ");
        exit(EXIT_FAILURE);
    }
    else if( X < T->Data )  // Go Left
        T->Left = Delete( X, T->Left );
    else if( X > T->Data ) // Go Right 
        T->Right = Delete( X, T->Right );
    else if( T->Left && T->Right )  // Two Children
    {
        // Replace with smallest in right subtree
        TmpCell =  FindMin( T->Right );
        T->Data = TmpCell->Data;
        T->Right = Delete( T->Data, T->Right );
    }
    else
    {
        TmpCell = T;
        if( T->Left == NULL )  // Also handles 0 children
            T = T->Right;
        else if( T->Right == NULL )
            T = T->Left;
        free( TmpCell );
    }

    return T;
}

int PrintTree( SearchTree T )
{
    if( T == NULL )
    {
        printf("Empty SearchTree !!!\n!");
    }
    else
    {
        printf( "%d", T->Data );
        if( T->Left != NULL )
            PrintTree( T->Left );
        if( T->Right != NULL )
            PrintTree( T->Right );
    }

    return 0;
}

int main()
{
    SearchTree T;
    PrintTree( MakeEmpty( T ) );

    return 0;
}
