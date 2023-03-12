
int RSA_padding_check_SSLv23(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  undefined4 uVar1;
  uchar *puVar2;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uchar *puVar3;
  
  if (fl < 10) {
    uVar4 = 0x6f;
    uVar1 = 0x70;
  }
  else if ((fl + 1 == rsa_len) && (*f == '\x02')) {
    iVar6 = fl + -1;
    iVar5 = 0;
    puVar3 = f + 1;
    do {
      puVar2 = puVar3 + 1;
      if (*puVar3 == '\0') {
        if ((iVar6 == iVar5) || (iVar5 < 8)) goto LAB_0050fc4c;
        goto LAB_0050fb40;
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar2;
    } while (puVar2 != f + fl);
    puVar2 = f + fl;
    if (iVar6 == iVar5) {
LAB_0050fc4c:
      uVar4 = 0x71;
      uVar1 = 0x80;
    }
    else {
LAB_0050fb40:
      if (((((puVar2[-9] == '\x03') && (puVar2[-8] == '\x03')) && (puVar2[-7] == '\x03')) &&
          ((puVar2[-6] == '\x03' && (puVar2[-5] == '\x03')))) &&
         ((puVar2[-4] == '\x03' && ((puVar2[-3] == '\x03' && (puVar2[-2] == '\x03')))))) {
        uVar4 = 0x73;
        uVar1 = 0x88;
      }
      else {
        iVar6 = iVar6 - (iVar5 + 1);
        if (iVar6 <= tlen) {
          (*(code *)PTR_memcpy_006a9aec)(to,puVar2,iVar6);
          return iVar6;
        }
        uVar4 = 0x6d;
        uVar1 = 0x8f;
      }
    }
  }
  else {
    uVar4 = 0x6b;
    uVar1 = 0x74;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(4,0x72,uVar4,"rsa_ssl.c",uVar1);
  return -1;
}

