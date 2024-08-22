#include <gtest/gtest.h>

#include <constant.h>


TEST(Token, TokenAssertion) {
    EXPECT_EQ(Token::str(Token::Keyword::If), "If");
}
