
int ssl_cipher_id_cmp_BSEARCH_CMP_FN(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 8) != *(int *)(param_2 + 8)) {
    iVar1 = (uint)(0 < *(int *)(param_1 + 8) - *(int *)(param_2 + 8)) * 2 + -1;
  }
  return iVar1;
}

