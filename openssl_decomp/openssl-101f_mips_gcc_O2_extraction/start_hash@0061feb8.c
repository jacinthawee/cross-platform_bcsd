
undefined4 start_hash(undefined4 *param_1)

{
  if (param_1[2] != 0) {
    (*(code *)PTR_memset_006aab00)(param_1 + 4,0,0x20);
    (*(code *)PTR_memset_006aab00)(param_1 + 0xc,0,0x20);
    param_1[3] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return 1;
  }
  return 0;
}

