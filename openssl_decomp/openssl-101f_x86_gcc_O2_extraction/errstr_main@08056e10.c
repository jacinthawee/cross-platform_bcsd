
int errstr_main(int param_1,int param_2)

{
  int iVar1;
  BIO_METHOD *pBVar2;
  BIO *bp;
  long lVar3;
  _LHASH *p_Var4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int in_GS_OFFSET;
  bool bVar8;
  byte bVar9;
  int local_130;
  ulong local_124;
  char local_120 [256];
  int local_20;
  
  bVar9 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar2 = BIO_s_file();
    bio_err = BIO_new(pBVar2);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  SSL_load_error_strings();
  bVar8 = param_1 == 1;
  if (param_1 < 2) {
LAB_08056f88:
    local_130 = 0;
  }
  else {
    iVar5 = 7;
    pcVar6 = *(char **)(param_2 + 4);
    pcVar7 = "-stats";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + (uint)bVar9 * -2 + 1;
      pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
    } while (bVar8);
    if (bVar8) {
      pBVar2 = BIO_s_file();
      bp = BIO_new(pBVar2);
      if (bp != (BIO *)0x0) {
        lVar3 = BIO_ctrl(bp,0x6a,0,stdout);
        if (lVar3 != 0) {
          p_Var4 = (_LHASH *)ERR_get_string_table();
          lh_node_stats_bio(p_Var4,bp);
          p_Var4 = (_LHASH *)ERR_get_string_table();
          lh_stats_bio(p_Var4,bp);
          p_Var4 = (_LHASH *)ERR_get_string_table();
          lh_node_usage_stats_bio(p_Var4,bp);
        }
        BIO_free_all(bp);
      }
      param_1 = param_1 + -1;
      param_2 = param_2 + 4;
      if (param_1 == 1) goto LAB_08056f88;
    }
    local_130 = 0;
    iVar5 = 1;
    do {
      while (iVar1 = __isoc99_sscanf(*(undefined4 *)(param_2 + iVar5 * 4),&DAT_081ed4df,&local_124),
            iVar1 == 0) {
        iVar1 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        __printf_chk(1,"%s: bad error code\n",*(undefined4 *)(param_2 + iVar1));
        puts("usage: errstr [-stats] <errno> ...");
        local_130 = local_130 + 1;
        if (param_1 <= iVar5) goto LAB_08056f05;
      }
      iVar5 = iVar5 + 1;
      ERR_error_string_n(local_124,local_120,0x100);
      puts(local_120);
    } while (iVar5 < param_1);
  }
LAB_08056f05:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_130;
}

