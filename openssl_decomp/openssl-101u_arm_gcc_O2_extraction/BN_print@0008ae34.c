
int BN_print(void *fp,BIGNUM *a)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if ((a->neg != 0) && (iVar6 = BIO_write((BIO *)fp,&DAT_00157d4c,1), iVar6 != 1)) {
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
        if (uVar1 == 0) goto LAB_0008ae68;
LAB_0008aec6:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008aee0;
LAB_0008ae70:
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ae78;
LAB_0008aefa:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008af14;
LAB_0008ae80:
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ae88;
LAB_0008af2e:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008af48;
LAB_0008ae90:
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
        if (uVar1 != 0) goto LAB_0008aec6;
LAB_0008ae68:
        uVar3 = (uVar4 << 8) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ae70;
LAB_0008aee0:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0xc) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008aefa;
LAB_0008ae78:
        uVar3 = (uVar4 << 0x10) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ae80;
LAB_0008af14:
        iVar2 = BIO_write((BIO *)fp,"0123456789ABCDEF" + uVar3,1);
        if (iVar2 != 1) {
          return 0;
        }
        uVar4 = *(uint *)((int)a->d + iVar5);
        uVar3 = (uVar4 << 0x14) >> 0x1c;
        uVar1 = uVar3 | 1;
        if (uVar1 != 0) goto LAB_0008af2e;
LAB_0008ae88:
        uVar3 = (uVar4 << 0x18) >> 0x1c;
        uVar1 = uVar1 | uVar3;
        if (uVar1 == 0) goto LAB_0008ae90;
LAB_0008af48:
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

