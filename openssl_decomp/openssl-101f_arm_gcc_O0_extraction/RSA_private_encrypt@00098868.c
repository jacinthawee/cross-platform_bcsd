
int RSA_private_encrypt(int flen,uchar *from,uchar *to,RSA *rsa,int padding)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00098874. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*rsa->meth->rsa_priv_enc)(flen,from,to,rsa,padding);
  return iVar1;
}

