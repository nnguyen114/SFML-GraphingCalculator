
#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../includes/Graph_Info.h"
#include "../../includes/graph.h"
#include "../../includes/token/token.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/coord_translation.h"
#include "../../includes/tokenizer.h"
#include "../../includes/animate.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
using namespace sf;
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_SHunting(bool debug = false){
Queue<Token *> infix;
 
  infix.push(new Integer(5));
  infix.push(new Operator("*"));
  infix.push(new Operator("sin"));
  infix.push(new LeftParen());
  infix.push(new Function("X"));
  infix.push(new RightParen());

  ShuntingYard sy(infix);
  Queue<Token*> postfix = sy.postfix();
  RPN rpn(postfix);
  cout << "3 * 5: " << rpn(2) << endl;
  return true ;
}

bool test_queue(bool debug = false)
{
  Graph_Info* info;
  info->equation="sin(X)";
  Tokenize token(info);

  Queue<Token *> tokenqueue = token(info);
  ShuntingYard sy(tokenqueue);
  Queue<Token *> postfix = sy.postfix();
  RPN rpn(postfix);

  cout<<rpn(3.14159265359/2)<<endl;

  while(!postfix.empty()){
   cout << postfix.pop()->token() << " ";
}
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

// TEST(TEST_GRAPH, TestGraph) {
  
//   //EXPECT_EQ(0, <your individual test functions are called here>);

//   EXPECT_EQ(1, test_graph(false));
// }

TEST(TEST_SHUntin, TestYard) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_SHunting(false));
}

TEST(TEST_Queue, TestYard) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_queue(false));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

