
void BUF_reverse(uchar *out,uchar *in,size_t siz)

{
  uchar uVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  if (in == (uchar *)0x0) {
    if (siz >> 1 != 0) {
      puVar2 = out + (siz - 1);
      puVar3 = out;
      do {
        puVar4 = puVar3 + 1;
        uVar1 = *puVar2;
        *puVar2 = *puVar3;
        *puVar3 = uVar1;
        puVar2 = puVar2 + -1;
        puVar3 = puVar4;
      } while (puVar4 != out + (siz >> 1));
      return;
    }
  }
  else {
    puVar2 = out + (siz - 1);
    puVar3 = in;
    if (siz != 0) {
      do {
        puVar4 = puVar3 + 1;
        *puVar2 = *puVar3;
        puVar2 = puVar2 + -1;
        puVar3 = puVar4;
      } while (in + siz != puVar4);
    }
  }
  return;
}

