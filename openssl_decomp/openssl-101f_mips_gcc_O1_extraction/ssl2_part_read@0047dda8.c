
int ssl2_part_read(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_3 < 0) {
    return param_3;
  }
  param_3 = param_3 + *(int *)(param_1 + 0x44);
  *(int *)(param_1 + 0x44) = param_3;
  if (param_3 < 3) {
    return 0;
  }
  pcVar3 = *(char **)(*(int *)(param_1 + 0x3c) + 4);
  if (*pcVar3 == '\0') {
    uVar1 = 0xfd;
    if (*(ushort *)(pcVar3 + 1) - 1 < 6) {
      uVar1 = *(undefined4 *)(CSWTCH_22 + (*(ushort *)(pcVar3 + 1) - 1) * 4);
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,param_2,uVar1,"s2_pkt.c",0x2a9);
    iVar2 = *(int *)(param_1 + 0x44) + -3;
    *(int *)(param_1 + 0x44) = iVar2;
    if (0 < iVar2) {
      (*(code *)PTR_memmove_006aabfc)(pcVar3,pcVar3 + 3);
    }
  }
  return 0;
}

