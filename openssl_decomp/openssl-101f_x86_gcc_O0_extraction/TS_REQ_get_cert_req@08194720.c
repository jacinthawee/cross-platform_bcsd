
bool TS_REQ_get_cert_req(int param_1)

{
  return *(int *)(param_1 + 0x10) != 0;
}

