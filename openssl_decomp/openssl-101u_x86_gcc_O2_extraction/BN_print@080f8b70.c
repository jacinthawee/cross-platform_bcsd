
int BN_print(void *fp,BIGNUM *a)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((a->neg != 0) && (iVar5 = BIO_write((BIO *)fp,&DAT_0823b914,1), iVar5 != 1)) {
    return 0;
  }
  iVar5 = a->top;
  if (iVar5 == 0) {
    iVar5 = BIO_write((BIO *)fp,"0",1);
    if (iVar5 != 1) {
      return 0;
    }
    iVar5 = a->top;
  }
  iVar5 = iVar5 + -1;
  uVar3 = 0;
  iVar4 = iVar5 * 4;
  if (-1 < iVar5) {
    do {
      while( true ) {
        uVar2 = *(uint *)((int)a->d + iVar4);
        if ((uVar3 | uVar2 >> 0x1c) != 0) break;
        uVar3 = uVar2 >> 0x18 & 0xf;
        if (uVar3 == 0) goto LAB_080f8bc2;
LAB_080f8c89:
        iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar1 != 1) {
          return 0;
        }
        uVar2 = *(uint *)((int)a->d + iVar4);
        uVar3 = uVar2 >> 0x14 & 0xf;
        if ((uVar3 | 1) != 0) goto LAB_080f8cc6;
LAB_080f8bd4:
        uVar3 = uVar2 >> 0x10 & 0xf;
        if (uVar3 == 0) goto LAB_080f8be6;
LAB_080f8d03:
        iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar1 != 1) {
          return 0;
        }
        uVar2 = *(uint *)((int)a->d + iVar4);
        uVar3 = uVar2 >> 0xc & 0xf;
        if ((uVar3 | 1) != 0) goto LAB_080f8d40;
LAB_080f8bf8:
        uVar3 = uVar2 >> 8 & 0xf;
        if (uVar3 == 0) goto LAB_080f8c0a;
LAB_080f8d7d:
        iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar1 != 1) {
          return 0;
        }
        uVar2 = *(uint *)((int)a->d + iVar4);
        uVar3 = uVar2 >> 4 & 0xf;
        if ((uVar3 | 1) != 0) goto LAB_080f8dba;
LAB_080f8c1c:
        uVar2 = uVar2 & 0xf;
        if (uVar2 == 0) goto LAB_080f8c29;
LAB_080f8dee:
        iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar2,1);
        if (iVar1 != 1) {
          return 0;
        }
        iVar5 = iVar5 + -1;
        iVar4 = iVar4 + -4;
        uVar3 = 1;
        if (iVar5 == -1) {
          return 1;
        }
      }
      iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + (uVar2 >> 0x1c),1);
      if (iVar1 != 1) {
        return 0;
      }
      uVar2 = *(uint *)((int)a->d + iVar4);
      uVar3 = uVar2 >> 0x18 & 0xf;
      if ((uVar3 | 1) != 0) goto LAB_080f8c89;
LAB_080f8bc2:
      uVar3 = uVar2 >> 0x14 & 0xf;
      if (uVar3 == 0) goto LAB_080f8bd4;
LAB_080f8cc6:
      iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
      if (iVar1 != 1) {
        return 0;
      }
      uVar2 = *(uint *)((int)a->d + iVar4);
      uVar3 = uVar2 >> 0x10 & 0xf;
      if ((uVar3 | 1) != 0) goto LAB_080f8d03;
LAB_080f8be6:
      uVar3 = uVar2 >> 0xc & 0xf;
      if (uVar3 == 0) goto LAB_080f8bf8;
LAB_080f8d40:
      iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
      if (iVar1 != 1) {
        return 0;
      }
      uVar2 = *(uint *)((int)a->d + iVar4);
      uVar3 = uVar2 >> 8 & 0xf;
      if ((uVar3 | 1) != 0) goto LAB_080f8d7d;
LAB_080f8c0a:
      uVar3 = uVar2 >> 4 & 0xf;
      if (uVar3 == 0) goto LAB_080f8c1c;
LAB_080f8dba:
      iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
      if (iVar1 != 1) {
        return 0;
      }
      uVar2 = *(uint *)((int)a->d + iVar4) & 0xf;
      if ((uVar2 | 1) != 0) goto LAB_080f8dee;
LAB_080f8c29:
      uVar3 = 0;
      iVar5 = iVar5 + -1;
      iVar4 = iVar4 + -4;
    } while (iVar5 != -1);
  }
  return 1;
}

