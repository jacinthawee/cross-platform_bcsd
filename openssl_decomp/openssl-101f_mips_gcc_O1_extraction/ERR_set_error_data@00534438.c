
void ERR_set_error_data(char *data,int flags)

{
  ERR_STATE *pEVar1;
  int iVar2;
  
  pEVar1 = ERR_get_state();
  iVar2 = pEVar1->top;
  if (iVar2 == 0) {
    iVar2 = 0xf;
  }
  if ((pEVar1->err_data[iVar2] != (char *)0x0) && ((pEVar1->err_data_flags[iVar2] & 1U) != 0)) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  pEVar1->err_data[iVar2] = data;
  pEVar1->err_data_flags[iVar2] = flags;
  return;
}

