
void ERR_add_error_vdata(int num,va_list args)

{
  char *dst;
  int iVar1;
  ERR_STATE *pEVar2;
  int iVar3;
  char *src;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  dst = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x51,"err.c",0x438);
  if (dst != (char *)0x0) {
    *dst = '\0';
    if (0 < num) {
      iVar7 = 0x50;
      iVar3 = 0;
      iVar5 = 0;
      iVar4 = (int)args + 4;
      pcVar6 = dst;
      do {
        src = *(char **)(iVar4 + -4);
        iVar5 = iVar5 + 1;
        dst = pcVar6;
        if (src != (char *)0x0) {
          iVar1 = (*(code *)PTR_strlen_006aab30)(src);
          iVar3 = iVar3 + iVar1;
          if (iVar7 < iVar3) {
            iVar7 = iVar3 + 0x14;
            dst = (char *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(pcVar6,iVar3 + 0x15,"err.c",0x447);
            if (dst == (char *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00534660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar6);
              return;
            }
          }
          BUF_strlcat(dst,src,iVar7 + 1);
        }
        iVar4 = iVar4 + 4;
        pcVar6 = dst;
      } while (num != iVar5);
    }
    pEVar2 = ERR_get_state();
    iVar3 = pEVar2->top;
    if (iVar3 == 0) {
      iVar3 = 0xf;
    }
    if ((pEVar2->err_data[iVar3] != (char *)0x0) && ((pEVar2->err_data_flags[iVar3] & 1U) != 0)) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    pEVar2->err_data[iVar3] = dst;
    pEVar2->err_data_flags[iVar3] = 3;
  }
  return;
}

