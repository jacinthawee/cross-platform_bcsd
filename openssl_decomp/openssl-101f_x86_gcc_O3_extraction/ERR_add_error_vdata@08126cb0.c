
void ERR_add_error_vdata(int num,va_list args)

{
  char *__s;
  size_t sVar1;
  char *pcVar2;
  ERR_STATE *pEVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *local_28;
  
  local_28 = (char *)CRYPTO_malloc(0x51,"err.c",0x438);
  if (local_28 != (char *)0x0) {
    *local_28 = '\0';
    if (0 < num) {
      iVar6 = 0x50;
      iVar4 = 0;
      iVar5 = 0;
      do {
        __s = *(char **)((int)args + iVar4 * 4);
        if (__s != (char *)0x0) {
          sVar1 = strlen(__s);
          iVar5 = iVar5 + sVar1;
          pcVar2 = local_28;
          if (iVar6 < iVar5) {
            iVar6 = iVar5 + 0x14;
            pcVar2 = (char *)CRYPTO_realloc(local_28,iVar5 + 0x15,"err.c",0x447);
            if (pcVar2 == (char *)0x0) {
              CRYPTO_free(local_28);
              return;
            }
          }
          local_28 = pcVar2;
          BUF_strlcat(local_28,__s,iVar6 + 1);
        }
        iVar4 = iVar4 + 1;
      } while (num != iVar4);
    }
    pEVar3 = ERR_get_state();
    iVar6 = pEVar3->top;
    if (iVar6 == 0) {
      iVar6 = 0xf;
    }
    if ((pEVar3->err_data[iVar6] != (char *)0x0) &&
       ((*(byte *)(pEVar3->err_data_flags + iVar6) & 1) != 0)) {
      CRYPTO_free(pEVar3->err_data[iVar6]);
    }
    pEVar3->err_data_flags[iVar6] = 3;
    pEVar3->err_data[iVar6] = local_28;
  }
  return;
}

