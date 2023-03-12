
RSA * PEM_read_RSAPublicKey(FILE *fp,RSA **x,undefined1 *cb,void *u)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)PEM_ASN1_read(PTR_d2i_RSAPublicKey_006a9f78,"RSA PUBLIC KEY",fp,x,cb,u);
  return pRVar1;
}

