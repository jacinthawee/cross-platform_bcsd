
undefined4 __regparm3 open_console(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0x1e4;
  CRYPTO_lock(param_1,9,(char *)0x1f,(int)"ui_openssl.c");
  is_a_tty = 1;
  tty_in = fopen("/dev/tty","r");
  if (tty_in == (FILE *)0x0) {
    tty_in = stdin;
  }
  tty_out = fopen("/dev/tty","w");
  if (tty_out == (FILE *)0x0) {
    tty_out = stderr;
  }
  iVar1 = fileno(tty_in);
  iVar1 = ioctl(iVar1,0x5405,tty_orig,uVar3);
  if (iVar1 != -1) {
    return 1;
  }
  piVar2 = __errno_location();
  if ((*piVar2 != 0x19) && (*piVar2 != 0x16)) {
    return 0;
  }
  is_a_tty = 0;
  return 1;
}

