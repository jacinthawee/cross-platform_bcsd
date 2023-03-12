
undefined4 hmac_signctx_init(int param_1,int param_2)

{
  (*(code *)PTR_HMAC_CTX_set_flags_006aa770)
            (*(int *)(param_1 + 0x14) + 0x14,*(uint *)(param_2 + 8) & 0xfffffeff);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(param_2,0x100);
  *(code **)(param_2 + 0x14) = int_update;
  return 1;
}

