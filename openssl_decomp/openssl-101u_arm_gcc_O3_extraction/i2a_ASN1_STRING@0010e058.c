
int i2a_ASN1_STRING(BIO *bp,ASN1_STRING *a,int type)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char local_24;
  char local_23;
  
  if (a == (ASN1_STRING *)0x0) {
    return 0;
  }
  if (a->length == 0) {
    iVar3 = BIO_write(bp,"0",1);
    if (iVar3 == 1) {
      return 1;
    }
  }
  else {
    if (a->length < 1) {
      return 0;
    }
    iVar4 = 0;
    iVar3 = 0;
    do {
      do {
        iVar5 = iVar3;
        local_24 = "0123456789ABCDEF"[a->data[iVar4] >> 4];
        pbVar1 = a->data + iVar4;
        iVar4 = iVar4 + 1;
        local_23 = "0123456789ABCDEF"[*pbVar1 & 0xf];
        iVar2 = BIO_write(bp,&local_24,2);
        iVar3 = iVar5 + 2;
        if (iVar2 != 2) {
          return -1;
        }
        if (a->length <= iVar4) {
          return iVar3;
        }
      } while ((iVar4 == 0) || (iVar4 != (iVar4 / 0x23) * 0x23));
      iVar2 = BIO_write(bp,&DAT_00162354,2);
      iVar3 = iVar5 + 4;
    } while (iVar2 == 2);
  }
  return -1;
}

