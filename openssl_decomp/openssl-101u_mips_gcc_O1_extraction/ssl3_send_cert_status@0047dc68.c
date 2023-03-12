
undefined4 ssl3_send_cert_status(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  if (*(int *)(param_1 + 0x34) != 0x2200) {
    uVar2 = ssl3_do_write(param_1,0x16);
    return uVar2;
  }
  iVar3 = (*(code *)PTR_BUF_MEM_grow_006a74a0)
                    (*(undefined4 *)(param_1 + 0x3c),*(int *)(param_1 + 0x13c) + 8);
  puVar1 = PTR_memcpy_006a9aec;
  if (iVar3 != 0) {
    puVar4 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
    *puVar4 = 0x16;
    puVar4[1] = (char)((uint)(*(int *)(param_1 + 0x13c) + 4) >> 0x10);
    puVar4[2] = (char)((uint)(*(int *)(param_1 + 0x13c) + 4) >> 8);
    puVar4[3] = (char)*(undefined4 *)(param_1 + 0x13c) + '\x04';
    puVar4[4] = (char)*(undefined4 *)(param_1 + 0x128);
    puVar4[5] = (char)*(undefined2 *)(param_1 + 0x13c);
    puVar4[6] = (char)((uint)*(undefined4 *)(param_1 + 0x13c) >> 8);
    puVar4[7] = (char)*(undefined4 *)(param_1 + 0x13c);
    (*(code *)puVar1)(puVar4 + 8,*(undefined4 *)(param_1 + 0x138),*(undefined4 *)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0x2201;
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x13c) + 8;
    uVar2 = ssl3_do_write(param_1,0x16);
    return uVar2;
  }
  *(undefined4 *)(param_1 + 0x34) = 5;
  return 0xffffffff;
}

