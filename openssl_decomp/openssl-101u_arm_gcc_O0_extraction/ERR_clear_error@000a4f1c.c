
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_clear_error(void)

{
  ERR_STATE *pEVar1;
  ERR_STATE *pEVar2;
  int iVar3;
  
  pEVar1 = ERR_get_state();
  iVar3 = 0x10;
  pEVar2 = pEVar1;
  do {
    pEVar2->err_flags[0] = 0;
    pEVar2->err_buffer[0] = 0;
    if ((pEVar2->err_data[0] != (char *)0x0) && (pEVar2->err_data_flags[0] << 0x1f < 0)) {
      CRYPTO_free(pEVar2->err_data[0]);
      pEVar2->err_data[0] = (char *)0x0;
    }
    iVar3 = iVar3 + -1;
    pEVar2->err_data_flags[0] = 0;
    pEVar2->err_file[0] = (char *)0x0;
    pEVar2->err_line[0] = -1;
    pEVar2 = (ERR_STATE *)&(pEVar2->tid).val;
  } while (iVar3 != 0);
  pEVar1->bottom = 0;
  pEVar1->top = 0;
  return;
}

