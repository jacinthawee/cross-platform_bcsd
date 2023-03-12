
int TS_REQ_get_cert_req(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

