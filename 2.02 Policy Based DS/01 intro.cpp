//header  files

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//including tree_order_statistics_node_update

using namespace __gnu_pbds;

//declaration of tree-based container
template <
    //key type,
    typename key,

    //Mapped-policy
    typename Mapped,

    //key comparison function
    typename Cmp_Fn = std ::less<key>,

    //specifies which underlying datastructure to use
    typename Tag = rb_tree_tag,

    template <
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_	>

    // apolicy for updating node invariants
    class Node_Update = null_node_update,

    //an allocator type
    typename Allocator = std :: allocator<char> >

class tree;


typedef tree<int, null_type, less<int> , rb_tree_tag,
        tree_order_statistics_node_update >
        new_data_set;


Tree Structures
rb_tree_tag			(red - black trees)
splay_tree_tag		(splay tree)
ov_tree_tag         (ordered - vector tree)
















Final declaration that we will use

typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;



https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures.html


setting in ubuntu


setting it in windows

\MinGW\lib\gcc\mingw32\6.3.0\include\c++\ext\pb_ds\detail\hash_standard_resize_policy_imp.hpp (correct )

hash_standard_resize_policy_imp.hpp0000644 (wrongly named)