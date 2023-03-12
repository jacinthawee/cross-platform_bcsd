
void Camellia_encrypt(uchar *in,uchar *out,CAMELLIA_KEY *key)

{
                    /* WARNING: Could not recover jumptable at 0x004e728c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_Camellia_EncryptBlock_Rounds_006a850c)(key->grand_rounds,in,key,out);
  return;
}

