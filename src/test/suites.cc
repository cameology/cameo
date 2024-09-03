#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <kernels/constant.h>
#include <kernels/exception.cc>
#include <frontend/lexer.h>



TEST(TokenAssertion, IntAssertionAsInt) {
    Lexer lexer;
    std::string line    = "int a = 1;";
    auto node           = lexer.serialize(line);

    // Positive case
    EXPECT_EQ(node.value.type, "int");
    EXPECT_EQ(node.id.name, "a");
    EXPECT_EQ(node.value.raw, "1");

    // Put string as integer
    line = "int a = 1";
    EXPECT_THROW(lexer.serialize(line), Exception::UnexpectedToken);
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
    const std::string line  = "boolean bl = true;";

    Lexer lexer;
    auto node = lexer.serialize(line);

    EXPECT_EQ(node.value.type, "boolean");
    EXPECT_EQ(node.id.name, "bl");
    EXPECT_EQ(node.value.raw, "true");
}

TEST(TokenAssertion, StringAssertion) {
    const std::string line  = "string a = \"kata kata\";";

    Lexer lexer;
    auto node = lexer.serialize(line);

    EXPECT_EQ(node.value.type, "string");
    EXPECT_EQ(node.id.name, "a");
    EXPECT_EQ(node.value.raw, "\"kata kata\"");
}
