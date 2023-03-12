
void Camellia_ecb_encrypt(uchar *in,uchar *out,CAMELLIA_KEY *key,int enc)

{
  if (enc != 1) {
                    /* WARNING: Could not recover jumptable at 0x005e6c84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_Camellia_decrypt_006a8514)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005e6c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_Camellia_encrypt_006a8518)();
  return;
}

