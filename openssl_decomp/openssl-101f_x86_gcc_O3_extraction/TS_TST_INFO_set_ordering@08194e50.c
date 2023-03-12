
undefined4 TS_TST_INFO_set_ordering(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x18) = ~-(uint)(param_2 == 0) & 0xff;
  return 1;
}

