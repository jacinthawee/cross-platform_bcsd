
undefined4 version_main(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  char *pcVar8;
  ulong uVar9;
  BIO_METHOD *type;
  bool bVar10;
  
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  bVar10 = param_1 == 1;
  if (param_1 < 2) {
    if (param_1 != 1) {
      return 0;
    }
    bVar4 = false;
    bVar6 = false;
    bVar2 = false;
    bVar3 = false;
    bVar5 = false;
  }
  else {
    bVar6 = false;
    bVar3 = false;
    bVar2 = false;
    bVar4 = false;
    bVar5 = false;
    iVar7 = 1;
    do {
      pcVar8 = *(char **)(param_2 + iVar7 * 4);
      if (*pcVar8 != '-') {
LAB_0807f3c0:
        BIO_printf(bio_err,"usage:version -[avbofpd]\n");
        return 1;
      }
      cVar1 = pcVar8[1];
      if (cVar1 == 'v') {
        if (pcVar8[2] != '\0') goto LAB_0807f3c0;
        bVar10 = true;
      }
      else if (cVar1 == 'b') {
        if (pcVar8[2] != '\0') goto LAB_0807f3c0;
        bVar2 = true;
      }
      else if (cVar1 == 'f') {
        if (pcVar8[2] != '\0') goto LAB_0807f3c0;
LAB_0807f47f:
        bVar5 = true;
      }
      else if (cVar1 == 'o') {
        if (pcVar8[2] != '\0') goto LAB_0807f3c0;
        bVar4 = true;
      }
      else if (cVar1 == 'p') {
        if (pcVar8[2] != '\0') goto LAB_0807f3c0;
        bVar3 = true;
      }
      else {
        if (cVar1 != 'd') {
          if ((cVar1 != 'a') || (pcVar8[2] != '\0')) goto LAB_0807f3c0;
          bVar6 = true;
          bVar3 = true;
          bVar2 = true;
          bVar4 = true;
          bVar10 = true;
          goto LAB_0807f47f;
        }
        if (pcVar8[2] != '\0') goto LAB_0807f3c0;
        bVar6 = true;
      }
      iVar7 = iVar7 + 1;
    } while (param_1 != iVar7);
    if (!bVar10) goto LAB_0807f40b;
  }
  uVar9 = SSLeay();
  if (uVar9 == 0x1000106f) {
    pcVar8 = SSLeay_version(0);
    puts(pcVar8);
  }
  else {
    pcVar8 = SSLeay_version(0);
    __printf_chk(1,"%s (Library: %s)\n","OpenSSL 1.0.1f 6 Jan 2014",pcVar8);
  }
LAB_0807f40b:
  if (bVar2) {
    pcVar8 = SSLeay_version(3);
    puts(pcVar8);
  }
  if (bVar3) {
    pcVar8 = SSLeay_version(4);
    puts(pcVar8);
  }
  if (bVar4) {
    __printf_chk(1,"options:  ");
    pcVar8 = BN_options();
    __printf_chk(1,&DAT_081f6565,pcVar8);
    pcVar8 = RC4_options();
    __printf_chk(1,&DAT_081f6565,pcVar8);
    pcVar8 = DES_options();
    __printf_chk(1,&DAT_081f6565,pcVar8);
    pcVar8 = idea_options();
    __printf_chk(1,&DAT_081f6565,pcVar8);
    pcVar8 = BF_options();
    __printf_chk(1,&DAT_081f6565,pcVar8);
    putchar(10);
  }
  if (bVar5) {
    pcVar8 = SSLeay_version(2);
    puts(pcVar8);
  }
  if (!bVar6) {
    return 0;
  }
  pcVar8 = SSLeay_version(5);
  puts(pcVar8);
  return 0;
}

