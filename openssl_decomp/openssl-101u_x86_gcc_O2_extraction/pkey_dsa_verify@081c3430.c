
void pkey_dsa_verify(int param_1,uchar *param_2,int param_3,uchar *param_4,int param_5)

{
  DSA *dsa;
  EVP_MD *md;
  int type;
  
  dsa = *(DSA **)(*(int *)(param_1 + 8) + 0x14);
  md = *(EVP_MD **)(*(int *)(param_1 + 0x14) + 0x14);
  type = 0x40;
  if (md != (EVP_MD *)0x0) {
    type = EVP_MD_type(md);
  }
  DSA_verify(type,param_4,param_5,param_2,param_3,dsa);
  return;
}

