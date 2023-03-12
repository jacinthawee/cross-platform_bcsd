
int BN_print(void *fp,BIGNUM *a)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if ((a->neg != 0) && (iVar6 = BIO_write((BIO *)fp,&DAT_001591bc,1), iVar6 != 1)) {
    return 0;
  }
  iVar6 = a->top;
  if (iVar6 == 0) {
    iVar6 = BIO_write((BIO *)fp,"0",1);
    if (iVar6 != 1) {
      return 0;
    }
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
        if (uVar1 == 0) goto LAB_0008c9f0;
LAB_0008ca4e:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008ca68;
LAB_0008c9f8:
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ca00;
LAB_0008ca82:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008ca9c;
LAB_0008ca08:
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ca10;
LAB_0008cab6:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008cad0;
LAB_0008ca18:
        uVar4 = uVar4 & 0xf;
        uVar1 = uVar1 | uVar4;
      }
      else {
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + (uVar4 >> 0x1c),1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 4) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008ca4e;
LAB_0008c9f0:
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008c9f8;
LAB_0008ca68:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008ca82;
LAB_0008ca00:
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ca08;
LAB_0008ca9c:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008cab6;
LAB_0008ca10:
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ca18;
LAB_0008cad0:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5) & 0xf;
        uVar1 = uVar4 | 1;
      }
      if ((uVar1 != 0) && (uVar1 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar4,1), uVar1 != 1)) {
        return 0;
      }
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -4;
    } while (iVar6 != -1);
  }
  return 1;
}

