#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * fp = NULL;
	char filename[] = "coffee.bmp";
	unsigned int offset,padding=0;
	unsigned int file_size;
	char colore[3] = {0, 0, 255}; //R=0, G=0, B=255
	// chiedo il nome del file
	//printf("Inserire nome file:");
	//scanf("%s", filename);
	// apro il file in lettura/scrittura binaria
	fp = fopen(filename, "r+b");
	if (fp == NULL)
	{
		printf("impossibile aprire il file %s\n", filename);
		return 1;
	}

	fseek(fp, 2, SEEK_SET);
	offset = ftell(fp);
	printf("posizione %u\n", offset);

	fread(&file_size, 4, 1, fp);
	printf("file size %u\n", file_size);

	fseek(fp, 4, SEEK_CUR);
	unsigned int pixel_position;
	fread(&pixel_position, 4, 1, fp);
	printf("i pixel cominciano all'offset %u\n", pixel_position);

	fseek(fp, 4, SEEK_CUR);
	unsigned int width, height;
	fread(&width, 4, 1, fp);
	fread(&height, 4, 1, fp);
	printf("dimensione immagine %u righe x %u colonne\n", width, height);
	fseek(fp, 2, SEEK_CUR);
	unsigned int bits_per_pixel = 0;
	fread(&bits_per_pixel, 2, 1, fp);
	printf("bit per pixel %u\n", bits_per_pixel);
	if (bits_per_pixel != 24)
	{
		printf("errore, bit per pixel deve essere 24\n");
		return 1;
	}
	unsigned int byte_per_pixel = bits_per_pixel / 8;
	printf("byte_per_pixel %u\n", byte_per_pixel);

	unsigned int byte_per_riga = byte_per_pixel * width;
	if (byte_per_riga % 4 != 0)
	{
		padding = 4 - (byte_per_riga % 4);
		byte_per_riga += padding;
		printf("non e' multiplo di 4\n");
		printf("padding %u\n", padding);
		printf("byte per riga %u\n", byte_per_riga);
	}

	fseek(fp, pixel_position, SEEK_SET);
	offset = ftell(fp);
	printf("posizione %u\n", offset);

	fseek(fp, (height/2) * byte_per_riga, SEEK_CUR);


	for (int i = 0; i < 25; i++)
	{
		for (int pix = 0; pix < width; pix++)
		{
			fwrite(colore, 3, 1, fp);
		}
		fseek(fp, padding, SEEK_CUR);
	}

	fclose(fp);
	return 0;
}
