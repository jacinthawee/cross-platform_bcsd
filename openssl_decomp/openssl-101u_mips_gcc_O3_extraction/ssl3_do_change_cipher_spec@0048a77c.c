
undefined4 ssl3_do_change_cipher_spec(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 0x21;
  if ((*(uint *)(param_1 + 0x34) & 0x2000) == 0) {
    uVar3 = 0x11;
  }
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x378) == 0) {
    iVar1 = *(int *)(param_1 + 0xc0);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x10) == 0)) {
      uVar4 = 0x85;
      uVar3 = 0x5ca;
      goto LAB_0048a858;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 8) + 100);
    *(undefined4 *)(iVar1 + 0xb4) = *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x344);
    iVar1 = (**(code **)(iVar2 + 8))();
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x10))(param_1,uVar3);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0x34) & 0x1000) == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 100);
    uVar3 = *(undefined4 *)(iVar1 + 0x20);
    uVar4 = *(undefined4 *)(iVar1 + 0x24);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 100);
    uVar3 = *(undefined4 *)(iVar1 + 0x28);
    uVar4 = *(undefined4 *)(iVar1 + 0x2c);
  }
  iVar1 = (**(code **)(iVar1 + 0x14))(param_1,uVar3,uVar4,*(int *)(param_1 + 0x58) + 0x2b8);
  if (iVar1 != 0) {
    *(int *)(*(int *)(param_1 + 0x58) + 0x338) = iVar1;
    return 1;
  }
  uVar4 = 0x44;
  uVar3 = 0x5e6;
LAB_0048a858:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x124,uVar4,"s3_pkt.c",uVar3);
  return 0;
}

