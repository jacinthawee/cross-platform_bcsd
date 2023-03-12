
int DSA_sign(int type,uchar *dgst,int dlen,uchar *sig,uint *siglen,DSA *dsa)

{
  DSA_SIG *a;
  uint uVar1;
  uchar *local_resc;
  
  local_resc = sig;
  RAND_seed(dgst,dlen);
  a = DSA_do_sign(dgst,dlen,dsa);
  if (a != (DSA_SIG *)0x0) {
    uVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,&local_resc,DSA_SIG_it);
    *siglen = uVar1;
    DSA_SIG_free(a);
    return 1;
  }
  *siglen = 0;
  return 0;
}

