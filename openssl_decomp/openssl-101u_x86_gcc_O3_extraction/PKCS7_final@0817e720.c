
int PKCS7_final(PKCS7 *p7,BIO *data,int flags)

{
  BIO *out;
  int iVar1;
  
  out = PKCS7_dataInit(p7,(BIO *)0x0);
  if (out != (BIO *)0x0) {
    SMIME_crlf_copy(data,out,flags);
    BIO_ctrl(out,0xb,0,(void *)0x0);
    iVar1 = PKCS7_dataFinal(p7,out);
    if (iVar1 == 0) {
      ERR_put_error(0x21,0x86,0x91,"pk7_smime.c",0x7e);
    }
    BIO_free_all(out);
    return (uint)(iVar1 != 0);
  }
  ERR_put_error(0x21,0x86,0x41,"pk7_smime.c",0x75);
  return 0;
}

