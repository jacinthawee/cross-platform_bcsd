
uint __regparm3 read_string_inner(UI *param_1_00,UI_STRING *param_2,int param_3,int param_1)

{
  FILE *pFVar1;
  char *pcVar2;
  int iVar3;
  sigaction *__act;
  sigaction *psVar4;
  uint uVar5;
  int in_GS_OFFSET;
  sigaction local_20b4;
  char local_2025 [5];
  char local_2020 [8192];
  int local_20;
  
  __act = (sigaction *)(savsig + 0x8c);
  ps_5979 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  psVar4 = &local_20b4;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    (psVar4->__sigaction_handler).sa_handler = (__sighandler_t)0x0;
    psVar4 = (sigaction *)&psVar4->sa_mask;
  }
  intr_signal = 0;
  local_20b4.__sigaction_handler.sa_handler = recsig;
  iVar3 = 1;
  psVar4 = (sigaction *)(savsig + 0x8c);
  do {
    if ((1 < iVar3 - 9U) && (iVar3 != 0xc)) {
      sigaction(iVar3,&local_20b4,psVar4);
    }
    iVar3 = iVar3 + 1;
    psVar4 = psVar4 + 1;
  } while (iVar3 != 0x20);
  signal(0x1c,(__sighandler_t)0x0);
  pFVar1 = tty_in;
  ps_5979 = 1;
  if (param_3 == 0) {
    tty_new._0_4_ = tty_orig._0_4_;
    tty_new._4_4_ = tty_orig._4_4_;
    tty_new._8_4_ = tty_orig._8_4_;
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
    tty_new._12_4_ = tty_orig._12_4_ & 0xfffffff7;
    if (is_a_tty == 0) goto LAB_0818985b;
    iVar3 = fileno(tty_in);
    iVar3 = tcsetattr(iVar3,0,(termios *)tty_new);
    if (iVar3 != -1) goto LAB_0818985b;
    uVar5 = -(uint)(intr_signal == 2);
LAB_08189979:
    fputc(10,tty_out);
    if (ps_5979 < 2) {
LAB_08189b00:
      if (ps_5979 < 1) goto LAB_081898fd;
    }
    else {
      tty_new._0_4_ = tty_orig._0_4_;
      tty_new._4_4_ = tty_orig._4_4_;
      tty_new._8_4_ = tty_orig._8_4_;
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
      tty_new._12_4_ = tty_orig._12_4_ | 8;
      if (is_a_tty != 0) {
        iVar3 = fileno(tty_in);
        iVar3 = tcsetattr(iVar3,0,(termios *)tty_new);
        if (iVar3 == -1) {
          uVar5 = 0;
        }
      }
    }
  }
  else {
LAB_0818985b:
    local_2020[0] = '\0';
    ps_5979 = 2;
    pcVar2 = fgets(local_2020,0x1fff,pFVar1);
    pFVar1 = tty_in;
    if (((pcVar2 == (char *)0x0) || (iVar3 = feof(tty_in), iVar3 != 0)) ||
       (iVar3 = ferror(pFVar1), iVar3 != 0)) {
LAB_081898a4:
      uVar5 = 0;
    }
    else {
      pcVar2 = strchr(local_2020,10);
      if (pcVar2 == (char *)0x0) {
        do {
          pcVar2 = fgets(local_2025,4,pFVar1);
          if (pcVar2 == (char *)0x0) goto LAB_081898a4;
          pcVar2 = strchr(local_2025,10);
        } while (pcVar2 == (char *)0x0);
      }
      else if (param_1 != 0) {
        *pcVar2 = '\0';
      }
      uVar5 = UI_set_result(param_1_00,param_2,local_2020);
      uVar5 = ~uVar5 >> 0x1f;
    }
    if (intr_signal == 2) {
      uVar5 = 0xffffffff;
    }
    if (param_3 == 0) goto LAB_08189979;
    if (ps_5979 < 2) goto LAB_08189b00;
  }
  iVar3 = 1;
  do {
    if ((iVar3 - 10U & 0xfffffffd) != 0) {
      sigaction(iVar3,__act,(sigaction *)0x0);
    }
    iVar3 = iVar3 + 1;
    __act = __act + 1;
  } while (iVar3 != 0x20);
LAB_081898fd:
  OPENSSL_cleanse(local_2020,0x2000);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

