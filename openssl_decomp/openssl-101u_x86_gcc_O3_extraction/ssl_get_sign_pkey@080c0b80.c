
int ssl_get_sign_pkey(int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  iVar2 = *(int *)(param_1 + 0x98);
  if ((uVar1 & 2) != 0) {
    iVar3 = *(int *)(iVar2 + 0x4c);
    iVar4 = 2;
    if (iVar3 != 0) goto LAB_080c0bab;
  }
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 0x40) != 0) {
      iVar3 = *(int *)(iVar2 + 0x70);
      iVar4 = 5;
      if (iVar3 != 0) goto LAB_080c0bab;
    }
LAB_080c0be2:
    ERR_put_error(0x14,0xb7,0x44,"ssl_lib.c",0x96a);
    return 0;
  }
  iVar3 = *(int *)(iVar2 + 0x40);
  iVar4 = 1;
  if (iVar3 == 0) {
    iVar3 = *(int *)(iVar2 + 0x34);
    iVar4 = 0;
    if (iVar3 == 0) goto LAB_080c0be2;
  }
LAB_080c0bab:
  if (param_3 != (undefined4 *)0x0) {
    iVar2 = iVar2 + iVar4 * 0xc;
    *param_3 = *(undefined4 *)(iVar2 + 0x38);
    iVar3 = *(int *)(iVar2 + 0x34);
  }
  return iVar3;
}

