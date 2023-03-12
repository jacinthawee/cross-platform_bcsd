
int ssl_get_sign_pkey(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x10);
  iVar2 = *(int *)(param_1 + 0x98);
  if ((iVar3 << 0x1e < 0) && (iVar1 = *(int *)(iVar2 + 0x4c), iVar1 != 0)) {
    iVar3 = 2;
  }
  else {
    if (-1 < iVar3 << 0x1f) {
      if (iVar3 << 0x19 < 0) {
        iVar1 = *(int *)(iVar2 + 0x70);
        iVar3 = 5;
        if (iVar1 != 0) goto LAB_000627d4;
      }
LAB_000627fe:
      ERR_put_error(0x14,0xb7,0x44,"ssl_lib.c",0x957);
      return 0;
    }
    iVar1 = *(int *)(iVar2 + 0x40);
    iVar3 = 1;
    if (iVar1 == 0) {
      iVar1 = *(int *)(iVar2 + 0x34);
      iVar3 = 0;
      if (iVar1 == 0) goto LAB_000627fe;
    }
  }
LAB_000627d4:
  if (param_3 != (undefined4 *)0x0) {
    iVar2 = iVar2 + iVar3 * 0xc;
    *param_3 = *(undefined4 *)(iVar2 + 0x38);
    iVar1 = *(int *)(iVar2 + 0x34);
  }
  return iVar1;
}

