
bool dh_missing_parameters(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0x14) + 8) != 0) {
    return *(int *)(*(int *)(param_1 + 0x14) + 0xc) == 0;
  }
  return true;
}

