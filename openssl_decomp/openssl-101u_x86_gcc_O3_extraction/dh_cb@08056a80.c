
undefined4 dh_cb(int param_1,undefined4 param_2,int param_3)

{
  int in_GS_OFFSET;
  undefined local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_11 = 0x2a;
  if (param_1 == 0) {
    local_11 = 0x2e;
  }
  else if (param_1 == 1) {
    local_11 = 0x2b;
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    local_11 = 10;
  }
  BIO_write(*(BIO **)(param_3 + 4),&local_11,1);
  BIO_ctrl(*(BIO **)(param_3 + 4),0xb,0,(void *)0x0);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

