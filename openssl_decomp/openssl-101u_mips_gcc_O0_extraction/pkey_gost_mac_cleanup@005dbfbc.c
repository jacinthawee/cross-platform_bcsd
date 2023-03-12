
void pkey_gost_mac_cleanup(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_EVP_PKEY_CTX_get_data_006a95d0)();
                    /* WARNING: Could not recover jumptable at 0x005dbfec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(uVar1);
  return;
}

