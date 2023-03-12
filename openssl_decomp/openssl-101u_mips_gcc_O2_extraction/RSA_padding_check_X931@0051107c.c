
int RSA_padding_check_X931(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((rsa_len != fl) || (1 < *f - 0x6a)) {
    iVar4 = 0x89;
    iVar6 = 0x70;
    goto LAB_00511180;
  }
  puVar3 = f + 1;
  if (*f == 0x6b) {
    iVar6 = rsa_len + -3;
    if (0 < iVar6) {
      uVar1 = f[1];
      if (uVar1 != 0xba) {
        iVar4 = 0;
        puVar2 = f + 2;
        do {
          if (uVar1 != 0xbb) {
            iVar4 = 0x8a;
            iVar6 = 0x7b;
            goto LAB_00511180;
          }
          iVar4 = iVar4 + 1;
          puVar3 = puVar2;
          iVar5 = iVar6;
        } while ((iVar4 != iVar6) &&
                (uVar1 = *puVar2, puVar3 = puVar2 + 1, iVar5 = iVar4, puVar2 = puVar2 + 1,
                uVar1 != 0xba));
        iVar6 = iVar6 - iVar5;
        if (iVar5 != 0) goto LAB_005110bc;
      }
    }
    iVar4 = 0x8a;
    iVar6 = 0x83;
  }
  else {
    iVar6 = rsa_len + -2;
LAB_005110bc:
    if (puVar3[iVar6] == 0xcc) {
      (*(code *)PTR_memcpy_006a9aec)(to,puVar3,iVar6);
      return iVar6;
    }
    iVar4 = 0x8b;
    iVar6 = 0x8b;
  }
LAB_00511180:
  ERR_put_error(4,0x80,iVar4,"rsa_x931.c",iVar6);
  return -1;
}

