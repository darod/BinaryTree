#include "BinaryTree.hpp"
#include <limits>
#include "Node.h"

namespace Autodesk
{
namespace
{

auto isLeftLessOrEq =   [](const Node* const node) {return node->left->value <= node->value;};
auto isLeftGraterThan = [](const Node* const node, int value) {return node->left->value > value;};
auto isRightGreater =   [](const Node* const node) {return node->right->value > node->value;};
auto isRightLessOrEqThan = [](const Node* const node, int value) {return node->right->value <= value;};
auto isNodeNotEmpty =   [](const Node* const node) {return node != nullptr;};



bool isNodeSorted(const Node* const node, int min, int max)
{
    if(isNodeNotEmpty(node->left))
    {
        if(not( isLeftLessOrEq(node) and
                isLeftGraterThan(node, min) and
                isNodeSorted(node->left, min, node->value) ))
        {
            return false;
        }
    }

    if(isNodeNotEmpty(node->right))
    {
        if(not( isRightGreater(node) and
                isRightLessOrEqThan(node, max) and
                isNodeSorted(node->right, node->value, max) ))
        {
            return false;
        }
    }

    return true;
}

}

bool isBinaryTreeSorted(const Node* const root)
{
    return isNodeNotEmpty(root) and
           isNodeSorted(root,
                        std::numeric_limits<int>::min(),
                        std::numeric_limits<int>::max());
}

}
