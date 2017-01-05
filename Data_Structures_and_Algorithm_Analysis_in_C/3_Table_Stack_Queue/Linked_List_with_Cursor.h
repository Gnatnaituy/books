#ifndef _Linked_List_Cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

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

#endif  /* _Linked_List_Cursor_H */
