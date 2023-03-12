
void SEED_ecb_encrypt(uchar *in,uchar *out,SEED_KEY_SCHEDULE *ks,int enc)

{
  if (enc == 0) {
                    /* WARNING: Could not recover jumptable at 0x005eaf20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_SEED_decrypt_006a963c)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005eaf2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_SEED_encrypt_006a9640)();
  return;
}

