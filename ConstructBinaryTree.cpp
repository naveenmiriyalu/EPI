/*
Author		:Naveen M
Date		:Feb 1st 2015
Description :Program to create a binary tree from inorder and preorder 
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<exception>
#include<stdexcept>
#include<stdio.h>
#include<stdlib.h>
class UniqueBinaryTree
{
  private:
  class Node {
   public:
   int data;
   class Node *left;
   class Node *right;
   Node(int d = 0,class Node *l=NULL, class Node *r=NULL): data(d),left(l),right(r){}
  };

  public:
  UniqueBinaryTree(std::string inorder_filename = "",std::string preorder_filename= "")
  {
    readArray(inorder_filename,I); 
    readArray(preorder_filename,P); 
  }

  void printInorder();
  void printPreorder();

  private:
  std::vector<int> P,I;
  typedef std::vector<int>::const_iterator const_iterator;
  typedef std::vector<int>::iterator iterator;
  void readArray(std::string filename,std::vector<int> &array);
  void printArray(const std::vector<int> &array,const std::string &title);
  Node* ConstructBinaryTree(const_iterator ibeg,const_iterator iend,const_iterator pbeg,const_iterator pend)
  {
  	Node* newNode;
  	if(ibeg == (iend-1))
  	{
	 int element = *ibeg;
     newNode = new Node(element);
	 
  	}
  	else
  	{
     int subtree_root = *pbeg;
	 std::vector<int>::const_iterator pos = findRootPos(ibeg,iend,subtree_root);
	 newNode = new Node(subtree_root);
  	}
   return newNode;
  }
  const_iterator findRootPos(const_iterator ibeg,const_iterator iend,int subtree_root);
  Node *root;
};


const_iterator UniqueBinaryTree::findRootPos(const_iterator ibeg,const_iterator iend,int subtree_root)
{
  for(std::vector<int>::const_iterator it = ibeg; it != iend; ++it)
  	if(*it == subtree_root)
		return it;
}

void UniqueBinaryTree::printInorder()
{
	printArray(I,"Inorder");
}
void UniqueBinaryTree::printPreorder()
{
	printArray(P,"Preorder");
}

void UniqueBinaryTree::printArray(const std::vector<int> &array,const std::string &title)
{
  std::cout << "---" << title << "---" << std::endl;
  for(std::vector<int>::const_iterator it = array.begin(); it != array.end(); ++it)
  	std::cout << *it << ",";
	std::cout << std::endl;
	std::cout << "Size=" << array.size() << std::endl;
}

void UniqueBinaryTree::readArray(std::string filename,std::vector<int> &v)
{
  std::ifstream infile;
  try {
      infile.open(filename.c_str());
	  if(infile)
	  {
	    int ival;
	    while(infile >> ival,!infile.eof())
		{
		  v.push_back(ival);
		}
	  }
	  else
	  {
	    std::cerr << "Unable to open file " << std::endl;
		throw std::runtime_error("Opening files failed");
	  }
	  infile.close();
  } 
  catch(...){
      exit(-1); 
     
  }
  
}

int main()
{
 UniqueBinaryTree BT("inorder.txt","preorder.txt");
 BT.printInorder();
 BT.printPreorder();
}
