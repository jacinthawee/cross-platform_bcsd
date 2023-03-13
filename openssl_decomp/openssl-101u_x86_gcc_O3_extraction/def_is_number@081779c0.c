
ushort def_is_number(int param_1,byte param_2)

{
  return *(ushort *)(*(int *)(param_1 + 4) + (uint)param_2 * 2) & 1;
}

