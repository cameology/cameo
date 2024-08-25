#include <string>
#include <gtest/gtest.h>

#include <kernels/constant.h>
#include <frontend/Lexer.h>



TEST(TokenAssertion, IntAssertionAsInt) {
    const std::string line  = "int a = 1";
    Lexer lexer;
}

TEST(TokenAssertion, IntAssertionAsFloat) {
    const std::string line  = "int a = 1.0";
    EXPECT_EQ(line, "int a = 1.0");
}

TEST(TokenAssertion, IntAssertionAsBoolean) {
    const std::string line  = "int a = true";
    EXPECT_EQ(line, "int a = true");
}

TEST(TokenAssertion, IntAssertionAsString) {
    const std::string line  = "int a = \"1\"";
    EXPECT_EQ(line, "int a = \"1\"");
}
