#include "BinaryExpr.h"
#include <memory>

BinaryExpr::BinaryExpr (void):
    rightChild(nullptr),
    leftChild(nullptr),
    Parent(nullptr)
    {

    }

BinaryExpr::~BinaryExpr (void)
    {
        //PROXY PATTERN TAKES CARE OF DESTRUCTION
    }

std::shared_ptr<Expr_Node> BinaryExpr::getRightChild(void)    //shared_ptr used for Proxy Pattern
    {
        return this->rightChild;
    }

std::shared_ptr<Expr_Node> BinaryExpr::getLeftChild(void) //shared_ptr used for Proxy Pattern
    {
        return this->leftChild;
    }

void BinaryExpr::setRightChild(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->rightChild = node;
    }

void BinaryExpr::setLeftChild(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->leftChild = node;
    }

std::shared_ptr<Expr_Node> BinaryExpr::getParent(void) //shared_ptr used for Proxy Pattern
    {
        return this->Parent;
    }

void BinaryExpr::setParent(std::shared_ptr<Expr_Node> node) //shared_ptr used for Proxy Pattern
    {
        this->Parent = node;
    }
