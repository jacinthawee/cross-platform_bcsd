
void SEED_ecb_encrypt(uchar *in,uchar *out,SEED_KEY_SCHEDULE *ks,int enc)

{
  if (enc == 0) {
                    /* WARNING: Could not recover jumptable at 0x005e8ba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_SEED_decrypt_006a851c)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005e8bac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_SEED_encrypt_006a8520)();
  return;
}

