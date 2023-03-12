
int i2d_PKCS8PrivateKey_nid_fp
              (FILE *fp,EVP_PKEY *x,int nid,char *kstr,int klen,undefined1 *cb,void *u)

{
  BIO *a;
  int iVar1;
  
  a = BIO_new_fp(fp,0);
  if (a != (BIO *)0x0) {
    iVar1 = do_pk8pkey(a,x,1,nid,0,kstr,klen,cb,u);
    BIO_free(a);
    return iVar1;
  }
  ERR_put_error(9,0x7d,7,"pem_pk8.c",0xe7);
  return 0;
}

