
void ERR_put_error(int lib,int func,int reason,char *file,int line)

{
  ERR_STATE *pEVar1;
  int iVar2;
  
  pEVar1 = ERR_get_state();
  iVar2 = (pEVar1->top + 1) % 0x10;
  pEVar1->top = iVar2;
  if (iVar2 == pEVar1->bottom) {
    pEVar1->bottom = (iVar2 + 1) % 0x10;
  }
  pEVar1->err_flags[iVar2] = 0;
  pEVar1->err_buffer[iVar2] = (func & 0xfffU) << 0xc | reason & 0xfffU | lib << 0x18;
  pEVar1->err_file[iVar2] = file;
  pEVar1->err_line[iVar2] = line;
  if ((pEVar1->err_data[iVar2] != (char *)0x0) &&
     ((*(byte *)(pEVar1->err_data_flags + iVar2) & 1) != 0)) {
    CRYPTO_free(pEVar1->err_data[iVar2]);
    iVar2 = pEVar1->top;
    pEVar1->err_data[iVar2] = (char *)0x0;
  }
  pEVar1->err_data_flags[iVar2] = 0;
  return;
}

