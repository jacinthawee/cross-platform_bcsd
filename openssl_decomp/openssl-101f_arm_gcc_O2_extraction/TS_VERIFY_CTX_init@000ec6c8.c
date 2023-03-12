
void TS_VERIFY_CTX_init(int param_1)

{
  if (param_1 == 0) {
    OpenSSLDie("ts_verify_ctx.c",0x4c,"ctx != NULL");
  }
  (*(code *)PTR_memset_0018a15c)(param_1,0,0x28);
  return;
}

