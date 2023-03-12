
DSA_SIG * DSA_do_sign(uchar *dgst,int dlen,DSA *dsa)

{
  DSA_SIG *pDVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0810f56a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pDVar1 = (*dsa->meth->dsa_do_sign)(dgst,dlen,dsa);
  return pDVar1;
}

