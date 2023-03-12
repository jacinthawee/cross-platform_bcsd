
void ec_GFp_mont_group_finish(int param_1)

{
  if (*(int *)(param_1 + 0xa0) != 0) {
    (*(code *)PTR_BN_MONT_CTX_free_006a8568)();
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(int *)(param_1 + 0xa4) != 0) {
    (*(code *)PTR_BN_free_006a701c)();
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  ec_GFp_simple_group_finish(param_1);
  return;
}

