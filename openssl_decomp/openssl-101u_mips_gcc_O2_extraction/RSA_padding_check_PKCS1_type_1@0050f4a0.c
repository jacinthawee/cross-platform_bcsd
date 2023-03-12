
int RSA_padding_check_PKCS1_type_1(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  undefined4 uVar1;
  uchar *puVar2;
  undefined4 uVar3;
  uchar *puVar4;
  int iVar5;
  uchar uVar6;
  int iVar7;
  
  if ((fl + 1 != rsa_len) || (puVar2 = f + 1, *f != '\x01')) {
    uVar3 = 0x6a;
    uVar1 = 0x67;
    goto LAB_0050f580;
  }
  iVar7 = fl + -1;
  if (iVar7 < 1) {
    if (iVar7 == 0) {
LAB_0050f5ac:
      uVar3 = 0x71;
      uVar1 = 0x7d;
      goto LAB_0050f580;
    }
  }
  else {
    uVar6 = f[1];
    puVar4 = f + fl;
    if (uVar6 == 0xff) {
      iVar5 = 0;
      do {
        puVar2 = puVar2 + 1;
        iVar5 = iVar5 + 1;
        if (puVar2 == puVar4) {
          if (iVar7 != iVar5) goto LAB_0050f518;
          goto LAB_0050f5ac;
        }
        uVar6 = *puVar2;
      } while (uVar6 == 0xff);
    }
    else {
      iVar5 = 0;
    }
    if (uVar6 != '\0') {
      uVar3 = 0x66;
      uVar1 = 0x74;
      goto LAB_0050f580;
    }
    puVar4 = puVar2 + 1;
LAB_0050f518:
    if (7 < iVar5) {
      iVar7 = iVar7 - (iVar5 + 1);
      if (iVar7 <= tlen) {
        (*(code *)PTR_memcpy_006a9aec)(to,puVar4,iVar7);
        return iVar7;
      }
      uVar3 = 0x6d;
      uVar1 = 0x89;
      goto LAB_0050f580;
    }
  }
  uVar3 = 0x67;
  uVar1 = 0x83;
LAB_0050f580:
  (*(code *)PTR_ERR_put_error_006a7f34)(4,0x70,uVar3,"rsa_pk1.c",uVar1);
  return -1;
}

