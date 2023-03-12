
int ssl_cipher_ptr_id_cmp(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(*param_1 + 8) != *(int *)(*param_2 + 8)) {
    iVar1 = (uint)(0 < *(int *)(*param_1 + 8) - *(int *)(*param_2 + 8)) * 2 + -1;
  }
  return iVar1;
}

