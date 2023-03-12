
int BN_print_fp(FILE *fp,BIGNUM *a)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar2 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar3 = (*(code *)PTR_BIO_new_006a6ea4)(uVar2);
  if (iVar3 == 0) {
    return 0;
  }
  (*(code *)PTR_BIO_ctrl_006a6e18)(iVar3,0x6a,0,fp);
  if (a->neg == 0) {
LAB_004f8ce4:
    iVar7 = a->top;
    if (iVar7 == 0) {
      iVar7 = (*(code *)PTR_BIO_write_006a6e14)(iVar3,"0",1);
      if (iVar7 != 1) goto LAB_004f8d9c;
      iVar7 = a->top;
    }
    iVar7 = iVar7 + -1;
    if (-1 < iVar7) {
      iVar6 = iVar7 * 4;
      bVar1 = false;
      do {
        uVar8 = 0x1c;
        do {
          uVar5 = uVar8 & 0x1f;
          uVar8 = uVar8 - 4;
          uVar5 = *(uint *)((int)a->d + iVar6) >> uVar5 & 0xf;
          if ((bVar1) || (uVar5 != 0)) {
            iVar4 = (*(code *)PTR_BIO_write_006a6e14)(iVar3,"0123456789ABCDEF" + uVar5,1);
            bVar1 = true;
            if (iVar4 != 1) goto LAB_004f8d9c;
          }
        } while (uVar8 != 0xfffffffc);
        iVar7 = iVar7 + -1;
        iVar6 = iVar6 + -4;
      } while (iVar7 != -1);
    }
    iVar7 = 1;
  }
  else {
    iVar7 = (*(code *)PTR_BIO_write_006a6e14)(iVar3,&DAT_006621f4,1);
    if (iVar7 == 1) goto LAB_004f8ce4;
LAB_004f8d9c:
    iVar7 = 0;
  }
  (*(code *)PTR_BIO_free_006a6e70)(iVar3);
  return iVar7;
}

