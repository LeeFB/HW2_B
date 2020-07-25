//
//  FamilyTree.cpp
//  ancestor-tree-a
//
//  Created by Lee Fingerhut on 09/04/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "FamilyTree.hpp"
using namespace std;
using namespace family;

string Tree::getName() {
    return this->name;
}

void Tree::setName(string name) {
    this->name = name;
}

Tree* Tree::getFather() {
    return this->father;
}

void Tree::setFather(Tree* father) {
    this->father = father;
}

Tree* Tree::getMother() {
    return this->mother;
}
void Tree::setMother(Tree* mother) {
    this->mother = mother;
}
//Returns the sub-tree whose name is its root
Tree* find_name_req(Tree* T, string name) {
    if(T->getName() == name) {
        return T;
    }
    Tree* t = NULL;
    if (T->getFather()) {
        t = find_name_req(T->getFather(), name);
        if (t) return t;
    }
    if (T->getMother()) {
        t = find_name_req(T->getMother(), name);
        if (t) return t;
    }
    return t ;
}

string find_name_level_req(Tree* T, string name, int current_level) {
    if(T == NULL)
    {
        return "";
    }
    if(T->getFather() != NULL && T->getFather()->getName() == name)
    {
        string s = "grandfather";
        for(int i=0; i<current_level; i++)
        {
            s = "great-"+s;
        }
        return s;
    }
    
    if(T->getMother() != NULL && T->getMother()->getName() == name)
    {
        string s = "grandmother";
        for(int i=0; i<current_level; i++)
        {
            s = "great-"+s;
        }
        return s;
    }
    string f = find_name_level_req(T->getFather(), name, current_level+1);
    if(!f.empty())
    {
        return f;
    }
    string m = find_name_level_req(T->getMother(), name, current_level+1);
    if(!m.empty())
    {
        return m;
    }
    return "";
}

string member_rel(Tree* T, string name)
{
    if(name.empty() || T == NULL)
    {
        return "";
    }
    if(name == "grandfather")
    {
        if(T->getFather() != NULL)
        {
            return T->getFather()->getName();
        }
        return "";
    }
    if(name == "grandmother")
    {
        if(T->getMother() != NULL)
        {
            return T->getMother()->getName();
        }
        return "";
    }
    std::string s = name;
    std::string delimiter = "-";
    std::string token = s.substr(s.find(delimiter)+1);
    if(token == name)
    {
        return "";
    }
    //cout << token << endl;
    string m = member_rel(T->getMother(), token);
    if(!m.empty())
    {
        return m;
    }
    string f = member_rel(T->getFather(), token);
    if(!f.empty())
    {
        return f;
    }
    return "";
}
// name null ? , Tree* find_name_req(Tree* T, string name), new
Tree& Tree::addFather(string name, string father) {
    
    if(father.empty())
    {
        throw std::runtime_error("got empty string");
    }
    Tree* Tname = find_name_req(this, name) ;
    if(!Tname)
    {
        throw std::runtime_error(name+"does not exist");
    }
    if(Tname->father)
    {
        throw std::runtime_error(name+"alredy has a father");
    }
    Tname->father = new Tree(father) ;
    return *this;
}
// name null ? , Tree* find_name_req(Tree* T, string name), new
Tree& Tree::addMother(string name, string mother) {
    Tree* Tname = find_name_req(this, name) ;
    if(mother.empty())
    {
        throw std::runtime_error("got empty string");
    }
    if(!Tname)
    {
        throw std::runtime_error(name+"does not exist");
    }
    if(Tname->mother)
    {
        throw std::runtime_error(name+"alredy has a mother");
    }
    Tname->mother = new Tree(mother) ;
    return *this;
}

/*#define COUNT 10
void display_req(Tree* T, int space, Tree* T1) {
    if (T->getName().empty()){
        return ;
    }
    space += COUNT;
    if (T->getFather() != NULL) {
        display_req(T->getFather(), space, T1);
    }
    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout<<" ";
    }
    cout << T1->relation(T->getName()) << "\n";
    if (T->getMother() != NULL) {
        display_req(T->getMother(), space, T1);
    }
}
void Tree::display() {
    display_req(this, 0, this);
}
*/

#define COUNT 10
void display_req(Tree* T, int space) {
    if (T->getName().empty()){
        return ;
    }
    space += COUNT;
    if (T->getFather() != NULL) {
        display_req(T->getFather(), space);
    }
    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout<<" ";
    }
    cout << T->getName() << "\n";
    if (T->getMother() != NULL) {
        display_req(T->getMother(), space);
    }
}

void Tree::display() {
    display_req(this, 0);
}
 //Gets the name of someone in the tree, and restores the relationship between him and you
//me,f,m
//string find_name_level_req(Tree* T, string name, int current_level)
string Tree::relation(string name) {
    
    if(name.empty()){
        throw runtime_error ("got empty string");
    }
    if (this->name == name) {
        return "me" ;
    }
    if (this->father && this->father->name == name) {
        return "father" ;
    }
    if (this->mother && this->mother->name == name) {
        return "mother" ;
    }
    if(this->father) {
        string s1 = find_name_level_req(this->father, name, 0);
        if(!s1.empty()) {
            return s1;
        }
    }
    if(this->mother != NULL) {
        string s2 = find_name_level_req(this->mother, name, 0);
        if(!s2.empty()) {
            return s2;
        }
    }
    return "unrelated";
}

//get relation -> return preson name
//string member_rel(Tree* T, string name);, delimiter "-"
string Tree::find(string name) {
    //CHECK_THROW_STR(name.empty(), "got empty string");
    if(name.empty())
    {
        throw runtime_error ("got empty string");
    }
    if(name == "unrelated")
    {
        throw runtime_error ("not illeagle name!");
    }
    //int pos = name.find("-");
    
    if (name == "me") {
        return this->name;
    }
    if (name == "father" && this->father) {
        return this->father->name;
    }
    if (name == "mother" && this->mother) {
        return this->mother->name;
    }
    if(this->father) {
        string s1 = member_rel(this->father, name);
        if(!s1.empty()) {
            return s1;
        }
    }
    if(this->mother != NULL) {
        string s2 = member_rel(this->mother, name);
        if(!s2.empty()) {
            return s2;
        }
    }
    if(true)
    {
        throw runtime_error ("The tree cannot handle the '"+name+"' relation");
    }
}


Tree* deletTree(string name, Tree* T)
{
    if (T) {
        if (T->getFather() != NULL && T->getFather()->getName() == name) {
            return T;
        }
        if (T->getMother() != NULL && T->getMother() ->getName() == name) {
            return T;
        }
        
        Tree* father = deletTree(name, T->getFather());
        if (father != NULL) {
            return father;
        }
        Tree* mother = deletTree(name, T->getMother());
        if (mother != NULL) {
            return mother;
        }
        return NULL;
    }
    return NULL;
}

void Tree::remove(string name){
    //Tree* deletTree(string name, Tree* T);
    Tree* T = deletTree(name, this);
    if (T) {
        if (T->father && T->father->name == name) {
            delete T->father;
            T->father = NULL;
            return;
        }
        else if (T->mother && T->mother->name == name) {
            delete T->mother;
            T->mother = NULL;
            return;
        }
    }
    else {
        throw runtime_error ("can't delete");
    }
}
