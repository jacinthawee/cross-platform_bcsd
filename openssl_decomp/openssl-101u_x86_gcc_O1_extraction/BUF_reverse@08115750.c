
void BUF_reverse(uchar *out,uchar *in,size_t siz)

{
  uchar uVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  if (in == (uchar *)0x0) {
    if (siz >> 1 != 0) {
      puVar3 = out + (siz - 1);
      puVar4 = out;
      do {
        uVar1 = *puVar3;
        puVar2 = puVar4 + 1;
        *puVar3 = *puVar4;
        *puVar4 = uVar1;
        puVar3 = puVar3 + -1;
        puVar4 = puVar2;
      } while (puVar2 != out + (siz >> 1));
      return;
    }
  }
  else {
    puVar4 = out + (siz - 1);
    puVar3 = in + siz;
    if (siz != 0) {
      do {
        puVar2 = in + 1;
        *puVar4 = *in;
        in = puVar2;
        puVar4 = puVar4 + -1;
      } while (puVar3 != puVar2);
    }
  }
  return;
}

