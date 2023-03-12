
undefined4 OPENSSL_DIR_end(void **param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((param_1 != (void **)0x0) && ((DIR **)*param_1 != (DIR **)0x0)) {
                    /* WARNING: Load size is inaccurate */
    iVar1 = closedir(**param_1);
    free(*param_1);
    uVar2 = 0;
    if ((iVar1 == -1) || (uVar2 = 1, iVar1 == 0)) {
      return uVar2;
    }
  }
  piVar3 = __errno_location();
  *piVar3 = 0x16;
  return 0;
}

