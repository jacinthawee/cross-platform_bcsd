
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
    tty_new._8_4_ = tty_orig._8_4_;
    tty_new._0_4_ = tty_orig._0_4_;
    tty_new._12_4_ = tty_orig._12_4_;
    tty_new._16_2_ = tty_orig._16_2_;
    tty_new._4_4_ = tty_orig._4_4_ & 0xfff7ffff;
    if (is_a_tty == 0) goto LAB_0818b208;
    iVar3 = fileno(tty_in);
    iVar3 = ioctl(iVar3,0x5406,tty_new);
    if (iVar3 != -1) goto LAB_0818b208;
    uVar5 = -(uint)(intr_signal == 2);
LAB_0818b32c:
    fputc(10,tty_out);
    if (ps_5979 < 2) {
LAB_0818b460:
      if (ps_5979 < 1) goto LAB_0818b2ad;
    }
    else {
      tty_new._0_4_ = tty_orig._0_4_;
      tty_new._8_4_ = tty_orig._8_4_;
      tty_new._12_4_ = tty_orig._12_4_;
      tty_new._16_2_ = tty_orig._16_2_;
      tty_new._4_4_ = tty_orig._4_4_ | 0x80000;
      if (is_a_tty != 0) {
        iVar3 = fileno(tty_in);
        iVar3 = ioctl(iVar3,0x5406,tty_new);
        if (iVar3 == -1) {
          uVar5 = 0;
        }
      }
    }
  }
  else {
LAB_0818b208:
    local_2020[0] = '\0';
    ps_5979 = 2;
    pcVar2 = fgets(local_2020,0x1fff,pFVar1);
    pFVar1 = tty_in;
    if (((pcVar2 == (char *)0x0) || (iVar3 = feof(tty_in), iVar3 != 0)) ||
       (iVar3 = ferror(pFVar1), iVar3 != 0)) {
LAB_0818b251:
      uVar5 = 0;
    }
    else {
      pcVar2 = strchr(local_2020,10);
      if (pcVar2 == (char *)0x0) {
        do {
          pcVar2 = fgets(local_2025,4,pFVar1);
          if (pcVar2 == (char *)0x0) goto LAB_0818b251;
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
    if (param_3 == 0) goto LAB_0818b32c;
    if (ps_5979 < 2) goto LAB_0818b460;
  }
  iVar3 = 1;
  do {
    if ((iVar3 - 10U & 0xfffffffd) != 0) {
      sigaction(iVar3,__act,(sigaction *)0x0);
    }
    iVar3 = iVar3 + 1;
    __act = __act + 1;
  } while (iVar3 != 0x20);
LAB_0818b2ad:
  OPENSSL_cleanse(local_2020,0x2000);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

