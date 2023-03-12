
void print_fp(undefined4 param_1,undefined4 param_2,void *param_3)

{
  BIO_METHOD *type;
  int in_GS_OFFSET;
  BIO local_50;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  BIO_set(&local_50,type);
  BIO_ctrl(&local_50,0x6a,0,param_3);
  BIO_printf(&local_50,"%s",param_1);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

