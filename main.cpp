#include <iostream>
#include <memory>

struct Btree {
        std::string val;
        std::unique_ptr<Btree> left;
        std::unique_ptr<Btree> right;

        Btree(std::string val) {
            this->val = val; this->left = NULL; this->right = NULL;
        }
        
        int evaluate() {
            if(this->val == "*") {
                return this->left->evaluate() * this->right->evaluate();
            }
            else  if(this->val == "-") {
                return this->left->evaluate() - this->right->evaluate();
            }
            else  if(this->val == "/") {
                return this->left->evaluate() / this->right->evaluate();
            }
            else  if(this->val == "+") {
                return this->left->evaluate() + this->right->evaluate();
            } 
            else {
                return std::stoi(this->val);
            }
        }
};

int main() {
    std::unique_ptr<Btree> root = std::make_unique<Btree>("*");
    root->left = std::make_unique<Btree>("+");
    root->right = std::make_unique<Btree>("+");
    root->left->left = std::make_unique<Btree>("3");
    root->left->right = std::make_unique<Btree>("2");
    root->right->right = std::make_unique<Btree>("5");
    root->right->left = std::make_unique<Btree>("4");
    std::cout<<"answer:"<<root->evaluate()<<std::endl;
    return 0;
}