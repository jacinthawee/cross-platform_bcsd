
undefined4 TS_REQ_set_cert_req(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xff;
  }
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  return 1;
}

