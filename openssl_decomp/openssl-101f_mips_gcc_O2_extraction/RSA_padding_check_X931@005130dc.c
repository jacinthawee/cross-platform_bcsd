
int RSA_padding_check_X931(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  uchar *puVar2;
  undefined4 uVar3;
  int iVar4;
  uchar *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  if ((rsa_len != fl) || (1 < *f - 0x6a)) {
    uVar6 = 0x89;
    uVar3 = 0x72;
    goto LAB_005131e0;
  }
  puVar5 = f + 1;
  if (*f == 0x6b) {
    iVar8 = rsa_len + -3;
    if (0 < iVar8) {
      uVar1 = f[1];
      if (uVar1 != 0xba) {
        iVar4 = 0;
        puVar2 = f + 2;
        do {
          if (uVar1 != 0xbb) {
            uVar6 = 0x8a;
            uVar3 = 0x81;
            goto LAB_005131e0;
          }
          iVar4 = iVar4 + 1;
          puVar5 = puVar2;
          iVar7 = iVar8;
        } while ((iVar4 != iVar8) &&
                (uVar1 = *puVar2, puVar5 = puVar2 + 1, iVar7 = iVar4, puVar2 = puVar2 + 1,
                uVar1 != 0xba));
        iVar8 = iVar8 - iVar7;
        if (iVar7 != 0) goto LAB_0051311c;
      }
    }
    uVar6 = 0x8a;
    uVar3 = 0x8a;
  }
  else {
    iVar8 = rsa_len + -2;
LAB_0051311c:
    if (puVar5[iVar8] == 0xcc) {
      (*(code *)PTR_memcpy_006aabf4)(to,puVar5,iVar8);
      return iVar8;
    }
    uVar6 = 0x8b;
    uVar3 = 0x93;
  }
LAB_005131e0:
  (*(code *)PTR_ERR_put_error_006a9030)(4,0x80,uVar6,"rsa_x931.c",uVar3);
  return -1;
}

