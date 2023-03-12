
/* WARNING: Type propagation algorithm not settling */

undefined4 version_main(int param_1,char **param_2)

{
  char cVar1;
  ulong uVar2;
  BIO_METHOD *type;
  char *pcVar3;
  int iVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  undefined uVar9;
  undefined uVar10;
  
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  uVar10 = param_1 == 1;
  uVar5 = false;
  uVar6 = uVar5;
  uVar9 = uVar5;
  uVar8 = uVar5;
  uVar7 = uVar5;
  if (1 < param_1) {
    uVar9 = false;
    uVar8 = false;
    uVar6 = false;
    uVar7 = false;
    iVar4 = 1;
    do {
      param_2 = param_2 + 1;
      pcVar3 = *param_2;
      if (*pcVar3 != '-') {
LAB_00036c22:
        BIO_printf(bio_err,"usage:version -[avbofpd]\n");
        return 1;
      }
      cVar1 = pcVar3[1];
      if (cVar1 == 'v') {
        if (pcVar3[2] != '\0') goto LAB_00036c22;
        uVar10 = true;
      }
      else if (cVar1 == 'b') {
        if (pcVar3[2] != '\0') goto LAB_00036c22;
        uVar6 = true;
      }
      else if (cVar1 == 'f') {
        if (pcVar3[2] != '\0') goto LAB_00036c22;
        uVar7 = true;
      }
      else if (cVar1 == 'o') {
        if (pcVar3[2] != '\0') goto LAB_00036c22;
        uVar8 = true;
      }
      else if (cVar1 == 'p') {
        if (pcVar3[2] != '\0') goto LAB_00036c22;
        uVar9 = true;
      }
      else if (cVar1 == 'd') {
        if (pcVar3[2] != '\0') goto LAB_00036c22;
        uVar5 = true;
      }
      else {
        if ((cVar1 != 'a') || (pcVar3[2] != '\0')) goto LAB_00036c22;
        uVar10 = true;
        uVar9 = true;
        uVar8 = true;
        uVar7 = true;
        uVar5 = uVar10;
        uVar6 = uVar10;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != param_1);
  }
  if ((bool)uVar10) {
    uVar2 = SSLeay();
    if (uVar2 == 0x1000115f) {
      pcVar3 = SSLeay_version(0);
      puts(pcVar3);
    }
    else {
      pcVar3 = SSLeay_version(0);
      __printf_chk(1,"%s (Library: %s)\n","OpenSSL 1.0.1u  22 Sep 2016",pcVar3);
    }
  }
  if ((bool)uVar6) {
    pcVar3 = SSLeay_version(3);
    puts(pcVar3);
  }
  if ((bool)uVar9) {
    pcVar3 = SSLeay_version(4);
    puts(pcVar3);
  }
  if ((bool)uVar8) {
    __printf_chk(1,"options:  ");
    pcVar3 = BN_options();
    __printf_chk(1,&DAT_00131388,pcVar3);
    pcVar3 = RC4_options();
    __printf_chk(1,&DAT_00131388,pcVar3);
    pcVar3 = DES_options();
    __printf_chk(1,&DAT_00131388,pcVar3);
    pcVar3 = idea_options();
    __printf_chk(1,&DAT_00131388,pcVar3);
    pcVar3 = BF_options();
    __printf_chk(1,&DAT_00131388,pcVar3);
    putchar(10);
  }
  if ((bool)uVar7) {
    pcVar3 = SSLeay_version(2);
    puts(pcVar3);
  }
  if ((bool)uVar5) {
    pcVar3 = SSLeay_version(5);
    puts(pcVar3);
  }
  return 0;
}

