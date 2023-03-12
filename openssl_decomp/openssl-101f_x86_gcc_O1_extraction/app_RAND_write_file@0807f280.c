
int app_RAND_write_file(char *param_1,BIO *param_2)

{
  int iVar1;
  int in_GS_OFFSET;
  char local_d8 [200];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if ((egdsocket == 0) && (iVar1 = seeded, seeded != 0)) {
    if (((param_1 == (char *)0x0) &&
        (param_1 = RAND_file_name(local_d8,200), param_1 == (char *)0x0)) ||
       (iVar1 = RAND_write_file(param_1), iVar1 == 0)) {
      BIO_printf(param_2,"unable to write \'random state\'\n");
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

