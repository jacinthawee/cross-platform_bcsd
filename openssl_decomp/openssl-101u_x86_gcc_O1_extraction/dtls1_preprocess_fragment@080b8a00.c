
undefined4 __regparm3 dtls1_preprocess_fragment(int param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_2 + 4);
  if (uVar1 < (uint)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0xc))) {
    iVar3 = 0x237;
  }
  else if (param_3 < (uint)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0xc))) {
    iVar3 = 0x23c;
  }
  else {
    if (*(int *)(*(int *)(param_1 + 0x5c) + 0x298) == 0) {
      iVar3 = BUF_MEM_grow_clean(*(BUF_MEM **)(param_1 + 0x3c),uVar1 + 0x1c);
      if (iVar3 != 0) {
        iVar3 = *(int *)(param_1 + 0x58);
        iVar2 = *(int *)(param_1 + 0x5c);
        *(uint *)(iVar3 + 0x33c) = uVar1;
        *(uint *)(iVar2 + 0x290) = uVar1;
        *(uint *)(iVar3 + 0x340) = (uint)*param_2;
        *(byte *)(iVar2 + 0x28c) = *param_2;
        *(undefined2 *)(*(int *)(param_1 + 0x5c) + 0x294) = *(undefined2 *)(param_2 + 8);
        return 0;
      }
      ERR_put_error(0x14,0x120,7,"d1_both.c",0x24a);
      return 0x50;
    }
    if (uVar1 == *(uint *)(*(int *)(param_1 + 0x5c) + 0x290)) {
      return 0;
    }
    iVar3 = 600;
  }
  ERR_put_error(0x14,0x120,0x98,"d1_both.c",iVar3);
  return 0x2f;
}

