
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_pop_to_mark(void)

{
  ERR_STATE *pEVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  pEVar1 = ERR_get_state();
  iVar2 = pEVar1->top;
  iVar4 = pEVar1->bottom;
  do {
    if (iVar4 == iVar2) {
      return 0;
    }
    while( true ) {
      if ((pEVar1->err_flags[iVar2] & 1U) != 0) {
        pEVar1->err_flags[iVar2] = pEVar1->err_flags[iVar2] & 0xfffffffe;
        return 1;
      }
      pEVar1->err_flags[iVar2] = 0;
      pEVar1->err_buffer[iVar2] = 0;
      if ((pEVar1->err_data[iVar2] == (char *)0x0) || ((pEVar1->err_data_flags[iVar2] & 1U) == 0)) {
        pEVar1->err_data_flags[iVar2] = 0;
        pEVar1->err_file[iVar2] = (char *)0x0;
        pEVar1->err_line[iVar2] = -1;
        pEVar1->top = iVar2 + -1;
        iVar2 = iVar2 + -1;
      }
      else {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        iVar3 = pEVar1->top;
        iVar4 = pEVar1->bottom;
        iVar2 = iVar3 + -1;
        pEVar1->err_data[iVar3] = (char *)0x0;
        pEVar1->err_data_flags[iVar3] = 0;
        pEVar1->err_file[iVar3] = (char *)0x0;
        pEVar1->err_line[iVar3] = -1;
        pEVar1->top = iVar2;
      }
      if (iVar2 != -1) break;
      iVar2 = 0xf;
      pEVar1->top = 0xf;
      if (iVar4 == 0xf) {
        return 0;
      }
    }
  } while( true );
}

