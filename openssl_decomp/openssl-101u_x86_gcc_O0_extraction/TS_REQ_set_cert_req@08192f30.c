
undefined4 TS_REQ_set_cert_req(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x10) = ~-(uint)(param_2 == 0) & 0xff;
  return 1;
}

