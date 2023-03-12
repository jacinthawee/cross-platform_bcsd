
void ssl3_read(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  
  puVar1 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  iVar4 = *(int *)(param_1 + 0x58);
  *puVar1 = 0;
  if (((*(int *)(iVar4 + 0x194) != 0) && (*(int *)(iVar4 + 0xf8) == 0)) &&
     (*(int *)(iVar4 + 0x108) == 0)) {
    uVar3 = (*(code *)PTR_SSL_state_006a88f4)(param_1);
    iVar4 = *(int *)(param_1 + 0x58);
    if ((uVar3 & 0x3000) == 0) {
      iVar2 = *(int *)(iVar4 + 0x19c);
      *(undefined4 *)(param_1 + 0x34) = 0x3004;
      *(undefined4 *)(iVar4 + 0x194) = 0;
      *(int *)(iVar4 + 0x19c) = iVar2 + 1;
      *(int *)(iVar4 + 0x198) = *(int *)(iVar4 + 0x198) + 1;
    }
  }
  iVar2 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar4 + 0x1a0) = 1;
  iVar4 = (**(code **)(iVar2 + 0x34))(param_1,0x17,param_2,param_3,0);
  if (iVar4 == -1) {
    iVar4 = *(int *)(param_1 + 0x58);
    if (*(int *)(iVar4 + 0x1a0) == 2) {
      pcVar5 = *(code **)(*(int *)(param_1 + 8) + 0x34);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      (*pcVar5)(param_1,0x17,param_2,param_3,0);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
      return;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x58);
  }
  *(undefined4 *)(iVar4 + 0x1a0) = 0;
  return;
}

