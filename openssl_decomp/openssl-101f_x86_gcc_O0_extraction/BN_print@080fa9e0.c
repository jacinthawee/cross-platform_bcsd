
int BN_print(void *fp,BIGNUM *a)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((a->neg != 0) && (iVar5 = BIO_write((BIO *)fp,&DAT_0823b414,1), iVar5 != 1)) {
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
        if (uVar3 == 0) goto LAB_080faa32;
LAB_080faaf9:
        iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar1 != 1) {
          return 0;
        }
        uVar2 = *(uint *)((int)a->d + iVar4);
        uVar3 = uVar2 >> 0x14 & 0xf;
        if ((uVar3 | 1) != 0) goto LAB_080fab36;
LAB_080faa44:
        uVar3 = uVar2 >> 0x10 & 0xf;
        if (uVar3 == 0) goto LAB_080faa56;
LAB_080fab73:
        iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar1 != 1) {
          return 0;
        }
        uVar2 = *(uint *)((int)a->d + iVar4);
        uVar3 = uVar2 >> 0xc & 0xf;
        if ((uVar3 | 1) != 0) goto LAB_080fabb0;
LAB_080faa68:
        uVar3 = uVar2 >> 8 & 0xf;
        if (uVar3 == 0) goto LAB_080faa7a;
LAB_080fabed:
        iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar1 != 1) {
          return 0;
        }
        uVar2 = *(uint *)((int)a->d + iVar4);
        uVar3 = uVar2 >> 4 & 0xf;
        if ((uVar3 | 1) != 0) goto LAB_080fac2a;
LAB_080faa8c:
        uVar2 = uVar2 & 0xf;
        if (uVar2 == 0) goto LAB_080faa99;
LAB_080fac5e:
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
      if ((uVar3 | 1) != 0) goto LAB_080faaf9;
LAB_080faa32:
      uVar3 = uVar2 >> 0x14 & 0xf;
      if (uVar3 == 0) goto LAB_080faa44;
LAB_080fab36:
      iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
      if (iVar1 != 1) {
        return 0;
      }
      uVar2 = *(uint *)((int)a->d + iVar4);
      uVar3 = uVar2 >> 0x10 & 0xf;
      if ((uVar3 | 1) != 0) goto LAB_080fab73;
LAB_080faa56:
      uVar3 = uVar2 >> 0xc & 0xf;
      if (uVar3 == 0) goto LAB_080faa68;
LAB_080fabb0:
      iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
      if (iVar1 != 1) {
        return 0;
      }
      uVar2 = *(uint *)((int)a->d + iVar4);
      uVar3 = uVar2 >> 8 & 0xf;
      if ((uVar3 | 1) != 0) goto LAB_080fabed;
LAB_080faa7a:
      uVar3 = uVar2 >> 4 & 0xf;
      if (uVar3 == 0) goto LAB_080faa8c;
LAB_080fac2a:
      iVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
      if (iVar1 != 1) {
        return 0;
      }
      uVar2 = *(uint *)((int)a->d + iVar4) & 0xf;
      if ((uVar2 | 1) != 0) goto LAB_080fac5e;
LAB_080faa99:
      uVar3 = 0;
      iVar5 = iVar5 + -1;
      iVar4 = iVar4 + -4;
    } while (iVar5 != -1);
  }
  return 1;
}

