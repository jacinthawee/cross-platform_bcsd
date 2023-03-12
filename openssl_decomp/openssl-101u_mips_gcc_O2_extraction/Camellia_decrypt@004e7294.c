
void Camellia_decrypt(uchar *in,uchar *out,CAMELLIA_KEY *key)

{
                    /* WARNING: Could not recover jumptable at 0x004e72a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_Camellia_DecryptBlock_Rounds_006a8510)(key->grand_rounds,in,key,out);
  return;
}

