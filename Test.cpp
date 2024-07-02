#include "Tree.hpp"
#include "Node.hpp"
#include "doctest.h"
#include "Complex.hpp"
#include <string>
using namespace std;



TEST_CASE("Tree with integer")
{ 
        Node<int> n1(1); 
        Tree<int> tree_with_int;          
        tree_with_int.add_root(n1);
        Node<int> n2(2);
        Node<int> n3(3);
        Node<int> n4(4);
        Node<int> n5(5);
        Node<int> n6(6);
        tree_with_int.add_sub_node(n1, n2);
        tree_with_int.add_sub_node(n1, n3);
        tree_with_int.add_sub_node(n2, n4);
        tree_with_int.add_sub_node(n2, n5);
        tree_with_int.add_sub_node(n3, n6);
        CHECK(tree_with_int.get_root()->get_childrens().at(0)->get_value() == n2.get_value());
        CHECK(n2.get_childrens().at(0)->get_value() == n4.get_value());

        
        SUBCASE("In_order Iterator")
        {
            std::vector<double> compared = {4, 2, 5, 1, 6, 3};
            auto it = compared.begin();
            for (auto node = tree_with_int.begin_in_order(); node != tree_with_int.end_in_order(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }


        SUBCASE("Pre_order Iterator")
        {
            std::vector<double> compared = {1, 2,4, 5, 3, 6};
            auto it = compared.begin();
            for (auto node = tree_with_int.begin_pre_order(); node != tree_with_int.end_pre_order(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("Post_order Iterator")
        {
            std::vector<double> compared = {4, 5, 2, 6, 3, 1};
            auto it = compared.begin();
            for (auto node = tree_with_int.begin_post_order(); node != tree_with_int.end_post_order(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }



        SUBCASE("BFS Iterator")
        {
            std::vector<double> compared = {1, 2, 3, 4, 5,6};
            auto it = compared.begin();
            for (auto node = tree_with_int.begin_bfs_scan(); node != tree_with_int.end_bfs_scan(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("DFS Iterator")
        {
            std::vector<double> compared = {1, 2, 4,5, 3, 6};
            auto it = compared.begin();
            for (auto node = tree_with_int.begin_dfs_scan(); node != tree_with_int.end_dfs_scan(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("Heap Iterator")
        {
            
            tree_with_int.construct_heap();
            std::vector<double> compared = {1, 2, 3, 4, 5, 6};
            auto it = compared.begin();
            for (auto node = tree_with_int.begin_heap(); node != tree_with_int.end_heap(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }

    
    }

TEST_CASE("Tree with double")
{
    
        Node<double> n1(1.1); 
        Tree<double> tree_with_double;          
        tree_with_double.add_root(n1);
        Node<double> n2(1.2);
        Node<double> n3(1.3);
        Node<double> n4(1.4);
        Node<double> n5(1.5);
        Node<double> n6(1.6);
        tree_with_double.add_sub_node(n1, n2);
        tree_with_double.add_sub_node(n1, n3);
        tree_with_double.add_sub_node(n2, n4);
        tree_with_double.add_sub_node(n2, n5);
        tree_with_double.add_sub_node(n3, n6);
        CHECK(tree_with_double.get_root()->get_childrens().at(0)->get_value() == n2.get_value());
        CHECK(n2.get_childrens().at(0)->get_value() == n4.get_value());

        SUBCASE("In_order Iterator")
        {
            std::vector<double> compared = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
            auto it = compared.begin();
            for (auto node = tree_with_double.begin_in_order(); node != tree_with_double.end_in_order(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("BFS Iterator")
        {
            std::vector<double> compared = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
            auto it = compared.begin();
            for (auto node = tree_with_double.begin_bfs_scan(); node != tree_with_double.end_bfs_scan(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("DFS Iterator")
        {
            std::vector<double> compared = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
            auto it = compared.begin();
            for (auto node = tree_with_double.begin_dfs_scan(); node != tree_with_double.end_dfs_scan(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("Heap Iterator")
        {
            
            tree_with_double.construct_heap();
            std::vector<double> compared = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
            auto it = compared.begin();
            for (auto node = tree_with_double.begin_heap(); node != tree_with_double.end_heap(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

         SUBCASE("Pre_order Iterator")
        {
            std::vector<double> compared = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
            auto it = compared.begin();
            for (auto node = tree_with_double.begin_pre_order(); node != tree_with_double.end_pre_order(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("Post_order Iterator")
        {
            std::vector<double> compared = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
            auto it = compared.begin();
            for (auto node = tree_with_double.begin_post_order(); node != tree_with_double.end_post_order(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

    
    }

 
TEST_CASE("Tree with Complex")
{
   
        Node<Complex> n1(Complex(1, 1)); 
        Tree<Complex> tree_with_complex;                   
        tree_with_complex.add_root(n1);
        Node<Complex> n2(Complex(2, 2));
        Node<Complex> n3(Complex(3, 3));
        Node<Complex> n4(Complex(4, 4));
        Node<Complex> n5(Complex(5, 5));
        Node<Complex> n6(Complex(6, 6));

        tree_with_complex.add_sub_node(n1, n2);
        tree_with_complex.add_sub_node(n1, n3);
        tree_with_complex.add_sub_node(n2, n4);
        tree_with_complex.add_sub_node(n2, n5);
        tree_with_complex.add_sub_node(n3, n6);
        CHECK(tree_with_complex.get_root()->get_childrens().at(0)->get_value() == n2.get_value());
        CHECK(n2.get_childrens().at(0)->get_value() == n4.get_value());

        

        SUBCASE("In_order Iterator")
        {
            std::vector<Complex> compared = {Complex(4, 4), Complex(2, 2), Complex(5, 5), Complex(1, 1), Complex(6, 6), Complex(3, 3)};
            auto it = compared.begin();
            for (auto node = tree_with_complex.begin_in_order(); node != tree_with_complex.end_in_order(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("BFS Iterator")
        {
            std::vector<Complex> compared = {Complex(1, 1), Complex(2, 2), Complex(3, 3), Complex(4, 4), Complex(5, 5), Complex(6, 6)};
            auto it = compared.begin();
            for (auto node = tree_with_complex.begin_bfs_scan(); node != tree_with_complex.end_bfs_scan(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("DFS Iterator")
        {
            std::vector<Complex> compared = {Complex(1, 1), Complex(2, 2), Complex(4, 4), Complex(5, 5), Complex(3, 3), Complex(6, 6)};
            auto it = compared.begin();
            for (auto node = tree_with_complex.begin_dfs_scan(); node != tree_with_complex.end_dfs_scan(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("Pre_order Iterator")
        {
            std::vector<Complex> compared = {Complex(1, 1), Complex(2, 2), Complex(4, 4), Complex(5, 5), Complex(3, 3), Complex(6, 6)};
            auto it = compared.begin();
            for (auto node = tree_with_complex.begin_pre_order(); node != tree_with_complex.end_pre_order(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("Post_orderIterator")
        {
            std::vector<Complex> compared = {Complex(4, 4), Complex(5, 5), Complex(2, 2), Complex(6, 6), Complex(3, 3), Complex(1, 1)};
            auto it = compared.begin();
            for (auto node = tree_with_complex.begin_post_order(); node != tree_with_complex.end_post_order(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("Heap Iterator")
        {
            tree_with_complex.construct_heap();
            std::vector<Complex> compared = {Complex(1, 1), Complex(2, 2), Complex(3, 3), Complex(4, 4), Complex(5, 5), Complex(6, 6)};
            auto it = compared.begin();
            for (auto node = tree_with_complex.begin_heap(); node != tree_with_complex.end_heap(); ++node){
                CHECK((*node)->get_value() == *it++);
            }
        }


    }
    
    

TEST_CASE("Tree K=3 with strng"){

        Node<string> n1("a"); 
        Tree<string, 3> tree_with_string;      
        tree_with_string.add_root(n1);
        Node<string> n2("b");
        Node<string> n3("c");
        Node<string> n4("d");
        Node<string> n5("e");
        Node<string> n6("f");

        tree_with_string.add_sub_node(n1, n2);
        tree_with_string.add_sub_node(n1, n3);
        tree_with_string.add_sub_node(n1, n4);
        tree_with_string.add_sub_node(n2, n5);
        tree_with_string.add_sub_node(n3, n6);
        CHECK(tree_with_string.get_root()->get_childrens().at(0)->get_value() == n2.get_value());
        CHECK(n2.get_childrens().at(0)->get_value() == n5.get_value());

       
        SUBCASE("Post_order Iterator")
        {
            std::vector<string> compared = {"a", "b", "e", "c", "f", "d"};
            auto it = compared.begin();
            for (auto node = tree_with_string.begin_post_order(); node != tree_with_string.end_post_order(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            } 
        }

        SUBCASE("In_order Iterator")
        {
            std::vector<string> compared = {"a", "b", "e", "c", "f", "d"};
            auto it = compared.begin();
            for (auto node = tree_with_string.begin_in_order(); node != tree_with_string.end_in_order(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }

         SUBCASE("Pre_order Iterator")
        {
            std::vector<string> compared = {"a", "b", "e", "c", "f", "d"};
            auto it = compared.begin();
            for (auto node = tree_with_string.begin_pre_order(); node != tree_with_string.end_pre_order(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }


        SUBCASE("BFS Iterator")
        {
            std::vector<string> compared = {"a", "b", "c", "d", "e", "f"};
            auto it = compared.begin();
            for (auto node = tree_with_string.begin_bfs_scan(); node != tree_with_string.end_bfs_scan(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }

        SUBCASE("DFS Iterator")
        {
            std::vector<string> compared = {"a", "b", "e", "c", "f", "d"};
            auto it = compared.begin();
            for (auto node = tree_with_string.begin_dfs_scan(); node != tree_with_string.end_dfs_scan(); ++node)
            {
                CHECK((*node)->get_value() == *it++);
            }
        }



}


