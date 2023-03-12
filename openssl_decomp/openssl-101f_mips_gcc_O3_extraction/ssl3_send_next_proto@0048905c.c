
void ssl3_send_next_proto(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar1 = PTR_memcpy_006aabf4;
  if (*(int *)(param_1 + 0x34) != 0x1200) {
    ssl3_do_write(param_1,0x16);
    return;
  }
  uVar2 = (uint)*(byte *)(param_1 + 0x178);
  puVar3 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
  puVar3[4] = *(byte *)(param_1 + 0x178);
  iVar4 = 0x20 - (uVar2 + 2 & 0x1f);
  (*(code *)puVar1)(puVar3 + 5,*(undefined4 *)(param_1 + 0x174),uVar2);
  puVar3[uVar2 + 5] = (char)iVar4;
  (*(code *)PTR_memset_006aab00)(puVar3 + uVar2 + 6,0,iVar4);
  puVar3[1] = 0;
  puVar3[3] = (char)iVar4 + (char)(uVar2 + 2);
  *puVar3 = 0x43;
  puVar3[2] = (char)(uVar2 + iVar4 + 2 >> 8);
  *(uint *)(param_1 + 0x44) = uVar2 + iVar4 + 6;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0x1201;
  ssl3_do_write(param_1,0x16);
  return;
}

