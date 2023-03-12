
undefined4 open_console(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1f,"ui_openssl.c",0x1e4);
  is_a_tty = 1;
  tty_in = (*(code *)PTR_fopen_006aac08)("/dev/tty","r");
  if (tty_in == 0) {
    tty_in = *(int *)PTR_stdin_006aab20;
  }
  tty_out = (*(code *)PTR_fopen_006aac08)("/dev/tty","w");
  if (tty_out == 0) {
    tty_out = *(int *)PTR_stderr_006aac00;
  }
  uVar1 = (*(code *)PTR_fileno_006aaae8)(tty_in);
  iVar2 = (*(code *)PTR_ioctl_006aab90)(uVar1,0x5401,tty_orig);
  if (iVar2 != -1) {
    return 1;
  }
  piVar3 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
  if ((*piVar3 != 0x19) && (*piVar3 != 0x16)) {
    return 0;
  }
  is_a_tty = 0;
  return 1;
}

