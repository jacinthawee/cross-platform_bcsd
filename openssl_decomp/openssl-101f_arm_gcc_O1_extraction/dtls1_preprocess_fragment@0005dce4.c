
undefined4 dtls1_preprocess_fragment(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_2 + 4);
  if (uVar5 < (uint)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0xc))) {
    iVar3 = 0x1f1;
  }
  else if (param_3 < (uint)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0xc))) {
    iVar3 = 0x1f7;
  }
  else {
    if (*(int *)(*(int *)(param_1 + 0x5c) + 0x294) == 0) {
      iVar3 = BUF_MEM_grow_clean(*(BUF_MEM **)(param_1 + 0x3c),uVar5 + 0xc);
      if (iVar3 != 0) {
        iVar3 = *(int *)(param_1 + 0x58);
        iVar4 = *(int *)(param_1 + 0x5c);
        uVar2 = *(undefined2 *)(param_2 + 8);
        *(uint *)(iVar3 + 0x33c) = uVar5;
        bVar1 = *param_2;
        *(uint *)(iVar4 + 0x28c) = uVar5;
        *(uint *)(iVar3 + 0x340) = (uint)bVar1;
        *(byte *)(iVar4 + 0x288) = *param_2;
        *(undefined2 *)(*(int *)(param_1 + 0x5c) + 0x290) = uVar2;
        return 0;
      }
      ERR_put_error(0x14,0x120,7,"d1_both.c",0x201);
      return 0x50;
    }
    if (*(uint *)(*(int *)(param_1 + 0x5c) + 0x28c) == uVar5) {
      return 0;
    }
    iVar3 = 0x20f;
  }
  ERR_put_error(0x14,0x120,0x98,"d1_both.c",iVar3);
  return 0x2f;
}

