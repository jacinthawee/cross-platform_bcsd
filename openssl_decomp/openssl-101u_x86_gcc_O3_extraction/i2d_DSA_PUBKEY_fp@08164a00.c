
int i2d_DSA_PUBKEY_fp(FILE *fp,DSA *dsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp(i2d_DSA_PUBKEY,fp,dsa);
  return iVar1;
}
