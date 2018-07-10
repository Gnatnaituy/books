#ifndef Array_with_Cursor_H
#define Array_with_Cursor_H
#define SpaceSize=20

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

void InitializeCursorSpace( void );

List MakeEmpty( List L );
int isEmpty( const List L );
int isLast( const Position P, const List L );
Position Find( ElementType X, const List L );
Position FindPrevious( ElementType X, const List L );
Position Header( const List L );
Position First( const List L );
Position Advance( const Position P );
void Delete( ElementType X, List L );
void DeleteList( List L );
void Insert( ElementType X, List L, Position P );
ElementType Retrieve( const Position P );

#endif


//Place in the implementation file
struct Node {
    ElementType Element;
    Position    Next;
};
struct Node CursorSpace[ SpaceSize ];