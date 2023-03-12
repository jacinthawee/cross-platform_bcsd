
int DH_compute_key(uchar *key,BIGNUM *pub_key,DH *dh)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00098f10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*dh->meth->compute_key)(key,pub_key,dh);
  return iVar1;
}

