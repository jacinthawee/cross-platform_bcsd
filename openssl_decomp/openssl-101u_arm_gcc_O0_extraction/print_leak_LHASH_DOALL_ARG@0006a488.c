
void print_leak_LHASH_DOALL_ARG(BIO **param_1,BIO **param_2)

{
  int iVar1;
  ulong uVar2;
  size_t sVar3;
  tm *ptVar4;
  size_t sVar5;
  BIO *pBVar6;
  BIO *pBVar7;
  int iVar8;
  char *pcVar9;
  CRYPTO_THREADID CStack_42c;
  char acStack_424 [1024];
  int iStack_24;
  
  iStack_24 = __stack_chk_guard;
  if (*param_1 != *param_2) {
    if (options << 0x1f < 0) {
      ptVar4 = localtime((time_t *)(param_1 + 7));
      BIO_snprintf(acStack_424,0x400,"[%02d:%02d:%02d] ",ptVar4->tm_hour,ptVar4->tm_min,
                   ptVar4->tm_sec);
      sVar5 = strlen(acStack_424);
      pcVar9 = acStack_424 + sVar5;
      sVar5 = 0x400 - sVar5;
    }
    else {
      pcVar9 = acStack_424;
      sVar5 = 0x400;
    }
    pBVar6 = param_1[2];
    pBVar7 = param_1[3];
    BIO_snprintf(pcVar9,sVar5,"%5lu file=%s, line=%d, ",param_1[6],pBVar6,pBVar7);
    sVar5 = strlen(pcVar9);
    pcVar9 = pcVar9 + sVar5;
    if (options << 0x1e < 0) {
      uVar2 = CRYPTO_THREADID_hash((CRYPTO_THREADID *)(param_1 + 4));
      BIO_snprintf(pcVar9,(int)&iStack_24 - (int)pcVar9,"thread=%lu, ",uVar2,pBVar6,pBVar7);
      sVar5 = strlen(pcVar9);
      pcVar9 = pcVar9 + sVar5;
    }
    BIO_snprintf(pcVar9,(int)&iStack_24 - (int)pcVar9,"number=%d, address=%08lX\n",param_1[1],
                 *param_1,pBVar7);
    BIO_puts(*param_2,acStack_424);
    pBVar7 = param_1[8];
    pBVar6 = param_1[1];
    param_2[1] = (BIO *)((int)&param_2[1]->method + 1);
    param_2[2] = (BIO *)((int)&pBVar6->method + (int)&param_2[2]->method);
    if (pBVar7 != (BIO *)0x0) {
      iVar8 = 0;
      CRYPTO_THREADID_cpy(&CStack_42c,(CRYPTO_THREADID *)pBVar7);
      do {
        iVar8 = iVar8 + 1;
        __memset_chk(acStack_424,0x3e,iVar8,0x400);
        uVar2 = CRYPTO_THREADID_hash((CRYPTO_THREADID *)pBVar7);
        BIO_snprintf(acStack_424 + iVar8,0x400 - iVar8," thread=%lu, file=%s, line=%d, info=\"",
                     uVar2,pBVar7->cb_arg,pBVar7->init);
        sVar5 = strlen(acStack_424);
        pcVar9 = (char *)pBVar7->shutdown;
        sVar3 = strlen(pcVar9);
        if ((int)(0x7d - sVar5) < (int)sVar3) {
          memcpy(acStack_424 + sVar5,pcVar9,0x7d - sVar5);
          sVar3 = 899;
          sVar5 = 0x7d;
        }
        else {
          BUF_strlcpy(acStack_424 + sVar5,pcVar9,0x400 - sVar5);
          sVar5 = strlen(acStack_424);
          sVar3 = 0x400 - sVar5;
        }
        BIO_snprintf(acStack_424 + sVar5,sVar3,"\"\n");
        BIO_puts(*param_2,acStack_424);
        pBVar7 = (BIO *)pBVar7->flags;
      } while ((pBVar7 != (BIO *)0x0) &&
              (iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)pBVar7,&CStack_42c), iVar1 == 0));
    }
  }
  if (iStack_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

