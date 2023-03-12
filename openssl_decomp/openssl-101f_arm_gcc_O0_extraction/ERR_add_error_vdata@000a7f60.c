
void ERR_add_error_vdata(int num,va_list args)

{
  char *dst;
  size_t sVar1;
  ERR_STATE *pEVar2;
  int iVar3;
  char *__s;
  int iVar4;
  char *addr;
  int iVar5;
  
  dst = (char *)CRYPTO_malloc(0x51,"err.c",0x438);
  if (dst != (char *)0x0) {
    iVar3 = 0;
    *dst = '\0';
    if (0 < num) {
      iVar5 = 0x50;
      iVar4 = 0;
      addr = dst;
      do {
                    /* WARNING: Load size is inaccurate */
        __s = *args;
        iVar4 = iVar4 + 1;
        dst = addr;
        if (__s != (char *)0x0) {
          sVar1 = strlen(__s);
          iVar3 = iVar3 + sVar1;
          if (iVar5 < iVar3) {
            dst = (char *)CRYPTO_realloc(addr,iVar3 + 0x15,"err.c",0x447);
            iVar5 = iVar3 + 0x14;
            if (dst == (char *)0x0) {
              CRYPTO_free(addr);
              return;
            }
          }
          BUF_strlcat(dst,__s,iVar5 + 1);
        }
        addr = dst;
        args = (char **)((int)args + 4);
      } while (iVar4 != num);
    }
    pEVar2 = ERR_get_state();
    iVar3 = pEVar2->top;
    if (iVar3 == 0) {
      iVar3 = 0xf;
    }
    if ((pEVar2->err_data[iVar3] != (char *)0x0) && (pEVar2->err_data_flags[iVar3] << 0x1f < 0)) {
      CRYPTO_free(pEVar2->err_data[iVar3]);
    }
    pEVar2->err_data[iVar3] = dst;
    pEVar2->err_data_flags[iVar3] = 3;
  }
  return;
}

