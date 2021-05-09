#include <iostream>


class Btree {
    public:
        std::string val;
        Btree* left;
        Btree* right;

        Btree(std::string val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }

        int evaluate() {
            if(this->val == "*") {
                return this->left->evaluate() * this->right->evaluate();
            }else  if(this->val == "-") {
                return this->left->evaluate() - this->right->evaluate();
            }
            else  if(this->val == "/") {
                return this->left->evaluate() / this->right->evaluate();
            }else  if(this->val == "+") {
                return this->left->evaluate() + this->right->evaluate();
            } else {
                return std::stoi(this->val);
            }
        }
};

int main() {
    Btree* root = new Btree("*");
    root->left = new Btree("+");
    root->right = new Btree("+");
    root->left->left = new Btree("3");
    root->left->right = new Btree("2");
    root->right->right = new Btree("5");
    root->right->left = new Btree("4");

    std::cout<<"answer:"<<root->evaluate()<<std::endl;
    return 0;
}