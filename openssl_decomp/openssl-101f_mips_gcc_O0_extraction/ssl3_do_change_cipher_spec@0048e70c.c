
undefined4 ssl3_do_change_cipher_spec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 0x21;
  if ((*(uint *)(param_1 + 0x34) & 0x2000) == 0) {
    uVar2 = 0x11;
  }
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x378) == 0) {
    if (*(int *)(param_1 + 0xc0) == 0) {
      uVar3 = 0x85;
      uVar2 = 0x59d;
      goto LAB_0048e7d4;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 100);
    *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xb4) =
         *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x344);
    iVar1 = (**(code **)(iVar1 + 8))();
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x10))(param_1,uVar2);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0x34) & 0x1000) == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 100);
    uVar2 = *(undefined4 *)(iVar1 + 0x20);
    uVar3 = *(undefined4 *)(iVar1 + 0x24);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 100);
    uVar2 = *(undefined4 *)(iVar1 + 0x28);
    uVar3 = *(undefined4 *)(iVar1 + 0x2c);
  }
  iVar1 = (**(code **)(iVar1 + 0x14))(param_1,uVar2,uVar3,*(int *)(param_1 + 0x58) + 0x2b8);
  if (iVar1 != 0) {
    *(int *)(*(int *)(param_1 + 0x58) + 0x338) = iVar1;
    return 1;
  }
  uVar3 = 0x44;
  uVar2 = 0x5ba;
LAB_0048e7d4:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x124,uVar3,"s3_pkt.c",uVar2);
  return 0;
}

