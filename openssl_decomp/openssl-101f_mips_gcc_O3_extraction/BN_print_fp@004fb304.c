
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
  
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if (iVar3 == 0) {
    return 0;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,0x6a,0,fp);
  if (a->neg == 0) {
LAB_004fb388:
    iVar7 = a->top;
    if (iVar7 == 0) {
      iVar7 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,"0",1);
      if (iVar7 != 1) goto LAB_004fb440;
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
            iVar4 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,"0123456789ABCDEF" + uVar5,1);
            bVar1 = true;
            if (iVar4 != 1) goto LAB_004fb440;
          }
        } while (uVar8 != 0xfffffffc);
        iVar7 = iVar7 + -1;
        iVar6 = iVar6 + -4;
      } while (iVar7 != -1);
    }
    iVar7 = 1;
  }
  else {
    iVar7 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,&DAT_00662b94,1);
    if (iVar7 == 1) goto LAB_004fb388;
LAB_004fb440:
    iVar7 = 0;
  }
  (*(code *)PTR_BIO_free_006a7f70)(iVar3);
  return iVar7;
}

