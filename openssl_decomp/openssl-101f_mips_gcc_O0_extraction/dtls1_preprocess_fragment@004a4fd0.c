
undefined4 dtls1_preprocess_fragment(int param_1,byte *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_2 + 4);
  if (uVar4 < (uint)(*(int *)(param_2 + 0xc) + *(int *)(param_2 + 0x10))) {
    uVar1 = 0x1f1;
  }
  else if (param_3 < (uint)(*(int *)(param_2 + 0xc) + *(int *)(param_2 + 0x10))) {
    uVar1 = 0x1f7;
  }
  else {
    if (*(int *)(*(int *)(param_1 + 0x5c) + 0x294) == 0) {
      iVar2 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)
                        (*(undefined4 *)(param_1 + 0x3c),uVar4 + 0xc);
      if (iVar2 != 0) {
        iVar3 = *(int *)(param_1 + 0x58);
        iVar2 = *(int *)(param_1 + 0x5c);
        *(uint *)(iVar3 + 0x33c) = uVar4;
        *(uint *)(iVar2 + 0x28c) = uVar4;
        *(uint *)(iVar3 + 0x340) = (uint)*param_2;
        *(byte *)(iVar2 + 0x288) = *param_2;
        *(undefined2 *)(*(int *)(param_1 + 0x5c) + 0x290) = *(undefined2 *)(param_2 + 8);
        return 0;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x120,7,"d1_both.c",0x201);
      return 0x50;
    }
    if (uVar4 == *(uint *)(*(int *)(param_1 + 0x5c) + 0x28c)) {
      return 0;
    }
    uVar1 = 0x20f;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x120,0x98,"d1_both.c",uVar1);
  return 0x2f;
}

