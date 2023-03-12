
void app_RAND_write_file(char *param_1,BIO *param_2)

{
  int iVar1;
  char acStack_dc [200];
  int local_14;
  
  local_14 = __TMC_END__;
  if (egdsocket == 0) {
    iVar1 = seeded;
    if (seeded != 0) {
      if (((param_1 == (char *)0x0) &&
          (param_1 = RAND_file_name(acStack_dc,200), param_1 == (char *)0x0)) ||
         (iVar1 = RAND_write_file(param_1), iVar1 == 0)) {
        BIO_printf(param_2,"unable to write \'random state\'\n");
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  if (local_14 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}

