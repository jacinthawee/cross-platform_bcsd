
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
  if ((a->neg != 0) && (iVar6 = BIO_write(bp,&DAT_00157d4c,1), iVar6 != 1)) {
LAB_0008ade6:
    BIO_free(bp);
    return 0;
  }
  iVar6 = a->top;
  if (iVar6 == 0) {
    iVar6 = BIO_write(bp,"0",1);
    if (iVar6 != 1) goto LAB_0008ade6;
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
        if (uVar1 != 0) goto LAB_0008ad3c;
LAB_0008acde:
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008ad56;
LAB_0008ace6:
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008ad70;
LAB_0008acee:
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008ad8a;
LAB_0008acf6:
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008ada4;
LAB_0008acfe:
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 != 0) goto LAB_0008adbe;
LAB_0008ad06:
        uVar4 = uVar4 & 0xf;
        uVar1 = uVar1 | uVar4;
      }
      else {
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + (uVar4 >> 0x1c),1);
        if (iVar2 != 1) goto LAB_0008ade6;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 4) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008acde;
LAB_0008ad3c:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008ade6;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008ace6;
LAB_0008ad56:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008ade6;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008acee;
LAB_0008ad70:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008ade6;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008acf6;
LAB_0008ad8a:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008ade6;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008acfe;
LAB_0008ada4:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008ade6;
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 == 0) goto LAB_0008ad06;
LAB_0008adbe:
        iVar2 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) goto LAB_0008ade6;
        uVar4 = *(uint *)((int)a->d + iVar5) & 0xf;
        uVar1 = uVar4 | 1;
      }
      if ((uVar1 != 0) && (uVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar4,1), uVar1 != 1))
      goto LAB_0008ade6;
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -4;
    } while (iVar6 != -1);
  }
  BIO_free(bp);
  return 1;
}

