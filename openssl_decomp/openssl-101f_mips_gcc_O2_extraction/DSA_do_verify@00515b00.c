
int DSA_do_verify(uchar *dgst,int dgst_len,DSA_SIG *sig,DSA *dsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00515b08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*dsa->meth->dsa_do_verify)(dgst,dgst_len,sig,dsa);
  return iVar1;
}

