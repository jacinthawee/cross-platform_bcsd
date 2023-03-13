
int app_RAND_load_file(char *param_1,BIO *param_2,int param_3)

{
  int iVar1;
  char *file;
  int in_GS_OFFSET;
  char local_d8 [200];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == (char *)0x0) {
    file = RAND_file_name(local_d8,200);
    if (file != (char *)0x0) goto LAB_0807fc52;
LAB_0807fc64:
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
      goto LAB_0807fc2d;
    }
  }
  else {
    iVar1 = RAND_egd(param_1);
    file = param_1;
    if (0 < iVar1) {
      egdsocket = 1;
      iVar1 = 1;
      goto LAB_0807fc2d;
    }
LAB_0807fc52:
    iVar1 = RAND_load_file(file,-1);
    if (iVar1 == 0) goto LAB_0807fc64;
  }
  seeded = 1;
  iVar1 = 1;
LAB_0807fc2d:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

