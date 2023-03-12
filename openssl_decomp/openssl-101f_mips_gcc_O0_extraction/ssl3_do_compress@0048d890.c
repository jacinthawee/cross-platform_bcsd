
undefined4 ssl3_do_compress(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x58);
  iVar1 = (*(code *)PTR_COMP_compress_block_006a9244)
                    (*(undefined4 *)(param_1 + 0x94),*(undefined4 *)(iVar2 + 0x13c),0x4400,
                     *(undefined4 *)(iVar2 + 0x140),*(undefined4 *)(iVar2 + 0x134));
  if (-1 < iVar1) {
    *(int *)(iVar2 + 0x134) = iVar1;
    *(undefined4 *)(iVar2 + 0x140) = *(undefined4 *)(iVar2 + 0x13c);
    return 1;
  }
  return 0;
}

