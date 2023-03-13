
int BN_print_fp(FILE *fp,BIGNUM *a)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_20;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  if ((a->neg == 0) || (iVar4 = BIO_write(bp,&DAT_0823b914,1), iVar4 == 1)) {
    local_20 = a->top;
    if (local_20 == 0) {
      iVar4 = BIO_write(bp,"0",1);
      if (iVar4 != 1) goto LAB_080f8b24;
      local_20 = a->top;
    }
    local_20 = local_20 + -1;
    uVar3 = 0;
    iVar4 = local_20 * 4;
    if (-1 < local_20) {
      do {
        uVar2 = *(uint *)((int)a->d + iVar4);
        if ((uVar3 | uVar2 >> 0x1c) == 0) {
          uVar3 = uVar2 >> 0x18 & 0xf;
          if (uVar3 != 0) goto LAB_080f898c;
LAB_080f88c2:
          uVar3 = uVar2 >> 0x14 & 0xf;
          if (uVar3 != 0) goto LAB_080f89c6;
LAB_080f88d4:
          uVar3 = uVar2 >> 0x10 & 0xf;
          if (uVar3 != 0) goto LAB_080f8a00;
LAB_080f88e6:
          uVar3 = uVar2 >> 0xc & 0xf;
          if (uVar3 != 0) goto LAB_080f8a3a;
LAB_080f88f8:
          uVar3 = uVar2 >> 8 & 0xf;
          if (uVar3 != 0) goto LAB_080f8a74;
LAB_080f890a:
          uVar3 = uVar2 >> 4 & 0xf;
          if (uVar3 != 0) goto LAB_080f8aae;
LAB_080f891c:
          uVar2 = uVar2 & 0xf;
          uVar5 = uVar2;
        }
        else {
          iVar1 = BIO_write(bp,"0123456789ABCDEF" + (uVar2 >> 0x1c),1);
          if (iVar1 != 1) goto LAB_080f8b24;
          uVar2 = *(uint *)((int)a->d + iVar4);
          uVar3 = uVar2 >> 0x18 & 0xf;
          if ((uVar3 | 1) == 0) goto LAB_080f88c2;
LAB_080f898c:
          iVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar1 != 1) goto LAB_080f8b24;
          uVar2 = *(uint *)((int)a->d + iVar4);
          uVar3 = uVar2 >> 0x14 & 0xf;
          if ((uVar3 | 1) == 0) goto LAB_080f88d4;
LAB_080f89c6:
          iVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar1 != 1) goto LAB_080f8b24;
          uVar2 = *(uint *)((int)a->d + iVar4);
          uVar3 = uVar2 >> 0x10 & 0xf;
          if ((uVar3 | 1) == 0) goto LAB_080f88e6;
LAB_080f8a00:
          iVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar1 != 1) goto LAB_080f8b24;
          uVar2 = *(uint *)((int)a->d + iVar4);
          uVar3 = uVar2 >> 0xc & 0xf;
          if ((uVar3 | 1) == 0) goto LAB_080f88f8;
LAB_080f8a3a:
          iVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar1 != 1) goto LAB_080f8b24;
          uVar2 = *(uint *)((int)a->d + iVar4);
          uVar3 = uVar2 >> 8 & 0xf;
          if ((uVar3 | 1) == 0) goto LAB_080f890a;
LAB_080f8a74:
          iVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar1 != 1) goto LAB_080f8b24;
          uVar2 = *(uint *)((int)a->d + iVar4);
          uVar3 = uVar2 >> 4 & 0xf;
          if ((uVar3 | 1) == 0) goto LAB_080f891c;
LAB_080f8aae:
          iVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar3,1);
          if (iVar1 != 1) goto LAB_080f8b24;
          uVar2 = *(uint *)((int)a->d + iVar4) & 0xf;
          uVar5 = uVar2 | 1;
        }
        uVar3 = 0;
        if (uVar5 != 0) {
          iVar1 = BIO_write(bp,"0123456789ABCDEF" + uVar2,1);
          if (iVar1 != 1) goto LAB_080f8b24;
          uVar3 = 1;
        }
        local_20 = local_20 + -1;
        iVar4 = iVar4 + -4;
      } while (local_20 != -1);
    }
    iVar4 = 1;
  }
  else {
LAB_080f8b24:
    iVar4 = 0;
  }
  BIO_free(bp);
  return iVar4;
}

