
undefined4 open_console(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1f,"ui_openssl.c",0x1de);
  is_a_tty = 1;
  tty_in = (*(code *)PTR_fopen_006a9b00)("/dev/tty","r");
  if (tty_in == 0) {
    tty_in = *(int *)PTR_stdin_006a9a14;
  }
  tty_out = (*(code *)PTR_fopen_006a9b00)("/dev/tty","w");
  if (tty_out == 0) {
    tty_out = *(int *)PTR_stderr_006a9af8;
  }
  uVar1 = (*(code *)PTR_fileno_006a99dc)(tty_in);
  iVar2 = (*(code *)PTR_tcgetattr_006a996c)(uVar1,tty_orig);
  if (iVar2 != -1) {
    return 1;
  }
  piVar3 = (int *)(*(code *)PTR___errno_location_006a99e8)();
  if ((*piVar3 != 0x19) && (*piVar3 != 0x16)) {
    return 0;
  }
  is_a_tty = 0;
  return 1;
}

