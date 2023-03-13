
void cleanup2_LHASH_DOALL(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 4) + 8);
  *piVar1 = *piVar1 + 1;
  return;
}

