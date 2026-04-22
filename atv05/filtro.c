#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREAD 4

int main() {
  int w, h, max_v;
  unsigned char *pixels;

  FILE *file = fopen("lena.pgm", "rb"); //lê
  if (!file) return 1;

  fscanf(file, "%*s %d %d %d", &w, &h, &max_v);
  fgetc(file);

  pixels = malloc(w * h);
  fread(pixels, 1, w * h, file);
  fclose(file);

  // O "parallel for" divide o trabalho automaticamente 
  #pragma omp parallel for schedule(static) num_threads(NUM_THREAD)
  for (int i = 0; i < w * h; i++) {
    int nv = pixels[i] + 50;
    pixels[i] = (unsigned char)(nv > 255 ? 255 : (nv < 0 ? 0 : nv));
    }

  file = fopen("lena.pgm", "wb"); //escreve
  if (!file) return 1;

  //Escreve o cabeçalho P5 (binário)
  fprintf(file, "P5\n%d %d\n%d\n", w, h, max_v);
  //Escreve os pixels modificados
  fwrite(pixels, 1, w * h, file);
  fclose(file);

  printf("lena.pgm atualizada!!!\n");

  free(pixels);
  return 0;
}