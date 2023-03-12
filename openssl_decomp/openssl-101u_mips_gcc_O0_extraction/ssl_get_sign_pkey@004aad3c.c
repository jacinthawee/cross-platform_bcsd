
int ssl_get_sign_pkey(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = *(uint *)(param_2 + 0x10);
  iVar4 = *(int *)(param_1 + 0x98);
  if (((uVar2 & 2) == 0) || (iVar1 = *(int *)(iVar4 + 0x4c), iVar1 == 0)) {
    if ((uVar2 & 1) == 0) {
      if ((uVar2 & 0x40) != 0) {
        iVar1 = *(int *)(iVar4 + 0x70);
        iVar3 = 5;
        if (iVar1 != 0) goto LAB_004aad70;
      }
LAB_004aaddc:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb7,0x44,"ssl_lib.c",0x96a);
      return 0;
    }
    iVar1 = *(int *)(iVar4 + 0x40);
    iVar3 = 1;
    if (iVar1 == 0) {
      iVar1 = *(int *)(iVar4 + 0x34);
      iVar3 = 0;
      if (iVar1 == 0) goto LAB_004aaddc;
    }
  }
  else {
    iVar3 = 2;
  }
LAB_004aad70:
  if (param_3 != (undefined4 *)0x0) {
    iVar4 = iVar4 + iVar3 * 0xc;
    *param_3 = *(undefined4 *)(iVar4 + 0x38);
    iVar1 = *(int *)(iVar4 + 0x34);
  }
  return iVar1;
}

