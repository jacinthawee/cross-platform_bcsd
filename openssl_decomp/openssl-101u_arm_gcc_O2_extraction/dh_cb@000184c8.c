
undefined4 dh_cb(int param_1,undefined4 param_2,int param_3)

{
  undefined local_10 [8];
  
  local_10[0] = 0x2a;
  if (param_1 == 0) {
    local_10[0] = 0x2e;
  }
  else if (param_1 == 1) {
    local_10[0] = 0x2b;
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    local_10[0] = 10;
  }
  BIO_write(*(BIO **)(param_3 + 4),local_10,1);
  BIO_ctrl(*(BIO **)(param_3 + 4),0xb,0,(void *)0x0);
  return 1;
}

