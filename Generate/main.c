#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrcodegen.h"

void printQr(const uint8_t qrcode[], char* url, char* text1, char* text2, char* text3, char* text4, char* text5, char* text6) {
    FILE *deposit = fopen(url, "w+");
    fputs(text1, deposit);
    fputs("\n", deposit);
    fputs(text2, deposit);
    fputs("\n", deposit);
    fputs(text3, deposit);
    fputs("\n", deposit);
    fputs(text4, deposit);
    fputs("\n", deposit);
    fputs(text5, deposit);
    fputs("\n", deposit);
    fputs(text6, deposit);
    fputs("\n", deposit);
	int size = qrcodegen_getSize(qrcode);
	int border = 4;
	for (int y = -border; y < size + border; y++) {
		for (int x = -border; x < size + border; x++) {
			fputs((qrcodegen_getModule(qrcode, x, y) ? "##" : "  "), deposit);
		}
		fputs("\n", deposit);
	}
	fputs("\n", deposit);
	fclose(deposit);
}

int doBasicDemo(char* text1, char* text2, char* text3, char* text4, char* text5, char* text6) {
    char* url = "user.txt";
    uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    bool ok;

    char *concat = calloc(strlen(text1) + strlen(text2) + strlen(text3) + strlen(text4) + strlen(text5) + strlen(text6) + 1, sizeof(char));
    strcat(concat, text1);
    strcat(concat, text2);
    strcat(concat, text3);
    strcat(concat, text4);
    strcat(concat, text5);
    strcat(concat, text6);
    ok = qrcodegen_encodeText(concat, tempBuffer, qrcode, qrcodegen_Ecc_LOW,
        qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
    if (ok)
        printQr(qrcode, url, text1, text2, text3, text4, text5, text6);
    free(concat);

}


int main(int argc, char **argv){

    doBasicDemo(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);

}




