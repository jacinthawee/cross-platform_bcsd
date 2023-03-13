
int BN_print(void *fp,BIGNUM *a)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((a->neg != 0) && (iVar5 = (*(code *)PTR_BIO_write_006a6e14)(fp,&DAT_006621f4,1), iVar5 != 1))
  {
    return 0;
  }
  iVar5 = a->top;
  if (iVar5 == 0) {
    iVar5 = (*(code *)PTR_BIO_write_006a6e14)(fp,"0",1);
    if (iVar5 != 1) {
      return 0;
    }
    iVar5 = a->top;
  }
  iVar5 = iVar5 + -1;
  if (-1 < iVar5) {
    iVar4 = iVar5 * 4;
    bVar1 = false;
    do {
      uVar6 = 0x1c;
      do {
        uVar3 = uVar6 & 0x1f;
        uVar6 = uVar6 - 4;
        uVar3 = *(uint *)((int)a->d + iVar4) >> uVar3 & 0xf;
        if ((bVar1) || (uVar3 != 0)) {
          iVar2 = (*(code *)PTR_BIO_write_006a6e14)(fp,"0123456789ABCDEF" + uVar3,1);
          bVar1 = true;
          if (iVar2 != 1) {
            return 0;
          }
        }
      } while (uVar6 != 0xfffffffc);
      iVar5 = iVar5 + -1;
      iVar4 = iVar4 + -4;
    } while (iVar5 != -1);
  }
  return 1;
}

