#include "ast.h"

#include <string>
#include <stdexcept>



namespace AbstractSyntaxTree {
    Identifier::~Identifier() {}
    Identifier::Identifier() {}
    Identifier::Identifier(std::string name) {
        this->name = name;
    }

    Value::~Value() {}
    Value::Value() {}
    Value::Value(std::string type) {
        this->type = type;
    }

    Value::Value(std::string type, std::string raw) {
        this->type  = type;
        this->raw   = raw;
    }

    void Value::setRaw(std::string raw) {
        this->raw = raw;
    }

    VariableNode::VariableNode() {}
    VariableNode::~VariableNode() {}
    VariableNode::VariableNode(int from, int to, Identifier id, Value value) {
        this->from  = from;
        this->to    = to;
        this->id    = id;
        this->value = value;
    }

    Node::~Node () {}
    Node::Node() { throw std::invalid_argument("missing required \"from\", \"to\", \"type\" params"); }
    Node::Node(int from, int to, std::string type) {
        if (type == "") {
            throw std::invalid_argument("type cannot be an empty string");
        }

        this->from  = from;
        this->to    = to;
        this->type  = type;
    }

    Node::Node(std::vector<Node> body) {
        this->body = body;
    }
}
