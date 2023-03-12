
void ERR_put_error(int lib,int func,int reason,char *file,int line)

{
  ERR_STATE *pEVar1;
  uint uVar2;
  uint uVar3;
  
  pEVar1 = ERR_get_state();
  uVar2 = pEVar1->top + 1U & 0x8000000f;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff0) + 1;
  }
  pEVar1->top = uVar2;
  if (uVar2 == pEVar1->bottom) {
    uVar3 = uVar2 + 1 & 0x8000000f;
    if ((int)uVar3 < 0) {
      pEVar1->bottom = (uVar3 - 1 | 0xfffffff0) + 1;
    }
    else {
      pEVar1->bottom = uVar3;
    }
  }
  pEVar1->err_line[uVar2] = line;
  pEVar1->err_flags[uVar2] = 0;
  pEVar1->err_file[uVar2] = file;
  pEVar1->err_buffer[uVar2] = (func & 0xfffU) << 0xc | reason & 0xfffU | lib << 0x18;
  if ((pEVar1->err_data[uVar2] != (char *)0x0) && ((pEVar1->err_data_flags[uVar2] & 1U) != 0)) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    uVar2 = pEVar1->top;
    pEVar1->err_data[uVar2] = (char *)0x0;
  }
  pEVar1->err_data_flags[uVar2] = 0;
  return;
}

