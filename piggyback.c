#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for the data packet
typedef struct {
    int sequenceNumber;
    char data[100];
} Packet;

// Function to send the data packet
void sendPacket(Packet packet) {
    printf("Sending packet with sequence number %d\n", packet.sequenceNumber);
    // Code for sending the packet over the network
}

// Function to receive the acknowledgement
void receiveAck(int ackNumber) {
    printf("Received acknowledgement for sequence number %d\n", ackNumber);
    // Code for processing the acknowledgement
}

int main() {
    // Simulating data transmission
    Packet dataPacket;
    dataPacket.sequenceNumber = 1;
    printf(dataPacket.data, "Sample data");

    bool ackReceived = false;
    int ackNumber;

    // Piggybacking the acknowledgement with the data packet
    sendPacket(dataPacket);

    // Simulating the reception of the data packet at the receiver
    // Here, the receiver extracts the sequence number and data from the received packet
    int receivedSequenceNumber = dataPacket.sequenceNumber;
    char receivedData[100];
    printf(receivedData, "%s", dataPacket.data);

    // Simulating the acknowledgement generation by the receiver
    ackNumber = receivedSequenceNumber;
    ackReceived = true;

    // Piggybacking the acknowledgement with the next data packet to be sent
    Packet nextDataPacket;
    nextDataPacket.sequenceNumber = receivedSequenceNumber + 1;
    sprintf(nextDataPacket.data, "Next data");

    if (ackReceived) {
        sendPacket(nextDataPacket);
        receiveAck(ackNumber);
    }

    return 0;
}