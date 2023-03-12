
void TS_VERIFY_CTX_init(int param_1)

{
  if (param_1 == 0) {
    OpenSSLDie("ts_verify_ctx.c",0x4d,"ctx != NULL");
  }
  (*(code *)PTR_memset_00189160)(param_1,0,0x28);
  return;
}

