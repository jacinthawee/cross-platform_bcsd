
void exnode_free(uint **param_1)

{
  if ((*param_1 != (uint *)0x0) && ((**param_1 & 8) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x005991ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    return;
  }
  return;
}

