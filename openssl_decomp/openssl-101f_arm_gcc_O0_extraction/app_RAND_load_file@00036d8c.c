
void app_RAND_load_file(char *param_1,BIO *param_2,int param_3)

{
  int iVar1;
  char *file;
  char acStack_e4 [200];
  int local_1c;
  
  local_1c = __TMC_END__;
  if (param_1 == (char *)0x0) {
    file = RAND_file_name(acStack_e4,200);
    if (file != (char *)0x0) goto LAB_00036dd0;
LAB_00036dda:
    iVar1 = RAND_status();
    if (iVar1 == 0) {
      if (param_3 == 0) {
        BIO_printf(param_2,"unable to load \'random state\'\n");
        BIO_printf(param_2,"This means that the random number generator has not been seeded\n");
        BIO_printf(param_2,"with much random data.\n");
        if (param_1 == (char *)0x0) {
          BIO_printf(param_2,
                     "Consider setting the RANDFILE environment variable to point at a file that\n")
          ;
          BIO_printf(param_2,"\'random\' data can be kept in (the file will be overwritten).\n");
        }
      }
      goto LAB_00036dbe;
    }
  }
  else {
    iVar1 = RAND_egd(param_1);
    file = param_1;
    if (0 < iVar1) {
      iVar1 = 1;
      egdsocket = 1;
      goto LAB_00036dbe;
    }
LAB_00036dd0:
    iVar1 = RAND_load_file(file,-1);
    if (iVar1 == 0) goto LAB_00036dda;
  }
  iVar1 = 1;
  seeded = 1;
LAB_00036dbe:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}

