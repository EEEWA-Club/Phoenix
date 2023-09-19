#include <gtest/gtest.h>
#include "protocol.h"

// Define a test case for sending a message
TEST(PhoenixProtocolTest, SendMessage) {
    // Create a PhoenixUARTMessage
    PhoenixUARTMessage message;
    message.start_marker = PHOENIX_UART_START_MARKER;
    message.module_number = 1;
    message.payload_size = 4;
    message.payload[0] = 0x11;
    message.payload[1] = 0x22;
    message.payload[2] = 0x33;
    message.payload[3] = 0x44;
    // Calculate and set the checksum (you need to implement this)
    message.checksum = calculate_checksum(&message);

    // Call phoenix_protocol_send_message and capture the return value
    int result = phoenix_protocol_send_message(&message);

    // Check if the message was sent successfully
    EXPECT_EQ(result, 0); // Assuming 0 means success, adjust as needed
}

// Define a test case for receiving a message
TEST(PhoenixProtocolTest, ReceiveMessage) {
    // Create a PhoenixUARTMessage to simulate a received message
    PhoenixUARTMessage received_message;
    received_message.start_marker = PHOENIX_UART_START_MARKER;
    received_message.module_number = 2;
    received_message.payload_size = 3;
    received_message.payload[0] = 0xAA;
    received_message.payload[1] = 0xBB;
    received_message.payload[2] = 0xCC;
    // Calculate and set the checksum (you need to implement this)
    received_message.checksum = calculate_checksum(&received_message);

    // Call phoenix_protocol_receive_message and capture the return value
    int result = phoenix_protocol_receive_message(&received_message);

    // Check if the message was received and processed successfully
    EXPECT_EQ(result, 0); // Assuming 0 means success, adjust as needed
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
