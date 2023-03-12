
void errstr_main(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  BIO_METHOD *pBVar3;
  BIO *bp;
  long lVar4;
  _LHASH *p_Var5;
  int iVar6;
  undefined4 *puVar7;
  ulong local_120;
  char acStack_11c [256];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar3 = BIO_s_file();
    bio_err = BIO_new(pBVar3);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  SSL_load_error_strings();
  if (param_1 < 2) {
LAB_0001b306:
    iVar1 = 0;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"-stats");
    if (iVar1 == 0) {
      pBVar3 = BIO_s_file();
      bp = BIO_new(pBVar3);
      if (bp != (BIO *)0x0) {
        lVar4 = BIO_ctrl(bp,0x6a,0,stdout);
        if (lVar4 != 0) {
          p_Var5 = (_LHASH *)ERR_get_string_table();
          lh_node_stats_bio(p_Var5,bp);
          p_Var5 = (_LHASH *)ERR_get_string_table();
          lh_stats_bio(p_Var5,bp);
          p_Var5 = (_LHASH *)ERR_get_string_table();
          lh_node_usage_stats_bio(p_Var5,bp);
        }
        BIO_free_all(bp);
      }
      param_1 = param_1 + -1;
      param_2 = param_2 + 4;
      if (param_1 == 1) goto LAB_0001b306;
    }
    iVar1 = 0;
    iVar6 = 1;
    puVar7 = (undefined4 *)(param_2 + 4);
    do {
      while( true ) {
        iVar2 = __isoc99_sscanf(*puVar7,&DAT_0012735c,&local_120);
        if (iVar2 != 0) break;
        __printf_chk(1,"%s: bad error code\n",*puVar7);
        iVar6 = iVar6 + 1;
        puts("usage: errstr [-stats] <errno> ...");
        iVar1 = iVar1 + 1;
        puVar7 = puVar7 + 1;
        if (param_1 <= iVar6) goto LAB_0001b2c6;
      }
      iVar6 = iVar6 + 1;
      ERR_error_string_n(local_120,acStack_11c,0x100);
      puts(acStack_11c);
      puVar7 = puVar7 + 1;
    } while (iVar6 < param_1);
  }
LAB_0001b2c6:
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar1);
}

