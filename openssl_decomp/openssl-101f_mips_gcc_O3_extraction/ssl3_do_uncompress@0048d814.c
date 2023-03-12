
undefined4 ssl3_do_uncompress(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x58);
  iVar1 = (*(code *)PTR_COMP_expand_block_006a9240)
                    (*(undefined4 *)(param_1 + 0x88),*(undefined4 *)(iVar2 + 0x120),0x4000,
                     *(undefined4 *)(iVar2 + 0x118),*(undefined4 *)(iVar2 + 0x110));
  if (-1 < iVar1) {
    *(int *)(iVar2 + 0x110) = iVar1;
    *(undefined4 *)(iVar2 + 0x118) = *(undefined4 *)(iVar2 + 0x120);
    return 1;
  }
  return 0;
}

