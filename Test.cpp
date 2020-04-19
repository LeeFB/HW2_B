//
//  Test.cpp
//  ancestor-tree-a
//
//  Created by Lee Fingerhut on 10/04/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace std;
using namespace family;

TEST_CASE("cheak for all methods")
{
    //Crate a tree, and added father/mother
    Tree T1("Yossi");
    T1.addFather("Yossi", "Asaf");
    T1.addFather("Asaf", "Guy");
    T1.addFather("Guy", "Haim");
    T1.addFather("Haim", "Amir");
    T1.addMother("Haim", "Reut");
    T1.addMother("Asaf", "Lin");
    T1.addFather("Lin", "Avi");
    T1.addMother("Lin", "Sima");
    T1.addFather("Avi", "Moshe");
    T1.addMother("Avi", "Mira");
    T1.addMother("Yossi", "Sara");
    T1.addMother("Sara", "Tal");
    T1.addFather("Sara", "Sami");
    T1.addFather("Sami", "Adam");
    T1.addMother("Sami", "Shir");
    T1.addMother("Tal", "Mor");
    T1.addFather("Tal", "Ziv");
    T1.addMother("Mor", "Tamar");
    T1.addFather("Mor", "Or");
    T1.addMother("Tamar", "Moran");
    T1.addFather("Tamar", "Itai");
    T1.addMother("Or", "Bar");
    T1.addFather("Or", "Lior");
    T1.addFather("Lior", "Shay");
    T1.addMother("Lior", "Liran");
    T1.addFather("Bar", "Dor");
    
    //*******Find*****
    CHECK(T1.find("me") == string("Yossi"));
    CHECK(T1.find("mother") == string("Sara"));
    CHECK(T1.find("father") == string("Asaf"));
    CHECK((T1.find("grandfather") == string("Guy") || T1.find("grandfather") == string("Sami")));
    CHECK((T1.find("great-grandfather") == string("Avi") || T1.find("great-grandfather") == string("Haim")));
    CHECK((T1.find("great-great-grandfather") == string("Moshe") || T1.find("great-great-grandfather") == string("Amir") || T1.find("great-great-grandfather") == string("Or")));
    CHECK((T1.find("grandmother") == string("Lin") || T1.find("grandmother") == string("Tal")));
    CHECK((T1.find("great-grandmother") == string("Sima") || T1.find("great-grandmother") == string("Shir") || T1.find("great-grandmother") == string("Mor")));
    CHECK((T1.find("great-great-grandmother") == string("Mira") || T1.find("great-great-grandmother") == string("Tamar") || T1.find("great-great-grandmother") == string("Reut")));
    CHECK((T1.find("great-great-great-grandmother") == string("Moran") || T1.find("great-great-great-grandmother") == string("Bar")));
    CHECK((T1.find("great-great-great-great-grandfather") == string("Shay") || T1.find("great-great-great-great-grandfather") == string("Dor")));
    
    //****Relation****
    CHECK(T1.relation("Yossi") == string("me"));
    CHECK(T1.relation("Asaf") == string("father"));
    CHECK(T1.relation("Guy") == string("grandfather"));
    CHECK(T1.relation("Haim") == string("great-grandfather"));
    CHECK(T1.relation("Amir") == string("great-great-grandfather"));
    CHECK(T1.relation("Lin") == string("grandmother"));
    CHECK(T1.relation("Avi") == string("great-grandfather"));
    CHECK(T1.relation("Sima") == string("great-grandmother"));
    CHECK(T1.relation("Moshe") == string("great-great-grandfather"));
    CHECK(T1.relation("Mira") == string("great-great-grandmother"));
    CHECK(T1.relation("Sara") == string("mother"));
    CHECK(T1.relation("Tal") == string("grandmother"));
    CHECK(T1.relation("Sami") == string("grandfather"));
    CHECK(T1.relation("Adam") == string("great-grandfather"));
    CHECK(T1.relation("Shir") == string("great-grandmother"));
    CHECK(T1.relation("Mor") == string("great-grandmother"));
    CHECK(T1.relation("Ziv") == string("great-grandfather"));
    CHECK(T1.relation("Tamar") == string("great-great-grandmother"));
    CHECK(T1.relation("Or") == string("great-great-grandfather"));
    CHECK(T1.relation("Moran") == string("great-great-great-grandmother"));
    CHECK(T1.relation("Itai") == string("great-great-great-grandfather"));
    CHECK(T1.relation("Bar") == string("great-great-great-grandmother"));
    CHECK(T1.relation("Lior") == string("great-great-great-grandfather"));
    CHECK(T1.relation("Shay") == string("great-great-great-great-grandfather"));
    CHECK(T1.relation("Liran") == string("great-great-great-great-grandmother"));
    CHECK(T1.relation("Dor") == string("great-great-great-great-grandfather"));
    CHECK(T1.relation("Eyal") == string("unrelated"));
    CHECK(T1.relation("micha") == string("unrelated"));
    CHECK(T1.relation("Imri") == string("unrelated"));
    CHECK(T1.relation("Sharon") == string("unrelated"));
    CHECK(T1.relation("Ben") == string("unrelated"));
    CHECK(T1.relation("Yair") == string("unrelated"));
    CHECK(T1.relation("Mirav") == string("unrelated"));
    CHECK(T1.relation("Roy") == string("unrelated"));
    CHECK(T1.relation("Oron") == string("unrelated"));
    CHECK(T1.relation("Yoav") == string("unrelated"));
    CHECK(T1.relation("Oz") == string("unrelated"));
    CHECK(T1.relation("Noa") == string("unrelated"));
    CHECK(T1.relation("Shiri") == string("unrelated"));
    CHECK(T1.relation("Ran") == string("unrelated"));
    CHECK(T1.relation("Rani") == string("unrelated"));
    CHECK(T1.relation("Rami") == string("unrelated"));
    CHECK(T1.relation("Shavit") == string("unrelated"));
    CHECK(T1.relation("Amit") == string("unrelated"));
    CHECK(T1.relation("Yoni") == string("unrelated"));
    CHECK(T1.relation("Yonatan") == string("unrelated"));
    CHECK(T1.relation("Oded") == string("unrelated"));
    CHECK(T1.relation("Naama") == string("unrelated"));
    CHECK(T1.relation("Yaya") == string("unrelated"));
    CHECK(T1.relation("Rotem") == string("unrelated"));
    CHECK(T1.relation("Oren") == string("unrelated"));
    CHECK(T1.relation("Beyonce") == string("unrelated"));
    CHECK(T1.relation("Mika") == string("unrelated"));
    CHECK(T1.relation("Maia") == string("unrelated"));
    CHECK(T1.relation("Dana") == string("unrelated"));
    CHECK(T1.relation("Gur") == string("unrelated"));
    CHECK(T1.relation("Lihi") == string("unrelated"));
    CHECK(T1.relation("Mati") == string("unrelated"));
    CHECK(T1.relation("mm") == string("unrelated"));
    CHECK(T1.relation("tt") == string("unrelated"));
    CHECK(T1.relation("yy") == string("unrelated"));
    CHECK(T1.relation("uu") == string("unrelated"));
    CHECK(T1.relation("retr") == string("unrelated"));
    CHECK(T1.relation("yugfrr") == string("unrelated"));
    CHECK(T1.relation("dnvdbhfd") == string("unrelated"));
    CHECK(T1.relation("dd") == string("unrelated"));
    CHECK(T1.relation("Racni") == string("unrelated"));
    CHECK(T1.relation("Racmi") == string("unrelated"));
    CHECK(T1.relation("avigrrgrit") == string("unrelated"));
    CHECK(T1.relation("Yoefregni") == string("unrelated"));
    CHECK(T1.relation("Yonatddean") == string("unrelated"));
    CHECK(T1.relation("Odedddd") == string("unrelated"));
    CHECK(T1.relation("Naaddma") == string("unrelated"));
    CHECK(T1.relation("Yaydda") == string("unrelated"));
    CHECK(T1.relation("Rodrgrgrtem") == string("unrelated"));
    CHECK(T1.relation("Orrggren") == string("unrelated"));
    CHECK(T1.relation("Beyrfrgrgonce") == string("unrelated"));
    CHECK(T1.relation("Mikrrffa") == string("unrelated"));
    CHECK(T1.relation("Mafffia") == string("unrelated"));
    CHECK(T1.relation("Dadfdfdfnca") == string("unrelated"));
    CHECK(T1.relation("Gurd") == string("unrelated"));
    CHECK(T1.relation("Lirgfvcccchi") == string("unrelated"));
    CHECK(T1.relation("Maftgghdgdhghgcti") == string("unrelated"));
    CHECK(T1.relation("Danda") == string("unrelated"));
    CHECK(T1.relation("Gudr") == string("unrelated"));
    CHECK(T1.relation("Lidhi") == string("unrelated"));
    CHECK(T1.relation("Mdati") == string("unrelated"));
    CHECK(T1.relation("mm") == string("unrelated"));
    CHECK(T1.relation("tt") == string("unrelated"));
    CHECK(T1.relation("yyddddd") == string("unrelated"));
    CHECK(T1.relation("uue") == string("unrelated"));
    CHECK(T1.relation("reeetr") == string("unrelated"));
    CHECK(T1.relation("yugfrr") == string("unrelated"));
    CHECK(T1.relation("dnvdbhfd") == string("unrelated"));
    CHECK(T1.relation("Lidddsdn") == string("unrelated"));
    CHECK(T1.relation("dscddd") == string("unrelated"));
    CHECK(T1.relation("d") == string("unrelated"));
    CHECK(T1.relation("Racccmi") == string("unrelated"));
    CHECK(T1.relation("avifddffdcgrrgrit") == string("unrelated"));
    CHECK(T1.relation("Yoecfregni") == string("unrelated"));
    CHECK(T1.relation("Yonahrghfghdfdtddean") == string("unrelated"));
    CHECK(T1.relation("Odedddd") == string("unrelated"));
    
    //******Eexception + Remov******
    CHECK_THROWS_AS(T1.addFather("Yossi", "Aviv"),std::exception);
    CHECK_THROWS_AS(T1.addMother("Yossi", "Rozi"),std::exception);
    CHECK_THROWS_AS(T1.addFather("Guy", "Ami"),std::exception);
    CHECK_THROWS_AS(T1.addMother("Sara", "Avital"),std::exception);
    CHECK_THROWS_AS(T1.addFather("Mor", "Roni"),std::exception);
    CHECK_THROWS_AS(T1.addMother("Mor", "Sigal"),std::exception);
    CHECK_THROWS_AS(T1.addFather("Tamar", "Ronen"),std::exception);
    CHECK_THROWS_AS(T1.addMother("Tamar", "Nati"),std::exception);
    CHECK_THROWS_AS(T1.addMother("Hay", "Sigal"),std::exception);
    CHECK_THROWS_AS(T1.addMother("Sima", ""),std::exception);
    CHECK_THROWS_AS(T1.addFather("Shahar", "Ronen"),std::exception);
    CHECK_THROWS_AS(T1.addMother("Niran", "Noa"),std::exception);
    CHECK_THROWS_AS(T1.addMother("Dor", ""),std::exception);
    CHECK_THROWS_AS(T1.remove("Yossi"),std::exception);
    CHECK_THROWS_AS(T1.find("great-great-great-great-great-grandfather"),std::exception);
    CHECK_THROWS_AS(T1.find("unrelated"),std::exception);
    CHECK_THROWS_AS(T1.find(""),std::exception);
    CHECK_THROWS_AS(T1.find("uncle"),std::exception);
    CHECK_THROWS_AS(T1.find("unrelated"),std::exception);
    CHECK_THROWS_AS(T1.find("great-great-great-great-great-great-great-great-grandmother"),std::exception);
    
}


