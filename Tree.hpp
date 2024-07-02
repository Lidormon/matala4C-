#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <iostream>
#include "Node.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>

template <typename T, int K = 2>
class Tree
{
private:
    Node<T> *root;
//calculate the depth of the tree
    int depth(Node<T> *f){
        if (!f)
            return 0;
        int ans_depth = 0;
        for (Node<T> *c : f->get_childrens()){
            int d = depth(c);
            if (d > ans_depth){ ans_depth = d;}     
        }
        return ans_depth + 1;
    }
//drwa the tree
    void draw_tree(sf::RenderWindow &window, Node<T> *n, sf::Font &font, float x, float y, float f, int level, int max_level){
        if (!n)
            return;
//circle
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(x, y);

        std::stringstream sstream;
  
        sstream << std::fixed << n->get_value();
        std::string s = sstream.str();
//value of the node
        sf::Text t;
        t.setFont(font);
        t.setString(s);
        t.setCharacterSize(15);
        t.setFillColor(sf::Color::Black);
        sf::FloatRect boun = t.getLocalBounds();
        t.setOrigin(boun.left + boun.width / 2.5f,boun.top + boun.height / 2.5f);
        t.setPosition(x + circle.getRadius(), y + circle.getRadius());

        window.draw(circle);
        window.draw(t);

//passover the childrens
        const std::vector<Node<T> *> &vec_children = n->get_childrens();
        float f2 = f / 2;
        float f3 = 500.0 / (max_level + 1);

        for (size_t i = 0; i < vec_children.size(); ++i){
            float right = x + (i - (vec_children.size() - 1) / 2.0) * f;
            float left = y + f3;

            sf::Vertex lines[] =
                {
                    sf::Vertex(sf::Vector2f(x + 18, y + 18), sf::Color::Red),
                    sf::Vertex(sf::Vector2f(right + 18, left), sf::Color::Red)};

            window.draw(lines, 2, sf::Lines);
            draw_tree(window, vec_children[i], font, right, left, f2, level + 1, max_level);
        }
    }


public:
//constractor
    Tree() : root(nullptr) {}
    ~Tree() {}
    
//get root of the tree
    Node<T> *get_root() const{ return root;}
    //add root
    void add_root(Node<T> &f){ root = &f;}
//add sub node 
    void add_sub_node(Node<T> &p, Node<T> &c){
        if (p.number_of_childrens() < K) {
            p.add_child(&c); 
        }
        else{
            throw std::invalid_argument("Error in number of childrens.");
        }
    }
    
  
    class PreOrderIterator
    {
    private:
        std::stack<Node<T> *> st; 

    public:
        PreOrderIterator(Node<T> *root) {
            if (root){st.push(root);}     
        }

        bool operator!=(const PreOrderIterator &other) const{
            return !(*this == other);
        }
             const PreOrderIterator &operator++(){
            if (st.empty()){return *this;}

            Node<T> *f = st.top();
            st.pop();
            
            for (auto it = f->get_childrens().rbegin(); it != f->get_childrens().rend(); ++it) {
                st.push(*it);
            }
            return *this;
        }

        bool operator==(const PreOrderIterator &other) const{
            return st == other.st;
        }

        Node<T> *operator*() const{
            if (st.empty()){
                throw std::invalid_argument("error:empty");
            }
            return st.top();
        }
    };
    auto begin_pre_order() const{
        if constexpr (K == 2) {return PreOrderIterator(root);}
        else{return DFSIterator(root);}
    }


    auto end_pre_order() const{
        if constexpr (K == 2){return PreOrderIterator(nullptr);}
        else{return DFSIterator(nullptr);  }
    }

    class PostOrderIterator{
    private:
        std::stack<Node<T> *> st; 
        std::stack<Node<T> *> s1;    

    public:
        
        PostOrderIterator(Node<T> *root){
            if (root){
                st.push(root);
                while (!st.empty()){
                    Node<T> *f = st.top();
                    st.pop();
                    s1.push(f);
                    const auto &vec_childrens = f->get_childrens();
                    for (Node<T> *c : vec_childrens){
                        st.push(c);
                    }
                }
            }
        }

        Node<T> *operator*() const{
            if (s1.empty()){
                throw std::invalid_argument("error:empty");
            }
            return s1.top();
        }
        bool operator!=(const PostOrderIterator &other) const{return !s1.empty();}
        const PostOrderIterator &operator++(){
            if (!s1.empty()){
                s1.pop();
            }
            return *this;
        }


    };

   
    auto begin_post_order() const{
        if constexpr (K == 2){ return PostOrderIterator(root);}
        else{ return DFSIterator(root);}
    }

   
    auto end_post_order() const{
        if constexpr (K == 2){return PostOrderIterator(nullptr);}
        else{return DFSIterator(nullptr);}
    }
  
    class InOrderIterator
    {
    private:
        std::stack<Node<T> *> st;
        Node<T> *curr;           
       
        void pushLeftmost(Node<T> *f){
            while (f){
                st.push(f);
                if (!f->get_childrens().empty()){
                    f = f->get_childrens().front(); 
                }
                else{break;}
            }
        }

    public:
        
        InOrderIterator(Node<T> *root) : curr(root){
            pushLeftmost(root);
        }
        bool operator!=(const InOrderIterator &other) const{
            return !st.empty();
        }

         Node<T> *operator*() const{
            if (st.empty()){
                throw std::invalid_argument("error:empty");
            }
            return st.top();
        }

