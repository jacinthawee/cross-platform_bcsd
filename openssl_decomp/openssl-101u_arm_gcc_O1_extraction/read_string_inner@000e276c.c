
void read_string_inner(UI *param_1,UI_STRING *param_2,int param_3,int param_4)

{
  FILE *pFVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  sigaction *psVar5;
  uint uVar6;
  sigaction local_20c0;
  char acStack_2034 [8];
  char local_202c [8192];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  psVar5 = (sigaction *)(savsig + 0x8c);
  ps_8594 = 0;
  intr_signal = 0;
  memset(&local_20c0,0,0x8c);
  iVar3 = 1;
  local_20c0.__sigaction_handler.sa_handler = (__sighandler_t)0xe26e5;
  for (iVar4 = 2;
      ((iVar3 == 0xc || (iVar4 - 10U < 2)) || (sigaction(iVar3,&local_20c0,psVar5), iVar4 != 0x20));
      iVar4 = iVar4 + 1) {
    iVar3 = iVar3 + 1;
    psVar5 = psVar5 + 1;
  }
  signal(0x1c,(__sighandler_t)0x0);
  pFVar1 = tty_in;
  ps_8594 = 1;
  if (param_3 == 0) {
    tty_new._0_4_ = tty_orig._0_4_;
    tty_new._4_4_ = tty_orig._4_4_;
    tty_new._8_4_ = tty_orig._8_4_;
    tty_new._12_4_ = tty_orig._12_4_ & 0xfffffff7;
    tty_new._16_4_ = tty_orig._16_4_;
    tty_new._20_4_ = tty_orig._20_4_;
    tty_new._24_4_ = tty_orig._24_4_;
    tty_new._28_4_ = tty_orig._28_4_;
    tty_new._32_4_ = tty_orig._32_4_;
    tty_new._36_4_ = tty_orig._36_4_;
    tty_new._40_4_ = tty_orig._40_4_;
    tty_new._44_4_ = tty_orig._44_4_;
    tty_new._48_4_ = tty_orig._48_4_;
    tty_new._52_4_ = tty_orig._52_4_;
    tty_new._56_4_ = tty_orig._56_4_;
    if (is_a_tty == 0) goto LAB_000e2840;
    iVar3 = fileno(tty_in);
    iVar3 = tcsetattr(iVar3,0,(termios *)tty_new);
    if (iVar3 != -1) goto LAB_000e2840;
LAB_000e2870:
    uVar6 = 0;
  }
  else {
LAB_000e2840:
    local_202c[0] = '\0';
    ps_8594 = 2;
    pcVar2 = fgets(local_202c,0x1fff,pFVar1);
    pFVar1 = tty_in;
    if (((pcVar2 == (char *)0x0) || (iVar3 = feof(tty_in), iVar3 != 0)) ||
       (iVar3 = ferror(pFVar1), iVar3 != 0)) goto LAB_000e2870;
    pcVar2 = strchr(local_202c,10);
    if (pcVar2 == (char *)0x0) {
      do {
        pcVar2 = fgets(acStack_2034,4,pFVar1);
        if (pcVar2 == (char *)0x0) goto LAB_000e2870;
        pcVar2 = strchr(acStack_2034,10);
      } while (pcVar2 == (char *)0x0);
    }
    else if (param_4 != 0) {
      *pcVar2 = '\0';
    }
    uVar6 = UI_set_result(param_1,param_2,local_202c);
    uVar6 = ~uVar6 >> 0x1f;
  }
  if (intr_signal == 2) {
    uVar6 = 0xffffffff;
  }
  if (param_3 == 0) {
    fputc(10,tty_out);
    if (ps_8594 < 2) goto LAB_000e29a6;
    tty_new._0_4_ = tty_orig._0_4_;
    tty_new._4_4_ = tty_orig._4_4_;
    tty_new._8_4_ = tty_orig._8_4_;
    tty_new._16_4_ = tty_orig._16_4_;
    tty_new._20_4_ = tty_orig._20_4_;
    tty_new._24_4_ = tty_orig._24_4_;
    tty_new._28_4_ = tty_orig._28_4_;
    tty_new._12_4_ = tty_orig._12_4_ | 8;
    tty_new._32_4_ = tty_orig._32_4_;
    tty_new._36_4_ = tty_orig._36_4_;
    tty_new._40_4_ = tty_orig._40_4_;
    tty_new._44_4_ = tty_orig._44_4_;
    tty_new._48_4_ = tty_orig._48_4_;
    tty_new._52_4_ = tty_orig._52_4_;
    tty_new._56_4_ = tty_orig._56_4_;
    if (is_a_tty != 0) {
      iVar3 = fileno(tty_in);
      iVar3 = tcsetattr(iVar3,0,(termios *)tty_new);
      if (iVar3 == -1) {
        uVar6 = 0;
      }
    }
  }
  else if (ps_8594 < 2) {
LAB_000e29a6:
    if (ps_8594 != 1) goto LAB_000e28b6;
  }
  iVar3 = 1;
  psVar5 = DAT_000e29d4;
  for (iVar4 = 2;
      ((iVar3 == 10 || (iVar3 == 0xc)) || (sigaction(iVar3,psVar5,(sigaction *)0x0), iVar4 != 0x20))
      ; iVar4 = iVar4 + 1) {
    iVar3 = iVar3 + 1;
    psVar5 = psVar5 + 1;
  }
LAB_000e28b6:
  OPENSSL_cleanse(local_202c,0x2000);
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar6);
}

