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
    
    
    // name null ? , Tree* find_name_req(Tree* T, string name), new
    Tree& addFather(string name, string father);
    // name null ? , Tree* find_name_req(Tree* T, string name), new
    Tree& addMother(string name, string father);
    //Gets the name of someone in the tree, and restores the relationship between him and you
    //me,f,m
    //string find_name_level_req(Tree* T, string name, int current_level)
    string relation(string name);
    //get relation -> return preson name
    //string member_rel(Tree* T, string name);, delimiter "-"
    string find(string name);

    void display();
    void remove(string name);
    //Tree* deletTree(string name, Tree* T);
    ~Tree() {}
    };
};
