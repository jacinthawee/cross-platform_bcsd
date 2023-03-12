
int RSA_padding_check_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  int iVar2;
  undefined4 uVar3;
  uchar *puVar4;
  uchar *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  if ((fl + 1 == rsa_len) && (iVar2 = fl + -1, *f == '\x02')) {
    if (iVar2 < 1) {
      if (iVar2 == 0) {
LAB_00511920:
        uVar6 = 0x71;
        uVar3 = 0xcc;
        goto LAB_0051198c;
      }
    }
    else if (f[1] != '\0') {
      puVar4 = f + 2;
      iVar7 = 0;
      do {
        iVar8 = iVar7;
        iVar7 = iVar8 + 1;
        puVar5 = puVar4 + 1;
        if (iVar7 == iVar2) goto LAB_00511920;
        uVar1 = *puVar4;
        puVar4 = puVar5;
      } while (uVar1 != '\0');
      if (7 < iVar7) {
        iVar2 = iVar2 - (iVar8 + 2);
        if (iVar2 <= tlen) {
          (*(code *)PTR_memcpy_006aabf4)(to,puVar5,iVar2);
          return iVar2;
        }
        uVar6 = 0x6d;
        uVar3 = 0xd9;
        goto LAB_0051198c;
      }
    }
    uVar6 = 0x67;
    uVar3 = 0xd2;
  }
  else {
    uVar6 = 0x6b;
    uVar3 = 0xbe;
  }
LAB_0051198c:
  (*(code *)PTR_ERR_put_error_006a9030)(4,0x71,uVar6,"rsa_pk1.c",uVar3);
  return -1;
}

