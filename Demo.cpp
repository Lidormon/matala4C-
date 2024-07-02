
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
using namespace std;

int main()
{

    Node<int> root_node(0);
    Tree<int> tree; 
    tree.add_root(root_node);
    Node<int> n1(1);
    Node<int> n2(2);
    Node<int> n3 (3);
    Node<int> n4(4);
    Node<int> n5(5);
    

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n2, n4);
    tree.add_sub_node(n2, n5);
    
cout << "preorder" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;
    cout << "post order" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;
    cout << "inorder" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;
    cout << "bfs" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;
    
    cout << "dfs" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;
    cout << "Same BFS" << endl;
    for (auto node : tree)
    {
        cout << node->get_value() << " ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;
    tree.construct_heap();
    cout << "Heap" << endl;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
    {
        std::cout << (*node)->get_value() << " ";
    }
    std::cout <<std::endl;
 tree.visualize();


    Node<string> root_string("a");
    Tree<string> tree1; 
    tree1.add_root(root_string);
    Node<string> n11("b");
    Node<string> n22("c");
    Node<string> n33 ("d");
    Node<string> n44("e");
    Node<string> n55("f");
    Node<string> n66("g");
    

    tree1.add_sub_node(root_string, n11);
    tree1.add_sub_node(root_string, n22);
    tree1.add_sub_node(n11, n33);
    tree1.add_sub_node(n11, n44);
    tree1.add_sub_node(n22, n55);
    tree1.add_sub_node(n22, n66);
   cout << "pre order" << endl;
    for (auto node = tree1.begin_pre_order(); node != tree1.end_pre_order(); ++node)
    {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;
    cout << "post order" << endl;
    for (auto node = tree1.begin_post_order(); node != tree1.end_post_order(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } 
    cout << endl;
    cout << "inorder" << endl;
    for (auto node = tree1.begin_in_order(); node != tree1.end_in_order(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } 
    cout << endl;
    cout << "bfs" << endl;
    for (auto node = tree1.begin_bfs_scan(); node != tree1.end_bfs_scan(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } 
    cout << endl;
    cout << "dfs" << endl;
    for (auto node = tree1.begin_dfs_scan(); node != tree1.end_dfs_scan(); ++node)
    {
        cout << (*node)->get_value() << " ";
    } 
    cout << endl;
    //cout << "same bfs" << endl;
    for (auto node : tree1)
    {
        cout << node->get_value() << " ";
    } 
    cout << endl;
    
    std::cout <<std::endl;
    //visualize tree
 tree1.visualize();

}
