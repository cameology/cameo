#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <kernels/constant.h>
#include <kernels/exception.cc>
#include <frontend/lexer.h>



TEST(TokenAssertion, IntAssertion) {
    Lexer lexer;
    std::string line    = "int a = 1;";
    auto node           = lexer.serialize(line);

    // Positive case
    EXPECT_EQ(node.value.type, "int");
    EXPECT_EQ(node.id.name, "a");
    EXPECT_EQ(node.value.raw, "1");

    // Put float as integer
    line = "int a = 1.5;";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);

    // Put string as integer
    line = "int a = \"stringg\";";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);

    // Put boolean as integer
    line = "int a = true;";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);
}

TEST(TokenAssertion, FloatAssertion) {
    const std::string line  = "float fl = 1.0;";

    Lexer lexer;
    auto node = lexer.serialize(line);

    EXPECT_EQ(node.value.type, "float");
    EXPECT_EQ(node.id.name, "fl");
    EXPECT_EQ(node.value.raw, "1.0");
}

TEST(TokenAssertion, BooleanAssertion) {
    Lexer lexer;
    std::string line  = "boolean bl = true;";
    auto node = lexer.serialize(line);

    // Positive case
    EXPECT_EQ(node.value.type, "boolean");
    EXPECT_EQ(node.id.name, "bl");
    EXPECT_EQ(node.value.raw, "true");

    // Put integer as boolean
    line = "boolean a = 1;";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);

    // Put float as boolean
    line = "boolean a = 1.5;";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);

    // Put string as boolean
    line = "boolean a = \"true\";";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);
}

TEST(TokenAssertion, StringAssertion) {
    Lexer lexer;
    std::string line    = "string a = \"kata kata\";";
    auto node           = lexer.serialize(line);

    // Positive case
    EXPECT_EQ(node.value.type, "string");
    EXPECT_EQ(node.id.name, "a");
    EXPECT_EQ(node.value.raw, "\"kata kata\"");

    // Put integer as string
    line = "string a = 1;";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);
    
    // Put float as string
    line = "string a = 1.3;";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);

    // Put boolean as string
    line = "string a = true;";
    EXPECT_THROW(lexer.serialize(line), Exception::InvalidDatatype);

    // Put string as without quotes
    line = "string a = stringg sdfsdaf;";
    EXPECT_THROW(lexer.serialize(line), Exception::UnexpectedToken);
}

TEST(TokenAssertion, UnexpectedToken) {
    const std::string line  = "string a = \"kata kata\"";

    Lexer lexer;
    EXPECT_THROW(lexer.serialize(line), Exception::UnexpectedToken);
}