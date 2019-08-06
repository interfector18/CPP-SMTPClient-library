#include <gtest/gtest.h>
#include "../../Include/PlainTextMessage.h"
#include <stdexcept>
#include <vector>

using namespace jed_utils;
using namespace std;

class SimpleMessage : public ::testing::Test
{
public:
    SimpleMessage()
    {
        msg = new PlaintextMessage(MessageAddress("myfromaddress@test.com", "Test Address Display"),
        MessageAddress("youraddress@domain.com"),
        "This is a test (Subject)",
        "Hello\nHow are you?");
    }

    ~SimpleMessage()
    {
        if (msg)
            delete msg;
    }

    PlaintextMessage *msg;
};

class CompleteMessageWithSimpleConstructor : public ::testing::Test
{
public:
    CompleteMessageWithSimpleConstructor()
    {
        vector<Attachment> att = { Attachment("C:\\Temp\\test.png", "test image.png"), Attachment("C:\\Temp\\test2.png", "test image2.png") };
        msg = new PlaintextMessage(MessageAddress("myfromaddress@test.com", "Test Address Display"),
        MessageAddress("youraddress@domain.com", "DisplayNameTo"),
        "This is a test (Subject)",
        "Hello\nHow are you?",
        vector<MessageAddress> { MessageAddress("myccaddress@domain.com", "myCCName") },
        vector<MessageAddress> { MessageAddress("mybccaddress@domain.com", "myBCCName") },
        att);
        
    }

    ~CompleteMessageWithSimpleConstructor()
    {
        if (msg)
            delete msg;
    }

    PlaintextMessage *msg;
};

TEST(plainTextMessage_SimpleConstructor, validParams)
{
    PlaintextMessage msg(MessageAddress("myfromaddress@test.com", "Test Address Display"),
        MessageAddress("youraddress@domain.com"),
        "This is a test (Subject)",
        "Hello\nHow are you?");
}

TEST(plainTextMessage_ExtendedConstructor, validParams)
{
    vector<MessageAddress> addr_to = { MessageAddress("youraddress@domain.com") };
    PlaintextMessage msg(MessageAddress("myfromaddress@test.com", "Test Address Display"),
        addr_to,
        "This is a test (Subject)",
        "Hello\nHow are you?");
}

//Simple Message fixture tests

TEST_F(SimpleMessage, getFromReturnValid)
{
    ASSERT_EQ(msg->getFrom(), MessageAddress("myfromaddress@test.com", "Test Address Display"));
}

TEST_F(SimpleMessage, getToCountReturnValid)
{
    ASSERT_EQ(msg->getToCount(), 1);
}

TEST_F(SimpleMessage, getToReturnValid)
{
    ASSERT_EQ(msg->getToCount(), 1);
    ASSERT_EQ(msg->getTo()[0], MessageAddress("youraddress@domain.com"));
}

TEST_F(SimpleMessage, getSubjectReturnValid)
{
    ASSERT_EQ(msg->getSubject().compare("This is a test (Subject)"), 0);
}

TEST_F(SimpleMessage, getBodyReturnValid)
{
    ASSERT_EQ(msg->getBody().compare("Hello\nHow are you?"), 0);
}

TEST_F(SimpleMessage, getCcCountReturnValid)
{
    ASSERT_EQ(msg->getCcCount(), 0);
}

TEST_F(SimpleMessage, getCcReturnNull)
{
    ASSERT_TRUE(msg->getCc().empty());
}

TEST_F(SimpleMessage, getAttachmentsCountReturn0)
{
    ASSERT_EQ(msg->getAttachmentsCount(), 0);
}

TEST_F(SimpleMessage, getAttachmentsPtrReturnNull)
{
    ASSERT_TRUE(msg->getAttachments().empty());
}

TEST_F(SimpleMessage, getMimeTypeReturnValidPlainText)
{
    ASSERT_EQ(msg->getMimeType().compare("text/plain"), 0);
}

//End Simple Message fixture tests
