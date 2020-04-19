//
//  FamilyTree.hpp
//  ancestor-tree-a
//
//  Created by Lee Fingerhut on 09/04/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#include <string>
#include<iostream>
using namespace std;

namespace family{
class Tree {
private:
    string name;
    Tree* father;
    Tree* mother;
public: 
    Tree(string name) {
        this->name = name;
        this->father = NULL;
        this->mother = NULL;
    }
    Tree() {
        Tree(NULL);
    };
    
    string getName();
    void setName(string name);
    Tree* getFather();
    void setFather(Tree* father);
    Tree* getMother();
    void setMother(Tree* mother);
    
    
    Tree* find_name_req(Tree* T, string name);
    string find_name_level_req(Tree* T, string name, int current_level);
    string member_rel(Tree* T, string name);
    Tree& addFather(string name, string father);
    Tree& addMother(string name, string father);
    string relation(string name);
    string find(string name);
    void display();
    void remove(string name);
    Tree* deletTree(string name, Tree* T);
    ~Tree() {
        if (this->father) {
            delete this->father;
        }
        if (this->mother) {
            delete this->mother;
        }
    };
};
};

