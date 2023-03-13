
undefined4 ssl3_do_change_cipher_spec(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int line;
  
  uVar1 = *(uint *)(param_1 + 0x34);
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x378) == 0) {
    iVar2 = *(int *)(param_1 + 0xc0);
    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x10) == 0)) {
      line = 0x5ca;
      iVar2 = 0x85;
      goto LAB_080a43d3;
    }
    *(undefined4 *)(iVar2 + 0xb4) = *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x344);
    iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 8))(param_1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x10))
                    (param_1,(-(uint)((uVar1 & 0x2000) == 0) & 0xfffffff0) + 0x21);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 100);
  if ((*(byte *)(param_1 + 0x35) & 0x10) == 0) {
    uVar3 = *(undefined4 *)(iVar2 + 0x20);
    uVar4 = *(undefined4 *)(iVar2 + 0x24);
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + 0x28);
    uVar4 = *(undefined4 *)(iVar2 + 0x2c);
  }
  iVar2 = (**(code **)(iVar2 + 0x14))(param_1,uVar3,uVar4,*(int *)(param_1 + 0x58) + 0x2b8);
  if (iVar2 != 0) {
    *(int *)(*(int *)(param_1 + 0x58) + 0x338) = iVar2;
    return 1;
  }
  line = 0x5e6;
  iVar2 = 0x44;
LAB_080a43d3:
  ERR_put_error(0x14,0x124,iVar2,"s3_pkt.c",line);
  return 0;
}

