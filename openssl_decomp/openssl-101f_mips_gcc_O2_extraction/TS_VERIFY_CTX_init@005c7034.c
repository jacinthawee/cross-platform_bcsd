
void TS_VERIFY_CTX_init(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005c706c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_memset_006aab00)(param_1,0,0x28);
    return;
  }
  (*(code *)PTR_OpenSSLDie_006a8d4c)("ts_verify_ctx.c",0x4c,"ctx != NULL");
                    /* WARNING: Could not recover jumptable at 0x005c70ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_memset_006aab00)(0,0,0x28);
  return;
}