        const InOrderIterator &operator++(){
            if (!st.empty()){
                Node<T> *f = st.top();
                st.pop();
                const auto &vec_childrens = f->get_childrens();
                if (vec_childrens.size() > 1){pushLeftmost(vec_childrens[1]);}
            }
            return *this;
        }

    };

    auto begin_in_order() const{
        if constexpr (K == 2){return InOrderIterator(root);}
        else{ return DFSIterator(root); }
    }

    auto end_in_order() const{
        if constexpr (K == 2){return InOrderIterator(nullptr);}
        else{return DFSIterator(nullptr);}
    }

  
    class BFSIterator
    {
    private:
        std::queue<Node<T> *> q; 

    public:
        BFSIterator(Node<T> *root){
            if (root) {q.push(root);}
        }
        bool operator!=(const BFSIterator &other) const{return !q.empty();}

       
        const BFSIterator &operator++() {
            if (!q.empty()){
                Node<T> *f = q.front();
                q.pop();
                for (Node<T> *c : f->get_childrens()){
                    q.push(c);
                }
            }
            return *this;
        }

        Node<T> *operator*() const{
            if (q.empty()){
                throw std::invalid_argument("Error: empty");
            }
            return q.front();
        }
    };
     BFSIterator begin_bfs_scan() const{return BFSIterator(root);}
    BFSIterator end_bfs_scan() const{return BFSIterator(nullptr); }
    BFSIterator begin() const{return begin_bfs_scan();}
    BFSIterator end() const{return end_bfs_scan();}
   


  


    class HeapIterator
{
private:
    std::vector<Node<T> *> heap;
    size_t f;

public:
    HeapIterator(Node<T> *root) : f(0){
        if (root){
            Heap_help(root);
        }
    }
    void Heap_help(Node<T> *root){
        std::queue<Node<T> *> q;
        if (root){
            q.push(root);
        }
        while (!q.empty()){
            Node<T> *f = q.front();
            q.pop();
            heap.push_back(f);
            for (Node<T> *c : f->get_childrens()){
                q.push(c);
            }
        }
        std::make_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b) {
            return a->get_value() > b->get_value();
        });
    }

    Node<T> *operator*() const{
    if (heap.empty() || f >= heap.size()){
        throw std::invalid_argument("error");
    }
    return heap[f];
}

    int size_heap(){return heap.size();}

    void update(int temp){f = temp;}

   bool operator!=(const HeapIterator &other) const{
    return f != other.f;
}


    const HeapIterator &operator++(){
        if (f < heap.size()){++f;}
    return *this;
    }

};
    HeapIterator begin_heap(){return HeapIterator(root);}

HeapIterator end_heap(){
    HeapIterator it(root);
    it.update(it.size_heap()); 
    return it;
}


HeapIterator construct_heap(){
    if (K == 2){
        if (!root){
            throw std::logic_error("error:empty tree");
        }
        std::vector<Node<T> *> vec_nodes;
        std::queue<Node<T> *> q;
        q.push(root);

        while (!q.empty()){
            Node<T> *f = q.front();
            q.pop();
            vec_nodes.push_back(f);
            for (Node<T> *c : f->get_childrens()){
                q.push(c);
            }
        }
        std::make_heap(vec_nodes.begin(), vec_nodes.end(), [](Node<T> *a, Node<T> *b) {
            return a->get_value() > b->get_value();
        });

        for (size_t i = 0; i < vec_nodes.size(); ++i){
            size_t postion_left = 2 * i + 1;
            size_t position_right = 2 * i + 2;

            vec_nodes[i]->update_childrens();
            if (postion_left < vec_nodes.size()){
                vec_nodes[i]->add_child(vec_nodes[postion_left]);
            }
            if (position_right < vec_nodes.size()){
                vec_nodes[i]->add_child(vec_nodes[position_right]);
            }
        }
        if (vec_nodes.empty()){root=nullptr;}
        else{root=vec_nodes.front();}

       // root = vec_nodes.empty() ? nullptr : vec_nodes.front();
    }
    else{
        throw std::logic_error("k is different of 2");
    }
    return HeapIterator(root);
}

  class DFSIterator
    {
    private:
        std::stack<Node<T> *> st; 

    public:
        DFSIterator(Node<T> *root){
            if (root){
                st.push(root);
            }
        }

        bool operator!=(const DFSIterator &other) const{
            return !st.empty();
        }

        Node<T> *operator*() const {
            if (st.empty()) {
                throw std::invalid_argument("Error:empty ");
            }
            return st.top();
        }

        const DFSIterator &operator++(){
            if (!st.empty()){
                Node<T> *f = st.top();
                st.pop();
                for (auto it = f->get_childrens().rbegin(); it != f->get_childrens().rend(); ++it){
                    st.push(*it);
                }
            }
            return *this;
        }
     
    };

    DFSIterator begin_dfs_scan() const{return DFSIterator(root);}
    DFSIterator end_dfs_scan() const{ return DFSIterator(nullptr);}
    


    void visualize()
    {
        sf::RenderWindow window(sf::VideoMode(1200, 800), "Tree Visualization");
        sf::Font f;


if (!f.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")){
            std::cerr << "Error load font" << std::endl;
            return;
        }
        while (window.isOpen()){
            sf::Event e;
            while (window.pollEvent(e)){
                if (e.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);
            int ans_depth = depth(root);
            draw_tree(window, root, f, window.getSize().x / 2, 20, window.getSize().x / 2, 0, ans_depth);
            window.display();
        }
    }
};

#endif
