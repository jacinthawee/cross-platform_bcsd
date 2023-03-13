
void TS_VERIFY_CTX_init(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005c47fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_memset_006a99f4)(param_1,0,0x28);
    return;
  }
  (*(code *)PTR_OpenSSLDie_006a7c5c)("ts_verify_ctx.c",0x4d,"ctx != NULL");
                    /* WARNING: Could not recover jumptable at 0x005c483c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_memset_006a99f4)(0,0,0x28);
  return;
}

