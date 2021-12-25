/**
 * @file Cipher.cpp
 *
 * @brief Assignment 2 Natrl Foundtn
 *
 * @author Group 14
 * Abdul Shahid     100709858
 * Md Fardin Rahman 100704517
 * Osamah Al-Bayati 100782415
 * 
 */

#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<cstring>
#include<istream>
using namespace std;

void encrypt_caesar() {
    string text;
    cout << "Enter text: ";
    cin.ignore(1,'\n');
    getline(cin, text);
    string cipher, cipherP;
    int c, e, k = 7;
    for(int i = 0; i < text.length(); i++) {
        c = int(text[i]);
        if (text[i] == 32) {
            cipher += 32;
        } else {
            e = (c - '0' + k )%75 + '0';
            cipher += e;

        }
       
       cipherP = cipher;

    }
    cout << "The Cipher text is: " << cipherP;
}

void decrypt_caesar() {
    string text;  
    cout << "Enter text: ";
    cin.ignore(1,'\n');
    getline(cin, text);
    string cipher, cipherP;
    int c, e, k = 7;
    for(int i = 0; text[i] != '\0'; i++) {

        c = int(text[i]);
        
        if (text[i] == 32) {

            cipher += 32;
        }else if (c >= '0' && c<= ('0' + k - 1)) {

            e = (c - '0' - k)%75 + 75 + '0';
            cipher += e;
        } else {

            e = (c - '0' - k )%75 + '0';
            cipher += e;
        }

        cipherP = cipher;

    }
    cout << "The Cipher text is: " << cipherP;
}

void encrypt_vigenere () {
    string text;
    cout << "Enter text : ";
    cin.ignore(1,'\n');
    getline(cin, text);
    int m = 0;
    while (text[m]) {
        if (isalpha(text[m]) || text[m] == ' ') {
            if (isupper(text[m])) {
            text[m] = tolower(text[m]);
            }
        } else {
            cout << "Error! Input Must Be Alphabetical!";
            return;
        }
        m++;
    }
    string cipher, cipherP;
    int c, e;
    char key;
    cout << "Enter key (a-z):";
    cin >> key; 
    int k = (int)key;
    for(int i = 0; i < text.length(); i++) {
        c = int(text[i]);
        if (text[i] == 32) {
            cipher += 32;
        } else if (c >= (111 - (k - 'a')) && c <= (122 - (k - 'a'))) {
            e = ((c + k) % 26) + 111;
            cipher += e;
        } else if (c < (111 - (k - 'a')) || c > (122 - (k - 'a'))) {
            e = ((c + k) % 26) + 85;
            cipher += e;
        }
       
       cipherP = cipher;

    }
    cout << cipherP;
}

void decrypt_vigenere () {
    string text;  
    cout << "Enter text: ";
    cin.ignore(1,'\n');
    getline(cin, text);
    int m = 0;
    while (text[m]) {
        if (isalpha(text[m]) || text[m] == ' ') {
            if (isupper(text[m])) {
            text[m] = tolower(text[m]);
            }
        } else {
            cout << "Error! Input Must Be Alphabetical!";
            return;
        }
        m++;
    }
    string cipher, cipherP;
    int c, e;
    char key;
    cout << "Enter key (a-z):";
    cin >> key; 
    int k = (int)key;
    for(int i = 0; text[i] != '\0'; i++) {
        c = int(text[i]);
        if (text[i] == 32) {
            cipher += 32;
        } else {
            e = (c - k + 26) % 26 + 'a';
            cipher += e;
        }

        cipherP = cipher;

    }
    cout << "The Cipher text is: " << cipherP;
}

int main() {
    int selection_1, selection_2;

    cout << "Please enter your selection: " << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cin >> selection_1;


        switch(selection_1) {
            case 1: 
                cout << "Encrypt: " << endl;
                cout << "Which cipher to use?" << endl;
                cout << "1. Caesar cipher" << endl;
                cout << "2. Vigenere cipher" << endl;
                cin >> selection_2;
                switch(selection_2) {
                    case 1: 
                        encrypt_caesar();
                    break;
                    case 2: 
                        encrypt_vigenere();
                    break;
                    default:
                        cout << "Invalid! Enter 1 or 2" << endl;
                        cin.ignore(1,'\n');
                        main();
                    break;
                }
            break;
            case 2: 
                cout << "Decrypt: " << endl;
                cout << "Which cipher to use?" << endl;
                cout << "1. Caesar cipher" << endl;
                cout << "2. Vigenere cipher" << endl;
                cin >> selection_2;
                switch(selection_2) {
                    case 1: 
                        decrypt_caesar();
                    break;
                    case 2: 
                        decrypt_vigenere();
                    break;
                    default:
                        cout << "Invalid! Enter 1 or 2" << endl;
                        cin.ignore(1,'\n');
                        main();
                    break;
                }
            break;  
            default: 
                cout << "Invalid! Enter 1 or 2" << endl;
                main();
            break;
        }
    return 0;
}    