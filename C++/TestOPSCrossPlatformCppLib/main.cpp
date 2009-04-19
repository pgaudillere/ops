/* 
 * File:   main.cpp
 * Author: Anton Gravestam
 *
 * Created on den 22 oktober 2008, 21:09
 */
#include <stdio.h>
#include <stdlib.h>
#include <UDPSender.h>
#include <string>
/*
 * 
 */
int main(int argc, char** argv)
{

    ops::UDPSender sender;
    //std::cout << "Hit " <<
    sender.getPort();
    char* bytes = new char[100];
    ops::ByteBuffer buf(bytes);

    buf.WriteString("Hejsan boost varlden!");
    
    for (int i = 0; i < 10; i++)
    {
        sender.sendTo(&buf, std::string("236.0.0.1"), 30001);

    }

    

    return (EXIT_SUCCESS);
}

