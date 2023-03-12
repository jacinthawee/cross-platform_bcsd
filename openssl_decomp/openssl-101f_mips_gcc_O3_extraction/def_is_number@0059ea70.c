
ushort def_is_number(int param_1,uint param_2)

{
  return *(ushort *)(*(int *)(param_1 + 4) + (param_2 & 0xff) * 2) & 1;
}

