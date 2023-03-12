
int BN_print_fp(FILE *fp,BIGNUM *a)

{
  BIO_METHOD *type;
  BIO *bp;
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  if ((a->neg != 0) && (iVar6 = BIO_write(bp,&DAT_001591bc,1), iVar6 != 1)) {
LAB_0008c96e:
    BIO_free(bp);
    return 0;
  }
  iVar6 = a->top;
  if (iVar6 == 0) {
    iVar6 = BIO_write(bp,"0",1);
    if (iVar6 != 1) goto LAB_0008c96e;
    iVar6 = a->top;
  }
  iVar6 = iVar6 + -1;
  if (-1 < iVar6) {
    iVar5 = iVar6 * 4;
    uVar1 = 0;
    do {
      uVar4 = *(uint *)((int)a->d + iVar5);
      if ((uVar1 | uVar4 >> 0x1c) == 0) {
        uVar1 = (uVar4 << 4) >> 0x1c;
        uVar3 = uVar1;
        if (uVar1 != 0) goto LAB_0008c8c4;
LAB_0008c866:
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008c8de;
LAB_0008c86e:
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008c8f8;
LAB_0008c876:
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008c912;
LAB_0008c87e:
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008c92c;
LAB_0008c886:
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008c946;
LAB_0008c88e:
        uVar4 = uVar4 & 0xf;
        uVar1 = uVar1 | uVar4;
      }
      else {
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + (uVar4 >> 0x1c),1);
        if (iVar2 != 1) goto LAB_0008c96e;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 4) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008c866;
LAB_0008c8c4:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008c96e;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008c86e;
LAB_0008c8de:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008c96e;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008c876;
LAB_0008c8f8:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008c96e;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008c87e;
LAB_0008c912:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008c96e;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008c886;
LAB_0008c92c:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008c96e;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008c88e;
LAB_0008c946:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008c96e;
        uVar4 = *(uint *)((int)a->d + iVar5) & 0xf;
        uVar1 = uVar4 | 1;
      }
      if ((uVar1 != 0) && (uVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar4,1), uVar1 != 1))
      goto LAB_0008c96e;
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -4;
    } while (iVar6 != -1);
  }
  BIO_free(bp);
  return 1;
}

