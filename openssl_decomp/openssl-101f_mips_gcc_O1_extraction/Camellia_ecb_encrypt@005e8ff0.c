
void Camellia_ecb_encrypt(uchar *in,uchar *out,CAMELLIA_KEY *key,int enc)

{
  if (enc != 1) {
                    /* WARNING: Could not recover jumptable at 0x005e9004. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_Camellia_decrypt_006a9634)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005e9010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_Camellia_encrypt_006a9638)();
  return;
}

