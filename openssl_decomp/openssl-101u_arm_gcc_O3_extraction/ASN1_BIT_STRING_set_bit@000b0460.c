
int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a,int n,int value)

{
  uint uVar1;
  size_t __n;
  uchar *puVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  int num;
  
  uVar1 = n & ~(n >> 0x20);
  if (n < 0) {
    uVar1 = n + 7;
  }
  bVar4 = (byte)(1 << (~n & 7U));
  iVar3 = (int)uVar1 >> 3;
  bVar5 = bVar4;
  if (value == 0) {
    bVar5 = 0;
  }
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  a->flags = a->flags & 0xfffffff0;
  if ((a->length <= iVar3) || (puVar2 = a->data, puVar2 == (uchar *)0x0)) {
    if (value == 0) {
      return 1;
    }
    num = iVar3 + 1;
    if (a->data == (uchar *)0x0) {
      puVar2 = (uchar *)CRYPTO_malloc(num,"a_bitstr.c",0xd0);
    }
    else {
      puVar2 = (uchar *)CRYPTO_realloc_clean(a->data,a->length,num,"a_bitstr.c",0xd3);
    }
    if (puVar2 == (uchar *)0x0) {
      ERR_put_error(0xd,0xb7,0x41,"a_bitstr.c",0xd5);
      return 0;
    }
    __n = num - a->length;
    if (0 < (int)__n) {
      memset(puVar2 + a->length,0,__n);
    }
    a->data = puVar2;
    a->length = num;
  }
  puVar2[iVar3] = bVar5 | puVar2[iVar3] & ~bVar4;
  iVar3 = a->length;
  if (0 < iVar3) {
    do {
      if (a->data[iVar3 + -1] != '\0') {
        return 1;
      }
      iVar3 = iVar3 + -1;
      a->length = iVar3;
    } while (iVar3 != 0);
  }
  return 1;
}

