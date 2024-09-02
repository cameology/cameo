#ifndef AST_H
#define AST_H

#include <string>
#include <vector>



namespace AbstractSyntaxTree {
    class Root {
        public:
            int from;
            int to;
            std::string type;
    };

    class Identifier : Root {
        public:
            std::string type = "Identifier";
            std::string name;

            Identifier();
            Identifier(std::string name);

            ~Identifier();
    };

    class Value : Root {
        public:
            std::string type = "Value";
            std::string raw;

            Value();
            Value(std::string type);
            Value(std::string type, std::string raw);
            void setRaw(std::string raw);

            ~Value();
    };

    class VariableNode : Root {
        public:
            std::string type = "Variable";
            Identifier id;
            Value value;

            VariableNode();
            VariableNode(int from, int to, Identifier id, Value value);
            ~VariableNode();
    };

    class Node : Root {
        public:
            std::vector<Node> body;

            Node();
            Node(int from, int to, std::string type);
            Node(std::vector<Node> body);

            ~Node();
    };
};

#endif
