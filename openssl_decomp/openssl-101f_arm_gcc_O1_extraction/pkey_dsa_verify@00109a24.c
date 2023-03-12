
void pkey_dsa_verify(int param_1,uchar *param_2,int param_3,uchar *param_4,int param_5)

{
  EVP_MD *md;
  int type;
  DSA *dsa;
  
  md = *(EVP_MD **)(*(int *)(param_1 + 0x14) + 0x14);
  dsa = *(DSA **)(*(int *)(param_1 + 8) + 0x14);
  if (md == (EVP_MD *)0x0) {
    type = 0x40;
  }
  else {
    type = EVP_MD_type(md);
  }
  DSA_verify(type,param_4,param_5,param_2,param_3,dsa);
  return;
}
